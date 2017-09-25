#include <stdio.h>
#include <stdlib.h>
#include "../Class.h"
#include "boy.h"

int main(){
	
	Boy b = new(Boy);
	$(b).name = "Candy";
	$(b).suject = "Math";
	$(b).sayHello();
	$(b).study();
	
	return 0;
}

