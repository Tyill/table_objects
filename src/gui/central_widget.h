
#pragma once

#include <QtWidgets/QMainWindow>

class TableWidget;

class CentralWidget : public QMainWindow{
    Q_OBJECT

public:
    CentralWidget(QWidget *parent = 0);
    ~CentralWidget() = default;
    
private:
    TableWidget* m_tableWidget = nullptr;
};