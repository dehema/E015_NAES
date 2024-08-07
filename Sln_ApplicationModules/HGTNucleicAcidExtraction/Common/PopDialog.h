#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QDialog>

#include "Utility.h"
class PopDialog :public QDialog
{
public:
	PopDialog(QWidget *parent = nullptr);
	~PopDialog();

	void SetContent(QWidget* &content, QString title);

private:
	//ui
	QWidget * widgetTitle;
	QLabel* lbTitle;
	//data
	const int titleHeight = 40;
};

