import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

Window {
    visible: true

    function dp(pixel){
        return pixel * Screen.logicalPixelDensity * 25.4 / 72;
    }

    Column{
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            text: "Screen.devicePixelRatio: " + Screen.devicePixelRatio
            font.pixelSize: dp(30)
        }

        Text {
            text: "Schriftgröße in Pixel: 30"
            font.pixelSize: dp(30)
        }

        Text {
            text: "Schriftgröße in Punkten: 30"
            font.pointSize: 30
        }

        Image {
            source: "qrc:/Qt.png"
            width: dp(100)
            height: dp(120)
            fillMode: Image.PreserveAspectFit
        }

        Image {
            source: "qrc:/SVG_logo.svg"
            width: dp(100)
            height: dp(120)
            fillMode: Image.PreserveAspectFit
        }
    }
}

