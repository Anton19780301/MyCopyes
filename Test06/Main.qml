import QtQuick
import QtQuick.Controls 2.15

Window {
    id: rootID
    width: 400
    height: 620
    maximumHeight : 620
    maximumWidth : 400
    minimumHeight : 100
    minimumWidth : 100

    visible: true
    title: qsTr("Калькулятор с сюрпризом")

    //TODO : сделать красивый задний фон
    Rectangle{
        id: rectusID
        width: rootID.width
        height: rootID.height
        radius: 10
        visible: true
        gradient: Gradient {
                GradientStop { position: 0.0; color: "purple" }
                GradientStop { position: 0.7; color: "green" }
                GradientStop { position: 1.0; color: "blue" }
            }
        Calculator{
            itemWidth: rootID.width
            itemHeight: rootID.height
        }
    }

    Rectangle{
        id: secretRectusID
        width: rootID.width
        height: rootID.height
        radius: 10
        visible: false
        gradient: Gradient {
                GradientStop { position: 0.0; color: "purple" }
                GradientStop { position: 0.7; color: "green" }
                GradientStop { position: 1.0; color: "blue" }
            }
        Label{
            text: "Секретное меню"
            anchors.centerIn: parent.Center
            anchors.top: parent.top
            font.pixelSize: 20
        }
        Button{
            width: 50
            height: 20
            x: rootID.width/2 - 25
            y: rootID.height - 20
            text: "НАЗАД"
            onClicked: {
                rectusID.visible = true;
                secretRectusID.visible = false;
            }
        }

    }

    Connections{
        target: cl
        function onOpen() {
            rectusID.visible = false;
            secretRectusID.visible = true;
        }
    }
}
