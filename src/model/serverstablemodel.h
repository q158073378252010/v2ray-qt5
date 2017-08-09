#ifndef SERVERSTABLEMODEL_H
#define SERVERSTABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "serveritemmodel.h"


class ServersTableModel: public QAbstractTableModel
{
    Q_OBJECT
public:
    ServersTableModel(QObject *parent = 0);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    void appendServer();

private:
    QList<ServerItemModel*> items;
};

#endif // SERVERSTABLEMODEL_H
