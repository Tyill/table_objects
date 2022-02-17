#include "logic.h"
#include "model/model.h"

Logic::Logic(CentralWidget* centralWidget, QObject* parent) :
    QObject(parent),
    m_centralWidget(centralWidget),
    m_model(new Model(this))
{ 
    
}

Logic::~Logic() 
{   
    
}

