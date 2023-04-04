	.cpu arm7tdmi
	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"startup.c"
	.text
	.align	2
	.global	Reset_Handler
	.syntax unified
	.arm
	.type	Reset_Handler, %function
Reset_Handler:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #24
	ldr	r3, .L6
	str	r3, [fp, #-8]
	ldr	r3, .L6+4
	str	r3, [fp, #-12]
	ldr	r2, .L6+8
	ldr	r3, .L6+4
	sub	r3, r2, r3
	str	r3, [fp, #-20]
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L2
.L3:
	ldr	r3, [fp, #-8]
	ldrb	r2, [r3]	@ zero_extendqisi2
	ldr	r3, [fp, #-12]
	strb	r2, [r3]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L2:
	ldr	r2, [fp, #-16]
	ldr	r3, [fp, #-20]
	cmp	r2, r3
	bcc	.L3
	ldr	r3, .L6+12
	str	r3, [fp, #-12]
	ldr	r2, .L6+16
	ldr	r3, .L6+12
	sub	r3, r2, r3
	str	r3, [fp, #-24]
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L4
.L5:
	ldr	r3, [fp, #-12]
	mov	r2, #0
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L4:
	ldr	r2, [fp, #-16]
	ldr	r3, [fp, #-24]
	cmp	r2, r3
	bcc	.L5
	bl	main
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L7:
	.align	2
.L6:
	.word	_E_text
	.word	_S_data
	.word	_E_data
	.word	_S_bss
	.word	_E_bss
	.size	Reset_Handler, .-Reset_Handler
	.align	2
	.global	Default_Handler
	.syntax unified
	.arm
	.type	Default_Handler, %function
Default_Handler:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	bl	Reset_Handler
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
	.size	Default_Handler, .-Default_Handler
	.weak	Usage_fault_Handler
	.set	Usage_fault_Handler,Default_Handler
	.weak	Bus_fault_Handler
	.set	Bus_fault_Handler,Default_Handler
	.weak	MM_fault_Handler
	.set	MM_fault_Handler,Default_Handler
	.weak	H_fault_Handler
	.set	H_fault_Handler,Default_Handler
	.weak	NMI_Handler
	.set	NMI_Handler,Default_Handler
	.global	vectors
	.section	.vectors,"aw"
	.align	2
	.type	vectors, %object
	.size	vectors, 28
vectors:
	.word	_stack_top
	.word	Reset_Handler
	.word	NMI_Handler
	.word	H_fault_Handler
	.word	MM_fault_Handler
	.word	Bus_fault_Handler
	.word	Usage_fault_Handler
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
