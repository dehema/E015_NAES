#pragma once
#include "QtWidgets/QDialog.h"
#include "QtWidgets/QMessageBox.h"
#include "Utility.h"

class QLabel;
class QVBoxLayout;
class QDialogButtonBox;
class QMouseEvent;

namespace HGT {
	/* 消息类定义 */
	class  HMessageBox : public QDialog
	{
		Q_OBJECT

	public:
		enum Icon {
			Messsage,
			Question,
			Warning,
			Error,
		};

		explicit HMessageBox(QWidget *parent = 0,
			Icon icon = Messsage,
			const QString &title = "Tip",
			const QString &text = "",
			QMessageBox::StandardButtons = QMessageBox::Ok,
			QMessageBox::StandardButton defaultButton = QMessageBox::Ok);

		void setDefaultButton(QPushButton *button);
		void setDefaultButton(QMessageBox::StandardButton defaultButton);


	protected:
		void mousePressEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);
		void mouseReleaseEvent(QMouseEvent *event);

	private:
		int execReturnCode(QAbstractButton *button);

	signals:
		private slots :
			void onButtonClicked(QAbstractButton *button);
	private:
		QLabel *m_lIconTitle;
		QLabel *m_lTitle;
		QLabel *m_lIconMain;
		QLabel *m_lText;
		QVBoxLayout *m_layout;
		QDialogButtonBox *m_pButtonBox;
		bool m_mouserPressed;
		QPoint m_point;
	};

	/* info question warn error */
	static HMessageBox *msgBox = nullptr;
	static HMessageBox::Icon m_curIcon = HMessageBox::Messsage;

	inline static QMessageBox::StandardButton information(QWidget *parent = 0,
		const QString &title = "Tip",
		const QString &text = QString::fromLocal8Bit(""),
		QMessageBox::StandardButtons standardButtons = QMessageBox::Ok,
		QMessageBox::StandardButton defaultButton = QMessageBox::Ok) {
		if (msgBox != nullptr)
		{
			delete msgBox;
			msgBox = nullptr;
		}

		m_curIcon = HMessageBox::Messsage;
		msgBox = new HMessageBox(parent, m_curIcon, title, text, standardButtons, defaultButton);
		msgBox->setModal(true);
		defaultButton = (QMessageBox::StandardButton)msgBox->exec();
		return defaultButton;
	}

	inline static QMessageBox::StandardButton Question(QWidget *parent = 0,
		const QString &title = "Tip",
		const QString &text = QString::fromLocal8Bit(""),
		QMessageBox::StandardButtons standardButtons = QMessageBox::Ok,
		QMessageBox::StandardButton defaultButton = QMessageBox::Ok) {
		if (msgBox != nullptr)
		{
			delete msgBox;
			msgBox = nullptr;
		}

		m_curIcon = HMessageBox::Question;
		msgBox = new HMessageBox(parent, m_curIcon, title, text, standardButtons, defaultButton);
		msgBox->setModal(true);
		defaultButton = (QMessageBox::StandardButton)msgBox->exec();
		return defaultButton;
	}

	inline static QMessageBox::StandardButton warning(QWidget *parent = 0,
		const QString &title = "Tip",
		const QString &text = QString::fromLocal8Bit(""),
		QMessageBox::StandardButtons standardButtons = QMessageBox::Ok,
		QMessageBox::StandardButton defaultButton = QMessageBox::Ok) {
		if (msgBox != nullptr)
		{
			delete msgBox;
			msgBox = nullptr;
		}

		m_curIcon = HMessageBox::Warning;
		msgBox = new HMessageBox(parent, m_curIcon, title, text, standardButtons, defaultButton);
		msgBox->setModal(true);

		defaultButton = (QMessageBox::StandardButton)msgBox->exec();
		return defaultButton;
	}

	inline static QMessageBox::StandardButton Error(QWidget *parent = 0,
		const QString &title = "Tip",
		const QString &text = QString::fromLocal8Bit(""),
		QMessageBox::StandardButtons standardButtons = QMessageBox::Ok,
		QMessageBox::StandardButton defaultButton = QMessageBox::Ok) {
		if (msgBox != nullptr)
		{
			delete msgBox;
			msgBox = nullptr;
		}

		m_curIcon = HMessageBox::Error;
		msgBox = new HMessageBox(parent, m_curIcon, title, text, standardButtons, defaultButton);
		msgBox->setModal(true);
		defaultButton = (QMessageBox::StandardButton)msgBox->exec();
		return defaultButton;
	}
}
