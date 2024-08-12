#include "DeviceMaintainPage_Axe_Status.h"

DeviceMaintainPage_Axe_Status::DeviceMaintainPage_Axe_Status(QWidget * _parent, DeviceControlService _handle) :
	DeviceMaintainPage_Axe_Base(_parent, _handle)
{
	this->setFixedSize(_parent->width(), parentWidget()->height());

	QGridLayout *layoutMain = getNewGridLayout(this);
	layoutMain->setSpacing(10);
	layoutMain->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
	layoutMain->setContentsMargins(0, 0, 0, 0);

	m_ckAutoGetStatus = getNewCheckBox("1708419973");
	layoutMain->addWidget(m_ckAutoGetStatus, 0, 0, 1, 6);

	//²½½øµç»ú×´Ì¬
	QHBoxLayout *layoutSM = getNewHBoxLayout();
	layoutSM->setSpacing(5);
	layoutSM->setAlignment(Qt::AlignCenter);
	layoutSM->setContentsMargins(0, 0, 0, 0);

	QGroupBox* gbSM = getNewGroupBox("1708420349", layoutSM);
	gbSM->setFixedSize(width(), 70);
	layoutMain->addWidget(gbSM, 1, 0, 1, 6);

	//Ë®Æ½
	m_lbSMChannel1 = getNewLbCommon("1708420350");
	m_lbSMChannel1->setFixedWidth(50);
	layoutSM->addWidget(m_lbSMChannel1);

	m_edtSMChannel1 = getNewLineEdit();
	layoutSM->addWidget(m_edtSMChannel1);

	m_lbSMChannel2 = getNewLbCommon("1708420351");
	m_lbSMChannel2->setFixedWidth(50);
	layoutSM->addWidget(m_lbSMChannel2);

	m_edtSMChannel2 = getNewLineEdit();
	layoutSM->addWidget(m_edtSMChannel2);

	m_lbSMChannel3 = getNewLbCommon("1708420352");
	m_lbSMChannel3->setFixedWidth(50);
	layoutSM->addWidget(m_lbSMChannel3);

	m_edtSMChannel3 = getNewLineEdit();
	layoutSM->addWidget(m_edtSMChannel3);

	m_lbSMChannel4 = getNewLbCommon("1708420353");
	m_lbSMChannel4->setFixedWidth(50);
	layoutSM->addWidget(m_lbSMChannel4);

	m_edtSMChannel4 = getNewLineEdit();
	layoutSM->addWidget(m_edtSMChannel4);

	m_lbSMChannel5 = getNewLbCommon("1708420354");
	m_lbSMChannel5->setFixedWidth(50);
	layoutSM->addWidget(m_lbSMChannel5);

	m_edtSMChannel5 = getNewLineEdit();
	layoutSM->addWidget(m_edtSMChannel5);

	//ÎÂ¿Ø°å×´Ì¬
	QHBoxLayout *layoutTemp = getNewHBoxLayout();
	layoutTemp->setSpacing(5);
	layoutTemp->setAlignment(Qt::AlignCenter);
	layoutTemp->setContentsMargins(0, 0, 0, 0);

	QGroupBox* gbTemp = getNewGroupBox("1708420356", layoutTemp);
	gbTemp->setFixedSize(width(), 70);
	layoutMain->addWidget(gbTemp, 2, 0, 1, 6);

	m_lbHBChannel1 = getNewLbCommon();
	m_lbHBChannel1->setMinimumWidth(50);
	m_lbHBChannel1->setText(GetLang("1708420250") + QString::number(1));
	layoutTemp->addWidget(m_lbHBChannel1);

	m_edtHBChannel1 = getNewLineEdit();
	m_edtHBChannel1->setMinimumWidth(50);
	m_edtHBChannel1->setReadOnly(true);
	layoutTemp->addWidget(m_edtHBChannel1);

	m_lbHBChannel2 = getNewLbCommon();
	m_lbHBChannel2->setMinimumWidth(50);
	m_lbHBChannel2->setText(GetLang("1708420250") + QString::number(2));
	layoutTemp->addWidget(m_lbHBChannel2);

	m_edtHBChannel2 = getNewLineEdit();
	m_edtHBChannel2->setFixedWidth(90);
	m_edtHBChannel2->setReadOnly(true);
	layoutTemp->addWidget(m_edtHBChannel2);

	m_lbHBChannel3 = getNewLbCommon();
	m_lbHBChannel3->setMinimumWidth(50);;
	m_lbHBChannel3->setText(GetLang("1708420250") + QString::number(3));
	layoutTemp->addWidget(m_lbHBChannel3);

	m_edtHBChannel3 = getNewLineEdit();
	m_edtHBChannel3->setFixedWidth(90);
	m_edtHBChannel3->setReadOnly(true);
	layoutTemp->addWidget(m_edtHBChannel3);

	m_lbHBChannel4 = getNewLbCommon();
	m_lbHBChannel4->setMinimumWidth(50);
	m_lbHBChannel4->setText(GetLang("1708420250") + QString::number(4));
	layoutTemp->addWidget(m_lbHBChannel4);

	m_edtHBChannel4 = getNewLineEdit();
	m_edtHBChannel4->setFixedWidth(90);
	m_edtHBChannel4->setReadOnly(true);
	layoutTemp->addWidget(m_edtHBChannel4);

	//·çÉÈ×´Ì¬
	m_lbFanStatus = getNewLbCommon("1708420357");
	layoutMain->addWidget(m_lbFanStatus, 3, 0);

	m_edtFanStatus = getNewLineEdit();
	layoutMain->addWidget(m_edtFanStatus, 3, 1);

	//ÕÕÃ÷µÆ×´Ì¬
	m_lbFloodLightStatus = getNewLbCommon("1708420358");
	layoutMain->addWidget(m_lbFloodLightStatus, 3, 2);

	m_edtFloodLightStatus = getNewLineEdit();
	layoutMain->addWidget(m_edtFloodLightStatus, 3, 3);

	//´Å°ôÌ××´Ì¬
	m_lbSleeveStatus = getNewLbCommon("1708420359");
	layoutMain->addWidget(m_lbSleeveStatus, 3, 4);

	m_edtSleeveStatus = getNewLineEdit();
	layoutMain->addWidget(m_edtSleeveStatus, 3, 5);

	//²ÕÃÅ×´Ì¬
	m_lbDoorStatus = getNewLbCommon("1708420360");
	layoutMain->addWidget(m_lbDoorStatus, 4, 0);

	m_edtDoorStatus = getNewLineEdit();
	layoutMain->addWidget(m_edtDoorStatus, 4, 1);

	//Á÷³ÌÊ¶±ðID
	m_lbProcessID = getNewLbCommon("1708420361");
	layoutMain->addWidget(m_lbProcessID, 4, 2);

	m_edtProcessID = getNewLineEdit();
	layoutMain->addWidget(m_edtProcessID, 4, 3);

	//ÌáÈ¡ÒÇ×´Ì¬
	m_lbAxeStatus = getNewLbCommon("1708420362");
	layoutMain->addWidget(m_lbAxeStatus, 4, 4);

	m_edtAxeStatus = getNewLineEdit();
	layoutMain->addWidget(m_edtAxeStatus, 4, 5);

	//Ô¤ÖÃ°å×´Ì¬
	m_lbPBStatus = getNewLbCommon("1708420363");
	layoutMain->addWidget(m_lbPBStatus, 5, 0);

	m_edtPBStatus = getNewLineEdit();
	layoutMain->addWidget(m_edtPBStatus, 5, 1);

	//À¬»øºÐ×´Ì¬
	m_lbTrashBoxStatus = getNewLbCommon("1708420364");
	layoutMain->addWidget(m_lbTrashBoxStatus, 5, 2);

	m_edtTrashBoxStatus = getNewLineEdit();
	layoutMain->addWidget(m_edtTrashBoxStatus, 5, 3);

	//´Å°ôÌ×ºÐ×´Ì¬
	m_lbSleeveBoxStatus = getNewLbCommon("1708420365");
	layoutMain->addWidget(m_lbSleeveBoxStatus, 5, 4);

	m_edtSleeveBoxStatus = getNewLineEdit();
	layoutMain->addWidget(m_edtSleeveBoxStatus, 5, 5);

	//×ÏÍâÏß×´Ì¬
	m_lbUVStatus = getNewLbCommon("1708420355");
	layoutMain->addWidget(m_lbUVStatus, 6, 0);

	m_edtUVStatus = getNewLineEdit();
	layoutMain->addWidget(m_edtUVStatus, 6, 1);

	this->setConnection();

	if (axeService != nullptr)
	{
		m_bOpen = true;
		connect(axeService, SIGNAL(signal_sendAxeStautsToUI(int, AXEModuleStatus)), this, SLOT(slot_recvAxeStatusData(int, AXEModuleStatus)));
	}
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