#pragma once
#include "Common/Utility.h"
#include "AXEMgr.h"
#include <QtCore/QThread>
#include <QtCore/QMutex>
#include "AXEMgr.h"

class AxeThread :public QThread
{
	Q_OBJECT
public:
	AxeThread();
	~AxeThread() {};

	//------------------------------field------------------------------
	IFAXEService* axeService;
	//当前运行的流程
	AXEProcessData currProcessData;
	//当前步骤索引
	int currStepIndex = 0;
	AXEStepData currStepData;
	QTimer checkStepFinishTimer;
	//状态
	AXEDeviceStatus axeStatus = AXEDeviceStatus::AXEDeviceStatusDisable;

	//------------------------------function------------------------------
	void run() override;
	bool isIdle();
	bool isLaunch();
	//运行流程
	void launchAxeProcess(AXEProcessData data);
	//运行步骤
	void launchAxeStep(AXEStepData stepData);
	//检测流程是否完成，如果完成运行下个流程
	void checkStepFinish();
	//运行下个步骤
	void launchStepNext();
	//流程完成
	void processFinish();
	void setStatus(AXEDeviceStatus _axeStatus);
	//复位 紧急暂停
	void reset();

signals:
	void signal_onAxeStepLaunch(AXEStepData _stepData);
	void signal_onAxeProcessFinish(AXEProcessData _processData);
};

