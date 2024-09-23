import QtQuick
import Game01

Item {
    GameCalulate{
        id: gccpp
    }

    property var modelGame:  gccpp.getModel().split(",",16)
    property var dicePlace: null
    property int moveDirection: 0

    id: gameID
    width: 400
    height: 400
    anchors.centerIn: parent

    signal tryMove(string ids)
    signal move(string ids)
    signal reload()

    function checkMoveDirectionS(ids){
        moveDirection = gccpp.moveLocation(ids);
        if(moveDirection != 0) moveS(ids)
    }

    function moveS(ids){
        gccpp.move(ids)
        modelGame = gccpp.getModel().split(",",16)
    }

    function reloadS(){
        gccpp.blendGamePlace()
        modelGame = gccpp.getModel().split(",",16)
    }

    Column{
        id: columnID
        Dice{
            game: gameID
            diceModel: modelGame
        }

        Rectangle{
            width: 400
            height: 100
            radius: 10
            border{
                color: "black"
                width: 10
            }
            color: "red"
            Text{
                anchors.centerIn: parent
                color: "black"
                font{
                    pointSize: 50
                }
                text: "Reload"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    gameID.reload()
                }
            }
        }
    }

    Component.onCompleted: {
        gameID.tryMove.connect(gameID.checkMoveDirectionS)
        gameID.reload.connect(gameID.reloadS)
    }
}
