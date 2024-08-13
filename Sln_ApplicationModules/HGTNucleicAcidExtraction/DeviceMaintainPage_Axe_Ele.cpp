#include "DeviceMaintainPage_Axe_Ele.h"

DeviceMaintainPage_Axe_Ele::DeviceMaintainPage_Axe_Ele(QWidget * _parent, DeviceControlService _handle) :
	DeviceMaintainPage_Axe_Base(_parent, _handle)
{
	//创建QGridLayout布局
	QGridLayout *layoutMain = getNewGridLayout(this);
	layoutMain->setAlignment(Qt::AlignCenter);
	layoutMain->setHorizontalSpacing(20);
	layoutMain->setVerticalSpacing(30);

	//步进电机运行
	m_btnStepMonitorRun = getNewBtCommon(GetLang("1708420281"));
	layoutMain->addWidget(m_btnStepMonitorRun, 0, 0);

	m_cbMonitorNumber = getNewComboxBox({ "1708420271","1708420272" ,"1708420273" ,"1708420274" ,"1708420275" });
	layoutMain->addWidget(m_cbMonitorNumber, 0, 1);

	//创建QLabel 并且设置文本
	m_lbMonitorDirection = getNewLbCommon("1708420276");
	m_lbMonitorDirection->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	layoutMain->addWidget(m_lbMonitorDirection, 0, 2);

	//创建QComboBox组件 并且添加两个选项
	m_edtMonitorDirection = getNewComboxBox({ "1708420430" ,"1708420431" });
	m_edtMonitorDirection->setFixedWidth(90);
	m_edtMonitorDirection->setValidator(new QIntValidator(0, 1, this));
	layoutMain->addWidget(m_edtMonitorDirection, 0, 3);

	m_lbMonitorSpeed = getNewLbCommon("1708419955");
	m_lbMonitorSpeed->setFixedWidth(45);
	m_lbMonitorSpeed->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	layoutMain->addWidget(m_lbMonitorSpeed, 0, 4);

	//创建HLineEdit组件
	m_edtMonitorSpeed = getNewLineEdit();
	m_edtMonitorSpeed->setText("1");
	m_edtMonitorSpeed->setValidator(new QIntValidator(1, 30, this));
	m_edtMonitorSpeed->setPlaceholderText(QString::fromLocal8Bit("1-30"));
	connect(m_edtMonitorSpeed, &HLineEdit::textChanged, this, [=](QString _text) {
		if (_text.isEmpty())
			return;
		const QIntValidator *intValidator = dynamic_cast<const QIntValidator*>(m_edtMonitorSpeed->validator());
		float val = qBound((float)intValidator->bottom(), _text.toFloat(), (float)intValidator->top());
		m_edtMonitorSpeed->setText(QString::number(val));
	});
	layoutMain->addWidget(m_edtMonitorSpeed, 0, 5);

	m_lbMonitorDistance = getNewLbCommon("1708420277");
	m_lbMonitorDistance->setFixedWidth(45);
	m_lbMonitorDistance->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	layoutMain->addWidget(m_lbMonitorDistance, 0, 6);

	m_edtMonitorDistance = getNewLineEdit();
	m_edtMonitorDistance->setValidator(UIUtility::ins().RegExpNumber);
	m_edtMonitorDistance->setValidator(new QIntValidator(1, 50, this));
	m_edtMonitorDistance->setPlaceholderText(QString::fromLocal8Bit("1-50"));
	layoutMain->addWidget(m_edtMonitorDistance, 0, 7);

	//步进电机停止
	m_btnStepMonitorStop = getNewBtCommon(GetLang("1708420286"));
	layoutMain->addWidget(m_btnStepMonitorStop, 1, 0);

	m_cbStopMonitorNumber = getNewComboxBox({ "1708420271","1708420272" ,"1708420273" ,"1708420274" ,"1708420275" });
	layoutMain->addWidget(m_cbStopMonitorNumber, 1, 1);

	//步进电机回零
	m_btnStepMonitorZero = getNewBtCommon(GetLang("1708420287"));
	layoutMain->addWidget(m_btnStepMonitorZero, 2, 0);

	m_cbZeroMonitorNumber = getNewComboxBox({ "1708420271","1708420272" ,"1708420273" ,"1708420274" });
	layoutMain->addWidget(m_cbZeroMonitorNumber, 2, 1);

	//步进电机绝对位置运行
	m_btnStepMonitorAbsRun = getNewBtCommon(GetLang("1708420285"));
	layoutMain->addWidget(m_btnStepMonitorAbsRun, 3, 0);

	m_cbMonitorAbsNumber = getNewComboxBox({ "1708420271","1708420272" ,"1708420273" ,"1708420274" });
	layoutMain->addWidget(m_cbMonitorAbsNumber, 3, 1);

	m_lbMonitorAbsDistance = getNewLbCommon("1708420278");
	m_lbMonitorAbsDistance->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	layoutMain->addWidget(m_lbMonitorAbsDistance, 3, 2);

	m_edtMonitorAbsDistance = getNewLineEdit();
	m_edtMonitorAbsDistance->setValidator(UIUtility::ins().RegExpNumber);
	layoutMain->addWidget(m_edtMonitorAbsDistance, 3, 3);


	////步进电机脱机锁定
	//m_btnSetStepMonitorStatus = getNewBtCommon(GetLang("1708420280"));
	//layoutMain->addWidget(m_btnSetStepMonitorStatus, 4, 0);

	//m_cbMonitorSetNumber = getNewComboxBox({ "1708420271","1708420272" ,"1708420273" ,"1708420274" });
	//layoutMain->addWidget(m_cbMonitorSetNumber, 4, 1);

	//m_lbMonitorSetStatus = getNewLbCommon("1708420279");
	//layoutMain->addWidget(m_lbMonitorSetStatus, 4, 2);

	//m_edtMonitorSetStatus = getNewLineEdit();
	//m_edtMonitorSetStatus->setValidator(new QIntValidator(0, 1, this));
	//m_edtMonitorSetStatus->setPlaceholderText(QString::fromLocal8Bit("0-1"));
	//layoutMain->addWidget(m_edtMonitorSetStatus, 4, 3);

	this->setConnection();
}


void DeviceMaintainPage_Axe_Ele::setConnection()
{
	connect(m_btnStepMonitorRun, SIGNAL(clicked()), this, SLOT(slot_btnStepMonitorRunClicked()));
	connect(m_btnStepMonitorStop, SIGNAL(clicked()), this, SLOT(slot_btnStepMonitorStopClicked()));
	connect(m_btnStepMonitorZero, SIGNAL(clicked()), this, SLOT(slot_btnStepMonitorZeroClicked()));
	connect(m_btnStepMonitorAbsRun, SIGNAL(clicked()), this, SLOT(slot_btnStepMonitorAbsposRunClicked()));
	connect(m_cbMonitorNumber, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_cbMonitorNumberChanged(int)));
	connect(m_cbMonitorAbsNumber, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_cbMonitorAbsNumberChanged(int)));
}

void DeviceMaintainPage_Axe_Ele::slot_btnStepMonitorRunClicked()
{
	if (axeService == nullptr)
		return;

	if (m_edtMonitorSpeed->text().isEmpty() || m_edtMonitorDistance->text().isEmpty())
	{
		HGT::warning(this, GetLang("1708420281"), GetLang("1708420282"), QMessageBox::Ok);
		return;
	}

	int monitorNumber = m_cbMonitorNumber->currentIndex() + 1;
	int monitorDirection = m_edtMonitorDirection->currentText().toInt();
	int monitorSpeed = m_edtMonitorSpeed->text().toInt();
	float monitorDistance = m_edtMonitorDistance->text().toFloat();

	int retCode = axeService->startStepMonitor(axeNumber, monitorNumber, monitorDirection, monitorSpeed, monitorDistance);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Ele StepMonitorRun retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Ele::slot_btnStepMonitorZeroClicked()
{
	if (axeService == nullptr)
		return;

	int monitorNumber = m_cbZeroMonitorNumber->currentIndex() + 1;

	int retCode = axeService->zeroStepMonitor(axeNumber, monitorNumber);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Ele StepMonitorZero retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Ele::slot_btnStepMonitorStopClicked()
{
	if (axeService == nullptr)
		return;
	//1水平移动电机 2进出仓电机 3磁棒套电机 4磁棒电机 5磁棒套旋转电机
	int monitorNumber = m_cbStopMonitorNumber->currentIndex() + 1;

	int retCode = axeService->stopStepMonitor(axeNumber, monitorNumber);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Ele StepMonitorStop retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Ele::slot_btnSetStepMonitorStatusClicked()
{
	if (axeService == nullptr)
		return;

	if (m_edtMonitorSetStatus->text().isEmpty())
	{
		HGT::warning(this, QString::fromLocal8Bit("步进电机脱机锁定"), QString::fromLocal8Bit("<font size=6>脱机锁定参数不能为空"), QMessageBox::Ok);
		return;
	}

	int status = m_edtMonitorSetStatus->text().toInt();
	int monitorNumber = m_cbMonitorSetNumber->currentIndex() + 1;

	int retCode = axeService->setStepMonitorStatus(axeNumber, monitorNumber, status);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Ele SetStepMonitorStatus retCode = " + strErrorCode.toStdString());;
	}
}

void DeviceMaintainPage_Axe_Ele::slot_btnLockStepMonitorClicked()
{
	if (axeService == nullptr)
		return;

	int retCode = axeService->lockStepMonitor(axeNumber);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Ele LockStempMonitor retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Ele::slot_btnStepMonitorAbsposRunClicked()
{
	if (axeService == nullptr)
		return;

	if (m_edtMonitorAbsDistance->text().isEmpty())
	{
		HGT::warning(this, GetLang("1708420283"), GetLang("1708420284"), QMessageBox::Ok);
		return;
	}

	int monitorNum = m_cbMonitorAbsNumber->currentIndex() + 1;
	float absDistance = m_edtMonitorAbsDistance->text().toFloat();

	int retCode = axeService->startStepMonitorWithAbspos(axeNumber, monitorNum, absDistance);
	if (retCode != 0)
	{
		QString strErrorCode = QString("%1").arg(retCode, 4, 16, QLatin1Char('0'));
		Log("DeviceMaintainPage_Axe_Ele StepMonitorAbsposRun retCode = " + strErrorCode.toStdString());
	}
}

void DeviceMaintainPage_Axe_Ele::slot_cbMonitorNumberChanged(int index)
{
	switch (index)
	{
	case 0:
		m_edtMonitorSpeed->setValidator(new QIntValidator(1, 30, this));
		m_edtMonitorSpeed->setPlaceholderText(QString::fromLocal8Bit("1-30"));
		m_edtMonitorDistance->setValidator(new QIntValidator(1, 50, this));
		m_edtMonitorDistance->setPlaceholderText(QString::fromLocal8Bit("1-50"));
		break;
	case 1:
		m_edtMonitorSpeed->setValidator(new QIntValidator(1, 30, this));
		m_edtMonitorSpeed->setPlaceholderText(QString::fromLocal8Bit("1-30"));
		m_edtMonitorDistance->setValidator(new QIntValidator(1, 153, this));
		m_edtMonitorDistance->setPlaceholderText(QString::fromLocal8Bit("1-153"));
		break;
	case 2:
		m_edtMonitorSpeed->setValidator(new QIntValidator(1, 30, this));
		m_edtMonitorSpeed->setPlaceholderText(QString::fromLocal8Bit("1-30"));
		m_edtMonitorDistance->setValidator(new QIntValidator(1, 40, this));
		m_edtMonitorDistance->setPlaceholderText(QString::fromLocal8Bit("1-40"));
		break;
	case 3:
		m_edtMonitorSpeed->setValidator(new QIntValidator(1, 30, this));
		m_edtMonitorSpeed->setPlaceholderText(QString::fromLocal8Bit("1-30"));
		m_edtMonitorDistance->setValidator(new QIntValidator(1, 67, this));
		m_edtMonitorDistance->setPlaceholderText(QString::fromLocal8Bit("1-67"));
		break;
	case 4:
		m_edtMonitorSpeed->setValidator(new QIntValidator(1, 3000, this));
		m_edtMonitorSpeed->setPlaceholderText(QString::fromLocal8Bit("1-3000"));
		m_edtMonitorDistance->setValidator(new QIntValidator(0, 0, this));
		m_edtMonitorDistance->setPlaceholderText(QString::fromLocal8Bit("0"));
		break;
	default:
		break;
	}
}

void DeviceMaintainPage_Axe_Ele::slot_cbMonitorAbsNumberChanged(int index)
{
	m_edtMonitorAbsDistance->clear();

	switch (index)
	{
	case 0:
		m_edtMonitorAbsDistance->setValidator(new QIntValidator(-5, 300, this));
		m_edtMonitorAbsDistance->setPlaceholderText(QString::fromLocal8Bit("-5-300"));
		break;
	case 1:
		m_edtMonitorAbsDistance->setValidator(new QIntValidator(-15, 140, this));
		m_edtMonitorAbsDistance->setPlaceholderText(QString::fromLocal8Bit("-15-140"));
		break;
	case 2:
		m_edtMonitorAbsDistance->setValidator(new QIntValidator(-15, 62.0, this));
		m_edtMonitorAbsDistance->setPlaceholderText(QString::fromLocal8Bit("-15-62.0"));
		break;
	case 3:;
		m_edtMonitorAbsDistance->setValidator(new QIntValidator(-15, 60, this));
		m_edtMonitorAbsDistance->setPlaceholderText(QString::fromLocal8Bit("-15-60"));
		break;
	default:
		break;
	}
}