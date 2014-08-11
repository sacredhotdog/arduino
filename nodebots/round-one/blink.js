var johnnyFive = require("./johnny-five/lib/johnny-five.js"),
    board = new johnnyFive.Board();

board.on("ready", function() {

    led = johnnyFive.Led({
        pin: 13
    })

    var ledOn = true;

    board.loop(1000, function() {
        ledOn ? led.on() : led.off();
        ledOn = !ledOn;
    });

});