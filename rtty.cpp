/**
 * 
 * Virginiastar RTTY Library
 * Copyright 2011 Hotchkissmade
 * All rights reserved
 *
 */
 
#include "WProgram.h"
#include "rtty.h"

RTTY::RTTY(int mark, int space) 
: MARK_PIN(mark), SPACE_PIN(space) { 
 // Currently no init needed.
}

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

void RTTY::start() { space(); }
void RTTY::stop() { mark(); mark(); }
void RTTY::rest() { mark(); }

void RTTY::badot(String message) {
	
	int length = message.length();
	
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
				badot('[');
				start(); space(); mark(); mark(); space(); mark(); stop(); 
				badot(']');
				break;
			case '1':
				badot('[');
				start(); mark(); mark(); mark(); space(); mark(); stop(); 
				badot(']');
				break;
			case '2':
				badot('[');
				start(); mark(); mark(); space(); space(); mark(); stop(); 
				badot(']');
				break;
			case '3':
				badot('[');
				start(); mark(); space(); space(); space(); space(); stop();
				badot(']');
				break;
			case '4':
				badot('[');
				start(); space(); mark(); space(); mark(); space(); stop(); 
				badot(']');
				break;
			case '5':
				badot('[');
				start(); space(); space(); space(); space(); mark(); stop();
				badot(']');
				break;
			case '6':
				badot('[');
				start(); mark(); space(); mark(); space(); mark(); stop();
				badot(']');
				break;
			case '7':
				badot('[');
				start(); mark(); mark(); mark(); space(); space(); stop(); 
				badot(']');
				break;
			case '8':
				badot('[');
				start(); space(); mark(); mark(); space(); space(); stop(); 
				badot(']');
				break;
			case '9':
				badot('[');
				start(); space(); space(); space(); mark(); mark(); stop(); 
				badot(']');
				break;
			case '-':
				badot('[');
				start(); mark(); mark(); space(); space(); space(); stop(); 
				badot(']');
				break;
			case '$':
				badot('[');
				start(); mark(); space(); space(); mark(); space(); stop(); 
				badot(']');
				break;
			case '!':
				badot('[');
				start(); mark(); space(); mark(); mark(); space(); stop(); 
				badot(']');
				break;
			case '&':
				badot('[');
				start(); space(); mark(); space(); mark(); mark(); stop(); 
				badot(']');
				break;
			case '#':
				badot('[');
				start(); space(); space(); mark(); space(); mark(); stop(); 
				badot(']');
				break;
			case '\'': // =)
				badot('[');
				start(); mark(); mark(); space(); mark(); space(); stop(); 
				badot(']');
				break;
			case '(':
				badot('[');
				start(); mark(); mark(); mark(); mark(); space(); stop(); 
				badot(']');
				break;
			case ')':
				badot('[');
				start(); space(); mark(); space(); space(); mark(); stop(); 
				badot(']');
				break;
			case '"':
				badot('[');
				start(); mark(); space(); space(); space(); mark(); stop(); 
				badot(']');
				break;
			case '/':
				badot('[');
				start(); mark(); space(); mark(); mark(); mark(); stop(); 
				badot(']');
				break;
			case ':':
				badot('[');
				start(); space(); mark(); mark(); mark(); space(); stop();
				badot(']');
				break;
			case ';':
				badot('[');
				start(); space(); mark(); mark(); mark(); mark(); stop();
				badot(']');
				break;
			case '?':
				badot('[');
				start(); mark(); space(); space(); mark(); mark(); stop();
				badot(']');
				break;
			case ',':
				badot('[');
				start(); space(); space(); mark(); mark(); space(); stop();
				badot(']');
				break;
			case '.':
				badot('[');
			    start(); space(); space(); mark(); mark(); mark(); stop();
				badot(']');
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
}