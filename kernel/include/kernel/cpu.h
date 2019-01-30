/*******************************************************************************
 * SOURCE NAME  : cpu.h
 * AUTHOR       : Aurélien Martin
 * DESCRIPTION  : Define structures about the cpu.
 ******************************************************************************/

#ifndef CPU_CPU_H
#define CPU_CPU_H

#include <stdint.h>

struct regs {
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t esp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;
};

#endif