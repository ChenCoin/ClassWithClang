#include <stdio.h>
#include <stdlib.h>
#include "../Class.h"
#include "man.h"
#include "boy.h"

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
