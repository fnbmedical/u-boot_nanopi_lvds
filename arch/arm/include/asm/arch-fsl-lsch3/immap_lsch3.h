/*
 * LayerScape Internal Memory Map
 *
 * Copyright 2014 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __ARCH_FSL_LSCH3_IMMAP_H
#define __ARCH_FSL_LSCH3_IMMAP_H_

/* This is chassis generation 3 */

struct sys_info {
	unsigned long freq_processor[CONFIG_MAX_CPUS];
	unsigned long freq_systembus;
	unsigned long freq_ddrbus;
	unsigned long freq_localbus;
	unsigned long freq_qe;
#ifdef CONFIG_SYS_DPAA_FMAN
	unsigned long freq_fman[CONFIG_SYS_NUM_FMAN];
#endif
#ifdef CONFIG_SYS_DPAA_QBMAN
	unsigned long freq_qman;
#endif
#ifdef CONFIG_SYS_DPAA_PME
	unsigned long freq_pme;
#endif
};

/* Global Utilities Block */
struct ccsr_gur {
	u32	porsr1;		/* POR status 1 */
	u32	porsr2;		/* POR status 2 */
	u8	res_008[0x20-0x8];
	u32	gpporcr1;	/* General-purpose POR configuration */
	u32	gpporcr2;	/* General-purpose POR configuration 2 */
	u32	dcfg_fusesr;	/* Fuse status register */
	u32	gpporcr3;
	u32	gpporcr4;
	u8	res_034[0x70-0x34];
	u32	devdisr;	/* Device disable control */
	u32	devdisr2;	/* Device disable control 2 */
	u32	devdisr3;	/* Device disable control 3 */
	u32	devdisr4;	/* Device disable control 4 */
	u32	devdisr5;	/* Device disable control 5 */
	u32	devdisr6;	/* Device disable control 6 */
	u32	devdisr7;	/* Device disable control 7 */
	u8	res_08c[0x90-0x8c];
	u32	coredisru;	/* uppper portion for support of 64 cores */
	u32	coredisrl;	/* lower portion for support of 64 cores */
	u8	res_098[0xa0-0x98];
	u32	pvr;		/* Processor version */
	u32	svr;		/* System version */
	u32	mvr;		/* Manufacturing version */
	u8	res_0ac[0x100-0xac];
	u32	rcwsr[32];	/* Reset control word status */

#define FSL_CHASSIS3_RCWSR0_SYS_PLL_RAT_SHIFT	2
#define FSL_CHASSIS3_RCWSR0_SYS_PLL_RAT_MASK	0x1f
#define FSL_CHASSIS3_RCWSR0_MEM_PLL_RAT_SHIFT	10
#define FSL_CHASSIS3_RCWSR0_MEM_PLL_RAT_MASK	0x3f
	u8	res_180[0x200-0x180];
	u32	scratchrw[32];	/* Scratch Read/Write */
	u8	res_280[0x300-0x280];
	u32	scratchw1r[4];	/* Scratch Read (Write once) */
	u8	res_310[0x400-0x310];
	u32	bootlocptrl;	/* Boot location pointer low-order addr */
	u32	bootlocptrh;	/* Boot location pointer high-order addr */
	u8	res_408[0x500-0x408];
	u8	res_500[0x740-0x500];	/* add more registers when needed */
	u32	tp_ityp[64];	/* Topology Initiator Type Register */
	struct {
		u32	upper;
		u32	lower;
	} tp_cluster[3];	/* Core Cluster n Topology Register */
	u8	res_858[0x1000-0x858];
};

#define TP_ITYP_AV		0x00000001	/* Initiator available */
#define TP_ITYP_TYPE(x)	(((x) & 0x6) >> 1)	/* Initiator Type */
#define TP_ITYP_TYPE_ARM	0x0
#define TP_ITYP_TYPE_PPC	0x1		/* PowerPC */
#define TP_ITYP_TYPE_OTHER	0x2		/* StarCore DSP */
#define TP_ITYP_TYPE_HA		0x3		/* HW Accelerator */
#define TP_ITYP_THDS(x)	(((x) & 0x18) >> 3)	/* # threads */
#define TP_ITYP_VER(x)	(((x) & 0xe0) >> 5)	/* Initiator Version */
#define TY_ITYP_VER_A7		0x1
#define TY_ITYP_VER_A53		0x2
#define TY_ITYP_VER_A57		0x3

#define TP_CLUSTER_EOC		0x80000000	/* end of clusters */
#define TP_CLUSTER_INIT_MASK	0x0000003f	/* initiator mask */
#define TP_INIT_PER_CLUSTER     4

struct ccsr_clk_cluster_group {
	struct {
		u8	res_00[0x10];
		u32	csr;
		u8	res_14[0x20-0x14];
	} hwncsr[3];
	u8	res_60[0x80-0x60];
	struct {
		u32	gsr;
		u8	res_84[0xa0-0x84];
	} pllngsr[3];
	u8	res_e0[0x100-0xe0];
};

struct ccsr_clk_ctrl {
	struct {
		u32 csr;	/* core cluster n clock control status */
		u8  res_04[0x20-0x04];
	} clkcncsr[8];
};
#endif /* __ARCH_FSL_LSCH3_IMMAP_H */
