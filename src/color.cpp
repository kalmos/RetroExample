/*
** color.cpp
**
** Made by lucas stefas
** Started on 03/07/14 22:47
*/

#include <RetroEngine/RetroSystem.h>
#include <SDL/SDL.h>
#include "Input.h"

int initColor(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Object2D		obj;
	
	RetroChangeResolution(256, 192, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	
	/*
	 * creating 2 sprite
	 */
	obj.posX = 60; // where it start to draw on X axy's
	obj.posY = 60; // where it start to draw on Y axy's
	obj.sizeX = 60; // where it end to draw on X axy's
	obj.sizeY = 60; // where it end to draw on Y axy's
	RetroCreateDrawable2D(0, &obj, SPRITE, api); //sending the sprite to your engine
	obj.posX = 136;
	obj.posY = 60;
	obj.sizeX = 60;
	obj.sizeY = 60;
	RetroCreateDrawable2D(1, &obj, SPRITE, api);
	return (0);
}

int ColorIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	static int	tmp = 0;
	Color		color;
	
	
	if (tmp == 60)
	{
		color.RGBA [0] = rand() % 255;
		color.RGBA [1] = rand() % 255;
		color.RGBA [2] = rand() % 255;
		color.RGBA [3] = rand() % 255;
		RetroAddDrawable2DColor(0, color.allColor, RETRO_ALL_CONER_COLOR, SPRITE, api);
		color.RGBA [0] = rand() % 255;
		color.RGBA [1] = rand() % 255;
		color.RGBA [2] = rand() % 255;
		color.RGBA [3] = rand() % 255;
		RetroAddDrawable2DColor(1, color.allColor, RETRO_ALL_CONER_COLOR, SPRITE, api);
		tmp = 0;
	}
	else
		tmp += 1;
	return (0);
}

int stopColor(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	(void)system;
	RetroDelDrawable2D(0, SPRITE, api);
	RetroDelDrawable2D(1, SPRITE, api);
	return (0);
}