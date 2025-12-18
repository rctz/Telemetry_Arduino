uint8_t EMER_RELAY = 30;

void setup() {
  Serial.begin(9600);
  Serial1.begin(57600);

  pinMode(EMER_RELAY, OUTPUT);
}

void loop() {
  if (Serial1.available()) {
    String data = Serial1.readStringUntil('\n');
    
    uint8_t val = data.toInt();
    if (val == 1) {
      digitalWrite(EMER_RELAY, HIGH);
    } else{
      digitalWrite(EMER_RELAY, LOW);
    }
  }
}