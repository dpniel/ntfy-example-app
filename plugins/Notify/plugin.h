#ifndef NOTIFYPLUGIN_H
#define NOTIFYPLUGIN_H

#include <QQmlExtensionPlugin>

class NotifyPlugin : public QQmlExtensionPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif
