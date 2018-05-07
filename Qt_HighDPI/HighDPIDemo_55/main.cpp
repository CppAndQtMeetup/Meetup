#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlFileSelector>
#include <QScreen>

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    /********************************************************
     * Image Version-Management in Qt 5.5
     ********************************************************/
//    QQmlFileSelector* selector = new QQmlFileSelector(&engine);
//    QStringList *extraFileSelector = new QStringList();

//    if (app.primaryScreen()->logicalDotsPerInch() > 300) {
//        extraFileSelector->append("high");
//    } else if (app.primaryScreen()->logicalDotsPerInch() > 100) {
//        extraFileSelector->append("middle");
//    }

//    selector->setExtraSelectors(*extraFileSelector);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
