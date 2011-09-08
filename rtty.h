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
 protected:
	 void mark();
	 void space();
	 void stop();
	 void start();
	 int MARK_PIN;
	 int SPACE_PIN;
};

#endif