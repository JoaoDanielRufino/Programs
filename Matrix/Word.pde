class Word {
  private char word[];
  private float x;
  private float y;
  private float ySpeed;

  public Word() {
    this.word = randomWord();
    this.x = random(0, width);
    this.y = random(-800, -50);
    this.ySpeed = random(1, 5);
  }

  private char randomChar() {
    return (char) random(33, 126);
  }

  private char[] randomWord() {
    char c[] = new char[WORD_SIZE];
    for (int i = 0; i < c.length; i++) {
      c[i] = randomChar();
    }
    return c;
  }

  public void update() {
    this.y += this.ySpeed;
    if (this.y > height + (15 * WORD_SIZE)) {
      this.x = random(0, width);
      this.y = random(-200, -50);
    }

    for (int i = 0; i < WORD_SIZE; i++) {
      int r = (int) random(2, 31);
      if ((frameCount % r) == 0)
        word[i] = randomChar();
    }
  }

  public void show() {
    int count = 0;
    for (int i = 0; i < WORD_SIZE; i++) {
      fill(0, 220, 0);
      textSize(13);
      text(word[i], this.x, this.y-count);
      count += 15;
    }
  }
}
