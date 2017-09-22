#include <stdio.h>
#include <stdlib.h>
#include "Class.h"

/* create class */
crtClass(
    	Boy
    ,(
    	int age;
    ),(
    	int (*getAge)();
    	int (*setAge)(int);
    )
);

/* class func */
int _getAge(){
    Boy boy = this(Boy);
    return boy->age;
}
int _setAge(int i){
    Boy boy = this(Boy);
    boy->age = i;
    return 0;
}

/* init class */
initClass(
    	Boy
    ,(
    	this(Boy)->age = 0; 
    ),(
    	_getAge,
    	_setAge
    )
);

/* main func */
int main()
{
    Boy b = new(Boy);
    Boy c = new(Boy);

    $(b).setAge(12);
    $(c).setAge(16);
    int age1 = $(b).getAge();
    int age2 = $(c).getAge();
    printf("%d : %d\n",age1,age2);
    
    return 0;
}

