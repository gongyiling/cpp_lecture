	.file	"main.cpp"
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2393:
	.cfi_startproc
	cmpl	$1, %edi
	je	.L7
.L4:
	ret
.L7:
	cmpl	$65535, %esi
	jne	.L4
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	call	__cxa_atexit@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE2393:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.globl	_Z13test_registerv
	.type	_Z13test_registerv, @function
_Z13test_registerv:
.LFB1876:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	call	rand@PLT
	movl	%eax, %r12d
	call	rand@PLT
	movl	%eax, %ebp
	call	rand@PLT
	movl	%eax, %ebx
	call	rand@PLT
	movl	%eax, %r8d
	movl	$0, %edx
	movl	$0, %esi
	movl	$0, %edi
	movl	$0, %eax
	movl	$0, %ecx
.L10:
	cmpl	$1073741823, %edx
	jg	.L9
	addl	%r12d, %ecx
	addl	%ebp, %eax
	addl	%ebx, %edi
	addl	%r8d, %esi
	addl	$1, %edx
	jmp	.L10
.L9:
	addl	%ecx, %eax
	addl	%edi, %eax
	addl	%esi, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1876:
	.size	_Z13test_registerv, .-_Z13test_registerv
	.globl	_Z11test_memoryv
	.type	_Z11test_memoryv, @function
_Z11test_memoryv:
.LFB1877:
	.cfi_startproc
	endbr64
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	call	rand@PLT
	movl	%eax, (%rsp)
	call	rand@PLT
	movl	%eax, 4(%rsp)
	call	rand@PLT
	movl	%eax, 8(%rsp)
	call	rand@PLT
	movl	%eax, 12(%rsp)
	movl	$0, %eax
	movl	$0, %ecx
	movl	$0, %esi
	movl	$0, %edi
	movl	$0, %edx
.L14:
	cmpl	$1073741823, %eax
	jg	.L13
	addl	(%rsp), %edx
	addl	4(%rsp), %edi
	addl	8(%rsp), %esi
	addl	12(%rsp), %ecx
	addl	$1, %eax
	jmp	.L14
.L13:
	leal	(%rdx,%rdi), %eax
	addl	%esi, %eax
	addl	%ecx, %eax
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1877:
	.size	_Z11test_memoryv, .-_Z11test_memoryv
	.section	.text._ZNSt6chronomiINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE,"axG",@progbits,_ZNSt6chronomiINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE,comdat
	.weak	_ZNSt6chronomiINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE
	.type	_ZNSt6chronomiINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE, @function
_ZNSt6chronomiINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE:
.LFB1885:
	.cfi_startproc
	endbr64
	movq	(%rdi), %rax
	subq	(%rsi), %rax
	ret
	.cfi_endproc
.LFE1885:
	.size	_ZNSt6chronomiINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE, .-_ZNSt6chronomiINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE
	.text
	.globl	main
	.type	main, @function
main:
.LFB1878:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$32, %rsp
	.cfi_def_cfa_offset 64
	movl	$40, %ebp
	movq	%fs:0(%rbp), %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movq	%rax, (%rsp)
	call	_Z13test_registerv
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movq	%rax, 8(%rsp)
	call	_Z11test_memoryv
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movq	%rax, 16(%rsp)
	movq	%rsp, %rsi
	leaq	8(%rsp), %r12
	movq	%r12, %rdi
	call	_ZNSt6chronomiINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE
	movq	%rax, %rcx
	movabsq	$4835703278458516699, %rbx
	imulq	%rbx
	sarq	$18, %rdx
	sarq	$63, %rcx
	subq	%rcx, %rdx
	movq	%rdx, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIlEERSoT_@PLT
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@PLT
	leaq	16(%rsp), %rdi
	movq	%r12, %rsi
	call	_ZNSt6chronomiINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE
	movq	%rax, %rcx
	imulq	%rbx
	sarq	$18, %rdx
	sarq	$63, %rcx
	movq	%rdx, %rsi
	subq	%rcx, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIlEERSoT_@PLT
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@PLT
	movq	24(%rsp), %rax
	xorq	%fs:0(%rbp), %rax
	jne	.L20
	movl	$0, %eax
	addq	$32, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L20:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1878:
	.size	main, .-main
	.type	_GLOBAL__sub_I__Z13test_registerv, @function
_GLOBAL__sub_I__Z13test_registerv:
.LFB2394:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE2394:
	.size	_GLOBAL__sub_I__Z13test_registerv, .-_GLOBAL__sub_I__Z13test_registerv
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z13test_registerv
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
