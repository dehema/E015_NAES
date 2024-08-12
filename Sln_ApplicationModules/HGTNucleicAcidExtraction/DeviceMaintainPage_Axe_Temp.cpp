#include "DeviceMaintainPage_AXE_Temp.h"

//ºËËáÌáÈ¡ÒÇ-ÎÂ¿Ø°å
DeviceMaintainPage_Axe_Temp::DeviceMaintainPage_Axe_Temp(QWidget * _parent, DeviceControlService _handle) :
	DeviceMaintainPage_Axe_Base(_parent, _handle)
{
	m_mainStacked = new QStackedWidget(this);
	m_mainStacked->move(0, 0);
	m_mainStacked->setFixedSize(parentWidget()->width(), parentWidget()->height());

	m_heatBoradCmd = new QWidget(m_mainStacked);
	m_heatBoradCmd->setFixedSize(parentWidget()->width(), parentWidget()->height());
	m_mainStacked->addWidget(m_heatBoradCmd);
	m_mainStacked->setCurrentWidget(m_heatBoradCmd);
	m_bShowRealTime = false;

	//µÚÒ»Ò³ÊÇÎÂ¿Ø°åµÄÃüÁîÒ³
	QVBoxLayout *m_vblMain = getNewVBoxLayout(m_heatBoradCmd);
	m_vblMain->setContentsMargins(20, 0, 0, 0);
	m_vblMain->setAlignment(Qt::AlignCenter);
	initAreas();

	m_vblMain->addWidget(m_qfmArea1);
	m_vblMain->addWidget(m_qfmArea2);
	m_vblMain->addWidget(m_qfmArea3);
	m_vblMain->addWidget(m_qfmArea5);
	m_vblMain->addWidget(m_qfmArea6);
	m_vblMain->addWidget(m_qfmArea7);
	m_vblMain->addWidget(m_qfmArea8);
	m_vblMain->addWidget(m_qfmArea9);
	m_vblMain->addWidget(m_qfmArea10);


	this->setConnection();

	if (axeService != nullptr)
	{
		m_bOpen = true;
		connect(axeService, SIGNAL(signal_sendCurTempToUI(int, HeatBoardData)), this, SLOT(slot_recvCurTempData(int, HeatBoardData)));
	}
}

void DeviceMaintainPage_Axe_Temp::initWidgetArea1()
{
	m_hblArea2 = getNewHBoxLayout(m_qfmArea1);
	m_hblArea2->setSpacing(10);

	m_btnGetCurrentDegree = getNewBtCommon("1708420201");
	m_hblArea2->addWidget(m_btnGetCurrentDegree);

	m_cbChannelNumber = getNewComboxBox();
	m_cbChannelNumber->setFixedWidth(constBtWidth);
	m_cbChannelNumber->addItem(GetLang("1708420235"));
	fillCbChannelItem(m_cbChannelNumber);
	m_hblArea2->addWidget(m_cbChannelNumber);

	m_lbTemp1 = getNewLabel("T1", 60);
	m_hblArea2->addWidget(m_lbTemp1);

	m_edtTemp1 = getNewLineEdit();
	m_edtTemp1->setReadOnly(true);
	m_hblArea2->addWidget(m_edtTemp1);

	m_lbTemp2 = getNewLabel("T2");
	m_hblArea2->addWidget(m_lbTemp2);

	m_edtTemp2 = getNewLineEdit();
	m_edtTemp2->setReadOnly(true);
	m_hblArea2->addWidget(m_edtTemp2);

	m_lbTemp3 = getNewLabel("T3");
	m_hblArea2->addWidget(m_lbTemp3);

	m_edtTemp3 = getNewLineEdit();
	m_edtTemp3->setReadOnly(true);
	m_hblArea2->addWidget(m_edtTemp3);

	m_lbTemp4 = getNewLabel("T4");
	m_hblArea2->addWidget(m_lbTemp4);

	m_edtTemp4 = getNewLineEdit();
	m_edtTemp4->setReadOnly(true);
	m_hblArea2->addWidget(m_edtTemp4);

	m_hblArea2->addStretch();
}

void DeviceMaintainPage_Axe_Temp::initWidgetArea2()
{
	m_cbStartChannelNumber = getNewComboxBox();
	m_cbStartChannelNumber->setFixedWidth(constBtWidth);
	fillCbChannelItem(m_cbStartChannelNumber);

	m_btnHeatBoardStart = getNewBtCommon("1708420236");

	m_hblArea3 = getNewHBoxLayout(m_qfmArea2);
	m_hblArea3->setSpacing(10);
	m_hblArea3->setContentsMargins(0, 0, 0, 0);

	m_hblArea3->addWidget(m_btnHeatBoardStart);
	m_hblArea3->addWidget(m_cbStartChannelNumber);
	m_hblArea3->addStretch();
}

void DeviceMaintainPage_Axe_Temp::initWidgetArea4()
{
	m_cbStopChannelNumber = getNewComboxBox();
	m_cbStopChannelNumber->setFixedWidth(constBtWidth);
	fillCbChannelItem(m_cbStopChannelNumber);

	m_btnHeatBoardStop = getNewBtCommon("1708420237");

	m_hblArea4 = getNewHBoxLayout(m_qfmArea3);
	m_hblArea4->setSpacing(10);
	m_hblArea4->setContentsMargins(0, 0, 0, 0);

	m_hblArea4->addWidget(m_btnHeatBoardStop);
	m_hblArea4->addWidget(m_cbStopChannelNumber);
	m_hblArea4->addStretch();
}

void DeviceMaintainPage_Axe_Temp::initWidgetArea5()
{
	m_hblArea5 = getNewHBoxLayout(m_qfmArea5);
	m_hblArea5->setSpacing(10);

	m_btnQueryHeatBoard = getNewBtCommon("1708420238");
	m_hblArea5->addWidget(m_btnQueryHeatBoard);

	m_cbQueryChannelNumber = getNewComboxBox();
	m_cbQueryChannelNumber->setFixedWidth(constBtWidth);
	fillCbChannelItem(m_cbQueryChannelNumber);
	m_hblArea5->addWidget(m_cbQueryChannelNumber);

	m_lbQueryTemp1 = getNewLabel("T1", 60);
	m_edtQueryTemp1 = getNewLineEdit();
	m_edtQueryTemp1->setReadOnly(true);

	m_hblArea5->addWidget(m_lbQueryTemp1);
	m_hblArea5->addWidget(m_edtQueryTemp1);

	m_lbQueryTemp2 = getNewLabel("T2");
	m_hblArea5->addWidget(m_lbQueryTemp2);

	m_edtQueryTemp2 = getNewLineEdit();
	m_edtQueryTemp2->setReadOnly(true);
	m_hblArea5->addWidget(m_edtQueryTemp2);

	m_lbQueryTemp3 = getNewLabel("T3");
	m_hblArea5->addWidget(m_lbQueryTemp3);

	m_edtQueryTemp3 = getNewLineEdit();
	m_edtQueryTemp3->setReadOnly(true);

	m_hblArea5->addWidget(m_edtQueryTemp3);

	m_lbQueryTemp4 = getNewLabel("T4");
	m_hblArea5->addWidget(m_lbQueryTemp4);

	m_edtQueryTemp4 = getNewLineEdit();
	m_edtQueryTemp4->setReadOnly(true);
	m_hblArea5->addWidget(m_edtQueryTemp4);

	m_hblArea5->addStretch();
}

void DeviceMaintainPage_Axe_Temp::initWidgetArea6()
{
	m_hblArea6 = getNewHBoxLayout(m_qfmArea6);
	m_hblArea6->setSpacing(10);


	m_btnSetHeatBoard = getNewBtCommon("1708420230");
	m_hblArea6->addWidget(m_btnSetHeatBoard);

	m_cbSetChannelNumber = getNewComboxBox();
	m_cbSetChannelNumber->setFixedWidth(constBtWidth);
	fillCbChannelItem(m_cbSetChannelNumber);
	m_hblArea6->addWidget(m_cbSetChannelNumber);

	m_lbSetTemp1 = getNewLabel("T", 60);
	m_hblArea6->addWidget(m_lbSetTemp1);

	m_edtSetTemp1 = getNewLineEdit();
	m_edtSetTemp1->setFixedWidth(110);
	m_edtSetTemp1->setValidator(new QIntValidator(25, 120, this));
	m_edtSetTemp1->setPlaceholderText(QString::fromLocal8Bit("25-120"));
	m_hblArea6->addWidget(m_edtSetTemp1);

	m_hblArea6->addStretch();
}

void DeviceMaintainPage_Axe_Temp::initWidgetArea7()
{
	m_hblArea7 = getNewHBoxLayout(m_qfmArea7);
	m_hblArea7->setSpacing(10);

	m_btnQueryPid = getNewBtCommon("1708420239");
	m_hblArea7->addWidget(m_btnQueryPid);

	m_btnSetPid = getNewBtCommon("1708420240");
	m_hblArea7->addWidget(m_btnSetPid);

	m_cbPidChannelNumber = getNewComboxBox();
	m_cbPidChannelNumber->setFixedWidth(100);
	fillCbChannelItem(m_cbPidChannelNumber);
	m_hblArea7->addWidget(m_cbPidChannelNumber);

	m_lbPParam = getNewLabel("P");
	m_hblArea7->addWidget(m_lbPParam);

	m_edtPParam = getNewLineEdit();
	m_edtPParam->setValidator(new QIntValidator(0, 100, this));
	m_edtPParam->setPlaceholderText(QString::fromLocal8Bit("0-100"));
	m_hblArea7->addWidget(m_edtPParam);

	m_lbIParam = getNewLabel("I");
	m_hblArea7->addWidget(m_lbIParam);

	m_edtIParam = getNewLineEdit();
	m_edtIParam->setValidator(new QIntValidator(0, 100, this));
	m_edtIParam->setPlaceholderText(QString::fromLocal8Bit("0-100"));
	m_hblArea7->addWidget(m_edtIParam);

	m_lbDParam = getNewLabel("D");
	m_hblArea7->addWidget(m_lbDParam);

	m_edtDParam = getNewLineEdit();
	m_edtDParam->setValidator(new QIntValidator(0, 100, this));
	m_edtDParam->setPlaceholderText(QString::fromLocal8Bit("0-100"));
	m_hblArea7->addWidget(m_edtDParam);

	m_hblArea7->addStretch();
}

void DeviceMaintainPage_Axe_Temp::initWidgetArea8()
{
	m_hblArea8 = getNewHBoxLayout(m_qfmArea8);
	m_hblArea8->setSpacing(10);

	m_btnQueryControlCorrected = getNewBtCommon("1708420242");
	m_hblArea8->addWidget(m_btnQueryControlCorrected);

	m_btnSetControlCorrected = getNewBtCommon("1708420243");
	m_hblArea8->addWidget(m_btnSetControlCorrected);

	m_cbControlChannelNumber = getNewComboxBox();
	m_cbControlChannelNumber->setFixedWidth(100);
	fillCbChannelItem(m_cbControlChannelNumber);
	m_hblArea8->addWidget(m_cbControlChannelNumber);

	m_lbControlCorrected = getNewLabel(GetLang("1708420241"));
	m_lbControlCorrected->setMinimumWidth(70);
	m_hblArea8->addWidget(m_lbControlCorrected);

	m_edtControlCorrected = getNewLineEdit();
	m_hblArea8->addWidget(m_edtControlCorrected);

	m_hblArea8->addStretch();
}

void DeviceMaintainPage_Axe_Temp::initWidgetArea9()
{
	m_hblArea9 = getNewHBoxLayout(m_qfmArea9);
	m_hblArea9->setSpacing(10);

	m_btnQueryMeasureCorrected = getNewBtCommon("1708420245");
	m_hblArea9->addWidget(m_btnQueryMeasureCorrected);

	m_btnSetMeasureCorrected = getNewBtCommon("1708420246");
	m_hblArea9->addWidget(m_btnSetMeasureCorrected);

	m_cbMeasureChannelNumber = getNewComboxBox();
	m_cbMeasureChannelNumber->setFixedWidth(100);
	fillCbChannelItem(m_cbMeasureChannelNumber);
	m_hblArea9->addWidget(m_cbMeasureChannelNumber);

	m_lbMeasureCorrected = getNewLabel(GetLang("1708420244"));
	m_lbMeasureCorrected->setAlignment(Qt::AlignCenter);
	m_lbMeasureCorrected->setMinimumWidth(70);
	m_edtMeasureCorrected = getNewLineEdit();

	m_hblArea9->addWidget(m_lbMeasureCorrected);
	m_hblArea9->addWidget(m_edtMeasureCorrected);

	m_hblArea9->addStretch();
}

void DeviceMaintainPage_Axe_Temp::initWidgetArea10()
{
	m_hblArea10 = getNewHBoxLayout(m_qfmArea10);
	m_hblArea10->setSpacing(10);

	m_btnQueryLoadPolarity = getNewBtCommon("1708420248");
	m_hblArea10->addWidget(m_btnQueryLoadPolarity);

	m_btnSetLoadPolarity = getNewBtCommon("1708420249");
	m_hblArea10->addWidget(m_btnSetLoadPolarity);

	m_cbPolarityChannelNumber = getNewComboxBox();
	m_cbPolarityChannelNumber->setFixedWidth(100);
	fillCbChannelItem(m_cbPolarityChannelNumber);
	m_hblArea10->addWidget(m_cbPolarityChannelNumber);

	m_lbLoadPolarity = getNewLabel(GetLang("1708420247"));
	m_lbLoadPolarity->setFixedWidth(100);
	m_lbLoadPolarity->setAlignment(Qt::AlignCenter);
	m_lbLoadPolarity->setMinimumWidth(70);
	m_hblArea10->addWidget(m_lbLoadPolarity);

	m_edtLoadPolarity = getNewLineEdit();
	m_edtLoadPolarity->setValidator(new QIntValidator(0, 1, this));
	m_edtLoadPolarity->setPlaceholderText(QString::fromLocal8Bit("0-1"));
	m_hblArea10->addWidget(m_edtLoadPolarity);

	m_hblArea10->addStretch();
}

void DeviceMaintainPage_Axe_Temp::initAreas()
{
	m_qfmArea1 = new QFrame(this);
	m_qfmArea2 = new QFrame(this);
	m_qfmArea3 = new QFrame(this);
	m_qfmArea5 = new QFrame(this);
	m_qfmArea6 = new QFrame(this);
	m_qfmArea7 = new QFrame(this);
	m_qfmArea8 = new QFrame(this);
	m_qfmArea9 = new QFrame(this);
	m_qfmArea10 = new QFrame(this);

	this->initWidgetArea1();
	this->initWidgetArea2();
	this->initWidgetArea4();
	this->initWidgetArea5();
	this->initWidgetArea6();
	this->initWidgetArea7();
	this->initWidgetArea8();
	this->initWidgetArea9();
	this->initWidgetArea10();

	m_qfmArea1->setFixedSize(ContentPage_WIDTH, 40);
	m_qfmArea1->setLayout(m_hblArea2);

	m_qfmArea2->setFixedSize(ContentPage_WIDTH, 40);
	m_qfmArea2->setLayout(m_hblArea3);

	m_qfmArea3->setFixedSize(ContentPage_WIDTH, 40);
	m_qfmArea3->setLayout(m_hblArea4);

	m_qfmArea5->setFixedSize(ContentPage_WIDTH, 40);
	m_qfmArea5->setLayout(m_hblArea5);

	m_qfmArea6->setFixedSize(ContentPage_WIDTH, 40);
	m_qfmArea6->setLayout(m_hblArea6);

	m_qfmArea7->setFixedSize(ContentPage_WIDTH, 40);
	m_qfmArea7->setLayout(m_hblArea7);

	m_qfmArea8->setFixedSize(ContentPage_WIDTH, 40);
	m_qfmArea8->setLayout(m_hblArea8);

	m_qfmArea9->setFixedSize(ContentPage_WIDTH, 40);
	m_qfmArea9->setLayout(m_hblArea9);

	m_qfmArea10->setFixedSize(ContentPage_WIDTH, 40);
	m_qfmArea10->setLayout(m_hblArea10);
}

void DeviceMaintainPage_Axe_Temp::setConnection()
{
	//connect(m_btnRealtimeTemp, SIGNAL(clicked()), this, SLOT(slot_bntRealtimeTempClicked()));	 
	//connect(m_btnReturnMain, SIGNAL(clicked()), this, SLOT(slot_bntRealtimeTempClicked()));
	connect(m_btnGetCurrentDegree, SIGNAL(clicked()), this, SLOT(slot_btnGetCurrentDegreeClicked()));
	connect(m_btnQueryHeatBoard, SIGNAL(clicked()), this, SLOT(slot_btnQueryHeatBoardClicked()));
	connect(m_btnSetHeatBoard, SIGNAL(clicked()), this, SLOT(slot_btnSetHeatBoardClicked()));
	connect(m_btnHeatBoardStart, SIGNAL(clicked()), this, SLOT(slot_btnStartHeatBoardClicked()));
	connect(m_btnHeatBoardStop, SIGNAL(clicked()), this, SLOT(slot_btnStopHeatBoardClicked()));
	connect(m_cbChannelNumber, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_cbChannelNumberChanged(int)));
	connect(m_cbQueryChannelNumber, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_cbQueryChannelNumberChanged(int)));
	connect(m_cbSetChannelNumber, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_cbSetChannelNumberChanged(int)));
	connect(m_btnQueryPid, SIGNAL(clicked()), this, SLOT(slot_btnQueryPidClicked()));
	connect(m_btnSetPid, SIGNAL(clicked()), this, SLOT(slot_btnSetPidClicked()));
	connect(m_btnQueryControlCorrected, SIGNAL(clicked()), this, SLOT(slot_btnQueryControlCorrectedClicked()));
	connect(m_btnSetControlCorrected, SIGNAL(clicked()), this, SLOT(slot_btnSetControlCorrectedClicked()));
	connect(m_btnQueryMeasureCorrected, SIGNAL(clicked()), this, SLOT(slot_btnQueryMeasureCorrectedClicked()));
	connect(m_btnSetMeasureCorrected, SIGNAL(clicked()), this, SLOT(slot_btnSetMeasureCorrectedClicked()));
	connect(m_btnQueryLoadPolarity, SIGNAL(clicked()), this, SLOT(slot_btnQueryLoadPolarityClicked()));
	connect(m_btnSetLoadPolarity, SIGNAL(clicked()), this, SLOT(slot_btnSetLoadPolarityClicked()));
}

void DeviceMaintainPage_Axe_Temp::slot_btnGetCurrentDegreeClicked()
{
	if (!m_bOpen)
	{
		Log("ÎÂ¿Ø³õÊ¼»¯Ê§°Ü");
		return;
	}

	int boardNumber = 1;
	int channelNumber = m_cbChannelNumber->currentIndex();

	HeatBoardData heatBoardData;
	heatBoardData = axeService->getCurrentTemperature(axeNumber, boardNumber, channelNumber);

	if (heatBoardData.retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(heatBoardData.retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Temp GetCurrentDegree retCode = " + strErrorCode.toStdString());
		return;
	}

	if (heatBoardData.currentChannel == 0)
	{
		m_edtTemp1->setText(QString::number(heatBoardData.degree[0], 'f', 1));
		m_edtTemp2->setText(QString::number(heatBoardData.degree[1], 'f', 1));
		m_edtTemp3->setText(QString::number(heatBoardData.degree[2], 'f', 1));
		m_edtTemp4->setText(QString::number(heatBoardData.degree[3], 'f', 1));
	}
	else
	{
		int nCurrentChannel = heatBoardData.currentChannel;
		switch (nCurrentChannel)
		{
		case 1:
			m_edtTemp1->setText(QString::number(heatBoardData.degree[0], 'f', 1));
			break;
		case 2:
			m_edtTemp2->setText(QString::number(heatBoardData.degree[1], 'f', 1));
			break;
		case 3:
			m_edtTemp3->setText(QString::number(heatBoardData.degree[2], 'f', 1));
			break;
		case 4:
			m_edtTemp4->setText(QString::number(heatBoardData.degree[3], 'f', 1));
			break;
		}
	}
}

void DeviceMaintainPage_Axe_Temp::slot_btnQueryHeatBoardClicked()
{
	if (!m_bOpen)
	{
		Log("ÎÂ¿Ø³õÊ¼»¯Ê§°Ü");
		return;
	}

	int boardNumber = 1;
	int channelNumber = m_cbQueryChannelNumber->currentIndex() + 1;

	HeatBoardData heatBoardData;
	heatBoardData = axeService->getAimTemperature(axeNumber, boardNumber, channelNumber);

	if (heatBoardData.retCode == 0)
	{
		if (heatBoardData.degree[0] != InitDegree)
			m_edtQueryTemp1->setText(QString::number(heatBoardData.degree[0], 'f', 1));
		if (heatBoardData.degree[1] != InitDegree)
			m_edtQueryTemp2->setText(QString::number(heatBoardData.degree[1], 'f', 1));
		if (heatBoardData.degree[2] != InitDegree)
			m_edtQueryTemp3->setText(QString::number(heatBoardData.degree[2], 'f', 1));
		if (heatBoardData.degree[3] != InitDegree)
			m_edtQueryTemp4->setText(QString::number(heatBoardData.degree[3], 'f', 1));
	}
	else
	{
		QString strErrorCode = QString("%1").arg(heatBoardData.retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Temp QueryHeatBoard retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Temp::slot_btnSetHeatBoardClicked()
{
	if (!m_bOpen)
	{
		Log("ÎÂ¿Ø³õÊ¼»¯Ê§°Ü");
		return;
	}

	if (m_edtSetTemp1->text().isEmpty())
	{
		HGT::warning(this, GetLang("1708420200"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}
	const QValidator* validator = m_edtSetTemp1->validator();
	const QIntValidator* intValidator = dynamic_cast<const QIntValidator*>(validator);
	if (m_edtSetTemp1->text().toInt() < intValidator->bottom())
	{
		HGT::warning(this, GetLang("1708419699"), GetLang("1708420403"), QMessageBox::Ok);
		return;
	}

	int boardNumber = 1;
	int channelNumber = m_cbSetChannelNumber->currentIndex() + 1;
	int aimDegree = m_edtSetTemp1->text().toInt();

	int retCode = axeService->setAimTemperature(axeNumber, boardNumber, channelNumber, aimDegree);

	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Temp setHeatBoard retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Temp::slot_btnStartHeatBoardClicked()
{
	if (!m_bOpen)
	{
		Log("ÎÂ¿Ø³õÊ¼»¯Ê§°Ü");
		return;
	}

	int boardNumber = 1;
	int channelNumber = m_cbStartChannelNumber->currentIndex() + 1;

	int retCode = axeService->startHeatBoard(axeNumber, boardNumber, channelNumber);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Temp StartHeatBoard retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Temp::slot_btnStopHeatBoardClicked()
{
	if (!m_bOpen)
	{
		Log("ÎÂ¿Ø³õÊ¼»¯Ê§°Ü");
		return;
	}

	int boardNumber = 1;
	int channelNumber = m_cbStopChannelNumber->currentIndex() + 1;

	int retCode = axeService->stopHeatBoard(axeNumber, boardNumber, channelNumber);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Temp StopHeatBoard retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Temp::slot_cbChannelNumberChanged(int)
{
	m_edtTemp1->clear();
	m_edtTemp2->clear();
	m_edtTemp3->clear();
	m_edtTemp4->clear();
}

void DeviceMaintainPage_Axe_Temp::slot_cbQueryChannelNumberChanged(int)
{
	m_edtQueryTemp1->clear();
	m_edtQueryTemp2->clear();
	m_edtQueryTemp3->clear();
	m_edtQueryTemp4->clear();
}

void DeviceMaintainPage_Axe_Temp::slot_cbSetChannelNumberChanged(int)
{
	m_edtSetTemp1->clear();
}

void DeviceMaintainPage_Axe_Temp::slot_btnQueryPidClicked()
{
	if (!m_bOpen)
	{
		Log("ÎÂ¿Ø³õÊ¼»¯Ê§°Ü");
		return;
	}

	int boardNumber = 1;
	int channelNumber = m_cbPidChannelNumber->currentIndex() + 1;

	int pid[3] = { 0 };
	int retCode = axeService->getPidParam(axeNumber, boardNumber, channelNumber, pid);

	if (retCode == 0)
	{
		m_edtPParam->setText(QString::number(pid[0]));
		m_edtIParam->setText(QString::number(pid[1]));
		m_edtDParam->setText(QString::number(pid[2]));
	}
	else
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Temp QueryPid retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Temp::slot_btnSetPidClicked()
{
	if (!m_bOpen)
	{
		Log("ÎÂ¿Ø³õÊ¼»¯Ê§°Ü");
		return;
	}

	if (m_edtPParam->text().isEmpty() || m_edtIParam->text().isEmpty() || m_edtDParam->text().isEmpty())
	{
		HGT::warning(this, GetLang("1708420200"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}

	int boardNumber = 1;
	int channelNumber = m_cbPidChannelNumber->currentIndex() + 1;

	int pid[3] = { 0 };
	pid[0] = m_edtPParam->text().toInt();
	pid[1] = m_edtIParam->text().toInt();
	pid[2] = m_edtDParam->text().toInt();

	int retCode = axeService->setPidParam(axeNumber, boardNumber, channelNumber, pid);

	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Temp SetPid retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Temp::slot_btnQueryControlCorrectedClicked()
{
	if (!m_bOpen)
	{
		Log("ÎÂ¿Ø³õÊ¼»¯Ê§°Ü");
		return;
	}

	int boardNumber = 1;
	int channelNumber = m_cbControlChannelNumber->currentIndex() + 1;

	float cValue = 0.0f;
	int retCode = axeService->getCorrectedControlValue(axeNumber, boardNumber, channelNumber, &cValue);

	if (retCode == 0)
	{
		m_edtControlCorrected->setText(QString::number(cValue, 'f', 1));
	}
	else
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Temp nQueryControlCorrected retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Temp::slot_btnSetControlCorrectedClicked()
{
	if (!m_bOpen)
	{
		Log("ÎÂ¿Ø³õÊ¼»¯Ê§°Ü");
		return;
	}

	if (m_edtControlCorrected->text().isEmpty())
	{
		HGT::warning(this, GetLang("1708420200"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}

	int boardNumber = 1;
	int channelNumber = m_cbControlChannelNumber->currentIndex() + 1;
	float cValue = m_edtControlCorrected->text().toFloat();

	int retCode = axeService->setCorrectedControlValue(axeNumber, boardNumber, channelNumber, cValue);

	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Temp SetControlCorrected retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Temp::slot_btnQueryMeasureCorrectedClicked()
{
	if (!m_bOpen)
	{
		Log("ÎÂ¿Ø³õÊ¼»¯Ê§°Ü");
		return;
	}

	int boardNumber = 1;
	int channelNumber = m_cbMeasureChannelNumber->currentIndex() + 1;

	float cValue = 0.0f;
	int retCode = axeService->getCorrectedMeasureValue(axeNumber, boardNumber, channelNumber, &cValue);

	if (retCode == 0)
	{
		m_edtMeasureCorrected->setText(QString::number(cValue, 'f', 1));
	}
	else
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Temp nQueryMeasureCorrected retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Temp::slot_btnSetMeasureCorrectedClicked()
{
	if (!m_bOpen)
	{
		Log("ÎÂ¿Ø³õÊ¼»¯Ê§°Ü");
		return;
	}

	if (m_edtMeasureCorrected->text().isEmpty())
	{
		HGT::warning(this, GetLang("1708420200"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}

	int boardNumber = 1;
	int channelNumber = m_cbMeasureChannelNumber->currentIndex() + 1;
	float cValue = m_edtMeasureCorrected->text().toFloat();

	int retCode = axeService->setCorrectedMeasureValue(axeNumber, boardNumber, channelNumber, cValue);

	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Temp SetMeasureCorrected retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Temp::slot_btnQueryLoadPolarityClicked()
{
	if (!m_bOpen)
	{
		Log("ÎÂ¿Ø³õÊ¼»¯Ê§°Ü");
		return;
	}

	int boardNumber = 1;
	int channelNumber = m_cbPolarityChannelNumber->currentIndex() + 1;

	int nPolar = -1;
	int retCode = axeService->getLoadPolarity(axeNumber, boardNumber, channelNumber, &nPolar);

	if (retCode == 0)
	{
		m_edtLoadPolarity->setText(QString::number(nPolar));
	}
	else
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Temp nQueryLoadPolarity retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Temp::slot_btnSetLoadPolarityClicked()
{
	if (!m_bOpen)
	{
		Log("ÎÂ¿Ø³õÊ¼»¯Ê§°Ü");
		return;
	}

	if (m_edtLoadPolarity->text().isEmpty())
	{
		HGT::warning(this, GetLang("1708420200"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}

	int boardNumber = 1;
	int channelNumber = m_cbPolarityChannelNumber->currentIndex() + 1;
	int nPolar = m_edtLoadPolarity->text().toInt();

	int retCode = axeService->setLoadPolarity(axeNumber, boardNumber, channelNumber, nPolar);

	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Temp SetLoadPolarity retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Temp::slot_bntRealtimeTempClicked()
{
	if (!m_bShowRealTime)
	{
		m_mainStacked->setCurrentIndex(1);
		m_bShowRealTime = true;
	}
	else
	{
		m_mainStacked->setCurrentIndex(0);
		m_bShowRealTime = false;
	}
}

void DeviceMaintainPage_Axe_Temp::fillCbChannelItem(QComboBox * _cb)
{
	_cb->addItem(GetLang("1708420250") + "1");
	_cb->addItem(GetLang("1708420250") + "2");
	_cb->addItem(GetLang("1708420250") + "3");
	_cb->addItem(GetLang("1708420250") + "4");
}

QLabel* DeviceMaintainPage_Axe_Temp::getNewLabel(QString _str, int _width)
{
	QLabel* lb = getNewLbCommon();
	lb->setText(_str);
	lb->setFixedWidth(_width);
	lb->setAlignment(Qt::AlignCenter);
	return lb;
}
