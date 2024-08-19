#include "UVView.h"


UVView::UVView(QWidget *parent) :BasePageContent(parent)
{
	deviceService = Utility::ins().deviceHandle;
	btGroup = new QButtonGroup(this);
	connect(btGroup, SIGNAL(buttonClicked(int)), this, SLOT(slot_onclickBt(int)));

	countDownTimer = new QTimer(this);
	countDownTimer->setInterval(1000);
	connect(countDownTimer, &QTimer::timeout, this, &UVView::countDown);

	QVBoxLayout* layoutMain = getNewVBoxLayout(this);
	layoutMain->setAlignment(Qt::AlignCenter);
	layoutMain->setSpacing(25);
	layoutMain->setContentsMargins(0, 0, 0, 0);

	QLabel* lb1 = getNewLbTitle();
	lb1->setFixedSize(getContentWidth(), 45);
	lb1->setText(GetLang("1708430046"));
	lb1->setAlignment(Qt::AlignCenter);
	layoutMain->addWidget(lb1);

	editTime = getNewLineEditLarge();
	editTime->setAlignment(Qt::AlignCenter);
	editTime->setEnabled(false);
	layoutMain->addWidget(editTime, 0, Qt::AlignCenter);

	QWidget* widgetHour = getNewWidgetCommon();
	widgetHour->setFixedSize(getContentWidth(), 55);
	layoutMain->addWidget(widgetHour);

	QHBoxLayout* layoutHour = getNewHBoxLayout(widgetHour);
	layoutHour->setAlignment(Qt::AlignCenter);
	layoutHour->setSpacing(30);

	QPushButton* btReduceHour = getNewBtLarge();
	btReduceHour->setText(GetLang("1708430061").arg("1"));
	btGroup->addButton(btReduceHour, BtType::ReduceHour);
	layoutHour->addWidget(btReduceHour);

	QPushButton* btAddHour = getNewBtLarge();
	btAddHour->setText(GetLang("1708430060").arg("1"));
	btGroup->addButton(btAddHour, BtType::AddHour);
	layoutHour->addWidget(btAddHour);

	QWidget* widgetMin = getNewWidgetCommon();
	widgetMin->setFixedSize(getContentWidth(), 55);
	layoutMain->addWidget(widgetMin);

	QHBoxLayout* layoutMin = getNewHBoxLayout(widgetMin);
	layoutMin->setAlignment(Qt::AlignCenter);
	layoutMin->setSpacing(30);

	QPushButton* btReduceMin = getNewBtLarge();
	btReduceMin->setText(GetLang("1708430063").arg("10"));
	btGroup->addButton(btReduceMin, BtType::ReduceMinute);
	layoutMin->addWidget(btReduceMin);

	QPushButton* btAddMin = getNewBtLarge();
	btAddMin->setText(GetLang("1708430062").arg("10"));
	btGroup->addButton(btAddMin, BtType::AddMinute);
	layoutMin->addWidget(btAddMin);

	btStart = getNewBtLarge("1708430050");
	btGroup->addButton(btStart, BtType::Launch);
	layoutMain->addWidget(btStart, 0, Qt::AlignCenter);

	btStop = getNewBtLarge("1708420348");
	btStop->setObjectName("bt_common_red");
	btStop->setVisible(countDownTimer->isActive());
	btGroup->addButton(btStop, BtType::Stop);
	layoutMain->addWidget(btStop, 0, Qt::AlignCenter);

	refreshTime();
}

void UVView::refreshTime()
{
	editTime->setText(countDownTime.toString("hh:mm:ss"));
}

void UVView::countDown()
{
	if (countDownTime.msecsSinceStartOfDay() == 0)
	{
		slot_onclickBt(UVView::Stop);
		return;
	}
	countDownTime = countDownTime.addSecs(-1);
	refreshTime();
}

void UVView::slot_onclickBt(int _index)
{
	switch (_index)
	{
	case UVView::AddHour:
	{
		countDownTime = countDownTime.addSecs(3600);
		refreshTime();
		break;
	}
	case UVView::ReduceHour:
	{
		if (countDownTime.msecsSinceStartOfDay() <= 3600000)
			return;
		countDownTime = countDownTime.addSecs(-3600);
		refreshTime();
		break;
	}
	case UVView::AddMinute:
	{
		countDownTime = countDownTime.addSecs(600);
		refreshTime();
		break;
	}
	case UVView::ReduceMinute:
	{
		if (countDownTime.msecsSinceStartOfDay() <= 600000)
			return;
		countDownTime = countDownTime.addSecs(-600);
		refreshTime();
		break;
	}
	case UVView::Launch:
		countDownTimer->start();
		btStart->setVisible(!countDownTimer->isActive());
		btStop->setVisible(countDownTimer->isActive());
		if (deviceService.axeService != nullptr)
			deviceService.axeService->startUV(axeNumber);
		countDown();
		break;
	case UVView::Stop:
		countDownTimer->stop();
		btStart->setVisible(!countDownTimer->isActive());
		btStop->setVisible(countDownTimer->isActive());
		if (deviceService.axeService != nullptr)
			deviceService.axeService->stopUV(axeNumber);
		countDownTime = QTime(0, 30);
		refreshTime();
		break;
	}
}