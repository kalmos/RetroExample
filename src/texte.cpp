/*
** texte.cpp
**
** Made by lucas stefas
** Started on 09/11/14 13:01
*/

#include <RetroEngine/RetroSystem.h>
#include <RetroEngine/Retro2DApi.h>
#include <SDL/SDL.h>
#include "Input.h"

int initTexte(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Object2D	obj;
	RetroChangeResolution(800, 600, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	
	/*
	 * loading different police
	 */
	RetroAddFont(0, "1234567890\nABCDEFGHIJ\nKLMNOPQRST\nUVWXYZ ?'\"\n\n\n\n\n", "font/policeMario64.bmp", *system);
	RetroAddFont(1, "1234567890\nABCDEFGHIJ\nKLMNOPQRST\nUVWXYZ ?'\"\nµ\n\n\n\n", "font/policeMario64Transparent.bmp", *system);
	RetroAddFont(2, "ABCDEFGHIJKLMNOPQRSTUVWXYZ\nabcdefghijklmnopqrstuvwxyz\n1234567890.,:!?'~-*\t&()\"“ \n\n", "font/policeMario64Alternate.bmp", *system);
	
	/*
	 * writing 3 hello world
	 */
	 obj.posX = 44;
	obj.posY = 190;
	obj.sizeX = 44;
	obj.sizeY = 44;
	RetroWrite(0, "'HELLO WORLD'", &obj, 0, api); // just a hello world
	
	obj.posX = 0;
	obj.posY = 278;
	obj.sizeX = 44;
	obj.sizeY = 44;
	RetroWrite(1, "'HELLO WORLD µ' ", &obj, 1, api); // hello world with utf8 char
	obj.posX = 0;
	obj.posY = 366;
	obj.sizeX = 44;
	obj.sizeY = 44;
	RetroWrite(2, "Hello World \"%d\"", &obj, 2, api, 42); // hello world with variable.
	
	/*
	 * and a weird background to show transparent font
	 */
	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 800;
	obj.sizeY = 600;
	RetroCreateDrawable2D(0, &obj, BACKGROUND, api);
	RetroAddDrawable2DColor(0, RETRO_COLOR_RED, RETRO_UP_LEFT_COLOR, BACKGROUND, api);
	RetroAddDrawable2DColor(0, RETRO_COLOR_GREEN, RETRO_UP_RIGHT_COLOR, BACKGROUND, api);
	RetroAddDrawable2DColor(0, RETRO_COLOR_BLUE, RETRO_DOWN_LEFT_COLOR, BACKGROUND, api);
	RetroAddDrawable2DColor(0, RETRO_COLOR_WHITE, RETRO_DOWN_RIGHT_COLOR, BACKGROUND, api);
	return (0);
}

int TexteIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	(void)api;
	return (0);
}

int stopTexte(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	RetroDeleteText(0, api);
	RetroDeleteText(1, api);
	RetroDeleteText(2, api);
	RetroDeleteFont(0, *system);
	RetroDeleteFont(1, *system);
	RetroDeleteFont(2, *system);
	RetroDelDrawable2D(0, BACKGROUND, api);
	return (0);
}