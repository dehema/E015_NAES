#include "PlayView.h"

PlayView::PlayView(QWidget * parent) :BasePageContent(parent)
{
	btGroup = new QButtonGroup(this);
	connect(btGroup, SIGNAL(buttonClicked(int)), this, SLOT(slot_onclickBt(int)));

	processIconGroup = new QButtonGroup(this);
	connect(processIconGroup, SIGNAL(buttonClicked(int)), this, SLOT(slot_onclickProcessIcon(int)));

	layoutMain = getNewVBoxLayout(this);
	layoutMain->setAlignment(Qt::AlignCenter);
	layoutMain->setContentsMargins(0, 0, 0, 0);


	//operate
	QWidget* widgetOperate = getNewWidgetCommon();
	widgetOperate->setFixedSize(getContentWidth(), 40);
	layoutMain->addWidget(widgetOperate);

	QHBoxLayout* layoutOperate = getNewHBoxLayout(widgetOperate);
	layoutOperate->setSpacing(15);
	layoutOperate->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

	//运行
	QPushButton* btLaunch = getNewBtCommon("1708420161");
	btGroup->addButton(btLaunch, BtType::Launch);
	layoutOperate->addWidget(btLaunch);

	//查看
	QPushButton* btPreview = getNewBtCommon("1708430051");
	btGroup->addButton(btPreview, BtType::Preview);
	layoutOperate->addWidget(btPreview);

	//表格模式
	btGridMode = getNewBtCommon("1708430052");
	btGridMode->hide();
	btGroup->addButton(btGridMode, BtType::GridMode);
	layoutOperate->addWidget(btGridMode);

	//列表模式
	btListModel = getNewBtCommon("1708430053");
	btGroup->addButton(btListModel, BtType::ListMode);
	layoutOperate->addWidget(btListModel);

	//data
	showGridProcess();
}

void PlayView::showGridProcess()
{
	int contentWidth = getContentWidth();
	int itemSize = contentWidth / 7;
	if (widgetGrid == nullptr)
	{
		widgetGrid = getNewFrame();
		widgetGrid->setFixedSize(getContentWidth(), size().height() - 40);
		layoutMain->insertWidget(0, widgetGrid);

		scrollProcess = new QScrollArea(widgetGrid);
		scrollProcess->setFixedSize(widgetGrid->size());
		scrollProcess->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

		widgetGridParent = getNewWidgetCommon(scrollProcess);
		//widgetGridParent->setFixedSize(getContentWidth(), 2000);
		widgetGridParent->setFixedWidth(getContentWidth());
		widgetGridParent->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		scrollProcess->setWidget(widgetGridParent);

		gridProcess = getNewGridLayout(widgetGridParent);
		gridProcess->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
		gridSpacing = getContentWidth() / 21;
		gridProcess->setHorizontalSpacing(gridSpacing);
		gridProcess->setVerticalSpacing(20);
		gridProcess->setContentsMargins(20, 20, 20, 20);
	}

	//del
	for (AXEProcessItem* item : processItemList)
		delete item;
	processItemList.clear();
	processIconGroup->buttons().clear();

	processList = AXEMgr().ins().getAllProcess();
	for (int i = 0; i < processList.count(); i++)
	{
		AXEProcessData processData = processList[i];
		AXEProcessItem* item = new AXEProcessItem(this);
		item->setText(processData.processName);
		item->setFixedSize(itemSize, itemSize);
		processItemList.append(item);
		processIconGroup->addButton(item->icon, processIconGroup->buttons().count());
		gridProcess->addWidget(item, i / 5, i % 5);
	}
	int rowCount = gridProcess->rowCount();
	int gridHeight = gridProcess->contentsMargins().top() + gridProcess->contentsMargins().bottom() +
		rowCount*itemSize + (rowCount - 1)*gridProcess->verticalSpacing();
	gridHeight = qMax(gridHeight, 0);
	widgetGridParent->setFixedHeight(gridHeight);

	widgetGrid->show();
	if (tbProcess != nullptr)
		tbProcess->hide();
	btGridMode->hide();
	btListModel->show();
}

void PlayView::showTbProcess()
{
	if (tbProcess == nullptr)
	{
		tbProcess = getNewTableView();
		tbProcess->setFixedSize(getContentWidth(), size().height() - 40);
		tbProcess->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
		tbProcess->horizontalHeader()->setFixedHeight(40);
		layoutMain->insertWidget(0, tbProcess);
		tmProcess = new HTableViewItemModel(this);
		QStringList headertbAxeProcess; headertbAxeProcess
			<< GetLang("1708420155")			//名称
			<< GetLang("1708420084") + "(Min)"	//预计时长
			<< GetLang("1708419632")			//创建时间
			;
		tmProcess->setHorizontalHeaderLabels(headertbAxeProcess);
		tmProcess->setColumnCount(headertbAxeProcess.count());
		tbProcess->setModel(tmProcess);
		UIUtility::ins().setTableRowHeight((QTableView*&)tbProcess);

	}
	tmProcess->removeRows(0, tmProcess->rowCount());
	processList = AXEMgr().ins().getAllProcess();
	tmProcess->setRowCount(processList.count());
	for (int i = 0; i < processList.count(); i++)
	{
		AXEProcessData processData = processList[i];
		//名称
		tmProcess->setData(tmProcess->index(i, 0), processData.processName);
		//预计时长
		tmProcess->setData(tmProcess->index(i, 1), processData.getEstimatedSec());
		//创建时间
		tmProcess->setData(tmProcess->index(i, 2), QDateTime::fromSecsSinceEpoch(processData.createDate).toString("yyyy-MM-dd hh:mm:ss"));
	}
	tbProcess->setModel(tmProcess);
	UIUtility::ins().setTableRowHeight((QTableView*&)tbProcess);

	widgetGrid->hide();
	tbProcess->show();
	btGridMode->show();
	btListModel->hide();
}

void PlayView::slot_onclickBt(int _index)
{
	switch (_index)
	{
	case PlayView::Launch:
		break;
	case PlayView::Preview:
		break;
	case PlayView::GridMode:
	{
		showGridProcess();
		break;
	}
	case PlayView::ListMode:
	{
		showTbProcess();
		break;
	}
	}
}

void PlayView::slot_onclickProcessIcon(int _index)
{
	for (AXEProcessItem* item : processItemList)
	{
		item->icon->showNormalIcon();
	}
	AXEProcessData processData = processList[_index];
	Log(processData.processName);
}