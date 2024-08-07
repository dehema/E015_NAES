#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>
#include <QtCore/QMetaType>
#include <QtGui\QFontDatabase>
#include "MainWindow.h"
#include "Common/Utility.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//任务栏图标
	QIcon iconLogo("../img/logo.png");
	a.setWindowIcon(iconLogo);
	//QTextCodec::setCodecForCStrings(codec);
	//QTextCodec::setCodecForTr(codec);
	//QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

	//编码
	QTextCodec *codec = QTextCodec::codecForName("GB2312");
	QTextCodec::setCodecForLocale(codec);

	//字体


	// 假设你的字体名称为 "YourFont"
	int fontId = QFontDatabase::addApplicationFont("../ttf/fontawesome-webfont.ttf");
	QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);

	// 应用字体到你的应用程序
	if (!fontFamilies.empty())
	{
		QString fontFamily = fontFamilies.at(0);
		QFont defaultFont = a.font();
		defaultFont.setFamily(fontFamily);
		a.setFont(defaultFont);
	}

	//多语言
	Utility::ins().loadLangFile(0);

	MainWindow mainWindow;
	mainWindow.show();
	return a.exec();
}