/*
** Input.h for RandomShmupNam
**
** Made by lucas stefas
** Login   stefas_l
**
** Started on 20/09/2014 00:07
*/

#ifndef		__Input_H__
#define		__Input_H__

#include <RetroEngine/RetroSystem.h>
#include <SDL/SDL.h>

class	Input
{

public:

    /**
	 *
     */
    Input();

	void fillinput();
	
    /**
	 *
     */
    ~Input();
  		
private:
	
	void getButtonDown(const SDL_Event event);
	
	void getButtonUp(const SDL_Event event);
	
	void getMouseDown(const SDL_Event event);
	
	void getMouseUp(const SDL_Event event);
	
	void resetStructure();
	
	void makeTheHeld();
	
	typedef struct	Press
	{
		bool       	T;
		bool		G;
		bool		F;
		bool		L;
		bool		C;
		bool       	Up;
		bool       	Down;
		bool       	Left;
		bool       	Right;
		bool       	Exit;
		bool		ESC;
		bool		LClik;
		bool		RClik;
	}	       	Press;
	
public:
	
	Press      	Newpress;
	Press      	Released;
	Press      	Held;
	signed int 	posX;
	signed int 	posY;
	signed int	x;
	signed int	y;
	
	
};

#endif
