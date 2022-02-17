
#include "central_widget.h"
#include "table_widget.h"

CentralWidget::CentralWidget(QWidget *parent):
    QMainWindow(parent),
    m_tableWidget(new TableWidget(this)){

    setObjectName("CentralWidget");     // ��� ������ qss (������� � ������� ���)
    
    this->setWindowTitle("TableObjects");
    
    setCentralWidget(m_tableWidget);
}