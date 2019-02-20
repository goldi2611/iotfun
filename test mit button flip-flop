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
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

// constants won't change. They're used here to set pin numbers:
const int tasterPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
bool tasterState, tasterState_alt, State;// Variablendeklaration (global)

void setup() {
  Serial.begin(115200);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(tasterPin, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  for (byte i=0;i<7;i++)   strip.setPixelColor(i, strip.Color(0, 0, 255)); //Blue, 60 Pixels
  strip.show();
  delay(1000);
}

void loop() {
   tasterAbfrage();
   ausgabe();  
 
}
void tasterAbfrage()
{
 const byte debounce_delay = 10;
 static uint32_t debounce_time;
 if (millis()-debounce_time>debounce_delay)tasterState = digitalRead(tasterPin); //einlesen des Tasters
   
 if (tasterState != tasterState_alt) // bei Pegelwechsel 
    {
     debounce_time=millis();
     if(!tasterState)//wenn Taster gedrückt
        State=!State;
        tasterState_alt = tasterState; // state aktualisieren
        }
}
void ausgabe()
{
    if (!State) {
    for (byte i=0;i<7;i++) strip.setPixelColor(i, strip.Color(255, 127, 0)); //Orange, 60 Pixels(255, 127, 0));
    strip.show();
    digitalWrite(ledPin, HIGH);
  } else {
         for (byte i=0;i<7;i++) strip.setPixelColor(i, strip.Color(0, 0, 255)); //Blue, 60 Pixels(0, 0, 255));
         strip.show();
         }
}
