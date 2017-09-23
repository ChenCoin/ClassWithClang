#include <stdio.h>
#include <stdlib.h>
#include "../Class.h"
#include "man.h"

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
