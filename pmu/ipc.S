	.file	"ipc.cpp"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	_Z5rdpmcii
	.type	_Z5rdpmcii, @function
_Z5rdpmcii:
.LFB1781:
	.cfi_startproc
	sall	$30, %esi
	leal	(%rsi,%rdi), %ecx
#APP
# 10 "ipc.cpp" 1
	rdpmc
# 0 "" 2
#NO_APP
	movq	%rdx, %rcx
	movl	%eax, %eax
	salq	$32, %rcx
	orq	%rcx, %rax
	ret
	.cfi_endproc
.LFE1781:
	.size	_Z5rdpmcii, .-_Z5rdpmcii
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.globl	_Z3sumii
	.type	_Z3sumii, @function
_Z3sumii:
.LFB1782:
	.cfi_startproc
	testl	%esi, %esi
	jle	.L5
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3

	movl $111, %ebx
    .byte 0x64, 0x67, 0x90

.L4:
	addl	%edi, %edx
	addl	$1, %ecx
	cmpl	%ecx, %esi
	jne	.L4

	movl $222, %ebx
    .byte 0x64, 0x67, 0x90

	movl	%esi, %eax
	imull	%edi, %eax
	ret
.L5:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE1782:
	.size	_Z3sumii, .-_Z3sumii
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"sum: %d, instruction retired: %ld, cycles: %ld, instructions per cycle: %f\n"
	.section	.text.unlikely
.LCOLDB3:
	.section	.text.startup,"ax",@progbits
.LHOTB3:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1783:
	.cfi_startproc
	subq	$152, %rsp
	.cfi_def_cfa_offset 160
	movl	$16, %ecx
	movl	$128, %esi
	movq	%fs:40, %rax
	movq	%rax, 136(%rsp)
	xorl	%eax, %eax
	movq	%rsp, %rdi
	movq	%rsp, %rdx
	rep stosq
	xorl	%edi, %edi
	movq	$1, (%rsp)
	call	sched_setaffinity
	call	rand
	movl	$1073741824, %ecx
	movl	%eax, %esi
#APP
# 10 "ipc.cpp" 1
	rdpmc
# 0 "" 2
#NO_APP
	salq	$32, %rdx
	movl	%eax, %eax
	movl	$1073741825, %ecx
	orq	%rax, %rdx
	movq	%rdx, %r9
#APP
# 10 "ipc.cpp" 1
	rdpmc
# 0 "" 2
#NO_APP
	movl	%eax, %eax
	salq	$32, %rdx
	movl	$2097152, %ecx
	orq	%rax, %rdx
	xorl	%eax, %eax
	movq	%rdx, %r10
	.p2align 4,,10
	.p2align 3
.L9:
	addl	%esi, %eax
	subl	$1, %ecx
	jne	.L9
	movl	$1073741824, %ecx
#APP
# 10 "ipc.cpp" 1
	rdpmc
# 0 "" 2
#NO_APP
	movl	$1073741825, %ecx
	movl	%edx, %r8d
	movl	%eax, %edi
#APP
# 10 "ipc.cpp" 1
	rdpmc
# 0 "" 2
#NO_APP
	movq	%r8, %rcx
	movq	%rdx, %r8
	movl	%eax, %eax
	salq	$32, %rcx
	salq	$32, %r8
	orq	%rax, %r8
	orq	%rdi, %rcx
	subq	%r10, %r8
	subq	%r9, %rcx
	js	.L10
	pxor	%xmm0, %xmm0
	cvtsi2ssq	%rcx, %xmm0
.L11:
	testq	%r8, %r8
	js	.L12
	pxor	%xmm1, %xmm1
	cvtsi2ssq	%r8, %xmm1
.L13:
	movl	%esi, %edx
	movl	$1, %edi
	movl	$.LC2, %esi
	divss	%xmm1, %xmm0
	sall	$21, %edx
	movl	$1, %eax
	cvtss2sd	%xmm0, %xmm0
	call	__printf_chk
	xorl	%eax, %eax
	movq	136(%rsp), %rdi
	xorq	%fs:40, %rdi
	jne	.L17
	addq	$152, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L10:
	.cfi_restore_state
	movq	%rcx, %rax
	movq	%rcx, %rdx
	pxor	%xmm0, %xmm0
	shrq	%rax
	andl	$1, %edx
	orq	%rdx, %rax
	cvtsi2ssq	%rax, %xmm0
	addss	%xmm0, %xmm0
	jmp	.L11
.L12:
	movq	%r8, %rax
	movq	%r8, %rdx
	pxor	%xmm1, %xmm1
	shrq	%rax
	andl	$1, %edx
	orq	%rdx, %rax
	cvtsi2ssq	%rax, %xmm1
	addss	%xmm1, %xmm1
	jmp	.L13
.L17:
	call	__stack_chk_fail
	.cfi_endproc
.LFE1783:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE3:
	.section	.text.startup
.LHOTE3:
	.section	.text.unlikely
.LCOLDB4:
	.section	.text.startup
.LHOTB4:
	.p2align 4,,15
	.type	_GLOBAL__sub_I__Z5rdpmcii, @function
_GLOBAL__sub_I__Z5rdpmcii:
.LFB1969:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit
	.cfi_endproc
.LFE1969:
	.size	_GLOBAL__sub_I__Z5rdpmcii, .-_GLOBAL__sub_I__Z5rdpmcii
	.section	.text.unlikely
.LCOLDE4:
	.section	.text.startup
.LHOTE4:
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z5rdpmcii
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
