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
	.file	"Pressure_Sensor.c"
	.text
	.align	2
	.global	PressureSensor_Init
	.syntax unified
	.arm
	.type	PressureSensor_Init, %function
PressureSensor_Init:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	PressureSensor_Init, .-PressureSensor_Init
	.global	PS_STATE
	.bss
	.align	2
	.type	PS_STATE, %object
	.size	PS_STATE, 4
PS_STATE:
	.space	4
	.global	PS_STATE_ID
	.type	PS_STATE_ID, %object
	.size	PS_STATE_ID, 1
PS_STATE_ID:
	.space	1
	.text
	.align	2
	.global	ST_PS_READING
	.syntax unified
	.arm
	.type	ST_PS_READING, %function
ST_PS_READING:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	ldr	r3, .L3
	mov	r2, #0
	strb	r2, [r3]
	bl	getPressureVal
	mov	r3, r0
	ldr	r2, .L3+4
	str	r3, [r2]
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L4:
	.align	2
.L3:
	.word	PS_STATE_ID
	.word	g_pressureVal
	.size	ST_PS_READING, .-ST_PS_READING
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
