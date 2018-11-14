import QtQuick 2.2

Item {
    id: item

    property FontsCollections fonts

    width: 1280
    height: 1024

    states: [

        State {
            name: "NONE"
            PropertyChanges {
                restoreEntryValues: true
            }
        },
        State {
            name: "ACTIVE_CLEAN"
            PropertyChanges {
                target: activepower_button
                selected: true
                restoreEntryValues: true
            }
        },
        State {
            name: "FOAM"
            PropertyChanges {
                target: foam_button
                selected: true
                restoreEntryValues: true
            }
        },
        State {
            name: "SHAMPOO"
            PropertyChanges {
                target: shampoo_button
                selected: true
                restoreEntryValues: true
            }
        },
        State {
            name: "COLDWATER"
            PropertyChanges {
                target: coldwater_button
                selected: true
                restoreEntryValues: true
            }
        },
        State {
            name: "HOTWATER"
            PropertyChanges {
                target: hotwater_button
                selected: true
                restoreEntryValues: true
            }
        },
        State {
            name: "WAX"
            PropertyChanges {
                target: wax_button
                selected: true
                restoreEntryValues: true
            }
        },
        State {
            name: "OSMOSE"
            PropertyChanges {
                target: osmose_button
                selected: true
                restoreEntryValues: true
            }
        },
        State {
            name: "PAUSE"
            PropertyChanges {
                target: pause_button
                selected: true
                restoreEntryValues: true
            }
        }
    ]

    Image {
        id: logo
        source: "images/logo_gradient.png"
        x: 812
        y: 547
        opacity: 0.05098039215686
        visible: false
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
        text: "МОЙКА ОКОНЧЕНА. СПАСИБО, ЧТО ВЫБИРАЕТЕ НАС!"
        font.pixelSize: 31
        font.family: fonts.boldFont.name
        color: "#fafaf9"
        smooth: true
        x: 214
        y: 23.0833325386047
        opacity: 1
    }

    Image {
        id: cost_rectangle
        source: "images/balance_rectangle_opaque.png"
        x: 278
        y: 104
        opacity: 1
    }
    Text {
        id: cost_text
        text: "СТОИМОСТЬ:"
        font.pixelSize: 35
        font.family: fonts.boldFont.name
        color: "#73716f"
        smooth: true
        x: 583
        y: 121.541667938232
        opacity: 1
    }
    Text {
        id: cost_value_text
        text: valueSource.costWash + " Р."
        font.pixelSize: 91
        font.family: fonts.boldFont.name
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

    Item {
        id: pause_button
        property bool selected: false
        visible: false
    }
    Item {
        id: osmose_button
        property bool selected: false
        visible: false
    }

    Item {
        id: wax_button
        property bool selected: false
        visible: false
    }

    Item {
        id: coldwater_button
        property bool selected: false
        visible: false
    }

    Item {
        id: hotwater_button
        property bool selected: false
        visible: false
    }

    Image {
        id: foam_button
        property bool selected: false
        visible: false
    }
    Item {
        id: shampoo_button
        property bool selected: false
        visible: false
    }
    Item {
        id: activepower_button
        property bool selected: false
        visible: false
    }

    Image {
        id: wash_fin_cost_rectangle
        source: "images/wash_fin_cost_rectangle.png"
        x: 278
        y: 327
        opacity: 1
    }
    Text {
        id: wash_fin_cost_text
        text: "ОПЛАЧЕНО НАЛИЧНЫМИ: " + valueSource.amountReceived + " Р.\n" +
              "СДАЧА: " + valueSource.costChange + " Р." +
              (valueSource.costChange > 0 ? "ЗАЧИСЛЕНА НА КАРТУ ECO" : "")
        font.pixelSize: 24
        font.family: fonts.boldFont.name
        color: "#73716f"
        smooth: true
        x: 328
        y: 356.75
        opacity: 1
    }
    Text {
        id: modes_cost_values
        text: (valueSource.costShampoo > 0 ? ("ШАМПУНЬ                        " +valueSource.costShampoo +" Р.\n" ) : "" ) +
              (valueSource.costHotWater > 0 ? ("ГОРЯЧАЯ ВОДА                " +valueSource.costHotWater +" Р.\n" ) : "" ) +
              (valueSource.costFoam > 0 ? ("ПЕНА                                 " +valueSource.costFoam +" Р.\n" ) : "" ) +
              (valueSource.costColdWater > 0 ? ("ХОЛОДНАЯ ВОДА            " +valueSource.costColdWater +" Р.\n" ) : "" ) +
              (valueSource.costWax > 0 ? ("ВОСК                                " +valueSource.costWax +" Р.\n" ) : "" ) +
              (valueSource.costOsmose > 0 ? ("ОСМОС                           " +valueSource.costOsmose +" Р.\n" ) : "" ) +
              (valueSource.costPause > 0 ? ("ПАУЗА                               " +valueSource.costPause +" Р.\n" ) : "" )

        font.pixelSize: 24
        font.family: fonts.basicFont.name
        color: "#73716f"
        smooth: true
        x: 327
        y: 457.75
        opacity: 1
    }
    Text {
        id: takeCard_text
        text: "ЗАБЕРИТЕ КАРТУ"
        font.pixelSize: 49
        font.family: fonts.basicFont.name
        color: "#cf1f7f"
        smooth: true
        x: 442
        y: 792.5
        opacity: 1
    }
    Image {
        id: takeCard_image
        source: "images/wash_fin_cost_small_rectangle.png"
        x: 322
        y: 775
        opacity: 1
    }
    Text {
        id: printReceipt_text
        text: "ДЛЯ ПОЛУЧЕНИЯ ЧЕКА \nНАЖМИТЕ КЛАВИШУ «ПЕЧАТЬ ЧЕКА»"
        font.pixelSize: 29
        font.family: fonts.basicFont.name
        color: "#73716f"
        smooth: true
        x: 382
        y: 905.5
        opacity: 1
    }
    Image {
        id: printReceipt_image
        source: "images/wash_fin_cost_small_rectangle.png"
        x: 322
        y: 896
        opacity: 1
    }
}
