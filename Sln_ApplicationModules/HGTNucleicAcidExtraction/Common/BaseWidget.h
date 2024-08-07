#pragma once
#include "BaseUI.h"
#include "IBaseView.h"

class BaseWidget : public QWidget, public BaseUI, public IBaseView
{
public:
	BaseWidget(QWidget* _parent);
	~BaseWidget() {};

	virtual void translate();
	void setVisible(bool) override;
	LangType langType;

protected:
	virtual void showEvent(QShowEvent *event) override;
};

