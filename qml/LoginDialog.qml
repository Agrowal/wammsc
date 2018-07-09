import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.1
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0

Window {
    id: loginWindow

    function login()
    {
        var userName = userTextInput.text
        var userPass = passTextInput.text
        return PageController.login(userName,userPass)
    }

    width: 350
    height: 500
    color: "#4d4d4d"
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width

    visible: true

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        Column {
            id: column
            anchors.fill: parent



            Image {
                id: avatarImage
                width: 150
                height: 150
                anchors.top: parent.top
                anchors.topMargin: 25
                anchors.horizontalCenter: parent.horizontalCenter
                source: "../images/login_avatar.jpg"

                property bool rounded: true
                property bool adapt: true

                layer.enabled: rounded
                layer.effect: OpacityMask {
                    maskSource: Item {
                        width: avatarImage.width
                        height: avatarImage.height
                        Rectangle {
                            anchors.centerIn: parent
                            width: avatarImage.adapt ? avatarImage.width : Math.min(avatarImage.width, avatarImage.height)
                            height: avatarImage.adapt ? avatarImage.height : width
                            radius: 20 // Math.min(width, height)
                        }
                    }
                }

            }

            Rectangle{
                id: userInput
                color: "#ded8d8"
                height: userTextInput.height+5
                width: userTextInput.width+20
                radius: 5

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: avatarImage.bottom
                anchors.topMargin: 65

                Label {
                    id: label
                    color: "#ededed"
                    anchors.left: parent.left
                    anchors.bottom: parent.top
                    anchors.bottomMargin: 5
                    text: qsTr("Użytkownik:")
                }

                TextInput {
                    id: userTextInput
                    width: 200
                    height: 20
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 12
                    text: "wammsc_micek"
                }

            }

            Rectangle{
                id: passInput
                color: "#ded8d8"
                height: passTextInput.height+5
                width: passTextInput.width+20
                radius: 5

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: userInput.bottom
                anchors.topMargin: 30

                Label {
                    id: label1
                    color: "#ededed"
                    anchors.left: parent.left
                    anchors.bottom: parent.top
                    anchors.bottomMargin: 5
                    text: qsTr("Hasło:")
                }

                TextInput {
                    id: passTextInput
                    width: 200
                    height: 20
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 12
                    echoMode: TextInput.Password
                }
            }

            Rectangle {
                id: rectangle
                height: 100
                color: "#5b5b5b"
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.bottom: parent.bottom


                RoundButton {
                    id: roundButton
                    width: 250
                    height: 50
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    radius: 15
                    text: "Zaloguj"
                    font.weight: Font.Normal
                    font.italic: false
                    font.letterSpacing: 2
                    font.capitalization: Font.MixedCase
                    font.bold: true
                    font.pointSize: 12

                    background: Rectangle{
                        color: "#03a69e"
                        radius: 15
                    }


                    onClicked:{
                        if(login()){
                            ApplicationControl.load("Mainpage")
                            loginWindow.close()
                        }
                        else{
                            messageDialog.visible = true;
                        }
                    }
                }
            }


        }

    }


    MessageDialog {
        id: messageDialog
        title: "Błąd logowania"
        icon: StandardIcon.Critical
        text: "Zła nazwa użytkownika lub hasło"
        onAccepted: {
            messageDialog.Close
        }
    }

}
