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
	//���������
	const int stepCountMax = 10;
	//ѡ����
	int selRowIndexProcess;
	//���б�����
	QList<QList<QWidget*>> widgetTableItems;
	//�����ӿ��
	int processItemWidth;
	//��ǰѡ������
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

