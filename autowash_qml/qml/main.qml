/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Controls 1.2
/*import QtQuick.Controls 2.0*/
import "./qmlelements" as QMLElements



ApplicationWindow {
    id: root
    visible: true
    height: 1024
    width: 1280
    title: "CarWashEco"
    visibility: Window.FullScreen

    Action {
       id: escAction
       shortcut: "Esc"
       onTriggered: {root.visibility = Window.Windowed;}// Do some action

    }


    FontsCollections {
        id: myFonts

    }



    QMLElements.NetVariables {
        id: valueSource
        onPostModeChanged: {


            switch (this.postMode) {

                // 	FUNC		:= 0,	// терминал готов к включению функций
                //
                // 	ACTIVECLEAN	:= 1,	// Р1. ECO-power		2
                // 	FOAM		:= 2,	// Р2. Пена				4
                // 	SHAMPOO		:= 3,	// Р3. Шампунь			3
                // 	COLDWATER	:= 4,	// Р4. Холодная вода	1
                // 	HOTWATER	:= 5,	// Р5. Горячая вода		2
                // 	WAX			:= 6,	// Р6. Воск				4
                // 	OSMOSE		:= 7,	// Р7. Осмос			3
                // 	PAUSE		:= 8,	// Пауза				4
                //
                // 	IDLE		:= 9,	// терминал в ожидании клиентов
                // 	ADVERT		:= 10,	// реклама
                //
                // 	FIN			:= 500,	// Экран окончания мойки
                // 	CLEANUP		:= 600,	// Экран уборки
                // 	CASHCOLLECT	:= 700,	// Экран инкассации
                // 	CASHCOLLECT_FIN	:= 710,	// Экран окончания инкассации
                // 	FREEMONEY	:= 800	// Экран добавления денег
                // 	STOP		:= 1000	// Экран состояния останова поста
                case 0 :
                        modeView.state = "FUNC";
                break;
                case 1 :
                        modeView.state = "FUNC";
                break;
                case 2 :
                        modeView.state = "FUNC";
                break;
                case 3 :
                        modeView.state = "FUNC";
                break;
                case 4 :
                        modeView.state = "FUNC";
                break;
                case 5 :
                        modeView.state = "FUNC";
                break;
                case 6 :
                        modeView.state = "FUNC";
                break;
                case 7 :
                        modeView.state = "FUNC";
                break;
                case 8 :
                        modeView.state = "FUNC";
                break;
                case 9 : modeView.state = "IDLE"; break;
                case 10 : modeView.state = "ADVERT"; break;
                case 500 : modeView.state = "FIN"; break;
                case 600 : modeView.state = "CLEANUP"; break;
                case 700 : modeView.state = "CASHCOLLECT"; break;
                case 710 : modeView.state = "CASHCOLLECT_FIN"; break;
                case 800 : modeView.state = "FREEMONEY"; break;
                case 1000 : modeView.state = "STOP"; break;
                default:
                    modeView.state = "FUNC";

            };


        }

        onButtonActiveChanged: {
            switch (this.buttonActive) {

                // TYPE EnumButton :
                // (
                // 	NONE := 0,				// нет нажатой кнопки
                // 	BTN_ACTIVECLEAN := 1,	// Р1. ECO-power
                // 	BTN_FOAM := 2,			// Р2. Пена
                // 	BTN_SHAMPOO := 3,		// Р3. Шампунь
                // 	BTN_COLDWATER := 4,		// Р4. Холодная вода
                // 	BTN_HOTWATER := 5,		// Р5. Горячая вода
                // 	BTN_WAX := 6,			// Р6. Воск
                // 	BTN_OSMOSE := 7,		// Р7. Осмос
                // 	BTN_PAUSE := 8,			// Пауза
                // 	BTN_PRINT := 9,			// Печать чека
                // 	BTN_HELP := 10			// Вызов оператора
                // );
                // END_TYPE
                case 0 :
                        modeView.buttonState = "NONE";
                break;
                case 1 :
                        modeView.buttonState = "ACTIVE_CLEAN";
                break;
                case 2 :
                        modeView.buttonState = "FOAM";
                break;
                case 3 :
                        modeView.buttonState = "SHAMPOO";
                break;
                case 4 :
                        modeView.buttonState = "COLDWATER";
                break;
                case 5 :
                        modeView.buttonState = "HOTWATER";
                break;
                case 6 :
                        modeView.buttonState = "WAX";
                break;
                case 7 :
                        modeView.buttonState = "OSMOSE";
                break;
                case 8 :
                        modeView.buttonState = "PAUSE";
                break;
                case 9 :
                        modeView.buttonState = "PRINT";
                break;
                case 10 :
                        modeView.buttonState = "HELP";
                break;

                default:
                     modeView.buttonState = "NONE";

            };


        }
    }


    function setVariables(variables) {
        valueSource.variableList = variables;
        variablesView.updateModel(valueSource.variableList)

     }

    function setQmlSettings(debugFlag, speedometerAnimation, animationTime) {
        variablesView.visible = debugFlag;
        visFunc.speedometer_animation = speedometerAnimation;
        visFunc.animation_time = animationTime;
    }

     Item {
        id: modeView

        property string buttonState: "NONE";


        state: "FUNC";
        states : [
            State {
                name : "CLEANUP"
                PropertyChanges {
                    target: visCleanup
                    visible : true
                    restoreEntryValues: true
                }
            },
            State {
                name : "CASHCOLLECT"
                PropertyChanges {
                    target: visCashCollect
                    visible : true
                    restoreEntryValues: true
                }
            },
            State {
                name : "CASHCOLLECT_FIN"
                PropertyChanges {
                    target: visCashCollectFin
                    visible : true
                    restoreEntryValues: true
                }
            },
            State {
                name : "FREEMONEY"
                PropertyChanges {
                    target: visFreeMoney
                    visible : true
                    restoreEntryValues: true
                }
            },
            State {
                name : "ADVERT"
                PropertyChanges {
                    target: visAdvert
                    visible : true
                    restoreEntryValues: true
                }
            },
            State {
                name : "STOP"
                PropertyChanges {
                    target: visStop
                    visible : true
                    restoreEntryValues: true
                }
            },
            State {
                name : "FUNC"
                PropertyChanges {
                    target: visFunc
                    visible : true
                    restoreEntryValues: true
                }
            },
            State {
                name : "FIN"
                PropertyChanges {
                    target: visFin
                    visible : true
                    restoreEntryValues: true
                }
            },
            State {
                name : "IDLE"
                PropertyChanges {
                    target: visIdle
                    visible : true
                    restoreEntryValues: true
                }
            }

        ]

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right:parent.right
        anchors.bottom:variablesView.top


        Image {
            id: background
            visible: true
            source: "images/background.png"
            x: 0
            y: 0
            opacity: 1
        }


        VisCleanup {
           id: visCleanup
           visible: false
           anchors.fill: parent
           fonts: myFonts
           state:parent.buttonState



        }

        VisCashCollect {
           id: visCashCollect
           visible: false
           anchors.fill: parent
           fonts : myFonts
           state:parent.buttonState

        }

        VisCashCollectFin {
           id: visCashCollectFin
           visible: false
           anchors.fill: parent
        }

        VisFreeMoney {
            id: visFreeMoney
            visible: false
            anchors.fill: parent
            state:parent.buttonState
            fonts: myFonts
        }

        VisStop {
            id :visStop
            visible: false
            anchors.fill: parent

        }

        VisFunc {
            id: visFunc
            visible: false
            anchors.fill: parent
            fonts: myFonts
            state:parent.buttonState


        }
        VisAdvert {
            id: visAdvert
            visible: false
            anchors.fill: parent
        }

        VisFin {
            id: visFin
            visible: false
            anchors.fill: parent
            fonts: myFonts
            state:parent.buttonState
        }

        VisIdle {
            id : visIdle
            visible: false
            anchors.fill: parent
        }



    }

     Component {
         id: myDelegate
         Text {text : varName +": " +varValue; font.pixelSize: 9}
     }

     ListView {
         id : variablesView
         height:200

         anchors.left: parent.left
         anchors.bottom: parent.bottom
         anchors.right:parent.right

         visible : false;

         model : ListModel {id: model}
         delegate: myDelegate
         function updateModel(variableList) {
             model.clear()
             for (var key in variableList) {
                 model.append({varName: key, varValue:variableList[key]})

             }

         }

     }






}
