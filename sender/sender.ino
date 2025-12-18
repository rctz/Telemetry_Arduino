// #include <SoftwareSerial.h>

const int SENSOR_PINS[] = {22, 24, 26, 28};
const int EMER_BUTTON_PIN = 50;

struct SensorGroup {
  bool s1_active;
  bool s2_active;
  bool s3_active;
  bool s4_active;
  bool s5_active;
};

void setup() {
  Serial.begin(9600);    // เอาไว้ดูใน Serial Monitor ของตัวส่งเอง
  Serial1.begin(57600);  // Baud rate ของ Telemetry (ปกติ 57600)

  for (int i = 0; i < 4; i++) {
    pinMode(SENSOR_PINS[i], INPUT_PULLUP);
  }

  pinMode(EMER_BUTTON_PIN, INPUT_PULLUP);
}

SensorGroup readSensor(){
  SensorGroup sensors;
  sensors.s1_active = (digitalRead(SENSOR_PINS[0]) == LOW);
  sensors.s2_active = (digitalRead(SENSOR_PINS[1]) == LOW);
  sensors.s3_active = (digitalRead(SENSOR_PINS[2]) == LOW);
  sensors.s4_active = (digitalRead(SENSOR_PINS[3]) == LOW);
  sensors.s5_active = (digitalRead(SENSOR_PINS[4]) == LOW);

  return sensors;
}

uint8_t emerReader(){
  uint8_t emerFlag= digitalRead(EMER_BUTTON_PIN);
  return emerFlag;
}


void loop() {
  SensorGroup sensors = readSensor();
  uint8_t emerActive = emerReader();

  uint8_t finalFlag = 0;
  if (sensors.s1_active || sensors.s2_active || sensors.s3_active || sensors.s4_active || emerActive) {
    finalFlag = 1;
  }
  Serial.println("Sent");

  Serial1.println(finalFlag);

  delay(200); 
}