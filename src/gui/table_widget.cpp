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

    mainLayout->addWidget(m_tableView, 1);
}

void TableWidget::setModel(QAbstractTableModel* model)
{      
    auto view = m_tableView;
    
    view->setModel(model);

    ///////////////////////////////////////////////////////////////////

    connect(model, &QAbstractItemModel::rowsInserted,
        this, [view, model, this](const QModelIndex&, int first, int last) {
        /* if (m_d->m_autoResizeColumns) {
             view->resizeColumnsToContents();
             updateHeader();
         }*/
    });
    connect(model, &QAbstractItemModel::dataChanged,
        this, [view, model, this](const QModelIndex& torLeft, const QModelIndex& rightBotton, const QVector<int>& roles) {
        //if (m_d->m_autoResizeColumns && (roles.size() > 1)) {  // обновляем размеры, только если прошлая станция изменилась
        //    view->resizeColumnsToContents();
        //    updateHeader();
        //}
        //view->update();
    });   
    
    view->resizeColumnsToContents();
 //   updateHeader();
}
