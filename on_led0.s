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
ErrMsg:	 .asciz	"Setup didn't work... Aborting...\n"
pin0:	 .int	0
OUTPUT	 =	1
	

//---------------------------------------
//	Code Section
// ---------------------------------------
	
	.text
	.globl	onLED0
	.p2align 2
	.type	onLED0, %function
	.extern printf
	.extern wiringPiSetup
	.extern delay
	.extern digitalWrite
	.extern pinMode
	
onLED0:
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
	bne	init
	ldr	r0, =ErrMsg
	bl	printf
	b	done
	.fnend

//  pinMode(pin, OUTPUT)		;
init:
	ldr	r0, =pin0
	ldr	r0, [r0]
	mov	r1, #OUTPUT
	bl	pinMode
	
//	digitalWrite(pin, 1) ;
	ldr	r0, =pin0
	ldr	r0, [r0]
	mov	r1, #1
	bl 	digitalWrite
	bgt	done

	
done:	
        pop 	{ip, pc}	//pop return address into pc
