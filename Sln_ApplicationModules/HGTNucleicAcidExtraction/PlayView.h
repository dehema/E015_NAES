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
	//����
	QWidget* widgetGrid;
	QGridLayout* gridProcess;
	QScrollArea* scrollProcess;
	//�б�
	HTableView* tbProcess;
	HTableViewItemModel* tmProcess;

	//���ģʽ
	QPushButton* btGridMode;
	QWidget* widgetGridParent;
	//�б�ģʽ
	QPushButton* btListModel;

	//--------------------field--------------------
	QList<AXEProcessData> processList;
	QList<AXEProcessItem*> processItemList;
	QButtonGroup* btGroup;
	QButtonGroup* processIconGroup;
	int gridSpacing;
	//ѡ�������
	AXEProcessData selProcessData;
	//--------------------function--------------------
	//��ʼ������ģʽ
	void showGridProcess();
	//��ʼ���б�ģʽ
	void showTbProcess();

	public slots:
	void slot_onclickBt(int);
	void slot_onclickProcessIcon(int);
signals:
	void signal_previewProcess(QString _name);
	void signal_runProcess(QString _name);
};

