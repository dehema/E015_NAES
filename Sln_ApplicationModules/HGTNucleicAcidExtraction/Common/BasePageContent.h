#pragma once
#include "Utility.h"
#include "BaseView.h"

class BasePageContent :public BaseView
{
public:
	BasePageContent(QWidget *parent);
	~BasePageContent() {};

	void translate() override;
};