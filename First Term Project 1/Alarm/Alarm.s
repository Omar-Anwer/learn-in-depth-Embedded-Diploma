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
	bl	StopAlarm
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
	.size	Alarm_Init, .-Alarm_Init
	.align	2
	.global	Set_Alarm_actuator
	.syntax unified
	.arm
	.type	Set_Alarm_actuator, %function
Set_Alarm_actuator:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	cmp	r3, #1
	bne	.L3
	ldr	r3, .L6
	ldr	r3, [r3]
	ldr	r2, .L6
	orr	r3, r3, #8192
	str	r3, [r2]
	b	.L5
.L3:
	ldr	r3, [fp, #-8]
	cmp	r3, #0
	bne	.L5
	ldr	r3, .L6
	ldr	r3, [r3]
	ldr	r2, .L6
	bic	r3, r3, #8192
	str	r3, [r2]
.L5:
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
.L7:
	.align	2
.L6:
	.word	1073809420
	.size	Set_Alarm_actuator, .-Set_Alarm_actuator
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
	mov	r0, #0
	bl	Set_Alarm_actuator
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
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
	mov	r0, #1
	bl	Set_Alarm_actuator
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
	.size	StopAlarm, .-StopAlarm
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
