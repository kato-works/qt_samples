#ifndef SAMPLEMODEL_H
#define SAMPLEMODEL_H

#include <QObject>

class SampleModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int mouseX MEMBER mouseX NOTIFY mouseXChanged)
    Q_PROPERTY(int mouseY MEMBER mouseY NOTIFY mouseYChanged)

public:
    explicit SampleModel(QObject *parent = nullptr);
    void setMouseX(int x);
    void setMouseY(int y);

private:
    int mouseX;
    int mouseY;

signals:
    void mouseXChanged(int mouseX);
    void mouseYChanged(int mouseY);

public slots:

};

#endif // SAMPLEMODEL_H
