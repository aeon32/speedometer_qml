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
         id: background
         visible: true
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
        text: "РЕЖИМ \"ИНКАССАЦИЯ\". НЕ ЗАБУДЬТЕ ЗАБРАТЬ КАРТУ ОПЕРАТОРА!"
        font.pixelSize: 31
        font.family: fonts.boldFont.name
        color: "#fafaf9"
        smooth: true
        x: 184
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
        id: operator_card
        source: "images/balance_rectangle.png"
        x: 278
        y: 104
        opacity: 1
    }
    Image {
        id: foam_button
        property bool selected: false
        source: selected ? "images/button_long_selected.png" : "images/button_long.png"
        x: 322
        y: 559
        opacity: 1
    }
    Text {
        id: operator_card_text
        text: "КАРТА\nОПЕРАТОРА"
        font.pixelSize: 45
        font.family: fonts.boldFont.name
        color: "#73716f"
        smooth: true
        x: 556
        y: 148.074097633362
        opacity: 1
    }
    Image {
        id: operator_card_image
        source: "images/operator-card.png"
        x: 332
        y: 144
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
        id: activepower_button
        property bool selected: false
        source: selected ? "images/button_long_selected.png" : "images/button_long.png"
        x: 322
        y: 371
        opacity: 1
    }

    Image {
        id: actiwepower_button2
        property bool selected: false
        source: selected ? "images/button_long_selected.png" : "images/button_long.png"
        x: 322
        y: 747
        opacity: 1
    }

    Text {
        id: cachCode_encash_text1
        text: "ИНКАССАЦИЯ КУПЮРНИКА"
        font.pixelSize: 29
        font.family: fonts.boldFont.name
        color: "#73716f"
        smooth: true
        x: 484
        y: 589.666667938232
        opacity: 1
    }

    Text {
        id: cachCode_encash_text2
        text: "НАЖМИТЕ \"ПЕНА\""
        font.pixelSize: 29
        font.family: fonts.basicFont.name
        color: "#73716f"
        smooth: true
        x: 484
        y: 636
        opacity: 1
    }
    Image {
        id: funds_2
        source: "images/funds-2.png"
        x: 355
        y: 582
        opacity: 1
    }

    Item {
        id: shampoo_button
        property bool selected: false
        visible: false
    }

    Text {
        id: unlock_text1
        text: "ОТКРЫТЬ ЗАМКИ"
        font.pixelSize: 29
        font.family: fonts.boldFont.name
        color: "#73716f"
        smooth: true
        x: 482
        y: 398.666667938232
        opacity: 1
    }
    Text {
        id: unlock_text2
        text: "НАЖМИТЕ \"АКТИВНАЯ ХИМИЯ\""
        font.pixelSize: 29
        font.family: fonts.basicFont.name
        color: "#73716f"
        smooth: true
        x: 482
        y: 445
        opacity: 1
    }

    Image {
        id: unlocked
        source: "images/unlocked.png"
        x: 365
        y: 388
        opacity: 1
    }


    Text {
        id: coin_encash_text1
        text: "ИНКАССАЦИЯ МОНЕТНИКА"
        font.pixelSize: 29
        font.family: fonts.boldFont.name
        color: "#73716f"
        smooth: true
        x: 485
        y: 777.666667938232
        opacity: 1
    }


    Text {
        id: coin_encash_text2
        text: "НАЖМИТЕ \"АКТИВНАЯ ХИМИЯ\""
        font.pixelSize: 29
        font.family: fonts.basicFont.name
        color: "#73716f"
        smooth: true
        x: 485
        y: 824
        opacity: 1
    }
    Image {
        id: coins
        source: "images/coins.png"
        x: 355
        y: 777
        opacity: 1
    }
}
