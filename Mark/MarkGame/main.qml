import QtQuick 2.2
import QtQuick.Window 2.1

Window {
    id: root
    visible: true
    width: 600; height: 400

    Text {
        x: 100
        y: 100
        text: qsTr("Hello World")

    }
    Image{
        x: 10
	 	y: 10
	    source: "file:///home/sh4869/Pictures/003.png"  
	}

}
