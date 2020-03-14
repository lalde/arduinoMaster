

int ttl_out_bottomC = 12; // pinout for TTL pulse to bottom camera
int ttl_out_status = 11; // pinout for TTL pulse to know general state of arduino (ie is it recording or not)
int userInput;

int freq = 60; // which sampling rate do you want, in Hz
int pulse = (1000 / freq) / 2; //duration of the high state

void setup() {
  //open the serial port
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Talk to me");
  //set ttl pin to output
  pinMode(ttl_out_bottomC, OUTPUT);
  pinMode(ttl_out_status, OUTPUT);
}

void loop() {
  digitalWrite(ttl_out_status, HIGH);
  digitalWrite(ttl_out_bottomC, HIGH);
  delay(pulse);
  digitalWrite(ttl_out_bottomC, LOW);
  delay(pulse);

}
