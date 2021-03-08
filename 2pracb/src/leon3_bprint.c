/*
 * leon3_bprint.c

 *
 *  Created on: 06/03/2021
 *      Author: arantxa
 */
#include "leon3_bprint.h"
#include "leon3_uart.h"

int8_t leon3_print_string(char *c){
	int pos = 0;
	int a =1;
	while(a==1){
		if(c[pos] != '\0'){
		leon3_putchar(c[pos]);
		pos=pos+1;
		}
		else{
			a=0;
		}

	}
	return 0;
}
int8_t leon3_print_uint8(uint8_t c){

	int8_t centenas, decenas, unidades;
	centenas =  c/100;
	decenas = (c-centenas*100)/10;
    unidades = c - centenas*100 - decenas*10;

	if(centenas>0) {
		leon3_putchar('0' + centenas);
		if(decenas == 0){
			leon3_print_uint8(0);
		}
	}

	if(decenas>0) {
		leon3_putchar('0' + decenas);
	}

	leon3_putchar('0' + unidades);


	return 0;
}

