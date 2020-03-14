int ttl_out_bottomC = 12; // pinout for TTL pulse to bottom camera
int ttl_out_status = 11; // pinout for TTL pulse to know general state of arduino (ie is it recording or not)
int userInput;

int freq = 60; // which sampling rate do you want, in Hz
float pulse = (1000 / freq) / 2; //duration of the high state
int recording_length_min = 10;  //duration of the recording, in minutes
long recording_length_ms = recording_length_min * 60000; //convert it in ms
long startedTime = 0;
bool startTimer = false;

void executeOnTimer() {
  if(startTimer) {
    digitalWrite(ttl_out_bottomC, HIGH);
    delay(pulse);
    digitalWrite(ttl_out_bottomC, LOW);
    delay(pulse);
    
    if ((millis() - startedTime) > recording_length_ms ) {
      digitalWrite(ttl_out_status, LOW);
      digitalWrite(ttl_out_bottomC, LOW);
      Serial.println("Time's up! Recording stopped");
      startTimer = false;
    }
  }
}

void manageUserInputs() {
  if (Serial.available() > 0) {
    userInput = Serial.parseInt();

    if  (userInput == 1) {
      digitalWrite(ttl_out_status, HIGH);
      Serial.println("Recording started");
      startTimer = true;
      startedTime = millis();
    } else if (userInput == 0) {
      digitalWrite(ttl_out_status, LOW);
     	startTimer = false;
      Serial.println("Master asks, Arduino obeys. Recording stopped");
    }
  }
}

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
  executeOnTimer();
  manageUserInputs();
}
