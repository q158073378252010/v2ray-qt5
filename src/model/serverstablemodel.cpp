#include "serverstablemodel.h"

ServersTableModel::ServersTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{}

QVariant ServersTableModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (orientation == Qt::Vertical || role != Qt::DisplayRole) {
        return QVariant();
    }

    switch (section) {
    case 0:
        return QVariant(tr("Name"));
    case 1:
        return QVariant(tr("Server"));
    case 2:
        return QVariant(tr("Status"));
    case 3:
        return QVariant(tr("Latency"));
    case 4:
        return QVariant(tr("Local Port"));
    case 5:
        return QVariant(tr("Last Used"));
    default:
        return QVariant();
    }
}

int ServersTableModel::columnCount(const QModelIndex &parent) const{
    return 6;
}

int ServersTableModel::rowCount(const QModelIndex &parent) const{
    return 0;
}

QVariant ServersTableModel::data(const QModelIndex &index, int role) const{
    return QVariant();
}

