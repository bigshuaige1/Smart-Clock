#include "SC32F1XXX.h"
#include "SC_it.h"

struct RTC_CLOCK
{
		uint32_t year;
	  uint32_t mon;
	  uint32_t day;
		uint32_t hour;
		uint32_t min;
	  uint32_t sec;
		uint32_t week;
};

extern struct RTC_CLOCK rtc_clock;
extern volatile uint16_t btm_interrupt_count;
extern uint8_t dayofweek;
void RTC_SetTime(uint16_t year,uint16_t mon,uint16_t day,uint16_t hour,uint16_t min);
void time_go(void);
