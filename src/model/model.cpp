#include "model.h"


Model::Model(QObject* parent):
    QAbstractTableModel(parent)
{
    
}

void Model::addObject(const Object& obj)
{
    beginInsertRows(QModelIndex(), m_objects.size(), m_objects.size());
    
    m_objects.insert(obj.name, obj);

    for (auto& k : obj.data.keys()) {
        m_dataKeys.insert(k);
    }

    endInsertRows();
}

Qt::ItemFlags Model::flags(const QModelIndex& index) const
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
}

int Model::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }    
    return m_dataKeys.size();
}

int Model::columnCount(const QModelIndex& parent) const
{
    return m_objects.size();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical) {
        if (role == Qt::DisplayRole) {
            return (0 <= section) && (section < rowCount()) ? *(m_dataKeys.begin() + section) : QVariant();
        }
    }
    else {
        if (role == Qt::DisplayRole) {
            return (0 <= section) && (section < columnCount()) ? (m_objects.begin() + section)->name : QVariant();
        }
    }
    return{};
}

QVariant Model::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }
      
    if (role == Qt::DisplayRole) {

        int row = index.row();
        if ((0 > row) || (row >= rowCount())) {
            return QVariant();
        }

        const QString& key = *(m_dataKeys.begin() + row);

        int col = index.column();
        if ((0 > col) || (col >= columnCount())) {
            return QVariant();
        }

        auto obj = m_objects.begin() + col;
        return obj->data.contains(key) ? (m_objects.begin() + col)->data[key] : QVariant();
    }
    return QVariant();
}

bool Model::setData(const QModelIndex& index, const QVariant& value, int role)
{   
    if (role != Qt::EditRole) {
        return QAbstractTableModel::setData(index, value, role);
    }

    int row = index.row();
    if ((0 > row) || (row >= rowCount())) {
        return false;
    }

    const QString& key = *(m_dataKeys.begin() + row);

    int col = index.column();
    if ((0 > col) || (col >= columnCount())) {
        return false;
    }
        
    auto text = value.toString();

    auto obj = m_objects.begin() + col;

    bool ok = false;

    if (obj->data.contains(key)) {           // такой ключ есть, проверяем подходит ли значение
        switch (obj->data[key].type()){
        case QVariant::Type::Bool: 
            if ((text == "true") || (text == "false")) {
                obj->data[key] = text == "true";
                ok = true;
            }
            break;
        case QVariant::Type::Double: {
            bool isDbl = false;
            double val = text.toDouble(&isDbl);
            if (isDbl) {
                obj->data[key] = val;
                ok = true;
            }
            break;
        }
        case QVariant::Type::String:
            obj->data[key] = text;
            ok = true;
            break;
        default:
            break;
        }              
    }
    else if (!value.toString().isEmpty()) {  // такого ключа нет - добавляем с учетом типа
        if ((text == "true") || (text == "false")) {
            obj->data[key] = text == "true";
            ok = true;
        }
        else {
            bool isDbl = false;
            double val = text.toDouble(&isDbl);
            if (isDbl) {
                obj->data[key] = val;
            }
            else {
                obj->data[key] = text;
            }
            ok = true;
        }
    }
    
    return ok;
}