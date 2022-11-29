
App.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0008 	ldr	r0, [pc, #8]	; 18 <main+0x18>
   c:	ebfffffe 	bl	0 <UART_Send_String>
  10:	e1a00000 	nop			; (mov r0, r0)
  14:	e8bd8800 	pop	{fp, pc}
  18:	00000000 	andeq	r0, r0, r0

Disassembly of section .rodata:

00000000 <buffer>:
   0:	7261656c 	rsbvc	r6, r1, #108, 10	; 0x1b000000
   4:	6e692d6e 	cdpvs	13, 6, cr2, cr9, cr14, {3}
   8:	7065642d 	rsbvc	r6, r5, sp, lsr #8
   c:	4f3a6874 	svcmi	0x003a6874
  10:	0072616d 	rsbseq	r6, r2, sp, ror #2
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	0000006e 	andeq	r0, r0, lr, rrx
   4:	00000004 	andeq	r0, r0, r4
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	00000014 	andeq	r0, r0, r4, lsl r0
  10:	00000e0c 	andeq	r0, r0, ip, lsl #28
  14:	00007100 	andeq	r7, r0, r0, lsl #2
  18:	00000000 	andeq	r0, r0, r0
  1c:	00001c00 	andeq	r1, r0, r0, lsl #24
  20:	00000000 	andeq	r0, r0, r0
  24:	00480200 	subeq	r0, r8, r0, lsl #4
  28:	00350000 	eorseq	r0, r5, r0
  2c:	3a030000 	bcc	c0034 <main+0xc0034>
  30:	63000000 	movwvs	r0, #0
  34:	00250400 	eoreq	r0, r5, r0, lsl #8
  38:	04050000 	streq	r0, [r5], #-0
  3c:	0000d007 	andeq	sp, r0, r7
  40:	08010500 	stmdaeq	r1, {r8, sl}
  44:	00000000 	andeq	r0, r0, r0
  48:	00004104 	andeq	r4, r0, r4, lsl #2
  4c:	00c90600 	sbceq	r0, r9, r0, lsl #12
  50:	03010000 	movweq	r0, #4096	; 0x1000
  54:	00003515 	andeq	r3, r0, r5, lsl r5
  58:	00030500 	andeq	r0, r3, r0, lsl #10
  5c:	07000000 	streq	r0, [r0, -r0]
  60:	000000dd 	ldrdeq	r0, [r0], -sp
  64:	00060401 	andeq	r0, r6, r1, lsl #8
  68:	1c000000 	stcne	0, cr0, [r0], {-0}
  6c:	01000000 	mrseq	r0, (UNDEF: 0)
  70:	Address 0x00000070 is out of bounds.


Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0xfffffeff
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10061201 	andne	r1, r6, r1, lsl #4
  10:	02000017 	andeq	r0, r0, #23
  14:	13490101 	movtne	r0, #37121	; 0x9101
  18:	00001301 	andeq	r1, r0, r1, lsl #6
  1c:	49002103 	stmdbmi	r0, {r0, r1, r8, sp}
  20:	000b2f13 	andeq	r2, fp, r3, lsl pc
  24:	00260400 	eoreq	r0, r6, r0, lsl #8
  28:	00001349 	andeq	r1, r0, r9, asr #6
  2c:	0b002405 	bleq	9048 <main+0x9048>
  30:	030b3e0b 	movweq	r3, #48651	; 0xbe0b
  34:	0600000e 	streq	r0, [r0], -lr
  38:	0e030034 	mcreq	0, 0, r0, cr3, cr4, {1}
  3c:	0b3b0b3a 	bleq	ec2d2c <main+0xec2d2c>
  40:	13490b39 	movtne	r0, #39737	; 0x9b39
  44:	1802193f 	stmdane	r2, {r0, r1, r2, r3, r4, r5, r8, fp, ip}
  48:	2e070000 	cdpcs	0, 0, cr0, cr7, cr0, {0}
  4c:	03193f00 	tsteq	r9, #0, 30
  50:	3b0b3a0e 	blcc	2ce890 <main+0x2ce890>
  54:	270b390b 	strcs	r3, [fp, -fp, lsl #18]
  58:	12011119 	andne	r1, r1, #1073741830	; 0x40000006
  5c:	96184006 	ldrls	r4, [r8], -r6
  60:	00001942 	andeq	r1, r0, r2, asr #18
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	0000001c 	andeq	r0, r0, ip, lsl r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000037 	andeq	r0, r0, r7, lsr r0
   4:	001c0003 	andseq	r0, ip, r3
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	2e707041 	cdpcs	0, 7, cr7, cr0, cr1, {2}
  20:	00000063 	andeq	r0, r0, r3, rrx
  24:	01050000 	mrseq	r0, (UNDEF: 5)
  28:	00020500 	andeq	r0, r2, r0, lsl #10
  2c:	16000000 	strne	r0, [r0], -r0
  30:	054b0205 	strbeq	r0, [fp, #-517]	; 0xfffffdfb
  34:	06024b01 	streq	r4, [r2], -r1, lsl #22
  38:	Address 0x00000038 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
   4:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
   8:	61686320 	cmnvs	r8, r0, lsr #6
   c:	70410072 	subvc	r0, r1, r2, ror r0
  10:	00632e70 	rsbeq	r2, r3, r0, ror lr
  14:	20554e47 	subscs	r4, r5, r7, asr #28
  18:	20373143 	eorscs	r3, r7, r3, asr #2
  1c:	332e3031 			; <UNDEFINED> instruction: 0x332e3031
  20:	3220312e 	eorcc	r3, r0, #-2147483637	; 0x8000000b
  24:	30313230 	eorscc	r3, r1, r0, lsr r2
  28:	20343238 	eorscs	r3, r4, r8, lsr r2
  2c:	6c657228 	sfmvs	f7, 2, [r5], #-160	; 0xffffff60
  30:	65736165 	ldrbvs	r6, [r3, #-357]!	; 0xfffffe9b
  34:	6d2d2029 	stcvs	0, cr2, [sp, #-164]!	; 0xffffff5c
  38:	3d757063 	ldclcc	0, cr7, [r5, #-396]!	; 0xfffffe74
  3c:	396d7261 	stmdbcc	sp!, {r0, r5, r6, r9, ip, sp, lr}^
  40:	6a653632 	bvs	194d910 <main+0x194d910>
  44:	2d20732d 	stccs	3, cr7, [r0, #-180]!	; 0xffffff4c
  48:	6f6c666d 	svcvs	0x006c666d
  4c:	612d7461 			; <UNDEFINED> instruction: 0x612d7461
  50:	733d6962 	teqvc	sp, #1605632	; 0x188000
  54:	2074666f 	rsbscs	r6, r4, pc, ror #12
  58:	72616d2d 	rsbvc	r6, r1, #2880	; 0xb40
  5c:	6d2d206d 	stcvs	0, cr2, [sp, #-436]!	; 0xfffffe4c
  60:	68637261 	stmdavs	r3!, {r0, r5, r6, r9, ip, sp, lr}^
  64:	6d72613d 	ldfvse	f6, [r2, #-244]!	; 0xffffff0c
  68:	65743576 	ldrbvs	r3, [r4, #-1398]!	; 0xfffffa8a
  6c:	672d206a 	strvs	r2, [sp, -sl, rrx]!
  70:	5c3a4400 	cfldrspl	mvf4, [sl], #-0
  74:	68636554 	stmdavs	r3!, {r2, r4, r6, r8, sl, sp, lr}^
  78:	452e335c 	strmi	r3, [lr, #-860]!	; 0xfffffca4
  7c:	6465626d 	strbtvs	r6, [r5], #-621	; 0xfffffd93
  80:	5c646564 	cfstr64pl	mvdx6, [r4], #-400	; 0xfffffe70
  84:	7261656c 	rsbvc	r6, r1, #108, 10	; 0x1b000000
  88:	6e692d6e 	cdpvs	13, 6, cr2, cr9, cr14, {3}
  8c:	7065642d 	rsbvc	r6, r5, sp, lsr #8
  90:	6c5c6874 	mrrcvs	8, 7, r6, ip, cr4
  94:	6e726165 	rpwvssz	f6, f2, f5
  98:	2d6e692d 			; <UNDEFINED> instruction: 0x2d6e692d
  9c:	74706564 	ldrbtvc	r6, [r0], #-1380	; 0xfffffa9c
  a0:	6d452d68 	stclvs	13, cr2, [r5, #-416]	; 0xfffffe60
  a4:	64646562 	strbtvs	r6, [r4], #-1378	; 0xfffffa9e
  a8:	442d6465 	strtmi	r6, [sp], #-1125	; 0xfffffb9b
  ac:	6f6c7069 	svcvs	0x006c7069
  b0:	555c616d 	ldrbpl	r6, [ip, #-365]	; 0xfffffe93
  b4:	3374696e 	cmncc	r4, #1802240	; 0x1b8000
  b8:	626d455f 	rsbvs	r4, sp, #398458880	; 0x17c00000
  bc:	65646465 	strbvs	r6, [r4, #-1125]!	; 0xfffffb9b
  c0:	5c435f64 	mcrrpl	15, 6, r5, r3, cr4
  c4:	3162614c 	cmncc	r2, ip, asr #2
  c8:	66756200 	ldrbtvs	r6, [r5], -r0, lsl #4
  cc:	00726566 	rsbseq	r6, r2, r6, ror #10
  d0:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
  d4:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
  d8:	746e6920 	strbtvc	r6, [lr], #-2336	; 0xfffff6e0
  dc:	69616d00 	stmdbvs	r1!, {r8, sl, fp, sp, lr}^
  e0:	Address 0x000000e0 is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	4120554e 			; <UNDEFINED> instruction: 0x4120554e
   c:	45206d72 	strmi	r6, [r0, #-3442]!	; 0xfffff28e
  10:	6465626d 	strbtvs	r6, [r5], #-621	; 0xfffffd93
  14:	20646564 	rsbcs	r6, r4, r4, ror #10
  18:	6c6f6f54 	stclvs	15, cr6, [pc], #-336	; fffffed0 <main+0xfffffed0>
  1c:	69616863 	stmdbvs	r1!, {r0, r1, r5, r6, fp, sp, lr}^
  20:	3031206e 	eorscc	r2, r1, lr, rrx
  24:	322d332e 	eorcc	r3, sp, #-1207959552	; 0xb8000000
  28:	2e313230 	mrccs	2, 1, r3, cr1, cr0, {1}
  2c:	20293031 	eorcs	r3, r9, r1, lsr r0
  30:	332e3031 			; <UNDEFINED> instruction: 0x332e3031
  34:	3220312e 	eorcc	r3, r0, #-2147483637	; 0x8000000b
  38:	30313230 	eorscc	r3, r1, r0, lsr r2
  3c:	20343238 	eorscs	r3, r4, r8, lsr r2
  40:	6c657228 	sfmvs	f7, 2, [r5], #-160	; 0xffffff60
  44:	65736165 	ldrbvs	r6, [r3, #-357]!	; 0xfffffe9b
  48:	Address 0x00000048 is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	0000001c 	andeq	r0, r0, ip, lsl r0
  20:	8b080e42 	blhi	203930 <main+0x203930>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	00040b0c 	andeq	r0, r4, ip, lsl #22

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002b41 	andeq	r2, r0, r1, asr #22
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000021 	andeq	r0, r0, r1, lsr #32
  10:	45543505 	ldrbmi	r3, [r4, #-1285]	; 0xfffffafb
  14:	0506004a 	streq	r0, [r6, #-74]	; 0xffffffb6
  18:	01090108 	tsteq	r9, r8, lsl #2
  1c:	01140412 	tsteq	r4, r2, lsl r4
  20:	03170115 	tsteq	r7, #1073741829	; 0x40000005
  24:	01190118 	tsteq	r9, r8, lsl r1
  28:	061e011a 			; <UNDEFINED> instruction: 0x061e011a
