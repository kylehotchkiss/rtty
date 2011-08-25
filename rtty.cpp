/**
 * 
 * Virginiastar RTTY Library
 * Copyright 2011 Hotchkissmade
 * Released under the GPL
 *
 */
 
#include "WProgram.h"
#include "rtty.h"

RTTY::RTTY(int mark, int space, int status) 
: MARK_PIN(mark), SPACE_PIN(space), STATUS_PIN(status) { 
 // No current need.
}


/* *********************** *
 * Output handling [2-pin] *
 * *********************** */
void RTTY::mark() {
    tone(MARK_PIN, 2125);  
    delayMicroseconds(10000);  
    delayMicroseconds(10150); 
    noTone(MARK_PIN);
}

void RTTY::space() {
    tone(SPACE_PIN, 2295);  
    delayMicroseconds(10000);  
    delayMicroseconds(10150);    
    noTone(SPACE_PIN);
}


/* ********************* *
 * RTTY Protocol Helpers *
 * ********************* */
void RTTY::start() { space(); }
void RTTY::stop() { mark(); mark(); }
void RTTY::rest() { mark(); }


/* ************************** *
 * Baudot Code Implementation *
 * ************************** */
void RTTY::encode(String message) {
	int length = message.length();
	
         // digitalWrite(STATUS_PIN, HIGH);

	for (int i = 0; i < length; i++) {
		switch(message[i]) {
			case 'a':
			case 'A':
	  			start(); mark(); mark(); space(); space(); space();
	  			break;
			case 'b':
			case 'B':
				start(); mark(); space(); space(); mark(); mark();
				break; 
			case 'c':
			case 'C':
				start(); space(); mark(); mark(); mark(); space(); 
				break;
			case 'd':
			case 'D':
				start(); mark(); space(); space(); mark(); space(); 
				break;
			case 'e':
			case 'E':
				start(); mark(); space(); space(); space(); space(); 
				break;
			case 'f':
			case 'F':
				start(); mark(); space(); mark(); mark(); space(); 
				break;
			case 'g':
			case 'G':
				start(); space(); mark(); space(); mark(); mark(); 
				break;
			case 'h':
			case 'H':
				start(); space(); space(); mark(); space(); mark(); 
				break;
			case 'i':
			case 'I':
				start(); space(); mark(); mark(); space(); space(); 
				break;
			case 'j':
			case 'J':
				start(); mark(); mark(); space(); mark(); space(); 
				break;
			case 'k':
			case 'K':
				start(); mark(); mark(); mark(); mark(); space(); 
				break;
			case 'l':
			case 'L':
				start(); space(); mark(); space(); space(); mark(); 
				break;
			case 'm':
			case 'M':
				start(); space(); space(); mark(); mark(); mark(); 
				break;
			case 'n':
			case 'N':
				start(); space(); space(); mark(); mark(); space(); 
				break;
			case 'o':
			case 'O':
				start(); space(); space(); space(); mark(); mark(); 
				break;
			case 'p':
			case 'P':
				start(); space(); mark(); mark(); space(); mark(); 
				break;
			case 'q':
			case 'Q':
				start(); mark(); mark(); mark(); space(); mark(); 
				break;
			case 'r':
			case 'R':
				start(); space(); mark(); space(); mark(); space(); 
				break;
			case 's':
			case 'S':
				start(); mark(); space(); mark(); space(); space(); 
				break;
			case 't':
			case 'T':
				start(); space(); space(); space(); space(); mark(); 
				break;
			case 'u':
			case 'U':
				start(); mark(); mark(); mark(); space(); space(); 
				break;
			case 'v':
			case 'V':
				start(); space(); mark(); mark(); mark(); mark(); 
				break;
			case 'w':
			case 'W':
				start(); mark(); mark(); space(); space(); mark(); 
				break;
			case 'x':
			case 'X':
				start(); mark(); space(); mark(); mark(); mark(); 
				break;
			case 'y':
			case 'Y':
				start(); mark(); space(); mark(); space(); mark(); 
				break;
			case 'z':
			case 'Z':
				start(); mark(); space(); space(); space(); mark(); 
				break;
			case '\r':
				start(); space(); space(); space(); mark(); space();
				break;
			case '\n':
				start(); space(); mark(); space(); space(); space();
				break;
			case ' ':
				start(); space(); space(); mark(); space(); space(); 
				break;
			case '0':
				encode('[');
				start(); space(); mark(); mark(); space(); mark(); stop(); 
				encode(']');
				break;
			case '1':
				encode('[');
				start(); mark(); mark(); mark(); space(); mark(); stop(); 
				encode(']');
				break;
			case '2':
				encode('[');
				start(); mark(); mark(); space(); space(); mark(); stop(); 
				encode(']');
				break;
			case '3':
				encode('[');
				start(); mark(); space(); space(); space(); space(); stop();
				encode(']');
				break;
			case '4':
				encode('[');
				start(); space(); mark(); space(); mark(); space(); stop(); 
				encode(']');
				break;
			case '5':
				encode('[');
				start(); space(); space(); space(); space(); mark(); stop();
				encode(']');
				break;
			case '6':
				encode('[');
				start(); mark(); space(); mark(); space(); mark(); stop();
				encode(']');
				break;
			case '7':
				encode('[');
				start(); mark(); mark(); mark(); space(); space(); stop(); 
				encode(']');
				break;
			case '8':
				encode('[');
				start(); space(); mark(); mark(); space(); space(); stop(); 
				encode(']');
				break;
			case '9':
				encode('[');
				start(); space(); space(); space(); mark(); mark(); stop(); 
				encode(']');
				break;
			case '-':
				encode('[');
				start(); mark(); mark(); space(); space(); space(); stop(); 
				encode(']');
				break;
			case '$':
				encode('[');
				start(); mark(); space(); space(); mark(); space(); stop(); 
				encode(']');
				break;
			case '!':
				encode('[');
				start(); mark(); space(); mark(); mark(); space(); stop(); 
				encode(']');
				break;
			case '&':
				encode('[');
				start(); space(); mark(); space(); mark(); mark(); stop(); 
				encode(']');
				break;
			case '#':
				encode('[');
				start(); space(); space(); mark(); space(); mark(); stop(); 
				encode(']');
				break;
			case '\'': // =)
				encode('[');
				start(); mark(); mark(); space(); mark(); space(); stop(); 
				encode(']');
				break;
			case '(':
				encode('[');
				start(); mark(); mark(); mark(); mark(); space(); stop(); 
				encode(']');
				break;
			case ')':
				encode('[');
				start(); space(); mark(); space(); space(); mark(); stop(); 
				encode(']');
				break;
			case '"':
				encode('[');
				start(); mark(); space(); space(); space(); mark(); stop(); 
				encode(']');
				break;
			case '/':
				encode('[');
				start(); mark(); space(); mark(); mark(); mark(); stop(); 
				encode(']');
				break;
			case ':':
				encode('[');
				start(); space(); mark(); mark(); mark(); space(); stop();
				encode(']');
				break;
			case ';':
				encode('[');
				start(); space(); mark(); mark(); mark(); mark(); stop();
				encode(']');
				break;
			case '?':
				encode('[');
				start(); mark(); space(); space(); mark(); mark(); stop();
				encode(']');
				break;
			case ',':
				encode('[');
				start(); space(); space(); mark(); mark(); space(); stop();
				encode(']');
				break;
			case '.':
				encode('[');
			    start(); space(); space(); mark(); mark(); mark(); stop();
				encode(']');
				break;
			case '[': // ITU2 FIGS
			    start(); mark(); mark(); space(); mark(); mark();
				break;
			case ']': // ITU2 LTRS
				start(); mark(); mark(); mark(); mark(); mark();
				break;
			default: // ITU2 NULL (throws off start bit)
				start(); space(); space(); space(); space(); space();
				break;
		}
		
		stop();
	}

         // digitalWrite(STATUS_PIN, LOW);
}