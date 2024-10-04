import QtQuick
import Test09

Item {
    property int widthP: 0
    property int heightP: 0

    Column{
        spacing: heightP / 2
        Repeater{
            model: dataZ
            Rectangle{
                property string wordP: modelData.word
                property int countP: modelData.count

                id: rectangleID
                visible: true
                color: Qt.rgba(Math.random(),Math.random(),Math.random(),1) //"#2980b9"
                width : widthP * countP/pa.len
                height: heightP
                radius: heightP / 4
                Text{
                    id: textWordID;
                    font.pixelSize : heightP / 1.8
                    text: wordP + " : " + countP
                }
                Component.onCompleted: {
                    //if (modelData.word === "" && modelData.count === 0) textWordID.text = ""
                }
            }
        }
    }
}
