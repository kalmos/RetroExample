//
// allExample.cpp for Example
// 
// Made by lucas stefas
// Login   stefas_l
// 
// Started on 13/02/2015 16:29
//

#include <iostream>
#include <fstream>
#include <string>
#include <RetroEngine/RetroSystem.h>
#include <RetroEngine/RetroGLExt.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Input.h"


#define DECLAREFUNCFOR(name)\
int init##name(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api);\
int name##Iter(Input& input, RETRO_TYPE_REF(Retro2DApi) api);\
int stop##name(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api);

#define INITPTRF(id, name)\
initFunc[id] = &init##name;\
FuncIter[id] = &name##Iter;\
stopFunc[id] = &stop##name;

#define NBFUNC	17

DECLAREFUNCFOR(Color)
DECLAREFUNCFOR(Moving)
DECLAREFUNCFOR(Lightmap)
DECLAREFUNCFOR(List)
DECLAREFUNCFOR(Priority)
DECLAREFUNCFOR(Shader)
DECLAREFUNCFOR(Texte)
DECLAREFUNCFOR(Thread)
DECLAREFUNCFOR(Texture)
DECLAREFUNCFOR(Zelda)
DECLAREFUNCFOR(Castlevania)
DECLAREFUNCFOR(DonkeyKong)
DECLAREFUNCFOR(SecretOfMana)
DECLAREFUNCFOR(F_Zero)
DECLAREFUNCFOR(ColorSwaping)
DECLAREFUNCFOR(Metroid)
DECLAREFUNCFOR(Rayman)


int (*initFunc[NBFUNC])(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api);
int (*FuncIter[NBFUNC])(Input& input, RETRO_TYPE_REF(Retro2DApi) api);
int (*stopFunc[NBFUNC])(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api);

#define onBox(x, x2, y, y2)\
	if (input.posX > x && input.posX < x2 && input.posY > y && input.posY < y2)

#define clicked()\
	if (input.Newpress.LClik)

static int texture[3];

std::string readFile(const std::string& path)
{
	std::string tmp;
	std::string data;
	std::fstream	file;
	
	file.open(path.c_str());
	while (std::getline(file, tmp))
	{
		data += tmp;
		data += '\n';
	}
	file.close();
	return (data);
}

void populateShader(int shaders[8], RetroSystem* system)
{
	RetroEasyCreateFragmentShader(readFile(std::string(system->userPath) + std::string("Shader/Empty.fragsh")).c_str(), system);
	shaders[0] = system->program;
	RetroEasyCreateFragmentShader(readFile(std::string(system->userPath) + std::string("Shader/Sepia.fragsh")).c_str(), system);
	shaders[1] = system->program;
	RetroEasyCreateFragmentShader(readFile(std::string(system->userPath) + std::string("Shader/Invert.fragsh")).c_str(), system);
	shaders[2] = system->program;
	RetroEasyCreateFragmentShader(readFile(std::string(system->userPath) + std::string("Shader/Weird.fragsh")).c_str(), system);
	shaders[3] = system->program;
	RetroEasyCreateFragmentShader(readFile(std::string(system->userPath) + std::string("Shader/scanLine.fragsh")).c_str(), system);
	shaders[4] = system->program;
	RetroEasyCreateFragmentShader(readFile(std::string(system->userPath) + std::string("Shader/Pixelate.fragsh")).c_str(), system);
	shaders[5] = system->program;
	shaders[6] = system->program;
	shaders[7] = system->program;
}

int makeButton(RETRO_TYPE_REF(Retro2DApi) api)
{
	Object2D	obj2 = {0, 5, 7, 70, 9, 0, 0};
	Object2D	obj = {0, 0, 8, 8, 8, 0, 0};
	
	int			i = 1;
	char		str[NBFUNC][9] = {" Color  ", " Moving ", "Lightmap", "  List  ", "Priority", " Shader ", " Texte  ", "Texture ", " Thread ", " Zelda  ", " Castle ", "   DK   ", "  SOM   ", " F-Zero ", "CSwaping", "SMetroid", " Rayman "};
	
	while (i <= NBFUNC)
	{
		RetroWrite(i - 1, "%s", &obj, 0, api, str[i - 1]);
		RetroCreateDrawable2D(i - 1, &obj2, SPRITE, api);
		RetroAddDrawable2DTex(i - 1, 1, 1, texture[1], SPRITE, api);
		if (!(i % 3))
		{
			obj.posX = 0;
			obj2.posX = 5;
			obj. posY += 16;
			obj2.posY += 16;
		}
		else
		{
			obj.posX += 120;
			obj2.posX += 120;
		}
		i += 1;
	}
	
	return (0);
}

int initMainHub(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Object2D		obj = {0, 0, 8, 8, 8, 0, 0};
	
	
	RetroChangeResolution(320, 240, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	RetroSetMaxFps(60, *system); // seting the maximum number of FPS
	RetroAddFont(0, "ABCDEFGH\nIJKLMNO \nPQRSTUVW\nXYZ.,:& \nabcdefgh\nijklmno\"\npqrstuvw\nxyz.,/&]\n01234567\n89+-*%=[", "font/mariopaint.bmp", *system);
	texture[0] = RetroLoadBmpTexture("MarioPaint/mouse2.bmp", RetroTrue, *system);
	texture[1] = RetroLoadBmpTexture("MarioPaint/box1.bmp", RetroTrue, *system);
	texture[2] = RetroLoadBmpTexture("MarioPaint/box2.bmp", RetroTrue, *system);
	
	makeButton(api);
	
	RetroCreateDrawable2D(-1, &obj, SPRITE, api);
	RetroAddDrawable2DTex(-1, 1, 6, texture[0], SPRITE, api);
	RetroStartAnimDrawable2D(-1, 1, 6, RetroTrue, 24, SPRITE, api);
	RetroDrawable2DSetBack(-1, 1, SPRITE, api);
	
	return (0);
}



int mainHub(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	int i = 1;
	int x = 16;
	int y = 16;
	int *a = new int;

	a = new int;
	a = new int;
	a = new int;
	
	RetroSetDrawable2DXY(-1, input.posX / 2, input.posY / 2, SPRITE, api);

	while (i <= NBFUNC)
	{
		onBox(x, x + 112, y, y + 16)
		{
			RetroAddDrawable2DTex(i - 1, 1, 1, texture[2], SPRITE, api);
			RetroSetTextColor(i -1, 0xb028c000, RETRO_ALL_CONER_COLOR, api);
			clicked()
				return (i - 1);
		}
		else
		{
			RetroAddDrawable2DTex(i - 1, 1, 1, texture[1], SPRITE, api);
			RetroSetTextColor(i -1, 0x4888f800, RETRO_ALL_CONER_COLOR, api);
		}
		
		
		if (!(i % 3))
		{
			x = 16;
			y += 32;
		}
		else
		{
			x += 240;
		}
		i += 1;
	}
	return (-1);
}

int cleanHub(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	RetroDeleteAllText(api);
	RetroResetDrawable2D(SPRITE, api);
	
	RetroDeleteFont(0, *system);
	RetroUnloadTexture(texture[0], *system);
	RetroUnloadTexture(texture[1], *system);
	RetroUnloadTexture(texture[2], *system);
	return (0);
}

int main(int argc, char**argv)
{
	RetroSystem*	system = NULL;
	Retro2DApi*		api = NULL;
	Object2D		obj = {0, 0, 8, 8, 8, 0, 0};
	Input			input;
	int				tmp = -1;
	bool			init = false;
	bool			cantQuit = false;
	int				shaderUsed = 0;
	int				shaders[8] = {0};
	std::string		text[8] = {	"No shader", "Sepia shader", "Inver color shader",
								"Weird shader", "Scan line shader", "Pixelate shader",
								"Pixelate shader", "Pixelate shader"};
	
	INITPTRF(0, Color)
	INITPTRF(1, Moving)
	INITPTRF(2, Lightmap)
	INITPTRF(3, List)
	INITPTRF(4, Priority)
	INITPTRF(5, Shader)
	INITPTRF(6, Texte)
	INITPTRF(7, Texture)
	INITPTRF(8, Thread)
	INITPTRF(9, Zelda)
	INITPTRF(10, Castlevania)
	INITPTRF(11, DonkeyKong)
	INITPTRF(12, SecretOfMana)
	INITPTRF(13, F_Zero)
	INITPTRF(14, ColorSwaping)
	INITPTRF(15, Metroid)
	INITPTRF(16, Rayman)
	
	/*
	 * first initialising the sdl part
	 */
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("All Example", NULL);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute( SDL_GL_SWAP_CONTROL, 0);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
	SDL_ShowCursor(0);
	atexit(SDL_Quit);
	
	/*
	 * initialising RetroEngine
	 */
	system = newRetroSystem(); // creating the C object for andling most of the work
	RetroEngineInit(argc, argv, 640, 480, "../Ressource", system); // initialisation
	api = get2DApiFromSystem(system); // geting the 2D engine ready for work
	RetroInitGLExt(system);
	populateShader(shaders, system);
	system->program = shaders[0];
	RetroStartStopShader(RetroTrue, system);
	RetroInitPostProcessing(api);
	
	initMainHub(&system, api);
	input.fillinput();
	
	input.x = 640;
	input.y = 480;
	
	obj.posY = system->info.screenY - 8;
	RetroWrite(NBFUNC, "No shader", &obj, 0, api);
	
	while ((cantQuit || !input.Newpress.Exit) && (!input.Newpress.ESC || tmp > -1))
	{
		if (tmp == -1)
			tmp = mainHub(input, api);
		
		if (tmp == 5)
		{
			switch (shaderUsed)
			{
				case 0:
					RetroStartStopShader(RetroFalse, system);
					system->program = shaders[shaderUsed + 1];
					RetroStartStopShader(RetroTrue, system);
					RetroDeleteText(NBFUNC, api);
					RetroWrite(NBFUNC, "%s", &obj, 0, api, text[shaderUsed + 1].c_str());
					break;
				case 1:
					RetroStartStopShader(RetroFalse, system);
					system->program = shaders[shaderUsed + 1];
					RetroStartStopShader(RetroTrue, system);
					RetroDeleteText(NBFUNC, api);
					RetroWrite(NBFUNC, "%s", &obj, 0, api, text[shaderUsed + 1].c_str());
					break;
				case 2:
					RetroStartStopShader(RetroFalse, system);
					system->program = shaders[shaderUsed + 1];
					RetroStartStopShader(RetroTrue, system);
					RetroDeleteText(NBFUNC, api);
					RetroWrite(NBFUNC, "%s", &obj, 0, api, text[shaderUsed + 1].c_str());
					break;
				case 3:
					RetroStartStopShader(RetroFalse, system);
					system->program = shaders[shaderUsed + 1];
					RetroStartStopShader(RetroTrue, system);
					RetroDeleteText(NBFUNC, api);
					RetroWrite(NBFUNC, "%s", &obj, 0, api, text[shaderUsed + 1].c_str());
					break;
				case 4:
					RetroStartStopShader(RetroFalse, system);
					system->program = shaders[shaderUsed + 1];
					RetroStartStopShader(RetroTrue, system);
					RetroSetShaderVariable2f("screen", system->info.origScreenX , system->info.origScreenY, system);
					RetroSetShaderVariable2f("dim", system->info.origScreenX / 256.0f, system->info.origScreenY / 224.0f, system);
					RetroDeleteText(NBFUNC, api);
					RetroWrite(NBFUNC, "%s", &obj, 0, api, text[shaderUsed + 1].c_str());
					break;
				case 5:
					RetroStartStopShader(RetroTrue, system);
					RetroSetShaderVariable2f("dim", 8.0, 8.0, system);
					RetroDeleteText(NBFUNC, api);
					RetroWrite(NBFUNC, "%s", &obj, 0, api, text[shaderUsed + 1].c_str());
					break;
				case 6:
					RetroStartStopShader(RetroTrue, system);
					RetroSetShaderVariable2f("dim", system->info.origScreenX / 160.0f, system->info.origScreenY / 144.0f, system);
					RetroDeleteText(NBFUNC, api);
					RetroWrite(NBFUNC, "%s", &obj, 0, api, text[shaderUsed + 1].c_str());
					break;
				default:
					RetroStartStopShader(RetroFalse, system);
					system->program = shaders[shaderUsed + 1];
					RetroStartStopShader(RetroTrue, system);
					shaderUsed = -1;
					RetroDeleteText(NBFUNC, api);
					RetroWrite(NBFUNC, "%s", &obj, 0, api, text[shaderUsed + 1].c_str());
					break;
			}
			shaderUsed += 1;
			tmp = -1;
		}
		
		
		if (tmp > -1 && !init)
		{
			cleanHub(&system, api);
			initFunc[tmp](&system, api);
			init = true;
		}
		
		if (tmp > -1)
			cantQuit = FuncIter[tmp](input, api);
		
		if (!cantQuit && tmp > -1 && input.Newpress.ESC)
		{
			stopFunc[tmp](&system, api);
			initMainHub(&system, api);
			RetroWrite(NBFUNC, "%s", &obj, 0, api, text[shaderUsed].c_str());
			init = false;
			tmp = -1;
		}
		
		/*
		 * Rendering phase
		 */
		
		if (/*input.x != system->info.origScreenX || input.y != system->info.origScreenY*/ input.Newpress.T)
		{
			//SDL_SetVideoMode(input.x, input.y, 32, SDL_OPENGL | SDL_RESIZABLE);
			//glMatrixMode(GL_PROJECTION);
			//glLoadIdentity();
			
			//glOrtho(0, input.x, input.y, 0, 1, 1000);
			system->info.origScreenX = input.x;
			system->info.origScreenY = input.y;
			system->info.origRes = ((float)input.x / (float)input.y);
			
			
		}
		
		RetroUsePostProcessing(RetroCleanDrawnOnScreen, system, api)
		//RetroCleanDrawnOnScreen(api); // clean and drawn on screen
		SDL_GL_SwapBuffers();
		RetroLimitFPS(system); //finishing with this for actualy slow down the aplication
		RetroGetFPSMsg("FPS: ");
		input.fillinput();
	}
	
	if (tmp > -1)
		stopFunc[tmp](&system, api);
	else
		cleanHub(&system, api);
	
	RetroStartStopShader(RetroFalse, system);
	
	for (int i = 0; i < 8; i++)
	{
		system->program = shaders[i];
		RetroDeleteShader(system);
	}
	
	RetroStopPostProcessing(api);
	RetroEngineStop(system); // and finaly killing the the engine
	
	
	
	return (0);
}