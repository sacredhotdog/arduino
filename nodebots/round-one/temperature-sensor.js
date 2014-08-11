var johnnyFive = require("./johnny-five/lib/johnny-five.js"),
    board = new johnnyFive.Board();

board.on("ready", function() {

    var coldLed = johnnyFive.Led({ pin: 2 });
    var warmLed = johnnyFive.Led({ pin: 3 });
    var hotLed = johnnyFive.Led({ pin: 4 });

    var temp = 0;

    var temperatureSensor = new johnnyFive.Sensor("A0");
    temperatureSensor.on("data", function() {
        var voltage = (this.value / 1024.0) * 5;
        temp = (voltage - 0.5) * 100;

        console.log(" -> temperature sensor = " + temp);
    });

    board.loop(500, function() {
        var coldThreshold = 18;
        var warmThreshold = 20;
        var hotThreshold = 22;

        if (temp <= coldThreshold) {
            coldLed.on();
            warmLed.off();
            hotLed.off();
        }

        if (temp > coldThreshold && temp <= warmThreshold) {
            coldLed.on();
            warmLed.on();
            hotLed.off();
        }

        if (temp > hotThreshold) {
            coldLed.on();
            warmLed.on();
            hotLed.on();
        }
    });

});
