var five = require("../../../../johnny-five/lib/johnny-five.js"),
    board = new five.Board();

board.on("ready", function() {
//    var myServo = new five.Servo(9);

    var temp = 0.0;
    var temperatureSensor = new five.Sensor("A0");

    temperatureSensor.on("data", function() {
        var voltage = (this.value / 1024.0) * 5.0;
        temp = (voltage - 0.5) * 100;

        console.log(" -> temperature sensor: voltage = " + voltage + "\ttemperature = " + temp);
    });

//    myServo.sweep();

//    this.wait(5000, function(){
//        myServo.stop();
//        myServo.center();
//    });

    board.loop(500, function() {
        var coldThreshold = 18;
        var warmThreshold = 20;
        var hotThreshold = 22;

        if (temp <= coldThreshold) {
        }

        if (temp > coldThreshold && temp <= warmThreshold) {
        }

        if (temp > hotThreshold) {
        }
    });

});

