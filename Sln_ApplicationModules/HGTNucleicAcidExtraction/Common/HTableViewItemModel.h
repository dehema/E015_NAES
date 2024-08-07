#pragma once
#include <QtGui/QStandardItemModel>

class HTableViewItemModel : public QStandardItemModel
{
public:
	explicit HTableViewItemModel(QObject *parent = Q_NULLPTR);
	~HTableViewItemModel() {};

	QVariant data(const QModelIndex &index, int role) const override {
		if (role == Qt::TextAlignmentRole) {
			return Qt::AlignCenter;  // �����ı����ж���
		}
		return QStandardItemModel::data(index, role);
	}
};

