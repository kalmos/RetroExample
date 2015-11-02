//
// Input.cpp for RandomShmupNam
// 
// Made by lucas stefas
// Login   stefas_l
// 
// Started on 20/09/2014 00:07
//

#include "Input.h"
#include <iostream>

Input::Input()
{
	Newpress.Up = false;
	Held.Up = false;
	Released.Up = false;
	
	Newpress.Down = false;
	Held.Down = false;
	Released.Down = false;
	
	Newpress.Left = false;
	Held.Left = false;
	Released.Left = false;
	
	Newpress.Right = false;
	Held.Right = false;
	Released.Right = false;
	
	Newpress.T = false;
	Held.T = false;
	Released.T = false;
	
	Newpress.G = false;
	Held.G = false;
	Released.G = false;
	
	Newpress.F = false;
	Held.F = false;
	Released.F = false;

	Newpress.L = false;
	Held.L = false;
	Released.L = false;
	
	Newpress.C = false;
	Held.C = false;
	Released.C = false;
	
	Newpress.Exit = false;
	Held.Exit = false;
	Released.Exit = false;
	
	Newpress.ESC = false;
	Held.ESC = false;
	Released.ESC = false;
}

void	Input::fillinput()
{
	SDL_Event event;
	
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
				this->getButtonDown(event);
				break;
			case SDL_KEYUP:
				this->getButtonUp(event);
				break;
			case SDL_QUIT:
				Newpress.Exit = true;
				break;
			case SDL_MOUSEMOTION:
				posX = event.motion.x;
				posY = event.motion.y;
				break;
			case SDL_MOUSEBUTTONDOWN:
				getMouseDown(event);
				break;
			case SDL_MOUSEBUTTONUP:
				getMouseUp(event);
				break;
			case SDL_VIDEORESIZE:
				x = event.resize.w;
				y = event.resize.h;
			default:
				this->resetStructure();
		}
	}
	else
		this->resetStructure();
	this->makeTheHeld();
}

void	Input::getButtonDown(const SDL_Event event)
{
	switch (event.key.keysym.sym)
    {
		case SDLK_UP:
		case SDLK_z:
		case SDLK_w:
			Newpress.Up = true;
			Released.Up = false;
			break;
		case SDLK_DOWN:
		case SDLK_s:
			Newpress.Down = true;
			Released.Down = false;
			break;
		case SDLK_LEFT:
		case SDLK_q:
		case SDLK_a:
			Newpress.Left = true;
			Released.Left = false;
			break;
		case SDLK_RIGHT:
		case SDLK_d:
			Newpress.Right = true;
			Released.Right = false;
			break;
		case SDLK_t:
			Newpress.T = true;
			Released.T = false;
			break;
		case SDLK_g:
			Newpress.G = true;
			Released.G = false;
			break;
		case SDLK_f:
			Newpress.F = true;
			Released.F = false;
			break;
		case SDLK_l:
			Newpress.L = true;
			Released.L = false;
			break;
		case SDLK_c:
			Newpress.C = true;
			Released.C = false;
			break;
		case SDLK_ESCAPE:
			Newpress.ESC = true;
			Released.ESC = false;
			break;
		default:
			break;
    }
}

void	Input::getButtonUp(const SDL_Event event)
{
	switch (event.key.keysym.sym)
    {
		case SDLK_UP:
		case SDLK_z:
		case SDLK_w:
			Newpress.Up = false;
			Released.Up = true;
			break;
		case SDLK_DOWN:
		case SDLK_s:
			Newpress.Down = false;
			Released.Down = true;
			break;
		case SDLK_LEFT:
		case SDLK_q:
		case SDLK_a:
			Newpress.Left = false;
			Released.Left = true;
			break;
		case SDLK_RIGHT:
		case SDLK_d:
			Newpress.Right = false;
			Released.Right = true;
			break;
		case SDLK_t:
			Newpress.T = false;
			Released.T = true;
			break;
		case SDLK_g:
			Newpress.G = false;
			Released.G = true;
			break;
		case SDLK_f:
			Newpress.F = false;
			Released.F = true;
			break;
		case SDLK_l:
			Newpress.L = false;
			Released.L = true;
			break;
		case SDLK_c:
			Newpress.C = false;
			Released.C = true;
			break;
		case SDLK_ESCAPE:
			Newpress.ESC = false;
			Released.ESC = true;
			break;
		default:
			break;
    }
}

void Input::getMouseDown(const SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		Newpress.LClik = true;
		Released.LClik = false;
	}
	else if (event.button.button == SDL_BUTTON_RIGHT)
	{
		Newpress.RClik = true;
		Released.RClik = false;
	}
}

void Input::getMouseUp(const SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		Newpress.LClik = false;
		Released.LClik = true;
	}
	else if (event.button.button == SDL_BUTTON_RIGHT)
	{
	 Newpress.RClik = false;
	 Released.RClik = true;
	}
}


void	Input::resetStructure()
{
	Newpress.Up = false;
	Released.Up = false;
	Newpress.Down = false;
	Released.Down = false;
	Newpress.Left = false;
	Released.Left = false;
	Newpress.Right = false;
	Released.Right = false;
	Newpress.T = false;
	Released.T = false;
	Newpress.G = false;
	Released.G = false;
	Newpress.F = false;
	Released.F = false;
	Newpress.L = false;
	Released.L = false;
	Newpress.C = false;
	Released.C = false;
	Newpress.Exit = false;
	Released.Exit = false;
	Newpress.ESC = false;
	Released.ESC = false;
	Newpress.LClik = false;
	Released.LClik = false;
	Newpress.RClik = false;
	Released.RClik = false;
}

void	Input::makeTheHeld()
{
	if (Newpress.Up)
		Held.Up = true;
	else if (Released.Up)
		Held.Up = false;
	if (Newpress.Down)
		Held.Down = true;
	else if (Released.Down)
		Held.Down = false;
	if (Newpress.Left)
		Held.Left = true;
	else if (Released.Left)
		Held.Left = false;
	if (Newpress.Right)
		Held.Right = true;
	else if (Released.Right)
		Held.Right = false;
	
	
	if (Newpress.T)
		Held.T = true;
	else if (Released.T)
		Held.T = false;
	if (Newpress.G)
		Held.G = true;
	else if (Released.G)
		Held.G = false;
	if (Newpress.F)
		Held.F = true;
	else if (Released.F)
		Held.F = false;
	if (Newpress.L)
		Held.L = true;
	else if (Released.L)
		Held.L = false;
	if (Newpress.C)
		Held.C = true;
	else if (Released.C)
		Held.C = false;
	if (Newpress.ESC)
		Held.ESC = true;
	else if (Released.ESC)
		Held.ESC = false;
	
	
	if (Newpress.Exit)
		Held.Exit = true;
	else if (Released.Exit)
		Held.Exit = false;
	
	if (Newpress.LClik)
		Held.LClik = true;
	else if (Released.LClik)
		Held.LClik = false;
	if (Newpress.RClik)
		Held.RClik = true;
	else if (Released.RClik)
		Held.RClik = false;
}

Input::~Input()
{

}
