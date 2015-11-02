/*
** priority.cpp
**
** Made by lucas stefas
** Started on 03/07/14 22:47
*/

/*
 * priority is a little hard to show without nothing so...
 * first, you need to know that :
 * SHADOWMAP and LIGHTMAP share se same priority of 1.
 * SPRITE use a default priority of 2.
 * and finaly the BACKGROUND have a default priority of 100.
 * the smaller the number is, the higher the priority is.
 * after than that, if two or more antiti share the same
 * priority level, the first one will be draw in last.
 */

#include <RetroEngine/RetroSystem.h>
#include <SDL/SDL.h>
#include "Input.h"

int				texture = 0;

int initPriority(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Object2D		obj;

	RetroChangeResolution(480, 360, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	texture = RetroLoadBmpTexture("Font/mariopaintnt.bmp", RetroTrue, *system);
	/*
	 * now 3 sprite without changing anything
	 */
	obj.posX = 80;
	obj.posY = 0;
	obj.sizeX = 80;
	obj.sizeY = 80;
	RetroCreateDrawable2D(0, &obj, SPRITE, api);
	RetroAddDrawable2DTex(0, 8, 10, texture, SPRITE, api);
	RetroChangeFramRowDrawable2D(0, 1, 9, SPRITE, api);
	RetroAddDrawable2DColor(0, RETRO_COLOR_RED, RETRO_ALL_CONER_COLOR, SPRITE, api);
	obj.posX = 80;
	obj.posY = 140;
	obj.sizeX = 80;
	obj.sizeY = 80;
	RetroCreateDrawable2D(1, &obj, SPRITE, api);
	RetroAddDrawable2DTex(1, 8, 10, texture, SPRITE, api);
	RetroChangeFramRowDrawable2D(1, 2, 9, SPRITE, api);
	RetroAddDrawable2DColor(1, RETRO_COLOR_GREEN, RETRO_ALL_CONER_COLOR, SPRITE, api);
	obj.posX = 80;
	obj.posY = 280;
	obj.sizeX = 80;
	obj.sizeY = 80;
	RetroCreateDrawable2D(2, &obj, SPRITE, api);
	RetroAddDrawable2DTex(2, 8, 10, texture, SPRITE, api);
	RetroChangeFramRowDrawable2D(2, 3, 9, SPRITE, api);
	RetroAddDrawable2DColor(2, RETRO_COLOR_BLUE, RETRO_ALL_CONER_COLOR, SPRITE, api);
	
	/*
	 * now 3 other sprite and messing with priority
	 */
	obj.posX = 320;
	obj.posY = 0;
	obj.sizeX = 80;
	obj.sizeY = 80;
	RetroCreateDrawable2D(3, &obj, SPRITE, api);
	RetroAddDrawable2DTex(3, 8, 10, texture, SPRITE, api);
	RetroChangeFramRowDrawable2D(3, 1, 9, SPRITE, api);
	RetroAddDrawable2DColor(3, RETRO_COLOR_RED, RETRO_ALL_CONER_COLOR, SPRITE, api);
	RetroDrawable2DSetBack(3, 3, SPRITE, api); // changing priority for drawing it in first.
	obj.posX = 320;
	obj.posY = 140;
	obj.sizeX = 80;
	obj.sizeY = 80;
	RetroCreateDrawable2D(4, &obj, SPRITE, api);
	RetroAddDrawable2DTex(4, 8, 10, texture, SPRITE, api);
	RetroChangeFramRowDrawable2D(4, 2, 9, SPRITE, api);
	RetroAddDrawable2DColor(4, RETRO_COLOR_GREEN, RETRO_ALL_CONER_COLOR, SPRITE, api); // changing priority for drawing it in second.
	RetroDrawable2DSetBack(4, 4, SPRITE, api);
	obj.posX = 320;
	obj.posY = 280;
	obj.sizeX = 80;
	obj.sizeY = 80;
	RetroCreateDrawable2D(5, &obj, SPRITE, api);
	RetroAddDrawable2DTex(5, 8, 10, texture, SPRITE, api);
	RetroChangeFramRowDrawable2D(5, 3, 9, SPRITE, api);
	RetroAddDrawable2DColor(5, RETRO_COLOR_BLUE, RETRO_ALL_CONER_COLOR, SPRITE, api); // changing priority for drawing it in third.
	RetroDrawable2DSetBack(5, 5, SPRITE, api);
	
	return (0);
}

int PriorityIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	static float y1 = 0;
	static float y2 = 0;
	
	if (y1 > 280)
		y1 = -1;
	y1 += 0.5f;
	if (y2 < 0)
		y2 = 281;
	y2 -= 0.5f;
	
	RetroSetDrawable2DY(0, y1, SPRITE, api);
	RetroSetDrawable2DY(2, y2, SPRITE, api);
	RetroSetDrawable2DY(3, y1, SPRITE, api);
	RetroSetDrawable2DY(5, y2, SPRITE, api);
	
	return (0);
}

int stopPriority(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	(void)system;
	RetroDelDrawable2D(0, SPRITE, api);
	RetroDelDrawable2D(1, SPRITE, api);
	RetroDelDrawable2D(2, SPRITE, api);
	RetroDelDrawable2D(3, SPRITE, api);
	RetroDelDrawable2D(4, SPRITE, api);
	RetroDelDrawable2D(5, SPRITE, api);
	
	RetroUnloadTexture(texture, *system);
	
	return (0);
}