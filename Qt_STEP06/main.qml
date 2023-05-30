import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

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
}
