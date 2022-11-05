/*
 * slave.h
 *
 *  Created on: 16-Aug-2021
 *      Author: Kartik
 */

#ifndef SLAVE_H_
#define SLAVE_H_

class slave {
public:
	void parse_frame( uint8_t *frame) = 0;
	void check_crc( uint8_t *frame)=0;
	void read_coil( int startaddress, int count ) = 0;
	void read_holding_register( int startaddress, int count ) = 0;
	void read_input_register( int startaddress, int count )= 0;
	void write_coil( int startaddress, int count, uint8_t data ) = 0;
	void write_holding_register( int startaddress,int count, uint8_t data ) = 0;
	void create_response_frame( void ) = 0;
};

#endif /* SLAVE_H_ */
