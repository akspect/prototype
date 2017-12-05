//-----------------
//processing 3.3.3
//save image sequence which was written number.
//
//user setting
//-----------------

String imgName = "num";
String imgExtention = "png";
int startNum = 0;
int totalNum = 5;
int fontSize = 100;
color textColor = color(0, 0, 100);
color bgColor = color(80, 80, 80, 255);// RGBA

//If you want to change the dimension of display window,
//please rewrite the size() function setting inside setup().
//-----------------

PGraphics pg;

void setup() {
  size(300, 200);
  pg = createGraphics(width, height, JAVA2D);
  
  noLoop();
}

void draw(){
  
  for(int i = startNum; i<(totalNum+startNum); i++){
    background(bgColor);
    
    pg.beginDraw();
    pg.smooth();
    pg.background(bgColor);
    pg.fill(255);
    pg.textAlign(CENTER,TOP);
    pg.textSize(fontSize);
    
    float ascent = pg.textAscent();//bottom
    float descent = pg.textDescent();//top
    float textHeight = ascent - descent;
    int textPosY = int((height-textHeight)/2-descent);
    
    pg.text(i, width/2, textPosY);
    
    pg.endDraw();
    image(pg,0,0);
    pg.save( "data/"+ imgName + String.format("%04d", i) + "." + imgExtention );
  }
}