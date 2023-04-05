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
	.file	"Alarm.c"
	.text
	.global	ALARM_STATE
	.bss
	.align	2
	.type	ALARM_STATE, %object
	.size	ALARM_STATE, 4
ALARM_STATE:
	.space	4
	.global	ALARM_STATE_ID
	.type	ALARM_STATE_ID, %object
	.size	ALARM_STATE_ID, 1
ALARM_STATE_ID:
	.space	1
	.text
	.align	2
	.global	ST_ALARM_WAITING
	.syntax unified
	.arm
	.type	ST_ALARM_WAITING, %function
ST_ALARM_WAITING:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	ldr	r3, .L2
	mov	r2, #2
	strb	r2, [r3]
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
.L3:
	.align	2
.L2:
	.word	ALARM_STATE_ID
	.size	ST_ALARM_WAITING, .-ST_ALARM_WAITING
	.align	2
	.global	ST_ALARM_ON
	.syntax unified
	.arm
	.type	ST_ALARM_ON, %function
ST_ALARM_ON:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	ldr	r3, .L5
	mov	r2, #1
	strb	r2, [r3]
	mov	r0, #1
	bl	Set_Alarm_actuator
	ldr	r3, .L5+4
	ldr	r2, .L5+8
	str	r2, [r3]
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L6:
	.align	2
.L5:
	.word	ALARM_STATE_ID
	.word	ALARM_STATE
	.word	ST_ALARM_WAITING
	.size	ST_ALARM_ON, .-ST_ALARM_ON
	.align	2
	.global	ST_ALARM_OFF
	.syntax unified
	.arm
	.type	ST_ALARM_OFF, %function
ST_ALARM_OFF:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	ldr	r3, .L8
	mov	r2, #0
	strb	r2, [r3]
	mov	r0, #0
	bl	Set_Alarm_actuator
	ldr	r3, .L8+4
	ldr	r2, .L8+8
	str	r2, [r3]
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L9:
	.align	2
.L8:
	.word	ALARM_STATE_ID
	.word	ALARM_STATE
	.word	ST_ALARM_WAITING
	.size	ST_ALARM_OFF, .-ST_ALARM_OFF
	.align	2
	.global	Alarm_Init
	.syntax unified
	.arm
	.type	Alarm_Init, %function
Alarm_Init:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	mov	r0, #0
	bl	Set_Alarm_actuator
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
	.size	Alarm_Init, .-Alarm_Init
	.align	2
	.global	StartAlarm
	.syntax unified
	.arm
	.type	StartAlarm, %function
StartAlarm:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	ldr	r3, .L12
	ldr	r2, .L12+4
	str	r2, [r3]
	ldr	r3, .L12
	ldr	r3, [r3]
	mov	lr, pc
	bx	r3
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L13:
	.align	2
.L12:
	.word	ALARM_STATE
	.word	ST_ALARM_ON
	.size	StartAlarm, .-StartAlarm
	.align	2
	.global	StopAlarm
	.syntax unified
	.arm
	.type	StopAlarm, %function
StopAlarm:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	ldr	r3, .L15
	ldr	r2, .L15+4
	str	r2, [r3]
	ldr	r3, .L15
	ldr	r3, [r3]
	mov	lr, pc
	bx	r3
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L16:
	.align	2
.L15:
	.word	ALARM_STATE
	.word	ST_ALARM_OFF
	.size	StopAlarm, .-StopAlarm
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
