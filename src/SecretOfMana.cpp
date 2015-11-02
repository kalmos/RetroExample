//
// F-Zero.cpp for Example
// 
// Made by lucas stefas
// Login   stefas_l
// 
// Started on 19/11/2014 14:35
//

#include <math.h>
#include <RetroEngine/RetroSystem.h>
#include <SDL/SDL.h>
#include "Input.h"


static Drawable2D*	SOMPrim;
static int			rot = 0;
static float		speedX = 0;
static float		speedY = 0.1;
static int			texture[4];

int initSecretOfMana(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Mode7 m7;
	Object2D obj;
	ComplexId cId;
	int x;
	int y;
	
	speedX = 0;
	speedY = 0.1;
	rot = 0;
	
	RetroChangeResolution(256, 224, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	
	texture[1] = RetroLoadBmpTexture("SecretOfMana/SeikenDensetsu3Effect.bmp", RetroTrue, *system);
	texture[2] = RetroLoadBmpTexture("SecretOfMana/SeikenDensetsu3Cloud2.bmp", RetroTrue, *system);
	texture[3] = RetroLoadBmpTexture("SecretOfMana/seikenDensetsu3Cloud.bmp", RetroTrue, *system);
	m7.textID = texture[0] = RetroLoadBmpTexture("SecretOfMana/SeikenDensetsu3Map.bmp", RetroTrue, *system);
	m7.posX = 0;
	m7.posY = 0;
	m7.sizeX = 256;
	m7.sizeY = 224;
	m7.textSizeX = 2048;
	m7.textSizeY = 2048;
	m7.textWidth = 256;
	m7.textHeight = 224;
	RetroCreateMode7Plan(0, &m7, 10, 10, MODE7, api);

	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 256;
	obj.sizeY = 68;
	RetroCreateDrawable2D(0, &obj, BACKGROUND, api);
	RetroAddDrawable2DTex(0, 3, 1, texture[2], BACKGROUND, api);
	obj.sizeY = 64;
	RetroCreateDrawable2D(1, &obj, LIGHTMAP, api);
	RetroAddDrawable2DTex(1, 3, 1, texture[3], LIGHTMAP, api);
	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 256;
	obj.sizeY = 224;
	RetroCreateDrawable2D(0, &obj, LIGHTMAP, api);
	RetroAddDrawable2DTex(0, 1, 1, texture[1], LIGHTMAP, api);
	cId = getComplexIdItem(&(api->AllIdList[MODE7]), 0);
	SOMPrim = RetroGetDrawable2DPtr(cId.startId, MODE7, api);
	
	x = (int)(SOMPrim->texture->startx * 2048) % 2048;
	y = (int)(SOMPrim->texture->starty * 2048) % 2048;
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	return (0);
}

int SecretOfManaIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	int tmp;
	int max;
	int x;
	int y;
	float rad;
	ComplexId cId = getComplexIdItem(&(api->AllIdList[MODE7]), 0);
	tmp = cId.startId;
	max = tmp + cId.Size;
	if (input.Held.Up)
	{
		while (tmp < max)
		{
			RetroMoveInfinitScroll(tmp, speedX, -speedY, MODE7, api);
			tmp += 1;
		}
	}
	if (input.Held.Down)
	{
		while (tmp < max)
		{
			RetroMoveInfinitScroll(tmp, -speedX, speedY, MODE7, api);
			tmp += 1;
		}
	}
	if (input.Held.Left)
	{
		RetroTextureRotateMode7(0, rot, MODE7, api);
		RetroMoveInfinitVScroll(1, -(1.0f / 512.0 * 360.f), LIGHTMAP, api);
		RetroMoveInfinitVScroll(0, -(1.0f / 1024.0f * 360.f), BACKGROUND, api);
		rot -= 2;
		rad = (float)((M_PI * (float)rot) / 180.0f);
		speedX = sin(rad) * 0.1f;
		speedY = cos(rad) * 0.1f;
	}
	if (input.Held.Right)
	{
		RetroTextureRotateMode7(0, rot, MODE7, api);
		RetroMoveInfinitVScroll(1, 1.0f / 512.0f * 360.f, LIGHTMAP, api);
		RetroMoveInfinitVScroll(0, 1.0f / 1024.0f * 360.f, BACKGROUND, api);
		rot += 2;
		rad = (float)((M_PI * (float)rot) / 180.0f);
		speedX = sin(rad) * 0.1f;
		speedY = cos(rad) * 0.1f;
	}
	x = (int)(SOMPrim->texture->startx * 2048) % 2048;
	y = (int)(SOMPrim->texture->starty * 2048) % 2048;
	return (0);
}

int stopSecretOfMana(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	RetroDeleteMode7(0, MODE7, api);
	RetroDelDrawable2D(0, BACKGROUND, api);
	RetroDelDrawable2D(1, LIGHTMAP, api);
	RetroDelDrawable2D(0, LIGHTMAP, api);
	
	RetroUnloadTexture(texture[0], *system);
	RetroUnloadTexture(texture[1], *system);
	RetroUnloadTexture(texture[2], *system);
	RetroUnloadTexture(texture[3], *system);
	return (0);
}