#define PIRPIN A0
#define THRESH 2000
#define DURT 5000
#define TIBTWSEND 600000

int motion_started;
int motion_ended;

void sendEmail() {
    String data = String(10);
    Particle.publish("motion_sensor", data, PRIVATE);
}

void setup() {
    motion_started = 0;
    motion_ended = 0;
}

void loop() {
    int rval = analogRead(PIRPIN);
    
    if(rval > THRESH) {
        motion_started = 1;
    }else{
        motion_ended = 1;
    }

    if(motion_started == 1 && motion_ended == 1) {
        sendEmail();
        motion_started = 0;
        motion_ended = 0;
        // delay(TIBTWSEND);
    }else{
        delay(DURT);
    }
}