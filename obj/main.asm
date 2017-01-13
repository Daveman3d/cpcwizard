;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.5 #9498 (CYGWIN)
;--------------------------------------------------------
	.module main
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _fase_jefe
	.globl _fase_1
	.globl _main
	.globl _pantalla_start
	.globl _init
	.globl _cpct_getScreenPtr
	.globl _cpct_setPALColour
	.globl _cpct_setPalette
	.globl _cpct_fw2hw
	.globl _cpct_waitVSYNC
	.globl _cpct_setVideoMode
	.globl _cpct_drawSolidBox
	.globl _cpct_drawSpriteMasked
	.globl _cpct_isKeyPressed
	.globl _cpct_scanKeyboard_f
	.globl _cpct_disableFirmware
	.globl _pos_player
	.globl _subiendo
	.globl _player_salto
	.globl _g_palette
	.globl _g_tile_block
	.globl _g_tile_mago_simple_iz
	.globl _g_tile_mago_simple
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_player_salto::
	.ds 1
_subiendo::
	.ds 1
_pos_player::
	.ds 1
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;src/main.c:87: void init()
;	---------------------------------
; Function init
; ---------------------------------
_init::
;src/main.c:93: cpct_disableFirmware();
	call	_cpct_disableFirmware
;src/main.c:95: cpct_setVideoMode(1);
	ld	l,#0x01
	call	_cpct_setVideoMode
;src/main.c:97: cpct_fw2hw     (g_palette, 4); // Convert our palette from firmware to hardware colours 
	ld	hl,#0x0004
	push	hl
	ld	hl,#_g_palette
	push	hl
	call	_cpct_fw2hw
;src/main.c:98: cpct_setPalette(g_palette, 4); // Set up the hardware palette using hardware colours   
	ld	hl,#0x0004
	push	hl
	ld	hl,#_g_palette
	push	hl
	call	_cpct_setPalette
;src/main.c:99: cpct_setBorder(0);
	ld	hl,#0x0010
	push	hl
	call	_cpct_setPALColour
	ret
_g_tile_mago_simple:
	.db #0x88	; 136
	.db #0x07	; 7
	.db #0x77	; 119	'w'
	.db #0x08	; 8
	.db #0xFF	; 255
	.db #0x00	; 0
	.db #0x88	; 136
	.db #0x52	; 82	'R'
	.db #0x00	; 0
	.db #0x78	; 120	'x'
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x88	; 136
	.db #0x61	; 97	'a'
	.db #0x00	; 0
	.db #0xA5	; 165
	.db #0x11	; 17
	.db #0x68	; 104	'h'
	.db #0x88	; 136
	.db #0x52	; 82	'R'
	.db #0x00	; 0
	.db #0x5A	; 90	'Z'
	.db #0x33	; 51	'3'
	.db #0xC0	; 192
	.db #0x88	; 136
	.db #0x43	; 67	'C'
	.db #0x00	; 0
	.db #0x79	; 121	'y'
	.db #0x33	; 51	'3'
	.db #0xC8	; 200
	.db #0xCC	; 204
	.db #0x21	; 33
	.db #0x00	; 0
	.db #0xF6	; 246
	.db #0x11	; 17
	.db #0xEC	; 236
	.db #0x88	; 136
	.db #0x70	; 112	'p'
	.db #0x00	; 0
	.db #0xF6	; 246
	.db #0x11	; 17
	.db #0xEC	; 236
	.db #0x22	; 34
	.db #0xD0	; 208
	.db #0x00	; 0
	.db #0xFF	; 255
	.db #0x33	; 51	'3'
	.db #0xC0	; 192
	.db #0xEE	; 238
	.db #0x10	; 16
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x11	; 17
	.db #0xE0	; 224
	.db #0xEE	; 238
	.db #0x10	; 16
	.db #0x00	; 0
	.db #0x0F	; 15
	.db #0x11	; 17
	.db #0x2C	; 44
	.db #0xCC	; 204
	.db #0x21	; 33
	.db #0x00	; 0
	.db #0xA5	; 165
	.db #0x00	; 0
	.db #0xF2	; 242
	.db #0xCC	; 204
	.db #0x30	; 48	'0'
	.db #0x00	; 0
	.db #0x5A	; 90	'Z'
	.db #0x11	; 17
	.db #0xEC	; 236
	.db #0xCC	; 204
	.db #0x21	; 33
	.db #0x00	; 0
	.db #0xF3	; 243
	.db #0x11	; 17
	.db #0xE0	; 224
	.db #0x88	; 136
	.db #0x52	; 82	'R'
	.db #0x00	; 0
	.db #0x96	; 150
	.db #0x11	; 17
	.db #0x68	; 104	'h'
	.db #0x88	; 136
	.db #0x70	; 112	'p'
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0xCC	; 204
	.db #0x30	; 48	'0'
	.db #0x33	; 51	'3'
	.db #0xC0	; 192
	.db #0x00	; 0
	.db #0xF0	; 240
_g_tile_mago_simple_iz:
	.db #0xFF	; 255
	.db #0x00	; 0
	.db #0xEE	; 238
	.db #0x10	; 16
	.db #0x11	; 17
	.db #0xE0	; 224
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xE1	; 225
	.db #0x11	; 17
	.db #0xA4	; 164
	.db #0x88	; 136
	.db #0x61	; 97	'a'
	.db #0x00	; 0
	.db #0x5A	; 90	'Z'
	.db #0x11	; 17
	.db #0x68	; 104	'h'
	.db #0xCC	; 204
	.db #0x30	; 48	'0'
	.db #0x00	; 0
	.db #0xA5	; 165
	.db #0x11	; 17
	.db #0xA4	; 164
	.db #0xCC	; 204
	.db #0x21	; 33
	.db #0x00	; 0
	.db #0x69	; 105	'i'
	.db #0x11	; 17
	.db #0x2C	; 44
	.db #0x88	; 136
	.db #0x43	; 67	'C'
	.db #0x00	; 0
	.db #0x96	; 150
	.db #0x33	; 51	'3'
	.db #0x48	; 72	'H'
	.db #0x88	; 136
	.db #0x43	; 67	'C'
	.db #0x00	; 0
	.db #0x96	; 150
	.db #0x11	; 17
	.db #0xE0	; 224
	.db #0xCC	; 204
	.db #0x30	; 48	'0'
	.db #0x00	; 0
	.db #0x0F	; 15
	.db #0x44	; 68	'D'
	.db #0xB0	; 176
	.db #0x88	; 136
	.db #0x70	; 112	'p'
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x77	; 119	'w'
	.db #0x80	; 128
	.db #0x88	; 136
	.db #0x43	; 67	'C'
	.db #0x00	; 0
	.db #0x0F	; 15
	.db #0x77	; 119	'w'
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0x5A	; 90	'Z'
	.db #0x33	; 51	'3'
	.db #0x48	; 72	'H'
	.db #0x88	; 136
	.db #0x70	; 112	'p'
	.db #0x00	; 0
	.db #0xA5	; 165
	.db #0x33	; 51	'3'
	.db #0xC0	; 192
	.db #0x88	; 136
	.db #0x70	; 112	'p'
	.db #0x00	; 0
	.db #0xB4	; 180
	.db #0x33	; 51	'3'
	.db #0x48	; 72	'H'
	.db #0x88	; 136
	.db #0x61	; 97	'a'
	.db #0x00	; 0
	.db #0x96	; 150
	.db #0x11	; 17
	.db #0xA4	; 164
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x11	; 17
	.db #0xE0	; 224
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0xCC	; 204
	.db #0x30	; 48	'0'
	.db #0x33	; 51	'3'
	.db #0xC0	; 192
_g_tile_block:
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
	.db #0x0F	; 15
_g_palette:
	.db #0x0A	; 10
	.db #0x02	; 2
	.db #0x17	; 23
	.db #0x1A	; 26
;src/main.c:104: void pantalla_start()
;	---------------------------------
; Function pantalla_start
; ---------------------------------
_pantalla_start::
;src/main.c:111: }
	ret
;src/main.c:115: void main(void) {
;	---------------------------------
; Function main
; ---------------------------------
_main::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
;src/main.c:116: Tplayer posicionp={0,100};
	ld	hl,#0x0000
	add	hl,sp
	ld	(hl),#0x00
	ld	hl,#0x0000
	add	hl,sp
	ld	-2 (ix),l
	ld	-1 (ix),h
	ex	de,hl
	inc	de
	ld	a,#0x64
	ld	(de),a
;src/main.c:119: init();
	push	de
	call	_init
	pop	de
;src/main.c:125: while(1) {
00126$:
;src/main.c:126: cpct_waitVSYNC ();//esperamos a que haya recorrido la pantalla
	push	de
	call	_cpct_waitVSYNC
	pop	de
;src/main.c:127: pvideomem = cpct_getScreenPtr(VMEM, posicionp.x, posicionp.y);
	ld	a,(de)
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	b,(hl)
	push	de
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	hl,#0xC000
	push	hl
	call	_cpct_getScreenPtr
	ld	c,l
	ld	b,h
	ld	hl,#0x1003
	push	hl
	xor	a, a
	push	af
	inc	sp
	push	bc
	call	_cpct_drawSolidBox
	pop	af
	pop	af
	inc	sp
	call	_cpct_scanKeyboard_f
	ld	hl,#0x0200
	call	_cpct_isKeyPressed
	pop	de
	ld	a,l
	or	a, a
	jr	Z,00105$
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	c,(hl)
	ld	a,c
	sub	a, #0x4D
	jr	NC,00105$
	inc	c
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	(hl),c
	ld	hl,#_pos_player + 0
	ld	(hl), #0x00
	jr	00106$
00105$:
;src/main.c:153: else if (cpct_isKeyPressed(Key_CursorLeft)  && posicionp.x > 0              ) {--posicionp.x; pos_player=1;}
	push	de
	ld	hl,#0x0101
	call	_cpct_isKeyPressed
	pop	de
	ld	a,l
	or	a, a
	jr	Z,00106$
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	c,(hl)
	ld	a,c
	or	a, a
	jr	Z,00106$
	dec	c
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	(hl),c
	ld	hl,#_pos_player + 0
	ld	(hl), #0x01
00106$:
;src/main.c:157: if      (cpct_isKeyPressed(Key_CursorUp)    && posicionp.y > 0  && player_salto==0            ) {player_salto=1;subiendo=1;}
	push	de
	ld	hl,#0x0100
	call	_cpct_isKeyPressed
	ld	b,l
	pop	de
;src/main.c:127: pvideomem = cpct_getScreenPtr(VMEM, posicionp.x, posicionp.y);
	ld	a,(de)
	ld	c,a
;src/main.c:157: if      (cpct_isKeyPressed(Key_CursorUp)    && posicionp.y > 0  && player_salto==0            ) {player_salto=1;subiendo=1;}
	ld	a,b
	or	a, a
	jr	Z,00109$
	ld	a,c
	or	a, a
	jr	Z,00109$
	ld	a,(#_player_salto + 0)
	or	a, a
	jr	NZ,00109$
	ld	hl,#_player_salto + 0
	ld	(hl), #0x01
	ld	hl,#_subiendo + 0
	ld	(hl), #0x01
00109$:
;src/main.c:160: if(player_salto>0)//est� saltando , cuando player_salto==
	ld	a,(#_player_salto + 0)
	or	a, a
	jr	Z,00121$
;src/main.c:162: if((player_salto<20) && (subiendo==1))
	ld	a,(#_player_salto + 0)
	sub	a, #0x14
	jr	NC,00113$
	ld	a,(#_subiendo + 0)
	dec	a
	jr	NZ,00113$
;src/main.c:163: {--posicionp.y;
	dec	c
	ld	a,c
	ld	(de),a
;src/main.c:164: player_salto++;
	ld	hl, #_player_salto+0
	inc	(hl)
00113$:
;src/main.c:166: if(player_salto>=20)
	ld	a,(#_player_salto + 0)
	sub	a, #0x14
	jr	C,00116$
;src/main.c:168: subiendo=0;
	ld	hl,#_subiendo + 0
	ld	(hl), #0x00
00116$:
;src/main.c:170: if((player_salto>0) && (subiendo==0))
	ld	a,(#_player_salto + 0)
	or	a, a
	jr	Z,00121$
	ld	a,(#_subiendo + 0)
	or	a, a
	jr	NZ,00121$
;src/main.c:171: {++posicionp.y;
	ld	a,(de)
	inc	a
	ld	(de),a
;src/main.c:172: player_salto--;
	ld	hl, #_player_salto+0
	dec	(hl)
00121$:
;src/main.c:179: pvideomem = cpct_getScreenPtr(VMEM, posicionp.x, posicionp.y);
	ld	a,(de)
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	b,(hl)
	push	de
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	hl,#0xC000
	push	hl
	call	_cpct_getScreenPtr
	ld	c,l
	ld	b,h
	pop	de
;src/main.c:135: cpct_drawSolidBox(pvideomem,0, SP_W, SP_H);//dibujamos un recuadro negro para limpiar la pantalla
;src/main.c:185: if(pos_player==0)
	ld	a,(#_pos_player + 0)
	or	a, a
	jr	NZ,00123$
;src/main.c:187: cpct_drawSpriteMasked(g_tile_mago_simple, pvideomem, SP_W, SP_H);
	push	de
	ld	hl,#0x1003
	push	hl
	push	bc
	ld	hl,#_g_tile_mago_simple
	push	hl
	call	_cpct_drawSpriteMasked
	pop	de
	jp	00126$
00123$:
;src/main.c:191: cpct_drawSpriteMasked(g_tile_mago_simple_iz, pvideomem, SP_W, SP_H);
	push	de
	ld	hl,#0x1003
	push	hl
	push	bc
	ld	hl,#_g_tile_mago_simple_iz
	push	hl
	call	_cpct_drawSpriteMasked
	pop	de
	jp	00126$
;src/main.c:199: void fase_1()
;	---------------------------------
; Function fase_1
; ---------------------------------
_fase_1::
;src/main.c:202: }
	ret
;src/main.c:204: void fase_jefe()
;	---------------------------------
; Function fase_jefe
; ---------------------------------
_fase_jefe::
;src/main.c:207: }
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__player_salto:
	.db #0x00	; 0
__xinit__subiendo:
	.db #0x00	; 0
__xinit__pos_player:
	.db #0x00	; 0
	.area _CABS (ABS)
