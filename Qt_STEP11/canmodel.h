#ifndef CANMODEL_H
#define CANMODEL_H

#include <QObject>

class CanModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString lastReceivedMessage MEMBER lastReceivedMessage NOTIFY messageReceived)

public:
    explicit CanModel(QObject *parent = nullptr);
    void receivedMessage(QString frameId, QString frameMsg);

private:
    QString lastReceivedMessage;
    QList<QString> receiveLog;

signals:
    void messageReceived(QString lastReceivedMessage);

public slots:

};

#endif // CANMODEL_H
