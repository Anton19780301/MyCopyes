import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import Test09

Window {
    id: rootID
    height: 800
    width: 600
    maximumHeight : 800
    maximumWidth : 600
    minimumHeight : 80
    minimumWidth : 60

    visible: true
    title: qsTr("Text calculate")
    ColumnLayout{
        anchors.centerIn: parent
        Gistagramm{
            id: gistagrammID
            widthP: rootID.width / 2.4 //250
            heightP: rootID.height / 40 //20
            Layout.preferredHeight: rootID.height / 1.8 //450
            Layout.preferredWidth: rootID.width / 2.4
            Layout.alignment: Qt.AlignCenter
        }
        CoolProgressBar{
            id: progressbarID
            Layout.preferredHeight: rootID.height / 25
            Layout.preferredWidth: rootID.width / 2.4
            Layout.alignment: Qt.AlignCenter
        }
        Button{
            Layout.preferredHeight: rootID.height / 25
            Layout.preferredWidth: rootID.width / 6
            Layout.alignment: Qt.AlignCenter
            text: "Открыть"
            onClicked: {
                fileDialog.visible = true;
            }
        }
        Button{
            Layout.preferredHeight: rootID.height / 25
            Layout.preferredWidth: rootID.width / 6
            Layout.alignment: Qt.AlignCenter
            text: "Старт"
            onClicked: {
                pa.startCalculate();
            }
        }
        Button{
            Layout.preferredHeight: rootID.height / 25
            Layout.preferredWidth: rootID.width / 6
            Layout.alignment: Qt.AlignCenter
            text: pa.namePB
            onClicked: {
                pa.pauseCalculate();
            }
        }
        Button{
            Layout.preferredHeight: rootID.height / 25
            Layout.preferredWidth: rootID.width / 6
            Layout.alignment: Qt.AlignCenter
            text: "Отмена"
            onClicked: {
                pa.cancelCalculate();
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Укажите файл"
        options : FileDialog.ReadOnly | FileDialog.DontResolveSymlinks
        nameFilters: ["Text files (*.txt)", "HTML files (*.html *.htm)"]
        onAccepted: {
            pa.openFile(fileDialog.selectedFile);
        }
        onRejected: {
            console.log("Canceled")
        }
        Component.onCompleted: visible = false
    }

}
