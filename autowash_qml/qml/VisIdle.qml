
import QtQuick 2.2
import QtMultimedia 5.6
import "./qmlelements" as QMLElements


Item {
    id: item
    width:1280
    height:1024
    property string videoFile: ""

    MediaPlayer {
        id: mediaPlayer
        autoPlay: false
        autoLoad: true
        loops:MediaPlayer.Infinite
        source: item.videoFile
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
