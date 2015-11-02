/*
** texture.cpp
**
** Made by lucas stefas
** Started on 03/07/14 22:47
*/


#include <RetroEngine/RetroSystem.h>
#include <SDL/SDL.h>
#include <string>
#include "Input.h"

static int	texture1 = 0;
static int	texture2 = 0;

int initTexture(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Object2D		obj;
	
	RetroChangeResolution(640, 480, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	
	/*
	 * loading our texture
	 */
	texture1 = RetroLoadBmpTexture("Other/megaman.bmp", RetroTrue, *system);
	texture2 = RetroLoadBmpTexture("Other/zelda.bmp", RetroTrue, *system);
	
	/*
	 * creating 4 sprite
	 */
	obj.posX = 64; // where it start to draw on X axy's
	obj.posY = 64; // where it start to draw on Y axy's
	obj.sizeX = 64; // where it end to draw on X axy's
	obj.sizeY = 64; // where it end to draw on Y axy's
	RetroCreateDrawable2D(0, &obj, SPRITE, api); //sending the sprite to your engine
	RetroAddDrawable2DTex(0, 3, 4, texture1, SPRITE, api);
	
	obj.posX = 512;
	obj.posY = 64;
	obj.sizeX = 64;
	obj.sizeY = 64;
	RetroCreateDrawable2D(1, &obj, SPRITE, api);
	RetroAddDrawable2DTex(1, 3, 4, texture1, SPRITE, api);
	RetroChangeRowDrawable2D(1, 2, SPRITE, api); // for changing the state.
	
	obj.posX = 64;
	obj.posY = 352;
	obj.sizeX = 64;
	obj.sizeY = 64;
	RetroCreateDrawable2D(2, &obj, SPRITE, api);
	RetroAddDrawable2DTex(2, 3, 4, texture1, SPRITE, api);
	RetroChangeRowDrawable2D(2, 2, SPRITE, api);
	RetroSetDrawable2DVFlip(2, SPRITE, api); // just to flip it.
	
	obj.posX = 512;
	obj.posY = 352;
	obj.sizeX = 64;
	obj.sizeY = 64;
	RetroCreateDrawable2D(3, &obj, SPRITE, api);
	RetroAddDrawable2DTex(3, 3, 4, texture1, SPRITE, api);
	RetroChangeRowDrawable2D(3, 3, SPRITE, api);
	RetroStartAnimDrawable2D(3, 1, 4, RetroTrue, 7, SPRITE, api); //for starting an animation.
	
	/*
	 * now two background just to show the infinit scroll system
	 */
	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 320;
	obj.sizeY = 480;
	RetroCreateDrawable2D(0, &obj, BACKGROUND, api);
	RetroAddDrawable2DTex(0, 1, 1, texture2, BACKGROUND, api);
	
	obj.posX = 320;
	obj.posY = 0;
	obj.sizeX = 320;
	obj.sizeY = 480;
	RetroCreateDrawable2D(1, &obj, BACKGROUND, api);
	RetroAddDrawable2DTex(1, 1, 1, texture2, BACKGROUND, api);
	
	/*
	 * seting the scroll ofset for each background part
	 */
	RetroUseHasInfinitHScroll(0, 0, BACKGROUND, api);
	RetroUseHasInfinitVScroll(1, 0, BACKGROUND, api);
	
	return (0);
}

int TextureIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	/*
	 * seting the scroll ofset for each background part
	 */
	RetroAddInfinitHScroll(0, 0.005, BACKGROUND, api);
	RetroAddInfinitVScroll(1, 0.005f, BACKGROUND, api);
	
	return (0);
}



int stopTexture(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	RetroDelDrawable2D(0, SPRITE, api);
	RetroDelDrawable2D(1, SPRITE, api);
	RetroDelDrawable2D(2, SPRITE, api);
	RetroDelDrawable2D(3, SPRITE, api);
	
	RetroDelDrawable2D(0, BACKGROUND, api);
	RetroDelDrawable2D(1, BACKGROUND, api);
	
	RetroUnloadTexture(texture1, *system);
	RetroUnloadTexture(texture2, *system);
	return (0);
}