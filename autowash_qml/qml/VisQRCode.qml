
import QtQuick 2.2
import "./qmlelements" as QMLElements
import QtQuickQRCode 1.0

Item {

   Image {
     id: background
     visible: true
     source: "images/background.png"
     x: 0
     y: 0
     opacity: 1
   }


    QtQuickQRCode {
        id: qrCode
        // позиционируем его и задаём размеры
        anchors.horizontalCenter:background.horizontalCenter

        qrString: valueSource.qrString0 + valueSource.qrString1
        
        //color format #AARRGGBB
        backgroundColor: "#00FFFFFF"
        pixelColor: "#FF000000"
        width:300
        height:300
        y:200


    } 


}
