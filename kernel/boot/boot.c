/*******************************************************************************
 * SOURCE NAME  : boot.c
 * AUTHOR       : Aurélien Martin
 * DESCRIPTION  : Contains the initial code executed after the bootloader.
 ******************************************************************************/

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <kernel/debug.h>
#include <kernel/cpu/gdt.h>
#include <kernel/cpu/idt.h>
#include <kernel/memory/paging.h>
#include <kernel/memory/heap.h>
#include <kernel/kernel.h>
#include <kernel/device/ata.h>
#include <kernel/tests.h>

#include "multiboot.h"

/**
 * @brief The main entry point of the kernel
 */
void kernel_main(struct mb_info *boot_info)
{
    if (!parse_boot_info(boot_info)) {
        KERNEL_PANIC("[PANIC] Invalid boot info!!");
    }

    gdt_install();
    idt_install();
    paging_install(KERNEL.memlen, KERNEL_END);
    
    heap_install();

    ata_install();
    
    test_all();
}
