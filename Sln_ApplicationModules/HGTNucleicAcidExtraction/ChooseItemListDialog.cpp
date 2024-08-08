#include "ChooseItemListDialog.h"


ChooseItemListDialog::ChooseItemListDialog(QWidget* _parent, QList<QString> _strList, QString _emptyTips) :BaseDialog(_parent),
strList(_strList)
{
	setSize(350, 450);

	layoutMain = getNewVBoxLayout(widgetBaseContent);
	layoutMain->setAlignment(Qt::AlignCenter);
	layoutMain->setSpacing(10);
	layoutMain->setContentsMargins(0, 0, 0, 10);

	widgetScrollArea = new QWidget(widgetBaseContent);
	widgetScrollArea->setFixedSize(getBaseContentWidth(), getBaseContentHeight());
	layoutMain->addWidget(widgetScrollArea);

	scrollArea = new QScrollArea(widgetScrollArea);
	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
	scrollArea->setContentsMargins(0, 0, 0, 0);
	scrollArea->setFixedSize(getBaseContentWidth(), getBaseContentHeight());

	widgetPage = new QWidget(scrollArea);
	widgetPage->setFixedSize(getBaseContentWidth(), getBaseContentHeight());
	widgetPage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	widgetPage->move(0, 0);
	scrollArea->setWidget(widgetPage);

	layoutItemIDs = getNewVBoxLayout(widgetPage);
	layoutItemIDs->setAlignment(Qt::AlignCenter);
	layoutItemIDs->setSpacing(10);
	layoutItemIDs->setContentsMargins(0, 0, 0, 0);

	buttonGroup = new QButtonGroup();
	connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(slot_onclickButtonGroup(int)));
	for (int i = 0; i < strList.count(); i++)
	{
		QPushButton* bt = getNewBtCommon();
		bt->setText(strList[i]);
		bt->setFixedWidth(200);
		layoutItemIDs->addWidget(bt);
		buttonGroup->addButton(bt, buttonGroup->buttons().count());
	}
	if (strList.count() == 0 && _emptyTips != nullptr)
	{
		QPushButton* bt = getNewBtCommon();
		bt->setText(_emptyTips);
		layoutItemIDs->addWidget(bt);
		buttonGroup->addButton(bt, -1);
	}

	int contentHeight = qMax((int)getBaseContentHeight() - 10,
		(UI_Bt_Height + layoutItemIDs->spacing()) * buttonGroup->buttons().count());
	widgetPage->setFixedHeight(contentHeight);
}

int ChooseItemListDialog::exec()
{
	int res = QDialog::exec();
	return clickIndex;
}

void ChooseItemListDialog::setSize(float _width, float _height)
{
	BaseDialog::setSize(_width, _height);
	//for (QAbstractButton* _bt : buttonGroup->buttons())
	//{
	//	_bt->setFixedSize(getBaseContentWidth() - 150, 35);
	//}

	//widgetScrollArea->setFixedSize(getBaseContentWidth(), getBaseContentHeight());
	//scrollArea->setFixedSize(getBaseContentWidth(), getBaseContentHeight());
}

void ChooseItemListDialog::slot_onclickButtonGroup(int _index)
{
	clickIndex = _index;
	close();
}