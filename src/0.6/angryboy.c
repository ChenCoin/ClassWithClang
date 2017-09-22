#include <stdio.h>
#include <stdlib.h>
#include "Class.h"
#include "boy.c"
int angry();

/* Class Create					*/
#define AngryBoy_DATA				\
	extends(Boy_DATA)					
#define AngryBoy_FUNC				\
	extends(Boy_FUNC)			\
	int (*angry)();

CreateClass(
	Name(AngryBoy),
	DataInit(),
	FuncInit(
    	this->angry = angry;
	),
	extends(Boy)
);

/* Class Inside Function 			*/

int angry(){
    printf("%s is angry\n",
    	this(Boy)->name);
    return 0;
}

