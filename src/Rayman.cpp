/*
** Rayman.c for Example
** 
** Made by lucas stefas
** Login   stefas_l
** 
** Started on 09/08/2015 13:29
*/

#include <RetroEngine/RetroSystem.h>
#include <RetroEngine/RetroColider.h>
#include <RetroEngine/GravityMotor.h>
#include <SDL/SDL.h>
#include "Input.h"
#include <iostream>

#include "RaymanBack.h"
#include "RaymanColl.h"

#define ABS(x)	(x > 0) ? x : -x

static int texture[4];
Drawable2D* rayman = NULL;
static GravityMotor motorY = {0, 0, 3 * M_PI / 2.0f, 1.0f, 0.5f, 1, 3};
static GravityMotor motorX1 = {0, 0, 0, 1.0f, 1.0f, 1, 1};
static GravityMotor motorX2 = {0, 0, 0, 1.0f, 0.0001f, 1, 1};
static unsigned int i1 = 0;
static unsigned int i2 = 0;
static Shader* shader = NULL;
static float tMapSize[2] = {16, 14};
static float tSet[2] = {1.0f / 9.0f, 1.0f / 9.0f};
static RetroTileColider* slideColl;
static RetroTileColider* normalColl;
static RetroTileColider* slopeColl;
static int	lastGround = 0;
static float	tSpeed = 0;
static float holdMX1 = 0;
static int cloudSpeed = -60;
static Retro_Colider* col;
static int RaymanAnim = 1;
static bool lastL = false;

int initRayman(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Object2D		obj;
	shader = newShader();
	Drawable2D* tmp;
	lastL = false;
	
	RetroChangeResolution(256, 224, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	
	texture[0] = RetroLoadBmpTexture("Rayman/back.bmp", RetroTrue, *system);
	texture[1] = RetroLoadBmpTexture("Rayman/Rayman.bmp", RetroTrue, *system);
	texture[2] = RetroLoadBmpTexture("Rayman/Cloud.bmp", RetroTrue, *system);
	texture[3] = RetroLoadBmpTexture("ToDo.bmp", RetroTrue, *system);
	
	glGenTextures(1, &i1);
	glBindTexture(GL_TEXTURE_2D, i1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 144, 144, 0, GL_RGBA, GL_UNSIGNED_BYTE, RaymanBackPal);
	ONLYPC1;
	glGenTextures(1, &i2);
	glBindTexture(GL_TEXTURE_2D, i2);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 16, 14, 0, GL_RGBA, GL_UNSIGNED_BYTE, RaymanBackMap);
	ONLYPC1;
	
	/*
	 * creating 2 sprite
	 */
	obj.posX = 60;
	obj.posY = 60;
	obj.sizeX = 28;
	obj.sizeY = 33;
	rayman = RetroCreateDrawable2D(2, &obj, SPRITE, api); //sending the sprite to your engine
	RetroAddDrawable2DTex(2, 4, 15, texture[1], SPRITE, api);
	
	obj.posX = 60;
	obj.posY = 60;
	obj.sizeX = 16;
	obj.sizeY = 32;
	rayman = RetroCreateDrawable2D(0, &obj, SPRITE, api); //sending the sprite to your engine
	RetroAddDrawable2DTex(0, 1, 1, texture[3], SPRITE, api);
	
	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 256;
	obj.sizeY = 224;
	RetroCreateDrawable2D(0, &obj, TILEMAP, api); //sending the sprite to your engine
	RetroAddDrawable2DTex(0, 1, 1, i1, TILEMAP, api);
	
	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 256;
	obj.sizeY = 224;
	RetroCreateDrawable2D(0, &obj, BACKGROUND, api); //sending the sprite to your engine
	RetroAddDrawable2DTex(0, 1, 1, texture[0], BACKGROUND, api);
	
	rayman->weight = 0x3A;
	rayman->startSpeedX = 0;
	rayman->startSpeedY = 0;
	rayman->speedX = 0;
	rayman->speedY = 0;
	rayman->maxSpeedX = 60;
	rayman->maxSpeedY = 480;
	
	shader->program = api->program;
	addShaderTexture(shader, i2, "tileMap");
	addShaderTexture(shader, i1, "tileSet");
	addShaderVariable(shader, "tileMapSize", (void*)(tMapSize), UNIFORM_2F);
	addShaderVariable(shader, "tileSize", (void*)(tSet), UNIFORM_2F);
	retroAttachShader(0 , shader, TILEMAP, api);
	
	normalColl = newTileColider(RetroGetDrawable2DPtr(0, TILEMAP, api), RaymanCollMap, 1);
	normalColl->tileSizeX = 16;
	normalColl->tileSizeY = 16;
	slideColl = newTileColider(RetroGetDrawable2DPtr(0, TILEMAP, api), RaymanCollMap, 1);
	slideColl->tileSizeX = 16;
	slideColl->tileSizeY = 16;
	slopeColl = newTileColider(RetroGetDrawable2DPtr(0, TILEMAP, api), RaymanCollMap, 1);
	slopeColl->tileSizeX = 16;
	slopeColl->tileSizeY = 16;
	setColorToTileColider(0, 0xff000001, normalColl);
	setColorToTileColider(0, 0xff000101, slideColl);
	setColorToTileColider(0, 0xff010101, slopeColl);
	
	/*
	 * creating 2 sprite
	 */
	obj.posX = 16 + 16;
	obj.posY = 224 - 16 - 16 - 16;
	obj.sizeX = 32;
	obj.sizeY = 16;
	tmp = RetroCreateDrawable2D(1, &obj, SPRITE, api); //sending the sprite to your engine
	RetroAddDrawable2DTex(1, 1, 1, texture[2], SPRITE, api);
	
	col = newCollider(rayman, 1);
	setCollider(0, tmp, FIRST_COLIDE_DOWN, col);
	
	return (0);
}

void colisionGestion(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	RetroBool coll[3] = {RetroFalse, RetroFalse, RetroFalse};
	float x[3];
	float y[3];
	RetroBool (*prediTileMap)(RetroTileColider*, Drawable2D *, float *, Retro2DApi *const) = NULL;
	bool useCustomMove = false;
	float tmp = 0;
	
	
	if (runSquareCollider(col) == FIRST_COLIDE_DOWN)
	{
		rayman->speedY = 0;
		if (input.Newpress.Up)
		{
			rayman->speedY = 220;
		}
		RetroMoveDrawable2DY(0, cloudSpeed, SPRITE, api);
	}
	
	if (tSpeed < 0)
		prediTileMap = predictLeftTileMapCollider;
	else
		prediTileMap = predictRightTileMapCollider;
	
	coll[0] = predictDownTileMapCollider(normalColl, rayman, &y[0], api);
	coll[1] = predictDownTileMapCollider(slideColl, rayman, &y[1], api);
	coll[2] = predictDownTileMapCollider(slopeColl, rayman, &y[2], api);
	
	if (predictDownTileMapCollider(slopeColl, rayman, &y[2], api))
	{
		
		tmp = rayman->speedX;
		rayman->speedX = holdMX1;
		motorX1.angle = M_PI;
		updateSpeedWithGravity(&motorX1, rayman, api);
		holdMX1 = rayman->speedX;
		rayman->speedX += tmp;
	}

	
	if (prediTileMap(slopeColl, rayman, &y[2], api))
	{
		useCustomMove = true;
	}
	else if (prediTileMap(normalColl, rayman, &y[0], api))
	{
		rayman->speedX = 0;
		tSpeed = 0;
	}
	if (useCustomMove &&
		((coll[0]) || (coll[1]) || (coll[2])))
		RetroMoveDrawable2DXY(0, tSpeed, tSpeed, SPRITE, api);
	else
		RetroMoveDrawable2DX(0, tSpeed, SPRITE, api);
	
	if (predictDownTileMapCollider(slopeColl, rayman, &x[2], api) &&
		(int)(rayman->x) % 16 > (int)(rayman->y + rayman->tailley) % 16 &&
		!(predictDownTileMapCollider(normalColl, rayman, &x[0], api) ||
		  predictDownTileMapCollider(slideColl, rayman, &x[1], api)))
	{
		RetroMoveDrawable2DY(0, -rayman->speedY, SPRITE, api);
		updateSpeedWithGravity(&motorY, rayman, api);
	}
	else if (!(((coll[0]) || (coll[1]) || (coll[2])) && rayman->speedY <= 0))
	{
		RetroMoveDrawable2DY(0, -rayman->speedY, SPRITE, api);
		updateSpeedWithGravity(&motorY, rayman, api);
	}
	else
	{
		rayman->speedY = 0;
		if (input.Newpress.Up)
		{
			rayman->speedY = 220;
		}
	}
	
	if (predictDownTileMapCollider(normalColl, rayman, &y[0], api))
		lastGround = 1;
	else if (predictDownTileMapCollider(slideColl, rayman, &y[1], api))
		lastGround = 2;
	else if (predictDownTileMapCollider(slopeColl, rayman, &y[2], api))
		lastGround = 3;
	
}

void RaymanAnimF(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	
	if (!testDownTileMapCollider(normalColl, rayman) &&
		!testDownTileMapCollider(slideColl, rayman) &&
		!testDownTileMapCollider(slopeColl, rayman) &&
		!(runSquareCollider(col) == FIRST_COLIDE_DOWN))
	{
		if (rayman->speedY > 0)
		{
			if (RaymanAnim != 3)
			{
				RetroChangeRowDrawable2D(2, 3, SPRITE, api);
				RetroStartAnimDrawable2D(2, 1, 10, RetroTrue, 16, SPRITE, api);
				RaymanAnim = 3;
			}
			if (RaymanAnim == 3 && RetroGetDrawable2DFrame(2, SPRITE, api) == 10)
				RetroStopAnimDrawable2D(2, SPRITE, api);
		}
		else
		{
			if (RaymanAnim != 4)
			{
				RetroChangeRowDrawable2D(2, 4, SPRITE, api);
				RetroStartAnimDrawable2D(2, 1, 1, RetroTrue, 16, SPRITE, api);
				RaymanAnim = 4;
			}
		}
	}
	else if (input.Held.Left || input.Held.Right)
	{
		if (RaymanAnim != 2)
		{
			RetroChangeRowDrawable2D(2, 2, SPRITE, api);
			RetroStartAnimDrawable2D(2, 1, 11, RetroTrue, 16, SPRITE, api);
			RaymanAnim = 2;
		}
	}
	else
	{
		if (RaymanAnim != 1)
		{
			RetroChangeRowDrawable2D(2, 1, SPRITE, api);
			RetroStartAnimDrawable2D(2, 1, 10, RetroTrue, 16, SPRITE, api);
			RaymanAnim = 1;
		}
	}
	if (input.Held.Left && !lastL)
	{
		RetroSetDrawable2DVFlip(2, SPRITE, api);
		lastL = true;
	}
	else if (input.Held.Right && lastL)
	{
		RetroSetDrawable2DVFlip(2, SPRITE, api);
		lastL = false;
	}
}

int RaymanIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	tSpeed = 0;
	static float holdMX2 = 0;
	static bool lastDir = false;
	bool mooving = false;
	
	if (input.Held.Down)
		RetroAddDrawable2DY(0, 1, SPRITE, api);
	if (input.Held.Left)
	{
		if (lastGround > 1)
		{
			rayman->speedX = holdMX1;
			motorX1.angle = 0;
			updateSpeedWithGravity(&motorX1, rayman, api);
			holdMX1 = rayman->speedX;
		}
		rayman->speedX = holdMX2;
		motorX2.angle = 0;
		updateSpeedWithGravity(&motorX2, rayman, api);
		holdMX2 = rayman->speedX;
		
		rayman->speedX = holdMX1 + holdMX2;
		lastDir = false;
		mooving = true;
	}
	else if (input.Held.Right)
	{
		if (lastGround > 1)
		{
			rayman->speedX = holdMX1;
			motorX1.angle = M_PI;
			updateSpeedWithGravity(&motorX1, rayman, api);
			holdMX1 = rayman->speedX;
		}
		rayman->speedX = holdMX2;
		motorX2.angle = M_PI;
		updateSpeedWithGravity(&motorX2, rayman, api);
		holdMX2 = rayman->speedX;
		
		rayman->speedX = -holdMX1 + holdMX2;
		lastDir = true;
		mooving = true;
	}
	else
	{
		tSpeed = rayman->speedX;
	}
	rayman->speedX = holdMX1 + holdMX2;
	tSpeed = rayman->speedX;
	
	colisionGestion(input, api);
	
	if (lastGround < 2)
	{
		rayman->speedX = 0;
		holdMX2 = 0;
		holdMX1 = 0;
	}
	else if (!mooving)
	{
		if (lastDir)
		{
			motorX1.angle = M_PI;
			motorX2.angle = M_PI;
		}
		else
		{
			motorX1.angle = 0;
			motorX2.angle = 0;
		}
		rayman->speedX = holdMX1;
		DeceleratingFromMotor(&motorX1, rayman, api);
		holdMX1 = rayman->speedX;
		rayman->speedX = holdMX2;
		DeceleratingFromMotor(&motorX2, rayman, api);
		holdMX2 = rayman->speedX;
	}
	
	RaymanAnimF(input, api);
	
	if (RetroGetDrawable2DY(1, SPRITE, api) < 64 && cloudSpeed < 0)
		cloudSpeed = -cloudSpeed;
	else if (RetroGetDrawable2DY(1, SPRITE, api) > 224 - 16 - 16 - 16  && cloudSpeed > 0)
		cloudSpeed = -cloudSpeed;
	RetroMoveDrawable2DY(1, cloudSpeed, SPRITE, api);
	
	int tmpX = RetroGetDrawable2DWidth(2, SPRITE, api);
	int tmpY = RetroGetDrawable2DHeight(2, SPRITE, api);
	
	tmpX -= rayman->taillex;
	tmpY -= rayman->tailley;
	tmpX *= 0.5;
	tmpY *= 0.5;
	
	RetroSetDrawable2DXY(2, rayman->x - tmpX, rayman->y - tmpY, SPRITE, api);
	
	return (0);
	
	return (0);
}
int stopRayman(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	(void)system;
	RetroDelDrawable2D(0, SPRITE, api);
	RetroDelDrawable2D(1, SPRITE, api);
	RetroDelDrawable2D(2, SPRITE, api);
	RetroDelDrawable2D(0, TILEMAP, api);
	RetroDelDrawable2D(0, BACKGROUND, api);
	
	RetroUnloadTexture(texture[0], *system);
	RetroUnloadTexture(texture[1], *system);
	RetroUnloadTexture(texture[2], *system);
	RetroUnloadTexture(texture[3], *system);
	deleteShader(shader);
	
	return (0);
}