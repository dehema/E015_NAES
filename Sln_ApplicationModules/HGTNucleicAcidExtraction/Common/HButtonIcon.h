#pragma once
#include <QtWidgets/QPushButton>

class HButtonIcon : public QPushButton {
	Q_OBJECT
public:
	bool sel = false;
	HButtonIcon(QString _normalIcon, QString _hoverIcon) : QPushButton() {
		if (_hoverIcon.isEmpty())
		{
			_hoverIcon = _normalIcon;
		}
		normalIcon = QIcon(_normalIcon);
		hoverIcon = QIcon(_hoverIcon);

		setObjectName("bt_common");
		setIcon(normalIcon);
		setIconSize(QSize(width(), height()));
	}

	void showNormalIcon()
	{
		sel = false;
		setIcon(normalIcon);
	}

	void showHoverIcon()
	{
		sel = true;
		setIcon(hoverIcon);
	}

protected:
	void enterEvent(QEvent *event) override {
		setIcon(hoverIcon);
		QPushButton::enterEvent(event);
	}

	void leaveEvent(QEvent *event) override {
		setIcon(sel ? hoverIcon : normalIcon);
		QPushButton::leaveEvent(event);
	}

private:
	QIcon normalIcon;
	QIcon hoverIcon;
};