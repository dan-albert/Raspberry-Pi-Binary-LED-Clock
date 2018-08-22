// Header file for Clock ADT
#ifndef CLOCK_H
#define CLOCK_H

class Clock
{
	public:
		Clock(); //Default Constructor
		Clock(int, int, int);
		int getSec() const;
		int getMin() const;
		int getHr() const;
		std::vector<int> getBits() const;
		
	private:
		int second, minute, hour;
		std::vector<int> bits;
	  int setSec(int sec);
		int setMin(int min);
		int setHr(int hr);
		void setBits();
};

#include "ClockADT.cpp"
#endif
