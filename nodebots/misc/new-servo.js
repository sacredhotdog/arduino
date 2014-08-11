var five = require("../../johnny-five/lib/johnny-five"),
    board;

board = new five.Board();

board.on("ready", function() {
    var myServo = new five.Servo(9);

    board.repl.inject({
        servo: myServo
    });


    this.wait(5000, function(){
        myServo.center();
    });  

    board.loop(5000, function() {
        myServo.center();
        myServo.stop();
        myServo.sweep();
        myServo.stop();
    });
});

