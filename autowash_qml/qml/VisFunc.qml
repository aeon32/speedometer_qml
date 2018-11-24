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



    	onScaleSegmentsChanged :
    	{
    	    var scaleSegmentsStr = ''
    	    var actualScale = this.scaleSegments


    	    if (actualScale < 10 )
    	        scaleSegmentsStr = '0' + actualScale
    	    else if (this.scaleSegments > this.scale_segments_n - 1)
    	    {    
    	        
    	        actualScale = this.scale_segments_n - 1
    	        scaleSegmentsStr =  actualScale.toString()
    	    } else {

    	    	scaleSegmentsStr = actualScale.toString()
    	    }

    	    console.log(this.speedValue + " " +scaleSegmentsStr)    	 

	    	var coords = {x:84, y:0}
    		switch (actualScale)
    		{
       		  case 1: coords = {x:108, y:459}; break;
       		  case 2: coords = {x:97, y:436}; break;
       		  case 3: coords = {x:92, y:414}; break;
       		  case 4: coords = {x:89, y:386}; break;
       		  case 5: coords = {x:84, y:359}; break;
       		  case 6: coords = {x:84, y:332}; break;
       		  case 7: coords = {x:84, y:303}; break;
       		  case 8: coords = {x:84, y:274}; break;
       		  case 9: coords = {x:84, y:245}; break;
       		  case 10: coords = {x:84, y:216}; break;       		         		         		         		  
       		  case 11: coords = {x:84, y:189}; break;
       		  case 12: coords = {x:84, y:162}; break;
       		  case 13: coords = {x:84, y:136}; break;
       		  case 14: coords = {x:84, y:112}; break;
       		  case 15: coords = {x:84, y:88}; break;
       		  case 16: coords = {x:84, y:67}; break;
       		  case 17: coords = {x:84, y:47}; break;
       		  case 18: coords = {x:84, y:30}; break;
       		  case 19: coords = {x:84, y:13}; break;
       		  case 20: coords = {x:84, y:0}; break;       		         		         		         		         		  


    		}
    		scale_image_bottom.x = coords.x;
    		scale_image_bottom.y = coords.y;



    		scale_image_bottom.source = "speedometer_scale_images/" + scaleSegmentsStr + '.png'


    	}

    	onSpeedValueChanged : {
    	    //this.speedValue = 200
            var auxSpeedValue = this.speedValue

            if (auxSpeedValue > this.scale_size)
                auxSpeedValue = this.scale_size;


            this.arrow_angle =  auxSpeedValue * scale_angle / scale_size + zero_angle
    	    
    	    var newScaleSegments = Math.floor(auxSpeedValue* scale_segments_n / scale_size) 

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
     		  animateBalanse.speed_value = this.speedValue

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
    	

    
        Image {
           id: scale_image_bottom
           source: "speedometer_scale_images/00.png"
           x: 84
           y: 0
           opacity: 1
           visible : speed_scale.speedValue > 0
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
