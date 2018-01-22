#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "personviewmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<PersonViewModel>("PersonViewModel", 1, 0, "Person");

    PersonViewModel cppPerson;
    PersonViewModel cppPersonCopy;
    QObject::connect(&cppPerson, &PersonViewModel::vornameChanged, &cppPersonCopy, &PersonViewModel::setVorname);
    QObject::connect(&cppPerson, &PersonViewModel::nameChanged, &cppPersonCopy, &PersonViewModel::setName);
    QObject::connect(&cppPerson, &PersonViewModel::alterChanged, &cppPersonCopy, &PersonViewModel::setAlter);
    QObject::connect(&cppPerson, &PersonViewModel::geschlechtChanged, &cppPersonCopy, &PersonViewModel::setGeschlecht);

    cppPerson.setVorname("Max");
    cppPerson.setName("Mustermann");
    cppPerson.setGeschlecht(PersonViewModel::Maennlich);

    cppPerson.setProperty("alter", 30);

    QMetaObject::invokeMethod(&cppPerson, "feiertGeburtstag");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("cppPerson", &cppPerson);
    engine.rootContext()->setContextProperty("cppPersonCopy", &cppPersonCopy);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
