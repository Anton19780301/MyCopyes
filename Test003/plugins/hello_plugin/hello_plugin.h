#pragma once
#include <QObject>
#include "plugin_interface.h"

// Плагин ОБЯЗАН наследоваться от QObject (первым) и от интерфейса (вторым)
class HelloPlugin : public QObject, public PluginInterface {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PluginInterface_iid) // Регистрирует плагин в Qt
    Q_INTERFACES(PluginInterface)               // Указывает, какой интерфейс реализован

public:
    explicit HelloPlugin(QObject *parent = nullptr) : QObject(parent) {}
    
    QString name() const override { return "Hello-Plugin v1.0"; }
    void execute() override;
};
