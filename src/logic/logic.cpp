#include "logic.h"
#include "model/model.h"
#include "gui/central_widget.h"
#include "gui/table_widget.h"


Logic::Logic(CentralWidget* centralWidget, QObject* parent) :
    QObject(parent),
    m_centralWidget(centralWidget),
    m_model(new Model(this))
{     
    Object obj1("obj1", { { "key1", QVariant(true) },
                          { "key2", QVariant(123)  },
                          { "key3", QVariant("str") }, });
    m_model->addObject(obj1);

    Object obj2("obj2", { { "key3", QVariant(false) },
                          { "key4", QVariant() },
                          { "key5", QVariant("str") }, });
    m_model->addObject(obj2);

    Object obj3("obj3", { { "key6", QVariant() },
                          { "key7", QVariant(123) },
                          { "key2", QVariant() }, });
    m_model->addObject(obj3);
  
    auto table = m_centralWidget->findChild<TableWidget*>("TableWidget");

    table->setModel(m_model);

}

Logic::~Logic() 
{   
    
}

