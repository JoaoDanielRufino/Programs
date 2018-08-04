Snake snake;

Food food;

void setup() {
  size(500, 300);
  frameRate(20);
  snake = new Snake();
  food = new Food();
}

void draw() {
  background(51);

  snake.update();
  snake.show();

  food.show();

  if (snake.eatFood(food)) {
    food.update();
  }

  if (snake.hitTail()) {
    println("DEAD");
    noLoop();
  }
}

void keyPressed() {
  if (keyCode == UP) {
    snake.setSpeed(0, -10);
  } else if (keyCode == DOWN) {
    snake.setSpeed(0, 10);
  } else if (keyCode == LEFT) {
    snake.setSpeed(-10, 0);
  } else if (keyCode == RIGHT) {
    snake.setSpeed(10, 0);
  }
}
