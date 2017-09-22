#ifndef c_man
#define c_man

#include <stdio.h>
#include <stdlib.h>
#include "Class.h"
int _setName(char*);
int _sayHello();

/* Class Create					*/
#define Man_DATA char *name;
#define Man_FUNC				\
	int (*setName)(char*);			\
	int (*sayHello)();
CreateClass(
	Name(Man),
	DataInit(
		this->name="unNamed";
	),
	FuncInit(
		this->setName = _setName;
		this->sayHello = _sayHello;
	)
);

/* class func 					*/
int _setName(char *str){
    this(Man)->name = str;
    return 0;
}
int _sayHello(){
    printf("Hello, my name is %s.\n",
    	this(Man)->name);
    return 0;
}

#endif

