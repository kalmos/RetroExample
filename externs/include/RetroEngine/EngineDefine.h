/*
** EngineDefine.h for SL
**
** Made by lucas stefas
** Login   stefas_l
**
** Started on 21/05/13 12:41 2013 by lucas stefas
*/

#ifndef		__EngineDefine_H__
#define		__EngineDefine_H__

#ifdef		__cplusplus
extern "C" {
#endif

#	if defined(Linux) || defined(Windows) || defined (Mac)

#		if defined(Windows)
#			include    <windows.h>
#			include	<WinDef.h>
#			include	<stdint.h>
#		endif

#		if defined(Linux) || defined(Windows)
#			include	<GL/gl.h>
#		elif defined(Mac)
#			include	<OpenGL/gl.h>
#		endif

#		define     DISPRINT(x, y, z)   printf(x, y);
#		define		GLCOLOR(x, y, z)    glColor3ub(x, y, z);
#		define		GLFIRST             glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
#		define		ONLYDS
#		define		GLFLUSH		        glFlush();
#		define		GLTEXTURES          glGenTextures(1, &texture);

#		if defined(Linux) || defined(Mac)
#			define     GLTEXIMAGERGB5_A1	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB5_A1, width, height, 0,\
                                            GL_BGRA, GL_UNSIGNED_SHORT_1_5_5_5_REV, tex);
#			define     GLTEXIMAGERGBA4		glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA4, width, height, 0, GL_RGBA,\
                                            GL_UNSIGNED_SHORT, tex);
#			define		GLTEXIMAGERGB8		glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex);
#			define		GLTEXIMAGERGBA8		glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA,\
                                            GL_UNSIGNED_INT_8_8_8_8, tex);
#		endif

#		if defined(Windows)
#			define     GLTEXIMAGERGB5_A1	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB5_A1, width, height, 0, GL_RGBA, 0x8366, tex);
#			define		GLTEXIMAGERGBA4		glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA4, width, height, 0, GL_RGBA,\
                                            GL_UNSIGNED_SHORT, tex);
#			define		GLTEXIMAGERGB8		glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex);
#			define		GLTEXIMAGERGBA8		glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, 0x8035, tex);
#		endif

#		define		ONLYPC1             glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);\
                                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
#		define		SHITWITHGLTEXTURE2D	0
#		define     GLFUNC              glEnable(GL_BLEND);\
                                        glEnable(GL_DEPTH_TEST);
#		define     GLCLEAR             glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

#		else

#		include	<PA9.h>
#		include	"KT_lib.h"
#		include	"efs_lib.h"

#		define		DISPRINT(x, y, z)   PA_OutputText(1, 0, z, x, y);
#		define     GLCOLOR(x, y, z)    glColor3b(x, y, z);
#		define		GLFIRST             glInit();
#		define		ONLYDS              glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE );
#		define		GLFLUSH             glFlush(0);
#		define		GLTEXTURES          glGenTextures(GL_TEXTURE_2D, &texture);
#		define		GLTEXIMAGE          glTexImage2D (0, 0, GL_RGBA, convertenum(width), convertenum(height), 0,\
                                        TEXGEN_TEXCOORD, (unsigned char*)tex);
#		define		ONLYPC1
#		define		ONLYPC2
#		define		SHITWITHGLTEXTURE2D	GL_TEXTURE_2D
#		define		GLFUNC

#	endif
	
#	if !defined	M_PI

#		define		M_PI    3.14159265358979323846

#	endif
    
#	if !defined		ERRCODE
	
#		define		ERRCODE		-1337
	
#	endif

#	if !defined		VALIDCODE
	
#		define		VALIDCODE	-1337

#	endif
	
#	ifndef TIME_CONSANT
#		ifdef Windows
#			define TIME_CONSTANT 1000000.0f
#		else
#			define TIME_CONSTANT 1000000.0f
#		endif
#	endif
	
#ifdef		__cplusplus
}
#endif

#endif
