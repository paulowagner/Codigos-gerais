	.file	"list02.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%f"
.LC2:
	.string	"%f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movl	%edi, -84(%rbp)
	movq	%rsi, -96(%rbp)
	movl	$2, -68(%rbp)
	movl	$2, -72(%rbp)
	movl	-72(%rbp), %eax
	cvtsi2sd	%eax, %xmm1
	cvtsi2sd	-68(%rbp), %xmm0
	call	pow
	cvttsd2si	%xmm0, %eax
	movl	%eax, -72(%rbp)
	leaq	-72(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	$0, -68(%rbp)
	jmp	.L2
.L3:
	leaq	-64(%rbp), %rax
	movl	-68(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	addl	$1, -68(%rbp)
.L2:
	movl	-72(%rbp), %eax
	cmpl	%eax, -68(%rbp)
	jl	.L3
	movl	-72(%rbp), %edx
	leaq	-64(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	mediaha
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	movl	$.LC2, %edi
	movl	$1, %eax
	call	printf
	movss	.LC3(%rip), %xmm1
	movss	.LC4(%rip), %xmm0
	call	letraj
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	movl	$.LC2, %edi
	movl	$1, %eax
	call	printf
	movss	.LC5(%rip), %xmm0
	call	detorad
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	movl	$.LC2, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC3:
	.long	1085632676
	.align 4
.LC4:
	.long	1075167887
	.align 4
.LC5:
	.long	1127481344
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
