#include "BaseWidget.h"

BaseWidget::BaseWidget(QWidget* _parent) :QWidget(_parent)
{
	setParent(_parent);
}

void BaseWidget::setVisible(bool _visible)
{
	QWidget::setVisible(_visible);
	if (_visible)
	{
		if (langType != Utility::ins().langType)
		{
			translate();
		}
	}
}

void BaseWidget::showEvent(QShowEvent * event)
{
	QWidget::showEvent(event);
}

void BaseWidget::translate()
{
	if (langType != Utility::ins().langType)
	{
		langType = Utility::ins().langType;
	}
	BaseUI::translate();
}