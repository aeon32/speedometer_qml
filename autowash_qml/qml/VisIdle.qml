
import QtQuick 2.2
import QtMultimedia 5.6
import "./qmlelements" as QMLElements


Item {
    id: item
    width:1280
    height:1024

    MediaPlayer {
        id: mediaPlayer
        autoPlay: false
        autoLoad: true
        loops:MediaPlayer.Infinite
        source:"/usr/share/autowash_qml/video/Idle.mp4"
    }

    VideoOutput {
        id:videoOutput
        source:mediaPlayer
        anchors.fill: parent
    }

    onVisibleChanged:
    {
        if (visible)
            mediaPlayer.play()
        else
            mediaPlayer.stop()
    }




}
