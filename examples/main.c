#include <stdio.h>
#include <stdlib.h>
#include "Class.h"
#include "man.h"
#include "boy.h"

int main(){
	Man m = new(Man);
	Man n = new(Man);
	$(m).name = "Alice";
	$(n).name = "Bob";
	$(m).sayHello();
	$(n).sayHello();
	
	Boy b = new(Boy);
	$(b).name = "Candy";
	$(b).sayHello();
	$(b).study();
	
	$( (Man)b ).name="Dav";
	$(b).sayHello();
	
	return 0;
}

