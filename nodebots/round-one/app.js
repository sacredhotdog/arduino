var johnnyFive = require("./../johnny-five/"),
    board = new johnnyFive.Board();

board.on("ready", function() {
    (new johnnyFive.Led(13));
});

