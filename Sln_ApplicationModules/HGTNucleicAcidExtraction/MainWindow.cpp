#include "MainWindow.h"
#include <QtGui/QPixmap>
#include "AxeThread.h"

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
	layoutMenu->setContentsMargins(0, 0, 20, 0);

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

	btPrePare = getBtMenu("img/prepare_white.svg", "img/prepare_blue.svg");
	bgMenu->addButton(btPrePare, PageType::PagePrepare);
	layoutMenu->addWidget(btPrePare);

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
	initAxeService(Utility::ins().deviceHandle.axeService);

	//核提线程
	axeThread = new AxeThread();
	Utility::ins().axeThread = axeThread;
	axeThread->start();
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

void MainWindow::showPage(PageType _pageType)
{
	if (currPageType == _pageType)
		return;
	btPlay->showNormalIcon();
	btPrePare->showNormalIcon();
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
		if (axeThread != nullptr&& axeThread->isLaunch())
		{
			widgetPage = axeRuningView;
		}
		else
		{
			if (playView == nullptr)
			{
				playView = new PlayView(widgetPageParent);
				connect(playView, SIGNAL(signal_previewProcess(QString)), this, SLOT(slot_previewProcess(QString)));
				connect(playView, SIGNAL(signal_runProcess(QString)), this, SLOT(slot_runProcess(QString)));
			}
			widgetPage = playView;
		}
		break;
	}
	case PageType::PagePrepare:
	{
		btPrePare->showHoverIcon();
		if (prepareView == nullptr)
		{
			prepareView = new PrepareView(widgetPageParent);
		}
		widgetPage = prepareView;
		break;
	}
	case PageType::PageProcess:
	{
		btProcess->showHoverIcon();
		if (processView == nullptr)
		{
			processView = new ProcessView(widgetPageParent);
		}
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

int MainWindow::getAxeComPort()
{
	int nComPort = 0;
	QString configFile = QCoreApplication::applicationDirPath() + "/data/CommonParam.ini";
	if (!QFile::exists(configFile))
	{
		Log("没有找到commonParam" + configFile);
		return false;
	}

	QSettings *setting = new QSettings(configFile, QSettings::IniFormat);
	setting->setIniCodec("UTF-8");
	nComPort = setting->value("/CommonParam/AxePort", 1).toInt();
	Log(QString::fromLocal8Bit("核酸提取仪端口") + QString::number(nComPort));
	delete setting;
	return nComPort;
}

bool MainWindow::initAxeService(IFAXEService *&axeService)
{
	int errorno = 0;

	int nPort = getAxeComPort();
	axeService = getAXEService(nullptr, nPort);

	if (axeService == nullptr)
	{
		Log("initAxeService failed. errno=" + errorno);
		return false;
	}

	axeService->start();
	axeService->enable();
	return true;
}

void MainWindow::slot_onclickBt(int _index)
{
	BtType _btType = (BtType)_index;
	switch (_btType)
	{
	case BtType::Play:
		showPage(PageType::PagePlay);
		break;
	case BtType::Prepare:
		showPage(PageType::PagePrepare);
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

void MainWindow::slot_previewProcess(QString _processName)
{
	btProcess->click();
	processView->loadProcess(_processName);
}

void MainWindow::slot_runProcess(QString _processName)
{
	widgetPage->hide();
	AXEProcessData processData = AXEMgr::ins().getProcessByName(_processName);
	if (axeRuningView == nullptr)
	{
		axeRuningView = new AXERuningView(widgetPageParent);
		axeRuningView->move(0, 0);
		axeRuningView->setFixedSize(widgetPageParent->width(), widgetPageParent->height());
		connect(axeRuningView, SIGNAL(signal_closeRuningView()), this, SLOT(slot_onAxeProcessFinish()));
	}
	axeRuningView->show();
	axeRuningView->launchProcess(processData);
	widgetPage = axeRuningView;
}

void MainWindow::slot_onAxeProcessFinish()
{
	widgetPage->hide();
	btPlay->click();
	btPlay->showHoverIcon();
	widgetPage = playView;
	playView->show();
}