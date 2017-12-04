//-----------------
//processing 3.3.3
//save image sequence which was written number.
//
//user setting
//-----------------

String imgName = "num";
String imgExtention = "png";
int startNum = 0;
int totalNum = 1;
int fontSize = 120;
color textColor = color(0, 0, 100);
color bgColor = color(80, 80, 80);

//If you want to change the dimension of display window,
//please rewrite the size() function setting inside setup().
//-----------------

int num;

void setup() {
  size(300, 500);
  textSize(fontSize);
  textAlign(CENTER,TOP);
  fill(textColor);
  
  for(int i = startNum; i<(totalNum+startNum); i++){
    background(bgColor);
    float ascent = textAscent();//bottom
    float descent = textDescent();//top
    float textHeight = ascent - descent;
    int textPosY = int((height-textHeight)/2-descent);
    text(i, width/2, textPosY);
    save( "data/"+ imgName + String.format("%04d", i) + "." + imgExtention );
  }
}