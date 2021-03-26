
import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Controls 1.2
import QtQuickQRCode 1.0




ApplicationWindow {
    id: root
    visible: true
    //height: 1024
    //width: 1280
    title: "CarWashEco"
    visibility: Window.FullScreen

    Action {
       id: escAction
       shortcut: "Esc"
       onTriggered: {root.visibility = Window.Windowed;}// Do some action

    }

        Rectangle {

         width:parent.width
         height:parent.height  

             QtQuickQRCode {
                id: qrCode
                // позиционируем его и задаём размеры

                anchors.centerIn:parent

         
                // Определяем его свойства, которые Q_PROPERTY
                qrString: "Вася235723d34tu349tyu349uyt9034uy90tu349utgj93ujgjeojg34ouj tg9-034u9-g3u9"
                //color format #AARRGGBB
                backgroundColor: "#00FFFFFF"
                pixelColor: "#FF000000"
                width:300
                height:300


            }
          color:"Cyan"

       }

       Timer {
         interval: 15000; running: false; repeat: true
         onTriggered: qrCode.qrString = Date().toString()
       }



}
