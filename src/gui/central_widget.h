
#pragma once

#include <QWidget>

class TableWidget;

class CentralWidget : public QWidget{
    Q_OBJECT

public:
    CentralWidget(QWidget *parent = 0);
    ~CentralWidget() = default;
    
private:
    TableWidget* m_tableWidget = nullptr;
};