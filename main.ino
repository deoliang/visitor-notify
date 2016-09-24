#define PIRPIN D6
#define DURT 2000

int flag = 0;
String status = String(5);

void sendStatus(String s) {
  Particle.publish("motion_sensor", s, PRIVATE);
}

void setup() {
  pinMode(PIRPIN, INPUT);
}

void loop() {
  if (digitalRead(PIRPIN) == HIGH) {
    flag = 1;
    sendStatus("start");
  } else {
    if (flag) {
      flag = 0;
      sendStatus("end");
    }
  }
  delay(DURT);
}
