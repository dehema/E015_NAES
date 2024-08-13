#pragma once
#include "Common/Utility.h"
#include "Common/Singleton.h"

//核提流程步骤数据
struct AXEStepData
{
	//编号
	int stepIndex;
	//第几列(1-6)
	int column = 1;
	//步骤名称
	QString stepName;
	//体系容量(1-1000)
	int volume = 1;
	//混合时间(Sec)
	int mixTime = 10;
	//混合速度(200-3000)
	int mixSpeed = 200;
	//混合振幅底部位置 距离磁棒底部百分比(0-50%)
	int mixPos = 0;
	//混合振幅顶部位置 距离磁棒底部百分比(0-100%)
	int mixAmplitude = 0;
	//吸磁时间(Sec)
	int magnetTime = 10;
	//吸磁速度(1-3) 慢中快
	int magnetSpeed = 1;
	//距离磁棒底部百分比(1-100%)(百分比）
	int adsorbPosition = 1;
	//等待时间(Sec)
	int waitTime = 0;
	//温度状态
	int heatStatus = 0;
	//温度
	int targetTemp = 25;
	AXEStepData() {	}
	AXEStepData(const AXEStepData& _data)
	{
		stepIndex = _data.stepIndex;
		column = _data.column;
		stepName = _data.stepName;
		waitTime = _data.waitTime;
		mixTime = _data.mixTime;
		mixSpeed = _data.mixSpeed;
		magnetTime = _data.magnetTime;
		magnetSpeed = _data.magnetSpeed;
		volume = _data.volume;
		mixPos = _data.mixPos;
		mixAmplitude = _data.mixAmplitude;
		adsorbPosition = _data.adsorbPosition;
		heatStatus = _data.heatStatus;
		targetTemp = _data.targetTemp;
	}
	bool operator == (AXEStepData &_data) //把等于符号给重载了
	{
		return
			_data.stepIndex == stepIndex&&
			_data.column == column&&
			_data.stepName == stepName&&
			_data.waitTime == waitTime&&
			_data.mixTime == mixTime&&
			_data.mixSpeed == mixSpeed&&
			_data.magnetTime == magnetTime&&
			_data.magnetSpeed == magnetSpeed&&
			_data.volume == volume&&
			_data.mixPos == mixPos&&
			_data.mixAmplitude == mixAmplitude&&
			_data.adsorbPosition == adsorbPosition&&
			_data.heatStatus == heatStatus&&
			_data.targetTemp == targetTemp
			;
	}
};

//核提流程数据
struct AXEProcessData
{
	//流程名称
	QString processName;
	//步骤数量
	int stepCount = 0;
	//预计时长(秒)
	int duration = 0;
	//蛋白酶K量
	int volumeProteaseK = 0;
	//样本容量
	int volumeSample = 0;
	//发布状态
	bool isPublish = false;
	//创建日期(秒时间戳)
	int createDate;
	//步骤数据
	QList<AXEStepData> stepsList = {};
	AXEProcessData()
	{
		processName = GetLang("1708420099");
		createDate = QDateTime::currentDateTime().toSecsSinceEpoch();
	}
	AXEProcessData(const AXEProcessData& data)
	{
		processName = data.processName;
		stepCount = data.stepCount;
		duration = data.duration;
		volumeProteaseK = data.volumeProteaseK;
		volumeSample = data.volumeSample;
		isPublish = data.isPublish;
		createDate = data.createDate;
		for (AXEStepData _stepData : data.stepsList)
		{
			stepsList.append(AXEStepData(_stepData));
		}
	}
	bool operator == (AXEProcessData &_data) //把等于符号给重载了
	{
		bool isSame;
		isSame = _data.processName == processName;
		isSame = isSame &&  _data.stepCount == stepCount;
		isSame = isSame && _data.duration == duration;
		isSame = isSame && _data.volumeProteaseK == volumeProteaseK;
		isSame = isSame && _data.volumeSample == volumeSample;
		isSame = isSame && _data.createDate == createDate;
		isSame = isSame && _data.processName == processName;
		if (!isSame || stepsList.count() != _data.stepsList.count())
			return false;
		for (int i = 0; i < stepsList.count(); i++)
		{
			isSame = isSame && stepsList[i] == _data.stepsList[i];
		}
		return isSame;
	}

	int getDurationSec(int _startStepIndex = 0)
	{
		int second = 0;
		for (AXEStepData data : stepsList)
		{
			if (data.stepIndex > _startStepIndex)
			{
				second += data.waitTime;
				second += data.mixTime;
				second += data.magnetTime;
			}
		}
		return second;
	}

	//获取剩余时间
	int getRemainSec(int _stepIndex)
	{
		int second = 0;
		for (int i = _stepIndex; i < stepsList.count(); i++)
		{
			second += stepsList[_stepIndex].waitTime;
			second += stepsList[_stepIndex].mixTime;
			second += stepsList[_stepIndex].magnetTime;
		}
		return second;
	}
	int getDurationMin()
	{
		return qFloor(getDurationSec() / 60.0f);
	}
	QString getDurationStr()
	{
		int duration = getDurationSec();
		return Utility::ins().secondToString(duration);
	}
	//获取预估时间
	int getEstimatedTime(int currStepIndex = 0)
	{
		int duration = getDurationSec(currStepIndex);
		int offset = 25 * (stepCount - currStepIndex);
		return  duration + offset;
	}
};

class AXEMgr :public Singleton<AXEMgr>
{
public:
	AXEMgr();
	~AXEMgr();
	//---------------filed---------------
	//吸磁速度
	QList<QString> magnetSpeedStr = {};
	QString configFolderPath;
	//获取所有流程的名称
	QList<QString> AXEMgr::getAllProcessNames();

	//---------------function---------------
	AXEProcessData getProcessByName(QString _processName);
	QString getStepJsonStr(AXEStepData _stepData);
	QJsonArray getStepJsonArray(QList<AXEStepData> _stepList);
	AXEProcessData getPrecessByByte(QByteArray _byteArray);
	QList<AXEStepData> getStepModelsByValue(QJsonValue _jsonValue);
	QString getPrecessJsonStr(AXEProcessData _processData);
	QList<QString> checkKitTips(AXEProcessData _processModel);
	QString getMagnetSpeedStr(int _speed);
	//读取所有流程文件
	QList<AXEProcessData> getAllProcess();

	QString getMixBtStr(AXEStepData _data);
	QString getMagnetBtStr(AXEStepData _data);
	QString getWaitBtStr(AXEStepData _data);
};

