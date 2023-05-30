#include "samplemodel.h"

SampleModel::SampleModel(QObject *parent) : QObject(parent)
{
    mouseX = 99;
    mouseY = 99;
}

void SampleModel::setMouseX(int x)
{
    qDebug("[SampleController] setMouseX: x=%d", x);
    mouseX = x;
    emit mouseXChanged(mouseX);
}

void SampleModel::setMouseY(int y)
{
    qDebug("[SampleController] setMouseY: y=%d", y);
    mouseY = y;
    emit mouseYChanged(mouseY);
}
