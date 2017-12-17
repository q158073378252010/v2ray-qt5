#ifndef SERVERITEMMODEL_H
#define SERVERITEMMODEL_H

#include <QObject>
#include <QVariant>
#include <QFont>
#include "vmessconfigmodel.h"

class ServerItemModel : public QObject
{
    Q_OBJECT
public:
    explicit ServerItemModel(VmessConfigModel* server,QObject *parent = 0);
    QVariant data(int column,int role) const;

private:
    VmessConfigModel* server;
    //QString TypeName;

signals:

public slots:
};

#endif // SERVERITEMMODEL_H
