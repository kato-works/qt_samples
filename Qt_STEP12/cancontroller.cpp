#include "cancontroller.h"
#include "canmodel.h"

CanController::CanController(CanModel *model, QObject *parent) : QObject(parent)
{
    c_model = model;

    QString errorString;
    canDevice = QCanBus::instance()->createDevice(
                    QStringLiteral("socketcan"),
                    "vcan0",
                    &errorString
                );
    if (!canDevice) {
        qDebug("接続失敗: %s", qPrintable(errorString));
        return;
    }

    connect(
        canDevice,
        &QCanBusDevice::framesReceived,
        this,
        &CanController::processReceivedFrames
    );

    canDevice->setConfigurationParameter(QCanBusDevice::CanFdKey, true);
    canDevice->connectDevice();
}

void CanController::processReceivedFrames()
{
    while (canDevice->framesAvailable()) {
        const QCanBusFrame frame = canDevice->readFrame();
        QString frameId;
        QString frameMsg;
        if (frame.frameType() == QCanBusFrame::ErrorFrame){
            frameId = "ERROR";
            frameMsg = canDevice->interpretErrorFrame(frame);
            c_model->receivedMessage(frameId, frameMsg);
        } else {
            frameId = QString::number(frame.frameId(),16);
            frameMsg = frame.payload().toHex().toUpper();
        }
        c_model->receivedMessage(frameId, frameMsg);
    }
}

void CanController::sendCanMessage(QString id, QString msg)
{
    qDebug("[CanController] sendCanMsg: (%s, %s)",
           qPrintable(id),
           qPrintable(msg));

    QCanBusFrame frame;
    QByteArray payload = QByteArray::fromHex(msg.toUtf8());

    frame.setFrameId(id.toUInt(nullptr,16));
    frame.setPayload(payload);
    canDevice->writeFrame(frame);
}
