class Star {
  private float x;
  private float y;
  private float z;

  public Star() {
    this.x = random(-width, width);
    this.y = random(-height, height);
    this.z = random(1, width);
  }

  public void update() {
    this.z -= 8;
    if(z < 1){
      this.x = random(-width, width);
      this.y = random(-height, height);
      this.z = width;
    }
  }

  public void show() {
    float px = map(this.x/z, 0, 1, width/2, width);
    float py = map(this.y/z, 0, 1, height/2, height);
    float sz = map(this.z, 1, width, 16, 3);
    
    fill(255);
    ellipse(px, py, sz, sz);
  }
}
