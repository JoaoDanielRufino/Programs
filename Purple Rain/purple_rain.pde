int QTD_DROPS = 500;
ArrayList<Drop> drops;

void setup(){
 size(900, 550);
 drops = new ArrayList();
 for(int i = 0; i < QTD_DROPS; i++){
   drops.add(new Drop()); 
 }
}

void draw(){
  background(230, 230, 250);
  for(int i = 0; i < drops.size(); i++){
    drops.get(i).show();
    drops.get(i).update();
  }
}
