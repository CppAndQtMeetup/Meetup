#ifndef BAR_H
#define BAR_H

#include <QObject>

class Bar : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit Bar(QObject *parent = nullptr);

QString name() const
{
    return m_name;
}

signals:

void nameChanged(QString name);

public slots:
void setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

private:
    QString m_name = "ANONYMOUS";
};

#endif // BAR_H
