import QtQuick
import Test06

Item {
    property int itemWidth: 0
    property int itemHeight: 0

    width: itemWidth
    height: itemHeight
    visible: true
    anchors.centerIn: parent.Center
    Column{
        spacing: 10
        Indicators{
            itemWidthIndi: itemWidth
            itemHeightIndi: itemHeight / 6
        }
        Grid{
            columns: 4
            rows: 5
            Repeater{
                model: ["C","=","+","-",
                    1,  2,  3, "*",
                    4,  5,  6, "/",
                    7,  8,  9, ".",
                    "a^b", 0,  "<-"]
                CalcButton{
                    textButton: modelData
                    buttonSize: itemWidth / 4
                }
            }
        }
    }
}
