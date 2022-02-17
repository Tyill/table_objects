
#include "central_widget.h"
#include "table_widget.h"

CentralWidget::CentralWidget(QWidget *parent):
    QMainWindow(parent),
    m_tableWidget(new TableWidget(this)){

    setObjectName("CentralWidget");     // для стилей qss (которых в проекте нет)
    
    this->setWindowTitle("TableObjects");
    
    setCentralWidget(m_tableWidget);
}