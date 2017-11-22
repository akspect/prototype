//-----------------
//processing 3.3.3
//save image sequence which was written number while compile.
//
//user setting
//-----------------

String imgName = "count";
String imgExtention = "jpg";
int startNum = 0;
int totalNum = 11;
int fontSize = 100;
color textColor = color(255, 255, 255);
color bgColor = color(0, 0, 0);

//If you want to change the dimension of display window,
//please rewrite the size() function setting inside setup().
//-----------------

int num;
PImage img;

void setup() {
  size(200, 200);
  textSize(fontSize);
  textAlign(CENTER,TOP);
  fill(textColor);
  
  for(int i = startNum; i<(totalNum+startNum); i++){
    background(bgColor);
    float ascent = textAscent();//bottom
    float descent = textDescent();//top
    int textYPos = int((height-(ascent-descent))/2+(0-descent));
    text(i, width/2, textYPos);
    save( "data/"+ imgName + String.format("%04d", i) + "." + imgExtention );
  }
}