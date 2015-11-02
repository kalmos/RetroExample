/*
** RetroType.h for SL
**
** Made by lucas stefas
** Login   stefas_l
**
** Started on 22/11/2013 14:02 2013 by lucas stefas
*/

/**
 * @file
 *
 * @ingroup RetroUtils
 *
 * @brief RetroEngine
 */

#ifndef		__RetroType_H__
#define		__RetroType_H__

#ifdef		__cplusplus
extern "C" {
#endif

#	if defined(Windows) || defined(Darwin)
#		include	<stdint.h>
#		include	<stddef.h>
#	endif
	
#	if defined(Linux)
#		include	<stdint.h>
//#		include	<stddef.h>
#	endif
	
	/**
	 * @defgroup RetroType Type
	 *
	 * @ingroup RetroUtils
	 *
	 * @brief The RetroUtils add some usefull thing.
	 *
	 * @{
	 */
	
	/**
	 * @brief short way to write unsigned char.
	 *
	 * just a shorter way for writing unsigned char.
	 * @retval unsigned char
	 */
	typedef unsigned char			RetroUChar;
	
	/**
	 * @brief short way to write signed char.
	 *
	 * just a shorter way for writing signed char.
	 * @retval signed char
	 */
	typedef signed char				RetroChar;
	
	/**
	 * @brief short way to write unsigned int.
	 *
	 * just a shorter way for writing unsigned int.
	 */
	typedef unsigned int			RetroUInt;
	
	/**
	 * @brief short way to write signed int.
	 *
	 * just a shorter way for writing signed int.
	 */
	typedef signed int				RetroInt;

	/**
	 * @brief short way to write float.
	 *
	 * just a shorter way for writing float.
	 */
	typedef float					RetroFloat;
	
	/**
	 * @brief short way to write double.
	 *
	 * just a shorter way for writing double.
	 */
	typedef double					RetroDouble;
	
	/**
	 * @brief short way to write void*.
	 *
	 * just a shorter way for writing void*.
	 */
	typedef void*					RetroPtr;
	
	/**
	 * @brief Fake boolean implementation in C.
	 *
	 * Fake boolean implementation in C.
	 */
	typedef enum	RetroBool
	{

		RetroFalse = 0,
		RetroTrue = 1
	}				RetroBool;
	
	typedef char* CString;
	
#	if defined(_INT8_T) || defined(__int8_t_defined) || defined(_STDINT)
		
		/**
		 * @brief unsigned 8 bit int.
		 *
		 * A more comon way of using unsigned 8 bit int.
		 * if uint8_t doesn't truly exist, it
		 * will define it.
		 */
		typedef uint8_t						RetroUInt8;
	
		/**
		 * @brief 8 bit int.
		 *
		 * A more comon way of using 8 bit int.
		 * if uint8_t doesn't truly exist, it
		 * will define it.
		 */
		typedef int8_t						RetroInt8;

#	else
		//based on OSX 10.9
		/**
		 * @brief 8 bit int.
		 *
		 * A more comon way of using 8 bit int.
		 * if uint8_t doesn't truly exist, it
		 * will define it.
		 */
		typedef unsigned char				RetroUInt8;
	
		/**
		 * @brief 8 bit int.
		 *
		 * A more comon way of using 8 bit int.
		 * if uint8_t doesn't truly exist, it
		 * will define it.
		 */
		typedef signed char					RetroInt8;

#		if defined(Windows)
#			pragma message("warning: Retroint8 type doesnt truly exist, use it at your own risk")
#		else
#			warning Retroint8 type doesnt truly exist, use it at your own risk
#		endif
#	endif
	
#	if defined(_INT16_T) || defined(__int8_t_defined) || defined(_STDINT)
	
		/**
		 * @brief unsigned 16 bit int.
		 *
		 * A more comon way of using unsigned 16 bit int.
		 * if uint16_t doesn't truly exist, it
		 * will define it.
		 */
		typedef uint16_t					RetroUInt16;
	
		/**
		 * @brief 16 bit int.
		 *
		 * A more comon way of using 16 bit int.
		 * if uint16_t doesn't truly exist, it
		 * will define it.
		 */
		typedef int16_t						RetroInt16;
#	else
		//based on OSX 10.9
		/**
		 * @brief unsigned 16 bit int.
		 *
		 * A more comon way of using unsigned 16 bit int.
		 * if uint16_t doesn't truly exist, it
		 * will define it.
		 */
		typedef unsigned short				RetroUInt16;
	
		/**
		 * @brief 16 bit int.
		 *
		 * A more comon way of using 16 bit int.
		 * if uint16_t doesn't truly exist, it
		 * will define it.
		 */
		typedef signed short				RetroInt16;

#		if defined(Windows)
#			pragma message("warning: Retroint16 type doesnt truly exist, use it at your own risk")
#		else
#			warning Retroint16 type doesnt truly exist, use it at your own risk
#		endif
#	endif
	
#	if defined(_INT32_T) || defined(__int8_t_defined) || defined(_STDINT)
		/**
		 * @brief unsigned 32 bit int.
		 *
		 * A more comon way of using unsigned 32 bit int.
		 * if uint32_t doesn't truly exist, it
		 * will define it.
		 */
		typedef uint32_t					RetroUInt32;
	
		/**
		 * @brief 32 bit int.
		 *
		 * A more comon way of using 32 bit int.
		 * if uint32_t doesn't truly exist, it
		 * will define it.
		 */
		typedef int32_t						RetroInt32;
	
#	else
		//based on OSX 10.9
		/**
		 * @brief unsigned 32 bit int.
		 *
		 * A more comon way of using unsigned 32 bit int.
		 * if uint32_t doesn't truly exist, it
		 * will define it.
		 */
		typedef unsigned int				RetroUInt32;
	
		/**
		 * @brief 32 bit int.
		 *
		 * A more comon way of using 32 bit int.
		 * if uint32_t doesn't truly exist, it
		 * will define it.
		 */
		typedef signed int					RetroInt32;
	
#		if defined(Windows)
#			pragma message("warning: Retroint32 type doesnt truly exist, use it at your own risk")
#		else
#			warning Retroint32 type doesnt truly exist, use it at your own risk
#		endif
#	endif

#	if defined(_INT64_T) || defined(__int8_t_defined) || defined(_STDINT)
		/**
		 * @brief unsigned 64 bit int.
		 *
		 * A more comon way of using unsigned 64 bit int.
		 * if uint64_t doesn't truly exist, it
		 * will define it.
		 */
		typedef uint64_t					RetroUInt64;
	
		/**
		 * @brief 64 bit int.
		 *
		 * A more comon way of using 64 bit int.
		 * if uint64_t doesn't truly exist, it
		 * will define it.
		 */
		typedef int64_t						RetroInt64;

#	else
		//based on OSX 10.9
		/**
		 * @brief unsigned 64 bit int.
		 *
		 * A more comon way of using unsigned 64 bit int.
		 * if uint64_t doesn't truly exist, it
		 * will define it.
		 */
		typedef unsigned long long			RetroUInt64;
	
		/**
		 * @brief 64 bit int.
		 *
		 * A more comon way of using 64 bit int.
		 * if uint64_t doesn't truly exist, it
		 * will define it.
		 */
		typedef signed long long			RetroInt64;
#		if defined(Windows)
#			if defined(ARCHx86_64)
#				pragma message("warning: Retroint64 type doesnt truly exist, use it at your own risk")
#			elif defined(ARCHx86)
#				pragma message("warning: you are on 32bit system, do not use Retroint64t")
#			else
#				pragma message("warning: can not see what system it was, use Retroint64t at your own risk")
#			endif
#		else
#			if defined(ARCHx86_64)
#				warning Retroint64 type doesnt truly exist, use it at your own risk
#			elif defined(ARCHx86)
#				warning you are on 32bit system, do not use Retroint64t
#			else
#				warning can not see what system it was, use Retroint64t at your own risk
#			endif
#		endif
#	endif
	/** @} */
#ifdef		__cplusplus
}
#endif

#endif