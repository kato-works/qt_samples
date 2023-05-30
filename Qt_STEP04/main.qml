import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Qt STEP04")

    function mouse_log(x, y){
        // マウスの位置情報をコンソールに出力
        console.log(`button001.onPressed mouseX=${x}, mouseY=${y}`);
    }

    // シグナルと関数を結合
    Component.onCompleted: {
        button001.clicked.connect(text001.update_text);
        button001.clicked.connect(mouse_log);
    }

    /**
     * Hello QML表示エリア
     */
    Text {
        id: text001
        text: qsTr("Hello World")
        anchors.horizontalCenter: parent.horizontalCenter
        y: 100
        font.pointSize: 32

        // ボタン押下で実行してほしい関数
        function update_text(){
            // 日付を"text001"に設定
            let d = new Date();
            let time_string = d.getHours() + ':'
                + ('0' + d.getMinutes()).slice(-2) + ":"
                + ('0' + d.getSeconds()).slice(-2);
            text = time_string;
        }
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

        // ボタン押下のシグナル
        signal clicked(int mouseX, int mouseY)

        Text {
            font.pointSize: 24
            text: qsTr("PUSH")
            anchors.horizontalCenter: parent.horizontalCenter
            color: "white"
        }
        MouseArea {
            anchors.fill: parent
            onPressed: {
                parent.clicked(mouseX, mouseY);
            }
        }
    }
}
