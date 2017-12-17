#include "serveritemmodel.h"

ServerItemModel::ServerItemModel(VmessConfigModel* server,QObject *parent) : QObject(parent)
{
    this->server = server;
    //this->TypeName = typeid(server).name();
}

QVariant ServerItemModel::data(int column, int role) const{
    if(!server){
        return QVariant();
    }
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch (column) {
        case 0://name
            return QVariant(server->Remarks);
        case 1://server
            return QVariant(server->Address);
        case 2://status
            return server->isRunning() ? QVariant(tr("Connected"))
                                    : QVariant(tr("Disconnected"));
        case 3://latency
            if (role == Qt::DisplayRole) {
                return QVariant(server->getLatency());
            } else {
                return QVariant(server->getLatency());
            }
        case 4://local port
            return QVariant(server->LocalPort);
        case 5://last used
            return QVariant(server->LastUseTime.toString());
        default:
            return QVariant();
        }
    } else if (role == Qt::FontRole) {
        QFont font;
        font.setBold(server->isRunning());
        return QVariant(font);
    }

    return QVariant();
}
