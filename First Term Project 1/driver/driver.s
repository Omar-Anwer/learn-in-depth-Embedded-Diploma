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
	.file	"driver.c"
	.text
	.align	2
	.global	Delay
	.syntax unified
	.arm
	.type	Delay, %function
Delay:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	b	.L2
.L3:
	ldr	r3, [fp, #-8]
	sub	r3, r3, #1
	str	r3, [fp, #-8]
.L2:
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L3
	nop
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	Delay, .-Delay
	.align	2
	.global	GPIO_INITIALIZATION
	.syntax unified
	.arm
	.type	GPIO_INITIALIZATION, %function
GPIO_INITIALIZATION:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	ldr	r3, .L5
	ldr	r3, [r3]
	ldr	r2, .L5
	orr	r3, r3, #4
	str	r3, [r2]
	ldr	r3, .L5+4
	ldr	r3, [r3]
	ldr	r2, .L5+4
	bic	r3, r3, #15728640
	str	r3, [r2]
	ldr	r3, .L5+4
	ldr	r2, .L5+4
	ldr	r3, [r3]
	str	r3, [r2]
	ldr	r3, .L5+8
	ldr	r3, [r3]
	ldr	r2, .L5+8
	bic	r3, r3, #15728640
	str	r3, [r2]
	ldr	r3, .L5+8
	ldr	r2, [r3]
	ldr	r1, .L5+8
	ldr	r3, .L5+12
	orr	r3, r2, r3
	str	r3, [r1]
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
.L6:
	.align	2
.L5:
	.word	1073877016
	.word	1073809408
	.word	1073809412
	.word	572662306
	.size	GPIO_INITIALIZATION, .-GPIO_INITIALIZATION
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
