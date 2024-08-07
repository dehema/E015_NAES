#include "MainWindow.h"

#include <QtGui/QPixmap>

MainWindow::MainWindow(QWidget *parent) : BaseUI()
{
	UIUtility::ins().mainWindow = this;
	this->setStyleSheet(Utility::loadStyleFile());
	resize(WIN_WIDTH, WIN_HEIGHT);
	bgMenu = new QButtonGroup(this);
	connect(bgMenu, SIGNAL(buttonClicked(int)), this, SLOT(slot_onclickBt(int)));

	widgetMenu = getNewWidgetCommon(this);
	widgetMenu->setObjectName("widgetMenu_mainWindow");
	widgetMenu->setFixedSize(size().width(), size().height()* 0.1);
	//widgetMenu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	widgetMenu->move(0, 0);
	QHBoxLayout* layoutMenu = getNewHBoxLayout(widgetMenu);
	layoutMenu->setSpacing(widgetMenu->size().width()*0.05);

	//logo
	QLabel* lb = getNewLbCommon();
	lb->setFixedSize(widgetMenu->size().width()*0.2, widgetMenu->size().height());
	QImage* img = new QImage;
	img->load("img/logo_full_w.png");
	QImage imgScaled = img->scaled(lb->width() - 20, lb->height() - 20, Qt::KeepAspectRatio);
	layoutMenu->addWidget(lb);
	lb->setPixmap(QPixmap::fromImage(imgScaled));
	lb->setAlignment(Qt::AlignCenter);

	btPlay = getBtMenu("img/play_white.svg", "img/play_blue.svg");
	bgMenu->addButton(btPlay, PageType::PagePlay);
	layoutMenu->addWidget(btPlay);

	btProcess = getBtMenu("img/process_white.svg", "img/process_blue.svg");
	bgMenu->addButton(btProcess, PageType::PageProcess);
	layoutMenu->addWidget(btProcess);

	btUV = getBtMenu("img/uv_white.svg", "img/uv_blue.svg");
	bgMenu->addButton(btUV, PageType::PageUV);
	layoutMenu->addWidget(btUV);

	btSetting = getBtMenu("img/setting_white.svg", "img/setting_blue.svg");
	bgMenu->addButton(btSetting, PageType::PageSetting);
	layoutMenu->addWidget(btSetting);

	widgetPageParent = getNewWidgetCommon(this);
	widgetPageParent->setFixedSize(size().width(), size().height() - widgetMenu->height());
	widgetPageParent->move(0, widgetMenu->height());
	widgetPageParent->show();

	btPlay->click();
}

HButtonIcon* MainWindow::getBtMenu(QString _normalIcon, QString _hoverIcon)
{
	HButtonIcon *bt = new HButtonIcon(_normalIcon, _hoverIcon);
	bt->setObjectName("bt_page_mainwindow");
	bt->setCheckable(true);
	bt->setFixedSize(widgetMenu->size().width()*0.15, widgetMenu->size().height());
	bt->setIconSize(bt->size() - QSize(5, 5));
	return bt;
}

void MainWindow::slot_onclickBt(int _index)
{
	BtType _btType = (BtType)_index;
	switch (_btType)
	{
	case BtType::Play:
		showPage(PageType::PagePlay);
		break;
	case BtType::Process:
		showPage(PageType::PageProcess);
		break;
	case BtType::UV:
		showPage(PageType::PageUV);
		break;
	case BtType::Setting:
		showPage(PageType::PageSetting);
		break;
	}
}


void MainWindow::showPage(PageType _pageType)
{
	if (currPageType == _pageType)
		return;
	btPlay->showNormalIcon();
	btProcess->showNormalIcon();
	btUV->showNormalIcon();
	btSetting->showNormalIcon();

	currPageType = _pageType;
	if (widgetPage != nullptr)
		widgetPage->hide();
	switch (_pageType)
	{
	case PageType::PagePlay:
	{
		btPlay->showHoverIcon();
		if (playView == nullptr)
			playView = new PlayView(widgetPageParent);
		widgetPage = playView;
		break;
	}
	case PageType::PageProcess:
	{
		btProcess->showHoverIcon();
		if (processView == nullptr)
			processView = new ProcessView(widgetPageParent);
		widgetPage = processView;
		break;
	}
	case PageType::PageUV:
	{
		btUV->showHoverIcon();
		if (uvView == nullptr)
			uvView = new UVView(widgetPageParent);
		widgetPage = uvView;
		break;
	}
	case PageType::PageSetting:
	{
		btSetting->showHoverIcon();
		if (settingView == nullptr)
			settingView = new SettingView(widgetPageParent);
		widgetPage = settingView;
		break;
	}
	}

	if (widgetPage != nullptr)
	{
		widgetPage->move(0, 0);
		widgetPage->show();
	}

	//Log(widgetPageParent->size().width());
	//Log(widgetPageParent->size().height());
	//Log(widgetPageParent->isVisible() ? "show" : "hide");
	//Log(widgetPage->isVisible() ? "show" : "hide");
}