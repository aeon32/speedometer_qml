import QtQuick 2.2
Item {
    id: item;


    property bool speedometer_animation : true
    property int animation_time : 500

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
                //target: activepower_button
                //selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "FOAM"
            PropertyChanges {
                //target: foam_button
                //selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "SHAMPOO"
            PropertyChanges {
                //target: shampoo_button
                //selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "COLDWATER"
            PropertyChanges {
                //target: coldwater_button
                //selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "HOTWATER"
            PropertyChanges {
                //target: hotwater_button
                //selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "WAX"
            PropertyChanges {
                //target: wax_button
                //selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "OSMOSE"
            PropertyChanges {
                //target: osmose_button
                //selected : true
                restoreEntryValues: true
            }
        },
        State {
            name : "PAUSE"
            PropertyChanges {
                //target: pause_button
                //selected : true
                restoreEntryValues: true
            }
        }


    ]


    Item {
    	id: speed_scale
    	width:parent.width
    	height:parent.height
    	property int speedValue: valueSource.postCounterFund 
    	property int oldSpeedValue : 19

    	readonly property int scale_segments_n : 50
    	readonly property int  scale_size : 200
    	property int scaleSegments : 0

    	readonly property real zero_angle : -155
    	readonly property real scale_angle : 214
    	property real arrow_angle : zero_angle

     	property bool speedometer_animation : parent.speedometer_animation
     	property int animation_time : parent.animation_time

        property int actualScaleSegment  : 0



    	onScaleSegmentsChanged :
    	{
    	    var scaleSegmentsStr = ''
    	    var actualScale = this.scaleSegments


            if (this.scaleSegments > this.scale_segments_n - 1)
    	    {    
    	        
    	        actualScale = this.scale_segments_n - 1
    	        scaleSegmentsStr =  actualScale.toString()
            }

            //console.log(this.speedValue + " " +scaleSegmentsStr)


            this.actualScaleSegment = actualScale


    	}

    	onSpeedValueChanged : {
    	    //this.speedValue = 200
            var auxSpeedValue = this.speedValue

            if (auxSpeedValue > this.scale_size)
                auxSpeedValue = this.scale_size;


            this.arrow_angle =  auxSpeedValue * scale_angle / scale_size + zero_angle
    	    
    	    var newScaleSegments = Math.floor(auxSpeedValue* scale_segments_n / scale_size) 
            //console.log("Speed value changed   " + this.speedValue + " " +newScaleSegments)

    		if (this.speedometer_animation) {
     		  oldSpeedValue = speedValue
     		  animateArrow.running = true
     		  animateScale.to = newScaleSegments
     		  animateScale.running = true
	          animateBalance.to = speedValue;
              animateBalance.running = true
            } else {
            
              arrowRotate.angle = this.arrow_angle
     		  this.scaleSegments = newScaleSegments
     		  balance_text.speed_value = this.speedValue

            }
     		
     	
    	}
    	//Behavior on speedValue {
        //	NumberAnimation { duration: 1000 }
    	//}

    	PropertyAnimation {id: animateArrow; target: arrowRotate; properties: "angle"; to: speed_scale.arrow_angle; duration: speed_scale.animation_time}

    	PropertyAnimation {id: animateScale; target: speed_scale; properties: "scaleSegments"; to: 0; duration: speed_scale.animation_time}

	    PropertyAnimation {id: animateBalance; target: balance_text; properties: "speed_value"; to: 0; duration: speed_scale.animation_time}

        Image {
           id: backgroung
           source: "images/speed_background.png"
           x: 0
           y: 0
           opacity: 1
        }        
    	

        /*
        Image {
           id: scale_image_bottom
           source: "speedometer_scale_images/00.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 2
        } 
        */

        Image {
           id: scale_image_00
           source: "speedometer_scale_images/00.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment == 0
           //visible : false
        }

        Image {
           id: scale_image_01
           source: "speedometer_scale_images/01.png"
           x: 108
           y: 459
           opacity: 1
           visible : speed_scale.actualScaleSegment == 1
           //visible : false
        }

        Image {
           id: scale_image_02
           source: "speedometer_scale_images/02.png"
           x: 97
           y: 436
           opacity: 1
           visible : speed_scale.actualScaleSegment== 2
           //visible : false
        }
        Image {
           id: scale_image_03
           source: "speedometer_scale_images/03.png"
           x: 92
           y: 414
           opacity: 1
           visible : speed_scale.actualScaleSegment== 3
           //visible : false
        }
        Image {
           id: scale_image_04
           source: "speedometer_scale_images/04.png"
           x: 89
           y: 386
           opacity: 1
           visible : speed_scale.actualScaleSegment== 4
           //visible : false
        }
        Image {
           id: scale_image_05
           source: "speedometer_scale_images/05.png"
           x: 84
           y: 359
           opacity: 1
           visible : speed_scale.actualScaleSegment== 5
           //visible : false
        }
        Image {
           id: scale_image_06
           source: "speedometer_scale_images/06.png"
           x: 84
           y: 332
           opacity: 1
           visible : speed_scale.actualScaleSegment== 6
           //visible : false
        }
        Image {
           id: scale_image_07
           source: "speedometer_scale_images/07.png"
           x: 84
           y: 303
           opacity: 1
           visible : speed_scale.actualScaleSegment== 7
           //visible : false
        }
        Image {
           id: scale_image_08
           source: "speedometer_scale_images/08.png"
           x: 84
           y: 274
           opacity: 1
           visible : speed_scale.actualScaleSegment== 8
           //visible : false
        }
        Image {
           id: scale_image_09
           source: "speedometer_scale_images/09.png"
           x: 84
           y: 245
           opacity: 1
           visible : speed_scale.actualScaleSegment== 9
           //visible : false
        }
        Image {
           id: scale_image_10
           source: "speedometer_scale_images/10.png"
           x: 84
           y: 216
           opacity: 1
           visible : speed_scale.actualScaleSegment== 10
           //visible : false
        }
        Image {
           id: scale_image_11
           source: "speedometer_scale_images/11.png"
           x: 84
           y: 189
           opacity: 1
           visible : speed_scale.actualScaleSegment== 11
           //visible : false
        }
        Image {
           id: scale_image_12
           source: "speedometer_scale_images/12.png"
           x: 84
           y: 162
           opacity: 1
           visible : speed_scale.actualScaleSegment== 12
           //visible : false
        }
        Image {
           id: scale_image_13
           source: "speedometer_scale_images/13.png"
           x: 84
           y: 136
           opacity: 1
           visible : speed_scale.actualScaleSegment== 13
           //visible : false
        }
        Image {
           id: scale_image_14
           source: "speedometer_scale_images/14.png"
           x: 84
           y: 112
           opacity: 1
           visible : speed_scale.actualScaleSegment== 14
           //visible : false
        }
        Image {
           id: scale_image_15
           source: "speedometer_scale_images/15.png"
           x: 84
           y: 88
           opacity: 1
           visible : speed_scale.actualScaleSegment== 15
           //visible : false
        }
        Image {
           id: scale_image_16
           source: "speedometer_scale_images/16.png"
           x: 84
           y: 67
           opacity: 1
           visible : speed_scale.actualScaleSegment== 16
           //visible : false
        }
        Image {
           id: scale_image_17
           source: "speedometer_scale_images/17.png"
           x: 84
           y: 47
           opacity: 1
           visible : speed_scale.actualScaleSegment== 17
           //visible : false
        }
        Image {
           id: scale_image_18
           source: "speedometer_scale_images/18.png"
           x: 84
           y: 30
           opacity: 1
           visible : speed_scale.actualScaleSegment== 18
           //visible : false
        }

        Image {
           id: scale_image_19
           source: "speedometer_scale_images/19.png"
           x: 84
           y: 13
           opacity: 1
           visible : speed_scale.actualScaleSegment== 19
           //visible : false
        }
        Image {
           id: scale_image_20
           source: "speedometer_scale_images/20.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 20
           //visible : false
        }
        Image {
           id: scale_image_21
           source: "speedometer_scale_images/21.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 21
           //visible : false
        }
        Image {
           id: scale_image_22
           source: "speedometer_scale_images/22.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 22
           //visible : false
        }
        Image {
           id: scale_image_23
           source: "speedometer_scale_images/23.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 23
           //visible : false
        }
        Image {
           id: scale_image_24
           source: "speedometer_scale_images/24.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 24
           //visible : false
        }
        Image {
           id: scale_image_25
           source: "speedometer_scale_images/25.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 25
           //visible : false
        }
        Image {
           id: scale_image_26
           source: "speedometer_scale_images/26.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 26
           //visible : false
        }
        Image {
           id: scale_image_27
           source: "speedometer_scale_images/27.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 27
           //visible : false
        }
        Image {
           id: scale_image_28
           source: "speedometer_scale_images/28.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 28
           //visible : false
        }
        Image {
           id: scale_image_29
           source: "speedometer_scale_images/29.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 29
           //visible : false
        }
        Image {
           id: scale_image_30
           source: "speedometer_scale_images/30.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 30
           //visible : false
        }
        Image {
           id: scale_image_31
           source: "speedometer_scale_images/31.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 31
           //visible : false
        }
        Image {
           id: scale_image_32
           source: "speedometer_scale_images/32.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 32
           //visible : false
        }
        Image {
           id: scale_image_33
           source: "speedometer_scale_images/33.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 33
           //visible : false
        }
        Image {
           id: scale_image_34
           source: "speedometer_scale_images/34.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 34
           //visible : false
        }
        Image {
           id: scale_image_35
           source: "speedometer_scale_images/35.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 35
           //visible : false
        }
        Image {
           id: scale_image_36
           source: "speedometer_scale_images/36.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 36
           //visible : false
        }
        Image {
           id: scale_image_37
           source: "speedometer_scale_images/37.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 37
           //visible : false
        }
        Image {
           id: scale_image_38
           source: "speedometer_scale_images/38.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 38
           //visible : false
        }
        Image {
           id: scale_image_39
           source: "speedometer_scale_images/39.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 39
           //visible : false
        }
        Image {
           id: scale_image_40_1
           source: "speedometer_scale_images/40_1.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 40
           //visible : false
        }
        Image {
           id: scale_image_40_2
           source: "speedometer_scale_images/40_2.png"
           x: 596
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 40
           //visible : false
        }

        Image {
           id: scale_image_41_1
           source: "speedometer_scale_images/41_1.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 41
           //visible : false
        }
        Image {
           id: scale_image_41_2
           source: "speedometer_scale_images/41_2.png"
           x: 596
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 41
           //visible : false
        }
        Image {
           id: scale_image_42_1
           source: "speedometer_scale_images/42_1.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 42
           //visible : false
        }
        Image {
           id: scale_image_42_2
           source: "speedometer_scale_images/42_2.png"
           x: 596
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 42
           //visible : false
        }

        Image {
           id: scale_image_43_1
           source: "speedometer_scale_images/43_1.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 43
           //visible : false
        }

        Image {
           id: scale_image_43_2
           source: "speedometer_scale_images/43_2.png"
           x: 596
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 43
           //visible : false
        }

        Image {
           id: scale_image_44_1
           source: "speedometer_scale_images/44_1.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 44
           //visible : false
        }
        Image {
           id: scale_image_44_2
           source: "speedometer_scale_images/44_2.png"
           x: 596
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 44
           //visible : false
        }


        Image {
           id: scale_image_45_1
           source: "speedometer_scale_images/45_1.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 45
           //visible : false
        }


        Image {
           id: scale_image_45_2
           source: "speedometer_scale_images/45_2.png"
           x: 596
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 45
           //visible : false
        }

        Image {
           id: scale_image_46_1
           source: "speedometer_scale_images/46_1.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 46
           //visible : false
        }

        Image {
           id: scale_image_46_2
           source: "speedometer_scale_images/46_2.png"
           x: 596
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 46
           //visible : false
        }


        Image {
           id: scale_image_47_1
           source: "speedometer_scale_images/47_1.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 47
           //visible : false
        }

        Image {
           id: scale_image_47_2
           source: "speedometer_scale_images/47_2.png"
           x: 596
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 47
           //visible : false
        }

        Image {
           id: scale_image_48_1
           source: "speedometer_scale_images/48_1.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 48
           //visible : false
        }

        Image {
           id: scale_image_48_2
           source: "speedometer_scale_images/48_2.png"
           x: 596
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 48
           //visible : false
        }

        Image {
           id: scale_image_49_1
           source: "speedometer_scale_images/49_1.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 49
           //visible : false
        }

        Image {
           id: scale_image_49_2
           source: "speedometer_scale_images/49_2.png"
           x: 596
           y: 0
           opacity: 1
           visible : speed_scale.actualScaleSegment== 49
           //visible : false
        }

    Image {
        id: strelka
        source: "images/strelka.png"
        x: 726
        y: 322
        visible : true


        opacity: 1

        transform : Rotation {
        	id: arrowRotate
        	angle: speed_scale.zero_angle
        	origin.x : -86
        	origin.y : 190


        }
    }

    Text {
        property int speed_value : 0
        id: balance_text
        text : this.speed_value
        font.family: fonts.speedFont.name
		font.pixelSize: 130
        font.bold: true
        color: "#ffffff"
        smooth: true
        x: 640
        y: 425.5
        width:0
        opacity: 1     
        horizontalAlignment: Text.AlignHCenter  
    }





    }


}

