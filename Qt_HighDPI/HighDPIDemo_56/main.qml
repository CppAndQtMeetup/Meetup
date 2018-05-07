import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

Window {
    visible: true


    Column{
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            text: "Screen.devicePixelRatio: " + Screen.devicePixelRatio
            font.pixelSize: 30
        }

        Text {
            text: "Schriftgröße in Pixel: 30"
            font.pixelSize: 30
        }

        Text {
            text: "Schriftgröße in Punkten: 30"
            font.pointSize: 30
        }

        Image {
            source: "qrc:/Qt.png"
            width: 100
            height: 120
            fillMode: Image.PreserveAspectFit
        }

        Image {
            source: "qrc:/SVG_logo.svg"
            width: 100
            height: 120
            fillMode: Image.PreserveAspectFit
        }
    }
}

