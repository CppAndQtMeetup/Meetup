#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QRect>
#include <QScreen>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // <---

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
