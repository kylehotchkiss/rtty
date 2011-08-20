Virginiastar RTTY
=================

If you take a good look around, you see other great Arduino RTTY libraries, 
but this one transmits in more traditional Baudot code and is sound based, so
that you may attach your arduino to an actual radio for enhanced range.

When building your board *you must* put at least 20kΩ of resistors in front 
of the device you are feeding sound to. If you connect your arduino to 
headphones and start this code, you will hurt your ears. It is also best not 
to shove too much power into your gadgets. 

Because Arduinos do not multitask natively, this code will render your 
Arduino useless for all other functions while transmitting. It is probably
best if you add another arduino to your project to handle priority logic. It's
strongly recommended that you avoid using interrupts, but they need not be 
disabled.

Usage
-----

The best place to test this code is (Fldigi)[http://www.w1hkj.com/Fldigi.html]
in the RTTY mode. Set your *Carrier Shift* to `170``, your *baud rate* to whatever
you defined above, your *bits per character* to `5`(baudot), your *parity* to 
`none`, and your stop bits to `2`.