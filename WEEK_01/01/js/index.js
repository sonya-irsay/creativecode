var ptA = window.innerWidth/2 - 200;
var ptB = window.innerWidth/2 + 200;
var y = window.innerHeight/2;
var moveX = ptA;
var t = 0;
var dir = 1;

var smoothPos = {x:0, y:0};

function setup(){

  createCanvas(window.innerWidth, window.innerHeight);
}

function draw(){
  background(0,0,0,70);
  noStroke();
  fill(255);

  t += .01 * dir;
  if(t <= 0 || t >= 1) dir *= -1;

  var pct = pow(t,5.5);

  pct = pow(t, 5.5);
  drawMotion(y - 50, pct, 5);

  pct = t*t;
  drawMotion(y, pct, 10);

  pct = t*t*t;
  drawMotion(y + 50, pct, 15);

  pct = t<.5 ? 2*t*t : -1+(4-2*t)*t;
  drawMotion(y + 100, pct, 20);
}

function drawMotion(yOffset, pct, radCircle){
    moveX = (1-pct) * ptA + pct * ptB;
    ellipse(moveX, yOffset, radCircle, radCircle);
}
