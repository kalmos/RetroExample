/*
 ** moving.cpp
 **
 ** Made by lucas stefas
 ** Started on 03/07/14 22:47
 */

#include <RetroEngine/RetroSystem.h>
#include <SDL/SDL.h>
#include "Input.h"

int	initMoving(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Object2D		obj;
	
	RetroChangeResolution(512, 384, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	
	/*
	 * creating 8 sprite
	 */
	obj.posX = 0; // where it start to draw on X axy's
	obj.posY = 50; // where it start to draw on Y axy's
	obj.sizeX = 50; // where it end to draw on X axy's
	obj.sizeY = 50; // where it end to draw on Y axy's
	RetroCreateDrawable2D(0, &obj, SPRITE, api); //sending the sprite to your engine
	RetroAddDrawable2DColor(0, RETRO_COLOR_RED, RETRO_ALL_CONER_COLOR, SPRITE, api); // and make it red for easili finding it
	obj.posX = 150;
	obj.posY = 50;
	obj.sizeX = 50;
	obj.sizeY = 50;
	RetroCreateDrawable2D(1, &obj, SPRITE, api);
	RetroAddDrawable2DColor(1, RETRO_COLOR_GREEN, RETRO_ALL_CONER_COLOR, SPRITE, api); // and make it green for easili finding it
	obj.posX = 0;
	obj.posY = 200;
	obj.sizeX = 50;
	obj.sizeY = 50;
	RetroCreateDrawable2D(2, &obj, SPRITE, api);
	RetroAddDrawable2DColor(2, RETRO_COLOR_BLUE, RETRO_ALL_CONER_COLOR, SPRITE, api); // and make it blue for easili finding it
	obj.posX = 150;
	obj.posY = 200;
	obj.sizeX = 50;
	obj.sizeY = 50;
	RetroCreateDrawable2D(3, &obj, SPRITE, api);
	
	
	obj.posX = 462; // where it start to draw on X axy's
	obj.posY = 50; // where it start to draw on Y axy's
	obj.sizeX = 50; // where it end to draw on X axy's
	obj.sizeY = 50; // where it end to draw on Y axy's
	RetroCreateDrawable2D(4, &obj, SPRITE, api); //sending the sprite to your engine
	RetroAddDrawable2DColor(4, RETRO_COLOR_YELLOW, RETRO_ALL_CONER_COLOR, SPRITE, api); // and make it yellow for easili finding it
	obj.posX = 312;
	obj.posY = 50;
	obj.sizeX = 50;
	obj.sizeY = 50;
	RetroCreateDrawable2D(5, &obj, SPRITE, api);
	RetroAddDrawable2DColor(5, RETRO_COLOR_CYAN, RETRO_ALL_CONER_COLOR, SPRITE, api); // and make it cyan for easili finding it
	obj.posX = 462;
	obj.posY = 200;
	obj.sizeX = 50;
	obj.sizeY = 50;
	RetroCreateDrawable2D(6, &obj, SPRITE, api);
	RetroAddDrawable2DColor(6, RETRO_COLOR_MAGENTA, RETRO_ALL_CONER_COLOR, SPRITE, api); // and make it magenta for easili finding it
	obj.posX = 312;
	obj.posY = 200;
	obj.sizeX = 50;
	obj.sizeY = 50;
	RetroCreateDrawable2D(7, &obj, SPRITE, api);
	RetroAddDrawable2DColor(7, 0x80808000, RETRO_ALL_CONER_COLOR, SPRITE, api); // and make it gray for easili finding it
	
	return (0);
}

int MovingIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	static int		x = 0;
	static int		y = 50;
	static float	angle = 0;
	static float	angle2 = 0;
	
	/*
	 * basic calcul for slowi moving the red one and moving it
	 */
	if (x > 150)
		x = -1;
	x += 1;
	if (y > 200)
		y = 49;
	y += 1;
	RetroSetDrawable2DXY(0, x, y, SPRITE, api); // actualy move the red square
	RetroSetDrawable2DY(1, y, SPRITE, api); // actualy move the green square
	RetroSetDrawable2DX(2, x, SPRITE, api); // actualy move the blue square
	
	if (angle > 360.0f)
		angle = -1.0f;
	angle += 0.6f;
	RetroRotateFromZ(3, angle, SPRITE, api);
	
	RetroAddDrawable2DXY(4, -1, 1, SPRITE, api);
	RetroAddDrawable2DY(5, 1, SPRITE, api);
	RetroAddDrawable2DX(6, -1, SPRITE, api);
	
	if (RetroGetDrawable2DX(4, SPRITE, api) < 312 && RetroGetDrawable2DY(4, SPRITE, api) > 200)
		RetroSetDrawable2DXY(4, 462, 50, SPRITE, api);
	if (RetroGetDrawable2DY(5, SPRITE, api) > 200)
		RetroSetDrawable2DY(5, 50, SPRITE, api);
	if (RetroGetDrawable2DX(6, SPRITE, api) < 312)
		RetroSetDrawable2DX(6, 462, SPRITE, api);
	
	if (angle2 < -360.0f)
		angle2 = 1.0f;
	angle2 -= 0.6f;
	RetroRotateFromZ(7, angle2, SPRITE, api);
	
	return (0);
}

int stopMoving(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	(void)system;
	RetroDelDrawable2D(0, SPRITE, api);
	RetroDelDrawable2D(1, SPRITE, api);
	RetroDelDrawable2D(2, SPRITE, api);
	RetroDelDrawable2D(3, SPRITE, api);
	RetroDelDrawable2D(4, SPRITE, api);
	RetroDelDrawable2D(5, SPRITE, api);
	RetroDelDrawable2D(6, SPRITE, api);
	RetroDelDrawable2D(7, SPRITE, api);
	return (0);
}