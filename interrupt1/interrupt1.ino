const uint8_t MOTOR_LEFT_DIR_PIN = 4;
const uint8_t MOTOR_LEFT_SPEED_PIN = 5;
const uint8_t MOTOR_RIGHT_DIR_PIN = 7;
const uint8_t MOTOR_RIGHT_SPEED_PIN = 6;
const uint8_t COLL_RIGHT_PIN = 2;    // Right collision detector PIN
const uint8_t COLL_RIGHT_ISR = 0;   // interrupt ID for PIN 2
const uint8_t COLL_LEFT_PIN = 3;   // Left collision detector PIN
const uint8_t COLL_LEFT_ISR = 1;   // interrupt ID for PIN 3

const uint8_t FORWARD = LOW;
const uint8_t BACKWARD = HIGH;

volatile int speed = 250;

void set_speed(uint8_t left, uint8_t right) {
    analogWrite(MOTOR_LEFT_SPEED_PIN, left);
    analogWrite(MOTOR_RIGHT_SPEED_PIN, right);
}

void set_direction(uint8_t left, uint8_t right) {
    digitalWrite(MOTOR_LEFT_DIR_PIN, left);
    digitalWrite(MOTOR_RIGHT_DIR_PIN, right);
}

void setup() {
    // inital states
    pinMode(MOTOR_LEFT_DIR_PIN, OUTPUT);
    pinMode(MOTOR_LEFT_SPEED_PIN, OUTPUT);
    pinMode(MOTOR_RIGHT_DIR_PIN, OUTPUT);
    pinMode(MOTOR_RIGHT_SPEED_PIN, OUTPUT);
    pinMode(COLL_LEFT_PIN, INPUT);
    pinMode(COLL_RIGHT_PIN, INPUT);
    attachInterrupt(COLL_RIGHT_ISR, blink, FALLING);
    attachInterrupt(COLL_LEFT_ISR, blink, FALLING);

    digitalWrite(MOTOR_LEFT_DIR_PIN, LOW);
    digitalWrite(MOTOR_LEFT_SPEED_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_DIR_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_SPEED_PIN, LOW);
    
    // setup
    set_direction(!FORWARD, !FORWARD);
    set_speed(100, 0);    
}
void blink() {
    set_speed(0,0);  
}


void loop() {
  delay(1000);
}
