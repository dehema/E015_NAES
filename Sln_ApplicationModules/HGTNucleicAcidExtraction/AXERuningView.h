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
	};

public:
	AXERuningView(QWidget *parent, AXEProcessData _data);
	~AXERuningView() {};

	//--------------------UI--------------------
	QVBoxLayout* layoutMain;

	HLineEdit* editProcessName;
	QLabel* lbRemainTime;
	QLabel* lbStatus;

	//表格
	HTableView* tbStep;
	QStandardItemModel* tbModelProcess;

	//温度
	HLineEdit* editT1;
	HLineEdit* editT2;
	HLineEdit* editT3;
	HLineEdit* editT4;

	QPushButton* btContinue;
	QPushButton* btPause;
	QPushButton* btReset;
	//--------------------field--------------------
	QButtonGroup* btGroup;
	//流程数据
	AXEProcessData currProcessData;
	//当前步骤
	AXEStepData currStepData;
	//倒计时
	QTimer launchTimer;
	//温度计时器
	QTimer temperatureTimer;
	//剩余时间
	float remainingTime = 0;
	int otherStepRemainingTime = 0;
	int stepDuration = 0;
	//线程
	AxeThread* axeThread;
	//--------------------function--------------------
	//运行倒计时
	void launchTimeCountDown();
	void refreshTemperature();
	//继续
	void launchContinue();
	//暂停
	void launchPause();
	//停止
	void launchReset();
	void launchProcess();
	//刷新状态
	void refreshStatus();

	public slots:
	void slot_onclickBt(int);
	//核酸步骤完成
	void slot_onAxeStepLaunch(AXEStepData _stepData);
	//核酸流程完成
	void slot_onAxeProcessFinish(AXEProcessData _processData);
};

