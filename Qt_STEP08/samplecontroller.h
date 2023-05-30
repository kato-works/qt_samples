#ifndef SAMPLECONTROLLER_H
#define SAMPLECONTROLLER_H

#include <QObject>
#include <samplemodel.h>

class SampleController : public QObject
{
    Q_OBJECT

public:
    explicit SampleController(SampleModel *model, QObject *parent = nullptr);
    static bool initialize(void);
    static bool deinitialize(void);

private:
    SampleModel *m_model;

public slots:
    void clickedSignalEmitted(int x, int y);

};

#endif // SAMPLECONTROLLER_H
