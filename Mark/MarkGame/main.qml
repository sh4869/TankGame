import QtQuick 2.2
import QtQuick.Window 2.1

Window {
    visible: true
    width: 1000
    height: 600

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}
