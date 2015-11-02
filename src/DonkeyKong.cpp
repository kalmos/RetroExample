//
// DonkeyKong.cpp for Example
// 
// Made by lucas stefas
// Login   stefas_l
// 
// Started on 19/11/2014 14:36
//

#include <RetroEngine/RetroSystem.h>
#include <SDL/SDL.h>
#include "Input.h"

static Drawable2D*	DKPrim;
static int			texture[2];

void setBackSPecial(int i, Drawable2D* d2D, void* param)
{
	(void)i;
	d2D->z = -*(int*)&param;
}

void distortion(int i, Drawable2D* d2D, void* param)
{
	int test = 0;
	while (test < 50)
	{
		if (!((i + *(int*)&param + test)% 100))
		{
			d2D->texture->rotx[0] = 0.00048828125f;
			d2D->texture->rotx[1] = 0.00048828125f;
			d2D->texture->rotx[2] = -0.00048828125f;
			d2D->texture->rotx[3] = -0.00048828125f;
			return ;
		}
		test += 1;
	}
	d2D->texture->rotx[0] = 0;
	d2D->texture->rotx[1] = 0;
	d2D->texture->rotx[2] = 0;
	d2D->texture->rotx[3] = 0;
}

int initDonkeyKong(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Mode7 m7;
	Object2D obj;
	int x;
	int y;
	int tmp;
	int max;
	ComplexId cId;
	
	RetroChangeResolution(256, 224, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	texture[1] = RetroLoadBmpTexture("DonkeyKong/dk.bmp", RetroTrue, *system);
	m7.textID = texture[0] = RetroLoadBmpTexture("DonkeyKong/dkf.bmp", RetroTrue, *system);
	m7.posX = 0;
	m7.posY = 0;
	m7.sizeX = 256;
	m7.sizeY = 224;
	m7.textSizeX = 2048;
	m7.textSizeY = 1920;
	m7.textWidth = 256;
	m7.textHeight = 224;
	RetroCreateMode7(0, &m7, MODE7,api);
	RetroSpecialMode7(0, setBackSPecial, (void*)2, MODE7, api);
	
	cId = getComplexIdItem(&(api->AllIdList[MODE7]), 0);
	tmp = cId.startId;
	max = tmp + cId.Size;
	
	DKPrim = RetroGetDrawable2DPtr(cId.startId, MODE7, api);
	
	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 256;
	obj.sizeY = 224;
	RetroCreateDrawable2D(0, &obj, BACKGROUND, api);
	RetroAddDrawable2DTex(0, 1, 1, texture[1], BACKGROUND, api);
	
	while (tmp < max)
	{
		RetroAddInfinitHScroll(tmp, 1643.0f / 1920.f, MODE7, api);
		tmp += 1;
	}
	
	x = (int)(DKPrim->texture->startx * 2048) % 2048;
	y = (int)(DKPrim->texture->starty * 1920) % 1920;

	return (0);
}

int DonkeyKongIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	static int effect = 0;
	int tmp;
	int max;
	int x;
	int y;
	ComplexId cId = getComplexIdItem(&(api->AllIdList[MODE7]), 0);
	tmp = cId.startId;
	max = tmp + cId.Size;
	
	if (input.Held.Up && DKPrim->texture->starty > 0)
	{
		tmp = cId.startId;
		while (tmp < max)
		{
			RetroMoveInfinitHScroll(tmp, -0.1, MODE7, api);
			tmp += 1;
		}
	}
	if (input.Held.Down && DKPrim->texture->starty * 1920 < 1696)
	{
		tmp = cId.startId;
		while (tmp < max)
		{
			RetroMoveInfinitHScroll(tmp, 0.1, MODE7, api);
			tmp += 1;
		}
	}
	if (input.Held.Left  && DKPrim->texture->startx > 0)
	{
		tmp = cId.startId;
		while (tmp < max)
		{
			RetroMoveInfinitVScroll(tmp, -0.1, MODE7, api);
			tmp += 1;
		}
	}
	if (input.Held.Right && DKPrim->texture->endx * 2048 < 2048)
	{
		tmp = cId.startId;
		while (tmp < max)
		{
			RetroMoveInfinitVScroll(tmp, 0.1, MODE7, api);
			tmp += 1;
		}
	}
	
	RetroSpecialMode7(0, distortion, (void*)effect, MODE7, api);
	effect += 1;
	
	x = (int)(DKPrim->texture->startx * 2048);
	y = (int)(DKPrim->texture->starty * 1920);
	
	return (0);
}

int stopDonkeyKong(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	RetroDeleteMode7(0, MODE7, api);
	RetroDelDrawable2D(0, BACKGROUND, api);
	RetroUnloadTexture(texture[0], *system);
	RetroUnloadTexture(texture[1], *system);
	
	return (0);
}