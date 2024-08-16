#include "AXERuningView.h"


AXERuningView::AXERuningView(QWidget *parent) :BasePageContent(parent)
{
	axeThread = dynamic_cast<AxeThread*>(Utility::ins().axeThread);

	btGroup = new QButtonGroup();
	connect(btGroup, SIGNAL(buttonClicked(int)), this, SLOT(slot_onclickBt(int)));
	connect(axeThread, SIGNAL(signal_onAxeStepLaunch(AXEStepData)), this, SLOT(slot_onAxeStepLaunch(AXEStepData)));
	connect(axeThread, SIGNAL(signal_onAxeProcessFinish(AXEProcessData)), this, SLOT(slot_onAxeProcessFinish(AXEProcessData)));
	connect(&launchTimer, &QTimer::timeout, this, [this]() {refreshStatus(); AXERuningView::launchTimeCountDown(); });

	//UI
	layoutMain = getNewVBoxLayout(this);
	layoutMain->setContentsMargins(Page_Dialog_Padding_Left, Page_Dialog_Padding_Top, Page_Dialog_Padding_Right, Page_Dialog_Padding_Bottom);
	layoutMain->setSpacing(10);
	layoutMain->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

	QWidget* widgetProcessName = getNewFrame();
	widgetProcessName->setFixedSize(width() - Page_Dialog_Padding_Left * 2, 40);
	layoutMain->addWidget(widgetProcessName);

	QHBoxLayout* layoutProcessName = getNewHBoxLayout(widgetProcessName);
	layoutProcessName->setContentsMargins(Page_Dialog_Padding_Left, 0, Page_Dialog_Padding_Right, 0);
	layoutProcessName->setAlignment(Qt::AlignCenter);
	layoutProcessName->setSpacing(10);

	//流程名称
	QLabel* l1 = getNewLbCommon();
	l1->setText(GetLang("1708420086") + ":");
	layoutProcessName->addWidget(l1);

	editProcessName = getNewLineEdit();
	editProcessName->setFixedWidth(450);
	editProcessName->setEnabled(false);
	layoutProcessName->addWidget(editProcessName);

	layoutProcessName->addStretch();

	//剩余时间
	QLabel* l2 = getNewLbCommon();
	l2->setText(GetLang("1708420153") + ":");
	layoutProcessName->addWidget(l2);

	lbRemainTime = getNewLbCommon();
	lbRemainTime->setFixedWidth(120);
	layoutProcessName->addWidget(lbRemainTime);

	//运行状态
	QLabel* l3 = getNewLbCommon();
	l3->setText(GetLang("1708419543") + ":");

	lbStatus = getNewLbCommon();
	layoutProcessName->addWidget(lbStatus);

	//QPushButton* btClose = getNewBtCommon("1708420233");
	//btGroup->addButton(btClose, BtType::Close);
	//layoutProcessName->addWidget(btClose);

	//表格
	tbStep = getNewTableView();
	tbStep->setEnabled(false);
	tbModelProcess = new HTableViewItemModel(this);
	tbModelProcess->setRowCount(10);
	tbModelProcess->setColumnCount(7);
	QStringList headerProcessDetail;
	headerProcessDetail
		<< GetLang("1708419680")	//序号
		<< GetLang("1708420088")	//孔位
		<< GetLang("1708420155")	//名称
		<< GetLang("1708420156")	//体系容量
		<< GetLang("1708420379")	//混合
		<< GetLang("1708430054")	//吸磁
		<< GetLang("1708430055")	//等待
		;
	tbModelProcess->setHorizontalHeaderLabels(headerProcessDetail);
	tbStep->setFixedSize(getContentWidth() - Page_Dialog_Padding_Left * 2, 382);
	tbStep->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
	tbStep->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	tbStep->verticalScrollBar()->hide();
	layoutMain->addWidget(tbStep, 0, Qt::AlignTop | Qt::AlignHCenter);

	QWidget* widgetTemperature = getNewWidgetCommon();
	widgetTemperature->setFixedSize(width() - Page_Dialog_Padding_Left * 2, 40);
	layoutMain->addWidget(widgetTemperature);

	QHBoxLayout* layoutTemperature = getNewHBoxLayout(widgetTemperature);
	layoutTemperature->setSpacing(5);
	layoutTemperature->setAlignment(Qt::AlignCenter);
	layoutTemperature->setContentsMargins(Page_Dialog_Padding_Left, 0, Page_Dialog_Padding_Right, 0);

	//1
	QLabel* lbt1 = getNewLbCommon();
	lbt1->setText("T1");
	layoutTemperature->addWidget(lbt1);

	editT1 = getNewLineEdit();
	editT1->setFixedWidth(70);
	editT1->setEnabled(false);
	editT1->setText("0");
	layoutTemperature->addWidget(editT1);

	QLabel* lboc1 = getNewLbCommon();
	lboc1->setText(QString::fromLocal8Bit("℃"));
	layoutTemperature->addWidget(lboc1);
	layoutTemperature->addSpacing(30);

	//2
	QLabel* lbt2 = getNewLbCommon();
	lbt2->setText("T2");
	layoutTemperature->addWidget(lbt2);

	editT2 = getNewLineEdit();
	editT2->setFixedWidth(70);
	editT2->setEnabled(false);
	editT2->setText("0");
	layoutTemperature->addWidget(editT2);

	QLabel* lboc2 = getNewLbCommon();
	lboc2->setText(QString::fromLocal8Bit("℃"));
	layoutTemperature->addWidget(lboc2);
	layoutTemperature->addSpacing(30);

	//3
	QLabel* lbt3 = getNewLbCommon();
	lbt3->setText("T3");
	layoutTemperature->addWidget(lbt3);

	editT3 = getNewLineEdit();
	editT3->setFixedWidth(70);
	editT3->setEnabled(false);
	editT3->setText("0");
	layoutTemperature->addWidget(editT3);

	QLabel* lboc3 = getNewLbCommon();
	lboc3->setText(QString::fromLocal8Bit("℃"));
	layoutTemperature->addWidget(lboc3);
	layoutTemperature->addSpacing(30);

	//4
	QLabel* lbt4 = getNewLbCommon();
	lbt4->setText("T4");
	layoutTemperature->addWidget(lbt4);

	editT4 = getNewLineEdit();
	editT4->setFixedWidth(70);
	editT4->setEnabled(false);
	editT4->setText("0");
	layoutTemperature->addWidget(editT4);

	QLabel* lboc4 = getNewLbCommon();
	lboc4->setText(QString::fromLocal8Bit("℃"));
	layoutTemperature->addWidget(lboc4);
	layoutTemperature->addStretch();

	//继续
	btContinue = getNewBtCommon("1708420347");
	btGroup->addButton(btContinue, (int)BtType::Continue);
	layoutTemperature->addWidget(btContinue);

	//暂停
	btPause = getNewBtCommon("1708420162");
	btPause->move(0, 0);
	btGroup->addButton(btPause, (int)BtType::Pause);
	layoutTemperature->addWidget(btPause);

	layoutTemperature->addSpacing(15);

	//停止
	btReset = getNewBtCommon("1708420348");
	btGroup->addButton(btReset, (int)BtType::Reset);
	layoutTemperature->addWidget(btReset);

	if (Utility::ins().deviceHandle.axeService != nullptr)
	{
		connect(&temperatureTimer, &QTimer::timeout, this, [=]() {refreshTemperature(); });
		temperatureTimer.start(1000);
	}
}

void AXERuningView::launchTimeCountDown()
{
	float speed = 0;
	if (remainingTime > otherStepRemainingTime)
	{
		if (remainingTime - otherStepRemainingTime > 20)
		{
			speed += 0.4f;
		}
		speed += (0.5f + (remainingTime - otherStepRemainingTime) / 100.0f);
		remainingTime -= speed;
	}
	if (remainingTime <= 0)
	{
		remainingTime = 0;
		launchTimer.stop();
	}
	lbRemainTime->setText(Utility::ins().secondToMinute((int)remainingTime));
}

void AXERuningView::refreshTemperature()
{
	HeatBoardData heatBoardData = Utility::ins().deviceHandle.axeService->getCurrentTemperature(1, 1, 0);
	editT1->setText(QString::number(heatBoardData.degree[0], 'f', 1));
	editT2->setText(QString::number(heatBoardData.degree[1], 'f', 1));
	editT3->setText(QString::number(heatBoardData.degree[2], 'f', 1));
	editT4->setText(QString::number(heatBoardData.degree[3], 'f', 1));
}

void AXERuningView::launchContinue()
{
	axeThread->setStatus(AXEDeviceStatus::AXEDeviceStatusExecuting);
	launchTimer.start(1000);
}

void AXERuningView::launchPause()
{
	axeThread->setStatus(AXEDeviceStatus::AXEDeviceStatusPause);
	launchTimer.stop();
	refreshStatus();
}

void AXERuningView::launchReset()
{
	axeThread->reset();
	refreshStatus();
}

void AXERuningView::slot_onclickBt(int index)
{
	switch (index)
	{
	case BtType::Continue:
		launchContinue();
		break;
	case BtType::Pause:
		launchPause();
		break;
	case BtType::Reset:
		launchReset();
		break;
	case BtType::Close:
		emit signal_closeRuningView();
		break;
	}
}

void AXERuningView::launchProcess(AXEProcessData _data)
{
	//data
	currProcessData = _data;
	//UI
	editProcessName->setText(currProcessData.processName);
	lbRemainTime->setText(Utility::ins().secondToMinute(currProcessData.getEstimatedTime()));
	//表格数据
	tbModelProcess->removeRows(0, tbModelProcess->rowCount());
	for (int _row = 0; _row < currProcessData.stepsList.length(); _row++)
	{
		AXEStepData data = currProcessData.stepsList[_row];
		QList<QStandardItem*> items;
		//编号
		items << new QStandardItem(QString::number(data.stepIndex));
		//孔位
		items << new QStandardItem(QString::number(data.column));
		//名称
		items << new QStandardItem(data.stepName);
		//体系容量
		items << new QStandardItem(QString::number(data.volume) + QString::fromLocal8Bit("μL"));
		//混合时间
		items << new QStandardItem(AXEMgr::ins().getMixBtStr(data));
		//吸磁时间
		items << new QStandardItem(AXEMgr::ins().getMagnetBtStr(data));
		//等待时间
		items << new QStandardItem(AXEMgr::ins().getWaitBtStr(data));
		tbModelProcess->appendRow(items);
	}
	tbStep->setModel(tbModelProcess);
	UIUtility::ins().setTableRowHeight(tbStep);

	tbStep->selectRow(0);
	//运行
	axeThread->launchAxeProcess(currProcessData);
	refreshStatus();
	launchTimer.start(1000);
}

void AXERuningView::slot_onAxeStepLaunch(AXEStepData _stepData)
{
	currStepData = _stepData;
	remainingTime = currProcessData.getEstimatedTime(_stepData.stepIndex - 1);
	otherStepRemainingTime = currProcessData.getEstimatedTime(currStepData.stepIndex);
	stepDuration = currProcessData.getEstimatedTime(currStepData.stepIndex - 1) - currProcessData.getEstimatedTime(currStepData.stepIndex);
	for (int i = 0; i < currProcessData.stepsList.count(); i++)
	{
		if (currProcessData.stepsList[i] == _stepData)
		{
			tbStep->selectRow(i);
			break;
		}
	}
}

void AXERuningView::slot_onAxeProcessFinish(AXEProcessData _processData)
{
	launchTimer.stop();
	remainingTime = 0;
	launchTimeCountDown();
	HGT::information(this, GetLang("1708419621"), GetLang("1708430059"), QMessageBox::Ok);
	emit signal_closeRuningView();
}

//设置状态  0:正在等待 1:正在进行
void AXERuningView::refreshStatus()
{
	AXEDeviceStatus status = axeThread->axeStatus;
	switch (status)
	{
	case AXEDeviceStatus::AXEDeviceStatusFree:
		lbStatus->setText(GetLang("1708420394"));
		break;
	case AXEDeviceStatus::AXEDeviceStatusExecuting:
		lbStatus->setText(GetLang("1708420392"));
		break;
	case AXEDeviceStatus::AXEDeviceStatusPause:
		lbStatus->setText(GetLang("1708420162"));
		break;
	}
	btPause->setVisible(status == AXEDeviceStatus::AXEDeviceStatusExecuting);
	btContinue->setVisible(status == AXEDeviceStatus::AXEDeviceStatusPause);
	btReset->setVisible(status == AXEDeviceStatus::AXEDeviceStatusExecuting || status == AXEDeviceStatus::AXEDeviceStatusPause);
}

void AXERuningView::showEvent(QShowEvent *event)
{
	if (!temperatureTimer.isActive())
		temperatureTimer.start(1000);
	BasePageContent::showEvent(event);
}

void AXERuningView::hideEvent(QHideEvent *event)
{
	if (temperatureTimer.isActive())
		temperatureTimer.stop();
	BasePageContent::hideEvent(event);
}