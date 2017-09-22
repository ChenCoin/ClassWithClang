#include <stdio.h>
#include <stdlib.h>
#include "Class.h"
#include "boy.c"
int _angry();
int _neverSayHello();

/* Class Create					*/
#define AngryBoy_DATA				\
	EX_DATA(Boy_DATA)					
#define AngryBoy_FUNC				\
	EX_FUNC(Boy_FUNC)			\
	int (*angry)();

CreateClass(
	Name(AngryBoy),
	DataInit(),
	FuncInit(
    		this->angry = _angry;
    		this->sayHello = _neverSayHello;
	),
	extends(Boy)
);

/* Class Inside Function 			*/

int _angry(){
    printf("%s is angry\n",
    	this(Boy)->name);
    return 0;
}

int _neverSayHello(){
	printf("I never say Hello.\n");
	return 0;
}

