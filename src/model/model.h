#pragma once

#include <QAbstractTableModel>
#include <QSet>

struct Object {
    QString name;
    QMap<QString, QVariant> data;

    Object(const QString& _name, const QMap<QString, QVariant>& _data) :
        name(_name), data(_data) {}
};

class Model : public QAbstractTableModel {
    Q_OBJECT
public:
  
    explicit Model(QObject *parent = nullptr);
    virtual ~Model() = default;
       
    void addObject(const Object&);
   
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    
protected:
    QMap<QString, Object> m_objects;
    QSet<QString> m_dataKeys;
};
