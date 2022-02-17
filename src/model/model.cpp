#include "model.h"

#include <QSet>

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
        return{};
    }
    if (role == Qt::DisplayRole) {
        return (0 <= section) && (section < columnCount()) ? (m_objects.begin() + section)->name : QVariant();
    }
    return{};
}

QVariant Model::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }
       
    const QString& key = *(m_dataKeys.begin() + index.row());

    if (role == Qt::DisplayRole) {
        return (m_objects.begin() + index.column())->data[key];
    }
    return QVariant();
}
