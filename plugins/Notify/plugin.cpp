#include <QtQml>
#include <QtQml/QQmlContext>

#include "plugin.h"
#include "notify.h"

void NotifyPlugin::registerTypes(const char *uri) {
    //@uri Notify
    qmlRegisterSingletonType<Notify>(uri, 1, 0, "Notify", [](QQmlEngine*, QJSEngine*) -> QObject* { return new Notify; });
}
