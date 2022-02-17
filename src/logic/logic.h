#pragma once

#include <QObject>

class CentralWidget;
class Model;
    
class Logic : public QObject
{   
    Q_OBJECT
public:
    explicit Logic(CentralWidget* centralWidget, QObject* parent = nullptr);
    ~Logic();
            
private:
    CentralWidget* m_centralWidget = nullptr;
    Model* m_model = nullptr;
};

