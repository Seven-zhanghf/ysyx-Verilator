#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vswitch.h"
 
 int main(int argc, char** argv) {
	 VerilatedContext* contextp = new VerilatedContext;
	 contextp->commandArgs(argc, argv);
	 Vswitch* top = new Vswitch{contextp};

	 int counter = 0;

	 while (counter < 10){
		 int a = rand() & 1;
		 int b = rand() & 1;
		 top->a = a;
		 top->b = b;
		 top->eval();
		 printf("a = %d, b = %d, f = %d\n", a, b, top->f);
		 assert(top->f == (a ^ b));
		 counter++;
	 }
	 delete top;
	 delete contextp;
	 return 0;
}
