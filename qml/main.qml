import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3



ApplicationWindow {
    id: mainWindow
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
        Tab{
            id: firstTab1
            title: "Produkty"
            source: "ProduktyTab.qml"
        }

    }

    statusBar: StatusBar {
        RowLayout {
            anchors.fill: parent
            Label {text: "Aplikacja WAMM SC. Użytkownik: "}
        }
    }

}
