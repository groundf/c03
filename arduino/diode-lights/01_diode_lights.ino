/*
  Program zapíná a vypíná zadané porty na kterých jsou 
  zapojeny diody. 
 */

int DELAY_MS = 1000;
int R_PIN = 2;
int B_PIN = 3;
int G_PIN = 4;
  

void setup() {
  // put your setup code here, to run once:
  // pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

/**
 *  Open the pin with a given number for a given time in milliseconds.
 */
void flash_diode(int pin_num, int time_ms) {
  digitalWrite(pin_num, HIGH);
  delay(time_ms);
  digitalWrite(pin_num, LOW);
}

void loop() {
    // read the value from sensor in range 0--1023.
    int sensor_value = analogRead(A0); 
    
    // Set the delay in milliseconds.
    int delay = sensor_value;

    // Flash the diods.
    flash_diode(R_PIN, delay);
    flash_diode(G_PIN, delay);
    flash_diode(B_PIN, delay);
}
