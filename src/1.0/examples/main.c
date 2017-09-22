#include <stdio.h>
#include <stdlib.h>
#include "../src/Class.h"
#include "man.h"
#include "boy.h"

int changeName(void* p,char* str){
	Man m = (Man)p;
	$(m).name = str;
	return 0;
}

int main(){
	Man m = new(Man);
	Man n = new(Man);
	$(m).name = "Alice";
	$(n).name = "Bob";
	$(m).sayHello();
	$(n).sayHello();
	
	Boy b = new(Boy);
	$(b).name = "Candy";
	$(b).suject = "Math";
	$(b).sayHello();
	$(b).study();
	
	changeName(b,"Dav");
	$(b).sayHello();
	
	return 0;
}

