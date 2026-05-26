#include <QCoreApplication>
#include <QDir>
#include <QPluginLoader>
#include <QDebug>
#include "plugin_interface.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Папка "plugins" рядом с исполняемым файлом приложения
    QDir pluginsDir(QCoreApplication::applicationDirPath());
    if (!pluginsDir.cd("plugins")) {
        qCritical() << "Папка 'plugins' не найдена!";
        return 1;
    }

    qDebug() << "Ищем плагины в папке:" << pluginsDir.absolutePath();

    // Сканируем файлы в папке плагинов
    const QStringList entries = pluginsDir.entryList(QDir::Files);
    for (const QString &fileName : entries) {
        // Абсолютный путь к файлу плагина (.dll / .so / .dylib)
        QString fullPath = pluginsDir.absoluteFilePath(fileName);
        
        // Создаем загрузчик Qt
        QPluginLoader loader(fullPath);
        QObject *pluginInstance = loader.instance();

        if (pluginInstance) {
            // Приводим базовый QObject к нашему кастомному интерфейсу
            auto *plugin = qobject_cast<PluginInterface*>(pluginInstance);
            if (plugin) {
                qDebug() << "\nУспешно найден плагин:" << plugin->name();
                qDebug() << "Вызываем метод execute()...";
                plugin->execute(); // Запуск логики плагина!
            } else {
                qWarning() << "Экземпляр загружен, но интерфейс PluginInterface не поддерживается.";
            }
        } else {
            qWarning() << "Не удалось загрузить файл:" << fileName 
                       << "Причина:" << loader.errorString();
        }
    }

    return 0;
}
