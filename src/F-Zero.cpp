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
#include <string>
#include "Input.h"
#include <iostream>

static Drawable2D*	FZPrim;
static int			rot = 0;
static float		speedX = 0;
static float		speedY = 0.1;
static int			texture[12];
static float tMapSize[2] = {860, 860};
static float tSet[2] = {1.0f / 19.0f, 1.0f / 19.0f};
static int frm = 0;
static Shader* shader = NULL;

int initF_Zero(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Mode7 m7;
	Object2D obj;
	ComplexId cId;
	float ratio = 1.0f;
	int ids = 0;

	shader = newShader();
	RetroChangeResolution(256, 224, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	
	speedX = 0;
	speedY = 0.1;
	rot = 0;
	
	texture[0] = RetroLoadBmpTexture("F-Zero/FMap.bmp", RetroTrue, *system);
	texture[1] = RetroLoadBmpTexture("F-Zero/Fset.bmp", RetroTrue, *system);
	texture[9] = RetroLoadBmpTexture("F-Zero/trueBack.bmp", RetroTrue, *system);
	texture[10] = RetroLoadBmpTexture("F-Zero/front.bmp", RetroTrue, *system);
	texture[11] = RetroLoadBmpTexture("F-Zero/effect.bmp", RetroTrue, *system);
	
	m7.posX = 0;
	m7.posY = 0;
	m7.sizeX = 256;
	m7.sizeY = 224;
	m7.textSizeX = 6880;
	m7.textSizeY = 6880;
	m7.textWidth = 64;
	m7.textHeight = 56;
	
	
	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 256;
	obj.sizeY = 224;

	
	RetroCreateMode7Plan(0, &m7, 36 * ratio, 36, TILEMAP7, api);
	RetroAddDrawable2DTex(0, 1, 1, texture[0], TILEMAP7, api);
	
	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 256;
	obj.sizeY = 47;
	RetroCreateDrawable2D(0, &obj, BACKGROUND, api);
	RetroAddDrawable2DTex(0, 3, 1, texture[9], BACKGROUND, api);
	obj.sizeY = 43;
	RetroCreateDrawable2D(1, &obj, BACKGROUND, api);
	RetroAddDrawable2DTex(1, 3, 1, texture[10], BACKGROUND, api);
	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 256;
	obj.sizeY = 224;
	RetroCreateDrawable2D(0, &obj, LIGHTMAP, api);
	RetroAddDrawable2DTex(0, 1, 1, texture[11], LIGHTMAP, api);
	cId = getComplexIdItem(&(api->AllIdList[TILEMAP7]), 0);
	FZPrim = RetroGetDrawable2DPtr(cId.startId, TILEMAP7, api);
	
	shader->program = api->program;
	addShaderTexture(shader, texture[0], "tileMap");
	addShaderTexture(shader, texture[1], "tileSet");
	addShaderVariable(shader, "tileMapSize", (void*)(tMapSize), UNIFORM_2F);
	addShaderVariable(shader, "tileSize", (void*)(tSet), UNIFORM_2F);
	addShaderVariable(shader, "fram", (void*)&(frm), UNIFORM_1I);
	
	retroAttachShader(0 , shader, TILEMAP7, api);
	
	while (ids <= cId.Size)
	{
		RetroAddInfinitScroll(ids + cId.startId, 1129.0f / 3488.0f, 4523.0f / 6880.0f, TILEMAP7, api);
		ids += 1;
	}
	return (0);
}

int F_ZeroIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	int tmp;
	int max;
	int x;
	int y;
	float rad;
	static int anim = 1;
	static int count = 0;
	
	ComplexId cId = getComplexIdItem(&(api->AllIdList[TILEMAP7]), 0);
	tmp = cId.startId;
	max = tmp + cId.Size;
	
	if (input.Held.Up)
	{
		while (tmp < max)
		{
			RetroMoveInfinitScroll(tmp, speedX, -speedY, TILEMAP7, api);
			tmp += 1;
		}
	}
	if (input.Held.Down)
	{
		while (tmp < max)
		{
			RetroMoveInfinitScroll(tmp, -speedX, speedY, TILEMAP7, api);
			tmp += 1;
		}
	}
	if (input.Held.Left)
	{
		RetroTextureRotateMode7(0, rot, TILEMAP7, api);
		RetroMoveInfinitVScroll(1, -(1.0f / 512.0 * 360.f), BACKGROUND, api);
		RetroMoveInfinitVScroll(0, -(1.0f / 1024.0f * 360.f), BACKGROUND, api);
		rot -= 2;
		rad = (float)((M_PI * (float)rot) / 180.0f);
		speedX = sin(rad) * 0.05f;
		speedY = cos(rad) * 0.05f;
	}
	if (input.Held.Right)
	{
		RetroTextureRotateMode7(0, rot, TILEMAP7, api);
		RetroMoveInfinitVScroll(1, 1.0f / 512.0f * 360.f, BACKGROUND, api);
		RetroMoveInfinitVScroll(0, 1.0f / 1024.0f * 360.f, BACKGROUND, api);
		rot += 2;
		rad = (float)((M_PI * (float)rot) / 180.0f);
		speedX = sin(rad) * 0.05f;
		speedY = cos(rad) * 0.05f;
	}
	
	
	if (count == 2)
	{
		anim += 1;
		if (anim == 9)
			anim = 1;
		frm += 1;
		count = 0;
	}
	
	count += 1;
	
	x = (int)(FZPrim->texture->startx * 3488) % 3488;
	y = (int)(FZPrim->texture->starty * 6880) % 6880;
	
	return (0);
}

int stopF_Zero(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	RetroDeleteMode7(0, TILEMAP7, api);
	RetroDelDrawable2D(0, BACKGROUND, api);
	RetroDelDrawable2D(1, BACKGROUND, api);
	RetroDelDrawable2D(0, LIGHTMAP, api);
	
	RetroUnloadTexture(texture[0], *system);
	RetroUnloadTexture(texture[1], *system);
	RetroUnloadTexture(texture[9], *system);
	RetroUnloadTexture(texture[10], *system);
	RetroUnloadTexture(texture[11], *system);
	
	deleteShader(shader);
	
	return (0);
}