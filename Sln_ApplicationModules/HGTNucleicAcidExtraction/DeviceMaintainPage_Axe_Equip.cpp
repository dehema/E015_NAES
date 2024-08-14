#include "DeviceMaintainPage_AXE_Equip.h"


const string g_ModuleName = "DeviceMaintainPage_Axe_Equip";
const string g_InitMsg = "the axe service is not init, please init first";

DeviceMaintainPage_Axe_Equip::DeviceMaintainPage_Axe_Equip(QWidget * _parent, DeviceControlService _handle) :
	DeviceMaintainPage_Axe_Base(_parent, _handle)
{

	btGroup = new QButtonGroup(this);
	connect(btGroup, SIGNAL(buttonClicked(int)), this, SLOT(slot_onclickBtGroup(int)));

	QHBoxLayout *layoutMain = getNewHBoxLayout(this);
	layoutMain->setAlignment(Qt::AlignCenter);
	layoutMain->setSpacing(15);

	QWidget* widgetLeft = getNewWidgetCommon();
	widgetLeft->setFixedSize(370, height());
	layoutMain->addWidget(widgetLeft);

	QGridLayout *layoutLeft = getNewGridLayout(widgetLeft);
	layoutLeft->setAlignment(Qt::AlignCenter);
	layoutLeft->setHorizontalSpacing(20);
	layoutLeft->setVerticalSpacing(25);

	//×°ÔØ´Å°ôÌ×
	m_btnLoadSleeve = getNewBtCommon("1708420297");
	layoutLeft->addWidget(m_btnLoadSleeve, 0, 0);

	m_edtLoadColumn = getNewComboxBox({ "1708420431","1708420432","1708420433","1708420434","1708420435","1708420436" });
	layoutLeft->addWidget(m_edtLoadColumn, 0, 1);

	m_lbLoadColumn = getNewLbCommon("1708420299");
	m_lbLoadColumn->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	m_lbLoadColumn->setFixedWidth(40);
	layoutLeft->addWidget(m_lbLoadColumn, 0, 2);

	//Ð¶ÔØ´Å°ôÌ×
	m_btnUnloadSleeve = getNewBtCommon("1708420298");
	layoutLeft->addWidget(m_btnUnloadSleeve, 1, 0);

	m_edtUnloadColumn = getNewComboxBox({ "1708420431","1708420432","1708420433","1708420434","1708420435","1708420436" });
	layoutLeft->addWidget(m_edtUnloadColumn, 1, 1);

	m_lbUnloadColumn = getNewLbCommon("1708420299");
	m_lbUnloadColumn->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	m_lbUnloadColumn->setFixedWidth(40);
	layoutLeft->addWidget(m_lbUnloadColumn, 1, 2);

	//·çÉÈ
	m_btnFanStart = getNewBtCommon("1708420289");
	layoutLeft->addWidget(m_btnFanStart, 2, 0);

	m_btnFanStop = getNewBtCommon("1708420290");
	layoutLeft->addWidget(m_btnFanStop, 2, 1);

	//²ÕÃÅ
	m_btnDoorOpen = getNewBtCommon("1708420293");
	layoutLeft->addWidget(m_btnDoorOpen, 3, 0);

	m_btnDoorClose = getNewBtCommon("1708420294");
	layoutLeft->addWidget(m_btnDoorClose, 3, 1);

	//ÕÕÃ÷µÆ
	m_btnLightOpen = getNewBtCommon("1708420295");
	layoutLeft->addWidget(m_btnLightOpen, 4, 0);

	m_btnLightClose = getNewBtCommon("1708420296");
	layoutLeft->addWidget(m_btnLightClose, 4, 1);


	QWidget* widgetRight = getNewWidgetCommon();
	widgetRight->setFixedSize(370, height());
	layoutMain->addWidget(widgetRight);

	QGridLayout *layoutRight = getNewGridLayout(widgetRight);
	layoutRight->setAlignment(Qt::AlignCenter);
	layoutRight->setHorizontalSpacing(20);
	layoutRight->setVerticalSpacing(25);

	//×ÏÍâµÆ
	m_btnUVStart = getNewBtCommon("1708420291");
	layoutRight->addWidget(m_btnUVStart, 0, 0);

	m_btnUVStop = getNewBtCommon("1708420292");
	layoutRight->addWidget(m_btnUVStop, 0, 1);

	QWidget* widgetUVTime = getNewWidgetCommon(widgetRight);
	widgetUVTime->setFixedSize(widgetRight->width(), 35);
	layoutRight->addWidget(widgetUVTime, 1, 0, 1, 2, Qt::AlignCenter);

	QHBoxLayout* layoutUVTime = getNewHBoxLayout(widgetUVTime);
	layoutUVTime->setSpacing(15);
	layoutUVTime->setAlignment(Qt::AlignCenter);

	QPushButton* btSubtractUVTime = getNewBtCommon();
	btSubtractUVTime->setText("-10Min");
	btSubtractUVTime->setFixedWidth(90);
	btGroup->addButton(btSubtractUVTime, BtType::SubtractUVTime);
	layoutUVTime->addWidget(btSubtractUVTime);

	editUVTime = getNewLineEdit();
	editUVTime->setFixedWidth(120);
	editUVTime->setAlignment(Qt::AlignCenter);
	editUVTime->setEnabled(false);
	layoutUVTime->addWidget(editUVTime);

	QPushButton* btAddUVTime = getNewBtCommon();
	btAddUVTime->setText("+10Min");
	btAddUVTime->setFixedWidth(75);
	btGroup->addButton(btAddUVTime, BtType::AddUVTime);
	layoutUVTime->addWidget(btAddUVTime);

	this->setConnection();

	if (axeService != nullptr)
		m_bOpen = true;
	refreshEditUVTime();
}

void DeviceMaintainPage_Axe_Equip::setConnection()
{
	connect(m_btnFanStart, SIGNAL(clicked()), this, SLOT(slot_btnStartFanClicked()));
	connect(m_btnFanStop, SIGNAL(clicked()), this, SLOT(slot_btnStopFanClicked()));
	connect(m_btnUVStart, SIGNAL(clicked()), this, SLOT(slot_btnStartUVClicked()));
	connect(m_btnUVStop, SIGNAL(clicked()), this, SLOT(slot_btnStopUVClicked()));
	connect(m_btnDoorOpen, SIGNAL(clicked()), this, SLOT(slot_btnOpenDoorClicked()));
	connect(m_btnDoorClose, SIGNAL(clicked()), this, SLOT(slot_btnCloseDoorClicked()));
	connect(m_btnLightOpen, SIGNAL(clicked()), this, SLOT(slot_btnLightOpenClicked()));
	connect(m_btnLightClose, SIGNAL(clicked()), this, SLOT(slot_btnLightCloseClicked()));
	connect(m_btnLoadSleeve, SIGNAL(clicked()), this, SLOT(slot_btnLoadSleeveClicked()));
	connect(m_btnUnloadSleeve, SIGNAL(clicked()), this, SLOT(slot_btnUnloadSleeveClicked()));
}

void DeviceMaintainPage_Axe_Equip::refreshEditUVTime()
{
	QString str =
		QString::number(timeUV.hour()).rightJustified(2, '0') + ":" +
		QString::number(timeUV.minute()).rightJustified(2, '0') + ":" +
		QString::number(timeUV.second()).rightJustified(2, '0');
	editUVTime->setText(str);
}

void DeviceMaintainPage_Axe_Equip::slot_btnLoadSleeveClicked()
{
	if (axeService == nullptr)
		return;

	if (m_edtLoadColumn->currentText().isEmpty())
	{
		HGT::warning(this, GetLang("1708420297"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}

	int column = m_edtLoadColumn->currentText().toInt();
	int retCode = axeService->loadMagneticBarSleeve(axeNumber, column);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Equip load sleeve failed retCode = !" + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Equip::slot_btnUnloadSleeveClicked()
{
	if (axeService == nullptr)
		return;

	if (m_edtUnloadColumn->currentText().isEmpty())
	{
		HGT::warning(this, GetLang("1708420298"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}
	int column = m_edtUnloadColumn->currentText().toInt();
	int retCode = axeService->unloadMagneticBarSleeve(axeNumber, column);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Equip unload sleeve failed retCode = !" + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Equip::slot_btnStartFanClicked()
{
	if (axeService == nullptr)
		return;

	int retCode = axeService->startFan(axeNumber);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Equip start fan failed retCode = !" + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Equip::slot_btnStopFanClicked()
{
	if (axeService == nullptr)
		return;

	int retCode = axeService->stopFan(axeNumber);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Equip stop fan failed retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Equip::slot_btnStartUVClicked()
{
	if (axeService == nullptr)
		return;

	//int retCode = axeService->startUV(axeNumber);
	//if (retCode != 0)
	//{
	//	QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
	//	Log("DeviceMaintainPage_Axe_Equip start uv failed retCode = " + strErrorCode.toStdString());
	//	return;
	//}
	if (timerUV != nullptr&&timerUV->isActive())
		timerUV->stop();
	timerUV = new QTimer(this);
	timerUV->start(1000);
	connect(timerUV, &QTimer::timeout, this, [this]() {
		timeUV = timeUV.addSecs(-1);
		editUVTime->setText(timeUV.toString("hh:mm:ss"));
		if (timeUV.second() <= 0)
		{
			slot_btnStopUVClicked();
		}
	});
}

void DeviceMaintainPage_Axe_Equip::slot_btnStopUVClicked()
{
	if (axeService == nullptr)
		return;

	int retCode = axeService->stopUV(axeNumber);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Equip stop uv failed retCode = " + strErrorCode.toStdString());
	}

	if (timerUV != nullptr&&timerUV->isActive())
		timerUV->stop();
	timeUV = QTime(0, 30);
	editUVTime->setText(timeUV.toString("hh:mm:ss"));
}

void DeviceMaintainPage_Axe_Equip::slot_btnOpenDoorClicked()
{
	if (axeService == nullptr)
		return;

	int retCode = axeService->openDoor(axeNumber);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("QFmEquipDoor open door failed retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Equip::slot_btnCloseDoorClicked()
{
	if (axeService == nullptr)
		return;

	int retCode = axeService->closeDoor(axeNumber);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("QFmEquipDoor close door failed retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Equip::slot_btnLightOpenClicked()
{
	if (axeService == nullptr)
		return;

	int retCode = axeService->openFloodLight(axeNumber);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("QFmEquipDoor open flood light failed retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Equip::slot_btnLightCloseClicked()
{
	if (axeService == nullptr)
		return;

	int retCode = axeService->closeFloodLight(axeNumber);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("QFmEquipDoor close flood light failed retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Equip::slot_onclickBtGroup(int _index)
{
	switch (_index)
	{
	case DeviceMaintainPage_Axe_Equip::SubtractUVTime:
	{
		if (timerUV != nullptr&&timerUV->isActive())
			return;
		if (timeUV.hour() == 0 && timeUV.minute() < 10)
		{
			timeUV = QTime(0, 0);
		}
		else
		{
			timeUV = timeUV.addSecs(-600);
		}
		refreshEditUVTime();
		break;
	}
	case DeviceMaintainPage_Axe_Equip::AddUVTime:
	{
		if (timerUV != nullptr&&timerUV->isActive())
			return;
		timeUV = timeUV.addSecs(600);
		refreshEditUVTime();
		break;
	}
	}
}