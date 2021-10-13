
import QtQuick 2.2
//import QtMultimedia 5.6
import QtAV 1.6
import "./qmlelements" as QMLElements


Item {
    id: item
    width:1280
    height:1024
    property string videoFile: ""

    signal videoStopped()
    signal videoPlaying()


    MediaPlayer {
        id: mediaPlayer
        autoPlay: false
        autoLoad: true
        loops:1
        source: item.videoFile

        onStopped : {
           log.debug("idle video stopped ")


        }



    }

    VideoOutput2 {
        id:videoOutput
        source:mediaPlayer
        anchors.fill: parent
        fillMode : VideoOutput.PreserveAspectCrop
    }

    onVisibleChanged:
    {

        if (visible)
            mediaPlayer.play()
        else
            mediaPlayer.stop()
    }

    Component.onCompleted:
    {
        mediaPlayer.stopped.connect(videoStopped)
        mediaPlayer.playing.connect(videoPlaying)
    }

    function play()
    {
        mediaPlayer.play()
    }


}
