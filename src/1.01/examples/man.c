#ifndef c_man
#define c_man

#include <stdio.h>
#include <stdlib.h>
#include "../Class.h"
#include "man.h"

//use (*this) install of $(this) to optimizer programs.
int _sayHello();
CreateClass(
	Man,
	(
		(*this).name = "NoName";
		(*this).sayHello = _sayHello;
	)
)

int _sayHello(){
	Man this = (Man)THIS;
	printf("Hello, I'm %s\n",(*this).name);
	return 0;
}

#endif
