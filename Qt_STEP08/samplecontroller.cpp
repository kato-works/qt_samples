#include <iostream>
#include "samplecontroller.h"
#include "samplemodel.h"

SampleController::SampleController(SampleModel *model, QObject *parent) : QObject(parent)
{
    m_model = model;
}

bool SampleController::initialize(void)
{
    qDebug("[SampleController] initialize.");
    return true;
}

void SampleController::clickedSignalEmitted(int x, int y)
{
    qDebug("[SampleController] clickedSignalEmitted: (%d,%d)", x, y);

    m_model->setMouseX(x);
    m_model->setMouseY(y);
}

bool SampleController::deinitialize(void)
{
    qDebug("[SampleController] deinitialize.");
    return true;
}
