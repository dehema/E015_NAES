#include "HMessageBox.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>
#include <QtGui/QMouseEvent>

const QString btnStyle = "QPushButton{border:3px solid rgb(25,43,62); \
						background-color:rgb(25,43,62); \
						border-radius:5px;	\
						color: white; \
						font-family:'Microsoft YaHei ';font-size:18px;} \
						QPushButton:hover{border:3px solid rgb(9, 21, 41); \
						background-color:rgb(9, 21, 41); \
						border-radius:5px;	\
						color:white;	\
						font-family:'Microsoft YaHei ';font-size:18px;} \
						QPushButton:pressed{border:3px solid rgb(25,43,62); \
						background-color:rgb(25,43,62); \
						color:white;	\
						border-radius:5px;	\
						font-family:'Microsoft YaHei ';font-size:18px;} ";

namespace HGT
{
	HMessageBox::HMessageBox(QWidget *parent,
		Icon icon,
		const QString &title,
		const QString &text,
		QMessageBox::StandardButtons standButtons,
		QMessageBox::StandardButton defaultButton)
		:QDialog(parent)
		, m_lTitle(new QLabel(this))
		, m_lIconMain(new QLabel(this))
		, m_lText(new QLabel(this))
		, m_layout(new QVBoxLayout())
		, m_pButtonBox(new QDialogButtonBox(this))
		, m_mouserPressed(false)
	{
		setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
		setFixedSize(QSize(606, 286));

		m_layout->setContentsMargins(20, 20, 20, 20);

		QHBoxLayout *titleLayout = new QHBoxLayout();
		titleLayout->setContentsMargins(8, 0, 0, 0);
		titleLayout->setSpacing(UI_Layout_Spacing);
		titleLayout->addWidget(m_lTitle);
		titleLayout->addStretch(1);
		m_lTitle->setFixedHeight(20);
		m_layout->addLayout(titleLayout);

		QWidget *groupBox = new QWidget(this);
		groupBox->setStyleSheet("background-color:rgb(45, 66, 86);");
		groupBox->setFixedHeight(230);
		m_layout->addWidget(groupBox);
		QVBoxLayout *vBoxLayout = new QVBoxLayout();
		groupBox->setLayout(vBoxLayout);
		vBoxLayout->setContentsMargins(20, 20, 20, 20);
		vBoxLayout->setSpacing(UI_Layout_Spacing);

		QHBoxLayout *hLayout = new QHBoxLayout();
		m_lIconMain->setFixedSize(QSize(90, 90));
		m_lText->setFixedHeight(120);
		hLayout->addWidget(m_lIconMain);
		hLayout->addWidget(m_lText);
		hLayout->addStretch(1);
		hLayout->setSpacing(10);
		vBoxLayout->addLayout(hLayout);

		QHBoxLayout *hLayoutButtons = new QHBoxLayout();
		hLayoutButtons->addStretch(1);
		hLayoutButtons->addWidget(m_pButtonBox);
		vBoxLayout->addLayout(hLayoutButtons);
		m_pButtonBox->setFixedHeight(55);
		m_layout->addWidget(groupBox);
		setLayout(m_layout);

		m_pButtonBox->setStandardButtons(QDialogButtonBox::StandardButtons((int)standButtons));
		setDefaultButton(defaultButton);

		QList<QAbstractButton *> buttons = m_pButtonBox->buttons();
		for (int i = 0; i < buttons.size(); i++) {
			QDialogButtonBox::StandardButton button = m_pButtonBox->standardButton(buttons.at(i));
			QPushButton *pushButton = m_pButtonBox->button(button);
			pushButton->setFixedSize(QSize(135, 55));
			if (button == QDialogButtonBox::Ok || button == QDialogButtonBox::Yes) {
				pushButton->setText(GetLang("1708419640"));
			}
			else {
				pushButton->setText(GetLang("1708419641"));
			}
			pushButton->setStyleSheet(btnStyle);
		}

		m_lTitle->setText(title);
		m_lTitle->setStyleSheet("font-size:20px; color:white;background-color:transparent;");
		m_lText->setText(text);
		m_lText->setStyleSheet("font-size:18px; color:white;background-color:rgb(45, 66, 86);");

		if (icon == Messsage) {

			m_lIconMain->setStyleSheet("image:url(img/info.png)");
		}
		else if (icon == Question) {

			m_lIconMain->setStyleSheet("image:url(img/question.png)");
		}
		else if (icon == Warning) {

			m_lIconMain->setStyleSheet("image:url(img/warning.png)");
		}
		else if (icon == Error) {

			m_lIconMain->setStyleSheet("image:url(img/error.png))");
		}

		this->setStyleSheet("QDialog{border:1px solid black;background-color:rgb(45,66,86);color:white;}");

		connect(m_pButtonBox, SIGNAL(clicked(QAbstractButton*)), this,
			SLOT(onButtonClicked(QAbstractButton*)));

	}

	void HMessageBox::setDefaultButton(QPushButton *button)
	{
		if (!m_pButtonBox->buttons().contains(button)) {
			return;
		}

		button->setDefault(true);
		button->setFocus();
	}

	void HMessageBox::setDefaultButton(QMessageBox::StandardButton defaultButton)
	{
		setDefaultButton(m_pButtonBox->button(QDialogButtonBox::StandardButton(defaultButton)));
	}

	void HMessageBox::mousePressEvent(QMouseEvent *event)
	{
		if (event->button() == Qt::LeftButton) {
			m_mouserPressed = true;
			m_point = event->globalPos() - this->pos();
			event->accept();
		}
	}

	void HMessageBox::mouseMoveEvent(QMouseEvent *event)
	{
		if (m_mouserPressed && (event->buttons() & Qt::LeftButton)) {
			this->move(event->globalPos() - m_point);
			event->accept();
		}
	}

	void HMessageBox::mouseReleaseEvent(QMouseEvent * /*event*/)
	{
		m_mouserPressed = false;
	}

	int HMessageBox::execReturnCode(QAbstractButton *button)
	{
		return m_pButtonBox->standardButton(button);
	}

	void HMessageBox::onButtonClicked(QAbstractButton *button)
	{
		done(execReturnCode(button));
	}

}