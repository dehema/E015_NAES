#include "BaseDialog.h"

BaseDialog::BaseDialog(QWidget* parent) : QDialog(parent)
{
	this->setStyleSheet(Utility::loadStyleFile());

	//this->setWindowModality(Qt::WindowModal);
	//this->setFocus();
	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

	widgetBaseMain = new QWidget(this);
	widgetBaseMain->setObjectName("widget_baseDialog_main");
	widgetBaseMain->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	widgetBaseMain->setContentsMargins(0, 0, 0, 0);

	//widgetTitle
	widgetBaseTitle = new QWidget(widgetBaseMain);
	widgetBaseTitle->setObjectName("widget_baseDialog_title");
	widgetBaseTitle->setFixedHeight(widgetBaseTitleHeight);

	//layoutTitle
	layoutBaseTitle = getNewHBoxLayout(widgetBaseTitle);
	layoutBaseTitle->setContentsMargins(5, 0, 5, 0);
	layoutBaseTitle->setSpacing(0);
	layoutBaseTitle->addSpacerItem(new QSpacerItem(37, 45, QSizePolicy::Expanding));

	//lbTitle
	lbBaseTitle = getNewLbTitle();
	lbBaseTitle->setObjectName("label_title");
	layoutBaseTitle->addWidget(lbBaseTitle);

	//btClose
	btBaseClose = getNewBtCommon();
	btBaseClose->setObjectName("bt_common_close");
	btBaseClose->setFixedSize(32, 32);
	connect(btBaseClose, SIGNAL(clicked()), this, SLOT(slot_onclickClose()));
	layoutBaseTitle->addWidget(btBaseClose);

	widgetBaseContentBg = new QWidget(widgetBaseMain);
	widgetBaseContentBg->move(0, widgetBaseTitleHeight);
	widgetBaseContentBg->setObjectName("widget_baseDialog_contentBg");
	widgetBaseContentBg->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

	//ÄÚÈÝ
	widgetBaseContent = new QWidget(widgetBaseMain);
	widgetBaseContent->move(0, widgetBaseTitleHeight);
	widgetBaseContent->setObjectName("widget_baseDialog_content");
	widgetBaseContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

	setFixedSize(WIN_WIDTH, WIN_FULLHEIGHT);
	//QDesktopWidget *desktop = QApplication::desktop();
	//setGeometry(desktop->screenGeometry(1));
}

void BaseDialog::setSize(float _width, float _height)
{
	baseDialogWidth = _width;
	baseDialogHeight = _height;
	resize();
	setDialogCenter();
}

void BaseDialog::resize()
{
	setFixedSize(baseDialogWidth, baseDialogHeight);
	widgetBaseMain->setFixedSize(baseDialogWidth, baseDialogHeight);
	widgetBaseTitle->setFixedSize(baseDialogWidth, widgetBaseTitleHeight);
	lbBaseTitle->setFixedSize(baseDialogWidth, widgetBaseTitleHeight);
	widgetBaseContent->setFixedSize(baseDialogWidth - 2, baseDialogHeight - widgetBaseTitleHeight - 2);
	widgetBaseContentBg->setFixedSize(baseDialogWidth, baseDialogHeight - widgetBaseTitleHeight);
}

void BaseDialog::setDialogCenter()
{
	int posX = (WIN_WIDTH - baseDialogWidth) / 2;
	int posY = (WIN_HEIGHT - baseDialogHeight) / 2;
	move(posX, posY);
}

void BaseDialog::setTitle(QString str)
{
	lbBaseTitle->setText(str);
}

void BaseDialog::closeDialog()
{
	close();
}

void BaseDialog::slot_onclickClose()
{
	closeDialog();
}
