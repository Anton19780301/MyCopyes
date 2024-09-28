import QtQuick
import Test06

Item {
    property string indicatorText: cl.indiacatorCondition
    property string memprutText: cl.memoryCondition
    property string actionText: cl.actionCondition
    property int itemWidthIndi: 0
    property int itemHeightIndi: 0

    width: itemWidthIndi
    height: itemHeightIndi

    Rectangle{
        id: indicatorID
        width: itemWidthIndi
        height: itemHeightIndi
        color: "#bbffe5"
        radius: itemWidthIndi / 40
        border{
            color: "darkgray"
            width: itemWidthIndi / 80
        }
        Text{
            id: indicatorTextID
            anchors.right: parent.right
            anchors.centerIn: parent.Center
            anchors.bottom: parent.bottom
            anchors.margins: itemWidthIndi / 80
            text: indicatorText
            font.pixelSize: indicatorID.width / 10
        }
        Rectangle{
            id: memoryID
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.margins: itemWidthIndi / 80
            width: itemWidthIndi / 2
            height: itemHeightIndi / 3
            visible: true
            color: "#bbffe5"
            radius: itemWidthIndi / 160
            border{
                color: "darkgray"
                width: itemWidthIndi / 300
            }
            Text{
                id: memoryTextID
                anchors.left: parent.left
                anchors.centerIn: parent.Center
                anchors.margins: itemWidthIndi / 80
                text: memprutText
                font.pixelSize: itemHeightIndi / 4
            }
        }
        Rectangle{
            id: actionID
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.margins: itemWidthIndi / 80
            width: itemWidthIndi / 10
            height: itemHeightIndi / 3
            visible: true
            color: "#bbffe5"
            radius: itemWidthIndi / 160
            border{
                color: "darkgray"
                width: itemWidthIndi / 300
            }
            Text{
                id: actionTextID
                anchors.left: parent.left
                anchors.centerIn: parent.Center
                anchors.margins: itemWidthIndi / 80
                text: actionText
                font.pixelSize: itemHeightIndi / 4
            }
        }
    }
}
