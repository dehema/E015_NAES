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
	//��ǰ���е�����
	AXEProcessData currProcessData;
	//��ǰ��������
	int currStepIndex = 0;
	AXEStepData currStepData;
	QTimer checkStepFinishTimer;
	//״̬
	AXEDeviceStatus axeStatus = AXEDeviceStatus::AXEDeviceStatusDisable;

	//------------------------------function------------------------------
	void run() override;
	bool isIdle();
	bool isLaunch();
	//��������
	void launchAxeProcess(AXEProcessData data);
	//���в���
	void launchAxeStep(AXEStepData stepData);
	//��������Ƿ���ɣ������������¸�����
	void checkStepFinish();
	//�����¸�����
	void launchStepNext();
	//�������
	void processFinish();
	void setStatus(AXEDeviceStatus _axeStatus);
	//��λ ������ͣ
	void reset();

signals:
	void signal_onAxeStepLaunch(AXEStepData _stepData);
	void signal_onAxeProcessFinish(AXEProcessData _processData);
};

