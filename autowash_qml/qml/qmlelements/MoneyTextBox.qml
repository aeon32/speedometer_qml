/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtQuick.Window 2.1

Rectangle {
    id: container

    property string moneyLabelText;

    implicitHeight: Math.max(Screen.pixelDensity * 7, (buttonLabel.implicitHeight) * 1.2+20)
    implicitWidth: Math.max(Screen.pixelDensity * 11, buttonLabel.implicitWidth * 1.3)

    height: implicitHeight
    width: implicitWidth

    gradient: Gradient {
        GradientStop {
            position: 0
            Behavior on color {ColorAnimation { duration: 100 }}
            color: button.pressed ? "#e0e0e0" : "#fff"
        }
        GradientStop {
            position: 1
            Behavior on color {ColorAnimation { duration: 100 }}
            color: button.pressed ? "#e0e0e0" : button.containsMouse ? "#f5f5f5" : "#eee"
        }
    }


    Item {
        id: button
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.right:parent.right
        implicitHeight: col.height
        height: implicitHeight


        Column {
            spacing: 2
            id: col
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width
            Text {

                id: buttonLabel
                anchors.horizontalCenter: parent.horizontalCenter
                horizontalAlignment : Text.AlignJustify
                text: moneyLabelText
                color: "black"
                font.pixelSize: 28
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                styleColor: "white"
                style: Text.Raised

            }

        }
    }

    Rectangle {
        height: 1
        color: "#ccc"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
    }
}

/*

Rectangle {
    id: root
    property string label;
    implicitHeight: Math.max(Screen.pixelDensity * 7, buttonLabel.implicitHeight * 1.2)
    implicitWidth: Math.max(Screen.pixelDensity * 11, buttonLabel.implicitWidth * 1.3)
    height: implicitHeight
    width: implicitWidth

    gradient: Gradient {
        GradientStop {
            position: 0
            Behavior on color {ColorAnimation { duration: 100 }}
            color: button.pressed ? "#e0e0e0" : "#fff"
        }
        GradientStop {
            position: 1
            Behavior on color {ColorAnimation { duration: 100 }}
            color: button.pressed ? "#e0e0e0" : button.containsMouse ? "#f5f5f5" : "#eee"
        }
    }


    Image {
        id: image
        opacity: 0.7
        Behavior on opacity {NumberAnimation {duration: 100}}
        source: "images/next.png"
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 16
    }


    Item {
        id: button
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.right:image.left
        implicitHeight: col.height
        height: implicitHeight
        width: buttonLabel.width + 20


        Column {
            spacing: 2
            id: col
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width
            Text {
                id: buttonLabel
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 10
                text: label
                color: "black"
                font.pixelSize: 22
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                styleColor: "white"
                style: Text.Raised

            }
            Text {
                id: buttonLabel2
                anchors.left: parent.left
                anchors.leftMargin: 10
                text: description
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                color: "#666"
                font.pixelSize: 12
            }
        }
    }

    Rectangle {
        height: 1
        color: "#ccc"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
    }
}
*/
