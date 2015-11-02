/*
** RetroDefine.h for SL
**
** Made by lucas stefas
** Login   stefas_l
**
** Started on 22/11/2013 14:00 2013 by lucas stefas
*/

/**
 * @file
 *
 * @ingroup RetroUtils
 *
 * @brief RetroEngine
 */

#ifndef		__RetroDefine_H__
#define		__RetroDefine_H__

#ifdef		__cplusplus
extern "C" {
#endif
	
	/**
	 * @defgroup RetroUtils RetroUtils
	 *
	 * @ingroup UpperLevelGroup
	 *
	 * @brief The RetroUtils add some usefull thing.
	 *
	 *
	 */
	
	/**
	 * @defgroup RetroDefine Define
	 *
	 * @ingroup RetroUtils
	 *
	 * @brief The RetroUtils add some usefull thing.
	 *
	 * @{
	 */
	
	/**
	 * @brief Representing a black color in 0xRRGGBBAA stile.
	 *
	 * Representing a black color in 0xRRGGBBAA stile.
	 */
#	define	RETRO_COLOR_BLACK			0x00000000
	
	/**
	 * @brief Representing a red color in 0xRRGGBBAA stile.
	 *
	 * Representing a red color in 0xRRGGBBAA stile.
	 */
#	define	RETRO_COLOR_RED				0xFF000000
	
	/**
	 * @brief Representing a green color in 0xRRGGBBAA stile.
	 *
	 * Representing a green color in 0xRRGGBBAA stile.
	 */
#	define	RETRO_COLOR_GREEN			0x00FF0000
	
	/**
	 * @brief Representing a yellow color in 0xRRGGBBAA stile.
	 *
	 * Representing a yellow color in 0xRRGGBBAA stile.
	 */
#	define	RETRO_COLOR_YELLOW			0xFFFF0000
	
	/**
	 * @brief Representing a blue color in 0xRRGGBBAA stile.
	 *
	 * Representing a blue color in 0xRRGGBBAA stile.
	 */
#	define	RETRO_COLOR_BLUE			0x0000FF00
	
	/**
	 * @brief Representing a magenta color in 0xRRGGBBAA stile.
	 *
	 * Representing a magenta color in 0xRRGGBBAA stile.
	 */
#	define	RETRO_COLOR_MAGENTA			0xFF00FF00
	
	/**
	 * @brief Representing a cyan color in 0xRRGGBBAA stile.
	 *
	 * Representing a cyan color in 0xRRGGBBAA stile.
	 */
#	define	RETRO_COLOR_CYAN			0x00FFFF00
	
	/**
	 * @brief Representing a white color in 0xRRGGBBAA stile.
	 *
	 * Representing a white color in 0xRRGGBBAA stile.
	 */
#	define	RETRO_COLOR_WHITE			0xFFFFFF00
	
	/**
	 * @brief A C equivalent of referenced type.
	 *
	 * A C equivalent of referenced type.
	 */
#	define	RETRO_TYPE_REF(type)		type * const
	
	/**
	 * @brief A C equivalent of constant referenced type.
	 *
	 * A C equivalent of constant referenced type.
	 */
#	define	RETRO_TYPE_REF_CONST(type)	const type * const
	
	/**
	 * A C equivalent of referenced type.
	 * @see RETRO_TYPE_REF.
	 */
#	define	R_T_R(type)					RETRO_TYPE_REF(type)
	
	/**
	 * A C equivalent of constant referenced type.
	 *
	 * @see RETRO_TYPE_REF_CONST.
	 */
#	define	R_T_R_C(type)				RETRO_TYPE_REF_CONST(type)
	
	/**
	 * enum to change only the top left color
	 */
#	define	RETRO_UP_LEFT_COLOR			0x1
	
	/**
	 * enum to change only the top right color
	 */
#	define	RETRO_UP_RIGHT_COLOR		0x2
	
	/**
	 * enum to change only the bottom left color
	 */
#	define	RETRO_DOWN_LEFT_COLOR		0x4
	
	/**
	 * enum to change only the bottom right color
	 */
#	define	RETRO_DOWN_RIGHT_COLOR		0x8
	
	/**
	 * enum to change the up color
	 */
#	define RETRO_UP_COLOR				0x3
	
	/**
	 * enum to change the down color
	 */
#	define RETRO_DOWN_COLOR				0xC
	
	/**
	 * enum to change the left color
	 */
#	define RETRO_LEFT_COLOR				0x5
	
	/**
	 * enum to change the right color
	 */
#	define RETRO_RIGHT_COLOR			0xA
	
	/**
	 * enum to change all color
	 */
#	define RETRO_ALL_CONER_COLOR		0xF
	
	/**
	 * enum to select rander option
	 */
#	define RETRO_FIT_WINDOW_KEPT_RATIO	0
	
	/**
	 * enum to select rander option
	 */
#	define RETRO_FIT_WINDOW				1
	
	/**
	 * enum to select rander option
	 */
#	define RETRO_DONT_FIT_WINDOW		2
	
	/**
	 * enum to select rander option
	 */
#	define RETRO_DONT_FIT_WINDOW_CENTER	3
	
	/**
	 * enum to select storage mode
	 */
#	define RETRO_USE_VECTOR				RetroFalse

	/**
	 * enum to select storage mode
	 */
#	define RETRO_USE_LIST				RetroTrue
	
	/**
	 * absolute function in define
	 */
#	define RETRO_ABS(x) (x < 0) ? -x : x
	
#	ifdef Mac
		/**
		 * A portable way of marking a function as deprecated
		 */
#		define	MARK_AS_DEPRECATED(func, msg) func __attribute__ ((deprecated(msg)));
#	elif defined Linux
#		if __GNUC__ >= 4 && __GNUC_MINOR__ >= 5
			/**
			 * A portable way of marking a function as deprecated
			 */
#			define	MARK_AS_DEPRECATED(func, msg) func __attribute__ ((deprecated(msg)));
#		else
			/**
			 * A portable way of marking a function as deprecated
			 */
#			define	MARK_AS_DEPRECATED(func, msg) func __attribute__ ((deprecated()));
#		endif
#	elif defined Windows
		/**
		* A portable way of marking a function as deprecated
		*/
#		define	MARK_AS_DEPRECATED(func, msg) __declspec(deprecated(msg)) func;
#	else
		/**
		 * A portable way of marking a function as deprecated
		 */
#		define	MARK_AS_DEPRECATED(func, msg) func;
#	endif
	
	
	/** @} */
#ifdef		__cplusplus
}
#endif

#endif
