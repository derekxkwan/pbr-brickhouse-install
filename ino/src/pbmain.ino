#include <Adafruit_NeoPixel.h>
#include "pb_pixelbank.h"

#define NUM_STR 500
#define MAX_LEN 100
#define LTR_LEN 15000 //length of each letter
#define GAP 20000 //gap between each string

PbPixelbank left_bank;
int left_pin[] = {2,3,4,5,6};
int right_pin[]; {7,8,9,10,11};
int cur_str;
int cur_idx; //1-idx, 0 idx is for size
int cur_len; //length of current string
bool new_word; //if we want a new word
// number of strings, max string length, 2 elts per character
int my_text[NUM_STR][MAX_LEN][2];
Pbpixelbank right_bank;

void setup() {
     left_bank = new PbPixelbank(left_pin, 1);
     right_bank = new PbPixelbank(right_pin, 1);
     cur_str = 0;
     cur_idx = 0;
     cur_len = 0;
     new_word = true;
     
}

void loop () {
     if(new_word == true)
     {
	if(left_bank.bFade == true || right_bank.bFade == true)
	{
		left_bank.incFade();
		right_bank.incFade();
		delay(GRAIN);
	}
	else
	{	
		cur_len = 0;
		while(cur_len < 0)
		{
			cur_idx = random(NUM_STR);
			cur_len = my_text[cur_str][cur_idx][0];
		};
		cur_idx = 0;
		int new_val[2] = my_text[cur_str][cur_idx];
		left_bank.setState(new_val[0]);
		right_bank.setState(new_val[1]);
		new_word == false;
		delay(GAP);
	};	
     }
     else
     {
     	if(left_bank.bFade == true || right_bank.bFade == true)
	{
		left_bank.incFade();
		right_bank.incFade();
		delay(GRAIN);
	};
	else
	{
		if(cur_idx <= my_text[cur_str][cur_idx][0])
		{
			cur_idx = cur_idx + 1;
			int new_val[2] = my_text[cur_str][cur_idx];
			left_bank.setState(new_val[0]);
			right_bank.setState(new_val[1]);
			delay(LTR_LEN);
		}
		else
		{
			new_word = true;
			left_bank.setState(0);
			right_bank.setState(0);

		};
	};
     };
}