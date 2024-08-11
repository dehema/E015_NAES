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
	QStandardItemModel* tbModelProcess;
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
	//表格格子宽度
	int processItemWidth;
	//当前选中流程
	AXEProcessData currProcessData;
	//--------------------function--------------------
	void refreshTbProcess();
	QWidget* getWidgetTableItem(int _rowIndex, int _colIndex);
	void addRowTbProcess(int _row, AXEStepData _data);
	void fillWidgetTableItems();
	void setWidgetTableItemVisible(int _row, bool _visible);
	bool isLegalSelRowIndexProcess();
	AXEProcessData getPublishProcessModel();
	QString getMixBtStr(AXEStepData _data);
	QString getMagnetBtStr(AXEStepData _data);
	QString getWaitBtStr(AXEStepData _data);
	void showEvent(QShowEvent *event) override;

	void openProcess();
	void newProcess();
	void newStep();
	void delStep();
	void save();

	public slots:
	void slot_onclickBt(int);
	void slot_onTbProcessSelectRow(const QModelIndex&, const QModelIndex&);
};

