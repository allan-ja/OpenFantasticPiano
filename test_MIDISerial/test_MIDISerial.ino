byte noteON = 144;//note on command
int LED = 12;

void setup() {
  Serial.begin(9600);
  //Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  MIDImessage(noteON, 60, 100);//turn note on
  digitalWrite(LED, HIGH);
  delay(300);//hold note for 300ms
  MIDImessage(noteON, 60, 0);
  digitalWrite(LED,LOW);//turn note off (note on with velocity 0)
  delay(400);//wait 200ms until triggering next note
}

//send MIDI message
void MIDImessage(byte command, byte data1, byte data2) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}
