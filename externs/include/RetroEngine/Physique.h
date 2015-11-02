/*
** Physique.h for SL
**
** Made by lucas stefas
** Login   stefas_l
**
** Started on 22/08/13 16:47 2013 by lucas stefas
*/

#ifndef		__Physique_H__
#define		__Physique_H__

#ifdef		__cplusplus
extern "C" {
#endif

#	include <RetroEngine/RetroType.h>
#	include <RetroEngine/Retro2DApi.h>
	
	typedef	enum	ColisionType
	{
		NONE_COLIDE =			0,
		FIRST_COLIDE_UP =		1,
		FIRST_COLIDE_DOWN =		2,
		FIRST_COLIDE_LEFT =		4,
		FIRST_COLIDE_RIGHT =	8,
		SECOND_COLIDE_UP =		16,
		SECOND_COLIDE_DOWN =	32,
		SECOND_COLIDE_LEFT =	64,
		SECOND_COLIDE_RIGHT =	128,
		COLIDE =				256,
	}				ColisionType;
	
	/* Collider.c */
	
	/**
	 *
	 */
	RetroUInt32     getSizeDrawable2DVector(Drawable2D* vector);
	
	/**
	 *
	 */
	int				RetroColideAllList(Drawable2DList* sprites);
	
	/**
	 *
	 */
	void			RetroColideAllVec(Drawable2D* sprites);
	
	/**
	 *
	 */
	ColisionType	RetroCircularColidePrecise(int distance, R_T_R(Drawable2D) obj1, R_T_R(Drawable2D) obj2);
	
	/**
	 *
	 */
	ColisionType	RetroSquareColidePrecise(R_T_R(Drawable2D) obj1, R_T_R(Drawable2D) obj2);
	
	/**
	 *
	 */
	RetroBool	RetroCircularColide(int distance, R_T_R(Drawable2D) obj1, R_T_R(Drawable2D) obj2);
	
	/**
	 *
	 */
	RetroBool	RetroSquareColide(R_T_R(Drawable2D) obj1, R_T_R(Drawable2D) obj2);
	
#ifdef		__cplusplus
}
#endif

#endif
