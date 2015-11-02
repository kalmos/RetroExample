/*
** Colider.h for SL
**
** Made by lucas stefas
** Login   stefas_l
**
** Started on 22/06/2015 23:04
*/

#ifndef		__Colider_H__
#define		__Colider_H__

#ifdef		__cplusplus
extern "C" {
#endif

#include "Physique.h"
	
	typedef Drawable2D* Drawable2DPtr;
	
	typedef struct			RetroTileColider
	{
		const RetroUInt32*	tileMap;
		Drawable2D*			item;
		int*				color;
		unsigned int		tileSizeX;
		unsigned int		tileSizeY;
		unsigned int		tileMapSizeX;
		unsigned int		tileMapSizeY;
	}						RetroTileColider;
	
	typedef	struct		Retro_Colider
	{
		Drawable2D*		item;
		Drawable2DPtr*	vectorColider;
		ColisionType*	importantColision;
	}					Retro_Colider;
	
	RetroUInt32		getSizeColisionTypeVector(ColisionType* vector);
	int				putInColisionTypeVector(RETRO_TYPE_REF(ColisionType*) vector, ColisionType data, const size_t num);
	ColisionType	getItemColisionTypeVector(ColisionType* vector, const size_t num);
	ColisionType*	getColisionTypePtrVector(ColisionType* vector, const size_t num);
	void			freeColisionTypeVector(RETRO_TYPE_REF(ColisionType*) vector);
	void			reserveColisionTypeVector(RETRO_TYPE_REF(ColisionType*) vector, RetroUInt32 size);
	void			resizeColisionTypeVector(RETRO_TYPE_REF(ColisionType*) vector, RetroUInt32 newSize);
	
	RetroUInt32		getSizeDrawable2DPtrVector(Drawable2DPtr* vector);
	int				putInDrawable2DPtrVector(RETRO_TYPE_REF(Drawable2DPtr*) vector, Drawable2DPtr data, const size_t num);
	Drawable2DPtr	getItemDrawable2DPtrVector(Drawable2DPtr* vector, const size_t num);
	Drawable2DPtr*	getDrawable2DPtrPtrVector(Drawable2DPtr* vector, const size_t num);
	void			freeDrawable2DPtrVector(RETRO_TYPE_REF(Drawable2DPtr*) vector);
	void			reserveDrawable2DPtrVector(RETRO_TYPE_REF(Drawable2DPtr*) vector, RetroUInt32 size);
	void			resizeDrawable2DPtrVector(RETRO_TYPE_REF(Drawable2DPtr*) vector, RetroUInt32 newSize);
	
	Retro_Colider*	newCollider(Drawable2D* principal, RetroUInt32 size);
	RetroUInt32		addCollider(Drawable2D* coll, ColisionType importantColl, Retro_Colider* colider);
	void			setCollider(int id, Drawable2D* coll, ColisionType importantColl, Retro_Colider* collider);
	void			removeCollider(int id, Retro_Colider* collider);
	void			setImportantColl(int id, ColisionType importantColl, Retro_Colider* collider);
	RetroUInt32		optimiseCollider(Retro_Colider* collider);
	void			deleteCollider(Retro_Colider** collider);
	ColisionType	runCollider(Retro_Colider* collider);
	int				runPreciseCollider(Retro_Colider* collider, ColisionType** retColl);
	
	ColisionType	runSquareCollider(Retro_Colider* collider);
	RetroBool		runFastSquareCollider(Retro_Colider* collider);
	void			runPreciseSquareCollider(Retro_Colider* collider, ColisionType* retColl);
	void			runFastPreciseSquareCollider(Retro_Colider* collider, ColisionType* retColl);
	
	ColisionType	runCircleCollider(int dst, Retro_Colider* collider);
	RetroBool	runFastCircleCollider(int dst, Retro_Colider* collider);
	void	runPreciseCircleCollider(int dst, Retro_Colider* collider, ColisionType* retColl);
	void	runFastPreciseCircleCollider(int dst, Retro_Colider* collider, ColisionType* retColl);
	
	
	
	RetroTileColider* newTileColider(Drawable2D* principal, const RetroUInt32* tileMap, RetroUInt32 size);
	RetroUInt32	addColorToTileColider(int color, RetroTileColider* colider);
	void setColorToTileColider(int id, int col, RetroTileColider* collider);
	void removeToTileColider(int id, RetroTileColider* collider);
	RetroUInt32	optimiseTileColider(RetroTileColider* collider);
	RetroBool	runTileMapCollider(RetroTileColider* collider, Drawable2D* sprite);
	ColisionType	runContourTileMapCollider(RetroTileColider* collider, Drawable2D* sprite);
	RetroBool	predictTileMapCollider(RetroTileColider* collider, Drawable2D* sprite, float* retX, float* retY, RETRO_TYPE_REF(Retro2DApi) api);
	ColisionType	predictContourTileMapCollider(RetroTileColider* collider, Drawable2D* sprite, float* retX, float* retY, RETRO_TYPE_REF(Retro2DApi) api);
	
	ColisionType	runCenterContourTileMapCollider(RetroTileColider* collider, Drawable2D* sprite);
	RetroBool	runCenterTileMapCollider(RetroTileColider* collider, Drawable2D* sprite);
	ColisionType	predictCenterContourTileMapCollider(RetroTileColider* collider, Drawable2D* sprite, float* retX, float* retY, RETRO_TYPE_REF(Retro2DApi) api);
	RetroBool	predictCenterTileMapCollider(RetroTileColider* collider, Drawable2D* sprite, float* retX, float* retY, RETRO_TYPE_REF(Retro2DApi) api);
	
	
	RetroBool	testDownTileMapCollider(RetroTileColider* collider, Drawable2D* sprite);
	RetroBool	testUpTileMapCollider(RetroTileColider* collider, Drawable2D* sprite);
	RetroBool	testRightTileMapCollider(RetroTileColider* collider, Drawable2D* sprite);
	RetroBool	testLeftTileMapCollider(RetroTileColider* collider, Drawable2D* sprite);
	
	RetroBool	predictDownTileMapCollider(RetroTileColider* collider, Drawable2D* sprite, float* retX, RETRO_TYPE_REF(Retro2DApi) api);
	RetroBool	predictUpTileMapCollider(RetroTileColider* collider, Drawable2D* sprite, float* retX, RETRO_TYPE_REF(Retro2DApi) api);
	RetroBool	predictRightTileMapCollider(RetroTileColider* collider, Drawable2D* sprite, float* retY, RETRO_TYPE_REF(Retro2DApi) api);
	RetroBool	predictLeftTileMapCollider(RetroTileColider* collider, Drawable2D* sprite, float* retY, RETRO_TYPE_REF(Retro2DApi) api);
	
	RetroBool	testLeftCenterTileMapCollider(RetroTileColider* collider, Drawable2D* sprite);
	RetroBool	testRightCenterTileMapCollider(RetroTileColider* collider, Drawable2D* sprite);
	RetroBool	testUpCenterTileMapCollider(RetroTileColider* collider, Drawable2D* sprite);
	RetroBool	testDownCenterTileMapCollider(RetroTileColider* collider, Drawable2D* sprite);

	RetroBool	predictLeftCenterTileMapCollider(RetroTileColider* collider, Drawable2D* sprite, float* retX, RETRO_TYPE_REF(Retro2DApi) api);
	RetroBool	predictRightCenterTileMapCollider(RetroTileColider* collider, Drawable2D* sprite, float* retX, RETRO_TYPE_REF(Retro2DApi) api);
	RetroBool	predictUpCenterTileMapCollider(RetroTileColider* collider, Drawable2D* sprite, float* retY, RETRO_TYPE_REF(Retro2DApi) api);
	RetroBool	predictDownCenterTileMapCollider(RetroTileColider* collider, Drawable2D* sprite, float* retY, RETRO_TYPE_REF(Retro2DApi) api);
	
#ifdef		__cplusplus
}
#endif

#endif
