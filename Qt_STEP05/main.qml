import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Qt STEP05")

    /**
     * シグナルと、シグナルハンドラの接続
     */
    Component.onCompleted: {
        mouse001.clicked.connect(model001.update);
    }

    /**
     * モデル:model001
     */
    Item {
        id: model001
        property int mouseX: 100
        property int mouseY: 100
        /**
         * 値の更新処理
         */
        function update(x, y){
            mouseX = x;
            mouseY = y;
        }
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
     * マウスコントロール:mouse001
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
