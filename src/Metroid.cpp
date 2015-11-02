//
// Metroid.cpp for Example
// 
// Made by lucas stefas
// Login   stefas_l
// 
// Started on 18/07/2015 16:20
//

#include <iostream>

#include <RetroEngine/RetroSystem.h>
#include <RetroEngine/RetroColider.h>
#include <RetroEngine/GravityMotor.h>
#include <SDL/SDL.h>
#include "Input.h"
#include "metroidBack.h"



#	include <RetroEngine/Vector.h>

static int texture[5];
static Drawable2D* scrollElem[3];
static Drawable2D* samus;
static GravityMotor motorX1 = {0, 0, 0, 4.0f, 1.0f, 1, 1};
static GravityMotor motorX2 = {0, 0, 0, 1.0f, 2.0f, 1, 1};
static GravityMotor motorY1 = {0, 0, 3 * M_PI / 2.0f, 4.0f, 1.0f, 1, 1};
static GravityMotor motorY2 = {0, 0, 3 * M_PI / 2.0f, 1.0f, 2.0f, 1, 1};

static Retro_Colider* col;

static Shader* shader = NULL;
static float tMapSize[2] = {16, 56};
static float tSet[2] = {1.0f / 5.0f, 1.0f / 5.0f};


static unsigned int i1 = 0;
static unsigned int i2 = 0;
static RetroTileColider* tCol;

static int samusAnim = 1;
static int samusSpeed = 20;

#define METROIDE_TILE_SIZE_X 16
#define METROIDE_TILE_SIZE_Y 16

int initMetroid(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Object2D		obj;
	
	shader = newShader();
	
	texture[0] = RetroLoadBmpTexture("Metroid/Water.bmp", RetroTrue, *system);
	texture[1] = RetroLoadBmpTexture("Metroid/front2.bmp", RetroTrue, *system);
	texture[2] = RetroLoadBmpTexture("Metroid/Green_Brinstar_Shaft.bmp", RetroTrue, *system);
	texture[3] = RetroLoadBmpTexture("Metroid/samusComplet.bmp", RetroTrue, *system);
	texture[4] = RetroLoadBmpTexture("ToDo.bmp", RetroTrue, *system);
	
	glGenTextures(1, &i1);
	glBindTexture(GL_TEXTURE_2D, i1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 80, 80, 0, GL_RGBA, GL_UNSIGNED_BYTE, metroidBackPal);
	ONLYPC1;
	glGenTextures(1, &i2);
	glBindTexture(GL_TEXTURE_2D, i2);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 16, 56, 0, GL_RGBA, GL_UNSIGNED_BYTE, metroidBackMap);
	ONLYPC1;
	
	RetroChangeResolution(256, 224, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	
	/*
	 * creating 2 sprite
	 */
	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 256;
	obj.sizeY = 512;
	scrollElem[0] = RetroCreateDrawable2D(0, &obj, BACKGROUND, api); //sending the sprite to your engine
	RetroAddDrawable2DTex(0, 1, 1, texture[2], BACKGROUND, api);
	
	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 256;
	obj.sizeY = 896;
	scrollElem[1] = RetroCreateDrawable2D(0, &obj, TILEMAP, api); //sending the sprite to your engine
	RetroAddDrawable2DTex(0, 1, 1, i1, TILEMAP, api);
	
	
	obj.posX = 0;
	obj.posY = 672;
	obj.sizeX = 256;
	obj.sizeY = 224;
	scrollElem[2] = RetroCreateDrawable2D(0, &obj, LIGHTMAP, api); //sending the sprite to your engine
	RetroAddDrawable2DTex(0, 1, 1, texture[0], LIGHTMAP, api);
	
	obj.posX = 115;
	obj.posY = 45;
	obj.sizeX = 35;
	obj.sizeY = 48;
	samus = RetroCreateDrawable2D(1, &obj, SPRITE, api); //sending the sprite to your engine
	RetroAddDrawable2DTex(1, 8, 10, texture[3], SPRITE, api);
	
	obj.posX = 115;
	obj.posY = 45;
	obj.sizeX = 26;
	obj.sizeY = 43;
	samus = RetroCreateDrawable2D(0, &obj, SPRITE, api); //sending the sprite to your engine
	RetroAddDrawable2DTex(0, 1, 1, texture[4], SPRITE, api);
	
	RetroChangeRowDrawable2D(0, 7, SPRITE, api);
	RetroStartAnimDrawable2D(0, 1, 8, RetroTrue, 16, SPRITE, api);
	
	samus->weight = 0x1A;
	samus->startSpeedX = 0;
	samus->startSpeedY = 0;
	samus->speedX = 0;
	samus->speedY = 0;
	samus->maxSpeedX = 480;
	samus->maxSpeedY = 480;
	
	col = newCollider(samus, 1);
	setCollider(0, scrollElem[2], COLIDE, col);
	
	shader->program = api->program;
	addShaderTexture(shader, i2, "tileMap");
	addShaderTexture(shader, i1, "tileSet");
	addShaderVariable(shader, "tileMapSize", (void*)(tMapSize), UNIFORM_2F);
	addShaderVariable(shader, "tileSize", (void*)(tSet), UNIFORM_2F);
	retroAttachShader(0 , shader, TILEMAP, api);
	
	tCol = newTileColider(scrollElem[1], metroidBackMap, 17);
	tCol->tileSizeX = METROIDE_TILE_SIZE_X;
	tCol->tileSizeY = METROIDE_TILE_SIZE_Y;
	setColorToTileColider(0, 0xff000001, tCol);
	setColorToTileColider(1, 0xff010001, tCol);
	setColorToTileColider(2, 0xff020001, tCol);
	setColorToTileColider(3, 0xff030001, tCol);
	setColorToTileColider(4, 0xff040001, tCol);
	
	setColorToTileColider(5, 0xff000101, tCol);
	setColorToTileColider(6, 0xff020101, tCol);
	setColorToTileColider(7, 0xff030101, tCol);
	setColorToTileColider(8, 0xff040101, tCol);

	setColorToTileColider(9, 0xff000201, tCol);
	setColorToTileColider(10, 0xff010201, tCol);
	setColorToTileColider(11, 0xff020201, tCol);
	setColorToTileColider(12, 0xff030201, tCol);
	setColorToTileColider(13, 0xff040201, tCol);
	
	setColorToTileColider(14, 0xff000301, tCol);
	setColorToTileColider(15, 0xff010301, tCol);
	setColorToTileColider(16, 0xff020301, tCol);
	return (0);
}

void scrollDown(float speed, RETRO_TYPE_REF(Retro2DApi) api)
{
	RetroMoveDrawable2DY(0, (512.0f * speed / 1344.0f), BACKGROUND, api);
	RetroMoveDrawable2DY(1, speed, BACKGROUND, api);
	RetroMoveDrawable2DY(0, speed, LIGHTMAP, api);
}

void scrollUp(float speed, RETRO_TYPE_REF(Retro2DApi) api)
{
	RetroMoveDrawable2DY(0, -(512.0f * speed / 1344.0f), BACKGROUND, api);
	RetroMoveDrawable2DY(1, -speed, BACKGROUND, api);
	RetroMoveDrawable2DY(0, -speed, LIGHTMAP, api);
}


void scrollJumpFall(RETRO_TYPE_REF(Retro2DApi) api)
{
	float y = 0;
	
	if (samus->speedY < 0 && !predictDownTileMapCollider(tCol, samus, &y, api))
	{
		if (samus->y > 112 + 43)
		{
			if (scrollElem[0]->y > -256)
			{
				RetroMoveDrawable2DY(0, (512.0f * samus->speedY / 1344.0f), BACKGROUND, api);
				RetroMoveDrawable2DY(0, samus->speedY, TILEMAP, api);
				RetroMoveDrawable2DY(0, samus->speedY, LIGHTMAP, api);
			}
			else
				RetroMoveDrawable2DY(0, -samus->speedY, SPRITE, api);
		}
		else
			RetroMoveDrawable2DY(0, -samus->speedY, SPRITE, api);
	}
	else if (samus->speedY < 0)
	{
		samus->speedY = 0;
		RetroSetDrawable2DY(0, (y), SPRITE, api);
	}
	else if (samus->speedY > 0  && !predictUpTileMapCollider(tCol, samus, &y, api))
	{
		if (samus->y < 112 - 43)
		{
			if (scrollElem[0]->y < 0)
			{
				RetroMoveDrawable2DY(0, (512.0f * samus->speedY / 1344.0f), BACKGROUND, api);
				RetroMoveDrawable2DY(0, samus->speedY, TILEMAP, api);
				RetroMoveDrawable2DY(0, samus->speedY, LIGHTMAP, api);
			}
			else
				RetroMoveDrawable2DY(0, -samus->speedY, SPRITE, api);
		}
		else
			RetroMoveDrawable2DY(0, -samus->speedY, SPRITE, api);
	}
	else if (samus->speedY > 0)
	{
		samus->speedY = 0;
		RetroSetDrawable2DY(0, y, SPRITE, api);
	}
	
	
	if (scrollElem[0]->y >= 0)
	{
		RetroSetDrawable2DY(0, 0, BACKGROUND, api);
		RetroSetDrawable2DY(0, 0, TILEMAP, api);
		RetroSetDrawable2DY(0, 672, LIGHTMAP, api);
	}
	if (scrollElem[0]->y <= -256)
	{
		RetroSetDrawable2DY(0, -256, BACKGROUND, api);
		RetroSetDrawable2DY(0, -672, TILEMAP, api);
		RetroSetDrawable2DY(0, 0, LIGHTMAP, api);
	}
}

void jumpAndFall(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	if (runFastSquareCollider(col))
	{
		samus->maxSpeedY = 180;
		updateSpeedWithGravity(&motorY2, samus, api);
		samusSpeed = 5;
	}
	else
	{
		samus->maxSpeedY = 240;
		updateSpeedWithGravity(&motorY1, samus, api);
		samusSpeed = 10;
	}
	
	if (input.Newpress.Up && testDownTileMapCollider(tCol, samus))
	{
		samus->speedY = samus->maxSpeedY;
	}
}

void run(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	static bool lastL = false;
	GravityMotor *tmp = NULL;
	bool useIner = true;
	float x;
	
	if (runFastSquareCollider(col))
	{
		samus->maxSpeedX = 90;
		tmp = &motorX2;
	}
	else
	{
		samus->maxSpeedX = 240;
		tmp = &motorX1;
	}
	
	if (input.Held.Left)
	{
		tmp->angle = 0;
		lastL = true;
	}
	else if (input.Held.Right)
	{
		tmp->angle = M_PI;
		lastL = false;
	}
	
	if (input.Held.Left || input.Held.Right)
	{
		updateSpeedWithGravity(tmp, samus, api);
	}
	else if (samus->speedX != 0 && useIner)
	{
		DeceleratingFromMotor(tmp, samus, api);
	}
	
	if ((samus->speedX < 0 && predictLeftTileMapCollider(tCol, samus, &x, api)) ||
		(samus->speedX > 0 && predictRightTileMapCollider(tCol, samus, &x, api)))
	{
		samus->speedX = 0;
		RetroSetDrawable2DX(0, x, SPRITE, api);
	}
	
	RetroMoveDrawable2DX(0, samus->speedX, SPRITE, api);
}

int MetroidIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	static bool lastL = false;
	
	if (input.Newpress.C)
		RetroSetDrawable2DY(0, samus->y - 1, SPRITE, api);
	if (input.Newpress.F)
		RetroSetDrawable2DY(0, samus->y + 1, SPRITE, api);
	if (input.Newpress.G)
		RetroSetDrawable2DX(0, samus->x - 1, SPRITE, api);
	if (input.Newpress.L)
		RetroSetDrawable2DX(0, samus->x + 1, SPRITE, api);
	
	jumpAndFall(input, api);
	run(input, api);
	scrollJumpFall(api);
	
	if (runFastSquareCollider(col))
		samusSpeed = 5;
	else
		samusSpeed = 10;
	
	if (!testDownTileMapCollider(tCol, samus))
	{
		if (lastL)
		{
			if (samusAnim != 7)
			{
				RetroChangeRowDrawable2D(1, 7, SPRITE, api);
				RetroStartAnimDrawable2D(1, 1, 8, RetroTrue, samusSpeed, SPRITE, api);
				samusAnim = 7;
			}
		}
		else
		{
			if (samusAnim != 8)
			{
				RetroChangeRowDrawable2D(1, 8, SPRITE, api);
				RetroStartAnimDrawable2D(1, 1, 8, RetroTrue, samusSpeed, SPRITE, api);
				samusAnim = 8;
			}
		}
	}
	else if (input.Held.Left)
	{
		if (samusAnim != 6)
		{
			RetroChangeRowDrawable2D(1, 6, SPRITE, api);
			RetroStartAnimDrawable2D(1, 1, 10, RetroTrue, samusSpeed, SPRITE, api);
			samusAnim = 6;
		}
		lastL = false;
	}
	else if (input.Held.Right)
	{
		if (samusAnim != 5)
		{
			RetroChangeRowDrawable2D(1, 5, SPRITE, api);
			RetroStartAnimDrawable2D(1, 1, 10, RetroTrue, samusSpeed, SPRITE, api);
			samusAnim = 5;
		}
		lastL = true;
	}
	else
	{
		if (lastL)
		{
			if (samusAnim != 3)
			{
				RetroChangeRowDrawable2D(1, 3, SPRITE, api);
				RetroStartAnimDrawable2D(1, 1, 4, RetroTrue, 4, SPRITE, api);
				samusAnim = 3;
			}
		}
		else
		{
			if (samusAnim != 2)
			{
				RetroChangeRowDrawable2D(1, 2, SPRITE, api);
				RetroStartAnimDrawable2D(1, 1, 4, RetroTrue, 4, SPRITE, api);
				samusAnim = 2;
			}
		}
	}
	if (input.Held.Left)
		lastL = false;
	else if (input.Held.Right)
		lastL = true;
	RetroMoveInfinitVScroll(0, 0.01f, LIGHTMAP, api);
	
	
	int tmpX = RetroGetDrawable2DWidth(1, SPRITE, api);
	int tmpY = RetroGetDrawable2DHeight(1, SPRITE, api);
	
	tmpX -= samus->taillex;
	tmpY -= samus->tailley;
	tmpX *= 0.5;
	tmpY *= 0.5;
	
	RetroSetDrawable2DXY(1, samus->x - tmpX, samus->y - tmpY, SPRITE, api);
	
	return (0);
}

int stopMetroid(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	(void)system;
	RetroDelDrawable2D(0, BACKGROUND, api);
	RetroDelDrawable2D(0, TILEMAP, api);
	RetroDelDrawable2D(0, LIGHTMAP, api);
	RetroDelDrawable2D(0, SPRITE, api);
	RetroDelDrawable2D(1, SPRITE, api);
	
	RetroUnloadTexture(texture[0], *system);
	RetroUnloadTexture(texture[1], *system);
	RetroUnloadTexture(texture[2], *system);
	RetroUnloadTexture(texture[3], *system);
	RetroUnloadTexture(texture[4], *system);
	RetroUnloadTexture(i1, *system);
	RetroUnloadTexture(i2, *system);
	
	deleteShader(shader);
	return (0);
}