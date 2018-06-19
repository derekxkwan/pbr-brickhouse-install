#ifndef Pbpixelbank_h
#define Pbpixelbank_h

#define N_BANK 5
#define MAX_BRIGHTNESS 1.0
#define MAX_COLOR 255
#define GRAIN 10
#define FADETIME 3000
#include <Adafruit_NeoPixel.h>

class PbPixelbank
{
 public:
  PbPixelbank(int pin[N_BANK], int perstrip);
  void incFade(void);
  void setState(int val);
  int perstrip;
  bool bFade;
  int grain; //grain in millis


 private:
  Adafruit_NeoPixel _strip[N_BANK];
  float * _bDiff(void);
  bool checkState(void);
  void setPrevState(void);
  int _color[N_BANK][3];
  int _state[N_BANK];
  int _prevstate[N_BANK];
  int _brightness[N_BANK];
  int _fadetime; //fadetime in millis
  int _fadeidx; //current position in fading
  
};
#endif
