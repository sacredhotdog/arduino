var five = require("../../johnny-five/lib/johnny-five"),
    board = new five.Board();

board.on("ready", function() {
    (new five.Led(13)).strobe();
});

