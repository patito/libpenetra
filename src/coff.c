#include <string.h>

#include <penetra/coff.h>
#include <penetra/error.h>

static const MachineTable arch[] =
{
	{"Any machine type", 0x0},
	{"Matsushita AM33", 0x1d3},
	{"x86-64 (64-bits)", 0x8664},
	{"ARM little endian", 0x1c0},
	{"ARMv7 (or higher) Thumb mode only", 0x1c4},
	{"EFI byte code", 0xebc},
	{"Intel 386 and compatible (32-bits)", 0x14c},
	{"Intel Itanium", 0x200},
	{"Mitsubishi M32R little endian", 0x9041},
	{"MIPS16", 0x266},
	{"MIPS with FPU", 0x366},
	{"MIPS16 with FPU", 0x466},
	{"Power PC little endian", 0x1f0},
	{"Power PC with floating point support", 0x1f1},
	{"MIPS little endian", 0x166},
	{"Hitachi SH3", 0x1a2},
	{"Hitachi SH3 DSP", 0x1a3},
	{"Hitachi SH4", 0x1a6},
	{"Hitachi SH5",  0x1a8},
	{"ARM or Thumb (\"interworking\")", 0x1c2},
	{"MIPS little-endian WCE v2", 0x169}
};


_u32 penetra_coff_get_arch(PenetraCoff *coff, _u16 *arch)
{
	if (NULL == coff) {
		return PENETRA_EINVAL;	
	}
	
	if (NULL == arch) {
		return PENETRA_EINVAL;
	}

	*arch = coff->arch;

	return PENETRA_SUCCESS;
}

