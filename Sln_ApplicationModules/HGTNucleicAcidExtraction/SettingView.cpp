#include "SettingView.h"


SettingView::SettingView(QWidget *parent) :BasePageContent(parent)
{
	btGroup = new QButtonGroup(this);
	connect(btGroup, SIGNAL(buttonClicked(int)), this, SLOT(slot_onclickBt(int)));

	//UI
	layoutMain = getNewGridLayout(this);
	layoutMain->setContentsMargins(Page_Dialog_Padding_Left, Page_Dialog_Padding_Top, Page_Dialog_Padding_Right, Page_Dialog_Padding_Bottom);
	layoutMain->setSpacing(15);
	layoutMain->setAlignment(Qt::AlignCenter);

	QLabel* lbLang = getNewLbCommon("1708420955");
	lbLang->setFixedSize(UI_Bt_Width, UI_Bt_Height);
	lbLang->setAlignment(Qt::AlignCenter);
	layoutMain->addWidget(lbLang, 0, 0);

	cbLang = getNewComboxBox();
	cbLang->addItem(QString::fromLocal8Bit("ÖÐÎÄ"));
	cbLang->addItem("en");
	connect(cbLang, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_onLangIndexChange(int)));
	layoutMain->addWidget(cbLang, 0, 1);

	QPushButton* btDeviceMaintain = getNewBtCommon("1708419564");
	btGroup->addButton(btDeviceMaintain, DeviceMaintain);
	layoutMain->addWidget(btDeviceMaintain, 1, 0, 1, 2, Qt::AlignCenter);
}

void SettingView::slot_onclickBt(int _index)
{
	switch (_index)
	{
	case SettingView::DeviceMaintain:
		DeviceMaintainDialog* dialog = new DeviceMaintainDialog(this, Utility::ins().deviceHandle);
		dialog->exec();
		break;
	}
}

void SettingView::slot_onLangIndexChange(int _index)
{
	Utility::ins().loadLangFile(_index);
}