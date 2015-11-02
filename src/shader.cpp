/*
** shader.cpp
**
** Made by lucas stefas
** Started on 03/07/14 22:47
*/

#include <RetroEngine/RetroSystem.h>
//#include <RetroEngine/RetroGLExt.h>
#include <SDL/SDL.h>
#include "Input.h"

#define ONE_COLOR_FILTER "\
	uniform sampler2D tex;\n\
	uniform vec4 onlyCol;\n\
	void main(void)\n\
	{\n\
		vec4 baseCol = texture2D(tex,gl_TexCoord[0].st);\n\
		if (baseCol == onlyCol)\n\
			gl_FragColor = onlyCol;\n\
		else\n\
		{\n\
			float gray = (baseCol.r + baseCol.g + baseCol.b) / 3.0;\n\
			gl_FragColor = vec4(gray, gray, gray, baseCol.a);\n\
		}\n\
	}\n\
"

static int texture;

int initShader(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Object2D	obj;
	
	RetroChangeResolution(256, 192, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	
	/*
	 * loading our texture
	 */
	texture = RetroLoadBmpTexture("Other/megaman.bmp", RetroTrue, *system);
	
	/*
	 * creating 1 sprite
	 */
	obj.posX = 64; // where it start to draw on X axy's
	obj.posY = 32; // where it start to draw on Y axy's
	obj.sizeX = 128; // where it end to draw on X axy's
	obj.sizeY = 128; // where it end to draw on Y axy's
	RetroCreateDrawable2D(0, &obj, SPRITE, api); //sending the sprite to your engine
	RetroAddDrawable2DTex(0, 3, 4, texture, SPRITE, api);
	RetroChangeRowDrawable2D(0, 3, SPRITE, api);
	RetroStartAnimDrawable2D(0, 1, 4, RetroTrue, 7, SPRITE, api);

	/*
	 * and now, the shader.
	 * You can only have one shader using this but the true open GL fonction exist so... have fun
	 */
	
	RetroEasyCreateFragmentShader(ONE_COLOR_FILTER, *system); // a "basic" shader who swap every color to black and white exept to the one set on onlyCol.
	
	RetroStartStopShader(RetroTrue, *system); // starting the shader, need to do that before seting the variable onlyCol
	RetroSetShaderVariable4f("onlyCol", 0.0f/255.0f, 234.0f/255.0f, 216.0f/255.0f, 1.0f, *system); // seting the variable onlyCol
	
	RetroInitPostProcessing(api);
	
	return (0);
}

int	ShaderIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	(void) api;
	
	return (0);
}

int stopShader(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	RetroDelDrawable2D(0, SPRITE, api);
	RetroStartStopShader(RetroFalse, *system);
	RetroDeleteShader(*system);
	RetroUnloadTexture(texture, *system);
	RetroStopPostProcessing(api);
	return (0);
}