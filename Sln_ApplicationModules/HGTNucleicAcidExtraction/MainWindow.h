#pragma once
#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>
#include <QtCore/QMetaType>
#include "Common/UIUtility.h"
#include "Common/BaseUI.h"
#include "PlayView.h"
#include "ProcessView.h"
#include "UVView.h"
#include "SettingView.h"

class MainWindow :public QDialog, public BaseUI
{
	Q_OBJECT
private:
	enum BtType {
		Play,
		Process,
		UV,
		Setting,
	};
	enum PageType
	{
		PagePlay,
		PageProcess,
		PageUV,
		PageSetting,
	};
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow() {};

	//-----------------------UI-----------------------
	QWidget* widgetMenu;
	HButtonIcon* btPlay;
	HButtonIcon* btProcess;
	HButtonIcon* btUV;
	HButtonIcon* btSetting;
	QWidget* widgetPageParent;
	QWidget* widgetPage;

	//-----------------------field-----------------------
	PageType currPageType = PageType::PageSetting;
	QButtonGroup* bgMenu;
	//运行界面
	AXERuningView* axeRuningView;
	PlayView* playView;
	ProcessView* processView;
	UVView* uvView;
	SettingView* settingView;

	AxeThread* axeThread;
	//-----------------------function-----------------------
	HButtonIcon* getBtMenu(QString _normalIcon, QString _hoverIcon);
	void showPage(PageType _pageType);
	int getAxeComPort();
	bool initAxeService(IFAXEService *&axeService);

	private slots:
	void slot_onclickBt(int);
	void slot_previewProcess(QString);
	void slot_runProcess(QString);
	void slot_onAxeProcessFinish();
};

