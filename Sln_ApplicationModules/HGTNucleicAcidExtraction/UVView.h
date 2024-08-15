#pragma once
#include "Common/BasePageContent.h"

class UVView : public BasePageContent
{
	Q_OBJECT

private:
	enum BtType {
		AddHour,
		ReduceHour,
		AddMinute,
		ReduceMinute,
		Launch,
		Stop,
	};
public:
	UVView(QWidget *parent);
	~UVView() {};

	//--------------------UI--------------------
	HLineEdit* editTime;
	QPushButton* btStart;
	QPushButton* btStop;

	//--------------------field--------------------
	QButtonGroup* btGroup;
	QTimer* countDownTimer;
	QTime countDownTime = QTime(0, 30);
	const int axeNumber = 1;
	DeviceControlService deviceService;

	//--------------------function--------------------
	void refreshTime();
	void countDown();

	public slots:
	void slot_onclickBt(int);
};

