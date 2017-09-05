var ptA = window.innerWidth/2 - 200;
var ptB = window.innerWidth/2 + 200;
var y = window.innerHeight/2;
var moveX = ptA;
var t = 0;
var dir = 1;
var points = [];

var smoothPos = {x:0, y:0};

function setup(){
  createCanvas(window.innerWidth, window.innerHeight);
  for( var i = 0; i < 50; i++){
  	points[i] = {x:i*20,y:window.innerHeight/2,pct:random(.65,.99)};
  }
}

function draw(){
  background(255,255,255,50);
  fill(0);
  stroke(0);
  strokeWeight(4);

  for( var i = 1; i < points.length; i++){
  	pct = points[i].pct;
  	points[i].x = pct*points[i].x + (1-pct)*(mouseX-20);
  	points[i].y = pct*points[i].y + (1-pct)*(mouseY);
    line(points[i].x, points[i].y, window.innerWidth, window.innerHeight/2);
    // line(points[i].x, points[i].y, window.innerWidth/2, window.innerHeight/2);
    line(0, window.innerHeight/2, points[i].x, points[i].y);
  }
}
