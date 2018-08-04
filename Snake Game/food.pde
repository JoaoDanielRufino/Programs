class Food {
  private PVector pos;

  public Food() {
    this.pos = new PVector(random(10, width-10), random(10, height-10));
  }

  public void update() {
    this.pos.x = random(10, width-10);
    this.pos.y = random(10, height-10);
  }

  public void show() {
    fill(255, 0, 100);
    rect(this.pos.x, this.pos.y, 15, 15);
  }

  public float getX() {
    return this.pos.x;
  }

  public float getY() {
    return this.pos.y;
  }
}
