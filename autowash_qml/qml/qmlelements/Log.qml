import QtQuick 2.2
Item { 
    id : log
	function debug(str) {
		console.log(str);

	}
        function error(str) {
		console.error(str);

	}




}