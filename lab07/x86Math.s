   1              		.file	"x86Math.c"
   2              	# GNU C (Debian 4.9.2-10) version 4.9.2 (x86_64-linux-gnu)
   3              	#	compiled by GNU C version 4.9.2, GMP version 6.0.0, MPFR version 3.1.2-p3, MPC version 1.0.2
   4              	# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   5              	# options passed:  -imultiarch x86_64-linux-gnu -D SIMPLE x86Math.c
   6              	# -mtune=generic -march=x86-64 -g -O0 -Wall -fverbose-asm
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
  34 0000 496E766F 		.string	"Invoke as %s <number>\n"
  34      6B652061 
  34      73202573 
  34      203C6E75 
  34      6D626572 
  35 0017 00       		.align 8
  36              	.LC1:
  37 0018 783D2564 		.string	"x=%d, x squared - 4x + 4 =%d divided by x-2=%d\n"
  37      2C207820 
  37      73717561 
  37      72656420 
  37      2D203478 
  38              		.text
  39              		.globl	main
  41              	main:
  42              	.LFB2:
  43              		.file 1 "x86Math.c"
   1:x86Math.c     **** #include <stdio.h>
   2:x86Math.c     **** #include <stdlib.h>
   3:x86Math.c     **** 
   4:x86Math.c     **** int add(int x, int y);
   5:x86Math.c     **** int mult(int x, int y);
   6:x86Math.c     **** int subtract(int x, int y);
   7:x86Math.c     **** int divide(int x, int y);
   8:x86Math.c     **** 
   9:x86Math.c     **** int main(int argc, char **argv) {
  44              		.loc 1 9 0
  45              		.cfi_startproc
  46 0000 55       		pushq	%rbp	#
  47              		.cfi_def_cfa_offset 16
  48              		.cfi_offset 6, -16
  49 0001 4889E5   		movq	%rsp, %rbp	#,
  50              		.cfi_def_cfa_register 6
  51 0004 4883EC20 		subq	$32, %rsp	#,
  52 0008 897DEC   		movl	%edi, -20(%rbp)	# argc, argc
  53 000b 488975E0 		movq	%rsi, -32(%rbp)	# argv, argv
  10:x86Math.c     **** 	if (argc < 2) {
  54              		.loc 1 10 0
  55 000f 837DEC01 		cmpl	$1, -20(%rbp)	#, argc
  56 0013 7F23     		jg	.L2	#,
  11:x86Math.c     **** 		printf("Invoke as %s <number>\n",argv[0]);
  57              		.loc 1 11 0
  58 0015 488B45E0 		movq	-32(%rbp), %rax	# argv, tmp88
  59 0019 488B00   		movq	(%rax), %rax	# *argv_3(D), D.2765
  60 001c 4889C6   		movq	%rax, %rsi	# D.2765,
  61 001f BF000000 		movl	$.LC0, %edi	#,
  61      00
  62 0024 B8000000 		movl	$0, %eax	#,
  62      00
  63 0029 E8000000 		call	printf	#
  63      00
  12:x86Math.c     **** 		return 1;
  64              		.loc 1 12 0
  65 002e B8010000 		movl	$1, %eax	#, D.2764
  65      00
  66 0033 E9A10000 		jmp	.L3	#
  66      00
  67              	.L2:
  13:x86Math.c     **** 	}
  14:x86Math.c     **** 	int x=atoi(argv[1]);
  68              		.loc 1 14 0
  69 0038 488B45E0 		movq	-32(%rbp), %rax	# argv, tmp89
  70 003c 4883C008 		addq	$8, %rax	#, D.2766
  71 0040 488B00   		movq	(%rax), %rax	# *_6, D.2765
  72 0043 4889C7   		movq	%rax, %rdi	# D.2765,
  73 0046 E8000000 		call	atoi	#
  73      00
  74 004b 8945FC   		movl	%eax, -4(%rbp)	# tmp90, x
  15:x86Math.c     **** 	int ans=mult(x,x);
  75              		.loc 1 15 0
  76 004e 8B55FC   		movl	-4(%rbp), %edx	# x, tmp91
  77 0051 8B45FC   		movl	-4(%rbp), %eax	# x, tmp92
  78 0054 89D6     		movl	%edx, %esi	# tmp91,
  79 0056 89C7     		movl	%eax, %edi	# tmp92,
  80 0058 E8000000 		call	mult	#
  80      00
  81 005d 8945F8   		movl	%eax, -8(%rbp)	# tmp93, ans
  16:x86Math.c     **** 	int term=mult(4,x);
  82              		.loc 1 16 0
  83 0060 8B45FC   		movl	-4(%rbp), %eax	# x, tmp94
  84 0063 89C6     		movl	%eax, %esi	# tmp94,
  85 0065 BF040000 		movl	$4, %edi	#,
  85      00
  86 006a E8000000 		call	mult	#
  86      00
  87 006f 8945F4   		movl	%eax, -12(%rbp)	# tmp95, term
  17:x86Math.c     **** 	ans=subtract(ans,term);
  88              		.loc 1 17 0
  89 0072 8B55F4   		movl	-12(%rbp), %edx	# term, tmp96
  90 0075 8B45F8   		movl	-8(%rbp), %eax	# ans, tmp97
  91 0078 89D6     		movl	%edx, %esi	# tmp96,
  92 007a 89C7     		movl	%eax, %edi	# tmp97,
  93 007c E8000000 		call	subtract	#
  93      00
  94 0081 8945F8   		movl	%eax, -8(%rbp)	# tmp98, ans
  18:x86Math.c     **** 	ans=add(ans,4);
  95              		.loc 1 18 0
  96 0084 8B45F8   		movl	-8(%rbp), %eax	# ans, tmp99
  97 0087 BE040000 		movl	$4, %esi	#,
  97      00
  98 008c 89C7     		movl	%eax, %edi	# tmp99,
  99 008e E8000000 		call	add	#
  99      00
 100 0093 8945F8   		movl	%eax, -8(%rbp)	# tmp100, ans
  19:x86Math.c     **** 	term=subtract(x,2);
 101              		.loc 1 19 0
 102 0096 8B45FC   		movl	-4(%rbp), %eax	# x, tmp101
 103 0099 BE020000 		movl	$2, %esi	#,
 103      00
 104 009e 89C7     		movl	%eax, %edi	# tmp101,
 105 00a0 E8000000 		call	subtract	#
 105      00
 106 00a5 8945F4   		movl	%eax, -12(%rbp)	# tmp102, term
  20:x86Math.c     **** 	int check=divide(ans,term);
 107              		.loc 1 20 0
 108 00a8 8B55F4   		movl	-12(%rbp), %edx	# term, tmp103
 109 00ab 8B45F8   		movl	-8(%rbp), %eax	# ans, tmp104
 110 00ae 89D6     		movl	%edx, %esi	# tmp103,
 111 00b0 89C7     		movl	%eax, %edi	# tmp104,
 112 00b2 E8000000 		call	divide	#
 112      00
 113 00b7 8945F0   		movl	%eax, -16(%rbp)	# tmp105, check
  21:x86Math.c     **** 	printf("x=%d, x squared - 4x + 4 =%d divided by x-2=%d\n",x,ans,check);
 114              		.loc 1 21 0
 115 00ba 8B4DF0   		movl	-16(%rbp), %ecx	# check, tmp106
 116 00bd 8B55F8   		movl	-8(%rbp), %edx	# ans, tmp107
 117 00c0 8B45FC   		movl	-4(%rbp), %eax	# x, tmp108
 118 00c3 89C6     		movl	%eax, %esi	# tmp108,
 119 00c5 BF000000 		movl	$.LC1, %edi	#,
 119      00
 120 00ca B8000000 		movl	$0, %eax	#,
 120      00
 121 00cf E8000000 		call	printf	#
 121      00
  22:x86Math.c     **** 	return 0;
 122              		.loc 1 22 0
 123 00d4 B8000000 		movl	$0, %eax	#, D.2764
 123      00
 124              	.L3:
  23:x86Math.c     **** }
 125              		.loc 1 23 0
 126 00d9 C9       		leave
 127              		.cfi_def_cfa 7, 8
 128 00da C3       		ret
 129              		.cfi_endproc
 130              	.LFE2:
 132              		.globl	add
 134              	add:
 135              	.LFB3:
  24:x86Math.c     **** 
  25:x86Math.c     **** #ifdef SIMPLE
  26:x86Math.c     **** 	int add(int x, int y) { return x+y; }
 136              		.loc 1 26 0
 137              		.cfi_startproc
 138 00db 55       		pushq	%rbp	#
 139              		.cfi_def_cfa_offset 16
 140              		.cfi_offset 6, -16
 141 00dc 4889E5   		movq	%rsp, %rbp	#,
 142              		.cfi_def_cfa_register 6
 143 00df 897DFC   		movl	%edi, -4(%rbp)	# x, x
 144 00e2 8975F8   		movl	%esi, -8(%rbp)	# y, y
 145              		.loc 1 26 0
 146 00e5 8B55FC   		movl	-4(%rbp), %edx	# x, tmp85
 147 00e8 8B45F8   		movl	-8(%rbp), %eax	# y, tmp86
 148 00eb 01D0     		addl	%edx, %eax	# tmp85, D.2769
 149 00ed 5D       		popq	%rbp	#
 150              		.cfi_def_cfa 7, 8
 151 00ee C3       		ret
 152              		.cfi_endproc
 153              	.LFE3:
 155              		.globl	subtract
 157              	subtract:
 158              	.LFB4:
  27:x86Math.c     **** 	int subtract(int x, int y) { return x-y; }
 159              		.loc 1 27 0
 160              		.cfi_startproc
 161 00ef 55       		pushq	%rbp	#
 162              		.cfi_def_cfa_offset 16
 163              		.cfi_offset 6, -16
 164 00f0 4889E5   		movq	%rsp, %rbp	#,
 165              		.cfi_def_cfa_register 6
 166 00f3 897DFC   		movl	%edi, -4(%rbp)	# x, x
 167 00f6 8975F8   		movl	%esi, -8(%rbp)	# y, y
 168              		.loc 1 27 0
 169 00f9 8B45FC   		movl	-4(%rbp), %eax	# x, tmp85
 170 00fc 2B45F8   		subl	-8(%rbp), %eax	# y, D.2770
 171 00ff 5D       		popq	%rbp	#
 172              		.cfi_def_cfa 7, 8
 173 0100 C3       		ret
 174              		.cfi_endproc
 175              	.LFE4:
 177              		.globl	mult
 179              	mult:
 180              	.LFB5:
  28:x86Math.c     **** 	int mult(int x, int y) { return x*y; }
 181              		.loc 1 28 0
 182              		.cfi_startproc
 183 0101 55       		pushq	%rbp	#
 184              		.cfi_def_cfa_offset 16
 185              		.cfi_offset 6, -16
 186 0102 4889E5   		movq	%rsp, %rbp	#,
 187              		.cfi_def_cfa_register 6
 188 0105 897DFC   		movl	%edi, -4(%rbp)	# x, x
 189 0108 8975F8   		movl	%esi, -8(%rbp)	# y, y
 190              		.loc 1 28 0
 191 010b 8B45FC   		movl	-4(%rbp), %eax	# x, tmp85
 192 010e 0FAF45F8 		imull	-8(%rbp), %eax	# y, D.2771
 193 0112 5D       		popq	%rbp	#
 194              		.cfi_def_cfa 7, 8
 195 0113 C3       		ret
 196              		.cfi_endproc
 197              	.LFE5:
 199              		.globl	divide
 201              	divide:
 202              	.LFB6:
  29:x86Math.c     **** 	int divide(int x, int y) { return x/y; }
 203              		.loc 1 29 0
 204              		.cfi_startproc
 205 0114 55       		pushq	%rbp	#
 206              		.cfi_def_cfa_offset 16
 207              		.cfi_offset 6, -16
 208 0115 4889E5   		movq	%rsp, %rbp	#,
 209              		.cfi_def_cfa_register 6
 210 0118 897DFC   		movl	%edi, -4(%rbp)	# x, x
 211 011b 8975F8   		movl	%esi, -8(%rbp)	# y, y
 212              		.loc 1 29 0
 213 011e 8B45FC   		movl	-4(%rbp), %eax	# x, tmp87
 214 0121 99       		cltd
 215 0122 F77DF8   		idivl	-8(%rbp)	# y
 216 0125 5D       		popq	%rbp	#
 217              		.cfi_def_cfa 7, 8
 218 0126 C3       		ret
 219              		.cfi_endproc
 220              	.LFE6:
 222              	.Letext0:
