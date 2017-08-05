#ifndef SERVERSTABLEMODEL_H
#define SERVERSTABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "serverconfigmodel.h"


class ServersTableModel: public QAbstractTableModel
{
    Q_OBJECT
public:
    ServersTableModel(QObject *parent = 0);
    void appendServer();
};

#endif // SERVERSTABLEMODEL_H
