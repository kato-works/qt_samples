#ifndef CANCONTROLLER_H
#define CANCONTROLLER_H

#include <QtCore>
#include <QWidget>
#include <QCanBus>

#include "canmodel.h"

class CanController : public QObject
{
    Q_OBJECT

public:
    explicit CanController(CanModel *model, QObject *parent = nullptr);
    void processReceivedFrames();

private:
    CanModel *c_model;
    QCanBusDevice *canDevice;

signals:
    void canMsgReceived(QString id, QString msg);

public slots:
    void sendCanMessage(QString id, QString msg);

};

#endif // CANCONTROLLER_H
