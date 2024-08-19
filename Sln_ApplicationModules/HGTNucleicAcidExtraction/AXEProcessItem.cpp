#include "AXEProcessItem.h"


AXEProcessItem::AXEProcessItem(QWidget *parent) :BaseView(parent)
{
	QVBoxLayout* mainLayout = getNewVBoxLayout(this);
	mainLayout->setSpacing(10);

	icon = new AXEProcessItem_Icon("img/testTube_blue.svg","img/testTube_white.svg");
	icon->setObjectName("AXEProcessItem_Icon");
	//int size = this->size().width()*0.6f;
	int size = this->size().width()*0.6f;
	icon->setCheckable(true);
	mainLayout->addWidget(icon, 0, Qt::AlignCenter);

	lb = getNewLbCommon();
	lb->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
	lb->setWordWrap(true);
	lb->setFixedHeight(35);
	mainLayout->addWidget(lb, 0, Qt::AlignCenter);
}

void AXEProcessItem::setText(QString str)
{
	lb->setText(str);
}

void AXEProcessItem::setFixedSize(int width, int height)
{
	BaseView::setFixedSize(width, height);
	int size = height - 45;
	icon->setFixedSize(QSize(size, size));
	icon->setIconSize(QSize(size, size));
	lb->setFixedWidth(width);
}