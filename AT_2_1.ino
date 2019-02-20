/*
Arduino Tutorial 2.1 - RGB LED Farben per Taster wechseln
 
In diesem Tutorial geht es darum einer RGB-LED Farben zuzuweisen und diese eingestellten Farbprogramme mit einem Taster durchzuschalten.
 
by Scynd 2015
http://www.scynd.de/tutorials/arduino-tutorials.html
*/

#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_RGB + NEO_KHZ800);

// Konstanten 
const int tasterPin = 2;     // Taster an Pin 2 angeschlossen
const int LEDPin = 13;       // Rote LED an Pin 10 angeschlossen

// Variablen
int lichtmodus = 0;          // Variable für die verschiedenen festgelegten Farben

void loop() {
   tasterAbfrage();
   ausgabe();  
 
}
void tasterAbfrage()
{
 
 if tasterState != tasterState_alt // bei Pegelwechsel 
    {
     debounce_time=millis();
     if(!tasterState)//wenn Taster gedrückt
        State=!State;
        tasterState_alt = tasterState; // state aktualisieren
        }
}
void ausgabe()

void setup()
{
  pinMode(tasterPin, INPUT);      // Setzt den TasterPin als Eingang 
  pinMode(LEDPin, OUTPUT);        // Setzt den LEDPin als Ausgang
 
} 


void loop()
{ 
  // Abfrage ob der Taster gedrückt ist
  tasterState != tasterState_alt;
  
  // Wenn Taster gedrückt ist...
  if(!tasterState)//wenn Taster gedrückt
        State=!State;
        tasterState_alt = tasterState; // state aktualisieren
  {
    lichtmodus++;     // Lichtmodus +1
    delay(300);       // 300ms warten
  }
  
  //+++++++++++++++ LEUCHTPROGRAMME +++++++++++++++++
  
  // Modus 0 = Licht aus  
  if (lichtmodus == 0)
  {
	strip.setPixelColor(i, strip.Color(0, 0, 0)); //LED aus, (0, 0, 0));
    strip.show();
    digitalWrite(ledPin, HIGH);
  }
  
  // Modus 1 = Blau  
  else if (lichtmodus == 1)
  {     
	strip.setPixelColor(i, strip.Color(0, 0, 255)); //Blau, (0, 0, 255));
    strip.show();
    digitalWrite(ledPin, HIGH);
  }
  
  
  // Modus 2 = Rot  
  else if (lichtmodus == 2)
  {
	strip.setPixelColor(i, strip.Color(255, 0, 0)); //Rot, (255, 0, 0));
    strip.show();
    digitalWrite(ledPin, HIGH);
  }
  
  // Modus 3 = Grün  
  else if (lichtmodus == 3)
  {
	strip.setPixelColor(i, strip.Color(0, 255, 0)); //Grün, (0, 255, 0));
    strip.show();
    digitalWrite(ledPin, HIGH);
  }
  
  // Modus 4 = Lila  
  else if (lichtmodus == 4)
  {    
	strip.setPixelColor(i, strip.Color(0, 255, 0)); //Lila, (255, 0, 255));
    strip.show();
    digitalWrite(ledPin, HIGH);
  }

  // Modus 5 = Weiß  
  else if (lichtmodus == 5)
  {
	strip.setPixelColor(i, strip.Color(255, 255, 255)); //Weiß, (255, 255, 255));
    strip.show();
    digitalWrite(ledPin, HIGH);
  }

  // Anzahl der Leutmodi auf 6 begrenzen. (0 bis 5)
  else
  {
    lichtmodus = 0;
  }
}
