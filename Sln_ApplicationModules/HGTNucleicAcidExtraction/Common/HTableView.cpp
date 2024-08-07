#include "HTableView.h"

HTableView::HTableView(QWidget * parent) : QTableView(parent)
{
	this->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
	this->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
	QScrollBar *scrollBar = (QScrollBar *)this->verticalScrollBar();
	connect(scrollBar, SIGNAL(valueChanged(int)), this, SLOT(moveRowTo(int)));
}

int HTableView::getRowSum()
{
	QAbstractItemModel* model = this->model();
	if (model == nullptr)
		return 0;
	int row = model->rowCount();
	return row;
}

int HTableView::getPageSum()
{
	int rowSum = getRowSum();
	if (rowSum == 0)
		return 0;
	int row1page = getRowSumPerPage();
	int totalPage = rowSum / row1page;
	if (rowSum % row1page != 0)
		totalPage++;
	return totalPage;
}

int HTableView::getRowSumPerPage()
{
	int tableViewHeight = this->height();
	int row1page = tableViewHeight / rowHeight - 1;
	return row1page;
}


void HTableView::moveToLastPage()
{
	int page = pageIndex;
	if (page <= 1) return;
	int tableViewHeight = this->height();
	int row1page = this->getRowSumPerPage();
	this->verticalScrollBar()->setSliderPosition((page - 2)*row1page);
	setPageIndexVal(page - 1);
}

void HTableView::moveToNextPage()
{
	int page = pageIndex;
	int totalRow = this->getRowSum();
	int totalPage = this->getPageSum();
	int row1page = this->getRowSumPerPage();
	this->verticalScrollBar()->setSliderPosition((page)*row1page);
	if (page + 1 <= totalPage)
		setPageIndexVal(page + 1);
}

void HTableView::setPageIndexVal(int _index)
{
	pageIndex = _index;
	signal_onPageIndexChange(_index);
}

void HTableView::moveRowTo(int _index)
{
	int totalRow = this->getRowSum();
	int row1page = this->getRowSumPerPage();
	int totalPage = this->getPageSum();

	int last = 0;
	int current = this->verticalScrollBar()->value();
	int next = row1page;
	for (int page = 1; page <= totalPage; page++)
	{
		if (current > last && current < next)
		{
			setPageIndexVal(page);
			break;
		}
		last += row1page;
		next += row1page;
	}
	if (current >= row1page*(totalPage))
		setPageIndexVal(totalPage);
}

void HTableView::movePageTo(int _pageIndex)
{
	int totalRow = this->getRowSum();
	int row1page = this->getRowSumPerPage();
	int totalPage = this->getPageSum();
	if (totalRow%row1page != 0) totalPage++;

	int page = _pageIndex;
	if (page <= 0) page = 1;
	else if (page > totalPage) page = totalPage;
	setPageIndexVal(page);
	this->verticalScrollBar()->setSliderPosition(row1page * (page - 1));
}

void HTableView::setModel(HTableViewItemModel * model)
{
	QTableView::setModel(model);
	for (int _row = 0; _row < model->rowCount(); _row++)
	{
		this->setRowHeight(_row, rowHeight);
	}
}

void HTableView::setModel(QStandardItemModel * model)
{
	QTableView::setModel(model);
}
