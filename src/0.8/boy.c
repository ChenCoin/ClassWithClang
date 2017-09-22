#ifndef c_boy
#define c_boy

#include <stdio.h>
#include <stdlib.h>
#include "Class.h"
#include "man.c"
int setSuject(char*);
int study();

/* Class Create					*/
#define Boy_DATA				\
	EX_DATA(Man_DATA)			\
	char *suject;
#define Boy_FUNC				\
	EX_FUNC(Man_FUNC)			\
	int (*setSuject)(char*);		\
	int (*study)();
CreateClass(
	Name(Boy),
	DataInit(
		this->suject="unknown";
	),
	FuncInit(
		this->setSuject = setSuject;
    		this->study = study;
	),
	extends(Man)
);

/* Class Inside Function 			*/
int setSuject(char *str){
    this(Boy)->suject = str;
    return 0;
}
int study(){
    printf("%s is study %s.\n",
    	this(Boy)->name,
    	this(Boy)->suject);
    return 0;
}

#endif

