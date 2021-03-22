
import QtQuick 2.2
import "./qmlelements" as QMLElements
import QtQuickQRCode 1.0

Item {

    QtQuickQRCode {
        id: qrCode

        anchors.centerIn:parent

        qrString: valueSource.qrString0 + valueSource.qrString1
        
        backgroundColor: "white"
        width:25*10
        height:25*10

    }
   

}
