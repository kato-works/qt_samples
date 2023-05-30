#ifndef SAMPLECONTROLLER_H
#define SAMPLECONTROLLER_H

#include <QObject>

class SampleController : public QObject
{
    Q_OBJECT

public:
    explicit SampleController( QObject *parent = nullptr);
    static bool initialize(void);
    static bool deinitialize(void);

public slots:
    void clickedSignalEmitted(int x, int y);

};

#endif // SAMPLECONTROLLER_H
