#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "canmodel.h"
#include "cancontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // モデル・コントローラのインスタンス化
    CanModel *canModel = new CanModel(&app);
    CanController *canController = new CanController(canModel, &app);
    // C++側からQML側にオブジェクトを送り込む
    engine.rootContext()->setContextProperty("model001", canModel);
    engine.rootContext()->setContextProperty("controller001", canController);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
