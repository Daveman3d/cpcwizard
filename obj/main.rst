                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.5.5 #9498 (CYGWIN)
                              4 ;--------------------------------------------------------
                              5 	.module main
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _fase_jefe
                             12 	.globl _fase_1
                             13 	.globl _main
                             14 	.globl _pantalla_start
                             15 	.globl _init
                             16 	.globl _cpct_getScreenPtr
                             17 	.globl _cpct_setPALColour
                             18 	.globl _cpct_setPalette
                             19 	.globl _cpct_fw2hw
                             20 	.globl _cpct_waitVSYNC
                             21 	.globl _cpct_setVideoMode
                             22 	.globl _cpct_drawSolidBox
                             23 	.globl _cpct_drawSpriteMasked
                             24 	.globl _cpct_isKeyPressed
                             25 	.globl _cpct_scanKeyboard_f
                             26 	.globl _cpct_disableFirmware
                             27 	.globl _pos_player
                             28 	.globl _subiendo
                             29 	.globl _player_salto
                             30 	.globl _g_palette
                             31 	.globl _g_tile_block
                             32 	.globl _g_tile_mago_simple_iz
                             33 	.globl _g_tile_mago_simple
                             34 ;--------------------------------------------------------
                             35 ; special function registers
                             36 ;--------------------------------------------------------
                             37 ;--------------------------------------------------------
                             38 ; ram data
                             39 ;--------------------------------------------------------
                             40 	.area _DATA
                             41 ;--------------------------------------------------------
                             42 ; ram data
                             43 ;--------------------------------------------------------
                             44 	.area _INITIALIZED
   4521                      45 _player_salto::
   4521                      46 	.ds 1
   4522                      47 _subiendo::
   4522                      48 	.ds 1
   4523                      49 _pos_player::
   4523                      50 	.ds 1
                             51 ;--------------------------------------------------------
                             52 ; absolute external ram data
                             53 ;--------------------------------------------------------
                             54 	.area _DABS (ABS)
                             55 ;--------------------------------------------------------
                             56 ; global & static initialisations
                             57 ;--------------------------------------------------------
                             58 	.area _HOME
                             59 	.area _GSINIT
                             60 	.area _GSFINAL
                             61 	.area _GSINIT
                             62 ;--------------------------------------------------------
                             63 ; Home
                             64 ;--------------------------------------------------------
                             65 	.area _HOME
                             66 	.area _HOME
                             67 ;--------------------------------------------------------
                             68 ; code
                             69 ;--------------------------------------------------------
                             70 	.area _CODE
                             71 ;src/main.c:87: void init()
                             72 ;	---------------------------------
                             73 ; Function init
                             74 ; ---------------------------------
   40E0                      75 _init::
                             76 ;src/main.c:93: cpct_disableFirmware();
   40E0 CD 38 44      [17]   77 	call	_cpct_disableFirmware
                             78 ;src/main.c:95: cpct_setVideoMode(1);
   40E3 2E 01         [ 7]   79 	ld	l,#0x01
   40E5 CD 2A 44      [17]   80 	call	_cpct_setVideoMode
                             81 ;src/main.c:97: cpct_fw2hw     (g_palette, 4); // Convert our palette from firmware to hardware colours 
   40E8 21 04 00      [10]   82 	ld	hl,#0x0004
   40EB E5            [11]   83 	push	hl
   40EC 21 E6 41      [10]   84 	ld	hl,#_g_palette
   40EF E5            [11]   85 	push	hl
   40F0 CD BB 43      [17]   86 	call	_cpct_fw2hw
                             87 ;src/main.c:98: cpct_setPalette(g_palette, 4); // Set up the hardware palette using hardware colours   
   40F3 21 04 00      [10]   88 	ld	hl,#0x0004
   40F6 E5            [11]   89 	push	hl
   40F7 21 E6 41      [10]   90 	ld	hl,#_g_palette
   40FA E5            [11]   91 	push	hl
   40FB CD 22 43      [17]   92 	call	_cpct_setPalette
                             93 ;src/main.c:99: cpct_setBorder(0);
   40FE 21 10 00      [10]   94 	ld	hl,#0x0010
   4101 E5            [11]   95 	push	hl
   4102 CD AF 43      [17]   96 	call	_cpct_setPALColour
   4105 C9            [10]   97 	ret
   4106                      98 _g_tile_mago_simple:
   4106 88                   99 	.db #0x88	; 136
   4107 07                  100 	.db #0x07	; 7
   4108 77                  101 	.db #0x77	; 119	'w'
   4109 08                  102 	.db #0x08	; 8
   410A FF                  103 	.db #0xFF	; 255
   410B 00                  104 	.db #0x00	; 0
   410C 88                  105 	.db #0x88	; 136
   410D 52                  106 	.db #0x52	; 82	'R'
   410E 00                  107 	.db #0x00	; 0
   410F 78                  108 	.db #0x78	; 120	'x'
   4110 00                  109 	.db #0x00	; 0
   4111 F0                  110 	.db #0xF0	; 240
   4112 88                  111 	.db #0x88	; 136
   4113 61                  112 	.db #0x61	; 97	'a'
   4114 00                  113 	.db #0x00	; 0
   4115 A5                  114 	.db #0xA5	; 165
   4116 11                  115 	.db #0x11	; 17
   4117 68                  116 	.db #0x68	; 104	'h'
   4118 88                  117 	.db #0x88	; 136
   4119 52                  118 	.db #0x52	; 82	'R'
   411A 00                  119 	.db #0x00	; 0
   411B 5A                  120 	.db #0x5A	; 90	'Z'
   411C 33                  121 	.db #0x33	; 51	'3'
   411D C0                  122 	.db #0xC0	; 192
   411E 88                  123 	.db #0x88	; 136
   411F 43                  124 	.db #0x43	; 67	'C'
   4120 00                  125 	.db #0x00	; 0
   4121 79                  126 	.db #0x79	; 121	'y'
   4122 33                  127 	.db #0x33	; 51	'3'
   4123 C8                  128 	.db #0xC8	; 200
   4124 CC                  129 	.db #0xCC	; 204
   4125 21                  130 	.db #0x21	; 33
   4126 00                  131 	.db #0x00	; 0
   4127 F6                  132 	.db #0xF6	; 246
   4128 11                  133 	.db #0x11	; 17
   4129 EC                  134 	.db #0xEC	; 236
   412A 88                  135 	.db #0x88	; 136
   412B 70                  136 	.db #0x70	; 112	'p'
   412C 00                  137 	.db #0x00	; 0
   412D F6                  138 	.db #0xF6	; 246
   412E 11                  139 	.db #0x11	; 17
   412F EC                  140 	.db #0xEC	; 236
   4130 22                  141 	.db #0x22	; 34
   4131 D0                  142 	.db #0xD0	; 208
   4132 00                  143 	.db #0x00	; 0
   4133 FF                  144 	.db #0xFF	; 255
   4134 33                  145 	.db #0x33	; 51	'3'
   4135 C0                  146 	.db #0xC0	; 192
   4136 EE                  147 	.db #0xEE	; 238
   4137 10                  148 	.db #0x10	; 16
   4138 00                  149 	.db #0x00	; 0
   4139 F0                  150 	.db #0xF0	; 240
   413A 11                  151 	.db #0x11	; 17
   413B E0                  152 	.db #0xE0	; 224
   413C EE                  153 	.db #0xEE	; 238
   413D 10                  154 	.db #0x10	; 16
   413E 00                  155 	.db #0x00	; 0
   413F 0F                  156 	.db #0x0F	; 15
   4140 11                  157 	.db #0x11	; 17
   4141 2C                  158 	.db #0x2C	; 44
   4142 CC                  159 	.db #0xCC	; 204
   4143 21                  160 	.db #0x21	; 33
   4144 00                  161 	.db #0x00	; 0
   4145 A5                  162 	.db #0xA5	; 165
   4146 00                  163 	.db #0x00	; 0
   4147 F2                  164 	.db #0xF2	; 242
   4148 CC                  165 	.db #0xCC	; 204
   4149 30                  166 	.db #0x30	; 48	'0'
   414A 00                  167 	.db #0x00	; 0
   414B 5A                  168 	.db #0x5A	; 90	'Z'
   414C 11                  169 	.db #0x11	; 17
   414D EC                  170 	.db #0xEC	; 236
   414E CC                  171 	.db #0xCC	; 204
   414F 21                  172 	.db #0x21	; 33
   4150 00                  173 	.db #0x00	; 0
   4151 F3                  174 	.db #0xF3	; 243
   4152 11                  175 	.db #0x11	; 17
   4153 E0                  176 	.db #0xE0	; 224
   4154 88                  177 	.db #0x88	; 136
   4155 52                  178 	.db #0x52	; 82	'R'
   4156 00                  179 	.db #0x00	; 0
   4157 96                  180 	.db #0x96	; 150
   4158 11                  181 	.db #0x11	; 17
   4159 68                  182 	.db #0x68	; 104	'h'
   415A 88                  183 	.db #0x88	; 136
   415B 70                  184 	.db #0x70	; 112	'p'
   415C 00                  185 	.db #0x00	; 0
   415D F0                  186 	.db #0xF0	; 240
   415E 00                  187 	.db #0x00	; 0
   415F F0                  188 	.db #0xF0	; 240
   4160 CC                  189 	.db #0xCC	; 204
   4161 30                  190 	.db #0x30	; 48	'0'
   4162 33                  191 	.db #0x33	; 51	'3'
   4163 C0                  192 	.db #0xC0	; 192
   4164 00                  193 	.db #0x00	; 0
   4165 F0                  194 	.db #0xF0	; 240
   4166                     195 _g_tile_mago_simple_iz:
   4166 FF                  196 	.db #0xFF	; 255
   4167 00                  197 	.db #0x00	; 0
   4168 EE                  198 	.db #0xEE	; 238
   4169 10                  199 	.db #0x10	; 16
   416A 11                  200 	.db #0x11	; 17
   416B E0                  201 	.db #0xE0	; 224
   416C 00                  202 	.db #0x00	; 0
   416D F0                  203 	.db #0xF0	; 240
   416E 00                  204 	.db #0x00	; 0
   416F E1                  205 	.db #0xE1	; 225
   4170 11                  206 	.db #0x11	; 17
   4171 A4                  207 	.db #0xA4	; 164
   4172 88                  208 	.db #0x88	; 136
   4173 61                  209 	.db #0x61	; 97	'a'
   4174 00                  210 	.db #0x00	; 0
   4175 5A                  211 	.db #0x5A	; 90	'Z'
   4176 11                  212 	.db #0x11	; 17
   4177 68                  213 	.db #0x68	; 104	'h'
   4178 CC                  214 	.db #0xCC	; 204
   4179 30                  215 	.db #0x30	; 48	'0'
   417A 00                  216 	.db #0x00	; 0
   417B A5                  217 	.db #0xA5	; 165
   417C 11                  218 	.db #0x11	; 17
   417D A4                  219 	.db #0xA4	; 164
   417E CC                  220 	.db #0xCC	; 204
   417F 21                  221 	.db #0x21	; 33
   4180 00                  222 	.db #0x00	; 0
   4181 69                  223 	.db #0x69	; 105	'i'
   4182 11                  224 	.db #0x11	; 17
   4183 2C                  225 	.db #0x2C	; 44
   4184 88                  226 	.db #0x88	; 136
   4185 43                  227 	.db #0x43	; 67	'C'
   4186 00                  228 	.db #0x00	; 0
   4187 96                  229 	.db #0x96	; 150
   4188 33                  230 	.db #0x33	; 51	'3'
   4189 48                  231 	.db #0x48	; 72	'H'
   418A 88                  232 	.db #0x88	; 136
   418B 43                  233 	.db #0x43	; 67	'C'
   418C 00                  234 	.db #0x00	; 0
   418D 96                  235 	.db #0x96	; 150
   418E 11                  236 	.db #0x11	; 17
   418F E0                  237 	.db #0xE0	; 224
   4190 CC                  238 	.db #0xCC	; 204
   4191 30                  239 	.db #0x30	; 48	'0'
   4192 00                  240 	.db #0x00	; 0
   4193 0F                  241 	.db #0x0F	; 15
   4194 44                  242 	.db #0x44	; 68	'D'
   4195 B0                  243 	.db #0xB0	; 176
   4196 88                  244 	.db #0x88	; 136
   4197 70                  245 	.db #0x70	; 112	'p'
   4198 00                  246 	.db #0x00	; 0
   4199 F0                  247 	.db #0xF0	; 240
   419A 77                  248 	.db #0x77	; 119	'w'
   419B 80                  249 	.db #0x80	; 128
   419C 88                  250 	.db #0x88	; 136
   419D 43                  251 	.db #0x43	; 67	'C'
   419E 00                  252 	.db #0x00	; 0
   419F 0F                  253 	.db #0x0F	; 15
   41A0 77                  254 	.db #0x77	; 119	'w'
   41A1 80                  255 	.db #0x80	; 128
   41A2 00                  256 	.db #0x00	; 0
   41A3 F0                  257 	.db #0xF0	; 240
   41A4 00                  258 	.db #0x00	; 0
   41A5 5A                  259 	.db #0x5A	; 90	'Z'
   41A6 33                  260 	.db #0x33	; 51	'3'
   41A7 48                  261 	.db #0x48	; 72	'H'
   41A8 88                  262 	.db #0x88	; 136
   41A9 70                  263 	.db #0x70	; 112	'p'
   41AA 00                  264 	.db #0x00	; 0
   41AB A5                  265 	.db #0xA5	; 165
   41AC 33                  266 	.db #0x33	; 51	'3'
   41AD C0                  267 	.db #0xC0	; 192
   41AE 88                  268 	.db #0x88	; 136
   41AF 70                  269 	.db #0x70	; 112	'p'
   41B0 00                  270 	.db #0x00	; 0
   41B1 B4                  271 	.db #0xB4	; 180
   41B2 33                  272 	.db #0x33	; 51	'3'
   41B3 48                  273 	.db #0x48	; 72	'H'
   41B4 88                  274 	.db #0x88	; 136
   41B5 61                  275 	.db #0x61	; 97	'a'
   41B6 00                  276 	.db #0x00	; 0
   41B7 96                  277 	.db #0x96	; 150
   41B8 11                  278 	.db #0x11	; 17
   41B9 A4                  279 	.db #0xA4	; 164
   41BA 00                  280 	.db #0x00	; 0
   41BB F0                  281 	.db #0xF0	; 240
   41BC 00                  282 	.db #0x00	; 0
   41BD F0                  283 	.db #0xF0	; 240
   41BE 11                  284 	.db #0x11	; 17
   41BF E0                  285 	.db #0xE0	; 224
   41C0 00                  286 	.db #0x00	; 0
   41C1 F0                  287 	.db #0xF0	; 240
   41C2 CC                  288 	.db #0xCC	; 204
   41C3 30                  289 	.db #0x30	; 48	'0'
   41C4 33                  290 	.db #0x33	; 51	'3'
   41C5 C0                  291 	.db #0xC0	; 192
   41C6                     292 _g_tile_block:
   41C6 0F                  293 	.db #0x0F	; 15
   41C7 0F                  294 	.db #0x0F	; 15
   41C8 0F                  295 	.db #0x0F	; 15
   41C9 0F                  296 	.db #0x0F	; 15
   41CA 0F                  297 	.db #0x0F	; 15
   41CB 0F                  298 	.db #0x0F	; 15
   41CC 0F                  299 	.db #0x0F	; 15
   41CD 0F                  300 	.db #0x0F	; 15
   41CE 0F                  301 	.db #0x0F	; 15
   41CF 0F                  302 	.db #0x0F	; 15
   41D0 0F                  303 	.db #0x0F	; 15
   41D1 0F                  304 	.db #0x0F	; 15
   41D2 0F                  305 	.db #0x0F	; 15
   41D3 0F                  306 	.db #0x0F	; 15
   41D4 0F                  307 	.db #0x0F	; 15
   41D5 0F                  308 	.db #0x0F	; 15
   41D6 0F                  309 	.db #0x0F	; 15
   41D7 0F                  310 	.db #0x0F	; 15
   41D8 0F                  311 	.db #0x0F	; 15
   41D9 0F                  312 	.db #0x0F	; 15
   41DA 0F                  313 	.db #0x0F	; 15
   41DB 0F                  314 	.db #0x0F	; 15
   41DC 0F                  315 	.db #0x0F	; 15
   41DD 0F                  316 	.db #0x0F	; 15
   41DE 0F                  317 	.db #0x0F	; 15
   41DF 0F                  318 	.db #0x0F	; 15
   41E0 0F                  319 	.db #0x0F	; 15
   41E1 0F                  320 	.db #0x0F	; 15
   41E2 0F                  321 	.db #0x0F	; 15
   41E3 0F                  322 	.db #0x0F	; 15
   41E4 0F                  323 	.db #0x0F	; 15
   41E5 0F                  324 	.db #0x0F	; 15
   41E6                     325 _g_palette:
   41E6 0A                  326 	.db #0x0A	; 10
   41E7 02                  327 	.db #0x02	; 2
   41E8 17                  328 	.db #0x17	; 23
   41E9 1A                  329 	.db #0x1A	; 26
                            330 ;src/main.c:104: void pantalla_start()
                            331 ;	---------------------------------
                            332 ; Function pantalla_start
                            333 ; ---------------------------------
   41EA                     334 _pantalla_start::
                            335 ;src/main.c:111: }
   41EA C9            [10]  336 	ret
                            337 ;src/main.c:115: void main(void) {
                            338 ;	---------------------------------
                            339 ; Function main
                            340 ; ---------------------------------
   41EB                     341 _main::
   41EB DD E5         [15]  342 	push	ix
   41ED DD 21 00 00   [14]  343 	ld	ix,#0
   41F1 DD 39         [15]  344 	add	ix,sp
   41F3 F5            [11]  345 	push	af
   41F4 F5            [11]  346 	push	af
                            347 ;src/main.c:116: Tplayer posicionp={0,100};
   41F5 21 00 00      [10]  348 	ld	hl,#0x0000
   41F8 39            [11]  349 	add	hl,sp
   41F9 36 00         [10]  350 	ld	(hl),#0x00
   41FB 21 00 00      [10]  351 	ld	hl,#0x0000
   41FE 39            [11]  352 	add	hl,sp
   41FF DD 75 FE      [19]  353 	ld	-2 (ix),l
   4202 DD 74 FF      [19]  354 	ld	-1 (ix),h
   4205 EB            [ 4]  355 	ex	de,hl
   4206 13            [ 6]  356 	inc	de
   4207 3E 64         [ 7]  357 	ld	a,#0x64
   4209 12            [ 7]  358 	ld	(de),a
                            359 ;src/main.c:119: init();
   420A D5            [11]  360 	push	de
   420B CD E0 40      [17]  361 	call	_init
   420E D1            [10]  362 	pop	de
                            363 ;src/main.c:125: while(1) {
   420F                     364 00126$:
                            365 ;src/main.c:126: cpct_waitVSYNC ();//esperamos a que haya recorrido la pantalla
   420F D5            [11]  366 	push	de
   4210 CD 22 44      [17]  367 	call	_cpct_waitVSYNC
   4213 D1            [10]  368 	pop	de
                            369 ;src/main.c:127: pvideomem = cpct_getScreenPtr(VMEM, posicionp.x, posicionp.y);
   4214 1A            [ 7]  370 	ld	a,(de)
   4215 DD 6E FE      [19]  371 	ld	l,-2 (ix)
   4218 DD 66 FF      [19]  372 	ld	h,-1 (ix)
   421B 46            [ 7]  373 	ld	b,(hl)
   421C D5            [11]  374 	push	de
   421D F5            [11]  375 	push	af
   421E 33            [ 6]  376 	inc	sp
   421F C5            [11]  377 	push	bc
   4220 33            [ 6]  378 	inc	sp
   4221 21 00 C0      [10]  379 	ld	hl,#0xC000
   4224 E5            [11]  380 	push	hl
   4225 CD 01 45      [17]  381 	call	_cpct_getScreenPtr
   4228 4D            [ 4]  382 	ld	c,l
   4229 44            [ 4]  383 	ld	b,h
   422A 21 03 10      [10]  384 	ld	hl,#0x1003
   422D E5            [11]  385 	push	hl
   422E AF            [ 4]  386 	xor	a, a
   422F F5            [11]  387 	push	af
   4230 33            [ 6]  388 	inc	sp
   4231 C5            [11]  389 	push	bc
   4232 CD 48 44      [17]  390 	call	_cpct_drawSolidBox
   4235 F1            [10]  391 	pop	af
   4236 F1            [10]  392 	pop	af
   4237 33            [ 6]  393 	inc	sp
   4238 CD 45 43      [17]  394 	call	_cpct_scanKeyboard_f
   423B 21 00 02      [10]  395 	ld	hl,#0x0200
   423E CD 39 43      [17]  396 	call	_cpct_isKeyPressed
   4241 D1            [10]  397 	pop	de
   4242 7D            [ 4]  398 	ld	a,l
   4243 B7            [ 4]  399 	or	a, a
   4244 28 1B         [12]  400 	jr	Z,00105$
   4246 DD 6E FE      [19]  401 	ld	l,-2 (ix)
   4249 DD 66 FF      [19]  402 	ld	h,-1 (ix)
   424C 4E            [ 7]  403 	ld	c,(hl)
   424D 79            [ 4]  404 	ld	a,c
   424E D6 4D         [ 7]  405 	sub	a, #0x4D
   4250 30 0F         [12]  406 	jr	NC,00105$
   4252 0C            [ 4]  407 	inc	c
   4253 DD 6E FE      [19]  408 	ld	l,-2 (ix)
   4256 DD 66 FF      [19]  409 	ld	h,-1 (ix)
   4259 71            [ 7]  410 	ld	(hl),c
   425A 21 23 45      [10]  411 	ld	hl,#_pos_player + 0
   425D 36 00         [10]  412 	ld	(hl), #0x00
   425F 18 24         [12]  413 	jr	00106$
   4261                     414 00105$:
                            415 ;src/main.c:153: else if (cpct_isKeyPressed(Key_CursorLeft)  && posicionp.x > 0              ) {--posicionp.x; pos_player=1;}
   4261 D5            [11]  416 	push	de
   4262 21 01 01      [10]  417 	ld	hl,#0x0101
   4265 CD 39 43      [17]  418 	call	_cpct_isKeyPressed
   4268 D1            [10]  419 	pop	de
   4269 7D            [ 4]  420 	ld	a,l
   426A B7            [ 4]  421 	or	a, a
   426B 28 18         [12]  422 	jr	Z,00106$
   426D DD 6E FE      [19]  423 	ld	l,-2 (ix)
   4270 DD 66 FF      [19]  424 	ld	h,-1 (ix)
   4273 4E            [ 7]  425 	ld	c,(hl)
   4274 79            [ 4]  426 	ld	a,c
   4275 B7            [ 4]  427 	or	a, a
   4276 28 0D         [12]  428 	jr	Z,00106$
   4278 0D            [ 4]  429 	dec	c
   4279 DD 6E FE      [19]  430 	ld	l,-2 (ix)
   427C DD 66 FF      [19]  431 	ld	h,-1 (ix)
   427F 71            [ 7]  432 	ld	(hl),c
   4280 21 23 45      [10]  433 	ld	hl,#_pos_player + 0
   4283 36 01         [10]  434 	ld	(hl), #0x01
   4285                     435 00106$:
                            436 ;src/main.c:157: if      (cpct_isKeyPressed(Key_CursorUp)    && posicionp.y > 0  && player_salto==0            ) {player_salto=1;subiendo=1;}
   4285 D5            [11]  437 	push	de
   4286 21 00 01      [10]  438 	ld	hl,#0x0100
   4289 CD 39 43      [17]  439 	call	_cpct_isKeyPressed
   428C 45            [ 4]  440 	ld	b,l
   428D D1            [10]  441 	pop	de
                            442 ;src/main.c:127: pvideomem = cpct_getScreenPtr(VMEM, posicionp.x, posicionp.y);
   428E 1A            [ 7]  443 	ld	a,(de)
   428F 4F            [ 4]  444 	ld	c,a
                            445 ;src/main.c:157: if      (cpct_isKeyPressed(Key_CursorUp)    && posicionp.y > 0  && player_salto==0            ) {player_salto=1;subiendo=1;}
   4290 78            [ 4]  446 	ld	a,b
   4291 B7            [ 4]  447 	or	a, a
   4292 28 14         [12]  448 	jr	Z,00109$
   4294 79            [ 4]  449 	ld	a,c
   4295 B7            [ 4]  450 	or	a, a
   4296 28 10         [12]  451 	jr	Z,00109$
   4298 3A 21 45      [13]  452 	ld	a,(#_player_salto + 0)
   429B B7            [ 4]  453 	or	a, a
   429C 20 0A         [12]  454 	jr	NZ,00109$
   429E 21 21 45      [10]  455 	ld	hl,#_player_salto + 0
   42A1 36 01         [10]  456 	ld	(hl), #0x01
   42A3 21 22 45      [10]  457 	ld	hl,#_subiendo + 0
   42A6 36 01         [10]  458 	ld	(hl), #0x01
   42A8                     459 00109$:
                            460 ;src/main.c:160: if(player_salto>0)//está saltando , cuando player_salto==
   42A8 3A 21 45      [13]  461 	ld	a,(#_player_salto + 0)
   42AB B7            [ 4]  462 	or	a, a
   42AC 28 33         [12]  463 	jr	Z,00121$
                            464 ;src/main.c:162: if((player_salto<20) && (subiendo==1))
   42AE 3A 21 45      [13]  465 	ld	a,(#_player_salto + 0)
   42B1 D6 14         [ 7]  466 	sub	a, #0x14
   42B3 30 0D         [12]  467 	jr	NC,00113$
   42B5 3A 22 45      [13]  468 	ld	a,(#_subiendo + 0)
   42B8 3D            [ 4]  469 	dec	a
   42B9 20 07         [12]  470 	jr	NZ,00113$
                            471 ;src/main.c:163: {--posicionp.y;
   42BB 0D            [ 4]  472 	dec	c
   42BC 79            [ 4]  473 	ld	a,c
   42BD 12            [ 7]  474 	ld	(de),a
                            475 ;src/main.c:164: player_salto++;
   42BE 21 21 45      [10]  476 	ld	hl, #_player_salto+0
   42C1 34            [11]  477 	inc	(hl)
   42C2                     478 00113$:
                            479 ;src/main.c:166: if(player_salto>=20)
   42C2 3A 21 45      [13]  480 	ld	a,(#_player_salto + 0)
   42C5 D6 14         [ 7]  481 	sub	a, #0x14
   42C7 38 05         [12]  482 	jr	C,00116$
                            483 ;src/main.c:168: subiendo=0;
   42C9 21 22 45      [10]  484 	ld	hl,#_subiendo + 0
   42CC 36 00         [10]  485 	ld	(hl), #0x00
   42CE                     486 00116$:
                            487 ;src/main.c:170: if((player_salto>0) && (subiendo==0))
   42CE 3A 21 45      [13]  488 	ld	a,(#_player_salto + 0)
   42D1 B7            [ 4]  489 	or	a, a
   42D2 28 0D         [12]  490 	jr	Z,00121$
   42D4 3A 22 45      [13]  491 	ld	a,(#_subiendo + 0)
   42D7 B7            [ 4]  492 	or	a, a
   42D8 20 07         [12]  493 	jr	NZ,00121$
                            494 ;src/main.c:171: {++posicionp.y;
   42DA 1A            [ 7]  495 	ld	a,(de)
   42DB 3C            [ 4]  496 	inc	a
   42DC 12            [ 7]  497 	ld	(de),a
                            498 ;src/main.c:172: player_salto--;
   42DD 21 21 45      [10]  499 	ld	hl, #_player_salto+0
   42E0 35            [11]  500 	dec	(hl)
   42E1                     501 00121$:
                            502 ;src/main.c:179: pvideomem = cpct_getScreenPtr(VMEM, posicionp.x, posicionp.y);
   42E1 1A            [ 7]  503 	ld	a,(de)
   42E2 DD 6E FE      [19]  504 	ld	l,-2 (ix)
   42E5 DD 66 FF      [19]  505 	ld	h,-1 (ix)
   42E8 46            [ 7]  506 	ld	b,(hl)
   42E9 D5            [11]  507 	push	de
   42EA F5            [11]  508 	push	af
   42EB 33            [ 6]  509 	inc	sp
   42EC C5            [11]  510 	push	bc
   42ED 33            [ 6]  511 	inc	sp
   42EE 21 00 C0      [10]  512 	ld	hl,#0xC000
   42F1 E5            [11]  513 	push	hl
   42F2 CD 01 45      [17]  514 	call	_cpct_getScreenPtr
   42F5 4D            [ 4]  515 	ld	c,l
   42F6 44            [ 4]  516 	ld	b,h
   42F7 D1            [10]  517 	pop	de
                            518 ;src/main.c:135: cpct_drawSolidBox(pvideomem,0, SP_W, SP_H);//dibujamos un recuadro negro para limpiar la pantalla
                            519 ;src/main.c:185: if(pos_player==0)
   42F8 3A 23 45      [13]  520 	ld	a,(#_pos_player + 0)
   42FB B7            [ 4]  521 	or	a, a
   42FC 20 11         [12]  522 	jr	NZ,00123$
                            523 ;src/main.c:187: cpct_drawSpriteMasked(g_tile_mago_simple, pvideomem, SP_W, SP_H);
   42FE D5            [11]  524 	push	de
   42FF 21 03 10      [10]  525 	ld	hl,#0x1003
   4302 E5            [11]  526 	push	hl
   4303 C5            [11]  527 	push	bc
   4304 21 06 41      [10]  528 	ld	hl,#_g_tile_mago_simple
   4307 E5            [11]  529 	push	hl
   4308 CD D8 43      [17]  530 	call	_cpct_drawSpriteMasked
   430B D1            [10]  531 	pop	de
   430C C3 0F 42      [10]  532 	jp	00126$
   430F                     533 00123$:
                            534 ;src/main.c:191: cpct_drawSpriteMasked(g_tile_mago_simple_iz, pvideomem, SP_W, SP_H);
   430F D5            [11]  535 	push	de
   4310 21 03 10      [10]  536 	ld	hl,#0x1003
   4313 E5            [11]  537 	push	hl
   4314 C5            [11]  538 	push	bc
   4315 21 66 41      [10]  539 	ld	hl,#_g_tile_mago_simple_iz
   4318 E5            [11]  540 	push	hl
   4319 CD D8 43      [17]  541 	call	_cpct_drawSpriteMasked
   431C D1            [10]  542 	pop	de
   431D C3 0F 42      [10]  543 	jp	00126$
                            544 ;src/main.c:199: void fase_1()
                            545 ;	---------------------------------
                            546 ; Function fase_1
                            547 ; ---------------------------------
   4320                     548 _fase_1::
                            549 ;src/main.c:202: }
   4320 C9            [10]  550 	ret
                            551 ;src/main.c:204: void fase_jefe()
                            552 ;	---------------------------------
                            553 ; Function fase_jefe
                            554 ; ---------------------------------
   4321                     555 _fase_jefe::
                            556 ;src/main.c:207: }
   4321 C9            [10]  557 	ret
                            558 	.area _CODE
                            559 	.area _INITIALIZER
   4524                     560 __xinit__player_salto:
   4524 00                  561 	.db #0x00	; 0
   4525                     562 __xinit__subiendo:
   4525 00                  563 	.db #0x00	; 0
   4526                     564 __xinit__pos_player:
   4526 00                  565 	.db #0x00	; 0
                            566 	.area _CABS (ABS)
