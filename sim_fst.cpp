#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <verilated_fst_c.h>
#include "Vswitch.h"

#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;

 int main(int argc, char** argv) {

	 VerilatedContext* contextp = new VerilatedContext;
	 contextp->commandArgs(argc, argv);
	 Vswitch* top = new Vswitch{contextp};

	 Verilated::traceEverOn(true);
   VerilatedFstC* m_trace = new VerilatedFstC;
   top->trace(m_trace, 99);
   m_trace->open("obj_dir_fst/switch_wave.fst");

	 while (sim_time < MAX_SIM_TIME && !contextp->gotFinish()){
		 int a = rand() & 1;
		 int b = rand() & 1;
		 top->a = a;
		 top->b = b;
		 top->eval();
		 printf("a = %d, b = %d, f = %d\n", a, b, top->f);
		 assert(top->f == (a ^ b));
		 m_trace->dump(sim_time);
		 sim_time++;
	 }

	 m_trace->close();
	 delete top;
	 delete contextp;
	 return 0;
}
