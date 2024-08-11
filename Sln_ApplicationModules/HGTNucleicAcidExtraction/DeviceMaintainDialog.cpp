#include "DeviceMaintainDialog.h"

DeviceMaintainDialog::DeviceMaintainDialog(QWidget* _parent, DeviceControlService deviceHandle)
	: BaseDialog(_parent), deviceHandle(Utility::ins().deviceHandle)
{
	setTitle(GetLang("1708419564"));
	setSize(WIN_WIDTH, WIN_HEIGHT);

	if (deviceHandle.axeService != nullptr)
	{
	}
	else {
		Log("没有连接上核酸提取仪");
	}


	bgMenu = new QButtonGroup(this);
	connect(bgMenu, SIGNAL(buttonClicked(int)), this, SLOT(slot_onclickBgMenu(int)));

	layoutMain = getNewHBoxLayout(widgetBaseContent);
	layoutMain->setAlignment(Qt::AlignCenter);
	layoutMain->setSpacing(5);

	//菜单
	widgetMenu = getNewWidgetCommon();
	widgetMenu->setFixedSize(UI_Bt_Width, getBaseContentHeight());
	layoutMain->addWidget(widgetMenu);

	layoutMenu = getNewVBoxLayout(widgetMenu);
	layoutMenu->setAlignment(Qt::AlignCenter);
	layoutMenu->setSpacing(30);

	QPushButton* btPageEle = getNewBtCommon("1708420257");
	btPageEle->setCheckable(true);
	layoutMenu->addWidget(btPageEle);
	bgMenu->addButton(btPageEle, AXEPageGroup::Axe_Ele);

	QPushButton* btPageTemp = getNewBtCommon("1708420200");
	btPageTemp->setCheckable(true);
	layoutMenu->addWidget(btPageTemp);
	bgMenu->addButton(btPageTemp, AXEPageGroup::Axe_Temp);

	QPushButton* btPageTempRealTimeTemp = getNewBtCommon("1708420985");
	btPageTempRealTimeTemp->setCheckable(true);
	layoutMenu->addWidget(btPageTempRealTimeTemp);
	bgMenu->addButton(btPageTempRealTimeTemp, AXEPageGroup::Axe_RealTimeTemp);

	QPushButton* btPageEquip = getNewBtCommon("1708420258");
	btPageEquip->setCheckable(true);
	layoutMenu->addWidget(btPageEquip);
	bgMenu->addButton(btPageEquip, AXEPageGroup::Axe_Equip);

	QPushButton* btPageSetting = getNewBtCommon("1708420259");
	btPageSetting->setCheckable(true);
	layoutMenu->addWidget(btPageSetting);
	bgMenu->addButton(btPageSetting, AXEPageGroup::Axe_Setting);

	QPushButton* btPageProcess = getNewBtCommon("1708420174");
	btPageProcess->setCheckable(true);
	layoutMenu->addWidget(btPageProcess);
	bgMenu->addButton(btPageProcess, AXEPageGroup::Axe_Process);

	QPushButton* btPageStatus = getNewBtCommon("1708419973");
	btPageStatus->setCheckable(true);
	layoutMenu->addWidget(btPageStatus);
	bgMenu->addButton(btPageStatus, AXEPageGroup::Axe_Status);

	//分割线
	QFrame* splitLine = getNewFrame();
	splitLine->setFixedSize(1, 450);
	splitLine->setStyleSheet("border:1px solid rgb(41, 141, 255);");
	layoutMain->addWidget(splitLine);

	//内容页
	widgetPage = getNewWidgetCommon();
	widgetPage->setFixedSize(getBaseContentWidth() - widgetMenu->width() - 50, getBaseContentHeight());
	layoutMain->addWidget(widgetPage);

	bgMenu->buttons()[0]->click();
}

void DeviceMaintainDialog::slot_onclickBgMenu(int _index)
{

	if (currPage != nullptr)
		currPage->hide();
	switch (_index)
	{
	case AXEPageGroup::Axe_Ele:
	{
		if (widgetEle == nullptr)
			widgetEle = new DeviceMaintainPage_Axe_Ele(widgetPage, deviceHandle);
		currPage = widgetEle;
		break;
	}
	case AXEPageGroup::Axe_Temp:
	{
		if (widgetTemp == nullptr)
			widgetTemp = new DeviceMaintainPage_Axe_Temp(widgetPage, deviceHandle);
		currPage = widgetTemp;
		break;
	}
	case AXEPageGroup::Axe_RealTimeTemp:
	{
		if (widgetRealTimeTemp == nullptr)
			widgetRealTimeTemp = new DeviceMaintainPage_Axe_RealTimeTemp(widgetPage, deviceHandle);
		currPage = widgetRealTimeTemp;
		break;
	}
	case AXEPageGroup::Axe_Equip:
	{
		if (widgetEquip == nullptr)
			widgetEquip = new DeviceMaintainPage_Axe_Equip(widgetPage, deviceHandle);
		currPage = widgetEquip;
		break;
	}
	case AXEPageGroup::Axe_Setting:
	{
		if (widgetSetting == nullptr)
			widgetSetting = new  DeviceMaintainPage_Axe_Setting(widgetPage, deviceHandle);
		currPage = widgetSetting;
		break;
	}
	case AXEPageGroup::Axe_Process:
	{
		if (widgetProcess == nullptr)
			widgetProcess = new DeviceMaintainPage_Axe_Process(widgetPage, deviceHandle);
		currPage = widgetProcess;
		break;
	}
	case AXEPageGroup::Axe_Status:
	{
		if (widgetStatus == nullptr)
			widgetStatus = new DeviceMaintainPage_Axe_Status(widgetPage, deviceHandle);
		currPage = widgetStatus;
		break;
	}
	}
	currPage->show();
}
