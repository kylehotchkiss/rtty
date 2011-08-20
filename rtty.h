/**
 * 
 * Virginiastar RTTY Library
 * Copyright 2011 Hotchkissmade
 * Released under the GPL  
 *
 */
 
#ifndef rtty_h
#define rtty_h

#include "WProgram.h"
 
class RTTY {
 public:
	 RTTY(int mark, int space);
	 void encode(String message);
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