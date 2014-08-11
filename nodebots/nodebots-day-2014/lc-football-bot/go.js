var keypress = require('keypress');

var FootballBot = require('footballbot');
var bot = new FootballBot('/dev/rfcomm0');


// make `process.stdin` begin emitting 'keypress' events
keypress(process.stdin);

bot.on('ready', function() {
    var leftMotor = bot.attach(new FootballBot.Motor({pins: {pwm: 9, dir: 7}}));
    var rightMotor = bot.attach(new FootballBot.Motor({pins: {pwm: 10, dir: 8}}));
    var motorsStarted = false;

    var leftSpeed = 0;
    var rightSpeed = 0;

    leftMotor.speed(leftSpeed);
    rightMotor.speed(rightSpeed);

    function startMotors() {
        if (!motorsStarted) {
            leftMotor.start();
            rightMotor.start();
            motorsStarted = true;
        }
    }

    function stopMotors() {
        if (motorsStarted) {
            leftMotor.stop();
            rightMotor.stop();
            motorsStarted = false;
        }
    }

    // listen for the 'keypress' event
    process.stdin.on('keypress', function(ch, key) {
        if (!key) return;

        if (key.name == 'up') {
            leftMotor.forward();
            rightMotor.forward();
            startMotors();
        } else if (key.name == 'down') {
            leftMotor.reverse();
            rightMotor.reverse();
            startMotors();
        } else if (key.name == 'left') {
            leftMotor.forward();
            rightMotor.reverse();
            startMotors();
        } else if (key.name == 'right') {
            leftMotor.reverse();
            rightMotor.forward();
            startMotors();
        } else if (key.name == 'q') {
            stopMotors();
        } else if (key.ctrl && key.name == 'c') {
            process.exit();
        }
    });

    process.stdin.setRawMode(true);
    process.stdin.resume();
});

