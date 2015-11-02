/*
 ** lightmaping.cpp
 **
 ** Made by lucas stefas
 ** Started on 03/07/14 22:47
 */

#include <RetroEngine/RetroSystem.h>
#include <SDL/SDL.h>
#include "Input.h"

int initLightmap(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Object2D		obj;
	
	RetroChangeResolution(512, 384, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	
	/*
	 * first we need 2 diferent background
	 */
	obj.posX = 0; // where it start to draw on X axy's
	obj.posY = 0; // where it start to draw on Y axy's
	obj.sizeX = 256; // where it end to draw on X axy's
	obj.sizeY = 384; // where it end to draw on Y axy's
	RetroCreateDrawable2D(0, &obj, BACKGROUND, api); //sending the sprite to your engine
	RetroAddDrawable2DColor(0, RETRO_COLOR_BLACK, RETRO_ALL_CONER_COLOR, BACKGROUND, api); // black for the lightmaping
	
	obj.posX = 256;
	obj.posY = 0;
	obj.sizeX = 256;
	obj.sizeY = 384;
	RetroCreateDrawable2D(1, &obj, BACKGROUND, api);
	
	/*
	 * now 3 light
	 */
	obj.posX = 0;
	obj.posY = 50 + 96;
	obj.sizeX = 64;
	obj.sizeY = 64;
	RetroCreateDrawable2D(0, &obj, LIGHTMAP, api);
	RetroAddDrawable2DColor(0, RETRO_COLOR_RED, RETRO_ALL_CONER_COLOR, LIGHTMAP, api);
	obj.posX = 192;
	obj.posY = 50 + 96;
	obj.sizeX = 64;
	obj.sizeY = 64;
	RetroCreateDrawable2D(1, &obj, LIGHTMAP, api);
	RetroAddDrawable2DColor(1, RETRO_COLOR_GREEN, RETRO_ALL_CONER_COLOR, LIGHTMAP, api);
	obj.posX = 95.5;
	obj.posY = 192 + 96;
	obj.sizeX = 64;
	obj.sizeY = 64;
	RetroCreateDrawable2D(2, &obj, LIGHTMAP, api);
	RetroAddDrawable2DColor(2, RETRO_COLOR_BLUE, RETRO_ALL_CONER_COLOR, LIGHTMAP, api);
	
	obj.posX = 256;
	obj.posY = 50 + 96;
	obj.sizeX = 64;
	obj.sizeY = 64;
	RetroCreateDrawable2D(0, &obj, SHADOWMAP, api);
	RetroAddDrawable2DColor(0, RETRO_COLOR_CYAN, RETRO_ALL_CONER_COLOR, SHADOWMAP, api);
	obj.posX = 448;
	obj.posY = 50 + 96;
	obj.sizeX = 64;
	obj.sizeY = 64;
	RetroCreateDrawable2D(1, &obj, SHADOWMAP, api);
	RetroAddDrawable2DColor(1, RETRO_COLOR_YELLOW, RETRO_ALL_CONER_COLOR, SHADOWMAP, api);
	obj.posX = 351.5f;
	obj.posY = 192 + 96;
	obj.sizeX = 64;
	obj.sizeY = 64;
	RetroCreateDrawable2D(2, &obj, SHADOWMAP, api);
	RetroAddDrawable2DColor(2, RETRO_COLOR_MAGENTA, RETRO_ALL_CONER_COLOR, SHADOWMAP, api);
	
	return (0);
}

int LightmapIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	static float	x1[2] = {0, 192};
	static float	y = 0;
	static float	x2[2] = {256, 448};
	
	if (x1[0] > 191)
		x1[0] = -1;
	x1[0] += 0.5f;
	if (x1[1] < 0)
		x1[1] = 191;
	x1[1] -= 0.5f;
	if (y < 0 + 48)
		y = 191.0f + 48;
	y -= 0.5f;
	
	if (x2[0] > 448)
		x2[0] = 256;
	x2[0] += 0.5f;
	if (x2[1] < 256)
		x2[1] = 448;
	x2[1] -= 0.5f;
	
	RetroSetDrawable2DX(0, x1[0], LIGHTMAP, api);
	RetroSetDrawable2DX(1, x1[1], LIGHTMAP, api);
	RetroSetDrawable2DY(2, y, LIGHTMAP, api);
	
	RetroSetDrawable2DX(0, x2[0], SHADOWMAP, api);
	RetroSetDrawable2DX(1, x2[1], SHADOWMAP, api);
	RetroSetDrawable2DY(2, y, SHADOWMAP, api);
	
	return (0);
}

int stopLightmap(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	(void)system;
	
	RetroDelDrawable2D(0, BACKGROUND, api);
	RetroDelDrawable2D(1, BACKGROUND, api);
	
	RetroDelDrawable2D(0, LIGHTMAP, api);
	RetroDelDrawable2D(1, LIGHTMAP, api);
	RetroDelDrawable2D(2, LIGHTMAP, api);
	
	RetroDelDrawable2D(0, SHADOWMAP, api);
	RetroDelDrawable2D(1, SHADOWMAP, api);
	RetroDelDrawable2D(2, SHADOWMAP, api);
	
	return (0);
}