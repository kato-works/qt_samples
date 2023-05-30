/*
 * Qt_STEP01/main.qml
 *
 * Author: Shohei KISHIMOTO
 *
 * Copyright (c) 2023 KATO WORKS CO., LTD. ALL RIGHTS RESERVED.
 */
import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    visible: true;
    width: 640;
    height: 480;
    title: qsTr("Qt STEP01");

    /**
     * Hello QML表示エリア
     */
    Text {
        id: text001;
        text: qsTr("Hello QML");
    }
}
