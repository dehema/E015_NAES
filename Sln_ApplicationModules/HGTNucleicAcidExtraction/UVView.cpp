#include "UVView.h"


UVView::UVView(QWidget *parent) :BasePageContent(parent)
{
	btGroup = new QButtonGroup(this);
	connect(btGroup, SIGNAL(buttonClicked(int)), this, SLOT(slot_onclickBt(int)));

	countDownTimer = new QTimer(this);
	countDownTimer->setInterval(1000);
	connect(countDownTimer, &QTimer::timeout, this, &UVView::countDown);

	QVBoxLayout* layoutMain = getNewVBoxLayout(this);
	layoutMain->setAlignment(Qt::AlignCenter);
	layoutMain->setSpacing(25);
	layoutMain->setContentsMargins(0, 0, 0, 0);

	QLabel* lb1 = getNewLbCommon();
	lb1->setFixedSize(getContentWidth(), 35);
	lb1->setText(GetLang("1708430046"));
	lb1->setAlignment(Qt::AlignCenter);
	layoutMain->addWidget(lb1);

	editTime = getNewLineEdit();
	editTime->setFixedSize(180, 35);
	editTime->setAlignment(Qt::AlignCenter);
	editTime->setEnabled(false);
	editTime->setText("00:00:00");
	layoutMain->addWidget(editTime, 0, Qt::AlignCenter);

	QWidget* widgetHour = getNewWidgetCommon();
	widgetHour->setFixedSize(getContentWidth(), 35);
	layoutMain->addWidget(widgetHour);

	QHBoxLayout* layoutHour = getNewHBoxLayout(widgetHour);
	layoutHour->setSpacing(20);
	layoutHour->setAlignment(Qt::AlignCenter);

	QPushButton* btAddHour = getNewBtCommon();
	btAddHour->setObjectName("KitEditorAddStage");
	btAddHour->setFixedSize(widgetHour->height(), widgetHour->height());
	btGroup->addButton(btAddHour, BtType::AddHour);
	layoutHour->addWidget(btAddHour);

	lbSetHour = getNewLbCommon();
	lbSetHour->setText(GetLang("1708430049").arg(setHour));
	lbSetHour->setFixedWidth(90);
	lbSetHour->setAlignment(Qt::AlignCenter);
	layoutHour->addWidget(lbSetHour);

	QPushButton* btReduceHour = getNewBtCommon();
	btReduceHour->setObjectName("KitEditorSubtractStage");
	btReduceHour->setFixedSize(widgetHour->height(), widgetHour->height());
	btGroup->addButton(btReduceHour, BtType::ReduceHour);
	layoutHour->addWidget(btReduceHour);

	QWidget* widgetMin = getNewWidgetCommon();
	widgetMin->setFixedSize(getContentWidth(), 35);
	layoutMain->addWidget(widgetMin);

	QHBoxLayout* layoutMin = getNewHBoxLayout(widgetMin);
	layoutMin->setAlignment(Qt::AlignCenter);
	layoutMin->setSpacing(20);

	QPushButton* btAddMin = getNewBtCommon();
	btAddMin->setObjectName("KitEditorAddStage");
	btAddMin->setFixedSize(widgetMin->height(), widgetMin->height());
	btGroup->addButton(btAddMin, BtType::AddMinute);
	layoutMin->addWidget(btAddMin);

	lbSetMin = getNewLbCommon();
	lbSetMin->setText(GetLang("1708430045").arg(setMinute));
	lbSetMin->setFixedWidth(90);
	lbSetMin->setAlignment(Qt::AlignCenter);
	layoutMin->addWidget(lbSetMin);

	QPushButton* btReduceMin = getNewBtCommon();
	btReduceMin->setObjectName("KitEditorSubtractStage");
	btReduceMin->setFixedSize(widgetMin->height(), widgetMin->height());
	btGroup->addButton(btReduceMin, BtType::ReduceMinute);
	layoutMin->addWidget(btReduceMin);

	btStart = getNewBtCommon("1708430050");
	btGroup->addButton(btStart, BtType::Launch);
	layoutMain->addWidget(btStart, 0, Qt::AlignCenter);

	btStop = getNewBtCommon("1708420348");
	btStop->setObjectName("bt_common_red");
	btStop->setVisible(countDownTimer->isActive());
	btGroup->addButton(btStop, BtType::Stop);
	layoutMain->addWidget(btStop, 0, Qt::AlignCenter);
}

void UVView::refreshTime()
{
	int _hour = second / 3600;
	QString hourStr = QString::number(_hour).rightJustified(2, '0');
	int _minute = second / 60;
	QString minuteStr = QString::number(_minute).rightJustified(2, '0');
	int _second = second % 60;
	QString secondStr = QString::number(_second).rightJustified(2, '0');
	editTime->setText(hourStr + ":" + minuteStr + ":" + secondStr);
}

void UVView::countDown()
{
	if (second == 0)
	{
		countDownTimer->stop();
		btStart->setVisible(!countDownTimer->isActive());
		btStop->setVisible(countDownTimer->isActive());
		return;
	}
	second--;
	refreshTime();
}

void UVView::slot_onclickBt(int _index)
{
	switch (_index)
	{
	case UVView::AddHour:
	{
		setHour++;
		lbSetHour->setText(GetLang("1708430049").arg(setHour));
		break;
	}
	case UVView::ReduceHour:
	{
		if (setHour > 0)
			setHour--;
		lbSetHour->setText(GetLang("1708430049").arg(setHour));
		break;
	}
	case UVView::AddMinute:
	{
		setMinute++;
		lbSetMin->setText(GetLang("1708430045").arg(setMinute));
		break;
	}
	case UVView::ReduceMinute:
	{
		if (setMinute > 0)
			setMinute--;
		lbSetMin->setText(GetLang("1708430045").arg(setMinute));
		break;
	}
	case UVView::Launch:
		second = setHour * 3600 + setMinute * 60;
		countDownTimer->start();
		btStart->setVisible(!countDownTimer->isActive());
		btStop->setVisible(countDownTimer->isActive());
		countDown();
		break;
	case UVView::Stop:
		countDownTimer->stop();
		btStart->setVisible(!countDownTimer->isActive());
		btStop->setVisible(countDownTimer->isActive());
		editTime->setText("00:00:00");
		break;
	default:
		break;
	}
}