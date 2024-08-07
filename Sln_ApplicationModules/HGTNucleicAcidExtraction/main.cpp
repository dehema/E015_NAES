#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>
#include <QtCore/QMetaType>
#include <QtGui\QFontDatabase>
#include "MainWindow.h"
#include "Common/Utility.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//������ͼ��
	QIcon iconLogo("../img/logo.png");
	a.setWindowIcon(iconLogo);
	//QTextCodec::setCodecForCStrings(codec);
	//QTextCodec::setCodecForTr(codec);
	//QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

	//����
	QTextCodec *codec = QTextCodec::codecForName("GB2312");
	QTextCodec::setCodecForLocale(codec);

	//����


	// ���������������Ϊ "YourFont"
	int fontId = QFontDatabase::addApplicationFont("../ttf/fontawesome-webfont.ttf");
	QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);

	// Ӧ�����嵽���Ӧ�ó���
	if (!fontFamilies.empty())
	{
		QString fontFamily = fontFamilies.at(0);
		QFont defaultFont = a.font();
		defaultFont.setFamily(fontFamily);
		a.setFont(defaultFont);
	}

	//������
	Utility::ins().loadLangFile(0);

	MainWindow mainWindow;
	mainWindow.show();
	return a.exec();
}