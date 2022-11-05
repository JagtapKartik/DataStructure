/*
 * main.c
 *
 *  Created on: 11-Aug-2021
 *      Author: Kartik
 */


#include<stdio.h>
#include<stdint.h>

#define LEFT_SHIFT( VAR  )   				( VAR = VAR << 1 )
#define RIGHT_SHIFT( VAR )	 				( VAR = VAR >> 1 )
#define TOGGLE_BIT( VAR, BITNUM )			( VAR ^=  1 << BITNUM )
#define TOGGLE_GROUP( VAR, POS, MASK )		( VAR ^= ( MASK = MASK << POS ) )
#define SET_BIT( VAR, POS )					( VAR |= 1 << POS )
#define CLEAR_BIT( VAR, POS )				( VAR &= ~(1 << POS ))

void check_endian( void )
{
	int var = 0xABCD;
	printf("[%x]\n",var);
	uint8_t u8var1 = 0, u8var2 = 0;
	u8var1 = var & 0xFF;
	printf("lsb[%x]\n",u8var1);
	u8var2 = var >> 8 ;
	printf("msb[%x]\n",u8var2);
}

int main( void )
{
#if 0
	int lvar = 16;
	LEFT_SHIFT( lvar );
	printf("result l [%d] [%x]\n", lvar, lvar);
	int rvar = 16;
	RIGHT_SHIFT( rvar );
	printf("result r [%d] [%x]\n", rvar, rvar);
	int tvar = 16;
	TOGGLE_BIT( tvar, 1 );
	printf("result t [%d] [%x]\n", tvar, tvar);
	int tgvar = 00, mask = 0xF;
	TOGGLE_GROUP( tgvar, 3, mask );
	printf("result tg [%d] [%x]\n", tgvar, tgvar);
	int svar = 2;
	SET_BIT( svar, 0);
	printf("result s [%d] [%x]\n", svar, svar);
	int cvar = 3;
	CLEAR_BIT(cvar, 1);
	printf("result c [%d] [%x]\n", cvar, cvar);
#endif
	check_endian();
	return 0;
}

