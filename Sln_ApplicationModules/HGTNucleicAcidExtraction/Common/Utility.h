#pragma once
#include <QtWidgets/QApplication>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QInputDialog>
#include <QtCore/QString>
#include <QtCore/QVector>
#include <QtCore/QMap>
#include <QtCore/QDebug>
#include <QtCore/QFile>
#include <QtCore/QJsonValue>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonDocument>
#include <QtCore/QCoreApplication>
#include <QtCore/QString>
#include <QtCore/QList>
#include <QtCore/QFileInfo>
#include <QtCore/QSettings>
#include <QtCore/QTime>
#include <QtCore/QTimer>
#include <QtCore/QtMath>
#include "Singleton.h"
#include "ConnectDatabase.h"
#include "GlobalDefine.h"
#include <iostream>

//屏幕高度
#define WIN_FULLHEIGHT 600

#define WIN_WIDTH 1024
#define WIN_HEIGHT 570

//内容页宽度
#define ContentPage_WIDTH 1024
#define ContentPage_HEIGHT 513

//内边距
#define Page_Dialog_Padding_Top 15
#define Page_Dialog_Padding_Bottom 15
#define Page_Dialog_Padding_Left 15
#define Page_Dialog_Padding_Right 15

#define UI_FONT_SIZE_COMMON 16
#define UI_FONT_SIZE_TITLE 20
#define UI_FONT_Family "宋体"

#define UI_Bt_Width 120
#define UI_Bt_Height 35

#define UI_Bt_Width_Large 160
#define UI_Bt_Height_Large 50

#define UI_CheckBox_Width 200
#define UI_CheckBox_Height 35

#define UI_ComboBox_Height 35

#define UI_TableView_RowHeight 35

#define UI_LineEdit_Width 200
#define UI_LineEdit_Height 35
//间隔
#define UI_Layout_Spacing 20

#define GetLang(langID) Utility::ins().getLang(langID)
#define Log(str) Utility::ins().log(str)

using namespace std;

class Utility :public Singleton<Utility>
{
public:
	//弹窗窗口宽度
	static const int DialogDefaultWidth = 800;

	static void log(const char *str)
	{
		qDebug() << QString::fromLocal8Bit(str);
	}

	static void log(QString str)
	{
		qDebug() << str;
	}
	static void log(int str)
	{
		qDebug() << QString::number(str);
	}
	static void log(string str)
	{
		cout << str << endl;
	}
	//倒计时文本化
	QString secondToString(int _second);
	QString secondToMinute(int _second);

	static QString loadStyleFile();

	//多语言
	LangType langType;
	QMap<QString, QString> langDict;
	void loadLangFile(int);
	QString getLang(QString _id);
	QString getLang(const char* _id);
	// 判断 UTF-8 编码的字符是否是中文
	bool isChineseUTF8(const char* str);

	//正则表达式
	const QRegExp *RegExpNumber = new QRegExp("\\d+");
	const QRegExp *RegExpLetterNumber = new QRegExp("[A-Za-z0-9]+");
	const QRegExp *RegExpChinese = new QRegExp("^[\u4E00-\u9FA5]+$");

	//key
	bool isShift = false;

	//---------------流程图---------------
	QMap<QString, QString> getDiagramFuncNames();
	bool getFuncTrue();

	static QDate stringToDate(QString str);
	static QString dateToString(QDate _date);


	//---------------核提仪---------------
	AXEModuleStatus axeStatus;

	//设备句柄
	DeviceControlService deviceHandle;

	QThread* axeThread;
};

//QSize Utility::ScreenSize = new QSize(1080, 1920);
