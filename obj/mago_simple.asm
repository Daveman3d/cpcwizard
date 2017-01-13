;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.5 #9498 (CYGWIN)
;--------------------------------------------------------
	.module mago_simple
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
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
	.area _CODE
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
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xE1	; 225
	.db #0x00	; 0
	.db #0xB4	; 180
	.db #0x00	; 0
	.db #0xE1	; 225
	.db #0x00	; 0
	.db #0x5A	; 90	'Z'
	.db #0x00	; 0
	.db #0x78	; 120	'x'
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xA5	; 165
	.db #0x00	; 0
	.db #0xB4	; 180
	.db #0x00	; 0
	.db #0xE1	; 225
	.db #0x00	; 0
	.db #0x69	; 105	'i'
	.db #0x00	; 0
	.db #0x3C	; 60
	.db #0x00	; 0
	.db #0xC3	; 195
	.db #0x00	; 0
	.db #0x96	; 150
	.db #0x00	; 0
	.db #0x78	; 120	'x'
	.db #0x00	; 0
	.db #0xC3	; 195
	.db #0x00	; 0
	.db #0x96	; 150
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0x0F	; 15
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xC3	; 195
	.db #0x00	; 0
	.db #0x0F	; 15
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0x5A	; 90	'Z'
	.db #0x00	; 0
	.db #0x78	; 120	'x'
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xA5	; 165
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xB4	; 180
	.db #0x00	; 0
	.db #0x78	; 120	'x'
	.db #0x00	; 0
	.db #0xE1	; 225
	.db #0x00	; 0
	.db #0x96	; 150
	.db #0x00	; 0
	.db #0xB4	; 180
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
	.db #0x00	; 0
	.db #0xF0	; 240
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
	.area _INITIALIZER
	.area _CABS (ABS)
