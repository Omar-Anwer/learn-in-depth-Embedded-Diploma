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
	.file	"main.c"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	bl	GPIO_INITIALIZATION
	bl	PressureSensor_Init
	bl	Alarm_Init
.L3:
	bl	getPressureVal
	ldr	r3, .L4
	ldr	r3, [r3]
	cmp	r3, #20
	bls	.L3
	bl	StartAlarm
	ldr	r0, .L4+4
	bl	Delay
	bl	StopAlarm
	b	.L3
.L5:
	.align	2
.L4:
	.word	g_pressureVal
	.word	30000000
	.size	main, .-main
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
