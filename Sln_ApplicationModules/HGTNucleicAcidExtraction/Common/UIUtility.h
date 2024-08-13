#pragma once
#include "Utility.h"

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QMessageBox>
#include <QtCore/QStringListModel>
#include <QtCore/QRegExp>
#include <QtCore/QRect>
#include <QtGui/QPainter>
#include <QtGui/QFont>
#include <QtGui/QRegExpValidator>
#include "HLineEdit.h"
#include "HTableView.h"
#include "HTableViewItemModel.h"
#include "ImageWidget.h"
#include "HButtonIcon.h"
#include "Utility.h"
#include "HMessageBox.h"

enum class PageType {
	//日志
	Log,
	//消耗品
	Consumable,
	//样本
	Test,
	//运行状态
	OperationState,
	//等待队列
	WaitingQueue,
	//历史任务
	HistoricalTask,
	//结果
	Result,
	//报告
	Report,
	//管理
	Manager,
	//管理_设备管理
	Manager_DeviceMaintain,
	//维护
	Maintain,
	Length,
};

class UIUtility :public Singleton<UIUtility>
{
public:
	UIUtility();
	~UIUtility();

	//----------------------field----------------------
	//主界面
	QWidget* mainWindow;

	QString comboxTableStyle;
	QString editTableStyle;
	QString btTableStyle;
	QString dateTableStyle;
	QString checkTableStyle;

	//----------------------widget----------------------
	QWidget* getNewWidgetCommon(QWidget* _parent = nullptr);
	QFrame* getNewFrame(QWidget* _parent = nullptr);
	void setNewFrame(QFrame * _frame);

	QGroupBox* getNewGroupBox(QString _langID, QLayout* _layout = nullptr, QWidget* _parent = nullptr);
	void setNewGroupBox(QGroupBox* _groupBox);

	QLabel* getNewLbCommon(QString _str = nullptr);
	void setNewLbCommon(QLabel* _lb);

	QLabel* getNewLbTitle(QString _str = nullptr);
	void setNewLbTitle(QLabel* _lb);

	QPushButton* getNewBtCommon(QString _langID = nullptr);
	void setNewBtCommon(QPushButton* _bt);

	HButtonIcon* getNewBtIcon(QString normalIcon, QString hoverIcon);

	HLineEdit* getNewLineEdit();
	void setNewLineEdit(HLineEdit* _lineEdit);

	QDateEdit* getNewDateEdit(QDate _date);
	void setNewDateEdit(QDateEdit* _dateEdit);

	QTimeEdit* getNewTimeEdit(QTime _time);
	void setNewTimeEdit(QTimeEdit* _timeEdit);

	QProgressBar* getNewProgressBar(int _min, int _max);

	QComboBox* getNewComboxBox(QStringList _list = {});
	void setNewComboxBox(QComboBox* _comboBox);

	QComboBox* getNewComboxBoxLarge(QStringList _list = {});
	void setNewComboxBoxLarge(QComboBox* _comboBox);

	HTableView* getNewTableView();
	void setNewTableView(HTableView* _tableView);

	QCheckBox* getNewCheckBox(QString _langID = nullptr);
	void setNewCheckBox(QCheckBox* _checkBox);

	QListView* getNewListView();
	void setNewListView(QListView* _listView);

	QTableWidget* getNewTableWidget();
	void setNewTableWidget(QTableWidget* _tableWidget);

	QScrollArea* getNewScrollArea(QWidget* _parent);

	QPlainTextEdit* getNewPlainText();

	QHBoxLayout* getNewHBoxLayout(QWidget* _widget);
	QVBoxLayout* getNewVBoxLayout(QWidget* _widget);
	QGridLayout* getNewGridLayout(QWidget* _widget);

	//-----------function-----------
	QSize getBtTextSize(QPushButton* bt, int _fontSize);
	QSize getTextSize(const QString &text, int _fontSize);

	void adjustBtTextSize(QPushButton* bt, int _defaultFontSize = 14);
	void adjustLbTextSize(QLabel* _lb);
	void adjustLbTextSize(QLabel* bt, int _defaultFontSize);

	const QRegExpValidator *RegExpNumber = new QRegExpValidator(QRegExp("\\d+"));
	const QRegExpValidator *RegExpLetterNumber = new QRegExpValidator(QRegExp("[A-Za-z0-9]+"));
	const QRegExpValidator *RegExpChinese = new QRegExpValidator(QRegExp("^[\u4E00-\u9FA5]+$"));

	void setTableItemCenter(QStandardItemModel*& _tb);
	void setTableRowHeight(HTableView*& _tb);
	void setTableColWidth(QTableView*& _tb, int _width);

	//获取屏幕矩阵
	QRect getScreenRect();

	//移除下拉列表的无效选项
	void removeComboBoxInvalidItem(QComboBox* _cb);

	void adjustBtFontSize(QPushButton* bt) {
		QFont font = bt->font();
		int buttonWidth = bt->width();
		int buttonHeight = bt->height();

		int fontSize = qMin(buttonWidth / bt->text().length(), buttonHeight / 2);
		font.setPointSize(fontSize);
		bt->setFont(font);
	}
};