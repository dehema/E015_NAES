#pragma once
#include "Common/BasePageContent.h"
#include "Common/UIUtility.h"
#include "AXEMgr.h"
#include "AxeThread.h"

class AXERuningView : public BasePageContent
{
	Q_OBJECT
private:
	enum BtType {
		Continue,
		Pause,
		Reset,
		Close,
	};

public:
	AXERuningView(QWidget *parent);
	~AXERuningView() {};

	//--------------------UI--------------------
	QVBoxLayout* layoutMain;

	HLineEdit* editProcessName;
	QLabel* lbRemainTime;
	QLabel* lbStatus;

	//���
	HTableView* tbStep;
	HTableViewItemModel* tbModelProcess;

	//�¶�
	HLineEdit* editT1;
	HLineEdit* editT2;
	HLineEdit* editT3;
	HLineEdit* editT4;

	QPushButton* btContinue;
	QPushButton* btPause;
	QPushButton* btReset;
	//--------------------field--------------------
	QButtonGroup* btGroup;
	//��������
	AXEProcessData currProcessData;
	//��ǰ����
	AXEStepData currStepData;
	//����ʱ
	QTimer launchTimer;
	//�¶ȼ�ʱ��
	QTimer temperatureTimer;
	//ʣ��ʱ��
	float remainingTime = 0;
	int otherStepRemainingTime = 0;
	int stepDuration = 0;
	//�߳�
	AxeThread* axeThread;
	//--------------------function--------------------
	//���е���ʱ
	void launchTimeCountDown();
	void refreshTemperature();
	//����
	void launchContinue();
	//��ͣ
	void launchPause();
	//ֹͣ
	void launchReset();
	void launchProcess(AXEProcessData _data);
	//ˢ��״̬
	void refreshStatus();

	private slots:
	void slot_onclickBt(int);
	//���Ჽ�����
	void slot_onAxeStepLaunch(AXEStepData _stepData);
	//�����������
	void slot_onAxeProcessFinish(AXEProcessData _processData);

signals:
	void signal_closeRuningView();
};

