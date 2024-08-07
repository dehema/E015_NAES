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
	QLabel* lbSetHour;
	QLabel* lbSetMin;
	QPushButton* btStart;
	QPushButton* btStop;

	//--------------------field--------------------
	QButtonGroup* btGroup;
	int second;
	int setHour = 0;
	int setMinute = 15;
	QTimer* countDownTimer;

	//--------------------function--------------------
	void refreshTime();
	void countDown();

	public slots:
	void slot_onclickBt(int);
};

