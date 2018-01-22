import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import PersonViewModel 1.0

GridLayout {
    columns: 2
    property variant person
    property bool editable: true

    Text{
        text: "Geschlecht"
        font.bold: true
        color: editable ? "black" : "grey"
    }

    Row{
        spacing: 10

        ExclusiveGroup{ id: geschlecht }
        RadioButton{
            text: "männlich"
            checked: person.geschlecht === Person.Maennlich
            onCheckedChanged: checked ? person.geschlecht = Person.Maennlich : null
            enabled: editable
            exclusiveGroup: geschlecht
        }

        RadioButton{
            id: weiblich
            text: "weiblich"
            checked: person.geschlecht === Person.Weiblich
            onCheckedChanged: checked ? person.geschlecht = Person.Weiblich : null
            enabled: editable
            exclusiveGroup: geschlecht
        }
    }

    Text{
        text: "Vorname"
        font.bold: true
        color: editable ? "black" : "grey"
    }

    TextField{
        text: person.vorname
        onTextChanged: person.vorname = text
        enabled: editable
        textColor: editable ? "black" : "grey"
    }
    Text{
        text: "Name"
        font.bold: true
        color: editable ? "black" : "grey"
    }

    TextField{
        text: person.name
        onTextChanged: person.name = text
        enabled: editable
        textColor: editable ? "black" : "grey"
    }

    Text{
        text: "Alter"
        font.bold: true
        color: editable ? "black" : "grey"
    }

    TextField{
        text: person.alter
        onTextChanged: person.alter = text
        enabled: editable
        textColor: editable ? "black" : "grey"
    }

    Button{
        Layout.fillWidth: true
        text: "feiert Geburtstag"
        onClicked: person.feiertGeburtstag()
        enabled: editable
    }
}
