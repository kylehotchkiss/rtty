/**
 * 
 * Virginiastar RTTY Library
 * Copyright 2011 Hotchkissmade
 * Released under the GPL  
 *
 * This is and was intended to be 
 * a very static library, allowing 
 * for maximum accuracy later on.
 *
 */
 
#ifndef rtty_h
#define rtty_h

#include "WProgram.h"
 
class RTTY {
 public:
	 RTTY(int mark, int space);
	 void badot(String message);
	 void rest();
 protected:
	 void mark();
	 void space();
	 void start();
	 void stop();
	 int MARK_PIN;
	 int SPACE_PIN;
};

#endif