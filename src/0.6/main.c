#include <stdio.h>
#include <stdlib.h>
#include "Class.h"
#include "man.c"
#include "boy.c"
#include "angryboy.c"

int main(){
	Man Alice = new(Man);
	Boy Bob = new(Boy);

	$(Alice).setName("alice");
	$(Bob).setName("bob");
	$(Bob).setSuject("Math");

	$(Alice).sayHello();
	$(Bob).sayHello();
	$(Bob).study();

	AngryBoy aboy = new(AngryBoy);
	$(aboy).setName("candy");
	$(aboy).study();
	$(aboy).angry();
	
	return 0;
}


