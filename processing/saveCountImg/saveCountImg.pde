//-----------------
//processing 3.3.3
//save image sequence which was written number while compile.
//
//user setting
//-----------------

String imgName = "count";
String imgExtention = "jpg";
int textSize = 100;
color textColor = color(255, 255, 255);
color bgColor = color(0, 0, 0);

//If you want to change the dimension of display window,
//please rewrite the size() function setting inside setup().
//-----------------

int num;
PImage img;

void setup() {
  size(200, 200);
  num = 0;
  textSize(textSize);
  textAlign(CENTER,TOP);
  fill(textColor);
  background(bgColor);
}

void draw() {
  background(bgColor);
  float ascent = textAscent();//bottom
  float descent = textDescent();//top

  int textYPos = int((height-(ascent-descent))/2+(0-descent));

  text(num, width/2, textYPos);
  save( "data/"+ imgName + String.format("%04d", num) + "." + imgExtention );
  num ++;
}