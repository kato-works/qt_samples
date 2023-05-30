import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Qt STEP08")

    Component.onCompleted: {
        // シグナル送信
        mouse001.clicked.connect(controller001.clickedSignalEmitted);
    }

    /**
     * テキスト:text001
     */
    Text {
        id: text001
        text: `Click!\n(${model001.mouseX}, ${model001.mouseY})`
        anchors.fill: parent
        font.pointSize: 36
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    /**
     * マウスエリア
     */
    MouseArea {
        id: mouse001
        anchors.fill: parent
        // ボタン押下のシグナル
        signal clicked(int mouseX, int mouseY)

        /**
         * マウスクリックイベント処理
         */
        onPressed: (mouse) => {
            clicked(mouse.x, mouse.y);
        }
    }
}
