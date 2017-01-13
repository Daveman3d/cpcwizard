// Data created with Img2CPC - (c) Retroworks - 2007-2015

#include <types.h>

//u8* const g_tile_tileset[1] = { 
//	g_tile_mago_simple
//};
//u8* const g_tile_tileset[1] = { 
//	g_tile_mago_simple
//};
// Tile g_tile_mago_simple: 16x16 pixels, 4x16 bytes.
/*
const u8 g_tile_mago_simpled[64] = {
	0x80, 0x70, 0xf0, 0xf0,
	0x82, 0x08, 0x00, 0xf0,
	0x81, 0x05, 0x18, 0xf0,
	0x82, 0x0a, 0x30, 0xf0,
	0x83, 0x18, 0xb0, 0xf0,
	0xc1, 0x60, 0xd0, 0xf0,
	0x80, 0x60, 0xd0, 0xf0,
	0x20, 0xf0, 0x30, 0xf0,
	0xe0, 0x00, 0x10, 0xf0,
	0xe0, 0x0f, 0x1c, 0xf0,
	0xc1, 0x05, 0x00, 0xf0,
	0xc0, 0x0a, 0x10, 0xf0,
	0xc1, 0x20, 0x10, 0xf0,
	0x82, 0x06, 0x18, 0xf0,
	0x80, 0x00, 0x00, 0xf0,
	0xc0, 0x30, 0x00, 0xf0
};
*/

// Tile g_tile_mago_simple: 12x16 pixels, 3x16 bytes.
const u8 g_tile_mago_simple[2 * 3 * 16] = {
	0x88, 0x07, 0x77, 0x08, 0xff, 0x00,
	0x88, 0x52, 0x00, 0x78, 0x00, 0xf0,
	0x88, 0x61, 0x00, 0xa5, 0x11, 0x68,
	0x88, 0x52, 0x00, 0x5a, 0x33, 0xc0,
	0x88, 0x43, 0x00, 0x79, 0x33, 0xc8,
	0xcc, 0x21, 0x00, 0xf6, 0x11, 0xec,
	0x88, 0x70, 0x00, 0xf6, 0x11, 0xec,
	0x22, 0xd0, 0x00, 0xff, 0x33, 0xc0,
	0xee, 0x10, 0x00, 0xf0, 0x11, 0xe0,
	0xee, 0x10, 0x00, 0x0f, 0x11, 0x2c,
	0xcc, 0x21, 0x00, 0xa5, 0x00, 0xf2,
	0xcc, 0x30, 0x00, 0x5a, 0x11, 0xec,
	0xcc, 0x21, 0x00, 0xf3, 0x11, 0xe0,
	0x88, 0x52, 0x00, 0x96, 0x11, 0x68,
	0x88, 0x70, 0x00, 0xf0, 0x00, 0xf0,
	0xcc, 0x30, 0x33, 0xc0, 0x00, 0xf0
};

/*
// Tile g_tile_mago_simple: 16x16 pixels, 3x16 bytes.
const u8 g_tile_mago_simpleiz[48] = {
 0xf0,0xf0,0x70,0x80,
 0xf0,0x00,0x08,0x82,
 0xf0,0x18,0x05,0x81,
 0xf0,0x30,0x0a,0x82,
 0xf0,0xb0,0x18,0x83,
 0xf0,0xd0,0x60,0xc1,
 0xf0,0xd0,0x60,0x80,
 0xf0,0x30,0xf0,0x20,
 0xf0,0x10,0x00,0xe0,
 0xf0,0x1c,0x0f,0xe0,
 0xf0,0x00,0x05,0xc1,
 0xf0,0x10,0x0a,0xc0,
 0xf0,0x10,0x20,0xc1,
 0xf0,0x18,0x06,0x82,
 0xf0,0x00,0x00,0x80, 
 0xf0,0x00,0x30,0xc0
};
*/

// Tile g_tile_mago_simple_iz: 12x16 pixels, 3x16 bytes.
const u8 g_tile_mago_simple_iz[2 * 3 * 16] = {
	0x00, 0xf0, 0x00, 0xf0, 0x00, 0xf0,
	0x00, 0xf0, 0x00, 0xe1, 0x00, 0xb4,
	0x00, 0xe1, 0x00, 0x5a, 0x00, 0x78,
	0x00, 0xf0, 0x00, 0xa5, 0x00, 0xb4,
	0x00, 0xe1, 0x00, 0x69, 0x00, 0x3c,
	0x00, 0xc3, 0x00, 0x96, 0x00, 0x78,
	0x00, 0xc3, 0x00, 0x96, 0x00, 0xf0,
	0x00, 0xf0, 0x00, 0x0f, 0x00, 0xf0,
	0x00, 0xf0, 0x00, 0xf0, 0x00, 0xf0,
	0x00, 0xc3, 0x00, 0x0f, 0x00, 0xf0,
	0x00, 0xf0, 0x00, 0x5a, 0x00, 0x78,
	0x00, 0xf0, 0x00, 0xa5, 0x00, 0xf0,
	0x00, 0xf0, 0x00, 0xb4, 0x00, 0x78,
	0x00, 0xe1, 0x00, 0x96, 0x00, 0xb4,
	0x00, 0xf0, 0x00, 0xf0, 0x00, 0xf0,
	0x00, 0xf0, 0x00, 0xf0, 0x00, 0xf0
};
// Tile g_tile_block: 16x8 pixels, 4x8 bytes.
const u8 g_tile_block[32] = {
	0x0f, 0x0f, 0x0f, 0x0f,
	0x0f, 0x0f, 0x0f, 0x0f,
	0x0f, 0x0f, 0x0f, 0x0f,
	0x0f, 0x0f, 0x0f, 0x0f,
	0x0f, 0x0f, 0x0f, 0x0f,
	0x0f, 0x0f, 0x0f, 0x0f,
	0x0f, 0x0f, 0x0f, 0x0f,
	0x0f, 0x0f, 0x0f, 0x0f
};