import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2


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
            MenuItem {
                text: "Importuj plik"
                shortcut: "Ctrl+I"
                onTriggered: fileDialog.open()
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
            Label {text: "Aplikacja WAMM SC. Użytkownik: "+PageController.getUserName()}
        }
    }

    FileDialog {
        id: fileDialog
        folder: shortcuts.home
        onAccepted: {
            var path = this.fileUrl.toString();
            // remove prefixed "file:///"
            path= path.replace(/^(file:\/{3})|(qrc:\/{2})|(http:\/{2})/,"");
            // unescape html codes like '%23' for '#'
            var cleanPath = decodeURIComponent(path);
            //Run controller function
            var readFileCode = PageController.readFile(cleanPath);
            if(readFileCode == 0){
                successMessageDialog.open();
            }else{
                switch(readFileCode){
                case 1:
                    errorMessageDialogText = "Error 0001 - niewłaściwy kod towaru!";
                    break;
                case 2:
                    errorMessageDialogText = "Error 0002 - towar posiada już technologię!";
                    break;
                case 3:
                    errorMessageDialogText = "Error 0003 - niewłaściwa ilość!";
                    break;
                default:
                    errorMessageDialogText = "Error 000X - nieprzewidzany błąd!";
                }

                errorMessageDialog.open();
            }
        }
    }

    MessageDialog {
        id: successMessageDialog
        title: "Sukces"
        text: "Import zakończony sukcesem!"
        onAccepted: {
            console.log("Log success.")
        }
    }

    property var errorMessageDialogText: "";

    MessageDialog {
        id: errorMessageDialog
        icon: StandardIcon.Critical
        title: "Error"
        text: errorMessageDialogText
        onAccepted: {
            console.log("Log error.")
        }
    }

}
