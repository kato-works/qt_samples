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
    canDevice->setConfigurationParameter(QCanBusDevice::CanFdKey, true);
    canDevice->connectDevice();
}

void CanController::processReceivedFrames()
{
    // このあとの演習で、バッファから読み込む際の準備
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
