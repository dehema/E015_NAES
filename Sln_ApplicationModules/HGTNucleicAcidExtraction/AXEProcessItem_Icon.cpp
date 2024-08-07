#include "AXEProcessItem_Icon.h"

AXEProcessItem_Icon::AXEProcessItem_Icon(QString _normalIcon, QString _hoverIcon) :HButtonIcon(_normalIcon, _hoverIcon)
{

}


void AXEProcessItem_Icon::enterEvent(QEvent * event)
{
	this->showHoverIcon();
	QWidget::enterEvent(event);
}

void AXEProcessItem_Icon::leaveEvent(QEvent * event)
{
	if (this->isChecked())
	{
		this->showHoverIcon();
	}
	else
	{
		this->showNormalIcon();
	}
	QWidget::leaveEvent(event);
}

void AXEProcessItem_Icon::mouseReleaseEvent(QMouseEvent *event)
{
	HButtonIcon::mouseReleaseEvent(event);
	this->showHoverIcon();
}