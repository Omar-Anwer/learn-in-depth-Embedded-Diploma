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
	ldr	r3, .L3
	ldr	r2, .L3+4
	str	r2, [r3]
	ldr	r3, .L3+8
	ldr	r2, .L3+12
	str	r2, [r3]
	ldr	r3, .L3+16
	ldr	r2, .L3+20
	str	r2, [r3]
.L2:
	ldr	r3, .L3+8
	ldr	r3, [r3]
	mov	lr, pc
	bx	r3
	ldr	r3, .L3+16
	ldr	r3, [r3]
	mov	lr, pc
	bx	r3
	ldr	r3, .L3
	ldr	r3, [r3]
	mov	lr, pc
	bx	r3
	b	.L2
.L4:
	.align	2
.L3:
	.word	ALARM_STATE
	.word	ST_ALARM_WAITING
	.word	PS_STATE
	.word	ST_PS_READING
	.word	PRESSURE_DETECTION_STATE
	.word	ST_PRESSURE_DETECTION
	.size	main, .-main
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
