int PIN_PULSE = A0;

int PulseSignal;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  PulseSignal = analogRead(PIN_PULSE);

  Serial.print(" ");
  Serial.println(PulseSignal);

  delay(30);
}
