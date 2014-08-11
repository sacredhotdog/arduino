//var johnnyFive = require("../johnny-five/lib/johnny-five"),
var johnnyFive = require("johnny-five/lib/johnny-five"),
	board = new johnnyFive.Board();

board.on("ready", function() {
	(new johnnyFive.Led(13)).strobe();
});
