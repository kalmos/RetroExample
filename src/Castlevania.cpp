//
// Castlevania.cpp for Example
// 
// Made by lucas stefas
// Login   stefas_l
// 
// Started on 19/11/2014 14:35
//

#include <RetroEngine/RetroSystem.h>
#include <SDL/SDL.h>
#include "Input.h"

static Drawable2D*	CPrim = NULL;
static int			texture[2];

int initCastlevania(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Mode7 m7;
	Object2D obj;
	ComplexId cId;
	int x;
	int y;
	
	RetroChangeResolution(256, 224, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	texture[1] = RetroLoadBmpTexture("Castlevania/cEffectB.bmp", RetroTrue, *system);
	m7.textID = texture[0] = RetroLoadBmpTexture("Castlevania/castlevania.bmp", RetroTrue, *system);
	m7.posX = 0;
	m7.posY = 0;
	m7.sizeX = 256;
	m7.sizeY = 224 + 100;
	m7.textSizeX = 1119;
	m7.textSizeY = 544;
	m7.textWidth = 256;
	m7.textHeight = 224;
	RetroCreateMode7Tube(0, &m7, 1, 0, MODE7, api);
	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 256;
	obj.sizeY = 224 + 100;
	RetroCreateDrawable2D(0, &obj, SHADOWMAP, api);
	RetroAddDrawable2DTex(0, 1, 1, texture[1], SHADOWMAP, api);
	
	cId = getComplexIdItem(&(api->AllIdList[MODE7]), 0);
	
	CPrim = RetroGetDrawable2DPtr(cId.startId, MODE7, api);
	
	x = CPrim->texture->startx;
	y = CPrim->y;
	return (0);
}

int CastlevaniaIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	int tmp = 0;
	int max;
	int x;
	int y;
	ComplexId cId = getComplexIdItem(&(api->AllIdList[MODE7]), 0);
	tmp = cId.startId;
	max = tmp + cId.Size;
	
	while (tmp < max)
	{
		RetroMoveInfinitHScroll(tmp, 0.1, MODE7, api);
		tmp += 1;
	}
	
	if (input.Held.Left)
	{
		tmp = cId.startId;
		while (tmp < max)
		{
			RetroMoveInfinitVScroll(tmp, -0.1, MODE7, api);
			tmp += 1;
		}
	}
	if (input.Held.Right)
	{
		tmp = cId.startId;
		while (tmp < max)
		{
			RetroMoveInfinitVScroll(tmp, 0.1, MODE7, api);
			tmp += 1;
		}
	}
	if (input.Held.Up && CPrim->y > -99)
	{
		tmp = cId.startId;
		while (tmp < max)
		{
			RetroMoveDrawable2DY(tmp, -60, MODE7, api);
			tmp += 1;
		}
		RetroMoveDrawable2DY(0, -60, SHADOWMAP, api);
	}
	
	if (input.Held.Down && CPrim->y < 0)
	{
		tmp = cId.startId;
		while (tmp < max)
		{
			RetroMoveDrawable2DY(tmp, 60, MODE7, api);
			tmp += 1;
		}
		RetroMoveDrawable2DY(0, 60, SHADOWMAP, api);
	}
	
	x = (int)(CPrim->texture->startx * 1119) % 1119;
	y = CPrim->y;
	return (0);
}

int stopCastlevania(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	RetroDeleteMode7(0, MODE7, api);
	RetroDelDrawable2D(0, SHADOWMAP, api);
	RetroUnloadTexture(texture[0], *system);
	RetroUnloadTexture(texture[1], *system);
	return (0);
}