#include "SC_Init.h"	// MCU initialization header file, including all firmware library header files
#include "SCDriver_List.h"
#include "shizhong.h"
#include "HeadFiles\SC_itExtern.h"

struct RTC_CLOCK rtc_clock;

//求月份的天数
uint16_t getDaysInMonth(uint16_t year, uint16_t month) 
{
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;  // 闰年2月29天，平年2月28天
        default:
            return 0; // 非法月份
    }
}

//蔡勒公式求星期几
uint8_t ZellerCongruence(uint16_t year,uint16_t mon,uint16_t day) 
{
    if (mon == 1 || mon == 2) {
        mon += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int h = day + 13 * (mon + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;
    return (h + 5) % 7 + 1; // 0=Saturday, 1=Sunday, 2=Monday, ..., 6=Friday
}

//将设定的日期传入结构体，用于后续计算和显示时钟
void RTC_SetTime(uint16_t year,uint16_t mon,uint16_t day,uint16_t hour,uint16_t min)
{
	rtc_clock.year=year;
	rtc_clock.mon=mon;
	rtc_clock.day=day;
	rtc_clock.hour=hour;
	rtc_clock.min=min;
}

void time_go(void)
{
  while(1)
   {
        //嵌套语句完成进位
	  int8_t i=0;
	  if(i!=btm_interrupt_count)
	  {
	    i=btm_interrupt_count;
		if(i>=60)
		{
					rtc_clock.min++;
					btm_interrupt_count=0;
					i=0;
			
			if(rtc_clock.min>=60)
			{
					rtc_clock.hour++;
			
			if(rtc_clock.hour>=24)
				{
				    rtc_clock.hour=0;
					rtc_clock.day++;
			
			if(rtc_clock.day>=getDaysInMonth(rtc_clock.year,rtc_clock.mon))
				  {
					  rtc_clock.day=1;
					  rtc_clock.mon++;
			 
			if(rtc_clock.mon>=12)
				    {
					    rtc_clock.mon=1;
				    	rtc_clock.year++;
					}
				  }
				}
			}
		}
	    //计算星期几
		uint8_t dayofweek;
		uint8_t getdayOfWeek = ZellerCongruence(rtc_clock.year,rtc_clock.mon,rtc_clock.day);
	    switch (getdayOfWeek) 
	      {
	        case 1: dayofweek=7; // Sunday
	        case 2: dayofweek=1; // Monday
	        case 3: dayofweek=2; // Tuesday
	        case 4: dayofweek=3; // Wednesday
	        case 5: dayofweek=4; // Thursday
	        case 6: dayofweek=5; // Friday
	        case 0: dayofweek=6; // Saturday
	        default:dayofweek=0; // Error
	      }
	   }
	   else break;
   }
}


