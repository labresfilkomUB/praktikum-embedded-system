#define LED_MERAH   13
#define LED_KUNING  12
#define LED_HIJAU   11
#define TOMBOL      2
  
int state = 1;
int input_sblm = HIGH;
int tepi_naik = HIGH;

void state_1();
void state_2();
void state_3();
void state_4();

void setup() {
  pinMode(LED_MERAH, OUTPUT);
  pinMode(LED_KUNING, OUTPUT);
  pinMode(LED_HIJAU, OUTPUT);
  pinMode(TOMBOL, INPUT_PULLUP);
}

void loop() {
  int input = digitalRead(TOMBOL);
  
  if(input == LOW && input_sblm == HIGH){
    input_sblm = input;
  }
  else if(input == HIGH && input_sblm == LOW){
    input_sblm = input;
    tepi_naik = LOW;
  }
       
  switch(state){
    case 1:
      state_1();
      if(tepi_naik == LOW){
        state = 2;
      }
      break;
    case 2:
      state_2();
      if(tepi_naik == LOW){
        state = 3;
      }
      break;
    case 3:
      state_3();
      if(tepi_naik == LOW){
        state = 4;
      }
      break;
    case 4:
      state_4();
      if(tepi_naik == LOW){
        state = 1;
      }
      break;
  }
  
  tepi_naik = HIGH;
}

void state_1() {
  digitalWrite(LED_MERAH, HIGH);
  digitalWrite(LED_KUNING, HIGH);
  digitalWrite(LED_HIJAU, HIGH);
}
void state_2(){
  digitalWrite(LED_MERAH, HIGH);
  digitalWrite(LED_KUNING, LOW);
  digitalWrite(LED_HIJAU, LOW);
}
void state_3(){
  digitalWrite(LED_MERAH, LOW);
  digitalWrite(LED_KUNING, HIGH);
  digitalWrite(LED_HIJAU, LOW);
}
void state_4(){
  digitalWrite(LED_MERAH, LOW);
  digitalWrite(LED_KUNING, LOW);
  digitalWrite(LED_HIJAU, HIGH);
}
