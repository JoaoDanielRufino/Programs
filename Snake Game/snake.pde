class Snake {
  private PVector headPos;
  private int xSpeed;
  private int ySpeed;
  private ArrayList<PVector> tail;
  private int len;

  public Snake() {
    this.headPos = new PVector(0, 0);
    this.xSpeed = 0;
    this.ySpeed = 0;
    this.tail = new ArrayList();
    this.len = 0;
  }

  public boolean eatFood(Food food) {
    if (dist(this.headPos.x, this.headPos.y, food.getX(), food.getY()) < 10) {
      this.len++;
      return true;
    } else {
      return false;
    }
  }

  public boolean hitTail() {
    for (PVector v : this.tail) {
      if (dist(this.headPos.x, this.headPos.y, v.x, v.y) < 3) {
        return true;
      }
    }
    return false;
  }

  public void setSpeed(int x, int y) {
    this.xSpeed = x;
    this.ySpeed = y;
  }

  public void update() {
    if (this.len > 0) {
      if (!this.tail.isEmpty() && this.tail.size() == this.len)
        this.tail.remove(0);
      this.tail.add(new PVector(this.headPos.x, this.headPos.y));
    }

    this.headPos.x += xSpeed;
    this.headPos.y += ySpeed;

    if (this.headPos.x > width) {
      this.headPos.x = 0;
    } else if (this.headPos.x < 0) {
      this.headPos.x = width;
    }

    if (this.headPos.y > height) {
      this.headPos.y = 0;
    } else if (this.headPos.y < 0) {
      this.headPos.y = height;
    }
  }

  public void show() {
    fill(255);
    for (PVector v : this.tail) {
      rect(v.x, v.y, 15, 15);
    }
    rect(this.headPos.x, this.headPos.y, 15, 15);
  }
}
