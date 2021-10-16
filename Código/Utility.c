#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"

float getMin (float x, float y){
	if(x>y){
		return y;
	}else{
		return x;
	}
}
