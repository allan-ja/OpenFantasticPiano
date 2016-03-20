#include <MIDI.h>
#include "Tlc5940.h"

MIDI_CREATE_DEFAULT_INSTANCE();

// -----------------------------------------------------------------------------
// This function will be automatically called when a NoteOn is received.
// It must be a void-returning function with the correct parameters,
// see documentation here:
// http://arduinomidilib.fortyseveneffects.com/a00022.html

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
   MIDI.sendNoteOn(pitch,velocity,channel);  //envoie la note à l'orgue
   Tlc.set(pitch-21, 4095);                  //allume la led
   while(Tlc.update());                      //force l'update sur le  tlc5940 
   
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
  MIDI.sendNoteOff(pitch,velocity,channel);  //envoie la note à l'orgue
 
  Tlc.set(pitch-21, 0);
    
while(Tlc.update());


    // Do something when the note is released.
    // Note that NoteOn messages with 0 velocity are interpreted as NoteOffs.
}

 void setHandleStop(void)
 {
      Tlc.clear();
 
    Tlc.update();
 }

// -----------------------------------------------------------------------------

void setup()
{
  Serial.begin(31250); 
    // Connect the handleNoteOn function to the library,
    // so it is called upon reception of a NoteOn.
    MIDI.setHandleNoteOn(handleNoteOn);  // Put only the name of the function

    // Do the same for NoteOffs
    MIDI.setHandleNoteOff(handleNoteOff);

 MIDI.setHandleStop(setHandleStop);

    // Initiate MIDI communications, listen to all channels
    MIDI.begin(MIDI_CHANNEL_OMNI);
    
    
    Tlc.init();
   Tlc.clear();
 
    Tlc.update();
}

void loop()
{
    // Call MIDI.read the fastest you can for real-time performance.
    MIDI.read();

    // There is no need to check if there are messages incoming
    // if they are bound to a Callback function.
    // The attached method will be called automatically
    // when the corresponding message has been received.
}
