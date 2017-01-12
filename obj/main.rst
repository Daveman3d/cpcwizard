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
                             17 	.globl _cpct_setPalette
                             18 	.globl _cpct_fw2hw
                             19 	.globl _cpct_waitVSYNC
                             20 	.globl _cpct_setVideoMode
                             21 	.globl _cpct_drawSolidBox
                             22 	.globl _cpct_drawSpriteMasked
                             23 	.globl _cpct_isKeyPressed
                             24 	.globl _cpct_scanKeyboard_f
                             25 	.globl _cpct_disableFirmware
                             26 	.globl _pos_player
                             27 	.globl _subiendo
                             28 	.globl _player_salto
                             29 	.globl _g_palette
                             30 	.globl _g_tile_block
                             31 	.globl _g_tile_mago_simple_iz
                             32 	.globl _g_tile_mago_simple
                             33 ;--------------------------------------------------------
                             34 ; special function registers
                             35 ;--------------------------------------------------------
                             36 ;--------------------------------------------------------
                             37 ; ram data
                             38 ;--------------------------------------------------------
                             39 	.area _DATA
                             40 ;--------------------------------------------------------
                             41 ; ram data
                             42 ;--------------------------------------------------------
                             43 	.area _INITIALIZED
   4520                      44 _player_salto::
   4520                      45 	.ds 1
   4521                      46 _subiendo::
   4521                      47 	.ds 1
   4522                      48 _pos_player::
   4522                      49 	.ds 1
                             50 ;--------------------------------------------------------
                             51 ; absolute external ram data
                             52 ;--------------------------------------------------------
                             53 	.area _DABS (ABS)
                             54 ;--------------------------------------------------------
                             55 ; global & static initialisations
                             56 ;--------------------------------------------------------
                             57 	.area _HOME
                             58 	.area _GSINIT
                             59 	.area _GSFINAL
                             60 	.area _GSINIT
                             61 ;--------------------------------------------------------
                             62 ; Home
                             63 ;--------------------------------------------------------
                             64 	.area _HOME
                             65 	.area _HOME
                             66 ;--------------------------------------------------------
                             67 ; code
                             68 ;--------------------------------------------------------
                             69 	.area _CODE
                             70 ;src/main.c:87: void init()
                             71 ;	---------------------------------
                             72 ; Function init
                             73 ; ---------------------------------
   40E0                      74 _init::
                             75 ;src/main.c:93: cpct_disableFirmware();
   40E0 CD 37 44      [17]   76 	call	_cpct_disableFirmware
                             77 ;src/main.c:95: cpct_setVideoMode(1);
   40E3 2E 01         [ 7]   78 	ld	l,#0x01
   40E5 CD 29 44      [17]   79 	call	_cpct_setVideoMode
                             80 ;src/main.c:97: cpct_fw2hw     (g_palette, 4); // Convert our palette from firmware to hardware colours 
   40E8 21 04 00      [10]   81 	ld	hl,#0x0004
   40EB E5            [11]   82 	push	hl
   40EC 21 DF 41      [10]   83 	ld	hl,#_g_palette
   40EF E5            [11]   84 	push	hl
   40F0 CD BA 43      [17]   85 	call	_cpct_fw2hw
                             86 ;src/main.c:98: cpct_setPalette(g_palette, 4); // Set up the hardware palette using hardware colours   
   40F3 21 04 00      [10]   87 	ld	hl,#0x0004
   40F6 E5            [11]   88 	push	hl
   40F7 21 DF 41      [10]   89 	ld	hl,#_g_palette
   40FA E5            [11]   90 	push	hl
   40FB CD 2D 43      [17]   91 	call	_cpct_setPalette
   40FE C9            [10]   92 	ret
   40FF                      93 _g_tile_mago_simple:
   40FF 00                   94 	.db #0x00	; 0
   4100 00                   95 	.db #0x00	; 0
   4101 00                   96 	.db #0x00	; 0
   4102 00                   97 	.db #0x00	; 0
   4103 00                   98 	.db #0x00	; 0
   4104 00                   99 	.db #0x00	; 0
   4105 00                  100 	.db #0x00	; 0
   4106 08                  101 	.db #0x08	; 8
   4107 08                  102 	.db #0x08	; 8
   4108 00                  103 	.db #0x00	; 0
   4109 00                  104 	.db #0x00	; 0
   410A 00                  105 	.db #0x00	; 0
   410B 00                  106 	.db #0x00	; 0
   410C 04                  107 	.db #0x04	; 4
   410D 04                  108 	.db #0x04	; 4
   410E 04                  109 	.db #0x04	; 4
   410F 08                  110 	.db #0x08	; 8
   4110 00                  111 	.db #0x00	; 0
   4111 00                  112 	.db #0x00	; 0
   4112 08                  113 	.db #0x08	; 8
   4113 08                  114 	.db #0x08	; 8
   4114 08                  115 	.db #0x08	; 8
   4115 00                  116 	.db #0x00	; 0
   4116 00                  117 	.db #0x00	; 0
   4117 00                  118 	.db #0x00	; 0
   4118 0C                  119 	.db #0x0C	; 12
   4119 08                  120 	.db #0x08	; 8
   411A 44                  121 	.db #0x44	; 68	'D'
   411B 88                  122 	.db #0x88	; 136
   411C 00                  123 	.db #0x00	; 0
   411D 00                  124 	.db #0x00	; 0
   411E 04                  125 	.db #0x04	; 4
   411F 44                  126 	.db #0x44	; 68	'D'
   4120 88                  127 	.db #0x88	; 136
   4121 CC                  128 	.db #0xCC	; 204
   4122 00                  129 	.db #0x00	; 0
   4123 00                  130 	.db #0x00	; 0
   4124 00                  131 	.db #0x00	; 0
   4125 44                  132 	.db #0x44	; 68	'D'
   4126 88                  133 	.db #0x88	; 136
   4127 CC                  134 	.db #0xCC	; 204
   4128 00                  135 	.db #0x00	; 0
   4129 00                  136 	.db #0x00	; 0
   412A 00                  137 	.db #0x00	; 0
   412B CC                  138 	.db #0xCC	; 204
   412C CC                  139 	.db #0xCC	; 204
   412D 00                  140 	.db #0x00	; 0
   412E 00                  141 	.db #0x00	; 0
   412F 00                  142 	.db #0x00	; 0
   4130 00                  143 	.db #0x00	; 0
   4131 00                  144 	.db #0x00	; 0
   4132 00                  145 	.db #0x00	; 0
   4133 00                  146 	.db #0x00	; 0
   4134 00                  147 	.db #0x00	; 0
   4135 00                  148 	.db #0x00	; 0
   4136 00                  149 	.db #0x00	; 0
   4137 0C                  150 	.db #0x0C	; 12
   4138 0C                  151 	.db #0x0C	; 12
   4139 0C                  152 	.db #0x0C	; 12
   413A 00                  153 	.db #0x00	; 0
   413B 00                  154 	.db #0x00	; 0
   413C 04                  155 	.db #0x04	; 4
   413D 04                  156 	.db #0x04	; 4
   413E 04                  157 	.db #0x04	; 4
   413F 00                  158 	.db #0x00	; 0
   4140 88                  159 	.db #0x88	; 136
   4141 00                  160 	.db #0x00	; 0
   4142 00                  161 	.db #0x00	; 0
   4143 08                  162 	.db #0x08	; 8
   4144 08                  163 	.db #0x08	; 8
   4145 CC                  164 	.db #0xCC	; 204
   4146 00                  165 	.db #0x00	; 0
   4147 00                  166 	.db #0x00	; 0
   4148 04                  167 	.db #0x04	; 4
   4149 00                  168 	.db #0x00	; 0
   414A CC                  169 	.db #0xCC	; 204
   414B 00                  170 	.db #0x00	; 0
   414C 00                  171 	.db #0x00	; 0
   414D 00                  172 	.db #0x00	; 0
   414E 08                  173 	.db #0x08	; 8
   414F 04                  174 	.db #0x04	; 4
   4150 08                  175 	.db #0x08	; 8
   4151 08                  176 	.db #0x08	; 8
   4152 00                  177 	.db #0x00	; 0
   4153 00                  178 	.db #0x00	; 0
   4154 00                  179 	.db #0x00	; 0
   4155 00                  180 	.db #0x00	; 0
   4156 00                  181 	.db #0x00	; 0
   4157 00                  182 	.db #0x00	; 0
   4158 00                  183 	.db #0x00	; 0
   4159 00                  184 	.db #0x00	; 0
   415A 00                  185 	.db #0x00	; 0
   415B 00                  186 	.db #0x00	; 0
   415C 00                  187 	.db #0x00	; 0
   415D 00                  188 	.db #0x00	; 0
   415E 00                  189 	.db #0x00	; 0
   415F                     190 _g_tile_mago_simple_iz:
   415F CC                  191 	.db #0xCC	; 204
   4160 CC                  192 	.db #0xCC	; 204
   4161 CC                  193 	.db #0xCC	; 204
   4162 88                  194 	.db #0x88	; 136
   4163 00                  195 	.db #0x00	; 0
   4164 44                  196 	.db #0x44	; 68	'D'
   4165 00                  197 	.db #0x00	; 0
   4166 00                  198 	.db #0x00	; 0
   4167 00                  199 	.db #0x00	; 0
   4168 04                  200 	.db #0x04	; 4
   4169 04                  201 	.db #0x04	; 4
   416A 44                  202 	.db #0x44	; 68	'D'
   416B 88                  203 	.db #0x88	; 136
   416C 04                  204 	.db #0x04	; 4
   416D 08                  205 	.db #0x08	; 8
   416E 08                  206 	.db #0x08	; 8
   416F 08                  207 	.db #0x08	; 8
   4170 44                  208 	.db #0x44	; 68	'D'
   4171 CC                  209 	.db #0xCC	; 204
   4172 00                  210 	.db #0x00	; 0
   4173 04                  211 	.db #0x04	; 4
   4174 04                  212 	.db #0x04	; 4
   4175 04                  213 	.db #0x04	; 4
   4176 44                  214 	.db #0x44	; 68	'D'
   4177 CC                  215 	.db #0xCC	; 204
   4178 44                  216 	.db #0x44	; 68	'D'
   4179 88                  217 	.db #0x88	; 136
   417A 04                  218 	.db #0x04	; 4
   417B 0C                  219 	.db #0x0C	; 12
   417C 44                  220 	.db #0x44	; 68	'D'
   417D 88                  221 	.db #0x88	; 136
   417E CC                  222 	.db #0xCC	; 204
   417F 44                  223 	.db #0x44	; 68	'D'
   4180 88                  224 	.db #0x88	; 136
   4181 08                  225 	.db #0x08	; 8
   4182 CC                  226 	.db #0xCC	; 204
   4183 88                  227 	.db #0x88	; 136
   4184 CC                  228 	.db #0xCC	; 204
   4185 44                  229 	.db #0x44	; 68	'D'
   4186 88                  230 	.db #0x88	; 136
   4187 00                  231 	.db #0x00	; 0
   4188 44                  232 	.db #0x44	; 68	'D'
   4189 CC                  233 	.db #0xCC	; 204
   418A 00                  234 	.db #0x00	; 0
   418B CC                  235 	.db #0xCC	; 204
   418C CC                  236 	.db #0xCC	; 204
   418D 44                  237 	.db #0x44	; 68	'D'
   418E 00                  238 	.db #0x00	; 0
   418F 88                  239 	.db #0x88	; 136
   4190 00                  240 	.db #0x00	; 0
   4191 00                  241 	.db #0x00	; 0
   4192 00                  242 	.db #0x00	; 0
   4193 44                  243 	.db #0x44	; 68	'D'
   4194 CC                  244 	.db #0xCC	; 204
   4195 88                  245 	.db #0x88	; 136
   4196 0C                  246 	.db #0x0C	; 12
   4197 0C                  247 	.db #0x0C	; 12
   4198 0C                  248 	.db #0x0C	; 12
   4199 44                  249 	.db #0x44	; 68	'D'
   419A CC                  250 	.db #0xCC	; 204
   419B 00                  251 	.db #0x00	; 0
   419C 00                  252 	.db #0x00	; 0
   419D 08                  253 	.db #0x08	; 8
   419E 08                  254 	.db #0x08	; 8
   419F 08                  255 	.db #0x08	; 8
   41A0 CC                  256 	.db #0xCC	; 204
   41A1 88                  257 	.db #0x88	; 136
   41A2 00                  258 	.db #0x00	; 0
   41A3 04                  259 	.db #0x04	; 4
   41A4 04                  260 	.db #0x04	; 4
   41A5 00                  261 	.db #0x00	; 0
   41A6 CC                  262 	.db #0xCC	; 204
   41A7 88                  263 	.db #0x88	; 136
   41A8 00                  264 	.db #0x00	; 0
   41A9 44                  265 	.db #0x44	; 68	'D'
   41AA 00                  266 	.db #0x00	; 0
   41AB 08                  267 	.db #0x08	; 8
   41AC CC                  268 	.db #0xCC	; 204
   41AD 88                  269 	.db #0x88	; 136
   41AE 04                  270 	.db #0x04	; 4
   41AF 04                  271 	.db #0x04	; 4
   41B0 08                  272 	.db #0x08	; 8
   41B1 04                  273 	.db #0x04	; 4
   41B2 44                  274 	.db #0x44	; 68	'D'
   41B3 00                  275 	.db #0x00	; 0
   41B4 00                  276 	.db #0x00	; 0
   41B5 00                  277 	.db #0x00	; 0
   41B6 00                  278 	.db #0x00	; 0
   41B7 00                  279 	.db #0x00	; 0
   41B8 44                  280 	.db #0x44	; 68	'D'
   41B9 00                  281 	.db #0x00	; 0
   41BA 00                  282 	.db #0x00	; 0
   41BB CC                  283 	.db #0xCC	; 204
   41BC 00                  284 	.db #0x00	; 0
   41BD 00                  285 	.db #0x00	; 0
   41BE CC                  286 	.db #0xCC	; 204
   41BF                     287 _g_tile_block:
   41BF 0F                  288 	.db #0x0F	; 15
   41C0 0F                  289 	.db #0x0F	; 15
   41C1 0F                  290 	.db #0x0F	; 15
   41C2 0F                  291 	.db #0x0F	; 15
   41C3 0F                  292 	.db #0x0F	; 15
   41C4 0F                  293 	.db #0x0F	; 15
   41C5 0F                  294 	.db #0x0F	; 15
   41C6 0F                  295 	.db #0x0F	; 15
   41C7 0F                  296 	.db #0x0F	; 15
   41C8 0F                  297 	.db #0x0F	; 15
   41C9 0F                  298 	.db #0x0F	; 15
   41CA 0F                  299 	.db #0x0F	; 15
   41CB 0F                  300 	.db #0x0F	; 15
   41CC 0F                  301 	.db #0x0F	; 15
   41CD 0F                  302 	.db #0x0F	; 15
   41CE 0F                  303 	.db #0x0F	; 15
   41CF 0F                  304 	.db #0x0F	; 15
   41D0 0F                  305 	.db #0x0F	; 15
   41D1 0F                  306 	.db #0x0F	; 15
   41D2 0F                  307 	.db #0x0F	; 15
   41D3 0F                  308 	.db #0x0F	; 15
   41D4 0F                  309 	.db #0x0F	; 15
   41D5 0F                  310 	.db #0x0F	; 15
   41D6 0F                  311 	.db #0x0F	; 15
   41D7 0F                  312 	.db #0x0F	; 15
   41D8 0F                  313 	.db #0x0F	; 15
   41D9 0F                  314 	.db #0x0F	; 15
   41DA 0F                  315 	.db #0x0F	; 15
   41DB 0F                  316 	.db #0x0F	; 15
   41DC 0F                  317 	.db #0x0F	; 15
   41DD 0F                  318 	.db #0x0F	; 15
   41DE 0F                  319 	.db #0x0F	; 15
   41DF                     320 _g_palette:
   41DF 00                  321 	.db #0x00	; 0
   41E0 02                  322 	.db #0x02	; 2
   41E1 17                  323 	.db #0x17	; 23
   41E2 1A                  324 	.db #0x1A	; 26
                            325 ;src/main.c:103: void pantalla_start()
                            326 ;	---------------------------------
                            327 ; Function pantalla_start
                            328 ; ---------------------------------
   41E3                     329 _pantalla_start::
                            330 ;src/main.c:110: }
   41E3 C9            [10]  331 	ret
                            332 ;src/main.c:114: void main(void) {
                            333 ;	---------------------------------
                            334 ; Function main
                            335 ; ---------------------------------
   41E4                     336 _main::
   41E4 DD E5         [15]  337 	push	ix
   41E6 DD 21 00 00   [14]  338 	ld	ix,#0
   41EA DD 39         [15]  339 	add	ix,sp
   41EC F5            [11]  340 	push	af
   41ED F5            [11]  341 	push	af
                            342 ;src/main.c:115: Tplayer posicionp={0,100};
   41EE 21 00 00      [10]  343 	ld	hl,#0x0000
   41F1 39            [11]  344 	add	hl,sp
   41F2 36 00         [10]  345 	ld	(hl),#0x00
   41F4 21 00 00      [10]  346 	ld	hl,#0x0000
   41F7 39            [11]  347 	add	hl,sp
   41F8 DD 75 FE      [19]  348 	ld	-2 (ix),l
   41FB DD 74 FF      [19]  349 	ld	-1 (ix),h
   41FE EB            [ 4]  350 	ex	de,hl
   41FF 13            [ 6]  351 	inc	de
   4200 3E 64         [ 7]  352 	ld	a,#0x64
   4202 12            [ 7]  353 	ld	(de),a
                            354 ;src/main.c:118: init();
   4203 D5            [11]  355 	push	de
   4204 CD E0 40      [17]  356 	call	_init
   4207 D1            [10]  357 	pop	de
                            358 ;src/main.c:124: while(1) {
   4208                     359 00126$:
                            360 ;src/main.c:125: cpct_waitVSYNC ();//esperamos a que haya recorrido la pantalla
   4208 D5            [11]  361 	push	de
   4209 CD 21 44      [17]  362 	call	_cpct_waitVSYNC
   420C D1            [10]  363 	pop	de
                            364 ;src/main.c:126: pvideomem = cpct_getScreenPtr(VMEM, posicionp.x, posicionp.y);
   420D 1A            [ 7]  365 	ld	a,(de)
   420E DD 6E FE      [19]  366 	ld	l,-2 (ix)
   4211 DD 66 FF      [19]  367 	ld	h,-1 (ix)
   4214 46            [ 7]  368 	ld	b,(hl)
   4215 D5            [11]  369 	push	de
   4216 F5            [11]  370 	push	af
   4217 33            [ 6]  371 	inc	sp
   4218 C5            [11]  372 	push	bc
   4219 33            [ 6]  373 	inc	sp
   421A 21 00 C0      [10]  374 	ld	hl,#0xC000
   421D E5            [11]  375 	push	hl
   421E CD 00 45      [17]  376 	call	_cpct_getScreenPtr
   4221 4D            [ 4]  377 	ld	c,l
   4222 44            [ 4]  378 	ld	b,h
   4223 D1            [10]  379 	pop	de
                            380 ;src/main.c:134: cpct_drawSolidBox(pvideomem,0, SP_W, SP_H);//dibujamos un recuadro negro para limpiar la pantalla
   4224 C5            [11]  381 	push	bc
   4225 D5            [11]  382 	push	de
   4226 21 03 10      [10]  383 	ld	hl,#0x1003
   4229 E5            [11]  384 	push	hl
   422A AF            [ 4]  385 	xor	a, a
   422B F5            [11]  386 	push	af
   422C 33            [ 6]  387 	inc	sp
   422D C5            [11]  388 	push	bc
   422E CD 47 44      [17]  389 	call	_cpct_drawSolidBox
   4231 F1            [10]  390 	pop	af
   4232 F1            [10]  391 	pop	af
   4233 33            [ 6]  392 	inc	sp
   4234 D1            [10]  393 	pop	de
   4235 C1            [10]  394 	pop	bc
                            395 ;src/main.c:137: cpct_drawSpriteMasked(g_tile_block, pvideomem, SP_W+4, SP_H);
   4236 D5            [11]  396 	push	de
   4237 21 07 10      [10]  397 	ld	hl,#0x1007
   423A E5            [11]  398 	push	hl
   423B C5            [11]  399 	push	bc
   423C 21 BF 41      [10]  400 	ld	hl,#_g_tile_block
   423F E5            [11]  401 	push	hl
   4240 CD D7 43      [17]  402 	call	_cpct_drawSpriteMasked
   4243 CD 50 43      [17]  403 	call	_cpct_scanKeyboard_f
   4246 21 00 02      [10]  404 	ld	hl,#0x0200
   4249 CD 44 43      [17]  405 	call	_cpct_isKeyPressed
   424C D1            [10]  406 	pop	de
   424D 7D            [ 4]  407 	ld	a,l
   424E B7            [ 4]  408 	or	a, a
   424F 28 1B         [12]  409 	jr	Z,00105$
   4251 DD 6E FE      [19]  410 	ld	l,-2 (ix)
   4254 DD 66 FF      [19]  411 	ld	h,-1 (ix)
   4257 4E            [ 7]  412 	ld	c,(hl)
   4258 79            [ 4]  413 	ld	a,c
   4259 D6 4D         [ 7]  414 	sub	a, #0x4D
   425B 30 0F         [12]  415 	jr	NC,00105$
   425D 0C            [ 4]  416 	inc	c
   425E DD 6E FE      [19]  417 	ld	l,-2 (ix)
   4261 DD 66 FF      [19]  418 	ld	h,-1 (ix)
   4264 71            [ 7]  419 	ld	(hl),c
   4265 21 22 45      [10]  420 	ld	hl,#_pos_player + 0
   4268 36 00         [10]  421 	ld	(hl), #0x00
   426A 18 24         [12]  422 	jr	00106$
   426C                     423 00105$:
                            424 ;src/main.c:152: else if (cpct_isKeyPressed(Key_CursorLeft)  && posicionp.x > 0              ) {--posicionp.x; pos_player=1;}
   426C D5            [11]  425 	push	de
   426D 21 01 01      [10]  426 	ld	hl,#0x0101
   4270 CD 44 43      [17]  427 	call	_cpct_isKeyPressed
   4273 D1            [10]  428 	pop	de
   4274 7D            [ 4]  429 	ld	a,l
   4275 B7            [ 4]  430 	or	a, a
   4276 28 18         [12]  431 	jr	Z,00106$
   4278 DD 6E FE      [19]  432 	ld	l,-2 (ix)
   427B DD 66 FF      [19]  433 	ld	h,-1 (ix)
   427E 4E            [ 7]  434 	ld	c,(hl)
   427F 79            [ 4]  435 	ld	a,c
   4280 B7            [ 4]  436 	or	a, a
   4281 28 0D         [12]  437 	jr	Z,00106$
   4283 0D            [ 4]  438 	dec	c
   4284 DD 6E FE      [19]  439 	ld	l,-2 (ix)
   4287 DD 66 FF      [19]  440 	ld	h,-1 (ix)
   428A 71            [ 7]  441 	ld	(hl),c
   428B 21 22 45      [10]  442 	ld	hl,#_pos_player + 0
   428E 36 01         [10]  443 	ld	(hl), #0x01
   4290                     444 00106$:
                            445 ;src/main.c:156: if      (cpct_isKeyPressed(Key_CursorUp)    && posicionp.y > 0  && player_salto==0            ) {player_salto=1;subiendo=1;}
   4290 D5            [11]  446 	push	de
   4291 21 00 01      [10]  447 	ld	hl,#0x0100
   4294 CD 44 43      [17]  448 	call	_cpct_isKeyPressed
   4297 45            [ 4]  449 	ld	b,l
   4298 D1            [10]  450 	pop	de
                            451 ;src/main.c:126: pvideomem = cpct_getScreenPtr(VMEM, posicionp.x, posicionp.y);
   4299 1A            [ 7]  452 	ld	a,(de)
   429A 4F            [ 4]  453 	ld	c,a
                            454 ;src/main.c:156: if      (cpct_isKeyPressed(Key_CursorUp)    && posicionp.y > 0  && player_salto==0            ) {player_salto=1;subiendo=1;}
   429B 78            [ 4]  455 	ld	a,b
   429C B7            [ 4]  456 	or	a, a
   429D 28 14         [12]  457 	jr	Z,00109$
   429F 79            [ 4]  458 	ld	a,c
   42A0 B7            [ 4]  459 	or	a, a
   42A1 28 10         [12]  460 	jr	Z,00109$
   42A3 3A 20 45      [13]  461 	ld	a,(#_player_salto + 0)
   42A6 B7            [ 4]  462 	or	a, a
   42A7 20 0A         [12]  463 	jr	NZ,00109$
   42A9 21 20 45      [10]  464 	ld	hl,#_player_salto + 0
   42AC 36 01         [10]  465 	ld	(hl), #0x01
   42AE 21 21 45      [10]  466 	ld	hl,#_subiendo + 0
   42B1 36 01         [10]  467 	ld	(hl), #0x01
   42B3                     468 00109$:
                            469 ;src/main.c:159: if(player_salto>0)//está saltando , cuando player_salto==
   42B3 3A 20 45      [13]  470 	ld	a,(#_player_salto + 0)
   42B6 B7            [ 4]  471 	or	a, a
   42B7 28 33         [12]  472 	jr	Z,00121$
                            473 ;src/main.c:161: if((player_salto<20) && (subiendo==1))
   42B9 3A 20 45      [13]  474 	ld	a,(#_player_salto + 0)
   42BC D6 14         [ 7]  475 	sub	a, #0x14
   42BE 30 0D         [12]  476 	jr	NC,00113$
   42C0 3A 21 45      [13]  477 	ld	a,(#_subiendo + 0)
   42C3 3D            [ 4]  478 	dec	a
   42C4 20 07         [12]  479 	jr	NZ,00113$
                            480 ;src/main.c:162: {--posicionp.y;
   42C6 0D            [ 4]  481 	dec	c
   42C7 79            [ 4]  482 	ld	a,c
   42C8 12            [ 7]  483 	ld	(de),a
                            484 ;src/main.c:163: player_salto++;
   42C9 21 20 45      [10]  485 	ld	hl, #_player_salto+0
   42CC 34            [11]  486 	inc	(hl)
   42CD                     487 00113$:
                            488 ;src/main.c:165: if(player_salto>=20)
   42CD 3A 20 45      [13]  489 	ld	a,(#_player_salto + 0)
   42D0 D6 14         [ 7]  490 	sub	a, #0x14
   42D2 38 05         [12]  491 	jr	C,00116$
                            492 ;src/main.c:167: subiendo=0;
   42D4 21 21 45      [10]  493 	ld	hl,#_subiendo + 0
   42D7 36 00         [10]  494 	ld	(hl), #0x00
   42D9                     495 00116$:
                            496 ;src/main.c:169: if((player_salto>0) && (subiendo==0))
   42D9 3A 20 45      [13]  497 	ld	a,(#_player_salto + 0)
   42DC B7            [ 4]  498 	or	a, a
   42DD 28 0D         [12]  499 	jr	Z,00121$
   42DF 3A 21 45      [13]  500 	ld	a,(#_subiendo + 0)
   42E2 B7            [ 4]  501 	or	a, a
   42E3 20 07         [12]  502 	jr	NZ,00121$
                            503 ;src/main.c:170: {++posicionp.y;
   42E5 1A            [ 7]  504 	ld	a,(de)
   42E6 3C            [ 4]  505 	inc	a
   42E7 12            [ 7]  506 	ld	(de),a
                            507 ;src/main.c:171: player_salto--;
   42E8 21 20 45      [10]  508 	ld	hl, #_player_salto+0
   42EB 35            [11]  509 	dec	(hl)
   42EC                     510 00121$:
                            511 ;src/main.c:178: pvideomem = cpct_getScreenPtr(VMEM, posicionp.x, posicionp.y);
   42EC 1A            [ 7]  512 	ld	a,(de)
   42ED DD 6E FE      [19]  513 	ld	l,-2 (ix)
   42F0 DD 66 FF      [19]  514 	ld	h,-1 (ix)
   42F3 46            [ 7]  515 	ld	b,(hl)
   42F4 D5            [11]  516 	push	de
   42F5 F5            [11]  517 	push	af
   42F6 33            [ 6]  518 	inc	sp
   42F7 C5            [11]  519 	push	bc
   42F8 33            [ 6]  520 	inc	sp
   42F9 21 00 C0      [10]  521 	ld	hl,#0xC000
   42FC E5            [11]  522 	push	hl
   42FD CD 00 45      [17]  523 	call	_cpct_getScreenPtr
   4300 4D            [ 4]  524 	ld	c,l
   4301 44            [ 4]  525 	ld	b,h
   4302 D1            [10]  526 	pop	de
                            527 ;src/main.c:134: cpct_drawSolidBox(pvideomem,0, SP_W, SP_H);//dibujamos un recuadro negro para limpiar la pantalla
                            528 ;src/main.c:184: if(pos_player==0)
   4303 3A 22 45      [13]  529 	ld	a,(#_pos_player + 0)
   4306 B7            [ 4]  530 	or	a, a
   4307 20 11         [12]  531 	jr	NZ,00123$
                            532 ;src/main.c:186: cpct_drawSpriteMasked(g_tile_mago_simple, pvideomem, SP_W, SP_H);
   4309 D5            [11]  533 	push	de
   430A 21 03 10      [10]  534 	ld	hl,#0x1003
   430D E5            [11]  535 	push	hl
   430E C5            [11]  536 	push	bc
   430F 21 FF 40      [10]  537 	ld	hl,#_g_tile_mago_simple
   4312 E5            [11]  538 	push	hl
   4313 CD D7 43      [17]  539 	call	_cpct_drawSpriteMasked
   4316 D1            [10]  540 	pop	de
   4317 C3 08 42      [10]  541 	jp	00126$
   431A                     542 00123$:
                            543 ;src/main.c:190: cpct_drawSpriteMasked(g_tile_mago_simple_iz, pvideomem, SP_W, SP_H);
   431A D5            [11]  544 	push	de
   431B 21 03 10      [10]  545 	ld	hl,#0x1003
   431E E5            [11]  546 	push	hl
   431F C5            [11]  547 	push	bc
   4320 21 5F 41      [10]  548 	ld	hl,#_g_tile_mago_simple_iz
   4323 E5            [11]  549 	push	hl
   4324 CD D7 43      [17]  550 	call	_cpct_drawSpriteMasked
   4327 D1            [10]  551 	pop	de
   4328 C3 08 42      [10]  552 	jp	00126$
                            553 ;src/main.c:198: void fase_1()
                            554 ;	---------------------------------
                            555 ; Function fase_1
                            556 ; ---------------------------------
   432B                     557 _fase_1::
                            558 ;src/main.c:201: }
   432B C9            [10]  559 	ret
                            560 ;src/main.c:203: void fase_jefe()
                            561 ;	---------------------------------
                            562 ; Function fase_jefe
                            563 ; ---------------------------------
   432C                     564 _fase_jefe::
                            565 ;src/main.c:206: }
   432C C9            [10]  566 	ret
                            567 	.area _CODE
                            568 	.area _INITIALIZER
   4523                     569 __xinit__player_salto:
   4523 00                  570 	.db #0x00	; 0
   4524                     571 __xinit__subiendo:
   4524 00                  572 	.db #0x00	; 0
   4525                     573 __xinit__pos_player:
   4525 00                  574 	.db #0x00	; 0
                            575 	.area _CABS (ABS)
