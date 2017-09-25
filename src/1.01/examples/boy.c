#ifndef c_boy
#define c_boy

#include <stdio.h>
#include <stdlib.h>
#include "../Class.h"
#include "boy.h"

#include "man.c"
//use (*this) install of $(this) to optimizer programs.
int _study();
CreateClass(
	Boy,
	(
		(*this).suject = "NotStudent";
		(*this).study = _study;
	),
	Man
)
	
int _study(){
	Boy this = (Boy)THIS;
	printf("%s is study %s\n",
		(*this).name,(*this).suject);
	return 0;
}

#endif
