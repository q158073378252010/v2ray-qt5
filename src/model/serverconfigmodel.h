#ifndef SERVERCONFIGMODEL_H
#define SERVERCONFIGMODEL_H

#include <QObject>

class ServerConfigModel : public QObject
{
    Q_OBJECT
public:
    explicit ServerConfigModel(QObject *parent = 0);
    //bool isRunning();
    //int getLatency();

signals:

private:
    //bool runningStatus;

public slots:
};

#endif // SERVERCONFIGMODEL_H
