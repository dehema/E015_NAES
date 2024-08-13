#include "ProcessView.h"

ProcessView::ProcessView(QWidget *parent) :BasePageContent(parent)
{
	btGroup = new QButtonGroup();
	connect(btGroup, SIGNAL(buttonClicked(int)), this, SLOT(slot_onclickBt(int)));

	//UI
	layoutMain = getNewVBoxLayout(this);
	layoutMain->setContentsMargins(Page_Dialog_Padding_Left, Page_Dialog_Padding_Top, Page_Dialog_Padding_Right, Page_Dialog_Padding_Bottom);
	layoutMain->setSpacing(10);
	layoutMain->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

	QWidget* widgetName = getNewWidgetCommon(this);
	widgetName->setFixedSize(getContentWidth(), 35);
	layoutMain->addWidget(widgetName);

	QHBoxLayout* layoutName = getNewHBoxLayout(widgetName);
	layoutName->setSpacing(15);

	editProcessName = getNewLineEdit();
	layoutName->addWidget(editProcessName);

	QPushButton* btOpenProcess = getNewBtCommon("1708419679");
	btGroup->addButton(btOpenProcess, BtType::OpenProcess);
	layoutName->addWidget(btOpenProcess);

	editProcessName->setFixedWidth(getContentWidth() - btOpenProcess->width() - layoutName->spacing() - Page_Dialog_Padding_Left * 2);

	QWidget* widgetOperate = getNewWidgetCommon(this);
	widgetOperate->setFixedSize(getContentWidth(), 35);
	layoutMain->addWidget(widgetOperate);

	QHBoxLayout* layoutOperate = getNewHBoxLayout(widgetOperate);
	layoutOperate->setSpacing(15);

	QPushButton* btNewProcess = getNewBtCommon("1708420099");
	btGroup->addButton(btNewProcess, BtType::NewProcess);
	layoutOperate->addWidget(btNewProcess);

	QPushButton* btNewStep = getNewBtCommon("1708420109");
	btGroup->addButton(btNewStep, BtType::NewStep);
	layoutOperate->addWidget(btNewStep);

	QPushButton* btRemoveStep = getNewBtCommon("1708420078");
	btGroup->addButton(btRemoveStep, BtType::DelStep);
	layoutOperate->addWidget(btRemoveStep);

	QPushButton* btSave = getNewBtCommon("1708419677");
	btGroup->addButton(btSave, BtType::Save);
	layoutOperate->addWidget(btSave);

	tbProcess = getNewTableView();
	tbModelProcess = new QStandardItemModel(this);
	tbModelProcess->setRowCount(stepCountMax);
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
	selectionModelProcess = new QItemSelectionModel(tbModelProcess);
	connect(selectionModelProcess, SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(slot_onTbProcessSelectRow(QModelIndex, QModelIndex)));
	tbProcess->setFixedSize(getContentWidth() - Page_Dialog_Padding_Left * 2, 382);
	tbProcess->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
	tbProcess->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	tbProcess->setModel(tbModelProcess);
	tbProcess->setSelectionModel(selectionModelProcess);
	layoutMain->addWidget(tbProcess, 0, Qt::AlignTop | Qt::AlignHCenter);
	UIUtility::ins().setTableRowHeight(tbProcess);
	processItemWidth = tbProcess->width() / headerProcessDetail.count();

	//data
	fillWidgetTableItems();
	refreshTbProcess();
}

void ProcessView::refreshTbProcess()
{
	for (int _row = 0; _row < currProcessData.stepsList.count(); _row++)
	{
		AXEStepData data = currProcessData.stepsList[_row];
		addRowTbProcess(_row, data);
	}
	tbProcess->setModel(tbModelProcess);
	//清空数据
	for (int _row = currProcessData.stepsList.count(); _row < stepCountMax; _row++)
	{
		tbModelProcess->setData(tbModelProcess->index(_row, 0), "");
		setWidgetTableItemVisible(_row, false);
	}
}


void ProcessView::fillWidgetTableItems()
{
	for (int i = 0; i < stepCountMax; i++)
	{
		QList<QWidget*> list = QList<QWidget*>();
		for (int i = 0; i < tbModelProcess->columnCount() - 1; i++)
			list.append(nullptr);
		widgetTableItems.append(list);
	}
}

void ProcessView::addRowTbProcess(int _row, AXEStepData _data)
{
	//编号
	tbModelProcess->setData(tbModelProcess->index(_row, 0), QString::number(_row + 1));
	tbModelProcess->setData(tbModelProcess->index(_row, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
	setWidgetTableItemVisible(_row, true);
	int col = -1;
	//孔位
	QWidget* w0 = getWidgetTableItem(_row, ++col);
	QComboBox* cbSlotID;
	if (w0 == nullptr)
	{
		cbSlotID = getNewComboxBox();
		cbSlotID->setFixedSize(processItemWidth, UI_TableView_RowHeight);
		QListView *ListView = new QListView;
		cbSlotID->setView(ListView);
		cbSlotID->setStyleSheet(UIUtility::ins().comboxTableStyle);
		cbSlotID->addItems({ "1","2","3","4","5","6" });
		widgetTableItems[_row][col] = cbSlotID;
		tbProcess->setIndexWidget(tbModelProcess->index(_row, col + 1), cbSlotID);
	}
	else
	{
		cbSlotID = dynamic_cast<QComboBox*>(w0);
	}
	cbSlotID->setCurrentText(QString::number(_data.column));
	//步骤名称
	QWidget* w1 = getWidgetTableItem(_row, ++col);
	HLineEdit* editStepName;
	if (w1 == nullptr)
	{
		editStepName = getNewLineEdit();
		editStepName->setMaxLength(30);
		editStepName->setFixedSize(processItemWidth - 2, UI_TableView_RowHeight);
		editStepName->setStyleSheet(UIUtility::ins().editTableStyle);
		widgetTableItems[_row][col] = editStepName;
		tbProcess->setIndexWidget(tbModelProcess->index(_row, col + 1), editStepName);
	}
	else
	{
		editStepName = dynamic_cast<HLineEdit*>(w1);
	}
	editStepName->setText(_data.stepName);
	//体系容量
	QWidget* wEditDosage = getWidgetTableItem(_row, ++col);
	HLineEdit* editDosage;
	if (wEditDosage == nullptr)
	{
		editDosage = getNewLineEdit();
		editDosage->setAlignment(Qt::AlignCenter);
		editDosage->setFixedSize(processItemWidth, UI_TableView_RowHeight);
		editDosage->setStyleSheet(UIUtility::ins().editTableStyle);
		editDosage->setPlaceholderText("1-1000");
		editDosage->setValidator(UIUtility::ins().RegExpNumber);
		widgetTableItems[_row][col] = editDosage;
		tbProcess->setIndexWidget(tbModelProcess->index(_row, col + 1), editDosage);
	}
	else
	{
		editDosage = dynamic_cast<HLineEdit*>(wEditDosage);
	}
	editDosage->setText(QString::number(_data.volume));
	//混合
	QWidget* wMix = getWidgetTableItem(_row, ++col);
	QPushButton* btMix;
	if (wMix == nullptr)
	{
		btMix = getNewBtCommon();
		btMix->setFixedSize(processItemWidth - 2, UI_TableView_RowHeight);
		btMix->setStyleSheet(UIUtility::ins().btTableStyle);
		connect(btMix, &QPushButton::clicked, this, [=]() {
			ProcessParamsDialog* dialog = new ProcessParamsDialog(this, currProcessData.stepsList[_row], ProcessParamsDialog::AXEParamsType::Mix);
			dialog->exec();
			btMix->setText(AXEMgr::ins().getMixBtStr(currProcessData.stepsList[_row]));
		});
		widgetTableItems[_row][col] = btMix;
		tbProcess->setIndexWidget(tbModelProcess->index(_row, col + 1), btMix);
	}
	else
	{
		btMix = dynamic_cast<QPushButton*>(wMix);
	}
	btMix->setText(AXEMgr::ins().getMixBtStr(currProcessData.stepsList[_row]));
	//吸磁
	QWidget* wMagnet = getWidgetTableItem(_row, ++col);
	QPushButton* btMagnet;
	if (wMagnet == nullptr)
	{
		btMagnet = getNewBtCommon();
		btMagnet->setFixedSize(processItemWidth - 2, UI_TableView_RowHeight);
		btMagnet->setStyleSheet(UIUtility::ins().btTableStyle);
		connect(btMagnet, &QPushButton::clicked, this, [=]() {
			ProcessParamsDialog* dialog = new ProcessParamsDialog(this, currProcessData.stepsList[_row], ProcessParamsDialog::AXEParamsType::Magnet);
			dialog->exec();
			btMagnet->setText(AXEMgr::ins().getMagnetBtStr(currProcessData.stepsList[_row]));
		});
		widgetTableItems[_row][col] = btMagnet;
		tbProcess->setIndexWidget(tbModelProcess->index(_row, col + 1), btMagnet);
	}
	else
	{
		btMagnet = dynamic_cast<QPushButton*>(wMagnet);
	}
	btMagnet->setText(AXEMgr::ins().getMagnetBtStr(currProcessData.stepsList[_row]));
	//等待
	QWidget* wWait = getWidgetTableItem(_row, ++col);
	QPushButton* btWait;
	if (wWait == nullptr)
	{
		btWait = getNewBtCommon();
		btWait->setFixedSize(processItemWidth - 2, UI_TableView_RowHeight);
		btWait->setStyleSheet(UIUtility::ins().btTableStyle);
		connect(btWait, &QPushButton::clicked, this, [=]() {
			ProcessParamsDialog* dialog = new ProcessParamsDialog(this, currProcessData.stepsList[_row], ProcessParamsDialog::AXEParamsType::Wait);
			dialog->exec();
			btWait->setText(AXEMgr::ins().getWaitBtStr(currProcessData.stepsList[_row]));
		});
		widgetTableItems[_row][col] = btWait;
		tbProcess->setIndexWidget(tbModelProcess->index(_row, col + 1), btWait);
	}
	else
	{
		btWait = dynamic_cast<QPushButton*>(wWait);
	}
	btWait->setText(AXEMgr::ins().getWaitBtStr(currProcessData.stepsList[_row]));
}



QWidget* ProcessView::getWidgetTableItem(int _rowIndex, int _colIndex)
{
	return widgetTableItems[_rowIndex][_colIndex];
}

void ProcessView::setWidgetTableItemVisible(int _row, bool _visible)
{
	for (int _col = 0; _col < tbModelProcess->columnCount() - 1; _col++)
	{
		QWidget* widget = getWidgetTableItem(_row, _col);
		if (widget != nullptr)
		{
			if (_visible && !widget->isVisible())
			{
				widget->show();
			}
			else if (!_visible&&widget->isVisible())
			{
				widget->hide();
			}
		}
	}
}

bool ProcessView::isLegalSelRowIndexProcess()
{
	return selRowIndexProcess >= 0 && selRowIndexProcess < currProcessData.stepsList.count();
}

void ProcessView::openProcess()
{
	QList<QString> strList = AXEMgr::ins().getAllProcessNames();
	ChooseItemListDialog* dialog = new ChooseItemListDialog(this, strList);
	dialog->setTitle(GetLang("1708420113"));
	int res = dialog->exec();
	if (res == -1)
		return;
	QString name = strList[res];
	loadProcess(name);
}

void ProcessView::newProcess()
{
	if (selectionModelProcess->currentIndex().row() != -1 && isLegalSelRowIndexProcess() && !currProcessData.isPublish)
	{
		int res = HGT::warning(this, GetLang("1708419699"), GetLang("1708420139"), QMessageBox::Yes | QMessageBox::No);
		if (res == QMessageBox::No)
		{
			return;
		}
	}
	editProcessName->clear();
	currProcessData = AXEProcessData();
	refreshTbProcess();
}

void ProcessView::newStep()
{
	if (selRowIndexProcess == -1)
	{
		HGT::warning(this, GetLang("1708419621"), GetLang("1708420106"), QMessageBox::Yes);
		return;
	}
	if (currProcessData.stepsList.count() >= stepCountMax)
	{
		HGT::warning(this, GetLang("1708419621").arg(stepCountMax), GetLang("1708420108").arg(stepCountMax), QMessageBox::Yes);
		return;
	}
	AXEStepData data = AXEStepData();
	data.stepName = "step" + QString::number(currProcessData.stepCount + 1);
	currProcessData.stepsList.append(data);
	currProcessData.stepCount = currProcessData.stepsList.count();
	addRowTbProcess(currProcessData.stepCount - 1, currProcessData.stepsList.last());
}

void ProcessView::delStep()
{
	if (!isLegalSelRowIndexProcess())
	{
		HGT::warning(this, GetLang("1708419621"), GetLang("1708420107"), QMessageBox::Yes);
		return;
	}
	currProcessData.stepsList.removeAt(selRowIndexProcess);
	refreshTbProcess();
}

void ProcessView::save()
{
	if (!isLegalSelRowIndexProcess())
	{
		HGT::warning(this, GetLang("1708419699"), GetLang("1708420106"), QMessageBox::Yes);
		return;
	}
	AXEProcessData processModel = getPublishProcessModel();
	if (processModel.processName.isEmpty())
	{
		HGT::warning(this, GetLang("1708419699"), GetLang("1708420481"), QMessageBox::Yes);
		return;
	}
	QString publicPath = AXEMgr::ins().configFolderPath + processModel.processName + ".json";
	QFile file(publicPath);
	if (file.exists())
	{
		int res = HGT::warning(this, GetLang("1708419699"), GetLang("1708419696"), QMessageBox::Yes | QMessageBox::No);
		if (res == QMessageBox::No)
		{
			return;
		}
	}
	processModel.isPublish = true;
	currProcessData.isPublish = true;
	QString str = AXEMgr::ins().getPrecessJsonStr(processModel);
	string str1 = str.toStdString();
	const char* ch = str1.data();
	if (file.open(QIODevice::WriteOnly))
	{
		file.write(ch);
		file.close();
		HGT::information(this, GetLang("1708419621"), GetLang("1708419697"), QMessageBox::Yes);
		Log(QString::fromLocal8Bit("发布至%1").arg(publicPath));
	}
	else {
		HGT::Error(this, GetLang("1708419637"), GetLang("1708419698"), QMessageBox::Yes);
		qDebug() << QString::fromLocal8Bit("发布失败");
	}
	refreshTbProcess();
	tbProcess->selectRow(selRowIndexProcess);
}

AXEProcessData ProcessView::getPublishProcessModel()
{
	AXEProcessData processData;
	processData.processName = editProcessName->text();
	processData.stepCount = currProcessData.stepsList.count();
	processData.isPublish = false;
	processData.createDate = currProcessData.createDate;
	for (int i = 0; i < currProcessData.stepsList.count(); i++)
	{
		//流程信息
		AXEStepData currStepData = currProcessData.stepsList[i];
		AXEStepData stepData = AXEStepData(currStepData);
		//编号
		stepData.stepIndex = i + 1;
		int col = 0;
		//孔位
		QComboBox* cbSlotID = dynamic_cast<QComboBox*>(getWidgetTableItem(i, col++));
		stepData.column = cbSlotID->currentText().toInt();
		//步骤名称
		HLineEdit* editStepName = dynamic_cast<HLineEdit*>(getWidgetTableItem(i, col++));
		stepData.stepName = editStepName->text();
		//容量
		HLineEdit* editVolume = dynamic_cast<HLineEdit*>(getWidgetTableItem(i, col++));
		stepData.volume = editVolume->text().toInt();
		processData.stepsList.append(stepData);
	}
	processData.duration = processData.getEstimatedTime();
	return processData;
}

void ProcessView::loadProcess(QString _processName)
{
	currProcessData = AXEMgr::ins().getProcessByName(_processName);
	editProcessName->setText(_processName);
	refreshTbProcess();
}

void ProcessView::showEvent(QShowEvent * event)
{
	if (tbProcess != nullptr)
	{
		QStringList headerProcessDetail;
		headerProcessDetail
			<< GetLang("1708419680")	//序号
			<< GetLang("1708420088")	//孔位
			<< GetLang("1708420155")	//名称
			<< GetLang("1708420156")	//体系容量
			<< GetLang("1708420379")	//混合
										//<< GetLang("1708420091") + "(Sec)"	//混合时间
										//<< GetLang("1708420093") + "(PRM)"	//混合速度
										//<< GetLang("1708420334") + "(%)"	//混合振幅底部位置
										//<< GetLang("1708420335") + "(%)"	//混合振幅顶部位置
			<< GetLang("1708430054")	//吸磁
										//<< GetLang("1708420092") + "(Sec)"	//吸磁时间
										//<< GetLang("1708420332")	//吸磁速度
										//<< GetLang("1708420336") + "(%)"	//吸磁位置
			<< GetLang("1708430055")	//等待
										//<< GetLang("1708420090") + "(Sec)"	//等待时间
										//<< GetLang("1708420339")	//是否加热
			;
		tbModelProcess->setHorizontalHeaderLabels(headerProcessDetail);
		tbProcess->setModel(tbModelProcess);
		BasePageContent::showEvent(event);
	}
}

void ProcessView::slot_onclickBt(int index)
{
	switch (index)
	{
	case ProcessView::OpenProcess:
		openProcess();
		break;
	case ProcessView::NewProcess:
		newProcess();
		break;
	case ProcessView::NewStep:
		newStep();
		break;
	case ProcessView::DelStep:
		delStep();
		break;
	case ProcessView::Save:
		save();
		break;
	}
}

void ProcessView::slot_onTbProcessSelectRow(const QModelIndex &current, const QModelIndex &previous)
{
	selRowIndexProcess = current.row();
}