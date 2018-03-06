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
#include <stdio.h>
#include <cpctelera.h>
#include "mago_simple.c"
#include "mago_simple.h"
#include "tiles_nivel1.h"
#include "tiles_wiz.h"
#include <string.h>
// Sprite size (in bytes)
#define SP_W   3
#define SP_H   16

// Screen size (in bytes)
#define SCR_W   80
#define SCR_H  200
//definimos las coordenadas del mapa
#define ORIGEN_MAPA_Y 0 //empiezo en 0,0
//VMEM

#define ORIGEN_MAPA  cpctm_screenPtr(CPCT_VMEM_START,0,ORIGEN_MAPA_Y)


//definimos propiedades del disparo
u8 disparo=0;//por defecto no est� disparando 
typedef struct 
{ u8 x, y;//posicion del player
   
} Tdisparo;//por defecto no hay disparo , pero en el momento que pulse deberemos crear una instancia de disparo y dejarla activa hasta que desaparezca

//definimos el mapa de tiles
u8* mapa;

//definimos el comienzo de la memoria de video
//#define VMEM (u8*)0xC000

//creamos la paleta porque sino coge la del firmware con el fondo azul y letras amarillas
//const u8 g_palette[4]={0, 2, 23, 26};
const u8 g_palette[4]={0, 13, 23, 26};

u8 player_salto=0;//inciamos la variable para detectar si est� o no saltando 0 si no y 1 si s�
u8 subiendo=0;//variable para indicar si est� subiendo o bajando
u8 pos_player=0;
//tipo estructura para guardar las coordenadas
typedef struct 
{ u8 x, y;//posicion del player
   
} Tplayer;


Tplayer posicionp={100,100};
//

void dibujarMapa()
{
  cpct_etm_drawTilemap2x4(g_map1_W,g_map1_H, ORIGEN_MAPA,mapa);  
}

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
   cpct_setBorder(g_palette[1]);

   mapa=g_map1;
  cpct_etm_setTileset2x4(g_tileset);
   dibujarMapa();
  posicionp.x=20;
   posicionp.y=50;
   
}

//Cargamos la pantalla de inicio
//en el momento que pulse cualquiera de las opciones empezamos el c�digo principal
void pantalla_start()
{
   //el titulo con una musiquilla de fondo si la tiene
   //cargamos imagen
   //seleccion
   //0: start game
   //abajo ponemos los titulos de cr�dito
}

//Obtenemos el tile en el que est� el protagonista
u8* obtenerTilePtr(u8 x, u8 y) {
   return mapa + (y-ORIGEN_MAPA_Y)/2*g_map1_W + x/2;
}


u8 sobreSuelo() {
   u8* tileSuelo = obtenerTilePtr(posicionp.x+2, posicionp.y + SP_H+1);
   if (*tileSuelo < 2 || *(tileSuelo+SP_W/2-3) < 2)
      return 1;

   return 0;
}
// MAIN: Using keyboard to move a sprite example
//codigo principal del juego, en el momento que perdamos volvemos a la funci�n pantalla_start()
void main(void) {
  
   //Tscene posicion={0,50}
   u8* pvideomem;
   u8* scenevideomem;
   u8* debugmem;
   char debugtext[16]; // texto de debug
   u8 valorx=0;
   u8 valory=0;
   u8 i;
   //u8* pvideomback;
  init();
 // Draw the sprite in the video memory location got from coordinates x, y
   //   cpct_drawSprite(g_tile_mago_simple, VMEM, SP_W, SP_H);
   // 
   // Infinite moving loop
   //
   while(1) {
      cpct_waitVSYNC ();//esperamos a que haya recorrido la pantalla
      pvideomem = cpct_getScreenPtr(CPCT_VMEM_START, posicionp.x, posicionp.y);
	//  scenevideomem=cpct_getScreenPtr(VMEM,0,116);
	  debugmem = cpct_getScreenPtr(CPCT_VMEM_START,32,0);
     /*
      //para solo repintar cuando haya un cambio
      if(pvideomem!=pvideomback)
       {        
         cpct_drawSolidBox(pvideomem,0, SP_W, SP_H);
         pvideomback=pvideomem;
      }*/
	   // sprintf(debugtext, "%10u", (strcat(strcat("X:",posicionp.x),strcat("Y:",posicionp.y))));
	/*   debugtext="";
	   strcat(debugtext,"X:");
	      strcat(debugtext,castposicionp.x);
		  strcat(debugtext,"Y:");
		  strcat(debugtext,(u8)posicionp.y);*/
		
		cpct_drawSolidBox(pvideomem,0, SP_W, SP_H);//dibujamos un recuadro negro para limpiar la pantalla
	  
	 
		//	  ;  //incluimos esta funcion que transforma el texto y lo mete en la variable para poder mostrarlo por pantalla
      //pintamos el escenario, el bloque en el que se mueve el protagonista
		//cpct_drawSprite(g_tile_block, scenevideomem, 2, 8);//el ancho es en bytes y se multiplica por 4 para el modo 1
	//	cpct_drawTileAligned2x8(g_tile_block,  scenevideomem);
//dibujamos las plataformas
	/*for(i=0; i < 192; i += 8) {
		//cargamos mapa de tiles
		//cargamos mapa de durezas
		//mostramos mapa de tiles
		//las tiles completamos las cargamos solo una vez, luego solo modificar�amos las tiles donde va el personaje, o hay enemigos
		//o hay animaciones
      scenevideomem = cpct_getScreenPtr(VMEM, i, 116);//empieza en X=0 Y=116 que es debajo del jugador
	 // cpct_drawTileAligned2x4(g_tile_block,  scenevideomem);  //lo seleccionamos la caja de tiles en cuesti�n
     // cpct_drawTileAligned2x4(g_tile_block,  scenevideomem);       
   }*/
   
   /***************************************************************************************************/
   //Cargar�amos mapa de tiles
   //Cargariamos mapa de tiles con colisi�n
   //al mover el personaje comprobariamos que la posici�n a la que va no sea solida
   //if derecha , comprobamos si al ir a la derecha el tile derecho es traspasable
   //if izquierda , comprobamos si al ir a la izquierda puede avanzar
   //if salto, si salta comprobamos que el tile de arriba y derecho son  traspasables y se pueden pasar
   //if abajo //siempre comprobamos si el tile de abajo es solido, sino se caer�a hacia abajo
   //comprobaci�n constante 
   //pesudoc�digo
	/* 
	//abajo ser�a la gravedad , por lo que es necesario comprobarla siempre
		//comprobamos posici�n del jugador en el eje y
			//comprobamos mapa de durezas de arriba si no es solido				
			if((posiciontile.y-(posicionp.y(posici�n y del jugador)+tama�o sprite)>1)
			{//caemos}
	if(pulsa tecla) //puede ser arriba, izquierda o derecha o podr�a pulsar arriba-izquierda, y arriba-derecha
	//si es la tecla de disparo debemos seguir el disparo y comprobar si choca con alg�n obstaculo
	{
		if(arriba)
		{
			//comprobamos posici�n del jugador en el eje y
			//comprobamos mapa de durezas de arriba si es s�lido
			if((posiciontile.y-(posicionp.y(posici�n y del jugador)+tama�o sprite)>1)
			{//saltamos}
		}
		if(derecha)
		{
			//comprobamos posici�n del jugador en el eje x
			//comprobamos mapa de durezas de arriba si es s�lido
			if((posiciontile.x-(posicionp.x(posici�n x del jugador)+tama�o sprite)>1)
			{//movemos derecha}
		}
		if(izquierda)
		{
			//comprobamos posici�n del jugador en el eje x
			//comprobamos mapa de durezas de arriba si es s�lido
			if((posiciontile.x-(posicionp.x(posici�n x del jugador))>1)
			{//movemos izquierda}
		}
		if(disparo)
		{
			disparo=1;//activamos el trigger para disparo, hasta que no choque con un obstaculo/enemigo o salga por pantalla lo seguimos controlando
			//si mira a la izquierda dispara a la izquierda
			if(posicion==izquierda)
			{
				disparox=-3; 
			}
			if(posicion==derecha)
			{
				disparox=+3; 
			}
			//si mira a la derecha dispara a la derecha
		}
	}
	*/
	/**************************************************************************************************/
		//cpct_etm_drawTilemap2x4 (100, 8, SCR, g_tile_block);
      // Scan Keyboard (fastest routine)
      // The Keyboard has to be scanned to obtain pressed / not pressed status of
      // every key before checking each individual key's status.
      cpct_scanKeyboard_f();

      // Check if user has pressed a Cursor Key and, if so, move the sprite if
      // it will still be inside screen boundaries
	  //detectamos si va en una direcci�n o en otra para cambiar el sprite
	  //dibujamos mago a la derecha
	  //Pendiente control de colisiones
	 
	  
		  if      (cpct_isKeyPressed(Key_CursorRight) && posicionp.x < (SCR_W - SP_W) ) {++posicionp.x; pos_player=0;}
		  //dibujamos mago a la izquierda
		  else if (cpct_isKeyPressed(Key_CursorLeft)  && posicionp.x > 0              ) {--posicionp.x; pos_player=1;}
		  //dibujamos mago saltando/arriba
		  //necesitamos una variable para indicar si est� saltando, si est� saltando no volvemos a saltar, cuando finalice inicializamos la variable
		 // else  if      (cpct_isKeyPressed(Key_CursorUp)    && posicionp.y > 0              ) {--posicionp.y;}
		  if      (cpct_isKeyPressed(Key_CursorUp)    && posicionp.y > 0  && player_salto==0            ) {player_salto=1;subiendo=1;}
		  
		  //Funci�n de salto, necesario comprobar los tiles si est� encima o debajo de un tile si puede ir abajo o si puede subir arriba
		  
		  if(player_salto>0)//est� saltando , cuando player_salto==
	  {
		  if((player_salto<20) && (subiendo==1))
		  {--posicionp.y;
			player_salto++;
		  }
		  if(player_salto>=20)
		  {
			  subiendo=0;
		  }
		  
		  //comprobamos si eld tile es 0 o 1 sino esta encima de uno de estos sigue bajando
		  if((player_salto>0 || sobreSuelo()==1) && (subiendo==0))
		  {
			  ++posicionp.y;
			  if(player_salto==0)
			  {
			  }
			  else
			  {
			player_salto--;
			  }
		  }
	  }
	  
	 
		  if(sobreSuelo()==1)
		  {
			  ++posicionp.y;
		  }
	  
		  //dibujamos mago agachado/abajo
		  //else if (cpct_isKeyPressed(Key_CursorDown)  && posicionp.y < (SCR_H - SP_H) ) {++posicionp.y;}
	  
      // Get video memory byte for coordinates x, y of the sprite (in bytes)
     pvideomem = cpct_getScreenPtr(CPCT_VMEM_START, posicionp.x, posicionp.y);
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
	  
	    //debug mostramos informaci�n de debug en pantalla
		//escribimos las coordinadas del jugador en pantalla
		  //incluimos esta funcion que transforma el texto y lo mete en la variable para poder mostrarlo por pantalla
		  if (valorx!=posicionp.x || valory!=posicionp.y)
		  {
			  valorx=posicionp.x;
			  valory=posicionp.y;
		 sprintf(debugtext, "X: %u Y: %u mapa %u", valorx,valory,sobreSuelo());
		cpct_drawStringM1(debugtext,debugmem,2,1);
		//para tener informaci�n de las coordenadas vamos a crear un cursor que podamos mover en todas las direcciones y que nos d�
		//la posici�n en la que est�, para poder hacer c�lculos m�s precisos
		  }
      
   }      
  
}


//Cargamos las fases, por cada fase ser�a necesario crear un mapa de tiles con durezas para saber si son bloques solidos o atravesables

//Cargamos la primera fase
void fase_1()
{
	
}
//la funci�n para cargar la fase de un final boss
void fase_jefe()
{
   //
}
