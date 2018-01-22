import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import PersonViewModel 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Person{
        id: personQML
        vorname: "Jane"
        name: "Doe"
        alter: 42
        geschlecht: Person.Weiblich
    }

    Column{
        anchors.fill: parent
        anchors.margins: 20
        spacing: 40

        PersonView{
            person: cppPerson
        }

        Text{
            text: "Die Kopie von cppPerson"
        }

        PersonView{
            person: cppPersonCopy
            editable: false
        }

        PersonView{
            person: personQML
        }

        PersonView{
            person: personQML
            editable: false
        }
    }
}
