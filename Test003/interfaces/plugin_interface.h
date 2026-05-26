#pragma once
#include <QtPlugin>
#include <QString>

class PluginInterface {
public:
    virtual ~PluginInterface() = default;
    
    // Чисто виртуальные функции, которые обязан реализовать плагин
    virtual QString name() const = 0;
    virtual void execute() = 0;
};

// Строковая метка (IID). Должна быть уникальной!
#define PluginInterface_iid "com.education.QtPluginProject.PluginInterface"

// Регистрируем интерфейс в мета-системе Qt
Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)
