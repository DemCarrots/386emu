#include "cpu.h"

namespace CPU
{
	reg32 ax, bx, cx, dx, si, di, bp, sp;
	sreg cs, ds, es, ss, fs, gs;
	u32 eip;
	u32 eflags;
	systbl gdtr, idtr;
	sreg ldtr, tr;

	bool irq;
	u8 irqnum;

	bool halted; //Once HLT has been executed, only check for interrupts.

	u8 cpl; //Only 2 bits.

	u32 cr[5];
	u32 dr[8];
	u32 testr[2];

	int seg;
	int rep;

	void init()
	{

	}
	void tick()
	{
		printf("NOTHING WORKS YET\n");
	}
	u8 rb(u16 seg, u32 addr)
	{

	}
	void wb(u16 seg, u32 addr, u8 data)
	{

	}
	void interrupt(u8 intr)
	{

	}
}