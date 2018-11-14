import Qt 4.7
Item {
    width:1280
    height:1024

    states : [

        State {
            name : "FUNC"
            PropertyChanges {
                restoreEntryValues: true
            }
        },
        State {
            name : "ACTIVE_CLEAN"
            PropertyChanges {
                target: activeCleanTB
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "FOAM"
            PropertyChanges {
                target: foamTB
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "SHAMPOO"
            PropertyChanges {
                target: shampooTB
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "COLDWATER"
            PropertyChanges {
                target: coldWaterTB
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "HOTWATER"
            PropertyChanges {
                target: hotWaterTB
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "WAX"
            PropertyChanges {
                target: waxTB
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "OSMOSE"
            PropertyChanges {
                target: osmoseTB
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "PAUSE"
            PropertyChanges {
                target: pauseTB
                selected : true
                restoreEntryValues: true
            }
        }


    ]



    Image {
        id: background
        visible: false
        source: "images/background.png"
        x: 0
        y: 0
        opacity: 1
    }
    Image {
        id: logo
        source: "images/logo_gradient.png"
        x: 812
        y: 547
        opacity: 0.05098039215686
        visible : false
    }
    Image {
        id: header_rectangle
        source: "images/header_rectangle.png"
        x: 0
        y: 0
        opacity: 1
    }
    Text {
        id: header_text
        text: "ВЫБЕРИТЕ НЕОБХОДИМЫЕ ОПЦИИ, НАЖАВ СООТВЕТСТВУЮЩУЮ КЛАВИШУ"
        font.pixelSize: 31
        font.family: "AGAvalancheC"
        color: "#fafaf9"
        smooth: true
        x: 62
        y: 23.0833325386047
        opacity: 1
    }
    Image {
        id: logo_color
        visible: false
        source: "images/logo_color.png"
        x: 543
        y: 118
        opacity: 0.50196078431373
    }
    Image {
        id: balance_rectangle
        source: "images/balance_rectangle.png"
        x: 278
        y: 104
        opacity: 1
    }
    Text {
        id: balance_text
        text: "ВАШ БАЛАНС:"
        font.pixelSize: 45
        font.family: "AGAvalancheC"
        color: "#73716f"
        smooth: true
        x: 583
        y: 121.541667938232
        opacity: 1
    }
    Text {
        id: balance_value_text.
        text: valueSource.amountReceived
        font.pixelSize: 116
        font.family: "AGAvalancheC"
        color: "#cf1f7f"
        smooth: true
        x: 580
        y: 159.833335876465
        opacity: 1
    }
    Image {
        id: wallet
        source: "images/wallet.png"
        x: 327
        y: 127
        opacity: 1
    }
    Text {
        id: пауза_стоимость__0_р.
        text: "ПАУЗА
СТОИМОСТЬ: 0 Р."
        font.pixelSize: 43
        font.family: "AGAvalancheC"
        color: "#cf1f7f"
        smooth: true
        x: 809
        y: 858.072847366333
        opacity: 1
    }
    Image {
        id: pause-circular-button
        source: "images/pause-circular-button.png"
        x: 705
        y: 868
        opacity: 1
    }
    Image {
        id: кнопка_8
        source: "images/кнопка_8.png"
        x: 674
        y: 837
        opacity: 1
    }
    Image {
        id: кнопка_7
        source: "images/кнопка_7.png"
        x: 676
        y: 672
        opacity: 1
    }
    Text {
        id: осмос_стоимость__100_р.
        text: "ОСМОС
СТОИМОСТЬ: 100 Р."
        font.pixelSize: 43
        font.family: "AGAvalancheC"
        color: "#cf1f7f"
        smooth: true
        x: 809
        y: 693.072847366333
        opacity: 1
    }
    Image {
        id: stars-4
        source: "images/stars-4.png"
        x: 696
        y: 697
        opacity: 1
    }
    Image {
        id: кнопка_6
        source: "images/кнопка_6.png"
        x: 674
        y: 507
        opacity: 1
    }
    Text {
        id: воск_стоимость__100_р.
        text: "ВОСК
СТОИМОСТЬ: 100 Р."
        font.pixelSize: 43
        font.family: "AGAvalancheC"
        color: "#cf1f7f"
        smooth: true
        x: 811
        y: 528.072847366333
        opacity: 1
    }
    Image {
        id: stars
        source: "images/stars.png"
        x: 696
        y: 529
        opacity: 1
    }
    Image {
        id: кнопка_5
        source: "images/кнопка_5.png"
        x: 674
        y: 342
        opacity: 1
    }
    Text {
        id: холодная_вода_стоимость__80_р.
        text: "ХОЛОДНАЯ ВОДА
СТОИМОСТЬ: 80 Р."
        font.pixelSize: 43
        font.family: "AGAvalancheC"
        color: "#cf1f7f"
        smooth: true
        x: 810
        y: 363.072847366333
        opacity: 1
    }
    Image {
        id: cold-water-2
        source: "images/cold-water-2.png"
        x: 696
        y: 370
        opacity: 1
    }
    Image {
        id: кнопка_4
        source: "images/кнопка_4.png"
        x: 55
        y: 837
        opacity: 1
    }
    Text {
        id: горячая_вода_стоимость__80_р.
        text: "ГОРЯЧАЯ ВОДА
СТОИМОСТЬ: 80 Р."
        font.pixelSize: 43
        font.family: "AGAvalancheC"
        color: "#cf1f7f"
        smooth: true
        x: 187
        y: 861.072847366333
        opacity: 1
    }
    Image {
        id: hot-thermometer
        source: "images/hot-thermometer.png"
        x: 85
        y: 866
        opacity: 1
    }
    Image {
        id: кнопка_3
        source: "images/кнопка_3.png"
        x: 57
        y: 672
        opacity: 1
    }
    Text {
        id: пена_стоимость__80_р.
        text: "ПЕНА
СТОИМОСТЬ: 80 Р."
        font.pixelSize: 43
        font.family: "AGAvalancheC"
        color: "#cf1f7f"
        smooth: true
        x: 187
        y: 693.072847366333
        opacity: 1
    }
    Image {
        id: bubbles
        source: "images/bubbles.png"
        x: 76
        y: 701
        opacity: 1
    }
    Image {
        id: кнопка_2
        source: "images/кнопка_2.png"
        x: 55
        y: 507
        opacity: 1
    }
    Text {
        id: раствор_моющий_стоимость__100_р.
        text: "РАСТВОР МОЮЩИЙ
СТОИМОСТЬ: 100 Р."
        font.pixelSize: 43
        font.family: "AGAvalancheC"
        color: "#cf1f7f"
        smooth: true
        x: 187
        y: 523.072847366333
        opacity: 1
    }
    Image {
        id: pet-shampoo-2
        source: "images/pet-shampoo-2.png"
        x: 98
        y: 533
        opacity: 1
    }
    Image {
        id: кнопка_1
        source: "images/кнопка_1.png"
        x: 55
        y: 342
        opacity: 1
    }
    Image {
        id: strong-bodybuilder
        visible: false
        source: "images/strong-bodybuilder.png"
        x: 93
        y: 362
        opacity: 1
    }
    Image {
        id: muscle
        source: "images/muscle.png"
        x: 78
        y: 366
        opacity: 1
    }
    Text {
        id: активная_химия_стоимость__100_р.
        text: "АКТИВНАЯ ХИМИЯ
СТОИМОСТЬ: 100 Р."
        font.pixelSize: 43
        font.family: "AGAvalancheC"
        color: "#cf1f7f"
        smooth: true
        x: 186
        y: 363.072847366333
        opacity: 1
    }
    Image {
        id: information
        source: "images/information.png"
        x: 1075
        y: 120
        opacity: 1
    }
    Text {
        id: узнать_про_опции
        text: "УЗНАТЬ
ПРО ОПЦИИ"
        font.pixelSize: 24
        font.family: "AGAvalancheC"
        color: "#73716f"
        smooth: true
        x: 1056
        y: 234.75
        opacity: 1
    }
    Image {
        id: error
        source: "images/error.png"
        x: 93
        y: 120
        opacity: 1
    }
    Text {
        id: отменить_операции
        text: "ОТМЕНИТЬ
ОПЕРАЦИИ"
        font.pixelSize: 24
        font.family: "AGAvalancheC"
        color: "#73716f"
        smooth: true
        x: 79
        y: 232.75
        opacity: 1
    }
}
