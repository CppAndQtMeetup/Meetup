#ifndef PERSONVIEWMODEL_H
#define PERSONVIEWMODEL_H

#include <QObject>
#include "person.h"

class PersonViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString vorname READ vorname WRITE setVorname NOTIFY vornameChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int alter READ alter WRITE setAlter NOTIFY alterChanged)
    Q_PROPERTY(Geschlecht geschlecht READ geschlecht WRITE setGeschlecht NOTIFY geschlechtChanged)

public:
    explicit PersonViewModel(QObject *parent = nullptr);

    enum Geschlecht{
        Unbekannt,
        Maennlich,
        Weiblich
    };
    Q_ENUM(Geschlecht)

    QString vorname() const
    {
        return QString::fromStdString(m_person.vorname);
    }

    QString name() const
    {
        return QString::fromStdString(m_person.name);
    }

    int alter() const
    {
        return m_person.alter;
    }

    Geschlecht geschlecht() const
    {
        return static_cast<Geschlecht>(m_person.geschlecht);
    }

    Q_INVOKABLE void feiertGeburtstag(){
        setAlter(m_person.alter + 1);
    }

signals:
    void vornameChanged(QString vorname);
    void nameChanged(QString name);
    void alterChanged(int alter);
    void geschlechtChanged(Geschlecht geschlecht);

public slots:
    void setVorname(QString vorname)
    {
        if (QString::fromStdString(m_person.vorname) == vorname)
            return;

        m_person.vorname = vorname.toStdString();
        emit vornameChanged(vorname);
    }

    void setName(QString name)
    {
        if (QString::fromStdString(m_person.name) == name)
            return;

        m_person.name = name.toStdString();
        emit nameChanged(name);
    }

    void setAlter(int alter)
    {
        if (m_person.alter == alter)
            return;

        m_person.alter = alter;
        emit alterChanged(alter);
    }

    void setGeschlecht(Geschlecht geschlecht)
    {
        if (m_person.geschlecht == geschlecht)
            return;

        m_person.geschlecht = static_cast<Person::Geschlecht>(geschlecht);
        emit geschlechtChanged(geschlecht);
    }

private:
    Person m_person;
};

#endif // PERSONVIEWMODEL_H
