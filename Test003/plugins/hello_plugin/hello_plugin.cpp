#include "hello_plugin.h"
#include <QDebug>

void HelloPlugin::execute() {
    qDebug() << "[Плагин] Привет из динамически загруженного плагина!";
}
