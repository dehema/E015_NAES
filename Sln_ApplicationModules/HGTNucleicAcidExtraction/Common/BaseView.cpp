#include "BaseView.h"

BaseView::BaseView(QWidget* _parent) :BaseWidget(_parent)
{
	this->setFixedSize(_parent->size());
}

int BaseView::getContentWidth()
{
	return size().width();
}