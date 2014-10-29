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

	reg32 ax, bx, cx, dx, si, di, bp, sp;
	sreg cs, ds, es, ss, fs, gs;
	u32 eip;
	u32 flags;
	systbl gdtr, idtr;
	sreg ldtr, tr;

	u8 cpl; //Only 2 bits.

	u32 cr[5];
	u32 dr[8];
	u32 tr[2];
}

#endif