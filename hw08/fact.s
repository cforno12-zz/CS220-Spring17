   1              		.file	"fact.c"
   2              	# GNU C (Debian 4.9.2-10) version 4.9.2 (x86_64-linux-gnu)
   3              	#	compiled by GNU C version 4.9.2, GMP version 6.0.0, MPFR version 3.1.2-p3, MPC version 1.0.2
   4              	# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   5              	# options passed:  -imultiarch x86_64-linux-gnu fact.c -mtune=generic
   6              	# -march=x86-64 -g -O0 -fverbose-asm
   7              	# options enabled:  -faggressive-loop-optimizations
   8              	# -fasynchronous-unwind-tables -fauto-inc-dec -fcommon
   9              	# -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
  10              	# -feliminate-unused-debug-types -ffunction-cse -fgcse-lm -fgnu-runtime
  11              	# -fgnu-unique -fident -finline-atomics -fira-hoist-pressure
  12              	# -fira-share-save-slots -fira-share-spill-slots -fivopts
  13              	# -fkeep-static-consts -fleading-underscore -fmath-errno
  14              	# -fmerge-debug-strings -fpeephole -fprefetch-loop-arrays
  15              	# -freg-struct-return -fsched-critical-path-heuristic
  16              	# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
  17              	# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
  18              	# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fshow-column
  19              	# -fsigned-zeros -fsplit-ivs-in-unroller -fstrict-volatile-bitfields
  20              	# -fsync-libcalls -ftrapping-math -ftree-coalesce-vars -ftree-cselim
  21              	# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
  22              	# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
  23              	# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
  24              	# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
  25              	# -malign-stringops -mavx256-split-unaligned-load
  26              	# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
  27              	# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
  28              	# -msse -msse2 -mtls-direct-seg-refs
  29              	
  30              		.text
  31              	.Ltext0:
  32              		.section	.rodata
  33              	.LC0:
  34 0000 46616374 		.string	"Factorial 4=%d\n"
  34      6F726961 
  34      6C20343D 
  34      25640A00 
  35              		.text
  36              		.globl	main
  38              	main:
  39              	.LFB2:
  40              		.file 1 "fact.c"
   1:fact.c        **** #include <stdio.h>
   2:fact.c        **** #include <stdlib.h>
   3:fact.c        **** 
   4:fact.c        **** 
   5:fact.c        **** int main(int argc, char *argv[])
   6:fact.c        **** {
  41              		.loc 1 6 0
  42              		.cfi_startproc
  43 0000 55       		pushq	%rbp	#
  44              		.cfi_def_cfa_offset 16
  45              		.cfi_offset 6, -16
  46 0001 4889E5   		movq	%rsp, %rbp	#,
  47              		.cfi_def_cfa_register 6
  48 0004 4883EC10 		subq	$16, %rsp	#,
  49 0008 897DFC   		movl	%edi, -4(%rbp)	# argc, argc
  50 000b 488975F0 		movq	%rsi, -16(%rbp)	# argv, argv
   7:fact.c        **** 
   8:fact.c        ****    printf("Factorial 4=%d\n",factorial(4));
  51              		.loc 1 8 0
  52 000f BF040000 		movl	$4, %edi	#,
  52      00
  53 0014 B8000000 		movl	$0, %eax	#,
  53      00
  54 0019 E8000000 		call	factorial	#
  54      00
  55 001e 89C6     		movl	%eax, %esi	# D.2728,
  56 0020 BF000000 		movl	$.LC0, %edi	#,
  56      00
  57 0025 B8000000 		movl	$0, %eax	#,
  57      00
  58 002a E8000000 		call	printf	#
  58      00
   9:fact.c        **** 
  10:fact.c        **** 	exit(0);
  59              		.loc 1 10 0
  60 002f BF000000 		movl	$0, %edi	#,
  60      00
  61 0034 E8000000 		call	exit	#
  61      00
  62              		.cfi_endproc
  63              	.LFE2:
  65              		.globl	factorial
  67              	factorial:
  68              	.LFB3:
  11:fact.c        **** }
  12:fact.c        **** 
  13:fact.c        **** int factorial(int n) {
  69              		.loc 1 13 0
  70              		.cfi_startproc
  71 0039 55       		pushq	%rbp	#
  72              		.cfi_def_cfa_offset 16
  73              		.cfi_offset 6, -16
  74 003a 4889E5   		movq	%rsp, %rbp	#,
  75              		.cfi_def_cfa_register 6
  76 003d 4883EC20 		subq	$32, %rsp	#,
  77 0041 897DEC   		movl	%edi, -20(%rbp)	# n, n
  14:fact.c        **** 	int answer;
  15:fact.c        **** 	if (n<2) answer=n;
  78              		.loc 1 15 0
  79 0044 837DEC01 		cmpl	$1, -20(%rbp)	#, n
  80 0048 7F08     		jg	.L3	#,
  81              		.loc 1 15 0 is_stmt 0 discriminator 1
  82 004a 8B45EC   		movl	-20(%rbp), %eax	# n, tmp87
  83 004d 8945FC   		movl	%eax, -4(%rbp)	# tmp87, answer
  84 0050 EB14     		jmp	.L4	#
  85              	.L3:
  16:fact.c        **** 	else answer=(factorial(n-1) * n);
  86              		.loc 1 16 0 is_stmt 1
  87 0052 8B45EC   		movl	-20(%rbp), %eax	# n, tmp88
  88 0055 83E801   		subl	$1, %eax	#, D.2730
  89 0058 89C7     		movl	%eax, %edi	# D.2730,
  90 005a E8000000 		call	factorial	#
  90      00
  91 005f 0FAF45EC 		imull	-20(%rbp), %eax	# n, tmp89
  92 0063 8945FC   		movl	%eax, -4(%rbp)	# tmp89, answer
  93              	.L4:
  17:fact.c        **** 	return answer;
  94              		.loc 1 17 0
  95 0066 8B45FC   		movl	-4(%rbp), %eax	# answer, D.2730
  18:fact.c        **** }
  96              		.loc 1 18 0
  97 0069 C9       		leave
  98              		.cfi_def_cfa 7, 8
  99 006a C3       		ret
 100              		.cfi_endproc
 101              	.LFE3:
 103              	.Letext0:
