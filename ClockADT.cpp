// ClockADT.cpp definition
#include "ClockADT.h"

Clock::Clock(int hr=0, int min=0, int sec=0) //Default constructor initializes to zero
{
	Clock::setHr(hr);
	Clock::setMin(min);
	Clock::setSec(sec);
	Clock::setBits();
}

int Clock::setSec(int sec)  //Returns 1 if valid, 0 if invalid just for any possible
{							// future validation that might be wanted
	if(sec>=0 && sec<=59)
	{
		second=sec;
		return 1;
	}
	else return 0;
}

int Clock::setMin(int min)
{
	if(min>=0 && min<=59)
	{
		minute=min;
		return 1;
	}
	else return 0;
}

int Clock::setHr(int hr)
{
	if(hr>=0 && hr<=12)
	{
		hour=hr;
		return 1;
	}
	else if(hr>12 && hr<=24) // Convert to 12 hour clock display
	{
		hour=hr-12;
	}
	else return 0;
}

void Clock::setBits() // Just the binary to decimal math function, inserts bits to a vector
{
  int sec=second, min=minute, hr=hour;
  
  for(int i=0; i<6; ++i) // 6 LED states = 6 iterations, fills zeroes in unused LEDS
  {
    //~ bits.insert(bits.begin(), sec%2);
    bits.push_back(sec%2);
    sec=sec/2;
  }

  for(int i=0; i<6; ++i)
  {
    //~ bits.insert(bits.begin(), min%2);
    bits.push_back(min%2);
    min=min/2;
  }

  for(int i=0; i<4; ++i)
  {
    //~ bits.insert(bits.begin(), hr%2);
    bits.push_back(hr%2);
    hr=hr/2;
  }
}

int Clock::getSec() const
{
  return second;
}

int Clock::getMin() const
{
  return minute;
}

int Clock::getHr() const
{
  return hour;
}

std::vector<int> Clock::getBits() const //Returns entire vector of LED states
{
  return bits;
}
