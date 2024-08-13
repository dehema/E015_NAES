#pragma once
#include "Common/BasePageContent.h"
#include "AXEMgr.h"
#include "AXEProcessItem.h"
#include "AxeRuningView.h"

class PlayView : public BasePageContent
{
	Q_OBJECT

private:
	enum BtType {
		Launch,
		Preview,
		GridMode,
		ListMode,
	};
public:
	PlayView(QWidget* parent);
	~PlayView() {};

	//--------------------UI--------------------
	QVBoxLayout* layoutMain;
	//网格
	QWidget* widgetGrid;
	QGridLayout* gridProcess;
	QScrollArea* scrollProcess;
	//列表
	HTableView* tbProcess;
	HTableViewItemModel* tmProcess;

	//表格模式
	QPushButton* btGridMode;
	QWidget* widgetGridParent;
	//列表模式
	QPushButton* btListModel;

	//--------------------field--------------------
	QList<AXEProcessData> processList;
	QList<AXEProcessItem*> processItemList;
	QButtonGroup* btGroup;
	QButtonGroup* processIconGroup;
	int gridSpacing;
	//选择的流程
	AXEProcessData selProcessData;
	//--------------------function--------------------
	//初始化网格模式
	void showGridProcess();
	//初始化列表模式
	void showTbProcess();

	public slots:
	void slot_onclickBt(int);
	void slot_onclickProcessIcon(int);
signals:
	void signal_previewProcess(QString _name);
	void signal_runProcess(QString _name);
};

