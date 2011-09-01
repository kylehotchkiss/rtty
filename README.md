Virginiastar RTTY
=================

If you take a good look around, you see other great Arduino RTTY libraries, 
but this one transmits in more traditional Baudot code and is sound based, so
that you may attach your Arduino to an UHF/VHF radio for extended range.

Because Arduino does not multitask natively, this code will render your 
Arduino useless for all other functions while transmitting. It is probably
best if you add another Arduino to your project to handle priority logic. An 
omniboot processor is about $5 so this shouldn't be too much. It's
strongly recommended that you avoid using interrupts, but they need not be 
disabled.

Usage
-----

To start, you will need to get a headphone wire, or another cable with an 
audio jack. Cut off one end of the cable, either the earbuds or one of the jacks. Strip 
the cable down, push the shielding back, and figure out how to get those two wires
connected to your breadboard. I soldered breakaway headers onto mine. You may want
to ground the shielding wire, but it works without it. Throw some resistors in the 
same line, about 20k-ohm to better handle the volume.

Next, you will need to download this code and place it in your Arduino `libraries` 
folder. You can create one if it doesn't exist. Then include this library with

    #include <rtty.h> 

Now connect your 2 sound wires to PWM pins on your Arduino, and then set those
in the following, before `setup()`: 

    RTTY rtty(pin1, pin2);

To transmit a message:

    String message = "test transmission"; rtty.encode(message);
 
Currently, this may drop the first character of your message and the best way
to handle noise is currently being decided. 

These two wires need to be connected to a sound cable that will run into your 
computer for testing, and into a radio for whatever purpose you will use them
for. Remember to be respectful of others when picking a frequency, because 
this could be broadcasting for long periods of time.

The best place to test this code is [Fldigi](http://www.w1hkj.com/Fldigi.html)
in the RTTY mode. Choose the `50 Baud` setting, place your frequency selectors 
on the two lines in your waterfall.

If all goes well, your message should show up!

About
-----

This libray was written by Hotchkiss for what I hope will be my first balloon flight 
([Virginiastar](http://hotchkissmade.com/blog/virginiastar/)). It has
been tested over wire and works well. Radio test