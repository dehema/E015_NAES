#include "BasePageContent.h"

BasePageContent::BasePageContent(QWidget *parent) : BaseView(parent)
{
	this->move(0, 0);
	this->setContentsMargins(0, 0, 0, 0);
}

void BasePageContent::translate()
{
	BaseView::translate();
}