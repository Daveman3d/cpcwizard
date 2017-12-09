//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

//#include <cpctelera.h>//importante incluirlo siempre

//codigo original
/*
#include <cpctelera.h>
void main(void) {
   u8* video_memory_start  = (u8*)0xC000;
   u8  character_line_size = 0x050;

   // Clear Screen
   cpct_memset(video_memory_start, 0, 0x4000);

   // Draw String on the middle of the screen
   cpct_drawStringM1("Welcome to CPCtelera!",
                     video_memory_start + character_line_size * 12,
                     1, 0);
   // Loop forever
   while (1);
}*/
   //fin codigo original

//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine 
//  Copyright (C) 2014-2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
//  Copyright (C)      2015 Maximo / Cheesetea / ByteRealms (@rgallego87)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include <cpctelera.h>
#include "mago_simple.c"

// Sprite size (in bytes)
#define SP_W   3
#define SP_H   16

// Screen size (in bytes)
#define SCR_W   80
#define SCR_H  200

//definimos el comienzo de la memoria de video
#define VMEM (u8*)0xC000

//creamos la paleta porque sino coge la del firmware con el fondo azul y letras amarillas
const u8 g_palette[4]={0, 2, 23, 26};

u8 player_salto=0;//inciamos la variable para detectar si está o no saltando 0 si no y 1 si sí
u8 subiendo=0;//variable para indicar si está subiendo o bajando
u8 pos_player=0;
//tipo estructura para guardar las coordenadas
typedef struct 
{ u8 x, y;//posicion del player
   
} Tplayer;

//
//parametros de inicializacion
void init()
{
   //
   // Set up the screen
   //
   // Disable firmware to prevent it from interfering with setPalette and setVideoMode
   cpct_disableFirmware();
   // Set video mode 1 (320x200, 4 colours)
   cpct_setVideoMode(1);
   // Set the colour palette
   cpct_fw2hw     (g_palette, 4); // Convert our palette from firmware to hardware colours 
   cpct_setPalette(g_palette, 4); // Set up the hardware palette using hardware colours   
   cpct_setBorder(g_palette[0]);
}

//Cargamos la pantalla de inicio
//en el momento que pulse cualquiera de las opciones empezamos el código principal
void pantalla_start()
{
   //el titulo con una musiquilla de fondo si la tiene
   //cargamos imagen
   //seleccion
   //0: start game
   //abajo ponemos los titulos de crédito
}

// MAIN: Using keyboard to move a sprite example
//codigo principal del juego, en el momento que perdamos volvemos a la función pantalla_start()
void main(void) {
   Tplayer posicionp={0,100};
   //Tscene posicion={0,50}
   u8* pvideomem;
   u8* scenevideomem;
   //u8* pvideomback;
  init();
 // Draw the sprite in the video memory location got from coordinates x, y
   //   cpct_drawSprite(g_tile_mago_simple, VMEM, SP_W, SP_H);
   // 
   // Infinite moving loop
   //
   while(1) {
      cpct_waitVSYNC ();//esperamos a que haya recorrido la pantalla
      pvideomem = cpct_getScreenPtr(VMEM, posicionp.x, posicionp.y);
	  scenevideomem=cpct_getScreenPtr(VMEM,0,0);
     /*
      //para solo repintar cuando haya un cambio
      if(pvideomem!=pvideomback)
       {        
         cpct_drawSolidBox(pvideomem,0, SP_W, SP_H);
         pvideomback=pvideomem;
      }*/
      cpct_drawSolidBox(pvideomem,0, SP_W, SP_H);//dibujamos un recuadro negro para limpiar la pantalla

      //pintamos el escenario, el bloque en el que se mueve el protagonista
		cpct_drawSpriteMasked(g_tile_block, scenevideomem, 8, 8);
		//cpct_etm_drawTilemap2x4 (100, 8, SCR, g_tile_block);
      // Scan Keyboard (fastest routine)
      // The Keyboard has to be scanned to obtain pressed / not pressed status of
      // every key before checking each individual key's status.
      cpct_scanKeyboard_f();

      // Check if user has pressed a Cursor Key and, if so, move the sprite if
      // it will still be inside screen boundaries
	  //detectamos si va en una dirección o en otra para cambiar el sprite
	  //dibujamos mago a la derecha
	  
	  
		  if      (cpct_isKeyPressed(Key_CursorRight) && posicionp.x < (SCR_W - SP_W) ) {++posicionp.x; pos_player=0;}
		  //dibujamos mago a la izquierda
		  else if (cpct_isKeyPressed(Key_CursorLeft)  && posicionp.x > 0              ) {--posicionp.x; pos_player=1;}
		  //dibujamos mago saltando/arriba
		  //necesitamos una variable para indicar si está saltando, si está saltando no volvemos a saltar, cuando finalice inicializamos la variable
		 // else  if      (cpct_isKeyPressed(Key_CursorUp)    && posicionp.y > 0              ) {--posicionp.y;}
		  if      (cpct_isKeyPressed(Key_CursorUp)    && posicionp.y > 0  && player_salto==0            ) {player_salto=1;subiendo=1;}
		  
		  //Función de salto, necesario comprobar los tiles si está encima o debajo de un tile si puede ir abajo o si puede subir arriba
		  if(player_salto>0)//está saltando , cuando player_salto==
	  {
		  if((player_salto<20) && (subiendo==1))
		  {--posicionp.y;
			player_salto++;
		  }
		  if(player_salto>=20)
		  {
			  subiendo=0;
		  }
		  if((player_salto>0) && (subiendo==0))
		  {++posicionp.y;
			player_salto--;
		  }
	  }
		  //dibujamos mago agachado/abajo
		  //else if (cpct_isKeyPressed(Key_CursorDown)  && posicionp.y < (SCR_H - SP_H) ) {++posicionp.y;}
	  
      // Get video memory byte for coordinates x, y of the sprite (in bytes)
     pvideomem = cpct_getScreenPtr(VMEM, posicionp.x, posicionp.y);
     //repintamos el cuadrado del color de fondo para que deje estela
    
      // Draw the sprite in the video memory location got from coordinates x, y     
	  //g_tile_mago_simpled
	  //g_tile_mago_simpleiz
	  if(pos_player==0)
	  {
		  cpct_drawSpriteMasked(g_tile_mago_simple, pvideomem, SP_W, SP_H);
	  }
	  else
	  {
		  cpct_drawSpriteMasked(g_tile_mago_simple_iz, pvideomem, SP_W, SP_H);
	  }
      
   }   
}
//Cargamos las fases, por cada fase sería necesario crear un mapa de tiles con durezas para saber si son bloques solidos o atravesables

//Cargamos la primera fase
void fase_1()
{
	
}
//la función para cargar la fase de un final boss
void fase_jefe()
{
   //
}
