import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

import io.qt.queryModel 1.0

Item {
    id: firstTab

    property var sqlQueryModel : PageController.getSqlQuery();

    anchors.fill: parent

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            if (mouse.button === Qt.RightButton)
                contextMenu.popup()
        }

        Menu {
            id: contextMenu
            MenuItem {text: "Context menu"}
        }




        Component
        {
            id: columnComponent
            TableViewColumn{width: 100 }
        }

        TableView{
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            anchors.topMargin: 50

            id: table_view1
            //            TableViewColumn  {
            //                role: "ID"
            //                title: "ID"
            //                width: 200
            //            }
            //            TableViewColumn  {
            //                role: "Nazw"
            //                title: "Nazwa"
            //                width: 100;
            //            }
            //            TableViewColumn  {
            //                role: "NVat"
            //                title: "VAT"
            //                width: 100;
            //            }

            resources: {
                //var roleList = firstTab.sqlQueryModel.userRoleNames
                var roleList = PageController.columnList()
                var temp = []
                for(var i=0; i<roleList.length; i++)
                {
                    var role  = roleList[i]
                    temp.push(columnComponent.createObject(table_view1, { "role": role, "title": role}))
                }
                return temp
            }

            model: firstTab.sqlQueryModel
        }
    }

}
