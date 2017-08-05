#ifndef CONFIGCONTROLLER_H
#define CONFIGCONTROLLER_H

#include <QObject>

#include "src/model/serverconfigmodel.h"
#include "src/model/configmodel.h"

class ConfigController : public QObject
{
    Q_OBJECT
private:
    explicit ConfigController(QObject *parent = 0);
    explicit ConfigController(const QString &configuration, QObject *parent = 0);
    ~ConfigController();
    ConfigController(const ConfigController&);
    ConfigController& operator=(const ConfigController&);
public:
    static ConfigController& getInstance();
    static ConfigController& getInstance(const QString &configuration);

    void addServerConfig(ServerConfigModel *server);

    void loadConfig(const QString &configuration = "");

    void saveConfig();

    ConfigModel *config;

signals:

public slots:
};

#endif // CONFIGCONTROLLER_H
