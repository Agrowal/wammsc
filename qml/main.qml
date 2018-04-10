import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
    id: window

    function buttonClickedHandler() {
        controller.changeModelData();
        text1.text = controller.getModelData();

    }

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        id: text1
        text: controller.getModelData()
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 270
        y: 55
        text: qsTr("Change model")
        onClicked: buttonClickedHandler()
    }
}
