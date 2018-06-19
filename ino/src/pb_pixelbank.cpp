#include "pb_pixelbank.h"
#include <Arduino.h>

PbPixelbank::PbPixelbank(int pin[N_BANK], int perstrip)
{
  int i;
  for(i=0; i <N_BANK; i++)
    {
      _state[i] = 0;
      _prevstate[i] = 0;
      _color[i] = {MAX_COLOR, MAX_COLOR, MAX_COLOR};
      _brightness[i] = 0;
      _strip[i] = Adafruit_NeoPixel(perstrip, pin[i], NEO_GRB + NEO_KHZ800);
      _strip[i].begin;
      _strip[i].show;
      _fadetime = FADETIME;
      grain = GRAIN;
    }

  bFade = false;
  perstrip = perstrip;
  _fadeidx = 0;

    
}

float * PbPixelbank::bDiff(void)
{
  int i;
  float diff[N_BANK];
  for(i=0; i<N_BANK; i++)
      diff[i] = (float)grain * MAX_BRIGHTNESS *((float)_state[i]/(float)_fadetime);
  return diff;
}

void PbPixelbank::incFade(void)
{
  int i,j;
  float diff[N_BANK] = PbPixelbank::bDiff();
  if(_fadeidx < _fadetime)
    {
      for(i=0; i < N_BANK; i++)
	{
	  int cur_brightness = (int)((MAX_BRIGHTNESS * _prevstate[i]) + (diff[i] * -fadeidx));
	  int cur_color[3];
	  cur_brightness = cur_brightness < 0.0 ? 0.0 : (cur_brightness > MAX_BRIGHTNESS ? MAX_BRIGHTNESS : cur_brightness);
	  cur_color = {(int)(_color[i][0] * cur_brightness),(int)(_color[i][1] * cur_brightness),(int)(_color[i][2] * cur_brightness)};
	  for(j=0; j < perstrip; i++)
	    _strip[i].setPixelsColor(j, _strip[i].Color(cur_color[0],cur_color[1],cur_color[2]));
	  _strip[i].show();
	};
    }
  else
    {
      bFade = false;
    };
  
}

void PbPixelbank::checkState(void)
{
  int i;
  bool equal = true;
  for(i=0; i < N_BANK; i++)
    {
      if(_state[i] != _prevstate[i]) equal = false;
    };
}

void PbPixelbank::setPrevState(void)
{
  int i;
  for(i=0; i < N_BANK; i++)
      _prevstate[i] = _state[i];
  
}

void PbPixelbank::setState(int val)
{
  int i;
  val = val < 0 ? 0 (val > N_BANK ? N_BANK : val);
  for(i=0; i < N_BANK; i++)
    {
      if(i < val)
	_state[i] = 1;
      else _state[i] = 0;
      
    };

  for(i=0; i < N_BANK; i++)
    {
      int pos = random(N_BANK);
      int temp = _state[i];
      _state[i] = _state[pos];
      _state[pos] = temp;
    };

  bFade = true;
  _fadeidx = 0;
  
}
