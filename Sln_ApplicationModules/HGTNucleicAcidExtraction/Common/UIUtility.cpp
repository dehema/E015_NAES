#include "UIUtility.h"

UIUtility::UIUtility()
{
	comboxTableStyle = QString(
		//1.界面上comboxBox样式 
		"QComboBox"
		"{"
		"	padding-left:5px;"
		"	font-size: 13px;"
		"	color:black;"
		"	background-color:rgba(255, 255, 255, 0);"
		"	text-align:center;"
		"	border-radius:0px;"
		"	border:0px solid #298DFF;"
		"}"
		" QComboBox QAbstractItemView"
		"{"
		"	font-size: 13px;"
		"	height:70px;"
		"	outline: 0px solid gray;"
		"	border: 1px solid #298DFF;"
		"	color: black;"
		"	background-color: #FFFFFF;"
		"	selection-color:#FFFFFF;"
		"	selection-background-color: #298DFF;"
		"}"
		"QComboBox QAbstractItemView::item"
		"{"
		"	height:24px;"
		"}"
		//5.下拉项展开时，comboxBox选中文字样式 文字离顶部8px, 左边4p
		//"QComboBox:on{padding-top:8px; padding-left:4px;}"
		//6.下拉按钮样式 子控件填充方式，位位顶部靠右边
		"QComboBox::drop-down"
		"{"
		"	subcontrol-origin: padding;"
		"	subcontrol-position: top right;"
		"	width: 30px;"
		"	border-left-width: 0px;"
		"	border-left-color: darkgray;"
		"	border-left-style: solid;"
		"	border-top-right-radius: 3px;"
		"	border-bottom-right-radius: 3px;"
		"}"
		//7.下面按钮悬浮样式
		//"QComboBox::drop-down:hover{background: red;}"
		//8.下拉箭头样式
		"QComboBox::down-arrow"
		"{"
		"	width:15px;"
		"	height:15px;"
		"	image: url(img/comboBox_down.png);"
		"}"
		//9.下拉列表展开时下拉箭头样式， 下拉时箭头距顶部5px, 左边5px
		"QComboBox::down-arrow:on"
		"{"
		"	image: url(img/comboBox_up.png);"
		"}"
	);
	editTableStyle = QString(
		"HLineEdit"
		"{"
		"	font-size: 12px;"
		"	background-color:rgba(255, 255, 255, 0);"
		"	border-radius:0px;"
		"	border:0px;"
		"}"
	);

	btTableStyle = QString(
		"QPushButton"
		"{"
		"font-size: 14px;"
		"border: 1px solid #298DFF;"
		"border-radius: 0px;"
		"background-color: #F2F2F2;"
		"color: #298DFF;"
		"font-family: 'Microsoft YaHei';"
		"}"
	);

	dateTableStyle = QString(
		"QDateEdit"
		"{"
		"font-size: 14px;"
		"border: 0px"
		"border-radius: 0px;"
		"background-color: #F2F2F2;"
		"color: #298DFF;"
		"font-family: 'Microsoft YaHei';"
		"}"
	);
	checkTableStyle = QString(
		"QCheckBox::indicator { width: 30px; height: 30px; }"
		"QCheckBox::indicator:checked { image: url(img/checkbox-sel.png); }"
		"QCheckBox::indicator:unchecked { image: url(img/checkbox-unSel.png); }"
	);
}

UIUtility::~UIUtility()
{
}

QWidget* UIUtility::getNewWidgetCommon(QWidget * _parent)
{
	QWidget* widget = new QWidget(_parent);
	return widget;
}

QFrame* UIUtility::getNewFrame(QWidget * _parent)
{
	QFrame* frame = new QFrame(_parent);
	frame->setObjectName("frame_common");
	return frame;
}


void UIUtility::setNewFrame(QFrame * _frame)
{
	_frame->setObjectName("frame_common");
}

QGroupBox* UIUtility::getNewGroupBox(QString _langID, QLayout* _layout, QWidget* _parent)
{
	QGroupBox* box = new QGroupBox(_parent);
	box->setTitle(GetLang(_langID));
	box->setObjectName("groupBox_common");
	if (_layout != nullptr)
		box->setLayout(_layout);
	QFont font;
	font.setPixelSize(18);
	box->setFont(font);
	box->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
	box->setContentsMargins(15, 45, 15, 15);
	return box;
}

void UIUtility::setNewGroupBox(QGroupBox * _groupBox)
{
	_groupBox->setObjectName("groupBox_common");
}

QLabel* UIUtility::getNewLbCommon(QString _str)
{
	QLabel* lb = new QLabel();
	lb->setObjectName("lb_common_normal");
	QFont font(UI_FONT_Family);
	font.setPixelSize(UI_FONT_SIZE_COMMON);
	lb->setFont(font);
	if (_str != nullptr)
		lb->setText(GetLang(_str));
	return lb;
}

void UIUtility::setNewLbCommon(QLabel * _lb)
{
	_lb->setObjectName("lb_common_normal");
}

QLabel* UIUtility::getNewLbTitle(QString _str)
{
	QLabel* lb = new QLabel(_str);
	lb->setObjectName("lb_common_title");
	QFont font(UI_FONT_Family);
	font.setBold(true);
	font.setPixelSize(UI_FONT_SIZE_TITLE);
	lb->setFont(font);
	if (_str != nullptr)
		lb->setText(GetLang(_str));
	lb->setAlignment(Qt::AlignCenter);
	lb->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	lb->setFixedHeight(35);
	return lb;;
}

void UIUtility::setNewLbTitle(QLabel * _lb)
{
	_lb->setObjectName("lb_common_title");
}

QPushButton* UIUtility::getNewBtCommon(QString _langID)
{
	QPushButton* bt = new QPushButton();
	bt->setFixedSize(UI_Bt_Width, UI_Bt_Height);
	bt->setObjectName("bt_common");
	QFont font(UI_FONT_Family);
	font.setPixelSize(UI_FONT_SIZE_COMMON);
	bt->setFont(font);
	if (_langID != nullptr)
		bt->setText(GetLang(_langID));
	bt->setAutoDefault(false);
	bt->setDefault(false);
	bt->setFocusPolicy(Qt::NoFocus);
	return bt;
}

void UIUtility::setNewBtCommon(QPushButton * _bt)
{
	_bt->setObjectName("bt_common");
}

HButtonIcon * UIUtility::getNewBtIcon(QString normalIcon, QString hoverIcon)
{
	HButtonIcon* bt = new HButtonIcon(normalIcon, hoverIcon);
	bt->setFixedSize(UI_Bt_Width, UI_Bt_Height);
	bt->setObjectName("bt_common");
	bt->setAutoDefault(false);
	bt->setDefault(false);
	bt->setFocusPolicy(Qt::NoFocus);
	return bt;
}

HLineEdit* UIUtility::getNewLineEdit()
{
	HLineEdit* lineEdit = new HLineEdit();
	lineEdit->setObjectName("lineEdit_common");
	lineEdit->setAttribute(Qt::WA_InputMethodEnabled, false);
	lineEdit->setFixedSize(UI_LineEdit_Width, UI_LineEdit_Height);
	return lineEdit;
}

void UIUtility::setNewLineEdit(HLineEdit * _lineEdit)
{
	_lineEdit->setObjectName("lineEdit_common");
}

QDateEdit* UIUtility::getNewDateEdit(QDate _date)
{
	QDateEdit* dateEdit = new QDateEdit();
	dateEdit->setObjectName("dateEdit_common");
	dateEdit->setAttribute(Qt::WA_InputMethodEnabled, false);
	dateEdit->setFixedSize(200, UI_Bt_Height);
	dateEdit->setDate(_date);
	dateEdit->setFixedSize(UI_Bt_Width, UI_Bt_Height);
	return dateEdit;
}

void UIUtility::setNewDateEdit(QDateEdit * _dateEdit)
{
	_dateEdit->setObjectName("dateEdit_common");
}

QTimeEdit * UIUtility::getNewTimeEdit(QTime _time)
{
	QTimeEdit* timeEdit = new QTimeEdit();
	timeEdit->setObjectName("timeEdit_common");
	timeEdit->setDisplayFormat("HH:mm:ss");
	timeEdit->setAttribute(Qt::WA_InputMethodEnabled, false);
	timeEdit->setFixedSize(200, UI_Bt_Height);
	timeEdit->setTime(_time);
	timeEdit->setFixedSize(UI_Bt_Width, UI_Bt_Height);
	return timeEdit;
}

void UIUtility::setNewTimeEdit(QTimeEdit * _timeEdit)
{
	_timeEdit->setObjectName("timeEdit_common");
}

QProgressBar* UIUtility::getNewProgressBar(int _min, int _max)
{
	QProgressBar* bar = new QProgressBar();
	bar->setFixedWidth(UI_CheckBox_Width);
	bar->setRange(_min, _max);
	bar->setValue(50);
	return bar;
}

QComboBox* UIUtility::getNewComboxBox(QStringList _list)
{
	QComboBox* box = new QComboBox();
	box->setFixedSize(UI_Bt_Width, UI_Bt_Height);
	for (int i = 0; i < _list.size(); i++)
	{
		QString _str = _list.at(i);
		box->addItem(GetLang(_str));
	}
	box->setObjectName("comboxBox_common");
	box->setCurrentIndex(0);
	QListView *ListView = getNewListView();
	box->setView(ListView);
	return box;
}

void UIUtility::setNewComboxBox(QComboBox * _comboBox)
{
	_comboBox->setObjectName("comboxBox_common");
}

HTableView* UIUtility::getNewTableView()
{
	HTableView* tableView = new HTableView();
	tableView->setObjectName("table_common");
	tableView->horizontalHeader()->setFixedHeight(30);
	tableView->setAlternatingRowColors(true);
	tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tableView->verticalHeader()->setDefaultSectionSize(30);
	tableView->verticalHeader()->setHidden(true);
	tableView->resizeRowsToContents();
	tableView->resizeColumnsToContents();
	tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	tableView->setDragDropMode(QAbstractItemView::DragDropMode::NoDragDrop);
	return tableView;
}

void UIUtility::setNewTableView(HTableView * _tableView)
{
	_tableView->setObjectName("table_common");
}

QCheckBox* UIUtility::getNewCheckBox(QString _langID)
{
	QCheckBox* checkBox = new QCheckBox();
	if (_langID != nullptr)
		checkBox->setText(GetLang(_langID));
	checkBox->setObjectName("checkBox_common");
	checkBox->setFixedSize(UI_CheckBox_Width, UI_CheckBox_Height);
	return checkBox;
}

void UIUtility::setNewCheckBox(QCheckBox * _checkBox)
{
	_checkBox->setObjectName("checkBox_common");
}

QSize UIUtility::getBtTextSize(QPushButton * bt, int _fontSize)
{
	return getTextSize(bt->text(), _fontSize);
}

QSize UIUtility::getTextSize(const QString &text, int _fontSize)
{
	/* 设置字体属性 */
	QFont font(UI_FONT_Family);
	font.setPixelSize(_fontSize);
	/* 设置字体信息 */
	QFontMetrics metrics(font);
	QSize size = metrics.boundingRect(text).size();
	return size;
}

QListView* UIUtility::getNewListView()
{
	QListView* listView = new QListView();
	listView->setObjectName("listView_common");
	return listView;
}

void UIUtility::setNewListView(QListView * _listView)
{
	_listView->setObjectName("listView_common");
}

QTableWidget* UIUtility::getNewTableWidget()
{
	QTableWidget* listView = new QTableWidget();
	listView->setObjectName("tableWidget_common");
	return listView;
}

void UIUtility::setNewTableWidget(QTableWidget * _tableWidget)
{
	_tableWidget->setObjectName("tableWidget_common");
}

QScrollArea* UIUtility::getNewScrollArea(QWidget * _parent)
{
	QScrollArea* scrollArea = new QScrollArea();
	scrollArea->setObjectName("scrollArea_common");
	return scrollArea;
}

QPlainTextEdit* UIUtility::getNewPlainText()
{
	QPlainTextEdit* plainText = new QPlainTextEdit();
	return plainText;
}

QHBoxLayout* UIUtility::getNewHBoxLayout(QWidget* _widget)
{
	QHBoxLayout* layout = new QHBoxLayout();
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	layout->setAlignment(Qt::AlignLeft);
	if (_widget != nullptr)
		_widget->setLayout(layout);
	return layout;
}

QVBoxLayout* UIUtility::getNewVBoxLayout(QWidget* _widget)
{
	QVBoxLayout* layout = new QVBoxLayout();
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(10);
	layout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
	if (_widget != nullptr)
		_widget->setLayout(layout);
	return layout;
}

QGridLayout * UIUtility::getNewGridLayout(QWidget * _widget)
{
	QGridLayout* layout = new QGridLayout();
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	if (_widget != nullptr)
		_widget->setLayout(layout);
	return layout;
}

void UIUtility::adjustBtTextSize(QPushButton * _bt, int _defaultFontSize)
{
	int fontSize = _defaultFontSize;
	QSize size = getBtTextSize(_bt, fontSize);
	while (size.width() > _bt->width() - 4 || size.height() > _bt->height())
	{
		fontSize--;
		size = getBtTextSize(_bt, fontSize);
	}
	if (fontSize != _bt->font().pixelSize())
	{
		QFont font(UI_FONT_Family);
		font.setPixelSize(fontSize);
		_bt->setFont(font);
	}
}

void UIUtility::adjustLbTextSize(QLabel * _lb)
{
	adjustLbTextSize(_lb, _lb->font().pixelSize());
}

void UIUtility::adjustLbTextSize(QLabel * _lb, int _defaultFontSize)
{
	int fontSize = _defaultFontSize;
	QSize size = getTextSize(_lb->text(), fontSize);
	while (size.width() > _lb->width() || size.height() > _lb->height())
	{
		fontSize--;
		size = getTextSize(_lb->text(), fontSize);
	}
	if (fontSize != _lb->font().pixelSize())
	{
		QFont font(UI_FONT_Family);
		font.setPixelSize(fontSize);
		_lb->setFont(font);
	}
}

//设置表格文本居中
void UIUtility::setTableItemCenter(QStandardItemModel*& _model)
{
	for (int row = 0; row < _model->rowCount(); ++row) {
		for (int column = 0; column < _model->columnCount(); ++column) {
			QStandardItem *item = _model->item(row, column);
			if (item) {
				item->setTextAlignment(Qt::AlignCenter);
			}
		}
	}
}

//设置文本行高
void UIUtility::setTableRowHeight(HTableView*& _tb)
{
	for (int row = 0; row < _tb->model()->rowCount(); row++)
	{
		_tb->setRowHeight(row, UI_TableView_RowHeight);
	}
}

//设置文本列宽
void UIUtility::setTableColWidth(QTableView*& _tb, int _width)
{
	for (int col = 0; col < _tb->model()->columnCount(); col++)
	{
		_tb->setColumnWidth(col, _width);
	}
}

QRect UIUtility::getScreenRect()
{
	QDesktopWidget *desktop = QApplication::desktop();
	QRect screenRect = desktop->availableGeometry();
	return screenRect;
}

void UIUtility::removeComboBoxInvalidItem(QComboBox * _cb)
{
	int index = _cb->findText("-");
	if (index != -1)
	{
		_cb->removeItem(index);
	}
}
