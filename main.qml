import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2


Window {
    id: root
    width: 500
    height: 1000
    visible: true
    title: qsTr("Login Page")

    Rectangle{
        id: mainArea
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        color: "#394454"

        Image {
            id: loginLogo
            x:serverField1.x
            width: 321
            height: 150
            anchors.top: parent.top
            source: "qrc:/postgre"
            fillMode: Image.PreserveAspectFit
        }

        TextField {
            id: serverField1
            x: 100
            y: 183
            width: 321
            height: 30
        }

        Rectangle{
            id: serverField1_1
            anchors.left: parent.left
            anchors.leftMargin: 10
            y:183
            color: "transparent"
            Text {
                anchors.fill: parent
                font.family: "Arial"
                font.pointSize: 12
                color:"white"
                text: qsTr("Name")
            }
        }

        TextField {
            id: serverField2
            x: 100
            y: 247
            width: 321
            height: 30
        }

        Rectangle{
            id: serverField2_2
            anchors.left: parent.left
            anchors.leftMargin: 10
            y:247
            color: "transparent"
            Text {
                anchors.fill: parent
                font.family: "Arial"
                font.pointSize: 12
                color:"white"
                text: qsTr("Surname")
            }
        }

        TextField {
            id: serverField3
            x: 100
            y: 310
            width: 321
            height: 30
        }

        Rectangle{
            id: serverField3_3
            anchors.left: parent.left
            anchors.leftMargin: 10
            y:310
            color: "transparent"
            Text {
                anchors.fill: parent
                font.family: "Arial"
                font.pointSize: 12
                color:"white"
                text: qsTr("Age")
            }
        }

        TextField {
            id: serverField4
            x: 100
            y: 375
            width: 321
            height: 30
        }

        Rectangle{
            id: serverField4_4
            anchors.left: parent.left
            anchors.leftMargin: 10
            y:375
            color: "transparent"
            Text {
                anchors.fill: parent
                font.family: "Arial"
                font.pointSize: 12
                color:"white"
                text: qsTr("Username")
            }
        }

        TextField {
            id: serverField5
            x: 100
            y: 440
            width: 321
            height: 30
        }

        Rectangle{
            id: serverField5_5
            anchors.left: parent.left
            anchors.leftMargin: 10
            y:440
            color: "transparent"
            Text {
                anchors.fill: parent
                font.family: "Arial"
                font.pointSize: 12
                color:"white"
                text: qsTr("Password")
            }
        }

        TextField {
            id: serverField6
            x: 100
            y: 505
            width: 321
            height: 30
        }

        Rectangle{
            id: serverField6_6
            anchors.left: parent.left
            anchors.leftMargin: 10
            y:505
            color: "transparent"
            Text {
                anchors.fill: parent
                font.family: "Arial"
                font.pointSize: 12
                color:"white"
                text: qsTr("City Plate")
            }
        }

        TextField {
            id: serverField7
            x: 100
            y: 570
            width: 321
            height: 30
            visible: false
        }

        Rectangle{
            id: serverField7_7
            anchors.left: parent.left
            anchors.leftMargin: 10
            y:570
            color: "transparent"
            visible: false
            Text {
                anchors.fill: parent
                font.family: "Arial"
                font.pointSize: 12
                color:"white"
                text: qsTr("User Id")
            }
        }

        Button {
            id: addButton
            width: 321
            height: 20
            x: 100
            text: qsTr("Click to add user")
            anchors {
                top: serverField7.bottom
                topMargin: 10
            }

            onClicked: {
                user_creation.insertUserData_1(serverField1.text, serverField2.text, serverField3.text,
                                               serverField4.text, serverField5.text, serverField6.text);
                serverField1.text = "";
                serverField2.text = "";
                serverField3.text = "";
                serverField4.text = "";
                serverField5.text = "";
                serverField6.text = "";
            }
        }

        Button {
            id: readButton
            width: 321
            height: 20
            x: 100
            text: qsTr("Click to read user data")
            anchors {
                top: addButton.bottom
                topMargin: 5
            }

            onClicked: {
                user_creation.connectDB();
                user_creation.readFromTable_1();
            }
        }

        Button {
            id: updateButton
            width: 321
            height: 20
            x: 100
            text: qsTr("Click to update data")
            anchors {
                top: readButton.bottom
                topMargin: 5
            }

            onClicked: {
                if(serverField7.visible == true){
                    user_creation.updateUserData_1(serverField7.text, serverField1.text, serverField2.text,
                                                serverField3.text, serverField4.text,
                                                serverField5.text, serverField6.text);
                }
                if(serverField7.visible == false){
                    serverField7.visible = true
                    serverField7_7.visible = true
                }else{
                    serverField7.visible = false
                    serverField7_7.visible = false
                }

                serverField1.text = "";
                serverField2.text = "";
                serverField3.text = "";
                serverField4.text = "";
                serverField5.text = "";
                serverField6.text = "";
                serverField7.text = "";
            }
        }
    }
}
