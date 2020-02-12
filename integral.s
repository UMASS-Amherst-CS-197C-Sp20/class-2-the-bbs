	.file	"integral.c"
	.section	.rodata
	.align 8
.LC3:
	.string	"The integral of sin(x) from x=0 to x=2*pi is approximately %f\n"
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
	subq	$48, %rsp
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -16(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -24(%rbp)
	movl	$0, -28(%rbp)
	jmp	.L2
.L3:
	pxor	%xmm0, %xmm0
	cvtsi2sd	-28(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	mulsd	-16(%rbp), %xmm0
	movsd	%xmm0, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -40(%rbp)
	movsd	-40(%rbp), %xmm0
	call	sin
	movapd	%xmm0, %xmm1
	movsd	-24(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	addl	$1, -28(%rbp)
.L2:
	cmpl	$9999, -28(%rbp)
	jle	.L3
	movq	-24(%rbp), %rax
	movq	%rax, -40(%rbp)
	movsd	-40(%rbp), %xmm0
	movl	$.LC3, %edi
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
	.align 8
.LC0:
	.long	1413754136
	.long	1075388923
	.align 8
.LC2:
	.long	0
	.long	1086556160
	.ident	"GCC: (Ubuntu 5.5.0-12ubuntu1~16.04) 5.5.0 20171010"
	.section	.note.GNU-stack,"",@progbits
