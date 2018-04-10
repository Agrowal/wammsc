import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: mainWindow

    function buttonClickedHandler() {
        controller.changeModelData();
        text1.text = controller.getModelData();
    }

    visible: true
    width: 640
    height: 480
    title: qsTr("WAMM MySQL Qt Client")

    menuBar: MenuBar {
        Menu {
            //PLIK//
            title: "Plik"
            MenuItem {
                text: "Zmień użytkownika"
                shortcut: "Ctrl+L"
            }
            MenuSeparator{}
            MenuItem {
                text: "Zakończ"
                shortcut: "Ctrl+E"
                onTriggered: mainWindow.close()
            }
        }
    }

    TabView{
        id: mainTabView
        anchors.fill: parent

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
        TableView{
            x: 123
            y: 116

            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom

            id: list_view1
            TableViewColumn  {
                role: "ID"
                title: "ID"
                width: 200
            }
            TableViewColumn  {
                role: "Nazw"
                title: "Nazwa"
                width: 100;
            }
            TableViewColumn  {
                role: "NVat"
                title: "VAT"
                width: 100;
            }
            model: modelQuery

        }
    }

    statusBar: StatusBar {
        RowLayout {
            anchors.fill: parent
            Label {text: "Aplikacja WAMM SC. Użytkownik: "}
        }
    }

}
