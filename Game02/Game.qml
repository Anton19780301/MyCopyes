import QtQuick
import Game02

Item {
    id: root
    width: 500
    height: 500
    anchors.centerIn: parent

    property int xMAX: gc.xmax
    property int yMAX: gc.ymax

    Grid{
        anchors.fill: parent
        columns: xMAX
        rows: yMAX
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
                width: 500/xMAX
                height: 500/yMAX
                color: "white"
                //radius: 5
                border{
                    color: "darkgray"
                    width: 1
                }

                //сделать управляемым моделью
                // Image{
                //     id: bombID
                //     visible: rectusVisible
                //     anchors.fill: parent
                //     source: "qrc://Game02/Images/Images/bomb.png"
                // }

                Text{
                    id: textID
                    text: modelData.name //""
                    anchors.centerIn: parent
                }

                Rectangle{
                    id: rectusMaskID
                    anchors.centerIn: parent
                    width: 500/xMAX
                    height: 500/yMAX
                    color: rectusColor
                    radius: 2
                    visible: rectusVisible
                    border{
                        color: "black"
                        width: 1
                    }
                    Image{
                        anchors.fill: parent
                        source: "qrc://Game02/Images/Images/dice.png"
                    }

                    Rectangle{
                        anchors.top: parent.top
                        anchors.topMargin: 500/yMAX/5
                        anchors.left: parent.left
                        anchors.leftMargin: 500/xMAX/5
                        width: 500/xMAX/10
                        height: 500/yMAX/1.5
                        color: "black"
                        visible: flagMarker
                    }
                    Rectangle{
                        id: flagMarkerID
                        anchors.top: parent.top
                        anchors.topMargin: 500/yMAX/5
                        anchors.left: parent.left
                        anchors.leftMargin: 500/xMAX/5
                        width: 500/xMAX/1.7
                        height: 500/yMAX/2.5
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
