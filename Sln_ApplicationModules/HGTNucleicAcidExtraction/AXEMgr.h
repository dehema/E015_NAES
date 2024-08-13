#pragma once
#include "Common/Utility.h"
#include "Common/Singleton.h"

//�������̲�������
struct AXEStepData
{
	//���
	int stepIndex;
	//�ڼ���(1-6)
	int column = 1;
	//��������
	QString stepName;
	//��ϵ����(1-1000)
	int volume = 1;
	//���ʱ��(Sec)
	int mixTime = 10;
	//����ٶ�(200-3000)
	int mixSpeed = 200;
	//�������ײ�λ�� ����Ű��ײ��ٷֱ�(0-50%)
	int mixPos = 0;
	//����������λ�� ����Ű��ײ��ٷֱ�(0-100%)
	int mixAmplitude = 0;
	//����ʱ��(Sec)
	int magnetTime = 10;
	//�����ٶ�(1-3) ���п�
	int magnetSpeed = 1;
	//����Ű��ײ��ٷֱ�(1-100%)(�ٷֱȣ�
	int adsorbPosition = 1;
	//�ȴ�ʱ��(Sec)
	int waitTime = 0;
	//�¶�״̬
	int heatStatus = 0;
	//�¶�
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
	bool operator == (AXEStepData &_data) //�ѵ��ڷ��Ÿ�������
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

//������������
struct AXEProcessData
{
	//��������
	QString processName;
	//��������
	int stepCount = 0;
	//Ԥ��ʱ��(��)
	int duration = 0;
	//����øK��
	int volumeProteaseK = 0;
	//��������
	int volumeSample = 0;
	//����״̬
	bool isPublish = false;
	//��������(��ʱ���)
	int createDate;
	//��������
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
	bool operator == (AXEProcessData &_data) //�ѵ��ڷ��Ÿ�������
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

	//��ȡʣ��ʱ��
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
	//��ȡԤ��ʱ��
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
	//�����ٶ�
	QList<QString> magnetSpeedStr = {};
	QString configFolderPath;
	//��ȡ�������̵�����
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
	//��ȡ���������ļ�
	QList<AXEProcessData> getAllProcess();

	QString getMixBtStr(AXEStepData _data);
	QString getMagnetBtStr(AXEStepData _data);
	QString getWaitBtStr(AXEStepData _data);
};

