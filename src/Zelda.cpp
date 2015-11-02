//
// Zelda.cpp for Example
// 
// Made by lucas stefas
// Login   stefas_l
// 
// Started on 21/11/2014 15:05
//

#include <RetroEngine/RetroSystem.h>
#include <SDL/SDL.h>
#include "Input.h"

static Drawable2D* ZPrim = NULL;

static int texture;

int initZelda(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Mode7 m7;
	ComplexId cId;
	int tmp;
	int max;
	
	RetroChangeResolution(256, 224, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	m7.textID = texture = RetroLoadBmpTexture("Zelda/zeldaMap.bmp", RetroTrue, *system);
	m7.posX = 10;
	m7.posY = 10;
	m7.sizeX = 256 * 8;
	m7.sizeY = 224 * 3.6f;
	m7.textSizeX = 1024 * 8;
	m7.textSizeY = 1024 * 3.6f;
	m7.textWidth = 1024 * 8;
	m7.textHeight = 1024 * 3.6f;
	RetroCreateMode7Plan(0, &m7, 3, 0, MODE7, api);
	
	cId = getComplexIdItem(&(api->AllIdList[MODE7]), 0);
	
	ZPrim = RetroGetDrawable2DPtr(cId.startId, MODE7, api);
	
	tmp = cId.startId;
	max = tmp + cId.Size;
	
	while (tmp < max)
	{
		RetroAddInfinitHScroll(tmp, 1.0f, MODE7, api);
		RetroAddInfinitVScroll(tmp, 0.5f, MODE7, api);
		RetroAddDrawable2DXY(tmp, -896, -281.2, MODE7, api);
		tmp += 1;
	}
	
	return (0);
}

int ZeldaIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	int x = 0;
	int y = 0;
	int tmp;
	int max;
	
	x = ZPrim->x;
	y = ZPrim->y;
	
	ComplexId cId = getComplexIdItem(&(api->AllIdList[MODE7]), 0);
	tmp = cId.startId;
	max = tmp + cId.Size;
	
	if (input.Held.Up && y < -170)
	{
		tmp = cId.startId;
		while (tmp < max)
		{
			RetroMoveDrawable2DY(tmp, 120, MODE7, api);
			tmp += 1;
		}
	}
	if (input.Held.Down && y > -436)
	{
		tmp = cId.startId;
		while (tmp < max)
		{
			RetroMoveDrawable2DY(tmp, -120, MODE7, api);
			tmp += 1;
		}
	}
	if (input.Held.Left && x < -454)
	{
		tmp = cId.startId;
		while (tmp < max)
		{
			RetroMoveDrawable2DX(tmp, 120, MODE7, api);
			tmp += 1;
		}
	}
	if (input.Held.Right && x > -1284)
	{
		tmp = cId.startId;
		while (tmp < max)
		{
			RetroMoveDrawable2DX(tmp, -120, MODE7, api);
			tmp += 1;
		}
	}
	
	x = ZPrim->x;
	y = ZPrim->y;
	return (0);
}

int stopZelda(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	RetroDeleteMode7(0, MODE7, api);
	RetroUnloadTexture(texture, *system);
	
	return (0);
}