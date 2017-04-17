var gpio = require('rpi-gpio');

gpio.on('export', function(channel) {
  console.log('Channel set: ' + channel);
});


var pins = [7, 11, 12, 13, 15, 16, 18, 22];

var digits = [
  [7, 13, 11, 16, 15, 22],
  [15, 16],
  [22, 15, 18, 13, 11],
  [22, 15, 18, 16, 11],
  [7, 18, 15, 16],
  [22, 7, 18, 16, 11],
  [22, 7, 13, 18, 11, 16],
  [22, 15, 16],
  [22, 7, 15, 18, 13, 16, 11],
  [22, 15, 16, 18, 7, 11]
]


var swichPins = [29, 31, 32, 33];
var delay = 200;
var count = 0;
var position = 0;

initPorts(0, pins.concat(swichPins), function() {
  var intervalID = setInterval(function() {
    // console.log(count, position);
    showDigit(count, position);
    position++;
    if (position > 3) {
      position = 0;
    }
  }, 10);

  var intervalForCount = setInterval(function() {
    count++;
    if (count > 9) {
      count = 0;
      closePins();
      clearInterval(intervalForCount);
    }
  }, 1000);

});


function initPorts(i, pins, call) {
  var k = i + 1;
  if (i < pins.length) {
    console.log(pins[i]);
    gpio.setup(pins[i], gpio.DIR_OUT, function() {
      initPorts(k, pins, call);
    });
  } else {
    call();
  }
}


function showDigit(n, nn) {
  //offSwichPins();
 // console.log(nn);
 if (nn > 0) {
    gpio.write(swichPins[nn - 1], 1);
  } else {
    gpio.write(swichPins[3], 1);
  }
  digits[n].forEach(function(pin, i, arr) {
    if (i == arr.length - 1) {
      gpio.write(pin, 1, pause(offPins, 10));
    } else {
      gpio.write(pin, 1);
    }
  });
  gpio.write(swichPins[nn], 0);
}


function pause(call, time) {
  setTimeout(call, time);
}

function offPins() {
  pins.forEach(function(pin) {
    gpio.write(pin, 0);
  })
}

function offSwichPins() {
  swichPins.forEach(function(pin) {
    gpio.write(pin, 1);
  });
}

function closePins() {
  gpio.destroy(function() {
    console.log('All pins unexported');
  });
}



/*

  22
7    15
  18
13   16
  11   12

 */
