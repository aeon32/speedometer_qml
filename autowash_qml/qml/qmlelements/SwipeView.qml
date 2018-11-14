import QtQuick 2.0

ListView
{
    id: root

    // Allow to add pages as you would for a QtQuick.Controls 2 SwipeView
    // Each item you declare in your SwipeView will be reparented to itemModel
    default property alias items: itemModel.children

    // SwipeView is horizontal
    orientation: Qt.Horizontal

    // Hide out of bounds pages
    clip: true

    // Do not stop between two pages
    //snapMode: ListView.SnapToItem

    //flicking: false;


    // Update currentIndex as you swipe through the pages
    highlightRangeMode: ListView.StrictlyEnforceRange

    model: VisualItemModel {
        id: itemModel
        // Used to bind the pages size to the swipeView size
        onChildrenChanged: {
            for(var i=0;i<children.length; i++)
            {
                children[i].width = Qt.binding(function(){return root.width})
                children[i].height = Qt.binding(function(){return root.height})
            }
        }
    }

}
