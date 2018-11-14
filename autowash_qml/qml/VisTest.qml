import QtQuick 2.2
Item {
    id: item;

    property FontsCollections fonts

    width:1280
    height:1024

    states : [

        State {
            name : "NONE"
            PropertyChanges {
                restoreEntryValues: true
            }
        },
        State {
            name : "ACTIVE_CLEAN"
            PropertyChanges {
                target: activepower_button
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "FOAM"
            PropertyChanges {
                target: foam_button
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "SHAMPOO"
            PropertyChanges {
                target: shampoo_button
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "COLDWATER"
            PropertyChanges {
                target: coldwater_button
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "HOTWATER"
            PropertyChanges {
                target: hotwater_button
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "WAX"
            PropertyChanges {
                target: wax_button
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "OSMOSE"
            PropertyChanges {
                target: osmose_button
                selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "PAUSE"
            PropertyChanges {
                target: pause_button
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
        font.family: fonts.boldFont.name
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
        font.pixelSize: 35
        font.family: fonts.boldFont.name
        color: "#73716f"
        smooth: true
        x: 583
        y: 121.541667938232
        opacity: 1
    }
    Text {
        id: balance_value_text
        text: valueSource.amountReceived + " Р."
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
    Text {
        id: pause_text
        text: "ПАУЗА"
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#cf1f7f"
        smooth: true
        x: 809
        y: 858.072847366333
        opacity: 1
    }

    Text {
        id: pause_value_text
        text: "СТОИМОСТЬ: 0 Р."
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#73716f"
        smooth: true
        x: 809
        y: 905
        opacity: 1
    }
    Image {
        id: pause_circular_button
        source: "images/pause-circular-button.png"
        x: 705
        y: 868
        opacity: 1
    }
    Image {
        id: pause_button
        property bool selected : false;
        source: selected ? "images/button_pause_selected.png" : "images/button.png"
        x: 674
        y: 837
        opacity: 1
    }
    Image {
        id: osmose_button
        property bool selected : false;
        source: selected ? "images/button_mode_selected.png" : "images/button.png"
        x: 676
        y: 672
        opacity: 1
    }
    Text {
        id: osmose_cost_text
        text: "ОСМОС"

        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#cf1f7f"
        smooth: true
        x: 809
        y: 693.072847366333
        opacity: 1
    }
    Text {
        id: osmose_cost_value_text
        text: "СТОИМОСТЬ: 100 Р."
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#73716f"
        smooth: true
        x: 809
        y: 740
        opacity: 1
    }


    Image {
        id: stars_4
        source: "images/stars-4.png"
        x: 696
        y: 697
        opacity: 1
    }
    Image {
        id: wax_button
        property bool selected : false;
        source: selected ? "images/button_mode_selected.png" : "images/button.png"
        x: 674
        y: 507
        opacity: 1
    }
    Text {
        id: wax_cost_text
        text: "ВОСК"
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#cf1f7f"
        smooth: true
        x: 811
        y: 528.072847366333
        opacity: 1
    }
    Text {
        id: wax_cost_value_text
        text: "СТОИМОСТЬ: 100 Р."
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#73716f"
        smooth: true
        x: 811
        y: 575
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
        id: coldwater_button
        property bool selected : false;
        source: selected ? "images/button_mode_selected.png" : "images/button.png"
        x: 674
        y: 342
        opacity: 1
    }
    Text {
        id: coldwater_cost_text
        text: "ХОЛОДНАЯ ВОДА"
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#cf1f7f"
        smooth: true
        x: 810
        y: 363.072847366333
        opacity: 1
    }

    Text {
        id: coldwater_cost_value_text
        text: "СТОИМОСТЬ: 80 Р."
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#73716f"
        smooth: true
        x: 810
        y: 410
        opacity: 1
    }
    Image {
        id: cold_water_2
        source: "images/cold-water-2.png"
        x: 696
        y: 370
        opacity: 1
    }
    Image {
        id: hotwater_button
        property bool selected : false;
        source: selected ? "images/button_mode_selected.png" : "images/button.png"
        x: 55
        y: 837
        opacity: 1
    }
    Text {
        id: hotwater_cost_text
        text: "ГОРЯЧАЯ ВОДА"
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#cf1f7f"
        smooth: true
        x: 187
        y: 861.072847366333
        opacity: 1
    }

    Text {
        id: hotwater_cost_value_text
        text: "СТОИМОСТЬ: 80 Р."
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#73716f"
        smooth: true
        x: 187
        y: 908
        opacity: 1
    }
    Image {
        id: hot_thermometer
        source: "images/hot-thermometer.png"
        x: 85
        y: 866
        opacity: 1
    }
    Image {
        id: foam_button
        property bool selected : false;
        source: selected ? "images/button_mode_selected.png" : "images/button.png"
        x: 57
        y: 672
        opacity: 1
    }
    Text {
        id: foam_cost_text
        text: "ПЕНА"
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#cf1f7f"
        smooth: true
        x: 187
        y: 693.072847366333
        opacity: 1
    }

    Text {
        id: foam_cost_value_text
        text: "СТОИМОСТЬ: 80 Р."
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#73716f"
        smooth: true
        x: 187
        y: 740
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
        id: shampoo_button
        property bool selected : false;
        source: selected ? "images/button_mode_selected.png" : "images/button.png"
        x: 55
        y: 507
        opacity: 1
    }
    Text {
        id: shampoo_cost_text
        text: "РАСТВОР МОЮЩИЙ"
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#cf1f7f"
        smooth: true
        x: 187
        y: 523.072847366333
        opacity: 1
    }
    Text {
        id: shampoo_cost_value_text
        text: "СТОИМОСТЬ: 100 Р."
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#73716f"
        smooth: true
        x: 187
        y: 570
        opacity: 1
    }

    Image {
        id: pet_shampoo_2
        source: "images/pet-shampoo-2.png"
        x: 98
        y: 533
        opacity: 1
    }
    Image {
        id: activepower_button
        property bool selected : false;
        source: selected ? "images/button_mode_selected.png" : "images/button.png"
        x: 55
        y: 342
        opacity: 1
    }
    Image {
        id: strong_bodybuilder
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
        id: activepower_cost_text
        text: "АКТИВНАЯ ХИМИЯ"
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#cf1f7f"
        smooth: true
        x: 186
        y: 363.072847366333
        opacity: 1
    }

    Text {
        id: activepower_cost_value_text
        text: "СТОИМОСТЬ: 100 Р."
        font.pixelSize: 34
        font.family: fonts.basicFont.name
        color: "#73716f"
        smooth: true
        x: 186
        y: 410
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
        id: options_info_text
        text: "УЗНАТЬ\nПРО ОПЦИИ"
        font.pixelSize: 25
        horizontalAlignment: Text.AlignHCenter
        font.family: fonts.basicFont.name
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
        id: cancel_text
        text: "ОТМЕНИТЬ\nОПЕРАЦИИ"
        font.pixelSize: 25
        font.family: fonts.basicFont.name
        horizontalAlignment: Text.AlignHCenter
        color: "#73716f"
        smooth: true
        x: 79
        y: 232.75
        opacity: 1
    }
}
