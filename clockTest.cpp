#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <time.h>
#include <wiringPi.h>
#include "ClockADT.h"

using namespace std;

extern "C" void onLED0();
extern "C" void offLED0();


void updateLED(int LED0=0, int LED1=0, int LED2=0, int LED3=0, int LED4=0, int LED5=0, int LED6=0, int LED7=0,
				int LED8=0, int LED9=0, int LED10=0, int LED11=0, int LED12=0, int LED13=0, int LED14=0, int LED15=0)
{
	// LED TEST
	digitalWrite(0, HIGH);	
	digitalWrite(1, HIGH);
	digitalWrite(2, HIGH);
	digitalWrite(3, LOW);
	digitalWrite(4, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(6, HIGH);
	digitalWrite(7, HIGH);
	digitalWrite(8, HIGH);
	digitalWrite(9, HIGH);
	digitalWrite(10, HIGH);
	digitalWrite(11, HIGH);
	digitalWrite(12, HIGH);
	digitalWrite(13, HIGH);
	digitalWrite(14, HIGH);
	digitalWrite(15, HIGH);
	
	//~ if(LED0) digitalWrite(0, HIGH);
	//~ if(LED0) onLED0(); // If 1 turn on
	//~ else digitalWrite(0, LOW);		// Else turn off
	//~ else offLED0();		// Else turn off
	
	//~ if(LED1) digitalWrite(1, HIGH);
	//~ else digitalWrite(1, LOW);

	//~ if(LED2) digitalWrite(2, HIGH);
	//~ else digitalWrite(2, LOW);
	
	//~ if(LED3) digitalWrite(3, HIGH);
	//~ else digitalWrite(3, LOW);

	//~ if(LED4) digitalWrite(4, HIGH);
	//~ else digitalWrite(4, LOW);
	
	//~ if(LED5) digitalWrite(5, HIGH);
	//~ else digitalWrite(5, LOW);

	//~ if(LED6) digitalWrite(6, HIGH);
	//~ else digitalWrite(6, LOW);

	//~ if(LED7) digitalWrite(7, HIGH);
	//~ else digitalWrite(7, LOW);
	
	//~ if(LED8) digitalWrite(8, HIGH); //wiringPi GPIO next available jumps to 10
	//~ else digitalWrite(8, LOW);
	
	//~ if(LED9) digitalWrite(9, HIGH);
	//~ else digitalWrite(9, LOW);
	
	//~ if(LED10) digitalWrite(10, HIGH);
	//~ else digitalWrite(10, LOW);
	
	//~ if(LED11) digitalWrite(11, HIGH);
	//~ else digitalWrite(11, LOW);
	
	//~ if(LED12) digitalWrite(12, HIGH);
	//~ else digitalWrite(12, LOW);
	
	//~ if(LED13) digitalWrite(13, HIGH);
	//~ else digitalWrite(13, LOW);
	
	//~ if(LED14) digitalWrite(14, HIGH);
	//~ else digitalWrite(14, LOW);
	
	//~ if(LED15) digitalWrite(15, HIGH);
	//~ else digitalWrite(15, LOW);
}

int main()
{	
	if(wiringPiSetup()==-1)
		cout<<"Setup wiringPi failed."<<endl;
	
	for(int i=0; i<16; i++)
		pinMode(i, OUTPUT);
			
	while(true)
	{
		time_t theTime = time(NULL);
		struct tm *myTime = localtime(&theTime); // get system local time
		
		Clock myClock(myTime->tm_hour, myTime->tm_min, myTime->tm_sec); // assign hour, minute, second to ClockADT

		cout<<"Hour:"<<myClock.getHr();
		cout<<"\t   Minute:"<<myClock.getMin();
		cout<<"\t  Second:"<<myClock.getSec()<<endl;
		  
		vector<int> bits(myClock.getBits()); //ClockADT keeps a bit status member variable
				
		updateLED(bits[0], bits[1], bits[2], bits[3], bits[4], bits[5], bits[6], bits[7], bits[8], bits[9], bits[10], bits[11], bits[12], bits[13], bits[14], bits[15]); // Only implemented seconds so far
		
		for(int i=15; i>=0; --i) // 0-5 = second bits, 6-11 = minute bits, 12-15 = hour bits
		{
			if(i==15) cout<<"     "; // Just formatting
			cout<<bits[i];
			if(i==12) cout<<"\t  ";
			if(i==6) cout<<"\t ";
		}
		
		cout<<endl;
		sleep(1);
	}
	
	return 0;
}
