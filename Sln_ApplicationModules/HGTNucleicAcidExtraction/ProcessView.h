#pragma once
#include "Common/UIUtility.h"
#include "Common/BasePageContent.h"
#include "AXEMgr.h"
#include "ProcessParamsDialog.h"
#include "ChooseItemListDialog.h"

class ProcessView : public BasePageContent
{
	Q_OBJECT
private:
	enum BtType {
		OpenProcess,
		NewProcess,
		ImportProcess,
		DelProcess,
		NewStep,
		DelStep,
		Save,
	};

public:
	ProcessView(QWidget *parent);
	~ProcessView() {};

	//--------------------UI--------------------
	QVBoxLayout* layoutMain;
	HLineEdit* editProcessName;

	HTableView* tbProcess;
	QStandardItemModel* tmProcess;
	QItemSelectionModel* selectionModelProcess;
	int processDetailItemWidth;
	//--------------------field--------------------
	QButtonGroup* btGroup;
	//最大步骤数量
	const int stepCountMax = 10;
	//选中行
	int selRowIndexProcess;
	//所有表格组件
	QList<QList<QWidget*>> widgetTableItems;
	//当前选中流程
	AXEProcessData currProcessData;
	AXEParamsLimit paramsLimit = AXEMgr::ins().axeParamsLimit;
	//--------------------function--------------------
	void refreshTbProcess();
	QWidget* getWidgetTableItem(int _rowIndex, int _colIndex);
	void addRowTbProcess(int _row, AXEStepData _data);
	void fillWidgetTableItems();
	void setWidgetTableItemVisible(int _row, bool _visible);
	bool isLegalSelRowIndexProcess();
	AXEProcessData getSaveProcessModel();
	void loadProcess(QString _processName);
	void initTbProcess();
	void clearTbProcess();
	void delAllWidgetTableItems();
	void showEvent(QShowEvent *event) override;

	void openProcess();
	void importProcess();
	void newProcess();
	void newStep();
	void delStep();
	void save();
	void delProcess();

	public slots:
	void slot_onclickBt(int);
	void slot_onTbProcessSelectRow(const QModelIndex&, const QModelIndex&);
};

