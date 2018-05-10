#ifndef NOTIFY_H
#define NOTIFY_H

#include <QObject>
#include <QDBusConnection>
#include <QJsonObject>


class Notify: public QObject {
    Q_OBJECT

public:
    explicit Notify(QObject *parent = Q_NULLPTR);
    ~Notify() = default;


    // Send a notification
    Q_INVOKABLE bool send(const QJsonObject &message);
    // Update a notification
    Q_INVOKABLE bool update(const QString &tag, const QJsonObject &message);

    Q_INVOKABLE bool hasTag(const QString &tag);
    Q_INVOKABLE bool clearPersistent(const QString &tag);
    Q_INVOKABLE bool updateCount(const QString &tag = QString(), const bool remove = false);

private:
    QByteArray makePath(const QString &appId);
    QStringList getPersistent();

    QDBusConnection m_conn;
    QStringList m_tags;

};

#endif
