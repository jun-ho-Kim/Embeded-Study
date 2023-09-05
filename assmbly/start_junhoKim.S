// 어셈블리어코드 - LED 0~7번까지 켜지는 과정에서 Switch S0번을 누르면 부트로드 되는 어셈블리 코드
ENTRY(kcci_led_test)
	ldr r0,=0xFE200000
	ldr r1,=0x09240000
	str r1,[r0,#0x00]

	ldr r1,=0x00012249
	str r1,[r0,#0x04]

	ldr r1,=0x00000040
@	str r1,[r0,#0x1C]

	mov r2, #8
ledloop:
	str r1, [r0,#0x1C]
	ldr r3,=0x400000
delay:
	ldr r4, = 0x00010000
	ldr r5, [r0, #0x34]

	ands r5,r4,r5
	bne final
	subs r3,r3, #1
	bne delay
	str r1,[r0,#0x28]
	mov r1, r1, LSL #1
	subs r2, r2, #1
	bne ledloop
final:	
	mov pc, lr
ENDPROC(kcci_led_test)
