import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Window 2.14

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Qt STEP09")

    signal sendCanMessage(string frameId, string frameMsg)

    Item {
        id: canModel
        property string receiveLog: "value"
    }

    Label {
        id: recvLabel
        anchors.top: parent.top
        text: "Received CAN frames:"
    }

    Rectangle {
        id: recvTextView
        width: 600
        height: 350
        anchors.top: recvLabel.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        border.color: "blue"

        ScrollView {
            id: view
            anchors.fill: parent
            TextArea {
                id: receiveLog
                text: canModel.receiveLog
            }
        }
    }

    Label {
        id: sendLabel
        anchors.top: recvTextView.bottom
        anchors.topMargin: 20
        text: "Send CAN Frame:"
    }

    Row {
        id: sendRow
        anchors.top: sendLabel.bottom
        anchors.horizontalCenter: recvTextView.horizontalCenter
        spacing: 5

        Column {
            Label {
                text: "Frame ID:"
            }
            Rectangle {
                width: 100
                height: 30
                border.color: "blue"
                TextEdit {
                    id: frameId
                    verticalAlignment: TextEdit.AlignVCenter
                    anchors.fill: parent
                    text: "123"
                }
            }
        }

        Column {
            Label {
                text: "Frame message:"
            }
            Rectangle {
                id: frameMsgTextEdit
                width: 400
                height: 30
                border.color: "blue"
                TextEdit {
                    id: frameMsg
                    verticalAlignment: TextEdit.AlignVCenter
                    anchors.fill: parent
                    text: "123456"
                }
            }
        }

        Button {
            anchors.bottom: sendRow.bottom
            height: 30
            text: "Send"
            onClicked: {
                sendCanMessage(frameId.text, frameMsg.text);
            }
        }
    }
}
