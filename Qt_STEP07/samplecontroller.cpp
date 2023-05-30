#include <iostream>
#include "samplecontroller.h"

SampleController::SampleController(QObject *parent) : QObject(parent)
{
}

bool SampleController::initialize(void)
{
    qDebug("[SampleController] initialize.");
    return true;
}

void SampleController::clickedSignalEmitted(int x, int y)
{
    qDebug("[SampleController] clickedSignalEmitted: (%d, %d)", x, y);
}

bool SampleController::deinitialize(void)
{
    qDebug("[SampleController] deinitialize.");
    return true;
}
