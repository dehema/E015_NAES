#pragma once
#include "UIUtility.h"

struct UIWidgetData
{
	int defaultFontSize;
	QString langID;
	QStringList optionLangIDs;
};

class BaseUI
{
public:
	QMap<QLabel*, UIWidgetData> lbMap;
	QMap<QAbstractButton*, UIWidgetData> btMap;
	QMap<QComboBox*, UIWidgetData> cbMap;
	QMap<QCheckBox*, UIWidgetData> checkMap;
	QMap<QGroupBox*, UIWidgetData> groupBoxMap;

	virtual QWidget* getNewWidgetCommon(QWidget* _parent = nullptr) {
		return	UIUtility::ins().getNewWidgetCommon(_parent);
	};
	virtual QFrame* getNewFrame(QWidget* _parent = nullptr) {
		return	UIUtility::ins().getNewFrame(_parent);
	};

	void setNewFrame(QFrame * _frame)
	{
		UIUtility::ins().setNewFrame(_frame);
	}

	virtual QGroupBox* getNewGroupBox(QString _langID, QLayout* _layout = nullptr, QWidget* _parent = nullptr) {
		QGroupBox* groupBox = UIUtility::ins().getNewGroupBox(_langID, _layout, _parent);
		if (_langID != nullptr)
		{
			UIWidgetData data;
			data.langID = _langID;
			groupBoxMap[groupBox] = data;
		}
		return groupBox;
	};


	void setNewGroupBox(QGroupBox * _groupBox)
	{
		UIUtility::ins().setNewGroupBox(_groupBox);
	}

	//lb
	virtual QLabel* getNewLbCommon(QString _langID = nullptr) {
		QLabel* lb = UIUtility::ins().getNewLbCommon(_langID);
		setLbLang(lb, _langID);
		return lb;
	};

	void setNewLbCommon(QLabel * _lb)
	{
		UIUtility::ins().setNewLbCommon(_lb);
	}

	virtual QLabel* getNewLbTitle(QString _langID = nullptr) {
		QLabel* lb = UIUtility::ins().getNewLbTitle(_langID);
		setLbLang(lb, _langID);
		return lb;
	};

	void setNewLbTitle(QLabel * _lb)
	{
		UIUtility::ins().setNewLbTitle(_lb);
	}

	virtual void setLbLang(QLabel* _lb, QString _langID = nullptr) {
		if (_langID != nullptr)
		{
			UIWidgetData data;
			data.defaultFontSize = _lb->font().pixelSize();
			data.langID = _langID;
			lbMap[_lb] = data;
		}
	};
	//bt
	virtual QPushButton* getNewBtCommon(QString _langID = nullptr) {
		QPushButton* bt = UIUtility::ins().getNewBtCommon(_langID);
		if (_langID != nullptr)
		{
			UIWidgetData data;
			data.defaultFontSize = bt->font().pixelSize();
			data.langID = _langID;
			btMap[bt] = data;
		}
		return bt;
	};

	virtual HButtonIcon* getNewBtIcon(QString normalIcon, QString hoverIcon = "") {
		HButtonIcon* bt = UIUtility::ins().getNewBtIcon(normalIcon, hoverIcon);
		return bt;
	};

	virtual QPushButton* getNewBtLarge(QString _langID = nullptr) {
		QPushButton* bt = UIUtility::ins().getNewBtCommon(_langID);
		bt->setFixedSize(UI_Bt_Width_Large, UI_Bt_Height_Large);
		bt->setObjectName("bt_large");
		if (_langID != nullptr)
		{
			UIWidgetData data;
			data.defaultFontSize = bt->font().pixelSize();
			data.langID = _langID;
			btMap[bt] = data;
		}
		return bt;
	};

	void setNewBtCommon(QPushButton * _bt)
	{
		UIUtility::ins().setNewBtCommon(_bt);
	}

	virtual HLineEdit* getNewLineEdit() {
		return	UIUtility::ins().getNewLineEdit();
	};

	void setNewLineEdit(HLineEdit * _lineEdit)
	{
		UIUtility::ins().setNewLineEdit(_lineEdit);
	}

	QDateEdit* getNewDateEdit(QDate _date = QDate::currentDate()) {
		return UIUtility::ins().getNewDateEdit(_date);
	}

	void setNewDateEdit(QDateEdit * _dateEdit)
	{
		UIUtility::ins().setNewDateEdit(_dateEdit);
	}

	QTimeEdit* getNewTimeEdit(QTime _time = QTime::currentTime()) {
		return UIUtility::ins().getNewTimeEdit(_time);
	}

	virtual QComboBox* getNewComboxBox(QStringList _langIDs = {}) {
		QComboBox* cb = UIUtility::ins().getNewComboxBox(_langIDs);
		if (_langIDs.count() != 0)
		{
			UIWidgetData data;
			data.optionLangIDs = _langIDs;
			cbMap[cb] = data;
		}
		return cb;
	};

	void setNewComboxBox(QComboBox * _comboBox)
	{
		UIUtility::ins().setNewComboxBox(_comboBox);
	}

	virtual QComboBox* getNewComboxBoxLarge(QStringList _langIDs = {}) {
		QComboBox* cb = UIUtility::ins().getNewComboxBoxLarge(_langIDs);
		QListView *ListView = new QListView;
		cb->setView(ListView);
		if (_langIDs.count() != 0)
		{
			UIWidgetData data;
			data.optionLangIDs = _langIDs;
			cbMap[cb] = data;
		}
		return cb;
	};

	void setNewComboxBoxLarge(QComboBox * _comboBox)
	{
		UIUtility::ins().setNewComboxBoxLarge(_comboBox);
	}

	HTableView* getNewTableView() {
		return	UIUtility::ins().getNewTableView();
	};

	void setNewTableView(HTableView * _tableView)
	{
		UIUtility::ins().setNewTableView(_tableView);
	}

	virtual QCheckBox* getNewCheckBox(QString _langID = nullptr) {
		QCheckBox* check = UIUtility::ins().getNewCheckBox(_langID);
		if (_langID != nullptr)
		{
			UIWidgetData data;
			data.langID = _langID;
			checkMap[check] = data;
		}
		return check;
	};

	void setNewCheckBox(QCheckBox * _checkBox)
	{
		UIUtility::ins().setNewCheckBox(_checkBox);
	}

	QListView* getNewListView() {
		return UIUtility::ins().getNewListView();
	}

	void setNewListView(QListView * _listView)
	{
		UIUtility::ins().setNewListView(_listView);
	}

	QTableWidget* getNewTableWidget() {
		return UIUtility::ins().getNewTableWidget();
	}

	void setNewTableWidget(QTableWidget * _tableWidget)
	{
		UIUtility::ins().setNewTableWidget(_tableWidget);
	}

	QSpinBox* getNewSpinBox(int _min, int _max) {
		return UIUtility::ins().getNewSpinBox(_min, _max);
	}

	void setNewSpinBox(QSpinBox * _spinBox)
	{
		UIUtility::ins().setNewSpinBox(_spinBox);
	}

	QDoubleSpinBox* getNewDoubleSpinBox(double _min, double _max) {
		return UIUtility::ins().getNewDoubleSpinBox(_min, _max);
	}

	void setNewDoubleSpinBox(QDoubleSpinBox * _doubleSpinBox)
	{
		UIUtility::ins().setNewDoubleSpinBox(_doubleSpinBox);
	}

	void setNewTimeEdit(QTimeEdit * _timeEdit)
	{
		UIUtility::ins().setNewTimeEdit(_timeEdit);
	}

	QProgressBar* getNewProgressBar(int _min = 0, int _max = 100) {
		return UIUtility::ins().getNewProgressBar(_min, _max);
	}

	QScrollArea* getNewScrollArea(QWidget* _parent = nullptr)
	{
		return UIUtility::ins().getNewScrollArea(_parent);
	}

	QPlainTextEdit* getNewPlainText() {
		return UIUtility::ins().getNewPlainText();
	};
	QHBoxLayout* getNewHBoxLayout(QWidget* _widget = nullptr) {
		return	UIUtility::ins().getNewHBoxLayout(_widget);
	};
	QVBoxLayout* getNewVBoxLayout(QWidget* _widget = nullptr) {
		return UIUtility::ins().getNewVBoxLayout(_widget);
	};
	QGridLayout* getNewGridLayout(QWidget* _widget = nullptr) {
		return UIUtility::ins().getNewGridLayout(_widget);
	};

	virtual void translate() {
		QMap<QLabel*, UIWidgetData>::iterator itemLb;
		for (itemLb = lbMap.begin(); itemLb != lbMap.end(); ++itemLb)
		{
			QLabel* lb = itemLb.key();
			UIWidgetData data = itemLb.value();
			if (!data.langID.isEmpty())
				lb->setText(GetLang(data.langID));
			UIUtility::ins().adjustLbTextSize(lb, data.defaultFontSize);
		}
		QMap<QAbstractButton*, UIWidgetData>::iterator itembt;
		for (itembt = btMap.begin(); itembt != btMap.end(); ++itembt)
		{
			UIWidgetData data = itembt.value();
			if (!data.langID.isEmpty())
			{
				QAbstractButton* bt = itembt.key();
				bt->setText(GetLang(data.langID));
				UIUtility::ins().adjustBtTextSize(qobject_cast<QPushButton*>(bt), data.defaultFontSize);
			}
		}
		QMap<QComboBox*, UIWidgetData>::iterator itemCb;
		for (itemCb = cbMap.begin(); itemCb != cbMap.end(); ++itemCb)
		{
			UIWidgetData data = itemCb.value();
			if (!data.optionLangIDs.isEmpty())
			{
				QComboBox* cb = itemCb.key();
				cb->clear();
				for (QString str : data.optionLangIDs)
				{
					cb->addItem(GetLang(str));
				}
			}
		}
		QMap<QCheckBox*, UIWidgetData>::iterator itemCheck;
		for (itemCheck = checkMap.begin(); itemCheck != checkMap.end(); ++itemCheck)
		{
			UIWidgetData data = itemCheck.value();
			if (!data.optionLangIDs.isEmpty())
			{
				QCheckBox* check = itemCheck.key();
				check->setText(GetLang(data.langID));
			}
		}
		QMap<QGroupBox*, UIWidgetData>::iterator itemGroupBox;
		for (itemGroupBox = groupBoxMap.begin(); itemGroupBox != groupBoxMap.end(); ++itemGroupBox)
		{
			UIWidgetData data = itemGroupBox.value();
			if (!data.optionLangIDs.isEmpty())
			{
				QGroupBox* groupBox = itemGroupBox.key();
				groupBox->setTitle(GetLang(data.langID));
			}
		}
	};

	void setAllComboBoxBlockSignal(bool _block)
	{
		QMap<QComboBox*, UIWidgetData>::iterator itemCb;
		for (itemCb = cbMap.begin(); itemCb != cbMap.end(); ++itemCb)
		{
			QComboBox* cb = itemCb.key();
			cb->blockSignals(_block);
		}
	}
};

