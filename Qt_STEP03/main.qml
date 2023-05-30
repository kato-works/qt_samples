import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    /**
     * Hello QML表示エリア
     */
    Text {
        id: text001
        text: qsTr("Hello World")
        anchors.horizontalCenter: parent.horizontalCenter
        y: 100
        font.pointSize: 32
    }

    /**
     * ボタン
     */
    Rectangle {
        id: button001
        width: 200
        height: 50
        anchors.horizontalCenter: parent.horizontalCenter
        y: 200
        color: "blue"
        Text {
            font.pointSize: 24
            text: qsTr("PUSH")
            anchors.horizontalCenter: parent.horizontalCenter
            color: "white"
        }
        MouseArea {
            anchors.fill: parent
            onPressed: {
                // マウスの位置情報をコンソールに出力
                console.log(`button001.onPressed mouseX=${mouseX}, mouseY=${mouseY}`);
                // 日付を"text001"に設定
                let d = new Date();
                let time_string = d.getHours() + ':'
                    + ('0' + d.getMinutes()).slice(-2) + ":" + ('0' + d.getSeconds()).slice(-2);
                text001.text = time_string;
            }
        }
    }
}
