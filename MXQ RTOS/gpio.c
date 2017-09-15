lwgpio_init(&led1, BSP_LED1, LWGPIO_DIR_OUTPUT, LWGPIO_VALUE_NOCHANGE) 
//Assigning Struct LED1 to GPIO PORT AND PIN, Output direction   
//#define BSP_LED1                    (GPIO_PORT_A | GPIO_PIN11)
//LWGPIO_VALUE_NOCHANGE is a special value in typedef LWGPIO_VALUE
//This special value is for function parameter to remain unchanged when using lwgpio_init



    lwgpio_int_enable(&btn1, TRUE); //btn1 Interupt 

    lwgpio_int_enable(&btn1, FALSE);


lwgpio_set_functionality(&btn1, BSP_BUTTON1_MUX_IRQ); //Set btn1 to IRQ mux
lwgpio_set_functionality(&btn1, BSP_BUTTON1_MUX_GPIO); //Set btn1 to GPIO MUX




#if defined(BSP_BUTTONS_ACTIVE_HIGH)
    lwgpio_set_attribute(&btn1, LWGPIO_ATTR_PULL_DOWN, LWGPIO_AVAL_ENABLE);
#else
    lwgpio_set_attribute(&btn1, LWGPIO_ATTR_PULL_UP, LWGPIO_AVAL_ENABLE);
#endif
//Macro is used to change Pullup or Pulldown resistor on GPIO pin


lwgpio_int_init(&btn1, LWGPIO_INT_MODE_FALLING);
//Enable btn1 GPIO to trigger on Falling Edge of signal. 


_int_install_isr(lwgpio_int_get_vector(&btn1), int_service_routine, (void *) &btn1);
/* install gpio interrupt service routine */
    