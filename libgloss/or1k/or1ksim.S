#include "or1k-asm.h"
#include "or1k-support-defs.h"

/*
 * Define symbols to be used during startup - file is linked at compile time
 *
 */
.global _board_mem_base
.global _board_mem_size
.global _board_clk_freq
	
_board_mem_base:	.long	0x0
_board_mem_size:	.long	0x800000

_board_clk_freq:	.long	100000000
	
/* Peripheral information - Set base to 0 if not present*/
.global _board_uart_base
.global _board_uart_baud
.global _board_uart_IRQ
	
_board_uart_base:	.long	0x0
_board_uart_baud:	.long	115200
_board_uart_IRQ:	.long	13
	
.global _board_exit
_board_exit:
        l.nop NOP_EXIT_SILENT
        OR1K_DELAYED_NOP(l.j _board_exit)
