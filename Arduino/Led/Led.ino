#define led1 D4                 // Make "led" variable as GPIO2
#define led2 2

void setup() {
  pinMode(led1, OUTPUT);       // Make "led" pin as output
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);    // Turn LED off
  digitalWrite(led2, LOW);
  delay(1000);                // 1 second delay
  digitalWrite(led1, LOW);     // Turn LED On
  digitalWrite(led2, HIGH);
  delay(1000);                // 1 second delay
}
