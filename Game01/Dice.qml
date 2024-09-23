import QtQuick

Item {
    id: rootID
    property var game: null
    property var diceModel: null

    width: 400
    height: 400

    Grid{
        id: gridID
        Repeater {
            model: diceModel
            Rectangle{
                id: rectusID
                property string textName: modelData.toString()
                width: 100
                height: 100
                color: "lightgreen"
                border{
                    color: "black"
                    width: 5
                }
                radius: 10
                Text {
                    id: textID
                    anchors.centerIn: parent
                    font.pixelSize: 20
                    text: qsTr(textName)
                }

                MouseArea{
                    anchors.fill: parent
                    onClicked:{
                        game.tryMove(textID.text);
                    }
                }

                Component.onCompleted: {
                    if (textName === "0") rectusID.opacity = 0.00
                }
            }
        }
    }
}
