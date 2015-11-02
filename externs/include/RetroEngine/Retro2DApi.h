/*
** Retro2DApi.h for SL
**
** Made by lucas stefas
** Login   stefas_l
**
** Started on 20/05/13 14:52 2013 by lucas stefas
*/

/**
 * @file
 *
 * @ingroup Engine2D
 *
 * @brief Engine2D
 */

#ifndef		__Retro2DApi_H__
#define		__Retro2DApi_H__

#ifdef		__cplusplus
extern "C" {
#endif
    
#	include <RetroEngine/RetroDefine.h>
#	include "EngineType.h"
#	include "EngineDefine.h"
	
#	ifndef MARK_AS_DEPRECATED
#			define	MARK_AS_DEPRECATED(func, msg) func;
#	endif
		
	/**
	 * @defgroup Engine2D Engine2D
	 *
	 * @ingroup UpperLevelGroup
	 *
	 * @brief The RetroList add an easy way to use List.
	 *
	 * @{
	 */
	
	/**
	 * @defgroup Engine2DType Type
	 *
	 * @ingroup Engine2D
	 *
	 * @brief The RetroList add an easy way to use List.
	 *
	 * @{
	 */
	
	typedef struct		Drawable2DList
	{
		Drawable2D		data;
		size_t			num;
		struct Drawable2DList	*next;
	}					Drawable2DList;
	
	typedef struct		RetroFontList
	{
		RetroFont		data;
		size_t			num;
		struct RetroFontList	*next;
	}					RetroFontList;
	
	typedef struct	ComplexIdList
	{
		ComplexId	data;
		size_t		num;
		struct ComplexIdList	*next;
	}				ComplexIdList;
	
	/**
	 * @brief Contain all needed for start rendering.
	 *
	 * An object passed to all funcion for playing with your scene.
	 * You can look at it, but don't directly use it.
	 */
    typedef struct		Retro2DApi
	{
        /**
		 * @brief All list of your drawable, used only with *_RL function.
		 */
		Drawable2DList	AllList[ALLLIST];
		
		/**
		 * @brief All vector of your drawable, used only with *_RV function.
		 */
		Drawable2D*		AllVect[ALLLIST];
		
		RetroFontList		AllFont;
		
		/**
		 * @brief All the Id for complexe things. Used only with *_RL function
		 */
		ComplexIdList	AllIdList[ALLLIST];
		
		/**
		 * @brief All the Id for complexe things. Used only with *_RL function
		 */
		ComplexId*	AllIdVect[ALLLIST];
		
		
		
		/**
		 * @brief The camera position.
		 */
        Camera			cam;
		
		/**
		 * @brief All your screen info.
		 */
		Info*			info;
		
		/**
		 * @brief the number of frame per seconde
		 */
		RetroUInt		TPI;
		
		/**
		 * @brief the number of frame per seconde
		 */
		RetroUInt		IPS;
		
		/**
		 * @brief RetroTrue if GlExt is enabled
		 */
		RetroBool		glExtEnabled;
		
		/**
		 * @brief the Shader used for tilemap
		 */
		RetroUInt		shader;
		
		/**
		 * @brief the Program used for the tilemap shader
		 */
		RetroUInt		program;
		
		RetroUInt fbo, fbo_texture, fbo_depth;
		
    }					Retro2DApi;
	
	/** @} */
	
	/**
	 * @defgroup Engine2DFunction Function
	 *
	 * @ingroup Engine2D
	 *
	 * @brief The RetroList add an easy way to use List.
	 *
	 * @{
	 */
	
	/* Retro2DApi.c */
	
	/**
	 * @brief set the maximum size of storage, work only in Vector Mode.
	 * 
	 * @param[in] lDrawable2D The vector you want to change his size.
	 * @param[in] newSize New size.
	 * @param[in, out] api Your api.
	 */
	void		resizeUsableThing(const enumList lDrawable2D, int newSize, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* sprite4.c */
	
	/**
	 * @brief Delete all the things you have on screen.
	 *
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
	int			RetroResetAll(RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Delete specific list.
	 *
	 * @param[in] lDrawable2D The list you want to delete
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
	int			RetroResetDrawable2D(enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
    
    /* sprite.c */
	
	/**
	 * @brief Create a new drawable thing.
	 *
	 * @param[in] id The id of the new item.
	 * @param[in] obj A small object describing your thing.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval The new Drawable2D on sucess (for optimisation purpose).
	 */
    Drawable2D*		RetroCreateDrawable2D(const RetroUInt id, RETRO_TYPE_REF_CONST(Object2D) obj, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Add a color to your item.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] colorRGB A color in 0xRRGGBB format.
	 * @param[in] collorMasc the specific part of the color to change (deffault is RETRO_ALL_CORNER_COLOR.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
    int			RetroAddDrawable2DColor(const RetroUInt id, const RetroInt colorRGB, const int collorMasc, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
    
    /* sprite2.c */
	
	/**
	 * @brief Set a new background position for your item.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] z the new Z position.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
    void		RetroDrawable2DSetBack(const RetroUInt id, const RetroUInt z, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);

    MARK_AS_DEPRECATED(void RetroDrawable2DSetProfond(const RetroUInt id, RetroFloat z,
													  const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api),
					   "use void		RetroDrawable2DSetBack(const RetroUInt id, const RetroUInt z, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api) instead")
    
    /* sprite3.c */
    
	/**
	 * @brief Delete a specific thing.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
	int			RetroDelDrawable2D(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);

    /**
	 * @brief Start a new Animation.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] from The first fram of your animation.
	 * @param[in] to The last fram of your animation.
	 * @param[in] sens The sens of the animation.
	 * @param[in] tempo The time between each fram.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
	int			RetroStartAnimDrawable2D(const RetroUInt id, const RetroUChar from, const RetroUChar to, const RetroBool sens,
										 const RetroUInt tempo, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
    
    /* sprite4.c */
	
	/**
	 * @brief get the curent fram number.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval on succes, return the fram number. or return -1.
	 */
    int			RetroGetDrawable2DFrame(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
    
    /* sprite5.c */
	
	/**
	 * @brief Change the vertical flip state of the asociated texture.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
    int         RetroSetDrawable2DVFlip(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Change the horizontal flip state of the asociated texture.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
    int         RetroSetDrawable2DHFlip(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Resise an element.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] x The new size on X axys.
	 * @param[in] y The new size on Y axys.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
    void        RetroSetSizeDrawable2DXY(const RetroUInt id, const RetroUInt x, const RetroUInt y, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Resise an element.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] x The new size on X axys.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
    void        RetroSetSizeDrawable2DX(const RetroUInt id, const RetroUInt x, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Resise an element.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] y The new size on Y axys.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
    void        RetroSetSizeDrawable2DY(const RetroUInt id, const RetroUInt y, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* sprite7.c */
	
	/**
	 * @brief Set the rotation for an element.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] angle The new angle in degret.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	void		RetroRotateFromZ(const RetroUInt id, int angle, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* spriteGetter.c */
	
	/**
	 * @brief Retrieve the X coordinate of an element.
	 * @param[in] id The id of the item.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval The X coordinate of an element or ERRCODE
	 */
	int		RetroGetDrawable2DX(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Retrieve the Y coordinate of an element.
	 * @param[in] id The id of the item.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval The Y coordinate of an element or ERRCODE
	 */
	int		RetroGetDrawable2DY(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Retrieve the coordinate of an element.
	 * @param[in] id The id of the item.
	 * @param[in] x Non null ptr to write the x coordinate.
	 * @param[in] y Non null ptr to write the y coordinate.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval VALIDCODE on succes or ERRCODE
	 */
	int		RetroGetDrawable2DXY(const RetroUInt id, RETRO_TYPE_REF(int) x, RETRO_TYPE_REF(int) y, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Retrieve the depth.
	 * @param[in] id The id of the item.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval The depth of an element or ERRCODE
	 */
	int		RetroGetDrawable2DDepth(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Retrieve the width.
	 * @param[in] id The id of the item.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval The width of an element or ERRCODE
	 */
	int		RetroGetDrawable2DWidth(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Retrieve the height.
	 * @param[in] id The id of the item.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval The height of an element or ERRCODE
	 */
	int		RetroGetDrawable2DHeight(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Retrieve the size of an element.
	 * @param[in] id The id of the item.
	 * @param[in] width Non null ptr to write the width.
	 * @param[in] height Non null ptr to write the height.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval VALIDCODE on succes or ERRCODE
	 */
	int		RetroGetDrawable2DSize(const RetroUInt id, RETRO_TYPE_REF(int) width, RETRO_TYPE_REF(int) height, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Retrieve the size of an element.
	 * @param[in] id The id of the item.
	 * @param[in] colorCorner the color corner to retrieve.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval Corner color or ERRCODE
	 */
	int		RetroGetDrawable2DColor(const RetroUInt id, int colorCorner, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	
	/**
	 * @brief Retrieve the ptr of an element.
	 * @param[in] id The id of the item.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval ptr of this eelement or NULL
	 */
	Drawable2D*	RetroGetDrawable2DPtr(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	
	float RetroGetNextXPos(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	float RetroGetNextYPos(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	float RetroGetNextXYPos(const RetroUInt id,  float* x, float* y, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* spriteSetter.c */
	
	/**
	 * @brief Set a new position for your item.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] x the new X position.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
	int			RetroSetDrawable2DX(const RetroUInt id, const RetroInt x, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Set a new position for your item.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] y the new Y position.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
    int			RetroSetDrawable2DY(const RetroUInt id, const RetroInt y, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Set a new position for your item.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] x the new X position.
	 * @param[in] y the new Y position.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
    int			RetroSetDrawable2DXY(const RetroUInt id, const RetroInt x, const RetroInt y, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* spriteMove.c */
	
	/**
	 * @brief Change position for your item.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] x Velocity on the X axis in pixel/second.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
	int		RetroMoveDrawable2DX(const RetroUInt id, const RetroFloat x, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Change position for your item.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] y Velocity on the Y axis in pixel/second.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
	int		RetroMoveDrawable2DY(const RetroUInt id, const RetroFloat y, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Change position for your item.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] x Velocity on the X axis in pixel/second.
	 * @param[in] y Velocity on the Y axis in pixel/second.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
	int		RetroMoveDrawable2DXY(const RetroUInt id, const RetroFloat x, const RetroFloat y, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* spriteAdd.c */
	
	/**
	 * @brief add to position for your item.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] x position to add on the X axis.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
	int		RetroAddDrawable2DX(const RetroUInt id, const RetroFloat x, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief add to position for your item.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] y position to add on the Y axis.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
	int		RetroAddDrawable2DY(const RetroUInt id, const RetroFloat y, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief add to position for your item.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] x position to add on the X axis.
	 * @param[in] y position to add on the Y axis.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 * @retval 0 on sucess.
	 */
	int		RetroAddDrawable2DXY(const RetroUInt id, const RetroFloat x, const RetroFloat y, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	
    /* anim.c */
	
	/**
	 * @brief Add a Texture to an element.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] nbX Number of frame on X axys.
	 * @param[in] nbY Number of frame on Y axys.
	 * @param[in] texture The id of the the texture.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	void		RetroAddDrawable2DTex(const RetroUInt id, const RetroUChar nbX, const RetroUChar nbY,
									const RetroUInt texture, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Add a Texture tileset to an element.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] nbX Number of frame on X axys.
	 * @param[in] nbY Number of frame on Y axys.
	 * @param[in] texture The id of the the tileset.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	void		RetroAddDrawable2DTileSet(const RetroUInt id, const RetroUInt nbX, const RetroUInt nbY,
										  const RetroUInt texture, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Add a Texture Tilemap to an element.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] nbX Number of frame on X axys.
	 * @param[in] nbY Number of frame on Y axys.
	 * @param[in] texture The id of the the tilemap.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	void		RetroAddDrawable2DTileMap(const RetroUInt id, const RetroUInt nbX, const RetroUInt nbY,
										  const RetroUInt texture, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Delete a Texture asociated to an element.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
    int			RetroDeleteDrawable2DText(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Stop the animation of an element.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
    void		RetroStopAnimDrawable2D(const RetroUInt id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
    
    /* anim2.c */
	
	/**
	 * @brief Change the frame used by an element.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] framNum The new frame number.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
    void		RetroChangeFramDrawable2D(const RetroUInt id, const RetroUChar framNum,
										  const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Change the row of frame used by an element.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] rowNum The new row number.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
    void		RetroChangeRowDrawable2D(const RetroUInt id, const RetroUChar rowNum, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Change the frame used by an element.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] framNum The new frame number.
	 * @param[in] rowNum The new row number.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
    void		RetroChangeFramRowDrawable2D(const RetroUInt id, const RetroUChar framNum,
											 const RetroUChar rowNum, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* anim3.c */
	
	/**
	 * @brief animate thhe tilemap.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] nbFram number of frame.
	 * @param[in] tempo frame per seconde.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	int		RetroAddTiledAnim(const RetroUInt id, const RetroUChar nbFram, const RetroUInt tempo,
							  const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief animate the tilemap7.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] nbFram number of frame.
	 * @param[in] tempo frame per seconde.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	int		RetroAddTiled7Anim(const RetroUInt id, const RetroUChar nbFram, const RetroUInt tempo,
							   const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* animScroll.c */
	
	/**
	 * @brief considere the item has a scolling one and set his position.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] v Vertical position of the item between 0 and 1.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	int		RetroUseHasInfinitVScroll(int id, float v, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief considere the item has a scolling one and set his position.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] h Vertical position of the item between 0 and 1.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	int		RetroUseHasInfinitHScroll(int id, float h, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief considere the item has a scolling one and set his position.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] v Vertical position of the item between 0 and 1.
	 * @param[in] h Vertical position of the item between 0 and 1.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	int		RetroUseHasInfinitScroll(int id, float v, float h, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief considere the item has a scolling one and move it's position.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] v Vertical velocity in texture size / second.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	int		RetroMoveInfinitVScroll(int id, float v, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief considere the item has a scolling one and move it's position.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] h Horizontal velocity in texture size / second.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	int		RetroMoveInfinitHScroll(int id, float h, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief considere the item has a scolling one and move it's position.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] v Vertical velocity in texture size / second.
	 * @param[in] h Horizontal velocity in texture size / second.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	int		RetroMoveInfinitScroll(int id, float v, float h, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* animScroll.c */
	
	/**
	 * @brief considere the item has a scolling one and move it's position.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] v Vertical velocity in texture size / second.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	int		RetroAddInfinitVScroll(int id, float v, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief considere the item has a scolling one and move it's position.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] h Horizontal velocity in texture size / second.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	int		RetroAddInfinitHScroll(int id, float h, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief considere the item has a scolling one and add to it's position.
	 *
	 * @param[in] id The id of the the item.
	 * @param[in] v Vertical velocity in texture size / second.
	 * @param[in] h Horizontal velocity in texture size / second.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	int		RetroAddInfinitScroll(int id, float v, float h, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* mode7.c */
	
	/**
	 * @brief create a mode7 like background witch look like perspectized plan.
	 *
	 * @param[in] id Id of mode7
	 * @param[in] m7 structure describing all the important componant for generating a mode7 background.
	 * @param[in] reductionWidth reduction reduct ratio on width.
	 * @param[in] reductionHeight reduction reduct ratio on height.
	 * @param[in] lDrawable2D The list for your item, must be MODE7 or TILEMAP7
	 * @param[in, out] api Your api.
	 * @retval return number of created things.
	 */
	int RetroCreateMode7Plan(int id, RETRO_TYPE_REF_CONST(Mode7) m7, float reductionWidth, float reductionHeight, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief create a mode7 like background witch look like an alf tube.
	 *
	 * @param[in] id Id of mode7
	 * @param[in] m7 structure describing all the important componant for generating a mode7 background.
	 * @param[in] reductionWidth reduction reduct ratio on width.
	 * @param[in] reductionHeight reduction reduct ratio on height.
	 * @param[in] lDrawable2D The list for your item, must be MODE7 or TILEMAP7
	 * @param[in, out] api Your api.
	 * @retval return number of created things.
	 */
	int RetroCreateMode7Tube(int id, RETRO_TYPE_REF_CONST(Mode7) m7, float reductionWidth, float reductionHeight, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief create a mode7 like background witch look like a normal background.
	 *
	 * @param[in] id Id of mode7
	 * @param[in] m7 structure describing all the important componant for generating a mode7 background.
	 * @param[in] lDrawable2D The list for your item, must be MODE7 or TILEMAP7
	 * @param[in, out] api Your api.
	 * @retval return number of created things.
	 */
	int RetroCreateMode7(int id, RETRO_TYPE_REF_CONST(Mode7) m7, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief create a mode7 like background same as RetroCreateMode7 but modify it using your function func.
	 *
	 * @param[in] id Id of mode7
	 * @param[in] m7 structure describing all the important componant for generating a mode7 background.
	 * @param[in] func your modifier.
	 * @param[in] lDrawable2D The list for your item, must be MODE7 or TILEMAP7
	 * @param[in, out] api Your api.
	 * @retval return number of created things.
	 * @see RetroCreateMode7
	 */
	int RetroCreateSpecialMode7(int id, RETRO_TYPE_REF_CONST(Mode7) m7, void (*func)(int, Drawable2D*), const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief delete a mode7 like background same as RetroDelDrawable2D but for mode7.
	 *
	 * @param[in] id Id of mode7
	 * @param[in] lDrawable2D The list for your item, must be MODE7 or TILEMAP7
	 * @param[in, out] api Your api.
	 * @retval return number of created things.
	 * @see RetroDelDrawable2D
	 */
	int RetroDeleteMode7(int id, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* mode7Rot.c */
	
	/**
	 * @brief rotate all the mode7 sprite, work like RetroRotateFromZ for a normal Drawable2D thing. work only for mode7.
	 *
	 * @param[in] id Id of mode7.
	 * @param[in] angle angle of rotation in degre.
	 * @param[in] lDrawable2D The list for your item, must be MODE7 or TILEMAP7
	 * @param[in, out] api Your api.
	 * @see RetroRotateFromZ
	 */
	void RetroMode7Rotate(const RetroUInt id, int angle, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief rotate the texture. work only for mode7.
	 *
	 * @param[in] id Id of mode7.
	 * @param[in] angle angle of rotation in degre.
	 * @param[in] lDrawable2D The list for your item, must be MODE7 or TILEMAP7
	 * @param[in, out] api Your api.
	 */
	void RetroTextureRotateMode7(const RetroUInt id, int angle, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief make a special effect to a mode7.
	 *
	 * @param[in] id Id of mode7.
	 * @param[in] func function witch aply the effect.
	 * @param[in] param param to the funcion.
	 * @param[in] lDrawable2D The list for your item, must be MODE7 or TILEMAP7
	 * @param[in, out] api Your api.
	 */
	void RetroSpecialMode7(const RetroUInt id, void (*func)(int, Drawable2D*, void*), void* param, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* mode7Tex.c */
	
	/**
	 * @brief Add a Texture to a mode7 element.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] nbX Number of frame on X axys.
	 * @param[in] nbY Number of frame on Y axys.
	 * @param[in] texture The id of the the texture.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	void		RetroSetMode7Texture(const RetroUInt id, const RetroUChar nbX, const RetroUChar nbY,
									 const RetroUInt texture, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Add a tileset to a mode7 element.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] nbX Number of frame on X axys.
	 * @param[in] nbY Number of frame on Y axys.
	 * @param[in] texture The id of the the tileset texture.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	void		RetroSetMode7TileSet(const RetroUInt id, const RetroUInt nbX, const RetroUInt nbY,
									 const RetroUInt texture, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Add a tilemap to a mode7 element.
	 *
	 * @param[in] id The id of the item.
	 * @param[in] nbX Number of frame on X axys.
	 * @param[in] nbY Number of frame on Y axys.
	 * @param[in] texture The id of the the tilemap texture.
	 * @param[in] lDrawable2D The list for your item.
	 * @param[in, out] api Your api.
	 */
	void		RetroSetMode7TileMap(const RetroUInt id, const RetroUInt nbX, const RetroUInt nbY,
									 const RetroUInt texture, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* RetroWaitForVBL.c */
	
	/**
	 * @brief prepar all thing to draw on the screen, need to be call for each frame.
	 *
	 * @param[in, out] api Your api.
	 * @retval on success, return -1337
	 */
    int         RetroPrepareToDraw(RETRO_TYPE_REF_CONST(Retro2DApi) api);
	
	
	
	struct RetroSystem;
	
	int         RetroDrawnOnScreenList(RETRO_TYPE_REF(Retro2DApi) api);
	int         RetroDrawnOnScreenVector(RETRO_TYPE_REF(Retro2DApi) api);
	int         RetroCleanDrawnOnScreenList(RETRO_TYPE_REF(Retro2DApi) api);
	int         RetroCleanDrawnOnScreenVector(RETRO_TYPE_REF(Retro2DApi) api);
	int         RetroDrawnOnScreenOLD(RETRO_TYPE_REF(Retro2DApi) api/*, RetroSystem* system*/);
	
	/**
	 * @brief draw on the screen, need to be call for each frame.
	 *
	 * @param[in, out] api Your api.
	 * @retval on success, return -1337
	 */
	extern int	(*RetroDrawnOnScreen)(RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief clean screen before redrawing.
	 *
	 * @param[in, out] api Your api.
	 * @retval on success, return -1337
	 */
	extern int	(*RetroCleanDrawnOnScreen)(RETRO_TYPE_REF(Retro2DApi) api);
	
	/*
	 * @brief draw on the screen, need to be call for each frame.
	 *
	 * @param[in, out] api Your api.
	 * @retval on success, return -1337
	 */
//#	define		RetroDrawnOnScreen(api) RetroDrawnOnScreenList(api)
//#	define		RetroDrawnOnScreen(api) RetroDrawnOnScreenVector(api)
	
	/**
	 * @brief finishing the drawing sequance, need to be call for each frame.
	 *
	 * @retval on success, return -1337
	 */
    int         RetroendDrawn();
	
	/* text.c */
	
	
	/**
	 * @brief print a text using a specific font. work a little like printf.
	 *
	 * @param[in] id Id of the text on screen.
	 * @param[in] text UTF-8 string to write.
	 * @param[in] obj A small descriptor to set where the text start and the size of each char.
	 * @param[in] fontId Id of the font to use.
	 * @param[in,out] api Your api.
	 * @param[in] ... same as printf.
	 * @retval number of writed char and id to use for the next text to write.
	 * @see RetroAddFont
	 */
#	ifndef  Windows
	int	RetroWrite(RetroUInt id, const char* text, RETRO_TYPE_REF_CONST(Object2D) obj, RetroUInt fontId, RETRO_TYPE_REF(Retro2DApi) api, ...) __attribute__((format(printf, 2, 6)));
#	else
	int	RetroWrite(RetroUInt id, const char* text, RETRO_TYPE_REF_CONST(Object2D) obj, RetroUInt fontId, RETRO_TYPE_REF(Retro2DApi) api, ...);
#	endif
	
	/**
	 * @brief delete an existing writed text.
	 *
	 * @param[in] id Id of the text on screen.
	 * @param[in,out] api Your api.
	 */
	int RetroDeleteText(int id, RETRO_TYPE_REF(Retro2DApi) api);
	
	/* text2.c */
	
	/**
	 * @brief set color for all char.
	 *
	 * @param[in] id Id of the text on screen.
	 * @param[in] colorRGB A color in 0xRRGGBB format.
	 * @param[in] collorMasc the specific part of the color to change (deffault is RETRO_ALL_CORNER_COLOR.
	 * @param[in,out] api Your api.
	 */
	int RetroSetTextColor(const RetroUInt id, const RetroInt colorRGB, const int collorMasc, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief delete all existing writed text.
	 *
	 * @param[in,out] api Your api.
	 */
	int RetroDeleteAllText(RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief nothing for now
	 */
	ComplexId			getComplexIdItem(RETRO_TYPE_REF_CONST(ComplexIdList) list, const size_t num);
	
	/** @} */
	
	/** @} */
#ifdef		__cplusplus
}
#endif

#endif
