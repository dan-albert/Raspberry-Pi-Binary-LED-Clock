/* compile commands
pi@raspberrypi:~ $ as on_led.s -o on_led.o
pi@raspberrypi:~ $ g++ -c -o clockTest.o clockTest.cpp
pi@raspberrypi:~ $ g++ -o clockTest clockTest.o ClockADT.o on_led.o  -lwiringPi
*/


//---------------------------------------
//	Data Section
// ---------------------------------------
	
	 .data
	 .balign 4	
//ErrMsg	 .asciz	"Setup didn't work... Aborting...\n"
pin0off:	 .int	0
OUTPUT	 =	0
	

//---------------------------------------
//	Code Section
// ---------------------------------------
	
	.text
	.globl	offLED0
	.p2align 2
	.type	offLED0, %function
	.extern printf
	.extern wiringPiSetup
	.extern delay
	.extern digitalWrite
	.extern pinMode
	
offLED0:
	.fnstart
	 push 	{ip, lr}	// push return address + dummy register
				// for alignment

//  if (wiringPiSetup() == -1) {
//     printf( "Setup didn't work... Aborting." ) ;
//     exit (1)					 ;
//  }
	bl	wiringPiSetup
	mov	r1,#-1
	cmp	r0, r1
	bne	init0off
	ldr	r0, =0  //changed ErrMsg to 0
	bl	printf
	b	done0off
	.fnend

//  pinMode(pin, OUTPUT)		;
init0off:
	ldr	r0, =pin0off
	ldr	r0, [r0]
	mov	r1, #OUTPUT
	bl	pinMode
	
//	digitalWrite(pin, 1) ;
	ldr	r0, =pin0off
	ldr	r0, [r0]
	mov	r1, #1
	bl 	digitalWrite
	bgt	done0off

	
done0off:	
        pop 	{ip, pc}	//pop return address into pc
