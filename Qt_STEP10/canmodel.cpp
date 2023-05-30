#include <time.h>
#include "canmodel.h"

CanModel::CanModel(QObject *parent) : QObject(parent)
{
    lastReceivedMessage = "";
}

QString currentDateTime() {

    struct timespec ts;
    struct tm t;
    int ret;

    ret = clock_gettime(CLOCK_REALTIME, &ts);
    if (ret < 0) {
      perror("clock_gettime fail");
    }

    localtime_r(&ts.tv_sec, &t);

    char buf[32];
    ret = strftime(buf, 32, "%H:%M:%S", &t);
    if (ret == 0) {
      perror("strftime fail");
    }

    char output[32];
    const int msec = ts.tv_nsec / 1000000;
    ret = snprintf(output, 32, "%s.%03d", buf, msec);
    if (ret == 0) {
      perror("snprintf fail");
    }

    return QString::fromStdString(output);
}

void CanModel::receivedMessage(QString frameId, QString frameMsg)
{
    lastReceivedMessage = QString("%1 %2#%3")
            .arg(currentDateTime())
            .arg(frameId)
            .arg(frameMsg);
    emit messageReceived(lastReceivedMessage);
}
