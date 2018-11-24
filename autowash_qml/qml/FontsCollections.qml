import QtQuick 2.2

Item {
    id:fonts

    FontLoader { id: basicFont_; source: "fonts/agavalanchec.otf" }
    FontLoader { id: boldFont_; source: "fonts/agavalanchec-bold.otf" }

    FontLoader { id: speedFont_; source: "fonts/helvetica-bold.otf" }
    


    property FontLoader basicFont : basicFont_
    property FontLoader boldFont : boldFont_
    property FontLoader speedFont : speedFont_



}
