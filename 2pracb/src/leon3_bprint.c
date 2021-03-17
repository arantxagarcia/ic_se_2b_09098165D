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
	//OK, pero mejor si tratas errores 
    //int8_t error=0;
    //while(c[pos]!='\0'&&(!error)){
      //error=leon3_putchar(c[pos]);
	
	while(a==1){
		if(c[pos] != '\0'){
		leon3_putchar(c[pos]);
		pos=pos+1;
		}
		else{
			a=0;
		}

	}
	//return error;
	return 0;
}
int8_t leon3_print_uint8(uint8_t c){

	int8_t centenas, decenas, unidades;
	centenas =  c/100;
	decenas = (c-centenas*100)/10;
    unidades = c - centenas*100 - decenas*10;

//El código funciona bien, 
	//pero se puede hacer de forma iterativa con un while 
	//en vez de usar if else if... 
	//Sería algo así
	//int8_t error=0;
	//int8_t first_digit=0;
	
	//if(i==0)
	//	leon3_putchar('0');
	//else{
		//while(i&&(!error)){
		// uint8_t aux=100; // aux para extraer dígitos
		
		// aux=aux/10; //centenas->decenas->unidades
		//} 
		
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

	//return error; //trata el error
	return 0;
}

