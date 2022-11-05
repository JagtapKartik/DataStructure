/*
 * modbusrtu.h
 *
 *  Created on: 16-Aug-2021
 *      Author: Kartik
 */

#ifndef MODBUSRTU_H_
#define MODBUSRTU_H_

#include "slave.h"

class modbus_rtu: public slave {
public:
	void parse_frame( uint8_t *frame);
	void check_crc( uint8_t *frame);
	void read_coil( int startaddress, int count );
	void read_holding_register( int startaddress, int count );
	void read_input_register( int startaddress, int count );
	void write_coil( int startaddress, int count, uint8_t data );
	void write_holding_register( int startaddress,int count, uint8_t data );
	void create_response_frame( void );
	modbus_rtu();
	virtual ~modbus_rtu();
};

#endif /* MODBUSRTU_H_ */
