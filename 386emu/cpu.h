#ifndef CPU_H
#define CPU_H

#include "common.h"

namespace CPU
{
	union reg32
	{
		u8 b[2];
		u16 w;
		u32 d;
	};

	struct sreg
	{
		u16 sel;
		u16 flags;
		u32 base;
		u32 limit;
		int d;
		bool valid;
	};

	struct systbl
	{
		u32 base;
		u16 limit;
	};

	extern reg32 ax, bx, cx, dx, si, di, bp, sp;
	extern sreg cs, ds, es, ss, fs, gs;
	extern u32 eip;
	extern u32 flags;
	extern systbl gdtr, idtr;
	extern sreg ldtr, tr;

	extern bool irq;
	extern u8 irqnum;

	extern bool halted; //Once HLT has been executed, only check for interrupts.

	extern u8 cpl; //Only 2 bits.

	extern u32 cr[5];
	extern u32 dr[8];
	extern u32 testr[2];

	enum segs
	{
		CS,DS,ES,SS,FS,GS,DEFAULT
	};

	extern int seg;

	enum reps
	{
		REP_EQ, REP_NE, NONE
	};

	extern int rep;

	void init();
	void tick();
	u8 rb(u16 seg, u32 addr);
	void wb(u16 seg, u32 addr, u8 data);
	void interrupt(u8 intr);
}

#endif