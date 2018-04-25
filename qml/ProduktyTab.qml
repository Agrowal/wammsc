import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
Item {
    id: firstTab

    function buttonClickedHandler() {
//        controller.changeModelData();
//        text2.text = controller.getModelData();
    }

    anchors.fill: parent

    Text {
        id: text2
        x: 113
        y: 11
        text: controller.getModelData()
        font.pixelSize: 12
    }
    
    
    Button {
        id: button

        anchors.left: text2.right
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 5

        height: 20
        width: 100

        text: qsTr("Change model")
        onClicked: buttonClickedHandler()
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
            var roleList = modelQuery.userRoleNames
            var temp = []
            for(var i=0; i<roleList.length; i++)
            {
                var role  = roleList[i]
                temp.push(columnComponent.createObject(table_view1, { "role": role, "title": role}))
            }
            return temp
        }
        
        model: modelQuery
        
    }


}
