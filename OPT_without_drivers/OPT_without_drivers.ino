#include <MIDI.h>


MIDI_CREATE_DEFAULT_INSTANCE();

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
  digitalWrite(pitch-47, HIGH);
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
  digitalWrite(pitch-47, LOW);
}

void setHandleStop(void)
 {
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
 }



// -----------------------------------------------------------------------------

void setup()
{
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    
    // Connect the handleNoteOn function to the library,
    // so it is called upon reception of a NoteOn.
    MIDI.setHandleNoteOn(handleNoteOn);  // Put only the name of the function

    // Do the same for NoteOffs
    MIDI.setHandleNoteOff(handleNoteOff);

    MIDI.setHandleStop(setHandleStop);

    // Initiate MIDI communications, listen to all channels
    MIDI.begin(MIDI_CHANNEL_OMNI);
    //Serial.begin(115200);
    Serial.begin(9600);
    
     
   
}

void loop()
{
  
    MIDI.read();  
}
