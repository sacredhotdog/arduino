var johnnyFive = require("./johnny-five/lib/johnny-five.js"),
    board = new johnnyFive.Board();

var runTimer = false;

board.on("ready", function () {
    var tiltSwitch = new johnnyFive.Switch(8);

    tiltSwitch.on("close", function () {
        runTimer = true;
        console.log(" -> tilt switch closed...");
    });
    tiltSwitch.on("open", function () {
        runTimer = false;
        console.log(" -> tilt switch opened...");
    });
});

board.loop(1000, function () {
    if (runTimer === true) {
        console.log(" -> runTimer is true");
    }
    else {
        console.log(" -> runTimer is false");
    }
});
