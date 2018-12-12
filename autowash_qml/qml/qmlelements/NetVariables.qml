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

import QtQuick 2.2




Item {
    id: valueSource

    // номер поста
    property int  postNumber: 0;

   // Состояние терминала: ожидание, функции, окончание мойки, уборка, инкассация, пополнение баланса оператором
    property int postMode: 0;
        // TYPE EnumMode :
        // (
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
        // );
        // END_TYPE

       // баланс
      property int postCounterFund: 0;

        // тип карты
      property int cardType: 0;
        // TYPE EnumCardType :
        // (
        // 	UNDEFINED	:= 0,	// неопределённая карта (карта отсутствует)
        // 	CLEANUP		:= 1,	// карта уборки
        // 	CASHCOLLECT	:= 2,	// карта инкассации
        // 	FREEMONEY	:= 3,	// карта добавления денег (бесплатной мойки)
        // 	SERVICE		:= 4	// карта техслужбы
        // );
        // END_TYPE


        // нажатая кнопка
       property int buttonActive: 0;
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

        // сумма внесения
        property int amountReceived: 0;


        // стоимость оконченной мойки
        property int costWash: 0;
        // сдача
        property int costChange: 0;
        // стоимость активной химии
        property int costActiveClean: 0;
        // стоимость пены
        property int costFoam: 0;
        // стоимость шампуня
        property int costShampoo: 0;
        // стоимость ХВ
        property int costColdWater: 0;
        // стоимость ГВ
        property int costHotWater: 0;
        // стоимость воска
        property int costWax: 0;
        // стоимость осмоса
        property int costOsmose: 0;
        // стоимость паузы
        property int costPause: 0;


        // состояние верхнего замка
        property int lockTop: 0;
        // состояние среднего замка
        property int lockMid: 0;
        // 1 - замок закрыт; 0 - замок открыт



        property var variableList;

        onVariableListChanged: {

            for (var varName in variableList) {
                if (varName in valueSource) {

                    valueSource[varName] = variableList[varName];
                };
            }
            
            //this.postMode = 1000;
            //this.postCounterFund= 0;            
            
                    

        }

}
