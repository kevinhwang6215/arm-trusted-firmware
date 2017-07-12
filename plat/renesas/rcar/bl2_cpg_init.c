/*
 * Copyright (c) 2015-2016, Renesas Electronics Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *   - Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *   - Neither the name of Renesas nor the names of its contributors may be
 *     used to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <debug.h>
#include <mmio.h>
#include "rcar_def.h"
#include "bl2_cpg_register.h"
#include "bl2_cpg_init.h"

static void bl2_secure_cpg_init(void);
#if (RCAR_LSI == RCAR_AUTO) || (RCAR_LSI == RCAR_H3)
static void bl2_realtime_cpg_init_h3(void);
static void bl2_system_cpg_init_h3(void);
#endif /* (RCAR_LSI == RCAR_AUTO) || (RCAR_LSI == RCAR_H3) */
#if (RCAR_LSI == RCAR_AUTO) || (RCAR_LSI == RCAR_M3)
static void bl2_realtime_cpg_init_m3(void);
static void bl2_system_cpg_init_m3(void);
#endif /* (RCAR_LSI == RCAR_AUTO) || (RCAR_LSI == RCAR_M3) */

typedef struct {
	uintptr_t	adr;
	uint32_t	val;
} reg_setting_t;

static void bl2_secure_cpg_init(void)
{

	/* CPG (SECURITY) registers */

	/* Secure Module Stop Control Register 0 */
	cpg_write(SCMSTPCR0,	0xFFFFFFFFU);
	/* Secure Module Stop Control Register 1 */
	cpg_write(SCMSTPCR1,	0xFFFFFFFFU);
	/* Secure Module Stop Control Register 2 */
	cpg_write(SCMSTPCR2,	0xEBFFFFFFU);
	/* Secure Module Stop Control Register 3 */
	cpg_write(SCMSTPCR3,	0xFFFFFFFFU);
	/* Secure Module Stop Control Register 4 */
	cpg_write(SCMSTPCR4,	0x7FFFFFFFU);
	/* Secure Module Stop Control Register 5 */
	cpg_write(SCMSTPCR5,	0xBFFFFFFFU);
	/* Secure Module Stop Control Register 6 */
	cpg_write(SCMSTPCR6,	0xFFFFFFFFU);
	/* Secure Module Stop Control Register 7 */
	cpg_write(SCMSTPCR7,	0xFFFFFFFFU);
	/* Secure Module Stop Control Register 8 */
	cpg_write(SCMSTPCR8,	0xFFFFFFFFU);
	/* Secure Module Stop Control Register 9 */
	cpg_write(SCMSTPCR9,	0xFFFDFFFFU);
	/* Secure Module Stop Control Register 10 */
	cpg_write(SCMSTPCR10,	0xFFFFFFFFU);
	/* Secure Module Stop Control Register 11 */
	cpg_write(SCMSTPCR11,	0xFFFFFFFFU);
	/* Secure Software Reset Access Enable Control Register 0 */
	cpg_write(SCSRSTECR0,	0x00000000U);
	/* Secure Software Reset Access Enable Control Register 1 */
	cpg_write(SCSRSTECR1,	0x00000000U);
	/* Secure Software Reset Access Enable Control Register 2 */
	cpg_write(SCSRSTECR2,	0x14000000U);
	/* Secure Software Reset Access Enable Control Register 3 */
	cpg_write(SCSRSTECR3,	0x00000000U);
	/* Secure Software Reset Access Enable Control Register 4 */
	cpg_write(SCSRSTECR4,	0x80000003U);
	/* Secure Software Reset Access Enable Control Register 5 */
	cpg_write(SCSRSTECR5,	0x40000000U);
	/* Secure Software Reset Access Enable Control Register 6 */
	cpg_write(SCSRSTECR6,	0x00000000U);
	/* Secure Software Reset Access Enable Control Register 7 */
	cpg_write(SCSRSTECR7,	0x00000000U);
	/* Secure Software Reset Access Enable Control Register 8 */
	cpg_write(SCSRSTECR8,	0x00000000U);
	/* Secure Software Reset Access Enable Control Register 9 */
	cpg_write(SCSRSTECR9,	0x00020000U);
	/* Secure Software Reset Access Enable Control Register 10 */
	cpg_write(SCSRSTECR10,	0x00000000U);
	/* Secure Software Reset Access Enable Control Register 11 */
	cpg_write(SCSRSTECR11,	0x00000000U);
}

#if (RCAR_LSI == RCAR_AUTO) || (RCAR_LSI == RCAR_H3)
static void bl2_realtime_cpg_init_h3(void)
{
	uint32_t	prr;

	prr = mmio_read_32(RCAR_PRR) & RCAR_CUT_MASK;

	/* CPG (REALTIME) registers */

	if ((prr == RCAR_CUT_ES10) || (prr == RCAR_CUT_ES11)) {
		/* Realtime Module Stop Control Register 0 */
		cpg_write(RMSTPCR0,	0x00200000U);
	} else {
		/* Realtime Module Stop Control Register 0 */
		cpg_write(RMSTPCR0,	0x00210000U);
	}
	/* Realtime Module Stop Control Register 1 */
	cpg_write(RMSTPCR1,	0xFFFFFFFFU);
	/* Realtime Module Stop Control Register 2 */
	cpg_write(RMSTPCR2,	0x340E0FDCU);
	/* Realtime Module Stop Control Register 3 */
	cpg_write(RMSTPCR3,	0xFFFFFFDFU);
	/* Realtime Module Stop Control Register 4 */
	cpg_write(RMSTPCR4,	0x80000184U);
	/* Realtime Module Stop Control Register 5 */
	cpg_write(RMSTPCR5,	0xC3FFFFFFU);
	/* Realtime Module Stop Control Register 6 */
	cpg_write(RMSTPCR6,	0xFFFFFFFFU);
	/* Realtime Module Stop Control Register 7 */
	cpg_write(RMSTPCR7,	0xFFFFFFFFU);
	if ((prr == RCAR_CUT_ES10) || (prr == RCAR_CUT_ES11)) {
		/* Realtime Module Stop Control Register 8 */
		cpg_write(RMSTPCR8,	0x01F1FFF4U);
	} else {
		/* Realtime Module Stop Control Register 8 */
		cpg_write(RMSTPCR8,	0x01F1FFF7U);
	}
	/* Realtime Module Stop Control Register 9 */
	cpg_write(RMSTPCR9,	0xFFFFFFFEU);
	/* Realtime Module Stop Control Register 10 */
	cpg_write(RMSTPCR10,	0xFFFEFFE0U);
	/* Realtime Module Stop Control Register 11 */
	cpg_write(RMSTPCR11,	0x000000B7U);
}

static void bl2_system_cpg_init_h3(void)
{
	/* CPG (SYSTEM) registers */

	/* System Module Stop Control Register 0 */
	cpg_write(SMSTPCR0,	0x00210000U);
	/* System Module Stop Control Register 1 */
	cpg_write(SMSTPCR1,	0xFFFFFFFFU);
	/* System Module Stop Control Register 2 */
	cpg_write(SMSTPCR2,	0x340E2FDCU);
	/* System Module Stop Control Register 3 */
	cpg_write(SMSTPCR3,	0xFFFFFBDFU);
	/* System Module Stop Control Register 4 */
	cpg_write(SMSTPCR4,	0x80000004U);
	/* System Module Stop Control Register 5 */
	cpg_write(SMSTPCR5,	0xC3FFFFFFU);
	/* System Module Stop Control Register 6 */
	cpg_write(SMSTPCR6,	0xFFFFFFFFU);
	/* System Module Stop Control Register 7 */
	cpg_write(SMSTPCR7,	0xFFFFFFFFU);
	/* System Module Stop Control Register 8 */
	cpg_write(SMSTPCR8,	0x01F1FFF5U);
	/* System Module Stop Control Register 9 */
	cpg_write(SMSTPCR9,	0xFFFFFFFEU);
	/* System Module Stop Control Register 10 */
	cpg_write(SMSTPCR10,	0xFFFEFFE0U);
	/* System Module Stop Control Register 11 */
	cpg_write(SMSTPCR11,	0x000000B7U);
}
#endif /* (RCAR_LSI == RCAR_AUTO) || (RCAR_LSI == RCAR_H3) */

#if (RCAR_LSI == RCAR_AUTO) || (RCAR_LSI == RCAR_M3)
static void bl2_realtime_cpg_init_m3(void)
{
	/* CPG (REALTIME) registers */

	/* Realtime Module Stop Control Register 0 */
	cpg_write(RMSTPCR0,	0x00200000U);
	/* Realtime Module Stop Control Register 1 */
	cpg_write(RMSTPCR1,	0xFFFFFFFFU);
	/* Realtime Module Stop Control Register 2 */
	cpg_write(RMSTPCR2,	0x340E0FDCU);
	/* Realtime Module Stop Control Register 3 */
	cpg_write(RMSTPCR3,	0xFFFFFFDFU);
	/* Realtime Module Stop Control Register 4 */
	cpg_write(RMSTPCR4,	0x80000184U);
	/* Realtime Module Stop Control Register 5 */
	cpg_write(RMSTPCR5,	0xC3FFFFFFU);
	/* Realtime Module Stop Control Register 6 */
	cpg_write(RMSTPCR6,	0xFFFFFFFFU);
	/* Realtime Module Stop Control Register 7 */
	cpg_write(RMSTPCR7,	0xFFFFFFFFU);
	/* Realtime Module Stop Control Register 8 */
	cpg_write(RMSTPCR8,	0x01F1FFF7U);
	/* Realtime Module Stop Control Register 9 */
	cpg_write(RMSTPCR9,	0xFFFFFFFEU);
	/* Realtime Module Stop Control Register 10 */
	cpg_write(RMSTPCR10,	0xFFFEFFE0U);
	/* Realtime Module Stop Control Register 11 */
	cpg_write(RMSTPCR11,	0x000000B7U);
}

static void bl2_system_cpg_init_m3(void)
{
	/* CPG (SYSTEM) registers */

	/* System Module Stop Control Register 0 */
	cpg_write(SMSTPCR0,	0x00200000U);
	/* System Module Stop Control Register 1 */
	cpg_write(SMSTPCR1,	0xFFFFFFFFU);
	/* System Module Stop Control Register 2 */
	cpg_write(SMSTPCR2,	0x340E2FDCU);
	/* System Module Stop Control Register 3 */
	cpg_write(SMSTPCR3,	0xFFFFFBDFU);
	/* System Module Stop Control Register 4 */
	cpg_write(SMSTPCR4,	0x80000004U);
	/* System Module Stop Control Register 5 */
	cpg_write(SMSTPCR5,	0xC3FFFFFFU);
	/* System Module Stop Control Register 6 */
	cpg_write(SMSTPCR6,	0xFFFFFFFFU);
	/* System Module Stop Control Register 7 */
	cpg_write(SMSTPCR7,	0xFFFFFFFFU);
	/* System Module Stop Control Register 8 */
	cpg_write(SMSTPCR8,	0x01F1FFF7U);
	/* System Module Stop Control Register 9 */
	cpg_write(SMSTPCR9,	0xFFFFFFFEU);
	/* System Module Stop Control Register 10 */
	cpg_write(SMSTPCR10,	0xFFFEFFE0U);
	/* System Module Stop Control Register 11 */
	cpg_write(SMSTPCR11,	0x000000B7U);
}
#endif /* (RCAR_LSI == RCAR_AUTO) || (RCAR_LSI == RCAR_M3) */

void bl2_cpg_init(void)
{
	uint32_t	modemr;
#if RCAR_LSI == RCAR_AUTO
	uint32_t	prr;
#endif /* RCAR_LSI == RCAR_AUTO */

	/* CPG (SECURITY) registers */
	bl2_secure_cpg_init();

	modemr = mmio_read_32(RCAR_MODEMR);
	modemr &= MODEMR_BOOT_CPU_MASK;

	/* CPG (REALTIME) registers */
	if((modemr == MODEMR_BOOT_CPU_CA57) ||
	   (modemr == MODEMR_BOOT_CPU_CA53)) {
#if RCAR_LSI == RCAR_AUTO
		prr = mmio_read_32(RCAR_PRR) & RCAR_PRODUCT_MASK;
		switch (prr) {
		case RCAR_PRODUCT_H3:
			bl2_realtime_cpg_init_h3();
			break;
		case RCAR_PRODUCT_M3:
			bl2_realtime_cpg_init_m3();
			break;
		default:
			panic();
			break;
		}
#elif RCAR_LSI == RCAR_H3
		bl2_realtime_cpg_init_h3();
#elif RCAR_LSI == RCAR_M3
		bl2_realtime_cpg_init_m3();
#else /* RCAR_LSI == RCAR_XX */
#error "Don't have CPG initialize routine(unknown)."
#endif /* RCAR_LSI == RCAR_XX */
	}
}

void bl2_system_cpg_init(void)
{
#if RCAR_LSI == RCAR_AUTO
	uint32_t	prr;

	prr = mmio_read_32(RCAR_PRR) & RCAR_PRODUCT_MASK;
	switch (prr) {
	case RCAR_PRODUCT_H3:
		bl2_system_cpg_init_h3();
		break;
	case RCAR_PRODUCT_M3:
		bl2_system_cpg_init_m3();
		break;
	default:
		panic();
		break;
	}
#elif RCAR_LSI == RCAR_H3
	bl2_system_cpg_init_h3();
#elif RCAR_LSI == RCAR_M3
	bl2_system_cpg_init_m3();
#else /* RCAR_LSI == RCAR_XX */
#error "Don't have CPG initialize routine(unknown)."
#endif /* RCAR_LSI == RCAR_XX */
}

void cpg_write(uintptr_t regadr, uint32_t regval)
{
	uint32_t value = (regval);
	mmio_write_32((uintptr_t)CPG_CPGWPR,~value);
	mmio_write_32(regadr,value);
}