#include "DeviceMaintainPage_Axe_Setting.h"

const string g_ModuleName = "DeviceMaintainPage_Axe_Setting";
const string g_InitMsg = "the axe service is not init, please init first";

//核酸提取仪-高级设置
DeviceMaintainPage_Axe_Setting::DeviceMaintainPage_Axe_Setting(QWidget * _parent, DeviceControlService _handle) :
	DeviceMaintainPage_Axe_Base(_parent, _handle)
{
	QVBoxLayout *m_vblMain = getNewVBoxLayout(this);
	//m_vblMain->setContentsMargins(15, 0, 0, 0);
	m_vblMain->setSpacing(20);
	m_vblMain->setAlignment(Qt::AlignCenter);
	this->initAreas();

	m_vblMain->addWidget(m_qfmArea1);
	m_vblMain->addWidget(m_qfmArea5);
	m_vblMain->addWidget(m_qfmArea3);
	m_vblMain->addWidget(m_qfmArea6);
	m_vblMain->addWidget(m_qfmArea7);
	m_vblMain->addWidget(m_qfmArea8);

	this->setFixedSize(parentWidget()->width(), parentWidget()->height());
	this->setConnection();

	if (axeService != nullptr)
		m_bOpen = true;
}

void DeviceMaintainPage_Axe_Setting::initWidgetArea1()
{
	m_qfmArea1 = getNewWidgetCommon();
	m_qfmArea1->setFixedSize(parentWidget()->width(), 50);
	m_hblArea2 = getNewHBoxLayout(m_qfmArea1);
	m_hblArea2->setSpacing(15);

	m_btnQueryDoorPos = getNewBtCommon("1708420323");
	m_hblArea2->addWidget(m_btnQueryDoorPos);

	m_btnSetDoorPos = getNewBtCommon("1708420326");
	m_hblArea2->addWidget(m_btnSetDoorPos);

	m_lbSetBZero = getNewLbCommon("1708420324");
	m_lbSetBZero->setAlignment(Qt::AlignCenter);
	m_hblArea2->addWidget(m_lbSetBZero);
	m_edtSetBZero = getNewLineEdit();
	m_edtSetBZero->setPlaceholderText(QString::fromLocal8Bit("(mm)"));
	m_hblArea2->addWidget(m_edtSetBZero);

	m_lbSetAZero = getNewLbCommon("1708420325");
	m_lbSetAZero->setAlignment(Qt::AlignCenter);
	m_hblArea2->addWidget(m_lbSetAZero);

	m_edtSetAzero = getNewLineEdit();
	m_edtSetAzero->setPlaceholderText(QString::fromLocal8Bit("(mm)"));
	m_hblArea2->addWidget(m_edtSetAzero);

	m_hblArea2->addStretch();
}

void DeviceMaintainPage_Axe_Setting::initWidgetArea2()
{
	m_qfmArea2 = getNewWidgetCommon();
	m_qfmArea2->setFixedSize(parentWidget()->width(), 50);
	m_hblArea3 = getNewHBoxLayout(m_qfmArea2);
	m_hblArea3->setSpacing(15);

	m_btnSetFixedPos = getNewBtCommon("1708420306");
	m_hblArea3->addWidget(m_btnSetFixedPos);

	m_btnQueryFixedPos = getNewBtCommon("1708420327");
	m_hblArea3->addWidget(m_btnQueryFixedPos);

	m_lbFixedXpos = getNewLbCommon();
	m_lbFixedXpos->setText("X" + GetLang("1708420305"));
	m_hblArea3->addWidget(m_lbFixedXpos);

	m_edtFixedXpos = getNewLineEdit();
	m_edtFixedXpos->setPlaceholderText(QString::fromLocal8Bit("(mm)"));
	m_hblArea3->addWidget(m_edtFixedXpos);

	m_lbFixedYpos = getNewLbCommon();
	m_lbFixedYpos->setText("Y" + GetLang("1708420305"));
	m_lbFixedYpos->setAlignment(Qt::AlignCenter);
	m_hblArea3->addWidget(m_lbFixedYpos);

	m_edtFixedYpos = getNewLineEdit();
	m_edtFixedYpos->setPlaceholderText(QString::fromLocal8Bit("(mm)"));
	m_hblArea3->addWidget(m_edtFixedYpos);

	m_lbFixedZpos = getNewLbCommon();
	m_lbFixedZpos->setText("Z" + GetLang("1708420305"));
	m_lbFixedZpos->setAlignment(Qt::AlignCenter);
	m_hblArea3->addWidget(m_lbFixedZpos);

	m_edtFixedZpos = getNewLineEdit();
	m_edtFixedZpos->setPlaceholderText(QString::fromLocal8Bit("(mm)"));
	m_hblArea3->addWidget(m_edtFixedZpos);

	m_hblArea3->addStretch();
}

void DeviceMaintainPage_Axe_Setting::initWidgetArea5()
{
	m_qfmArea5 = getNewWidgetCommon();
	m_qfmArea5->setFixedSize(parentWidget()->width(), 50);
	m_hblArea5 = getNewHBoxLayout(m_qfmArea5);
	m_hblArea5->setSpacing(15);


	m_btnGetMagneticSleevePos = getNewBtCommon("1708420307");
	m_hblArea5->addWidget(m_btnGetMagneticSleevePos);

	m_btnSetMagneticSleevePos = getNewBtCommon("1708420310");
	m_hblArea5->addWidget(m_btnSetMagneticSleevePos);

	m_lbSleeveTopPos = getNewLbCommon("1708420308");
	m_lbSleeveTopPos->setAlignment(Qt::AlignCenter);
	m_hblArea5->addWidget(m_lbSleeveTopPos);

	m_edtSleeveTopPos = getNewLineEdit();
	m_edtSleeveTopPos->setPlaceholderText(QString::fromLocal8Bit("(mm)"));
	m_hblArea5->addWidget(m_edtSleeveTopPos);


	m_lbKitBoxPos = getNewLbCommon("1708420304");
	m_lbKitBoxPos->setAlignment(Qt::AlignCenter);
	m_hblArea5->addWidget(m_lbKitBoxPos);

	m_edtKitBoxPos = getNewLineEdit();
	m_edtKitBoxPos->setPlaceholderText(QString::fromLocal8Bit("(mm)"));
	m_hblArea5->addWidget(m_edtKitBoxPos);

	m_lbKitBoxBottom = getNewLbCommon("1708420309");
	m_lbKitBoxBottom->setAlignment(Qt::AlignCenter);
	m_hblArea5->addWidget(m_lbKitBoxBottom);

	m_edtBitBoxBottom = getNewLineEdit();
	m_edtBitBoxBottom->setPlaceholderText(QString::fromLocal8Bit("(mm)"));
	m_hblArea5->addWidget(m_edtBitBoxBottom);

	m_hblArea5->addStretch();
}

void DeviceMaintainPage_Axe_Setting::initWidgetArea6()
{
	m_qfmArea6 = getNewWidgetCommon();
	m_qfmArea6->setFixedSize(parentWidget()->width(), 50);
	m_hblArea6 = getNewHBoxLayout(m_qfmArea6);
	m_hblArea6->setSpacing(15);

	m_btnGetMagneticBarPos = getNewBtCommon("1708420311");
	m_hblArea6->addWidget(m_btnGetMagneticBarPos);

	m_btnSetMagneticBarPos = getNewBtCommon("1708420314");
	m_hblArea6->addWidget(m_btnSetMagneticBarPos);

	m_lbGetBarAfterZero = getNewLbCommon("1708420312");
	m_lbGetBarAfterZero->setAlignment(Qt::AlignCenter);
	m_hblArea6->addWidget(m_lbGetBarAfterZero);

	m_edtGetBarAfterZero = getNewLineEdit();
	m_edtGetBarAfterZero->setPlaceholderText(QString::fromLocal8Bit("(mm)"));
	m_hblArea6->addWidget(m_edtGetBarAfterZero);


	m_lbGetBarBeforeZero = getNewLbCommon("1708420313");
	m_lbGetBarBeforeZero->setAlignment(Qt::AlignCenter);
	m_hblArea6->addWidget(m_lbGetBarBeforeZero);

	m_edtGetBarBeforeZero = getNewLineEdit();
	m_edtGetBarBeforeZero->setPlaceholderText(QString::fromLocal8Bit("(mm)"));
	m_hblArea6->addWidget(m_edtGetBarBeforeZero);

	m_hblArea6->addStretch();
}

void DeviceMaintainPage_Axe_Setting::initWidgetArea7()
{
	m_qfmArea7 = getNewWidgetCommon();
	m_qfmArea7->setFixedSize(parentWidget()->width(), 50);
	m_hblArea7 = getNewHBoxLayout(m_qfmArea7);
	m_hblArea7->setSpacing(15);

	m_btnGetHorPos = getNewBtCommon("1708420315");
	m_hblArea7->addWidget(m_btnGetHorPos);

	m_btnSetHorPos = getNewBtCommon("1708420316");
	m_hblArea7->addWidget(m_btnSetHorPos);

	m_lbGetHorPos1 = getNewLbCommon("1708420317");
	m_lbGetHorPos1->setAlignment(Qt::AlignCenter);
	m_hblArea7->addWidget(m_lbGetHorPos1);
	m_edtGetHorPos1 = getNewLineEdit();
	m_edtGetHorPos1->setPlaceholderText(QString::fromLocal8Bit("(mm)"));
	m_hblArea7->addWidget(m_edtGetHorPos1);

	m_lbGetHorPos2 = getNewLbCommon("1708420318");
	m_lbGetHorPos2->setAlignment(Qt::AlignCenter);
	m_hblArea7->addWidget(m_lbGetHorPos2);

	m_edtGetHorPos2 = getNewLineEdit();
	m_edtGetHorPos2->setPlaceholderText(QString::fromLocal8Bit("(mm)"));
	m_hblArea7->addWidget(m_edtGetHorPos2);

	m_lbGetHorPos3 = getNewLbCommon("1708420319");
	m_lbGetHorPos3->setAlignment(Qt::AlignCenter);
	m_hblArea7->addWidget(m_lbGetHorPos3);

	m_edtGetHorPos3 = getNewLineEdit();
	m_edtGetHorPos3->setPlaceholderText(QString::fromLocal8Bit("(mm)"));
	m_hblArea7->addWidget(m_edtGetHorPos3);

	m_hblArea7->addStretch();
}

void DeviceMaintainPage_Axe_Setting::initAreas()
{
	this->initWidgetArea1();
	this->initWidgetArea2();
	//this->initWidgetArea4();
	this->initWidgetArea5();
	this->initWidgetArea6();
	this->initWidgetArea7();
	//this->initWidgetArea8();
}

void DeviceMaintainPage_Axe_Setting::setConnection()
{
	connect(m_btnQueryDoorPos, SIGNAL(clicked()), this, SLOT(slot_btnQueryDoorPosClicked()));
	connect(m_btnSetDoorPos, SIGNAL(clicked()), this, SLOT(slot_btnSetDoorPosClicked()));
	connect(m_btnGetMagneticSleevePos, SIGNAL(clicked()), this, SLOT(slot_btnGetSleevePosClicked()));
	connect(m_btnSetMagneticSleevePos, SIGNAL(clicked()), this, SLOT(slot_btnSetSleevePosClicked()));
	connect(m_btnGetMagneticBarPos, SIGNAL(clicked()), this, SLOT(slot_btnGetBarPosClicked()));
	connect(m_btnSetMagneticBarPos, SIGNAL(clicked()), this, SLOT(slot_btnSetBarPosClicked()));
	connect(m_btnGetHorPos, SIGNAL(clicked()), this, SLOT(slot_btnGetHorPosClicked()));
	connect(m_btnSetHorPos, SIGNAL(clicked()), this, SLOT(slot_btnSetHorPosClicked()));
}

void DeviceMaintainPage_Axe_Setting::slot_btnQueryDoorPosClicked()
{
	if (axeService == nullptr)
		return;

	float nBeforeZeroPos = 0.0f;
	float nAfterZeroPos = 0.0f;
	int retCode = axeService->getDoorPosition(axeNumber, nBeforeZeroPos, nAfterZeroPos);
	if (retCode == 0)
	{
		m_edtSetBZero->setText(QString::number(nBeforeZeroPos, 'f', 1));
		m_edtSetAzero->setText(QString::number(nAfterZeroPos, 'f', 1));
	}
	else
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Setting QueryDoorPos failed retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Setting::slot_btnSetDoorPosClicked()
{
	if (axeService == nullptr)
		return;

	if (m_edtSetBZero->text().isEmpty() || m_edtSetAzero->text().isEmpty())
	{
		HGT::warning(this, GetLang("1708420259"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}

	float beforeZeroPos = m_edtSetBZero->text().toFloat();
	float afterZeroPos = m_edtSetAzero->text().toFloat();
	int retCode = axeService->setDoorPosition(axeNumber, beforeZeroPos, afterZeroPos);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Setting SetDoorPos failed retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Setting::slot_btnQueryFixedPosClicked()
{
	if (axeService == nullptr)
		return;

	float nXPos = 0.0f;
	float nYPos = 0.0f;
	float nZPos = 0.0f;

	int retCode = axeService->getFixedPosition(axeNumber, nXPos, nYPos, nZPos);
	if (retCode == 0)
	{
		m_edtFixedXpos->setText(QString::number(nXPos, 'f', 1));
		m_edtFixedYpos->setText(QString::number(nYPos, 'f', 1));
		m_edtFixedZpos->setText(QString::number(nZPos, 'f', 1));
	}
	else
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Setting QueryFixedPos door failed retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Setting::slot_btnSetFixedPosClicked()
{
	if (axeService == nullptr)
		return;

	if (m_edtFixedXpos->text().isEmpty() || m_edtFixedYpos->text().isEmpty() || m_edtFixedZpos->text().isEmpty())
	{
		HGT::warning(this, GetLang("1708420259"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}

	float xPos = m_edtFixedXpos->text().toFloat();
	float yPos = m_edtFixedYpos->text().toFloat();
	float zPos = m_edtFixedZpos->text().toFloat();
	int retCode = axeService->setFixedPosition(axeNumber, xPos, yPos, zPos);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Setting SetFixedPos failed retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Setting::slot_btnGetSleevePosClicked()
{
	if (axeService == nullptr)
		return;

	float pos[3] = { -1.0f };
	int retCode = axeService->getMagneticSleevePosition(axeNumber, pos);
	if (retCode == 0)
	{
		m_edtSleeveTopPos->setText(QString::number(pos[0], 'f', 1));
		m_edtKitBoxPos->setText(QString::number(pos[1], 'f', 1));
		m_edtBitBoxBottom->setText(QString::number(pos[2], 'f', 1));
	}
	else
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Setting GetSleevePos failed retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Setting::slot_btnSetSleevePosClicked()
{
	if (axeService == nullptr)
		return;

	if (m_edtSleeveTopPos->text().isEmpty() || m_edtKitBoxPos->text().isEmpty() || m_edtBitBoxBottom->text().isEmpty())
	{
		HGT::warning(this, GetLang("1708420310"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}

	float pos[3] = { -1.0f };
	pos[0] = m_edtSleeveTopPos->text().toFloat();
	pos[1] = m_edtKitBoxPos->text().toFloat();
	pos[2] = m_edtBitBoxBottom->text().toFloat();

	int retCode = axeService->setMagneticSleevePosition(axeNumber, pos);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("QFmEquipMagneticBar SetSleevePos retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Setting::slot_btnGetBarPosClicked()
{
	if (axeService == nullptr)
		return;

	float upZeroPos = 0.0f;
	float downZeroPos = 0.0f;
	int retCode = axeService->getMagneticBarPosition(axeNumber, upZeroPos, downZeroPos);
	if (retCode == 0)
	{
		m_edtGetBarAfterZero->setText(QString::number(upZeroPos, 'f', 1));
		m_edtGetBarBeforeZero->setText(QString::number(downZeroPos, 'f', 1));
	}
	else
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("QFmEquipMagneticBar GetBarPos retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Setting::slot_btnSetBarPosClicked()
{
	if (axeService == nullptr)
		return;

	if (m_edtGetBarAfterZero->text().isEmpty() || m_edtGetBarBeforeZero->text().isEmpty())
	{
		HGT::warning(this, GetLang("1708420314"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}

	float upZeroPos = m_edtGetBarAfterZero->text().toFloat();
	float downZeroPos = m_edtGetBarBeforeZero->text().toFloat();

	int retCode = axeService->setMagneticBarPosition(axeNumber, upZeroPos, downZeroPos);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("QFmEquipMagneticBar SetBarPos retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Setting::slot_btnGetHorPosClicked()
{
	if (axeService == nullptr)
		return;

	float pos[6] = { -1.0f };
	int retCode = axeService->getHorizontalPosition(axeNumber, pos);
	if (retCode == 0)
	{
		m_edtGetHorPos1->setText(QString::number(pos[0], 'f', 1));
		m_edtGetHorPos2->setText(QString::number(pos[1], 'f', 1));
		m_edtGetHorPos3->setText(QString::number(pos[2], 'f', 1));
		//m_edtGetHorPos4->setText(QString::number(pos[3], 'f', 1));
		//m_edtGetHorPos5->setText(QString::number(pos[4], 'f', 1));
		//m_edtGetHorPos6->setText(QString::number(pos[5], 'f', 1));
	}
	else
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("QFmEquipHorizontalMotor GetHorPos retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Setting::slot_btnSetHorPosClicked()
{
	if (axeService == nullptr)
		return;

	if (m_edtGetHorPos1->text().isEmpty() || m_edtGetHorPos2->text().isEmpty() || m_edtGetHorPos3->text().isEmpty())
		//|| m_edtGetHorPos4->text().isEmpty() ||
		//m_edtGetHorPos5->text().isEmpty() || m_edtGetHorPos6->text().isEmpty())
	{
		HGT::warning(this, GetLang("1708420316"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}

	float pos[18] = { -1.0f };
	pos[0] = m_edtGetHorPos1->text().toFloat();
	pos[1] = m_edtGetHorPos2->text().toFloat();
	pos[2] = m_edtGetHorPos3->text().toFloat();
	pos[3] = 0.0f;
	pos[4] = 0.0f;;
	pos[5] = 0.0f;;

	int retCode = axeService->setHorizontalPosition(axeNumber, pos);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("QFmEquipHorizontalMotor SetHorPos retCode = " + strErrorCode.toStdString());
	}
}
//
//void DeviceMaintainPage_Axe_Setting::slot_btnQueryLoadingPosClicked()
//{
//	if (axeService == nullptr)
//		return;
//
//	float nXPos = 0.0f;
//	float nYPos = 0.0f;
//	float nZPos = 0.0f;
//
//	int retCode = axeService->getLoadingPosition(axeNumber, nXPos, nYPos, nZPos);
//	if (retCode == 0)
//	{
//		m_edtLoadingXpos->setText(QString::number(nXPos, 'f', 1));
//		m_edtLoadingYpos->setText(QString::number(nYPos, 'f', 1));
//		m_edtLoadingZpos->setText(QString::number(nZPos, 'f', 1));
//	}
//	else
//	{
//		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
//		Log("DeviceMaintainPage_Axe_Setting QueryLoadingPos door failed retCode = " + strErrorCode.toStdString());
//	}
//}

//void DeviceMaintainPage_Axe_Setting::slot_btnSetLoadingPosClicked()
//{
//	if (axeService == nullptr)
//		return;
//
//	if (m_edtLoadingXpos->text().isEmpty() || m_edtLoadingYpos->text().isEmpty() || m_edtLoadingZpos->text().isEmpty())
//	{
//		HGT::warning(this, GetLang("1708420259"), GetLang("1708420284"), QMessageBox::Ok);
//		return;
//	}
//
//	float xPos = m_edtLoadingXpos->text().toFloat();
//	float yPos = m_edtLoadingYpos->text().toFloat();
//	float zPos = m_edtLoadingZpos->text().toFloat();
//	int retCode = axeService->setLoadingPosition(axeNumber, xPos, yPos, zPos);
//	if (retCode != 0)
//	{
//		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
//		Log("DeviceMaintainPage_Axe_Setting SetLoadingPos failed retCode = " + strErrorCode.toStdString());
//	}
//}

