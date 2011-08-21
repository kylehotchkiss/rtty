Virginiastar RTTY
=================

If you take a good look around, you see other great Arduino RTTY libraries, 
but this one transmits in more traditional Baudot code and is sound based, so
that you may attach your arduino to an actual radio for enhanced range.

When building your board *you must* put at least 20kΩ of resistors in front 
of the device you are feeding sound to. If you connect your arduino to 
headphones and start this code, you will hurt your ears. It is also best not 
to shove too much power into your gadgets. 

Because Arduino does not multitask natively, this code will render your 
Arduino useless for all other functions while transmitting. It is probably
best if you add another Arduino to your project to handle priority logic. It's
strongly recommended that you avoid using interrupts, but they need not be 
disabled.

Usage
-----

The best place to test this code is [Fldigi](http://www.w1hkj.com/Fldigi.html)
in the RTTY mode. Set your *Carrier Shift* to `170`, your *baud rate* to `50`, 
your *bits per character* to `5` (baudot), your *parity* to `none`, and your 
stop bits to `2`.

You will need to connect 2 wires to PWM pins on your Arduino, and then set those
in the following, before `setup()`: 

    RTTY rtty(pin1, pin2);

To transmit a message:

    String message = "test transmission"; rtty.encode(message);
 
To rest (in between messages):

    do { rtty.rest(); } while (some condition);
 
Resting is not required, but recommended to keep your first character from a 
message from getting dropped.

These two wires need to be connected to a sound cable that will run into your 
computer for testing, and into a radio for whatever purpose you will use them
for. Remember to be respectful of others when picking a frequency, because 
this could be broadcasting for long periods of time.

About
-----

This libray was written for what I hope will be my first balloon flight. It has
been tested and decided to stick with default transmission settings for the best
performance in the long run.