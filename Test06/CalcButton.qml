import QtQuick
import Test06

Rectangle{
    property string textButton: ""
    property int buttonSize: 0

    id: rectusID
    width: buttonSize
    height: buttonSize
    color: "#ceffff"

    radius: buttonSize / 2
    border{
        color: "darkgray"
        width: buttonSize / 20
    }
    Text{
        id: textID
        text: textButton
        font.pixelSize: buttonSize/3
        anchors.centerIn: parent
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            cl.buttonPresed(textButton);
        }
        onPressed: {
            if (textButton === "=") cl.beginFinalCountdown();
        }
        onReleased: {
            if (textButton === "=") cl.stopFinalCountdown();
        }
    }
    Component.onCompleted: {
        if (textButton === "")
        {
            rectusID.enabled = false
            rectusID.opacity = 0
        }
    }
}
