/*
** GravityMotor.h for SL
**
** Made by lucas stefas
** Login   stefas_l
**
** Started on 06/09/13 21:25 2013 by lucas stefas
*/

#ifndef		__GravityMotor_H__
#define		__GravityMotor_H__

#ifdef		__cplusplus
extern "C" {
#endif

	#include <RetroEngine/Retro2DApi.h>
	
	typedef struct		GravityMotor
	{
		int				posX;
		int				posY;
		float			angle;
		float			atraction;
		float			TAccel;
		int				JLose;
		int				FGain;
	}					GravityMotor;
	
	float getAccelerationX(GravityMotor* motor, float poids, float initSpeed);
	float getAccelerationY(GravityMotor* motor, float poids, float initSpeed);
	void attractToPoint(GravityMotor* motor, Drawable2D* d2D, RETRO_TYPE_REF(Retro2DApi) api);
	void updateWithGravity(GravityMotor* motor, Drawable2D* d2D, RETRO_TYPE_REF(Retro2DApi) api);
	void updateSpeedWithGravity(GravityMotor* motor, Drawable2D* d2D, RETRO_TYPE_REF(Retro2DApi) api);
	void updateSpeedAttractToPoint(GravityMotor* motor, Drawable2D* d2D, RETRO_TYPE_REF(Retro2DApi) api);
	void DeceleratingFromMotor(GravityMotor* motor, Drawable2D* d2D, RETRO_TYPE_REF(Retro2DApi) api);
	
#ifdef		__cplusplus
}
#endif

#endif
