final int QTD_WORDS = 70;
final int WORD_SIZE = 15;

Word words[];

void setup() {
  size(900, 500); 
  words = new Word[QTD_WORDS];
  for(int i = 0; i < QTD_WORDS; i++){
     words[i] = new Word(); 
  }
}

void draw() {
  background(0);
  for(Word word: words){
   word.show();
   word.update();
  }
}
