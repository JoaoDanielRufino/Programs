class Drop{
 private PVector pos;
 private float len;
 private float ySpeed;
 
 public Drop(){
   this.pos = new PVector(random(width), random(-500, -50), random(0, 20));
   this.len = map(this.pos.z, 0, 20, 10, 40);
   this.ySpeed = map(this.pos.z, 0, 20, 6, 15);
 }
 
 public void update(){
   this.pos.y += this.ySpeed;
   if(this.pos.y > height)
     this.pos.y = random(-500, -50);
 }
 
 public void show(){
   strokeWeight(2);
   stroke(138, 43, 226);
   line(this.pos.x, this.pos.y, this.pos.x, this.pos.y+len);
 }
 
}
