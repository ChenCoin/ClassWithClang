#include <stdio.h>
#include <stdlib.h>
#include "Class.h"
#include "man.c"
#include "boy.c"
#include "angryboy.c"

int changeName(Man m,char* name){
	$(m).setName(name);
	$(m).sayHello();
	return 0;
}

int main(){
	Man Alice = new(Man);
	Boy Bob = new(Boy);

	$(Alice).setName("alice");
	$(Bob).setName("bob");
	$(Bob).setSuject("Math");

	$(Alice).sayHello();
	$(Bob).sayHello();
	$(Bob).study();

	$( (Man)Bob ).setName("test");
	$( (Man)Bob ).sayHello();

	AngryBoy caly = new(AngryBoy);
	$(caly).setName("caly");
	$(caly).study();
	$(caly).angry();
	
	changeName((Man)caly,"clever");
	$(caly).angry();
	$(caly).sayHello();
	
	return 0;
}

