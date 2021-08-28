import QtQuick 2.2
//import QtMultimedia 5.6
import QtAV 1.7
import "./qmlelements" as QMLElements


Item {
    id: item

    anchors.fill: parent
    property string videoFile:""
    property bool looped : false
    signal videoStopped()
    signal videoPlaying()

    visible : false


    onVisibleChanged: {
       if (visible)
       {
          mediaPlayer.play()
       }
    }          

    function play()
    {
        mediaPlayer.play()
    }

    MediaPlayer {
        id: mediaPlayer
        autoPlay: false
        autoLoad: true
        loops: looped ? MediaPlayer.Infinite : 1
        source: item.videoFile
        onError : {
           
           log.debug("media player error : " + errorString);
           item.videoStopped();

        }

    }

    VideoOutput2 {

        id:videoOutput
        source:mediaPlayer
        anchors.fill: parent
        fillMode : VideoOutput.PreserveAspectCrop

    }

    Component.onCompleted:
    {
        mediaPlayer.stopped.connect(videoStopped)
        mediaPlayer.playing.connect(videoPlaying)
    }

}
