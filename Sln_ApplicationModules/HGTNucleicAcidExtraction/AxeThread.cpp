#include "AxeThread.h"

AxeThread::AxeThread()
{
	axeService = Utility::ins().deviceHandle.axeService;
	connect(&checkStepFinishTimer, &QTimer::timeout, this, &AxeThread::checkStepFinish);
}

void AxeThread::run()
{
}

bool AxeThread::isIdle()
{
	return axeStatus == AXEDeviceStatus::AXEDeviceStatusFree;
}

bool AxeThread::isLaunch()
{
	return axeStatus == AXEDeviceStatus::AXEDeviceStatusExecuting;
}

void AxeThread::launchAxeProcess(AXEProcessData data)
{
	if (axeStatus == AXEDeviceStatus::AXEDeviceStatusExecuting)
		return;
	axeStatus = AXEDeviceStatus::AXEDeviceStatusExecuting;
	currStepIndex = 0;
	currProcessData = AXEProcessData(data);
	if (currProcessData.stepsList.count() > 0)
	{
		currStepData = currProcessData.stepsList[currStepIndex];
		launchAxeStep(currStepData);
	}
	else
	{
		processFinish();
	}
}

void AxeThread::launchAxeStep(AXEStepData _stepData)
{
	//stepData
	emit signal_onAxeStepLaunch(_stepData);
	currStepData = _stepData;
	MixedProcessPara para;
	para.nProcessID = currStepData.stepIndex;
	para.nColumnNum = currStepData.column;
	para.nVolume = currStepData.volume;
	para.nMixedTime = currStepData.mixTime;
	para.nMixedSpeed = currStepData.mixSpeed;
	para.nAdsorbTime = currStepData.magnetTime;
	para.nWaitTime = currStepData.waitTime;
	para.nMixPosition = currStepData.mixPos;
	para.nMixAmplitude = currStepData.mixAmplitude;
	para.nAdsorbSpeed = currStepData.magnetSpeed;
	para.nAdsorbPosition = currStepData.adsorbPosition;

	//加热
	if (currStepData.heatStatus)
	{
		axeService->setAimTemperature(1, 1, 1, currStepData.targetTemp);
		axeService->setAimTemperature(1, 1, 2, currStepData.targetTemp);
		axeService->setAimTemperature(1, 1, 3, currStepData.targetTemp);
		axeService->setAimTemperature(1, 1, 4, currStepData.targetTemp);
		axeService->startHeatBoard(1, 1, 1);
	}

	int retCode = axeService->startMixedProcess(1, para);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Process StartMixed retCode = " + strErrorCode.toStdString());
	}
	checkStepFinishTimer.start(3000);
}

void AxeThread::checkStepFinish()
{
	if (axeStatus != AXEDeviceStatus::AXEDeviceStatusExecuting)
		return;
	AXEModuleStatus status = axeService->getAxeModuleStatus(1);
	if (status.axeDeviceStatus != AXEDeviceStatus::AXEDeviceStatusFinish)
	{
		//是否空闲
		return;
	}
	if (currStepData.heatStatus)
	{
		HeatBoardData heatBoardData = axeService->getCurrentTemperature(1, 1, 0);
		if (heatBoardData.degree[0] < currStepData.targetTemp - 2)
		{
			//温度是否达到
			return;
		}
	}
	checkStepFinishTimer.stop();
	//结束
	axeService->stopHeatBoard(1, 1, 1);
	//next
	currStepIndex++;
	if (currStepIndex < currProcessData.stepsList.count())
	{
		currStepData = currProcessData.stepsList[currStepIndex];
		//if (currStepData.waitTime == 0)
		//{
		//	launchStepNext();
		//}
		//else
		//{
		//	QTimer::singleShot(currStepData.waitTime * 1000, this, [&]() {
		//		launchStepNext();
		//	});
		//}
		launchStepNext();
	}
	else {
		processFinish();
	}
}

void AxeThread::launchStepNext()
{
	if (axeStatus == AXEDeviceStatus::AXEDeviceStatusPause)
		return;
	launchAxeStep(currStepData);
}

void AxeThread::processFinish()
{
	axeStatus = AXEDeviceStatus::AXEDeviceStatusFree;
	signal_onAxeProcessFinish(currProcessData);
}

void AxeThread::setStatus(AXEDeviceStatus _axeStatus)
{
	if (_axeStatus == AXEDeviceStatus::AXEDeviceStatusExecuting)
	{
		axeService->processControl(1, 3);
	}
	else if (_axeStatus == AXEDeviceStatus::AXEDeviceStatusPause)
	{
		axeService->processControl(1, 2);
	}
	axeStatus = _axeStatus;
}

//紧急暂停
void AxeThread::reset()
{
	checkStepFinishTimer.stop();
	processFinish();
	//axeService->stopHeatBoard(1, 1, 1);
	//axeService->stopStepMonitor(1, 1);
	//axeService->stopStepMonitor(1, 2);
	//axeService->stopStepMonitor(1, 3);
	//axeService->stopStepMonitor(1, 4);
	//axeService->stopStepMonitor(1, 5);
	axeService->processControl(1, 4);
}
