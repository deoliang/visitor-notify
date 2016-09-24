#define PIRPIN D6
#define DURT 2000
#define DELAYFORLEAVE 5000

int flag = 0;
bool sendeds = false;
bool sendede = false;
int motion_started = 0;
int motion_ended = 0;

void sendStartStatus(String s) {
  if(sendeds == false) {
    Particle.publish("motion_sensor", s, PRIVATE);
    sendeds = true;
  }
}

void sendEndStatus(String t) {
  if(sendede == false) {
    Particle.publish("motion_sensor", t, PRIVATE);
    sendede = true;
  }
}

void setup() {
  pinMode(PIRPIN, INPUT);
}

void loop() {
  if (digitalRead(PIRPIN) == HIGH) {
    flag = 1;
    sendStartStatus("start");
  } else {
    if (flag) {
      flag = 0;
      delay(DELAYFORLEAVE);
      sendEndStatus("end");
    }
  }
  delay(DURT);
  if(sendeds == true && sendede == true) {
    sendeds = false;
    sendede = false;
  }
}
