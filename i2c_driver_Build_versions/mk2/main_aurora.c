
#include "AURORA_I2C.h"


/***********************************
* Private Prototypes
***********************************/


void display_result(config_ascii_t *configuration_t,command_ascii_t *command);

int main()
{
	uint16_t result;
	uint16_t config;
	config_ascii_t configuration;
	command_ascii_t command;
	/* Init I2C hardware. */
      BOARD_InitBootPins();
      BOARD_InitBootClocks();
      BOARD_InitDebugConsole();

	config = init_i2c_tranfer();
	if(config == MASTER_CONFIGURED ){

	  PRINTF("\n\rConfigured as MASTER");

//		    command.data_id    = '0';
//		    command.command    = 'p';
//
//
//
//		    configuration.data_id    = '1';
//		    configuration.color_code = '3';
//		    configuration.refresh_rate[0]='r';
//		    configuration.refresh_rate[1]='9';
//		    configuration.start_color[0] = 's';
//		    configuration.start_color[1] = '1';
//		    configuration.start_color[2] = '5';
//		    configuration.end_color[0] = 'e';
//		    configuration.end_color[1] = '4';
//		    configuration.end_color[2] = '2';
//		    configuration.step_size ='6';
//		    configuration.mode = '1';
//		    configuration.change_rate[0] = 'c';
//		    configuration.change_rate[1] = '2';
//		    configuration.change_rate[2] = '8';
//		    configuration.direction = '3';
//		    configuration.cycles = '4';

		    result = i2c_send_data(NULL,&command);
		    if(result == SENDCOMMAND_SUCCESS || result ==SENDCONFIG_SUCCESS){
		    	PRINTF("\n\rTRANSFER SUCCESSFULL");
		    }else{
		    	PRINTF("\n\rTRANSFER FAILED");
		    }
	}

	else if(config == SLAVE_CONFIGURED){
		PRINTF("\n\r Configured as SLAVE");
        while(result !=RECIEVECONFIG_SUCCESS && result != RECIEVECOMMAND_SUCCESS){
        result = i2c_recieve_data(NULL,&command);
	}
	    if (result ==RECIEVECONFIG_SUCCESS || result == RECIEVECOMMAND_SUCCESS){
	    	PRINTF("\n\rRECEPTION SUCCESSFULL");
	    	display_result(NULL,&command);
	    }else{
	    	PRINTF("\n\rRECEPTION FAILED");
	    }
	}

	return 0;
}

void display_result(config_ascii_t *configuration,command_ascii_t *command)
{
	if(configuration != NULL)
	{
	        PRINTF("\n\rData_ID = %c",configuration->data_id);
		    PRINTF("\n\rColor_Code= %c",configuration->color_code);
		    PRINTF("\n\rRefresh Rate = ");
		       for(uint32_t i =0;i<2;i++)
		       {
		       	PRINTF("%c",configuration->refresh_rate[i]);
		       }

		    PRINTF("\n\rSTART_COLOR = ");
		    for(uint32_t i =0;i<3;i++)
		        {
		        	PRINTF("%c,",configuration->start_color[i]);
		        }
		     PRINTF("\n\rEND_COLOR = ");
		    for(uint32_t i =0;i<3;i++)
		         {
		           PRINTF("%c,",configuration->end_color[i]);
		         }
		     PRINTF("\n\rCHANGE RATE = ");
		    for(uint32_t i =0;i<3;i++)
		         {
		           PRINTF("%c,",configuration->change_rate[i]);
		         }
		     PRINTF("\n\rStepSize = %c",configuration->step_size);
		     PRINTF("\n\rMode = %c",configuration->mode);
		     PRINTF("\n\rDirection = %c",configuration->direction);
		     PRINTF("\n\rCycles = %c",configuration->cycles);
	}
	else
	{
		PRINTF("\n\rData_ID = %c",command->data_id);
		PRINTF("\n\rCommand= %c",command->command);
	}
}
