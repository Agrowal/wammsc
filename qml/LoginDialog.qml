import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    id: loginWindow

    function login()
    {
        return true
//        var userName = userTextInput.text
//        var userPass = passTextInput.text
//        return myBackEnd.login(userName,userPass)
    }

    width: 350
    height: 500
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width

    visible: true

    MouseArea {
        id: mouseArea
        anchors.fill: parent

            Image {
                id: avatarImage
                width: 150
                height: 150
                anchors.top: parent.top
                anchors.topMargin: 25
                anchors.horizontalCenter: parent.horizontalCenter
                source: "../images/login_avatar.jpg"
            }

            Rectangle{
                id: userInput
                color: "#ded8d8"
                height: childrenRect.height+5
                width: childrenRect.width+20
                radius: 5

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: avatarImage.bottom
                anchors.topMargin: 50

                TextInput {
                    id: userTextInput
                    width: 200
                    height: 20
                    text: qsTr("Użytkownik")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 12
                }
            }

            Rectangle{
                id: passInput
                color: "#ded8d8"
                height: childrenRect.height+5
                width: childrenRect.width+20
                radius: 5

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: userInput.bottom
                anchors.topMargin: 25

                TextInput {
                    id: passTextInput
                    width: 200
                    height: 20
                    text: qsTr("Hasło")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 12
                    echoMode: TextInput.Password
                }
            }

            Rectangle {
                id: rectangle
                height: 100
                color: "#d0fdd0"
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.bottom: parent.bottom


                RoundButton {
                    id: roundButton
                    width: 100
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    radius: 25
                    text: "Zaloguj"
                    onClicked:{
                        if(login()){
                            ApplicationControl.load("Mainpage")
                            loginWindow.close()
                        }
                    }
                }
            }


    }

}
