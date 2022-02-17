#pragma once

#include <QWidget>

class QTableView;
class QAbstractTableModel;

class TableWidget : public QWidget
{
    Q_OBJECT
public:        
    explicit TableWidget(QWidget* parent = nullptr);
    virtual ~TableWidget() = default;

    void setModel(QAbstractTableModel*);
    
private:
    QTableView* m_tableView = nullptr;
};

