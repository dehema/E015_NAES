#pragma once
#include "PopDialog.h"
#include "BaseUI.h"
#include "IBaseView.h"

class BaseDialog :public QDialog, public BaseUI, public IBaseView
{
	Q_OBJECT
public:
	BaseDialog(QWidget* parent);
	~BaseDialog() {};
	//----------------------UI----------------------
	QPushButton* btBaseClose = nullptr;

	//function
	virtual void setSize(float _width, float _height);
	void setTitle(QString str);

	//窗口宽度
	int baseDialogWidth = WIN_WIDTH;
	//窗口高度
	int baseDialogHeight = WIN_HEIGHT;
	//标头高度
	const int widgetBaseTitleHeight = 45;
	float getBaseContentWidth() { return baseDialogWidth; }
	float getBaseContentHeight() { return baseDialogHeight - widgetBaseTitleHeight; }
	void resize();
	void setDialogCenter();
	virtual void closeDialog();
	private slots:
	void slot_onclickClose();

private:
	QWidget* widgetBaseTitle = nullptr;
	QHBoxLayout* layoutBaseTitle = nullptr;
	QLabel* lbBaseTitle = nullptr;
	QWidget* widgetBaseMain = nullptr;
	QWidget* widgetBaseContentBg = nullptr;
};

