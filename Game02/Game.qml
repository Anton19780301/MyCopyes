import QtQuick
import Game02

Item {
    id: root
    width: 600
    height: 600
    anchors.centerIn: parent

    Grid{
        anchors.fill: parent
        columns: 10
        rows: 10
        Repeater{
            model: dataZ
            Rectangle{
                property bool rectusVisible: modelData.visible
                property string rectusTytle: modelData.name
                property color rectusColor: "lightblue"
                property int rectusX: modelData.xID
                property int rectusY: modelData.yID
                property bool flagMarker: modelData.flagMarker

                id: rectusID
                width: 50
                height: 50
                color: "white"
                radius: 5
                border{
                    color: "black"
                    width: 2
                }

                Text{
                    id: textID
                    text: modelData.name //""
                    anchors.centerIn: parent
                }

                Rectangle{
                    id: rectusMaskID
                    anchors.centerIn: parent
                    width: 50
                    height: 50
                    color: rectusColor
                    radius: 5
                    visible: rectusVisible
                    border{
                        color: "black"
                        width: 2
                    }

                    Rectangle{
                        anchors.top: parent.top
                        anchors.topMargin: 10
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        width: 5
                        height: 30
                        color: "grey"
                        visible: flagMarker
                    }
                    Rectangle{
                        id: flagMarkerID
                        anchors.top: parent.top
                        anchors.topMargin: 10
                        anchors.left: parent.left
                        anchors.leftMargin: 15
                        width: 25
                        height: 20
                        color: "red"
                        visible: flagMarker
                    }

                    MouseArea{
                        acceptedButtons: Qt.LeftButton | Qt.RightButton
                        anchors.fill: parent
                        onClicked: {
                            if (mouse.button === Qt.LeftButton && !flagMarker)
                            {
                                gc.click(rectusX,rectusY);
                            }
                            else if (mouse.button === Qt.RightButton)
                            {
                                gc.markFlag(rectusX,rectusY);
                            }
                        }
                    }
                }
            }
        }
    }
}
