void BOARD_InitPins(void)
{

	    CLOCK_EnableClock(kCLOCK_PortE);  						   /* Port E Clock Gate Control: Clock enabled */
	    CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */



	    const port_pin_config_t portc4_pin4_config = {
	    		kPORT_PullUp ,                                            /* Internal pull-up resistor is enabled */
				kPORT_SlowSlewRate,                                      /* Slow slew rate is configured ,No need here beccause the pin is Configured as INPUT*/
	   	        kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
				kPORT_OpenDrainDisable,                                   /* Open drain is Disabled */
	   	        kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
				kPORT_MuxAsGpio,                                           /* Pin is configured as I2C0_SCL */
	   	        kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
	   	      };


	    PORT_SetPinConfig(PORTC, 4U,&portc4_pin4_config);



	    const port_pin_config_t porte24_pin31_config = {
	        kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
	        kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
	        kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
	        kPORT_OpenDrainEnable,                                   /* Open drain is enabled */
	        kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
	        kPORT_MuxAlt5,                                           /* Pin is configured as I2C0_SCL */
	        kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
	      };
	      PORT_SetPinConfig(PORTE, 24U, &porte24_pin31_config); /* PORTE24 (pin 31) is configured as I2C0_SCL */
	      const port_pin_config_t porte25_pin32_config = {
	        kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
	        kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
	        kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
	        kPORT_OpenDrainEnable,                                   /* Open drain is enabled */
	        kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
	        kPORT_MuxAlt5,                                           /* Pin is configured as I2C0_SDA */
	        kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
	      };
	      PORT_SetPinConfig(PORTE, 25U, &porte25_pin32_config); /* PORTE25 (pin 32) is configured as I2C0_SDA */
}
