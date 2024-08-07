#include "PopDialog.h"

PopDialog::PopDialog(QWidget *parent) :QDialog(parent)
{
	this->move(0, 0);
	this->setFixedSize(WIN_WIDTH, WIN_HEIGHT);
	this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	QWidget* bg = new QWidget(this);
	bg->setStyleSheet("background-color:rgba(0,0,0,0.5);");
	bg->move(0, 0);
	bg->setFixedSize(WIN_WIDTH, WIN_HEIGHT);
	//±êÌâÀ¸
	widgetTitle = new QWidget(this);
	lbTitle = new QLabel(widgetTitle);
	QLabel* lbTips = new QLabel(this);
}

void PopDialog::SetContent(QWidget* &content, QString title)
{
	lbTitle->setText(title);
	content->setParent(this);
	int height = titleHeight + content->height();
	int startPosX = (WIN_WIDTH - content->width()) / 2;
	int startPosY = WIN_HEIGHT / 2 - height / 2;
	widgetTitle->move(startPosX, startPosY);
	content->move(startPosX, startPosY + titleHeight);


	this->exec();
}

PopDialog::~PopDialog()
{

}
