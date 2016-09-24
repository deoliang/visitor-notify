#define PIRPIN D6
#define DURT 2000

int flag = 0;

void sendStatus() {
  
}

void setup() {
  pinMode(PIRPIN, INPUT);
}

void loop() {
  if (digitalRead(PIRPIN) == HIGH) {
    flag = 1;
  } else {
    if (flag) {
      flag = 0;
    }
  }
  delay(DURT);
}
