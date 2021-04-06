	.file	"vec.cpp"
	.section	.text.unlikely._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
.LCOLDB0:
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
.LHOTB0:
	.align 2
	.p2align 4,,15
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1210:
	.cfi_startproc
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1210:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.section	.text.unlikely._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
.LCOLDE0:
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
.LHOTE0:
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"elapsed milliseconds: "
	.section	.text.unlikely,"ax",@progbits
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.globl	_Z4testiRKSt6vectorIiSaIiEE
	.type	_Z4testiRKSt6vectorIiSaIiEE, @function
_Z4testiRKSt6vectorIiSaIiEE:
.LFB2178:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movl	%edi, %r12d
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rsi, %rbx
	call	_ZNSt6chrono3_V212system_clock3nowEv
	testl	%r12d, %r12d
	movq	%rax, %rbp
	jle	.L10
	movq	(%rbx), %r8
	movq	8(%rbx), %rdx
	xorl	%ecx, %ecx
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L6:
	cmpq	%rdx, %r8
	je	.L4
	movq	%r8, %rax
	.p2align 4,,10
	.p2align 3
.L5:
#APP
# 14 "vec.cpp" 1
	#LLVM-MCA-BEGIN test
# 0 "" 2
#NO_APP
	addl	(%rax), %ebx
	addq	$4, %rax
	cmpq	%rax, %rdx
	jne	.L5
.L4:
#APP
# 17 "vec.cpp" 1
	#LLVM-MCA-END
# 0 "" 2
#NO_APP
	addl	$1, %ecx
	cmpl	%ecx, %r12d
	jne	.L6
.L3:
	call	_ZNSt6chrono3_V212system_clock3nowEv
	movabsq	$4835703278458516699, %rdx
	subq	%rbp, %rax
	movl	$.LC1, %esi
	movq	%rax, %rcx
	movl	$_ZSt4cout, %edi
	imulq	%rdx
	sarq	$63, %rcx
	sarq	$18, %rdx
	subq	%rcx, %rdx
	movq	%rdx, %rbp
	movl	$22, %edx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	%rbp, %rsi
	movl	$_ZSt4cout, %edi
	call	_ZNSo9_M_insertIlEERSoT_
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbp
	testq	%rbp, %rbp
	je	.L17
	cmpb	$0, 56(%rbp)
	je	.L8
	movsbl	67(%rbp), %esi
.L9:
	movq	%r12, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	movl	%ebx, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L8:
	.cfi_restore_state
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	0(%rbp), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L9
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L9
.L10:
	xorl	%ebx, %ebx
	jmp	.L3
.L17:
	call	_ZSt16__throw_bad_castv
	.cfi_endproc
.LFE2178:
	.size	_Z4testiRKSt6vectorIiSaIiEE, .-_Z4testiRKSt6vectorIiSaIiEE
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.text.unlikely
.LCOLDB3:
	.text
.LHOTB3:
	.p2align 4,,15
	.globl	_Z4testiRKNSt7__cxx114listIiSaIiEEE
	.type	_Z4testiRKNSt7__cxx114listIiSaIiEEE, @function
_Z4testiRKNSt7__cxx114listIiSaIiEEE:
.LFB2187:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movl	%edi, %r13d
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rsi, %rbp
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	call	_ZNSt6chrono3_V212system_clock3nowEv
	testl	%r13d, %r13d
	movq	%rax, %r12
	jle	.L26
	movq	0(%rbp), %rcx
	xorl	%edx, %edx
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L22:
	cmpq	%rcx, %rbp
	je	.L20
	movq	%rcx, %rax
	.p2align 4,,10
	.p2align 3
.L21:
#APP
# 32 "vec.cpp" 1
	#LLVM-MCA-BEGIN test
# 0 "" 2
#NO_APP
	addl	16(%rax), %ebx
	movq	(%rax), %rax
	cmpq	%rax, %rbp
	jne	.L21
.L20:
#APP
# 35 "vec.cpp" 1
	#LLVM-MCA-END
# 0 "" 2
#NO_APP
	addl	$1, %edx
	cmpl	%edx, %r13d
	jne	.L22
.L19:
	call	_ZNSt6chrono3_V212system_clock3nowEv
	movabsq	$4835703278458516699, %rdx
	subq	%r12, %rax
	movl	$.LC1, %esi
	movq	%rax, %rcx
	movl	$_ZSt4cout, %edi
	imulq	%rdx
	sarq	$63, %rcx
	sarq	$18, %rdx
	subq	%rcx, %rdx
	movq	%rdx, %rbp
	movl	$22, %edx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	%rbp, %rsi
	movl	$_ZSt4cout, %edi
	call	_ZNSo9_M_insertIlEERSoT_
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbp
	testq	%rbp, %rbp
	je	.L32
	cmpb	$0, 56(%rbp)
	je	.L24
	movsbl	67(%rbp), %esi
.L25:
	movq	%r12, %rdi
	call	_ZNSo3putEc
	movq	%rax, %rdi
	call	_ZNSo5flushEv
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movl	%ebx, %eax
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L24:
	.cfi_restore_state
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	0(%rbp), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	$_ZNKSt5ctypeIcE8do_widenEc, %rax
	je	.L25
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L25
.L26:
	xorl	%ebx, %ebx
	jmp	.L19
.L32:
	call	_ZSt16__throw_bad_castv
	.cfi_endproc
.LFE2187:
	.size	_Z4testiRKNSt7__cxx114listIiSaIiEEE, .-_Z4testiRKNSt7__cxx114listIiSaIiEEE
	.section	.text.unlikely
.LCOLDE3:
	.text
.LHOTE3:
	.section	.text.unlikely._ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_,"axG",@progbits,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_,comdat
	.align 2
.LCOLDB4:
	.section	.text._ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_,"axG",@progbits,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_,comdat
.LHOTB4:
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_
	.type	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_, @function
_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_:
.LFB2420:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movq	%rsi, %r12
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movq	8(%rdi), %rax
	movq	%rdi, %rbx
	subq	(%rdi), %rax
	sarq	$2, %rax
	testq	%rax, %rax
	je	.L41
	leaq	(%rax,%rax), %rdx
	cmpq	%rdx, %rax
	jbe	.L53
.L42:
	movq	$-4, %r13
	jmp	.L34
	.p2align 4,,10
	.p2align 3
.L41:
	movl	$4, %r13d
.L34:
	movq	%r13, %rdi
	call	_Znwm
	movq	%rax, %rbp
.L40:
	movq	(%rbx), %r14
	movq	8(%rbx), %rdx
	movl	(%r12), %ecx
	movq	%rbp, %r12
	subq	%r14, %rdx
	movq	%rdx, %rax
	sarq	$2, %rax
	addq	%rdx, %r12
	je	.L36
	movl	%ecx, (%r12)
.L36:
	testq	%rax, %rax
	jne	.L54
	addq	$4, %r12
	testq	%r14, %r14
	je	.L39
.L38:
	movq	%r14, %rdi
	call	_ZdlPv
.L39:
	movq	%rbp, (%rbx)
	addq	%r13, %rbp
	movq	%r12, 8(%rbx)
	movq	%rbp, 16(%rbx)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L54:
	.cfi_restore_state
	movq	%r14, %rsi
	movq	%rbp, %rdi
	addq	$4, %r12
	call	memmove
	jmp	.L38
.L53:
	movabsq	$4611686018427387903, %rcx
	cmpq	%rcx, %rdx
	ja	.L42
	xorl	%r13d, %r13d
	xorl	%ebp, %ebp
	testq	%rdx, %rdx
	je	.L40
	leaq	0(,%rax,8), %r13
	jmp	.L34
	.cfi_endproc
.LFE2420:
	.size	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_, .-_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_
	.section	.text.unlikely._ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_,"axG",@progbits,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_,comdat
.LCOLDE4:
	.section	.text._ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_,"axG",@progbits,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_,comdat
.LHOTE4:
	.weak	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIiEEEvDpOT_
	.set	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIiEEEvDpOT_,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_
	.section	.text.unlikely
.LCOLDB5:
	.section	.text.startup,"ax",@progbits
.LHOTB5:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB2188:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA2188
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movl	$10000, %ebx
	subq	$80, %rsp
	.cfi_def_cfa_offset 112
	leaq	48(%rsp), %rbp
	movq	$0, 16(%rsp)
	movq	$0, 24(%rsp)
	movq	%fs:40, %rax
	movq	%rax, 72(%rsp)
	xorl	%eax, %eax
	movq	$0, 32(%rsp)
	movq	$0, 64(%rsp)
	movq	%rbp, 48(%rsp)
	movq	%rbp, 56(%rsp)
	jmp	.L59
	.p2align 4,,10
	.p2align 3
.L83:
	testq	%rdx, %rdx
	je	.L57
	movl	%eax, (%rdx)
.L57:
	addq	$4, %rdx
	movq	%rdx, 24(%rsp)
.L58:
	call	rand
	movl	$24, %edi
	movl	%eax, %r12d
.LEHB0:
	call	_Znwm
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	movq	%rbp, %rsi
	movl	%r12d, 16(%rax)
	movq	%rax, %rdi
	call	_ZNSt8__detail15_List_node_base7_M_hookEPS0_
	addq	$1, 64(%rsp)
	subl	$1, %ebx
	je	.L82
.L59:
	call	rand
	movq	24(%rsp), %rdx
	cmpq	32(%rsp), %rdx
	movl	%eax, 12(%rsp)
	jne	.L83
	leaq	12(%rsp), %rsi
	leaq	16(%rsp), %rdi
	call	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJiEEEvDpOT_
	jmp	.L58
	.p2align 4,,10
	.p2align 3
.L82:
	leaq	16(%rsp), %rsi
	movl	$100000, %edi
	call	_Z4testiRKSt6vectorIiSaIiEE
	movq	%rbp, %rsi
	movl	$100000, %edi
	movl	%eax, %ebx
	call	_Z4testiRKNSt7__cxx114listIiSaIiEEE
	leal	(%rbx,%rax), %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEi
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
.LEHE0:
	movq	48(%rsp), %rdi
	cmpq	%rbp, %rdi
	je	.L63
	.p2align 4,,10
	.p2align 3
.L76:
	movq	(%rdi), %rbx
	call	_ZdlPv
	cmpq	%rbp, %rbx
	movq	%rbx, %rdi
	jne	.L76
.L63:
	movq	16(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L62
	call	_ZdlPv
.L62:
	xorl	%eax, %eax
	movq	72(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L84
	addq	$80, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L70:
	.cfi_restore_state
	movq	48(%rsp), %rdi
	movq	%rax, %rbx
.L67:
	cmpq	%rbp, %rdi
	je	.L66
	movq	(%rdi), %r12
	call	_ZdlPv
	movq	%r12, %rdi
	jmp	.L67
.L84:
	call	__stack_chk_fail
.L66:
	movq	16(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L68
	call	_ZdlPv
.L68:
	movq	%rbx, %rdi
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
	.cfi_endproc
.LFE2188:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA2188:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2188-.LLSDACSB2188
.LLSDACSB2188:
	.uleb128 .LEHB0-.LFB2188
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L70-.LFB2188
	.uleb128 0
	.uleb128 .LEHB1-.LFB2188
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE2188:
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE5:
	.section	.text.startup
.LHOTE5:
	.section	.text.unlikely
.LCOLDB6:
	.section	.text.startup
.LHOTB6:
	.p2align 4,,15
	.type	_GLOBAL__sub_I__Z4testiRKSt6vectorIiSaIiEE, @function
_GLOBAL__sub_I__Z4testiRKSt6vectorIiSaIiEE:
.LFB2528:
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
.LFE2528:
	.size	_GLOBAL__sub_I__Z4testiRKSt6vectorIiSaIiEE, .-_GLOBAL__sub_I__Z4testiRKSt6vectorIiSaIiEE
	.section	.text.unlikely
.LCOLDE6:
	.section	.text.startup
.LHOTE6:
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z4testiRKSt6vectorIiSaIiEE
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
