import QtQuick

Window {
    width: 800
    height: 800
    visible: true
    title: qsTr("Minesweeper")
    property color indicatorColor: gc.statecolor

    Column{
        //spacing: 10
        anchors.fill: parent
        Rectangle{
            id: indicatorID
            width: 75
            height: 75
            color: indicatorColor
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            radius: 40
            border{
                color: "black"
                width: 3
            }
        }

        Game{
            id: game
        }
    }

    Rectangle{
        width: 300
        height: 100
        color: "green"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
        radius: 10
        border{
            color: "black"
            width: 3
        }
        Text{
            text: "Рестарт"
            anchors.centerIn: parent
            color: "black"
            font.pixelSize : 25
            MouseArea
            {
                anchors.fill: parent
                onClicked: {
                    gc.reset();
                }
            }
        }
    }
}
