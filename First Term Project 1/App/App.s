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
	.file	"App.c"
	.text
	.global	g_pressureVal
	.bss
	.align	2
	.type	g_pressureVal, %object
	.size	g_pressureVal, 4
g_pressureVal:
	.space	4
	.global	pressure_Threshold
	.section	.rodata
	.align	2
	.type	pressure_Threshold, %object
	.size	pressure_Threshold, 4
pressure_Threshold:
	.word	20
	.global	PRESSURE_DETECTION_STATE
	.bss
	.align	2
	.type	PRESSURE_DETECTION_STATE, %object
	.size	PRESSURE_DETECTION_STATE, 4
PRESSURE_DETECTION_STATE:
	.space	4
	.global	PRESSURE_DETECTION_STATE_ID
	.type	PRESSURE_DETECTION_STATE_ID, %object
	.size	PRESSURE_DETECTION_STATE_ID, 1
PRESSURE_DETECTION_STATE_ID:
	.space	1
	.text
	.align	2
	.global	ST_PRESSURE_DETECTION
	.syntax unified
	.arm
	.type	ST_PRESSURE_DETECTION, %function
ST_PRESSURE_DETECTION:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	ldr	r3, .L4
	mov	r2, #0
	strb	r2, [r3]
	ldr	r3, .L4+4
	ldr	r3, [r3]
	mov	r2, #20
	cmp	r3, r2
	ble	.L3
	bl	StartAlarm
	ldr	r0, .L4+8
	bl	Delay
	bl	StopAlarm
.L3:
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L5:
	.align	2
.L4:
	.word	PRESSURE_DETECTION_STATE_ID
	.word	g_pressureVal
	.word	32040000
	.size	ST_PRESSURE_DETECTION, .-ST_PRESSURE_DETECTION
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
