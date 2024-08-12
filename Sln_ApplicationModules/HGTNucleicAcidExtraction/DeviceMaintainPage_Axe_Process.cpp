#include "DeviceMaintainPage_Axe_Process.h"

DeviceMaintainPage_Axe_Process::DeviceMaintainPage_Axe_Process(QWidget * _parent, DeviceControlService _handle) :
	DeviceMaintainPage_Axe_Base(_parent, _handle)
{

	this->initWidgetArea1();
	this->initWidgetArea2();
	this->initWidgetArea4();
	this->initWidgetArea6();

	QVBoxLayout *m_vblFirstPage = getNewVBoxLayout(this);
	m_vblFirstPage->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
	m_vblFirstPage->setContentsMargins(0, 0, 0, 20);

	m_vblFirstPage->addWidget(m_qfmArea1);
	m_vblFirstPage->addWidget(m_qfmArea2);
	m_vblFirstPage->addWidget(m_qfmArea3);
	m_vblFirstPage->addWidget(m_qfmArea6);

	this->setConnection();

	if (axeService != nullptr)
		m_bOpen = true;
}

void DeviceMaintainPage_Axe_Process::initWidgetArea1()
{
	m_qfmArea1 = getNewWidgetCommon();
	m_qfmArea1->setFixedSize(parentWidget()->width(), 60);
	m_hblArea2 = getNewHBoxLayout(m_qfmArea1);
	m_hblArea2->setSpacing(20);

	m_btnProcessControl = getNewBtCommon("1708420341");
	m_hblArea2->addWidget(m_btnProcessControl);

	m_lbControlCmd = getNewLbCommon("1708420328");
	m_hblArea2->addWidget(m_lbControlCmd);

	m_cbProcessControl = getNewComboxBox({
		//"1708420163", 
		"1708420162",
		"1708420347",
		"1708420348",
	});
	m_hblArea2->addWidget(m_cbProcessControl);

	m_hblArea2->addStretch();
}

void DeviceMaintainPage_Axe_Process::initWidgetArea2()
{
	m_qfmArea2 = getNewWidgetCommon();
	m_qfmArea2->setFixedSize(parentWidget()->width(), 60);
	m_hblArea3 = getNewHBoxLayout(m_qfmArea2);
	m_hblArea3->setSpacing(20);

	m_btnQueryProcessVer = getNewBtCommon("1708420342");
	m_hblArea3->addWidget(m_btnQueryProcessVer);

	m_lbQueryProcessVer = getNewLbCommon("1708420329");
	m_hblArea3->addWidget(m_lbQueryProcessVer);

	m_edtQueryProcessVer = getNewLineEdit();
	m_edtQueryProcessVer->setReadOnly(true);
	m_hblArea3->addWidget(m_edtQueryProcessVer);

	m_hblArea3->addStretch();
}

void DeviceMaintainPage_Axe_Process::initWidgetArea4()
{
	m_qfmArea3 = getNewFrame();
	m_qfmArea3->setFixedSize(parentWidget()->width() - 10, 180);

	m_hblArea4 = getNewGridLayout(m_qfmArea3);
	m_hblArea4->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	m_hblArea4->setHorizontalSpacing(10);
	m_hblArea4->setVerticalSpacing(20);
	m_hblArea4->setContentsMargins(12, 0, 12, 0);

	m_btnMixedProcess = getNewBtCommon("1708420343");
	m_btnMixedProcess->setFixedWidth(190);
	m_hblArea4->addWidget(m_btnMixedProcess, 0, 0, 1, 2, Qt::AlignLeft);

	//流程ID
	m_lbProcessID = getNewLbCommon("1708420330");
	m_lbProcessID->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbProcessID, 0, 2);

	m_edtProcessID = getNewLineEdit();
	m_edtProcessID->setText("1");
	m_edtProcessID->setValidator(new QIntValidator(1, 99, this));
	m_edtProcessID->setPlaceholderText(QString::fromLocal8Bit("1-99"));
	m_hblArea4->addWidget(m_edtProcessID, 0, 3);

	//容积
	m_lbVolume = getNewLbCommon("1708420333");
	m_lbVolume->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbVolume, 0, 4);

	m_edtVolume = getNewLineEdit();
	m_edtVolume->setText("500");
	m_edtVolume->setValidator(new QIntValidator(1, 1000, this));
	m_edtVolume->setPlaceholderText(QString::fromLocal8Bit("1-1000"));
	m_hblArea4->addWidget(m_edtVolume, 0, 5);

	//列号
	m_lbColumnNum = getNewLbCommon("1708420331");
	m_lbColumnNum->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbColumnNum, 0, 6);

	m_edtColumnNum = getNewLineEdit();
	m_edtColumnNum->setText("1");
	m_edtColumnNum->setValidator(new QIntValidator(1, 6, this));
	m_edtColumnNum->setPlaceholderText(QString::fromLocal8Bit("1-6"));
	m_hblArea4->addWidget(m_edtColumnNum, 0, 7);

	//混合时间
	m_lbMixedTime = getNewLbCommon("1708420091");
	m_lbMixedTime->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbMixedTime, 1, 0);

	m_edtMixedTime = getNewLineEdit();
	m_edtMixedTime->setText("10");
	m_edtMixedTime->setPlaceholderText(QString::fromLocal8Bit("(s)"));
	m_hblArea4->addWidget(m_edtMixedTime, 1, 1);

	//混合速度
	m_lbMixedSpeed = getNewLbCommon();
	m_lbMixedSpeed->setAlignment(Qt::AlignCenter);
	m_lbMixedSpeed->setText(GetLang("1708420093") + "(PRM)");
	m_hblArea4->addWidget(m_lbMixedSpeed, 1, 2);

	m_edtMixedSpeed = getNewLineEdit();
	m_edtMixedSpeed->setText("1000");
	m_edtMixedSpeed->setValidator(new QIntValidator(200, 3000, this));
	m_edtMixedSpeed->setPlaceholderText(QString::fromLocal8Bit("200-3000"));
	m_hblArea4->addWidget(m_edtMixedSpeed, 1, 3);

	//混合底部位置
	m_lbMixPosition = getNewLbCommon("1708420334");
	m_lbMixPosition->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbMixPosition, 1, 4);

	m_edtMixPosition = getNewLineEdit();
	m_edtMixPosition->setText("10");
	m_edtMixPosition->setValidator(new QIntValidator(0, 50, this));
	m_edtMixPosition->setPlaceholderText(QString::fromLocal8Bit("0-50"));
	m_hblArea4->addWidget(m_edtMixPosition, 1, 5);

	//混合顶部位置
	m_lbMixAmplitude = getNewLbCommon("1708420335");
	m_lbMixAmplitude->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbMixAmplitude, 1, 6);

	m_edtMixAmplitude = getNewLineEdit();
	m_edtMixAmplitude->setText("10");
	m_edtMixAmplitude->setValidator(new QIntValidator(0, 100, this));
	m_edtMixAmplitude->setPlaceholderText(QString::fromLocal8Bit("0-100"));
	m_hblArea4->addWidget(m_edtMixAmplitude, 1, 7);

	//吸磁时间
	m_lbAdsorbTime = getNewLbCommon("1708420092");
	m_lbAdsorbTime->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbAdsorbTime, 2, 0);

	m_edtAdsorbTime = getNewLineEdit();
	m_edtAdsorbTime->setText("10");
	m_edtAdsorbTime->setPlaceholderText(QString::fromLocal8Bit("(s)"));
	m_hblArea4->addWidget(m_edtAdsorbTime, 2, 1);

	//吸磁速度
	m_lbAdsorbSpeed = getNewLbCommon("1708420332");
	m_lbAdsorbSpeed->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbAdsorbSpeed, 2, 2);

	m_cbAdsorbSpeed = getNewComboxBox(AXEMgr::ins().magnetSpeedStr);
	m_cbAdsorbSpeed->setValidator(new QIntValidator(1, 10, this));
	m_cbAdsorbSpeed->setCurrentIndex(0);
	m_hblArea4->addWidget(m_cbAdsorbSpeed, 2, 3);

	//等待时间
	m_lbWaitTime = getNewLbCommon("1708420090");
	m_lbWaitTime->setText("10");
	m_lbWaitTime->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbWaitTime, 2, 4);

	m_edtWaitTime = getNewLineEdit();
	m_edtWaitTime->setPlaceholderText(QString::fromLocal8Bit("(s)"));
	m_hblArea4->addWidget(m_edtWaitTime, 2, 5);

	//吸磁位置
	m_lbAdsorbPosition = getNewLbCommon("1708420336");
	m_lbAdsorbPosition->setAlignment(Qt::AlignCenter);
	m_hblArea4->addWidget(m_lbAdsorbPosition, 2, 6);

	m_edtAdsorbPosition = getNewLineEdit();
	m_edtAdsorbPosition->setText("10");
	m_edtAdsorbPosition->setValidator(new QIntValidator(1, 100, this));
	m_edtAdsorbPosition->setPlaceholderText(QString::fromLocal8Bit("1-100"));
	m_hblArea4->addWidget(m_edtAdsorbPosition, 2, 7);
}

void DeviceMaintainPage_Axe_Process::initWidgetArea6()
{
	m_qfmArea6 = getNewWidgetCommon();
	m_qfmArea6->setFixedSize(parentWidget()->width(), 100);

	m_hblArea6 = getNewGridLayout(m_qfmArea6);
	m_hblArea6->setSpacing(20);

	m_btnHeatProcess = getNewBtCommon("1708420344");
	m_btnHeatProcess->setFixedWidth(200);
	m_hblArea6->addWidget(m_btnHeatProcess, 0, 0, 1, 2);

	m_lbHeatProcessID = getNewLbCommon("1708420330");
	m_hblArea6->addWidget(m_lbHeatProcessID, 0, 2);

	m_edtHeatProcessID = getNewLineEdit();
	m_edtHeatProcessID->setValidator(new QIntValidator(1, 99, this));
	m_edtHeatProcessID->setPlaceholderText(QString::fromLocal8Bit("1-99"));
	m_hblArea6->addWidget(m_edtHeatProcessID, 0, 3);

	m_lbGroupNum = getNewLbCommon("1708420340");
	m_hblArea6->addWidget(m_lbGroupNum, 0, 4);

	m_cbGroupNum = getNewComboxBox();
	m_cbGroupNum->addItem("1,7" + GetLang("1708420299"));
	m_cbGroupNum->addItem("6,12" + GetLang("1708420299"));
	m_hblArea6->addWidget(m_cbGroupNum, 0, 5);

	m_lbAimDegree = getNewLbCommon("1708420338");
	m_hblArea6->addWidget(m_lbAimDegree, 1, 0);

	m_edtAimDegree = getNewLineEdit();
	m_edtAimDegree->setValidator(new QIntValidator(25, 120, this));
	m_edtAimDegree->setPlaceholderText(QString::fromLocal8Bit("25-120"));
	m_hblArea6->addWidget(m_edtAimDegree, 1, 1);

	m_lbIsHeat = getNewLbCommon("1708420339");
	m_hblArea6->addWidget(m_lbIsHeat, 1, 2);

	m_cbIsHeat = getNewComboxBox({ "1708420213","1708420212" });
	m_hblArea6->addWidget(m_cbIsHeat, 1, 3);
}

void DeviceMaintainPage_Axe_Process::setConnection()
{
	connect(m_btnProcessControl, SIGNAL(clicked()), this, SLOT(slot_btnProcessControlClicked()));
	connect(m_btnQueryProcessVer, SIGNAL(clicked()), this, SLOT(slot_btnGetProcessVerClicked()));
	connect(m_btnMixedProcess, SIGNAL(clicked()), this, SLOT(slot_btnStartMixedProcess()));
	connect(m_btnHeatProcess, SIGNAL(clicked()), this, SLOT(slot_btnStartHeatProcess()));
}

void DeviceMaintainPage_Axe_Process::slot_btnProcessControlClicked()
{
	if (axeService == nullptr)
		return;
	//1复位 2暂停 3继续 4停止
	int controlCmd = m_cbProcessControl->currentIndex() + 2;

	int retCode = axeService->processControl(axeNumber, controlCmd);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Process ProcessControl retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Process::slot_btnGetProcessVerClicked()
{
	if (axeService == nullptr)
		return;

	string version("");
	int retCode = axeService->getAxeVersion(axeNumber, version);
	if (retCode == 0)
	{
		m_edtQueryProcessVer->setText(version.c_str());
	}
	else
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Process GetProcessVer retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Process::slot_btnStartMixedProcess()
{
	if (axeService == nullptr)
		return;

	if (m_edtProcessID->text().isEmpty() || m_edtColumnNum->text().isEmpty() || m_edtColumnNum->text().isEmpty() || \
		m_edtMixedTime->text().isEmpty() || m_edtMixedSpeed->text().isEmpty() || m_edtAdsorbTime->text().isEmpty() || \
		m_edtWaitTime->text().isEmpty() || m_edtVolume->text().isEmpty() || \
		m_edtMixPosition->text().isEmpty() || m_edtMixAmplitude->text().isEmpty() || m_edtAdsorbPosition->text().isEmpty())
	{
		HGT::information(this, GetLang("1708420343"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}

	MixedProcessPara para;
	para.nProcessID = m_edtProcessID->text().toInt();
	para.nColumnNum = m_edtColumnNum->text().toInt();

	para.nMixedTime = m_edtMixedTime->text().toInt();
	para.nMixedSpeed = m_edtMixedSpeed->text().toInt();

	para.nAdsorbTime = m_edtAdsorbTime->text().toInt();
	para.nAdsorbSpeed = m_cbAdsorbSpeed->currentIndex() + 1;

	para.nWaitTime = m_edtWaitTime->text().toInt();
	para.nVolume = m_edtVolume->text().toInt();

	para.nMixPosition = m_edtMixPosition->text().toInt();
	para.nMixAmplitude = m_edtMixAmplitude->text().toInt();
	para.nAdsorbPosition = m_edtAdsorbPosition->text().toInt();

	int retCode = axeService->startMixedProcess(axeNumber, para);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Process StartMixed retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Process::slot_btnStartHeatProcess()
{
	if (axeService == nullptr)
		return;

	if (m_edtHeatProcessID->text().isEmpty() || m_edtAimDegree->text().isEmpty())
	{
		HGT::warning(this, GetLang("1708420344"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}

	const QValidator* validator = m_edtAimDegree->validator();
	const QIntValidator* intValidator = dynamic_cast<const QIntValidator*>(validator);
	if (m_edtAimDegree->text().toInt() < intValidator->bottom())
	{
		HGT::warning(this, GetLang("1708419699"), GetLang("1708420403"), QMessageBox::Ok);
		return;
	}

	HeatProcessPara para;
	para.nProcessID = m_edtHeatProcessID->text().toInt();
	para.nGroupNum = m_cbGroupNum->currentIndex();
	para.nAimDegree = m_edtAimDegree->text().toInt();
	para.nIsHeat = m_cbIsHeat->currentIndex();

	int retCode = axeService->startHeatProcess(axeNumber, para);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Process StartHeat retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Process::slot_btnNextPageClicked()
{
	m_firstPage->hide();
	m_secondPage->show();
}

void DeviceMaintainPage_Axe_Process::slot_btnFrontPageClicked()
{
	m_firstPage->show();
	m_secondPage->hide();
}