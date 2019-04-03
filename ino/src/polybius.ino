//length of word_bank
#define BANK_LEN 820
//length of pos_bank
#define POS_LEN 38
//length of each letter in ms
#define LETTER_LEN 5000
//length between words in ms
#define PAUSE_LEN 5000

//define starting pin idxs for left and right bank
#define LEFT_0 2
#define RIGHT_0 8

#define PINS_PER_BANK 5

#define  DEBUG 0
// word_bank are all the letter pairs sequentially and flattened with delimiters of 6
// ie [1_l, 1_r, 2_l, 2_r, ... n_l, n_r, 6,....

// pos_bank gives the position in the array of each word start


const uint16_t word_bank[] PROGMEM = 
{3, 5, 3, 4, 3, 5, 2, 4, 1, 1, 2, 3, 6, 5, 4, 4, 5, 3, 2, 1,
3, 2, 3, 1, 1, 6, 1, 5, 2, 2, 2, 2, 4, 4, 1, 1, 4, 2, 4, 4, 4,
3, 6, 4, 2, 2, 4, 1, 3, 1, 5, 1, 5, 5, 1, 1, 5, 4, 2, 5, 4, 1,
4, 2, 4, 3, 3, 3, 3, 1, 5, 4, 2, 6, 5, 5, 3, 4, 3, 3, 2, 2, 5,
5, 2, 4, 6, 1, 2, 3, 4, 4, 4, 1, 1, 3, 3, 4, 2, 2, 4, 1, 3, 1,
5, 1, 3, 1, 1, 3, 3, 1, 4, 5, 4, 6, 2, 3, 1, 1, 5, 2, 2, 1, 3,
1, 1, 1, 2, 5, 1, 5, 4, 3, 6, 4, 3, 2, 3, 1, 1, 4, 2, 2, 5, 2,
1, 2, 4, 3, 3, 4, 3, 3, 4, 4, 5, 3, 5, 6, 1, 2, 2, 4, 4, 2, 1,
4, 4, 3, 3, 3, 1, 5, 4, 3, 4, 4, 4, 3, 3, 4, 4, 5, 3, 5, 6, 5,
1, 2, 4, 4, 4, 1, 1, 4, 3, 3, 4, 5, 4, 4, 3, 3, 4, 5, 4, 6, 1,
3, 2, 3, 4, 2, 5, 4, 4, 3, 1, 1, 3, 3, 4, 4, 2, 3, 1, 5, 3, 2,
4, 5, 3, 2, 4, 4, 1, 5, 1, 1, 6, 1, 3, 2, 3, 2, 4, 3, 3, 1, 5,
4, 3, 1, 5, 3, 2, 1, 5, 1, 4, 2, 4, 1, 3, 2, 4, 3, 3, 1, 5, 6,
4, 2, 3, 4, 1, 1, 4, 3, 4, 4, 1, 4, 4, 5, 1, 3, 2, 5, 6, 4, 3,
5, 2, 1, 5, 1, 5, 4, 4, 1, 1, 3, 3, 1, 4, 4, 3, 3, 4, 4, 5, 4,
2, 3, 5, 3, 4, 4, 2, 2, 5, 6, 4, 4, 3, 4, 3, 2, 1, 1, 4, 4, 3,
4, 1, 5, 2, 2, 2, 2, 4, 3, 6, 5, 2, 3, 4, 3, 3, 4, 4, 3, 4, 3,
3, 4, 3, 3, 4, 4, 5, 3, 5, 6, 3, 1, 1, 1, 3, 5, 1, 3, 2, 3, 1,
5, 3, 4, 3, 3, 2, 2, 6, 1, 3, 1, 5, 3, 3, 4, 4, 4, 5, 4, 2, 5,
4, 1, 5, 2, 2, 2, 2, 6, 1, 3, 3, 4, 3, 3, 2, 2, 1, 5, 1, 5, 6,
5, 2, 2, 4, 3, 3, 4, 4, 1, 5, 4, 2, 3, 2, 1, 5, 3, 1, 3, 4, 3,
3, 6, 1, 4, 2, 4, 3, 2, 4, 3, 4, 5, 3, 2, 6, 2, 1, 3, 1, 3, 4,
4, 3, 4, 3, 5, 4, 3, 5, 3, 4, 4, 2, 2, 5, 6, 2, 3, 3, 4, 4, 4,
1, 1, 3, 3, 1, 4, 4, 3, 3, 4, 4, 5, 4, 2, 4, 3, 3, 4, 4, 5, 3,
5, 6, 4, 2, 2, 4, 1, 2, 1, 5, 3, 3, 1, 1, 6, 1, 2, 3, 1, 1, 1,
1, 3, 2, 5, 1, 3, 4, 5, 4, 2, 4, 2, 1, 1, 3, 3, 4, 4, 6, 2, 4,
2, 4, 1, 1, 3, 3, 1, 4, 4, 5, 2, 4, 6, 1, 3, 2, 3, 1, 1, 4, 3,
2, 4, 4, 5, 1, 2, 1, 1, 3, 4, 6, 4, 4, 2, 4, 3, 3, 2, 2, 4, 4,
2, 4, 3, 3, 2, 2, 2, 4, 1, 1, 2, 3, 1, 5, 6, 4, 3, 4, 4, 1, 1,
4, 2, 2, 1, 4, 2, 4, 5, 2, 4, 4, 4, 6, 3, 1, 3, 4, 3, 3, 2, 2,
1, 1, 3, 3, 6, 3, 1, 5, 4, 1, 3, 2, 3, 1, 5, 1, 5, 6, 4, 2, 2,
4, 1, 3, 1, 5, 2, 4, 3, 3, 4, 3, 3, 4, 4, 5, 3, 5, 6, 1, 3, 1,
5, 3, 1, 3, 1, 3, 4, 3, 5, 2, 3, 1, 1, 3, 3, 1, 5, 3, 3, 3, 4,
3, 4, 1, 4, 3, 1, 1, 5, 4, 3, 6, 2, 1, 3, 4, 4, 2, 4, 4, 4, 5,
3, 3, 1, 5, 1, 3, 3, 4, 3, 4, 2, 5, 2, 4, 1, 5, 4, 3, 6, 3, 2,
3, 4, 3, 4, 3, 3, 1, 3, 1, 1, 2, 5, 1, 5, 6, 3, 1, 3, 4, 4, 4,
4, 5, 4, 3, 4, 3, 1, 5, 1, 5, 1, 4, 1, 2, 4, 5, 3, 3, 4, 3, 6,
4, 4, 1, 5, 1, 1, 4, 4, 2, 4, 3, 2, 1, 5, 6, 3, 2, 2, 4, 3, 1,
2, 5, 2, 4, 3, 3, 2, 3, 3, 4, 3, 3, 2, 2, 2, 5, 3, 4, 3, 3, 2, 2, 6};

//len = 38
const uint16_t pos_bank[] PROGMEM = 
{0, 13, 26, 43, 74, 87, 116, 135, 160, 187, 208, 241, 272, 291, 324,
345, 366, 385, 406, 419, 442, 455, 476, 505, 518, 543, 558, 577, 602,
621, 634, 647, 668, 703, 732, 749, 776, 791};

//init as 2 for init state, 0 for off, 1 for on
unsigned int led_state[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

uint16_t cur_step = 0; //current step in word

int new_word = 0; //if a new word is needed

uint16_t cur_start = 0; //starting position of current word

unsigned int num_inv =  PINS_PER_BANK + 1; //invalid number of lights
unsigned int cur_left = num_inv; // 6 = init, current lights on left turned on
unsigned int cur_right = num_inv;


//l_r: left = 0, right = 1
uint16_t get_numlights (uint16_t start_idx, unsigned int _cur_step, unsigned int l_r)
{
	uint16_t num_lights = num_inv; // default to none (6)
	uint16_t real_idx = start_idx + (2 * cur_step);
	if(l_r > 0) real_idx += 1;

	if(real_idx < BANK_LEN) num_lights = pgm_read_word_near(word_bank + real_idx);

	return num_lights;
}


//want_on: number of lights wanted on
void set_bank(unsigned int want_on, unsigned int l_r)
{
  unsigned int cur_on = cur_left;
	uint16_t start_pin = LEFT_0;
	unsigned int state_start = 0; //the starting index in led_state
	unsigned int want_state[PINS_PER_BANK] = {0, 0, 0, 0, 0}; //state to set current bank to
	if(l_r > 0)
		{
      cur_on = cur_right;
			start_pin = RIGHT_0;
			state_start = PINS_PER_BANK;
		};

	if(want_on >= 0)
		{
			unsigned int num_to_set = (want_on > PINS_PER_BANK) ? PINS_PER_BANK : want_on;
			while(num_to_set > 0)
				{
					//index in want state we want to set to on
					unsigned int idx_to_set = random(PINS_PER_BANK);
					unsigned int cur_setflag = want_state[idx_to_set];
					//if not already marked to set, set it, else continue on
					if(cur_setflag == 0)
						{
							want_state[idx_to_set] = 1;
						  num_to_set--;
						};

           //if  done assigning lights to set, make sure the lights set changes per letter (if possible)
           // (so we can tell that there are repeated  letters)
           if(num_to_set == 0 && cur_on == want_on && want_on < PINS_PER_BANK)
           {
            unsigned int different = 0;
            for(int i = 0; i < PINS_PER_BANK; i++)
            {
              unsigned int state_idx = state_start + i;
              unsigned int cur_state = led_state[state_idx];
              unsigned int wanted = want_state[i];
              if(wanted != cur_state)
              {
                different = 1;
                break;    
              }; 
            };
            if(different != 1)
            {
              num_to_set = want_on;
              for(int i=0; i <PINS_PER_BANK; i++) want_state[i] =  0;
            };
           };
				};
		

			for(int i = 0; i < PINS_PER_BANK; i++)
				{
					unsigned int pin_num = start_pin + i;
					unsigned int state_idx = state_start + i;
					unsigned int cur_state = led_state[state_idx];
					unsigned int wanted = want_state[i];
					//only set if wanted state doesn't equal current state
					if(cur_state != wanted)
						{
							if(wanted > 0) digitalWrite(pin_num, HIGH);
							else digitalWrite(pin_num, LOW);
							led_state[state_idx] = wanted;
						};
				};
		};


  if(l_r == 0) cur_left = want_on;
  else cur_right = want_on;
}

void set_lights(unsigned int num_left, unsigned int num_right)
{
	set_bank(num_left, 0);
	set_bank(num_right, 1);
}

void setup() {
  if(DEBUG > 0) Serial.begin(9600);

	for(int i = 0; i < PINS_PER_BANK; i++)
		{
			pinMode(LEFT_0 + i, OUTPUT);
			pinMode(RIGHT_0 + i, OUTPUT);
		};

	new_word = 1;
	set_lights(0, 0);
	
}

void loop() {
	uint16_t want_left, want_right;
	int valid;
	if(new_word > 0)
		{
      unsigned int rand_idx = random(POS_LEN); //get a random word's starting position by idx
      cur_start = pgm_read_word_near(pos_bank + rand_idx);
			new_word = 0;
			cur_step = 0;
		};

	want_left = get_numlights(cur_start, cur_step, 0);
  valid = want_left <= PINS_PER_BANK;
  	
	//if valid number of lights
	if(valid > 0)
		{
			want_right = get_numlights(cur_start, cur_step, 1);
      if(want_right<= PINS_PER_BANK)
      {
			  set_lights(want_left, want_right);
			  cur_step += 1;
        if(DEBUG > 0)
        {
          /*
          Serial.print(cur_start);
          Serial.print("+");
          Serial.print(cur_step);
          Serial.print(": ");
          */
          Serial.print(want_left);
          Serial.print(" ");
          Serial.print(want_right);
          Serial.print("\n");
        };
			  delay(LETTER_LEN);
      }
      else valid = 0;
		};
	if(valid  == 0)
		{
			new_word = 1;
			set_lights(0, 0);
     if(DEBUG > 0) Serial.print("\n");
			delay(PAUSE_LEN);
		};

}
