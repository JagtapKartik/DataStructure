/*
 * main.c
 *
 *  Created on: 04-Aug-2020
 *      Author: Kartik
 */

#include <stdio.h>
#include <stdint.h>

typedef void (*timer_callback) (void);

typedef struct
{
	 uint16_t time_remaining;// Timer starts at 0, so callback is triggered
	 // When time_remaining goes to 0, this reload value is stored back to time_remaining
	 uint16_t timer_reload_value;
	 timer_callback callback;
}timer_s;

timer_s timers_example[2];

void timer_0_callback(void) {
// just for test
puts("Timer 0 Callback");
//Restart timer 0 here
}
void timer_1_callback(void) {
// just for test
puts("Timer 1 Callback");
//Restart timer 1 here
}

void timer_periodic_task(timer_s* timers, size_t timers_array_size) {
// TODO

}

int main(void)
{
	timers_example[0].time_remaining = 0U;
	timers_example[0].timer_reload_value = 5U;
	timers_example[0].callback = timer_0_callback;

	timers_example[1].time_remaining = 3U;
	timers_example[1].timer_reload_value = 7U;
	timers_example[1].callback = timer_1_callback;

	while(1)
	{
		timer_periodic_task(timers_example, 2);
	}
	return 0;
}

