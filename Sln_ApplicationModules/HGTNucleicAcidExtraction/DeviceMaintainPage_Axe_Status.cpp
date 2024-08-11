#include "DeviceMaintainPage_Axe_Status.h"

DeviceMaintainPage_Axe_Status::DeviceMaintainPage_Axe_Status(QWidget * _parent, DeviceControlService _handle) :
	DeviceMaintainPage_Axe_Base(_parent, _handle)
{
	this->setFixedSize(ContentPage_WIDTH, parentWidget()->height());
	QVBoxLayout *m_vblMain = getNewVBoxLayout(this);
	m_vblMain->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
	m_vblMain->setContentsMargins(20, 0, 20, 20);
	this->initAreas();

	m_vblMain->addWidget(m_qfmArea1);
	m_vblMain->addWidget(m_qfmArea1);
	m_vblMain->addWidget(m_qfmArea3);
	m_vblMain->addWidget(m_qfmArea5);
	m_vblMain->addWidget(m_qfmArea8);
	m_vblMain->addWidget(m_qfmArea11);

	this->setConnection();

	if (axeService != nullptr)
	{
		m_bOpen = true;
		connect(axeService, SIGNAL(signal_sendAxeStautsToUI(int, AXEModuleStatus)), this, SLOT(slot_recvAxeStatusData(int, AXEModuleStatus)));
	}
}

void DeviceMaintainPage_Axe_Status::initWidgetArea1()
{
	m_hblArea1 = new QHBoxLayout();
	m_hblArea1->setSpacing(20);
	m_hblArea1->setContentsMargins(0, 0, 0, 0);

	m_ckAutoGetStatus = getNewCheckBox("1708419973");
	m_hblArea1->addWidget(m_ckAutoGetStatus, 0, Qt::AlignLeft);

	m_hblArea1->addStretch();
}

void DeviceMaintainPage_Axe_Status::initWidgetArea2()
{
	m_hblArea2 = new QHBoxLayout();
	m_hblArea2->setSpacing(20);
	m_hblArea2->setContentsMargins(0, 0, 0, 0);

	m_lbStepMonitorStatus = getNewLbCommon("1708420349");
	m_lbStepMonitorStatus->setMinimumWidth(90);
	m_lbStepMonitorStatus->setAlignment(Qt::AlignCenter);
	m_hblArea2->addWidget(m_lbStepMonitorStatus);

	m_lbSMChannel1 = getNewLbCommon("1708420350");
	m_lbSMChannel1->setMinimumWidth(50);
	m_lbSMChannel1->setAlignment(Qt::AlignCenter);
	m_hblArea2->addWidget(m_lbSMChannel1);

	m_edtSMChannel1 = getNewLineEdit();
	m_edtSMChannel1->setFixedWidth(90);
	m_edtSMChannel1->setReadOnly(true);
	m_hblArea2->addWidget(m_edtSMChannel1);

	m_lbSMChannel2 = getNewLbCommon("1708420351");
	m_lbSMChannel2->setMinimumWidth(50);
	m_lbSMChannel2->setAlignment(Qt::AlignCenter);
	m_hblArea2->addWidget(m_lbSMChannel2);

	m_edtSMChannel2 = getNewLineEdit();
	m_edtSMChannel2->setFixedWidth(90);
	m_edtSMChannel2->setReadOnly(true);
	m_hblArea2->addWidget(m_edtSMChannel2);

	m_lbSMChannel3 = getNewLbCommon("1708420352");
	m_lbSMChannel3->setMinimumWidth(50);
	m_lbSMChannel3->setAlignment(Qt::AlignCenter);
	m_hblArea2->addWidget(m_lbSMChannel3);

	m_edtSMChannel3 = getNewLineEdit();
	m_edtSMChannel3->setFixedWidth(90);
	m_edtSMChannel3->setReadOnly(true);
	m_hblArea2->addWidget(m_edtSMChannel3);

	m_lbSMChannel4 = getNewLbCommon("1708420353");
	m_lbSMChannel4->setMinimumWidth(50);
	m_lbSMChannel4->setAlignment(Qt::AlignCenter);
	m_hblArea2->addWidget(m_lbSMChannel4);

	m_edtSMChannel4 = getNewLineEdit();
	m_edtSMChannel4->setFixedWidth(90);
	m_edtSMChannel4->setReadOnly(true);
	m_hblArea2->addWidget(m_edtSMChannel4);

	m_lbSMChannel5 = getNewLbCommon("1708420354");
	m_lbSMChannel5->setMinimumWidth(50);
	m_lbSMChannel5->setAlignment(Qt::AlignCenter);
	m_hblArea2->addWidget(m_lbSMChannel5);

	m_edtSMChannel5 = getNewLineEdit();
	m_edtSMChannel5->setFixedWidth(90);
	m_edtSMChannel5->setReadOnly(true);
	m_hblArea2->addWidget(m_edtSMChannel5);

	m_hblArea2->addStretch();
}

void DeviceMaintainPage_Axe_Status::initWidgetArea4()
{
	m_hblArea4 = new QHBoxLayout();
	m_hblArea4->setSpacing(20);
	m_hblArea4->setContentsMargins(0, 0, 0, 0);

	m_lbHeatBoardStatus = getNewLbCommon("1708420356");
	m_lbHeatBoardStatus->setMinimumWidth(90);
	m_lbHeatBoardStatus->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbHeatBoardStatus);

	m_lbHBChannel1 = getNewLbCommon();
	m_lbHBChannel1->setMinimumWidth(50);
	m_lbHBChannel1->setText(GetLang("1708420250") + QString::number(1));
	m_lbHBChannel1->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbHBChannel1);

	m_edtHBChannel1 = getNewLineEdit();
	m_edtHBChannel1->setFixedWidth(90);
	m_edtHBChannel1->setReadOnly(true);
	m_hblArea4->addWidget(m_edtHBChannel1);

	m_lbHBChannel2 = getNewLbCommon();
	m_lbHBChannel2->setMinimumWidth(50);
	m_lbHBChannel2->setText(GetLang("1708420250") + QString::number(2));
	m_lbHBChannel2->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbHBChannel2);

	m_edtHBChannel2 = getNewLineEdit();
	m_edtHBChannel2->setFixedWidth(90);
	m_edtHBChannel2->setReadOnly(true);
	m_hblArea4->addWidget(m_edtHBChannel2);

	m_lbHBChannel3 = getNewLbCommon();
	m_lbHBChannel3->setMinimumWidth(50);
	m_lbHBChannel3->setText(GetLang("1708420250") + QString::number(3));
	m_lbHBChannel3->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbHBChannel3);

	m_edtHBChannel3 = getNewLineEdit();
	m_edtHBChannel3->setFixedWidth(90);
	m_edtHBChannel3->setReadOnly(true);
	m_hblArea4->addWidget(m_edtHBChannel3);

	m_lbHBChannel4 = getNewLbCommon();
	m_lbHBChannel4->setMinimumWidth(50);
	m_lbHBChannel4->setText(GetLang("1708420250") + QString::number(4));
	m_lbHBChannel4->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbHBChannel4);

	m_edtHBChannel4 = getNewLineEdit();
	m_edtHBChannel4->setFixedWidth(90);
	m_edtHBChannel4->setReadOnly(true);
	m_hblArea4->addWidget(m_edtHBChannel4);

	m_hblArea4->addStretch();
}

void DeviceMaintainPage_Axe_Status::initWidgetArea5()
{
	m_hblArea5 = new QHBoxLayout();
	m_hblArea5->setSpacing(20);
	m_hblArea5->setContentsMargins(0, 0, 0, 0);

	m_lbFanStatus = getNewLbCommon("1708420357");
	m_lbFanStatus->setMinimumWidth(90);
	m_lbFanStatus->setAlignment(Qt::AlignCenter);
	m_hblArea5->addWidget(m_lbFanStatus, 0, Qt::AlignLeft);

	m_edtFanStatus = getNewLineEdit();
	m_edtFanStatus->setReadOnly(true);
	m_hblArea5->addWidget(m_edtFanStatus, 0, Qt::AlignLeft);

	m_lbFloodLightStatus = getNewLbCommon("1708420358");
	m_lbFloodLightStatus->setMinimumWidth(90);
	m_lbFloodLightStatus->setAlignment(Qt::AlignCenter);
	m_hblArea5->addWidget(m_lbFloodLightStatus, 0, Qt::AlignLeft);

	m_edtFloodLightStatus = getNewLineEdit();
	m_edtFloodLightStatus->setReadOnly(true);
	m_hblArea5->addWidget(m_edtFloodLightStatus, 0, Qt::AlignLeft);

	m_lbSleeveStatus = getNewLbCommon("1708420359");
	m_lbSleeveStatus->setMinimumWidth(90);
	m_lbSleeveStatus->setAlignment(Qt::AlignCenter);
	m_hblArea5->addWidget(m_lbSleeveStatus, 0, Qt::AlignLeft);

	m_edtSleeveStatus = getNewLineEdit();
	m_edtSleeveStatus->setReadOnly(true);
	m_hblArea5->addWidget(m_edtSleeveStatus, 0, Qt::AlignLeft);

	m_lbUVStatus = getNewLbCommon("1708420355");
	m_lbUVStatus->setMinimumWidth(90);
	m_lbUVStatus->setAlignment(Qt::AlignCenter);
	m_hblArea5->addWidget(m_lbUVStatus, 0, Qt::AlignLeft);

	m_edtUVStatus = getNewLineEdit();
	m_edtUVStatus->setReadOnly(true);
	m_hblArea5->addWidget(m_edtUVStatus, 0, Qt::AlignLeft);

	m_hblArea5->addStretch();
}

void DeviceMaintainPage_Axe_Status::initWidgetArea8()
{
	m_hblArea8 = new QHBoxLayout();
	m_hblArea8->setSpacing(20);
	m_hblArea8->setContentsMargins(0, 0, 0, 0);

	m_lbDoorStatus = getNewLbCommon("1708420360");
	m_lbDoorStatus->setMinimumWidth(90);
	m_lbDoorStatus->setAlignment(Qt::AlignCenter);
	m_hblArea8->addWidget(m_lbDoorStatus, 0, Qt::AlignLeft);

	m_edtDoorStatus = getNewLineEdit();
	m_edtDoorStatus->setReadOnly(true);
	m_hblArea8->addWidget(m_edtDoorStatus, 0, Qt::AlignLeft);

	m_lbProcessID = getNewLbCommon("1708420361");
	m_lbProcessID->setMinimumWidth(90);
	m_lbProcessID->setAlignment(Qt::AlignCenter);
	m_hblArea8->addWidget(m_lbProcessID, 0, Qt::AlignLeft);

	m_edtProcessID = getNewLineEdit();
	m_edtProcessID->setReadOnly(true);
	m_hblArea8->addWidget(m_edtProcessID, 0, Qt::AlignLeft);

	m_lbAxeStatus = getNewLbCommon("1708420362");
	m_lbAxeStatus->setMinimumWidth(90);
	m_lbAxeStatus->setAlignment(Qt::AlignCenter);
	m_hblArea8->addWidget(m_lbAxeStatus, 0, Qt::AlignLeft);

	m_edtAxeStatus = getNewLineEdit();
	m_edtAxeStatus->setReadOnly(true);
	m_hblArea8->addWidget(m_edtAxeStatus, 0, Qt::AlignLeft);

	m_hblArea8->addStretch();
}

void DeviceMaintainPage_Axe_Status::initWidgetArea11()
{
	m_lbPBStatus = getNewLbCommon("1708420363");
	m_lbPBStatus->setMinimumWidth(90);
	m_lbPBStatus->setAlignment(Qt::AlignCenter);

	m_edtPBStatus = getNewLineEdit();
	m_edtPBStatus->setReadOnly(true);

	m_lbTrashBoxStatus = getNewLbCommon("1708420364");
	m_lbTrashBoxStatus->setMinimumWidth(90);
	m_lbTrashBoxStatus->setAlignment(Qt::AlignCenter);

	m_edtTrashBoxStatus = getNewLineEdit();
	m_edtTrashBoxStatus->setReadOnly(true);

	m_lbSleeveBoxStatus = getNewLbCommon("1708420365");
	m_lbSleeveBoxStatus->setMinimumWidth(90);
	m_lbSleeveBoxStatus->setAlignment(Qt::AlignCenter);

	m_edtSleeveBoxStatus = getNewLineEdit();
	m_edtSleeveBoxStatus->setReadOnly(true);

	m_hblArea11 = new QHBoxLayout();
	m_hblArea11->setSpacing(20);
	m_hblArea11->setContentsMargins(0, 0, 0, 0);
	m_hblArea11->addWidget(m_lbPBStatus, 0, Qt::AlignLeft);
	m_hblArea11->addWidget(m_edtPBStatus, 0, Qt::AlignLeft);
	m_hblArea11->addWidget(m_lbTrashBoxStatus, 0, Qt::AlignLeft);
	m_hblArea11->addWidget(m_edtTrashBoxStatus, 0, Qt::AlignLeft);
	m_hblArea11->addWidget(m_lbSleeveBoxStatus, 0, Qt::AlignLeft);
	m_hblArea11->addWidget(m_edtSleeveBoxStatus, 0, Qt::AlignLeft);
	m_hblArea11->addStretch();
}


void DeviceMaintainPage_Axe_Status::initAreas()
{
	this->initWidgetArea1();
	this->initWidgetArea2();
	this->initWidgetArea4();
	this->initWidgetArea5();
	this->initWidgetArea8();
	this->initWidgetArea11();

	m_qfmArea1 = new QFrame();
	m_qfmArea1 = new QFrame();
	m_qfmArea3 = new QFrame();
	m_qfmArea5 = new QFrame();
	m_qfmArea8 = new QFrame();
	m_qfmArea11 = new QFrame();

	m_qfmArea1->setFixedSize(ContentPage_WIDTH, 50);
	m_qfmArea1->setLayout(m_hblArea1);

	m_qfmArea1->setFixedSize(ContentPage_WIDTH, 50);
	m_qfmArea1->setLayout(m_hblArea2);

	m_qfmArea3->setFixedSize(ContentPage_WIDTH, 50);
	m_qfmArea3->setLayout(m_hblArea4);

	m_qfmArea5->setFixedSize(ContentPage_WIDTH, 50);
	m_qfmArea5->setLayout(m_hblArea5);

	m_qfmArea8->setFixedSize(ContentPage_WIDTH, 50);
	m_qfmArea8->setLayout(m_hblArea8);

	m_qfmArea11->setFixedSize(ContentPage_WIDTH, 50);
	m_qfmArea11->setLayout(m_hblArea11);
}

void DeviceMaintainPage_Axe_Status::setConnection()
{
	connect(m_ckAutoGetStatus, SIGNAL(stateChanged(int)), this, SLOT(slot_onStateChanged(int)));
}

void DeviceMaintainPage_Axe_Status::slot_recvAxeStatusData(int axeNumber, AXEModuleStatus status)
{
	QString strTemp;

	/* ²½½øµç»ú×´Ì¬ */
	for (int index = 0; index < 5; index++)
	{
		switch (status.stepMonitorStatus[index])
		{
		case StepMonitorStatusDisable:
			strTemp = GetLang("1708420103");
			break;
		case StepMonitorStatusFree:
			strTemp = GetLang("1708420366");
			break;
		case StepMonitorStatusRunning:
			strTemp = GetLang("1708420367");
			break;
		default:
			strTemp = QString::number(status.stepMonitorStatus[index]);
		}

		switch (index)
		{
		case 0:
			m_edtSMChannel1->setText(strTemp);
			break;
		case 1:
			m_edtSMChannel2->setText(strTemp);
			break;
		case 2:
			m_edtSMChannel3->setText(strTemp);
			break;
		case 3:
			m_edtSMChannel4->setText(strTemp);
			break;
		case 4:
			m_edtSMChannel5->setText(strTemp);
			break;
		}
	}

	/* ÎÂ¿Ø°å×´Ì¬ */
	for (int index = 0; index < 4; index++)
	{
		switch (status.heatBoardStatus[index])
		{
		case HeatBoardStatusDisable:
			strTemp = GetLang("1708420103");
			break;
		case HeatBoardStatusOpen:
			strTemp = GetLang("1708420164");
			break;
		case HeatBoardStatusClose:
			strTemp = GetLang("1708420165");
			break;
		case HeatBoardStatusError:
			strTemp = GetLang("1708420368");
			break;
		default:
			strTemp = QString::number(status.stepMonitorStatus[index]);
		}

		switch (index)
		{
		case 0:
			m_edtHBChannel1->setText(strTemp);
			break;
		case 1:
			m_edtHBChannel2->setText(strTemp);
			break;
		case 2:
			m_edtHBChannel3->setText(strTemp);
			break;
		case 3:
			m_edtHBChannel4->setText(strTemp);
			break;
		}
	}

	/* ·çÉÈ×´Ì¬ */
	switch (status.fanStatus)
	{
	case FanStatusDisable:
		strTemp = GetLang("1708420103");
		break;
	case FanStatusOpen:
		strTemp = GetLang("1708420164");
		break;
	case FanStatusClose:
		strTemp = GetLang("1708420165");
		break;
	default:
		strTemp = QString::number(status.fanStatus);
	}
	m_edtFanStatus->setText(strTemp);

	/* ×ÏÍâµÆ×´Ì¬ */
	switch (status.uvLampStatus)
	{
	case UVLampStatusOpen:
		strTemp = GetLang("1708420164");
		break;
	case UVLampStatusClose:
		strTemp = GetLang("1708420165");
		break;
	default:
		strTemp = QString::number(status.uvLampStatus);
	}
	m_edtUVStatus->setText(strTemp);

	/* Ô¤ÖÃ°å×´Ì¬ */
	switch (status.presetBoardStatus)
	{
	case PresetBoardInPosition:
		strTemp = GetLang("1708420369");
		break;
	case PresetBoardNotInPosition:
		strTemp = GetLang("1708420370");
		break;
	default:
		strTemp = QString::number(status.presetBoardStatus);
	}
	m_edtPBStatus->setText(strTemp);

	/* ´Å°ôÌ×ºÐ×´Ì¬ */
	switch (status.magneticBarSleeveBoxStatus)
	{
	case MagneticBarSleeveBoxInPosition:
		strTemp = GetLang("1708420369");
		break;
	case MagneticBarSleeveBoxNotInPosition:
		strTemp = GetLang("1708420370");
		break;
	default:
		strTemp = QString::number(status.magneticBarSleeveBoxStatus);
	}
	m_edtSleeveBoxStatus->setText(strTemp);

	/* ½ø³ö²Ö×´Ì¬ */
	switch (status.doorStatus)
	{
	case DoorStatusUnknown:
		strTemp = GetLang("1708420371");
		break;
	case DoorStatusClose:
		strTemp = GetLang("1708420294");
		break;
	case DoorStatusOpen:
		strTemp = GetLang("1708420293");
		break;
	default:
		strTemp = QString::number(status.doorStatus);
	}
	m_edtDoorStatus->setText(strTemp);

	/* Á÷³ÌID */
	m_edtProcessID->setText(QString::number(status.processID));

	/* ºËËáÌáÈ¡ÒÇ×´×´Ì¬ */
	switch (status.axeDeviceStatus)
	{
	case AXEDeviceStatusDisable:
		strTemp = GetLang("1708420103");
		break;
	case AXEDeviceStatusFree:
		strTemp = GetLang("1708420366");
		break;
	case AXEDeviceStatusInit:
		strTemp = GetLang("1708420372");
		break;
	case AXEDeviceStatusExecuting:
		strTemp = GetLang("1708420373");
		break;
	case AXEDeviceStatusPause:
		strTemp = GetLang("1708420162");
		break;
	case AXEDeviceStatusStop:
		strTemp = GetLang("1708420348");
		break;
	case AXEDeviceStatusException:
		strTemp = GetLang("1708420374");
		break;
	case AXEDeviceStatusFinish:
		strTemp = GetLang("1708420375");
		break;
	default:
		strTemp = QString::number(status.axeDeviceStatus);
	}
	m_edtAxeStatus->setText(strTemp);

	/* ´Å°ôÌ×À¬»øºÐ×´Ì¬ */
	switch (status.sleeveTrashBoxStatus)
	{
	case SleeveTrashBoxInPosition:
		strTemp = GetLang("1708420369");
		break;
	case SleeveTrashBoxNotInPosition:
		strTemp = GetLang("1708420370");
		break;
	default:
		strTemp = QString::number(status.sleeveTrashBoxStatus);
	}
	m_edtTrashBoxStatus->setText(strTemp);

	/* ÕÕÃ÷µÆ×´Ì¬ */
	switch (status.floodLightStatus)
	{
	case FloodLightOpen:
		strTemp = GetLang("1708420164");
		break;
	case FloodLightClose:
		strTemp = GetLang("1708420165");
		break;
	default:
		strTemp = QString::number(status.floodLightStatus);
	}
	m_edtFloodLightStatus->setText(strTemp);

	/* ´Å°ôÌ××´Ì¬ */
	switch (status.magneticBarSleeveStatus)
	{
	case MagneticBarSleeveStatusNo:
		strTemp = GetLang("1708420371");
		break;
	case MagneticBarSleeveStatusLoad:
		strTemp = GetLang("1708420376");
		break;
	case MagneticBarSleeveStatusUnload:
		strTemp = GetLang("1708420377");
		break;
	default:
		strTemp = QString::number(status.magneticBarSleeveStatus);
	}
	m_edtSleeveStatus->setText(strTemp);
}

void DeviceMaintainPage_Axe_Status::slot_onStateChanged(int state)
{
	if (!m_bOpen)
	{
		m_ckAutoGetStatus->setCheckState(Qt::CheckState::Unchecked);
		return;
	}

	if (state == Qt::Checked)
	{
		axeService->setAutoGetAxeStatus(true);
	}
	else
	{
		axeService->setAutoGetAxeStatus(false);
	}
}