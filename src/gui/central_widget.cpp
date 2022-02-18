
#include "central_widget.h"
#include "table_widget.h"

#include <QVBoxLayout>

CentralWidget::CentralWidget(QWidget *parent):
    QWidget(parent),
    m_tableWidget(new TableWidget(this)){

    setObjectName("CentralWidget");
    
    setWindowTitle("TableObjects");
    
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins({});
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    mainLayout->addWidget(m_tableWidget);
}