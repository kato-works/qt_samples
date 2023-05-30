#include "cancontroller.h"
#include "canmodel.h"

CanController::CanController(CanModel *model, QObject *parent) : QObject(parent)
{
    c_model = model;
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
    std::reverse(msg.begin(), msg.end());
    c_model->receivedMessage(id, msg);
}
