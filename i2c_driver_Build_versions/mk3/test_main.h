#ifndef __MAIN_AURORA_H_INCLUDED
#define _MAIN_AURORA__H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct config{
	    	uint8_t data_id;
	    	uint8_t color_code;
	    	uint8_t refresh_rate[2];
	        uint8_t start_color[3];
	        uint8_t end_color[3];
	        uint8_t step_size;
	        uint8_t mode;
	        uint8_t change_rate[3];
	        uint8_t direction;
	        uint8_t cycles;

	    }config_ascii_t;

typedef struct command{
	        uint8_t data_id;
	        uint8_t command;
}command_ascii_t;

#endif /*MAIN_AURORA_H_ INCLUDED*/
