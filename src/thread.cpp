/*
** thread.cpp
**
** Made by lucas stefas
** Started on 03/07/14 22:47
*/

#include <RetroEngine/Thread.h>
#include <RetroEngine/RetroSystem.h>
#include <SDL/SDL.h>
#include "Input.h"

#ifndef Windows
#	define SLEEP(x) sleep(x);
#else
#	define SLEEP(x) Sleep(x * 1000);
#endif

static PortableThread* threadG = NULL;

typedef struct	ParamOfThread
{
	Retro2DApi * const api;
	int			i;
	int			id;
}				ParamOfThread;

static int		runing;

/*
 * creating a test function to thread
 */

ThreadRetVal monthread(ThreadParam param)
{
	Object2D		obj = {0, 0, 8, 8, 8, 0, 0};
	ParamOfThread	paramOfMiniThread = *(ParamOfThread*)param;
	
	obj.posY *= paramOfMiniThread.id;
	SLEEP(paramOfMiniThread.i);
	RetroWrite(paramOfMiniThread.id, "thread sleep during %d", &obj, 0, paramOfMiniThread.api, paramOfMiniThread.i);
	return (NULL);
}

ThreadRetVal otherThread(ThreadParam param)
{
	PortableThread* th = newPortableThread(); // preparing the portable thread handler
	Retro2DApi * const api = (Retro2DApi*)param;
	ParamOfThread	paramOfMiniThread[5] = {{api, 0, 0}, {api, 0, 0}, {api, 0, 0}, {api, 0, 0}, {api, 0, 0}};
	Object2D		obj = {0, 0, 0, 8, 8, 0, 0};
	
	/*
	 * adding all the function to thread.
	 */
	
	paramOfMiniThread[1].i = 1;
	paramOfMiniThread[1].id = 6;
	addThread(&monthread, &paramOfMiniThread[1], th);
	paramOfMiniThread[2].i = 2;
	paramOfMiniThread[2].id = 7;
	addThread(&monthread, &paramOfMiniThread[2], th);
	paramOfMiniThread[3].i = 3;
	paramOfMiniThread[3].id = 8;
	addThread(&monthread, &paramOfMiniThread[3], th);
	paramOfMiniThread[4].i = 4;
	paramOfMiniThread[4].id = 9;
	addThread(&monthread, &paramOfMiniThread[4], th);
	
	RetroWrite(0, "run without thread", &obj, 0, api); // seeing everithing is normal.
	paramOfMiniThread[0].i = 1;
	paramOfMiniThread[0].id = 1;
	monthread(&paramOfMiniThread);
	paramOfMiniThread[0].i = 2;
	paramOfMiniThread[0].id = 2;
	monthread(&paramOfMiniThread);
	paramOfMiniThread[0].i = 3;
	paramOfMiniThread[0].id = 3;
	monthread(&paramOfMiniThread);
	paramOfMiniThread[0].i = 4;
	paramOfMiniThread[0].id = 4;
	monthread(&paramOfMiniThread);
	
	obj.posY = 40;
	RetroWrite(5, "run with thread", &obj, 0, api);
	runAllThread(th); // efectively run all thread
	waitAllThread(th); // whait all remening thread before finishing the aplication.
	
	deleteThread(&th);
	
	obj.posY = 80;
	RetroWrite(10, "th = %p", &obj, 0, api, th); // just to be sure it was realy deleted.
	runing = 0;
	return (NULL);
}

int initThread(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	threadG = newPortableThread(); // preparing the portable thread handler
	RetroChangeResolution(320, 240, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	RetroAddFont(0, "ABCDEFGH\nIJKLMNO \nPQRSTUVW\nXYZ.,:& \nabcdefgh\nijklmno\"\npqrstuvw\nxyz.,/&]\n01234567\n89+-*%=[", "font/mariopaint.bmp", *system);
	runing = 1;
	addThread(&otherThread, api, threadG);
	
	
	runAllThread(threadG); // efectively run all thread
	return (0);
}

int ThreadIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	
	return (runing);
}

int stopThread(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	waitAllThread(threadG);
	
	RetroDeleteText(0, api);
	RetroDeleteText(1, api);
	RetroDeleteText(2, api);
	RetroDeleteText(3, api);
	RetroDeleteText(4, api);
	RetroDeleteText(5, api);
	RetroDeleteText(6, api);
	RetroDeleteText(7, api);
	RetroDeleteText(8, api);
	RetroDeleteText(9, api);
	RetroDeleteText(10, api);
	RetroDeleteFont(0, *system);
	
	deleteThread(&threadG);
	
	return (0);
}