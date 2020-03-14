

int ttl_out_bottomC = 12; // pinout for TTL pulse to bottom camera
int ttl_out_status = 11; // pinout for TTL pulse to know general state of arduino (ie is it recording or not)
int userInput;

int freq = 60; // which sampling rate do you want, in Hz
int pulse = (1000 / freq) / 2; //duration of the high state
int recording_length_min = 10;  //duration of the recording, in minutes
int recording_length_ms = recording_length_min * 60000; //convert it in ms
int itt = 2 * pulse;
int num_loops = recording_length_ms / itt; //1 loop equals 2 x pulse, so how many loops do you need to cover your recording session



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

  if (Serial.available() > 0) {
    userInput = Serial.parseInt();

    if  (userInput == 1) {
      digitalWrite(ttl_out_status, HIGH);
      Serial.println("Recording started");
      int var = 0;
      do {
        digitalWrite(ttl_out_bottomC, HIGH);
        delay(pulse);
        digitalWrite(ttl_out_bottomC, LOW);
        delay(pulse);
        var++;
      } while (var < num_loops);

      if (var = num_loops) {
        digitalWrite(ttl_out_status, LOW);
        digitalWrite(ttl_out_bottomC, LOW);
        Serial.println("Time's up! Recording stopped");
      }

      else if (userInput == 0) {
        digitalWrite(ttl_out_status, LOW);
        Serial.println("Master asks, Arduino obeys. Recording stopped");
      }
    }
  }
}
