#pragma once
#include <QtWidgets/QWidget>
#include <QtGui/QPixmap>
#include <QtGui/QBitmap>

class ImageWidget :public QWidget
{
public:
	~ImageWidget() {};

	explicit ImageWidget(QWidget *parent = nullptr) : QWidget(parent) {}

	void setPixmap(const QPixmap &pixmap) {
		m_pixmap = pixmap;
		adjustSize();
	}

protected:
	void resizeEvent(QResizeEvent *event) override {
		QWidget::resizeEvent(event);
		setMask(m_pixmap.mask());
	}

private:
	QPixmap m_pixmap;
};

