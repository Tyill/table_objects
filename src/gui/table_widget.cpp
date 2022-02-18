#include "table_widget.h"

#include <QLayout>
#include <QTableView>
#include <QHeaderView>
#include <QAbstractItemModel>

TableWidget::TableWidget(QWidget* parent) :
    QWidget(parent)
{    
    setObjectName("TableWidget");

    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins({});
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
        
    m_tableView = new QTableView(this);
    m_tableView->setObjectName("TableView");
    m_tableView->verticalHeader()->setVisible(true);

    mainLayout->addWidget(m_tableView, 1);
}

void TableWidget::setModel(QAbstractTableModel* model)
{   
    m_tableView->setModel(model);
            
    m_tableView->resizeColumnsToContents();
 }
