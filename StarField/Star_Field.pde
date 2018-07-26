int QTD_STARS = 100;
ArrayList<Star> stars;

void setup(){
 size(900, 550);
 stars = new ArrayList();
 for(int i = 0; i < QTD_STARS; i++){
   stars.add(new Star());
 }
}

void draw(){
  background(0);
  for(int i = 0; i < QTD_STARS; i++){
    stars.get(i).show();
    stars.get(i).update();
  }
}
