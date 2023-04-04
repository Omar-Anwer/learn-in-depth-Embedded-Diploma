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
	.global	g_pressureVal
	.bss
	.align	2
	.type	g_pressureVal, %object
	.size	g_pressureVal, 4
g_pressureVal:
	.space	4
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
	ldr	r3, .L2
	mov	r2, #0
	str	r2, [r3]
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
.L3:
	.align	2
.L2:
	.word	g_pressureVal
	.size	PressureSensor_Init, .-PressureSensor_Init
	.align	2
	.global	getPressureVal
	.syntax unified
	.arm
	.type	getPressureVal, %function
getPressureVal:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	ldr	r3, .L5
	ldr	r3, [r3]
	and	r3, r3, #255
	ldr	r2, .L5+4
	str	r3, [r2]
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
.L6:
	.align	2
.L5:
	.word	1073809416
	.word	g_pressureVal
	.size	getPressureVal, .-getPressureVal
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
