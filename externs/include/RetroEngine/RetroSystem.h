/*
** RetroSystem.h for SL
**
** Made by lucas stefas
** Login   stefas_l
**
** Started on 17/05/13 11:31 2013 by lucas stefas
*/

/**
 * @file
 *
 * @ingroup RetroSystem
 *
 * @brief RetroSystem
 */

#ifndef		__RetroSystem_H__
#define		__RetroSystem_H__

#ifdef		__cplusplus
extern "C" {
#endif

#	include <RetroEngine/RetroDefine.h>
#	include <RetroEngine/List.h>

#	include "Retro2DApi.h"
	
	/**
	 * @defgroup RetroSystem RetroSystem
	 *
	 * @ingroup UpperLevelGroup
	 *
	 * @brief The RetroSystem add many things for gestioning sprite.
	 *
	 * @{
	 */
	
	/**
	 * @defgroup RetroSystemType Type
	 *
	 * @ingroup RetroSystem
	 *
	 * @brief The RetroSystem add many things for gestioning sprite.
	 *
	 * @{
	 */

	/**
	 * @brief Contain important info.
	 *
	 * An object passed to all funcion for all sort of thing that didn't do rendering.
	 * You can look at it, but don't directly use it.
	 */
	typedef struct	RetroSystem
	{
		/**
		 * @brief This is what will contain all your sprite and other stuff.
		 */
		Retro2DApi    *api2D;
		
		/**
		 * @brief This will contain some info spec.
		 */
		Info		info;
		
		/**
		 * @brief This will contain in clear the maximum fram per second.
		 */
		RetroInt maxFps;
		
		/**
		 * @brief This represent the time neded in each fram.
		 */
		RetroFloat timePerFram;
		
		/**
		 * @brief This represent if the system is shader compatible
		 */
		RetroBool ShaderCompatible;

		/**
		 * @brief This is the shader created and used by the system function
		 * @see
		 */
		RetroUInt shader;

		/**
		 * @brief This is the shader program created and used by the system function
		 * @see
		 */
		RetroUInt program;
		
		/**
		 * @brief If found, the aplication Path or "./" or ".\\" (os dependent)
		 */
		const char* aplicationPath;
		
		/**
		 * @brief If set, the user specific path or aplicationPath
		 */
		const char* userPath;
		
		/**
		 * @brief All the loaded texture Id, kept for cleanup purpose.
		 */
		intList textureList;
		
		
	}				RetroSystem;

	/** @} */

	/**
	 * @defgroup RetroSystemFunc Function
	 *
	 * @ingroup RetroSystem
	 *
	 * @brief The RetroSystem add many things for gestioning sprite.
	 *
	 * @{
	 */
	
	/**
	 * @brief Function witch create a new system and prepare it.
	 *
	 * @retval A ready to use System.
	 */
	RetroSystem*   newRetroSystem();

	/**
	 * @brief Get the 2D Api associated to a specific system.
	 *
	 * @param[in] system Your system.
	 * @retval The asociated 2D Api.
	 */
	Retro2DApi*		get2DApiFromSystem(RetroSystem* system);
	
	/* init.c */

	/**
	 * @brief Init the RetroEngine part of the system.
	 *
	 * @param[in] argc The argc of your main.
	 * @param[in] argv The argv of your main.
	 * @param[in] x The width of the window.
	 * @param[in] y The height of the window.
	 * @param[in] path A specific path for your log file.
	 * @param[in, out] system Your system.
	 */
	void	RetroEngineInit(int argc, char** argv, const RetroUInt x, const RetroUInt y, const char* path, RetroSystem* system);

	/**
	 * @brief Init the OpenGL extension part of the system.
	 *
	 * @param[in, out] system Your system.
	 * @retval If you can use shader or not.
	 */
	RetroBool RetroInitGLExt(RetroSystem* system);

	/**
	 * @brief Change the screen resolution.
	 *
	 * @param[in] x The new width resolution in the window.
	 * @param[in] y The new height resolution in the window.
	 * @param[in] scaleMode If it scale to fit in th window or not.
	 * @param[in, out] system Your system.
	 * @see RETRO_FIT_WINDOW_KEPT_RATIO RETRO_FIT_WINDOW RETRO_DONT_FIT_WINDOW RETRO_DONT_FIT_WINDOW_CENTER
	 */
    void		RetroChangeResolution(const RetroUInt x, const RetroUInt y, const int scaleMode, RetroSystem* system);
    
	/**
	 * @brief properly stop the RetroEngine.
	 *
	 * @param[in, out] system Your system.
	 */
	void RetroEngineStop(RETRO_TYPE_REF(RetroSystem) system);
	
	/* init2.c */
	
	/**
	 * @brief select if you want to store your data in
	 * list or in vector
	 *
	 * @param[in] mode true for List, False for Vector
	 * @see RETRO_USE_VECTOR RETRO_USE_LIST
	 */
	void	selectStorageMode(const RetroBool mode);
	
    /* loader.c */
	
	/**
	 * @brief Charge an BMP image format.
	 *
	 * @param[in] name The path to the image.
	 * @param[in] reverse Attempt to correct color in the image.
	 * @param[in] sys Your system.
	 * @retval An identifier to the texture.
	 */
	int			RetroLoadBmpTexture(const char *name, const RetroBool reverse, RETRO_TYPE_REF(RetroSystem) sys);
	
	/**
	 * @brief Unload a previously charged texture.
	 *
	 * @param[in] tex A texture identifier.
	 * @param[in, out] sys The system.
	 */
	void	RetroUnloadTexture(RetroUInt tex, RETRO_TYPE_REF(RetroSystem) sys);
	
	/**
	 * @brief charge an BMP image in RGB5_A1 format.
	 *
	 * @param[in] name The path to the image.
	 * @param[in] width The width of the image.
	 * @param[in] height The width of the image.
	 * @param[in] error attempt to correct color in the image.
	 * @retval an identifier to the texture.
	 */
    MARK_AS_DEPRECATED(int chargeBmpTextureRGB5_A1(const char *name, const RetroUInt width, const RetroUInt height, const RetroBool error),
					   "Use int	RetroChargeBmpTexture(const char *name, const RetroBool reverse) insted")
	/**
	 * @brief charge an BMP image in RGBA4 format.
	 *
	 * @param[in] name The path to the image.
	 * @param[in] width The width of the image.
	 * @param[in] height The width of the image.
	 * @param[in] error attempt to correct color in the image.
	 * @retval an identifier to the texture.
	 */
	MARK_AS_DEPRECATED(int chargeBmpTextureRGBA4(const char *name, const RetroUInt width, const RetroUInt height, const RetroBool error),
					   "Use int	RetroChargeBmpTexture(const char *name, const RetroBool reverse) insted")
	
	/**
	 * @brief charge an BMP image in RGB8 format.
	 *
	 * @param[in] name The path to the image.
	 * @param[in] width The width of the image.
	 * @param[in] height The width of the image.
	 * @param[in] error attempt to correct color in the image.
	 * @retval an identifier to the texture.
	 */
    MARK_AS_DEPRECATED(int chargeBmpTextureRGB8(const char *name, const RetroUInt width, const RetroUInt height, const RetroBool error),
					   "Use int	RetroChargeBmpTexture(const char *name, const RetroBool reverse) insted")
	
	/**
	 * @brief charge an BMP image in RGBA8 format.
	 *
	 * @param[in] name The path to the image.
	 * @param[in] width The width of the image.
	 * @param[in] height The width of the image.
	 * @param[in] error attempt to correct color in the image.
	 * @retval an identifier to the texture.
	 */
    MARK_AS_DEPRECATED(int chargeBmpTextureRGBA8(const char *name, const RetroUInt width, const RetroUInt height, const RetroBool error),
					   "Use int	RetroChargeBmpTexture(const char *name, const RetroBool reverse) insted")
	
	/**
	 * @brief load an BMP image and return it as a single array.
	 *
	 * @param[in] name The path to the BMP image.
	 * @retval A single array witch contain all the image
	 */
    RetroUInt16	*chargeBmpMap(const char *name);
	
	/**
	 * @brief load an BMP image and return it as a double array.
	 *
	 * @param[in] name The path to the BMP image.
	 * @param[in] sizeX The width of the image.
	 * @param[in] sizeY The height of the image.
	 * @retval A single array witch contain all the image
	  * @see deleteCollMap.
	 */
    RetroUInt16	**useCollMap(const char* name, const int sizeX, int sizeY);
	
	/**
	 * @brief unload the double array previously load with useCollMap.
	 *
	 * @param[in] collmap The double array to unload.
	 * @retval On success, return 0.
	 * @see useCollMap.
	 */
    int			deleteCollMap(RetroUInt16 **collmap);
    
    /* util.c */
	
	/**
	 * @brief Show the number of frame per seconde on the standar output.
	 *
	 * @brief message to display.
	 * @retval the number of frame per seconde.
	 */
    int			RetroGetFPSMsg(const char* msg);
	
	/** 
	 * @brief Get the number of frame per seconde.
	 *
	 * @retval the number of frame per seconde.
	 */
    int			RetroGetFPS();
	
	/**
	 * @brief limit the number of frame per seconde in your aplication.
	 *
	 * @param[in] system the system associated.
	 */
    void		RetroLimitFPS(RETRO_TYPE_REF_CONST(RetroSystem) system);
	
	/**
	 * @brief set the maximum frame per seconde, must be call before limitFPS
	 *
	 * @param[in] maxFps The new number of frame per seconde, a negate value for disabling it
	 * @param[in,out] system the system associated.
	 * @see limitFPS
	 */
	void		RetroSetMaxFps(signed int maxFps, RETRO_TYPE_REF(RetroSystem) system);

	/**
	 * @brief output a log message, depend on the debug lvl used.
	 *
	 * @param[in] lvl debug lvl, 0b1 for console, 0b10 for file
	 * @param[in] format Same as printf.
	 */
	void RetroDebugLogFjunc(int lvl, const char *  format, ...);
	
	/**
	 * @brief output a log message, depend on the debug lvl used.
	 *
	 * @param[in] lvl debug lvl, 0b1 for console, 0b10 for file
	 * @param[in] format Same as printf.
	 */
	void RetroDebugLogMessageFunc(int lvl, const char *  format, ...);
	
	/**
	 * @brief output a log message, depend on the debug lvl used.
	 *
	 * @param[in] lvl debug lvl, 0b1 for console, 0b10 for file
	 * @param[in] format Same as printf.
	 */
	void RetroDebugLogWarningFunc(int lvl, const char *  format, ...);
	
	/**
	 * @brief output a log message, depend on the debug lvl used.
	 *
	 * @param[in] lvl debug lvl, 0b1 for console, 0b10 for file
	 * @param[in] format Same as printf.
	 */
	void RetroDebugLogErrorFunc(int lvl, const char *  format, ...);
	
	/**
	 * @brief output a log message, depend on the debug lvl used.
	 *
	 * @param[in] lvl debug lvl, 0b1 for console, 0b10 for file
	 * @param[in] format Same as printf.
	 */
	void RetroDebugLogFailureFunc(int lvl, const char *  format, ...);
	
	/**
	 * @brief may stop the aplication if on debug, or does nothing.
	 *
	 * @param[in] lvl debug lvl, 0b1 for console, 0b10 for file, 0b100 for working assert.
	 * @param[in] expr must be true to pass the test.
	 * @param[in] format Same as printf.
	 */
	void RetroAssertFunc(int lvl, RetroBool expr, const char *  format, ...);
	
	/* EasyShader.h */

	/**
	 * @brief create a ready to use shader
	 *
	 * @param[in] nbCode number of code in "code" variable.
	 * @param[in] code your GLSL code, must be terminated by the char '\0'.
	 * @param[in] shaderType the type of shader you will create.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroCreateShader(int nbCode, const char** code, RetroUInt shaderType, RetroSystem* system);

	/**
	 * @brief easy way to create a ready to use fragment shader
	 *
	 * @param[in] code your GLSL code, must be terminated by the char '\0'.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroEasyCreateFragmentShader(const char* code, RetroSystem* system);

	/**
	 * @brief easy way to create a ready to use vertex shader
	 *
	 * @param[in] code your GLSL code, must be terminated by the char '\0'.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroEasyCreateVertexShader(const char* code, RetroSystem* system);

	/**
	 * @brief allow you to start and stop the shader.
	 *
	 * @param[in] start if you want to start using this shader.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroStartStopShader(RetroBool start, RetroSystem* system);

	/**
	 * @brief Delete the shader.
	 *
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroDeleteShader(RetroSystem* system);

	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] val Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable1f(const char* name, float val, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] size The size of the vector.
	 * @param[in] val Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable1fv(const char* name, int size, float* val, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] val Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable1i(const char* name, int val, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] size The size of the vector.
	 * @param[in] val Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable1iv(const char* name, int size, int* val, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] val1 Value of your variable.
	 * @param[in] val2 Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable2f(const char* name, float val1, float val2, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] size The size of the vector.
	 * @param[in] val Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable2fv(const char* name, int size, float* val, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] val1 Value of your variable.
	 * @param[in] val2 Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable2i(const char* name, int val1, int val2, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] size The size of the vector.
	 * @param[in] val Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable2iv(const char* name, int size, int* val, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] val1 Value of your variable.
	 * @param[in] val2 Value of your variable.
	 * @param[in] val3 Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable3f(const char* name, float val1, float val2, float val3, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] size The size of the vector.
	 * @param[in] val Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable3fv(const char* name, int size, float* val, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] val1 Value of your variable.
	 * @param[in] val2 Value of your variable.
	 * @param[in] val3 Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable3i(const char* name, int val1, int val2, int val3, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] size The size of the vector.
	 * @param[in] val Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable3iv(const char* name, int size, int* val, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] val1 Value of your variable.
	 * @param[in] val2 Value of your variable.
	 * @param[in] val3 Value of your variable.
	 * @param[in] val4 Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable4f(const char* name, float val1, float val2, float val3, float val4, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] size The size of the vector.
	 * @param[in] val Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable4fv(const char* name, int size, float* val, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] val1 Value of your variable.
	 * @param[in] val2 Value of your variable.
	 * @param[in] val3 Value of your variable.
	 * @param[in] val4 Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable4i(const char* name, int val1, int val2, int val3, int val4, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] size The size of the vector.
	 * @param[in] val Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariable4iv(const char* name, int size, int* val, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] size The size of the vector.
	 * @param[in] transpose Specifies whether to transpose the matrix as the values are loaded into the variable.
	 * @param[in] val Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariableMatrix2fv(const char* name, int size, RetroBool transpose, float* val, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] size The size of the vector.
	 * @param[in] transpose Specifies whether to transpose the matrix as the values are loaded into the variable.
	 * @param[in] val Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariableMatrix3fv(const char* name, int size, RetroBool transpose, float* val, RetroSystem* system);
	
	/**
	 * @brief Set a variable on your shader.
	 *
	 * @param[in] name Name of your variable.
	 * @param[in] size The size of the vector.
	 * @param[in] transpose Specifies whether to transpose the matrix as the values are loaded into the variable.
	 * @param[in] val Value of your variable.
	 * @param[in,out] system the system associated.
	 * @retval On sucess, return 1.
	 */
	int RetroSetShaderVariableMatrix4fv(const char* name, int size, RetroBool transpose, float* val, RetroSystem* system);
	
	/**
	 * @brief Initialise post processing render.
	 *
	 * @param[in,out] api the api associated.
	 */
	int	RetroInitPostProcessing(RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 * @brief Stop post processing render.
	 *
	 * @param[in,out] api the api associated.
	 */
	int	RetroStopPostProcessing(RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 *
	 */
	Shader* newShader();
	
	/**
	 *
	 */
	int addShaderTexture(RETRO_TYPE_REF(Shader) shader, int texture, const char* const name);
	
	/**
	 *
	 */
	void addShaderVariable(RETRO_TYPE_REF(Shader) shader, const char* const name, void* val, ShaderParamType type);
	
	/**
	 *
	 */
	void retroAttachShader(int id, RETRO_TYPE_REF(Shader) shader, const enumList lDrawable2D, RETRO_TYPE_REF(Retro2DApi) api);
	
	/**
	 *
	 */
	void deleteShader(RETRO_TYPE_REF(Shader) shader);
	
	
	/* police.c */
	
	/**
	 * @brief create or change a font.
	 *
	 * @param[in] id Id of the font.
	 * @param[in] descriptor A desciptor of what the font look like.
	 * @param[in] fontFile Path to the fontFile.
	 * @param[in,out] sys the system associated.
	 */
	int RetroAddFont(RetroUInt id, const char* descriptor, const char* fontFile, RETRO_TYPE_REF(RetroSystem) sys);
	
	/**
	 * @brief delete an old font.
	 *
	 * @param[in] id Id of the font.
	 * @param[in,out] sys the system associated.
	 */

	int RetroDeleteFont(RetroUInt id, RETRO_TYPE_REF(RetroSystem) sys);
	
#	define RetroUsePostProcessing(func, system, api)\
	{\
		RetroGlBindFramebuffer(GL_FRAMEBUFFER, api->fbo);\
		func(api);\
		RetroGlBindFramebuffer(GL_FRAMEBUFFER, 0);\
		\
		glClearColor(0.0, 0.0, 0.0, 1.0);\
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);\
		\
		glBindTexture(GL_TEXTURE_2D, api->fbo_texture);\
		\
		RetroStartStopShader(RetroTrue, system);\
		glBegin(GL_QUADS);\
			GLCOLOR(255, 255, 255);\
			glTexCoord2f(0, 1);\
			glVertex3f(0, 0, -1);\
			glTexCoord2f(0, 0);\
			glVertex3f(0, api->info->origScreenY, -1);\
			glTexCoord2f(1, 0);\
			glVertex3f(api->info->origScreenX, api->info->origScreenY, -1);\
			glTexCoord2f(1, 1);\
			glVertex3f(api->info->origScreenX, 0,  -1);\
		glEnd();\
		RetroStartStopShader(RetroFalse, system);\
	}
	
	/** @} */
	
	/** @} */
#ifdef		__cplusplus
}
#endif

#endif



