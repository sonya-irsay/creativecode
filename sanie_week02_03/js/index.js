var ptA = window.innerWidth/2 - 200;
var ptB = window.innerWidth/2 + 200;
var y = window.innerHeight/2;
var moveX = ptA;
var t = 0;
var dir = 1;
var points = [];
var str = "abcdefghijklmnopqrstuvwxyz";

var alphaArray = str.split(""); // the argument is a null string, "".
var bg;

var smoothPos = {x:0, y:0};

function setup(){
  bg = loadImage("assets/paper.jpg");
  createCanvas(1280,1007);
  for( var i = 0; i < 25; i++){
  	points[i] = {x:i*20,y:window.innerHeight/2,pct:random(.25,.99)};
  }
}

function draw(){
  background(bg);
  fill(0);
  noStroke();
  textSize(100);

  for( var i = 1; i < points.length; i++){
  	pct = points[i].pct;
  	points[i].x = pct*points[i].x + (1-pct)*mouseX+(random(-15,15));
  	points[i].y = pct*points[i].y + (1-pct)*mouseY+(random(-15,15));
    text(alphaArray[i], points[i].x, points[i].y);
  }
}
