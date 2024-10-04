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
    color: "#e8fff8"

    visible: true
    title: qsTr("Text analiser")
    ColumnLayout{
        anchors.centerIn: parent
        Gistagramm{
            id: gistagrammID
            widthP: rootID.width / 2.4 //250
            heightP: rootID.height / 40 //20
            Layout.preferredHeight: rootID.height / 1.8 //450
            Layout.preferredWidth: rootID.width / 2.4
            Layout.alignment: Qt.AlignCenter
            opacity: 0.0
        }
        ProgressBar{
            id: progressbarID
            Layout.preferredHeight: rootID.height / 25
            Layout.preferredWidth: rootID.width / 2.4
            Layout.alignment: Qt.AlignCenter
            from: 0
            to: pa.maxlenght
            value: pa.curentbyte
            opacity: 0.0
            Text{
                id: pbID
                x: progressbarID.width / 2
                y: 0
                font.pixelSize : progressbarID.height / 1.5
                text: pa.pbtext
            }
        }
        Button{
            id: openBID
            Layout.preferredHeight: rootID.height / 25
            Layout.preferredWidth: rootID.width / 6
            Layout.alignment: Qt.AlignCenter
            text: "Открыть"
            enabled: true
            onClicked: {
                fileDialog.visible = true;
            }
        }
        Button{
            id: startBID
            Layout.preferredHeight: rootID.height / 25
            Layout.preferredWidth: rootID.width / 6
            Layout.alignment: Qt.AlignCenter
            text: "Старт"
            enabled: false
            onClicked: {
                pa.startCalculate();
                gistagrammID.opacity = 1;
                progressbarID.opacity = 1;
                startBID.enabled = false;
                pauseBID.enabled = true;
                cancelBID.enabled = true;
            }
        }
        Button{
            id: pauseBID
            Layout.preferredHeight: rootID.height / 25
            Layout.preferredWidth: rootID.width / 6
            Layout.alignment: Qt.AlignCenter
            text: pa.namePB
            enabled: false
            onClicked: {
                pa.pauseCalculate();
            }
        }
        Button{
            id: cancelBID
            Layout.preferredHeight: rootID.height / 25
            Layout.preferredWidth: rootID.width / 6
            Layout.alignment: Qt.AlignCenter
            text: "Отмена"
            enabled: false
            onClicked: {
                pa.cancelCalculate();
                gistagrammID.opacity = 0;
                progressbarID.opacity = 0;
                openBID.enabled = true;
                startBID.enabled = false;
                pauseBID.enabled = false;
                cancelBID.enabled = false;
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
            openBID.enabled = false;
            startBID.enabled = true;
            cancelBID.enabled = true;
        }
        onRejected: {
            console.log("Canceled")
        }
        Component.onCompleted: visible = false
    }

}
