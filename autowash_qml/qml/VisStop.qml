
import QtQuick 2.2
import "./qmlelements" as QMLElements


Item {


Rectangle {
    id: container
    width: parent.width
    anchors.centerIn: parent

    gradient: Gradient {
        GradientStop { position: 0; color: "black"}
        GradientStop { position: 1; color: "lightsteelblue" }
    }
    Column {
        id: column
        opacity: 0.99 // work around QTBUG-29037

        width:parent.width
        anchors.horizontalCenter: parent.horizontalCenter

           QMLElements.MoneyTextBox{
                id : moneyTextBox
                width: parent.width
                moneyLabelText : "Останов"

            }

    }
}

}
