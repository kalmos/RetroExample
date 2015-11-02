/*
** RetroGLExt.h for SL
**
** Made by lucas stefas
** Login   stefas_l
**
** Started on 24/06/14 12:25 2014 by lucas stefas
*/

#ifndef	__RetroGLExt_H__
#define		__RetroGLExt_H__

#ifdef		__cplusplus
extern "C" {
#endif

#ifdef Windows
#	include <gl/GL.h>
#	define RetroGlGetProcAddress wglGetProcAddress
#	define GLAPIENTRY __stdcall
#	define CASTBWLEW const char*
#elif defined(Mac)
#	include <OpenGL/gl.h>
#	define RetroGlGetProcAddress aglGetProcAddress
#	define CASTBWLEW const unsigned char*
#	define GLAPIENTRY
#elif defined(Linux)
#	include <GL/gl.h>
#	define RetroGlGetProcAddress glXGetProcAddress
#	define GLAPIENTRY
#	define CASTBWLEW const unsigned char*
#endif

#define RETRO_BLACK_AND_WHITE_FRAGMENT_SHADER	"uniform sampler2D tex;\n\
												void main(void)\n\
												{\n\
													vec4 baseCol = texture2D(tex,gl_TexCoord[0].st);\n\
													float grayCol = float((baseCol.r + baseCol.g + baseCol.b) / 3.0);\n\
													gl_FragColor = vec4(grayCol, grayCol, grayCol, baseCol.a);\n\
												}"
#define	RETRO_SEPIA_FRAGMENT_SHADER	"uniform sampler2D tex;\n\
									void main(void)\n\
									 {\n\
										 vec4 baseCol = texture2D(tex,gl_TexCoord[0].st);\n\
										 gl_FragColor = vec4((baseCol.r * 0.393) + (baseCol.g * 0.769) + (baseCol.b * 0.189),\n\
										 (baseCol.r * 0.349) + (baseCol.g * 0.686) + (baseCol.b * 0.168),\n\
										 (baseCol.r * 0.272) + (baseCol.g * 0.534) + (baseCol.b * 0.131),\n\
										 baseCol.a);\n\
									 }"
#define RETRO_INVERT_COLOR_FRAGMENT_SHADER	"uniform sampler2D tex;\n\
											void main(void)\n\
											{\n\
											vec4 baseCol = texture2D(tex,gl_TexCoord[0].st);\n\
											gl_FragColor = vec4(1.0 - baseCol.r, 1.0 - baseCol.g, 1.0 - baseCol.b, baseCol.a);\n\
											}"

#ifndef		GL_FRAGMENT_SHADER
#	define	GL_FRAGMENT_SHADER		0x8B30
#endif
#ifndef		GL_VERTEX_SHADER
#	define	GL_VERTEX_SHADER		0x8B31
#endif
#ifndef		GL_COMPILE_STATUS
#	define	GL_COMPILE_STATUS		0x8B81
#endif
#ifndef		GL_LINK_STATUS
#	define	GL_LINK_STATUS			0x8B82
#endif
#ifndef		GL_INFO_LOG_LENGTH
#	define	GL_INFO_LOG_LENGTH		0x8B84
#endif
#ifndef		GL_FUNC_ADD
#	define	GL_FUNC_ADD				0x8006
#endif
#ifndef		GL_FUNC_SUBTRACT
#	define	GL_FUNC_SUBTRACT		0x800A
#endif
#ifndef		GL_TEXTURE0
#	define	GL_TEXTURE0				0x84C0
#endif
#ifndef		GL_CLAMP_TO_EDGE
#	define	GL_CLAMP_TO_EDGE		0x812F
#endif
#ifndef		GL_RENDERBUFFER
#	define	GL_RENDERBUFFER			0x8D41
#endif
#ifndef		GL_DEPTH_COMPONENT16
#	define	GL_DEPTH_COMPONENT16	0x81A5
#endif
#ifndef		GL_FRAMEBUFFER
#	define	GL_FRAMEBUFFER			0x8D40
#endif
#ifndef		GL_COLOR_ATTACHMENT0
#	define	GL_COLOR_ATTACHMENT0	0x8CE0
#endif
#ifndef		GL_DEPTH_ATTACHMENT
#	define	GL_DEPTH_ATTACHMENT		0x8D00
#endif
#ifndef		GL_FRAMEBUFFER_COMPLETE
#	define	GL_FRAMEBUFFER_COMPLETE	0x8CD5
#endif
	
	
#if !defined(GL_VERSION_1_2) || !defined(Linux)
	typedef	void	(GLAPIENTRY * PFNGLBLENDEQUATIONPROC)		(GLenum mode);
#endif
	
#if !defined(GL_VERSION_1_3) || !defined(Linux)
	typedef void	(GLAPIENTRY * PFNGLACTIVETEXTUREPROC)		(GLenum texture);
#endif
	
#if !defined(GL_VERSION_2_0) || !defined(linux)
	typedef	GLuint	(GLAPIENTRY * PFNGLCREATESHADERPROC)			(GLenum type);
	typedef	void	(GLAPIENTRY * PFNGLSHADERSOURCEPROC)			(GLuint shader,
																	 GLsizei count, const char* const *strings, const GLint* lengths);
	typedef	void	(GLAPIENTRY * PFNGLCOMPILESHADERPROC)			(GLuint shader);
	typedef	void	(GLAPIENTRY * PFNGLGETSHADERIVPROC)				(GLuint shader, GLenum pname, GLint* param);
	typedef	void	(GLAPIENTRY * PFNGLGETSHADERINFOLOGPROC)		(GLuint shader, GLsizei bufSize, GLsizei* length, char* infoLog);
	typedef	GLuint	(GLAPIENTRY * PFNGLCREATEPROGRAMPROC)			(void);
	typedef	void	(GLAPIENTRY * PFNGLATTACHSHADERPROC)			(GLuint program, GLuint shader);
	typedef	void	(GLAPIENTRY * PFNGLLINKPROGRAMPROC)				(GLuint program);
	typedef	void	(GLAPIENTRY * PFNGLGETPROGRAMIVPROC)			(GLuint program, GLenum pname, GLint* param);
	typedef	void	(GLAPIENTRY * PFNGLGETPROGRAMINFOLOGPROC)		(GLuint shader, GLsizei bufSize, GLsizei* length, char* infoLog);
	typedef	void	(GLAPIENTRY * PFNGLUSEPROGRAMPROC)				(GLuint program);
	typedef	void	(GLAPIENTRY * PFNGLDELETEPROGRAMPROC)			(GLuint program);
	typedef	void	(GLAPIENTRY * PFNGLDELETESHADERPROC)			(GLuint shader);
	typedef	void	(GLAPIENTRY * PFNGLDETACHSHADERPROC)			(GLuint program, GLuint shader);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM1FPROC)				(GLint location, GLfloat v0);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM1FVPROC)				(GLint location, GLsizei count, const GLfloat* value);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM1IPROC)				(GLint location, GLint v0);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM1IVPROC)				(GLint location, GLsizei count, const GLint* value);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM2FPROC)				(GLint location, GLfloat v0, GLfloat v1);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM2FVPROC)				(GLint location, GLsizei count, const GLfloat* value);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM2IPROC)				(GLint location, GLint v0, GLint v1);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM2IVPROC)				(GLint location, GLsizei count, const GLint* value);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM3FPROC)				(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM3FVPROC)				(GLint location, GLsizei count, const GLfloat* value);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM3IPROC)				(GLint location, GLint v0, GLint v1, GLint v2);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM3IVPROC)				(GLint location, GLsizei count, const GLint* value);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM4FPROC)				(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM4FVPROC)				(GLint location, GLsizei count, const GLfloat* value);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM4IPROC)				(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	typedef void	(GLAPIENTRY * PFNGLUNIFORM4IVPROC)				(GLint location, GLsizei count, const GLint* value);
	typedef void	(GLAPIENTRY * PFNGLUNIFORMMATRIX2FVPROC)		(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	typedef void	(GLAPIENTRY * PFNGLUNIFORMMATRIX3FVPROC)		(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	typedef void	(GLAPIENTRY * PFNGLUNIFORMMATRIX4FVPROC)		(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
	typedef void	(GLAPIENTRY * PFNGLGENRENDERBUFFERSPROC)		(GLsizei n, GLuint *renderbuffers);
	typedef void	(GLAPIENTRY * PFNGLBINDRENDERBUFFERPROC)		(GLenum target, GLuint renderbuffer);
	typedef void	(GLAPIENTRY * PFNGLRENDERBUFFERSTORAGEPROC)		(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	typedef void	(GLAPIENTRY * PFNGLGENFRAMEBUFFERSPROC)			(GLsizei n, GLuint *framebuffers);
	typedef void	(GLAPIENTRY * PFNGLBINDFRAMEBUFFERPROC)			(GLenum target, GLuint framebuffer);
	typedef void	(GLAPIENTRY * PFNGLFRAMEBUFFERTEXTURE2DPROC)	(GLenum target,
																	 GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	typedef void	(GLAPIENTRY * PFNGLFRAMEBUFFERRENDERBUFFERPROC)	(GLenum target,
																	 GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	typedef GLenum	(GLAPIENTRY * PFNGLCHECKFRAMEBUFFERSTATUSPROC)	(GLenum target);
	typedef void	(GLAPIENTRY * PFNGLDELETERENDERBUFFERSPROC)		(GLsizei n, const GLuint *renderbuffers);
	typedef void	(GLAPIENTRY * PFNGLDELETEFRAMEBUFFERSPROC)		(GLsizei n, const GLuint *framebuffers);
	
#endif
	
typedef int		(GLAPIENTRY * PFNGLFETUNIFORMLOCATIONPROC)	(GLuint program, const char* name);

	
PFNGLBLENDEQUATIONPROC				RetroGlBlendEquation;
PFNGLACTIVETEXTUREPROC				RetroGlActiveTexture;
PFNGLCREATESHADERPROC				RetroGlCreateShader;
PFNGLSHADERSOURCEPROC				RetroGlShaderSource;
PFNGLCOMPILESHADERPROC				RetroGlCompileShader;
PFNGLGETSHADERIVPROC				RetroGlGetShaderiv;
PFNGLGETSHADERINFOLOGPROC			RetroGlGetShaderInfoLog;
PFNGLCREATEPROGRAMPROC				RetroGlCreateProgram;
PFNGLATTACHSHADERPROC				RetroGlAttachShader;
PFNGLLINKPROGRAMPROC				RetroGlLinkProgram;
PFNGLGETPROGRAMIVPROC				RetroGlGetProgramiv;
PFNGLGETPROGRAMINFOLOGPROC			RetroGlGetProgramInfoLog;
PFNGLUSEPROGRAMPROC					RetroGlUseProgram;
PFNGLDELETEPROGRAMPROC				RetroGlDeleteProgram;
PFNGLDELETESHADERPROC				RetroGlDeleteShader;
PFNGLDETACHSHADERPROC				RetroGlDetachShader;
PFNGLFETUNIFORMLOCATIONPROC			RetroGlGetUniformLocation;
PFNGLUNIFORM1FPROC					RetroGlUniform1f;
PFNGLUNIFORM1FVPROC					RetroGlUniform1fv;
PFNGLUNIFORM1IPROC					RetroGlUniform1i;
PFNGLUNIFORM1IVPROC					RetroGlUniform1iv;
PFNGLUNIFORM2FPROC					RetroGlUniform2f;
PFNGLUNIFORM2FVPROC					RetroGlUniform2fv;
PFNGLUNIFORM2IPROC					RetroGlUniform2i;
PFNGLUNIFORM2IVPROC					RetroGlUniform2iv;
PFNGLUNIFORM3FPROC					RetroGlUniform3f;
PFNGLUNIFORM3FVPROC					RetroGlUniform3fv;
PFNGLUNIFORM3IPROC					RetroGlUniform3i;
PFNGLUNIFORM3IVPROC					RetroGlUniform3iv;
PFNGLUNIFORM4FPROC					RetroGlUniform4f;
PFNGLUNIFORM4FVPROC					RetroGlUniform4fv;
PFNGLUNIFORM4IPROC					RetroGlUniform4i;
PFNGLUNIFORM4IVPROC					RetroGlUniform4iv;
PFNGLUNIFORMMATRIX2FVPROC			RetroGlUniformMatrix2fv;
PFNGLUNIFORMMATRIX3FVPROC			RetroGlUniformMatrix3fv;
PFNGLUNIFORMMATRIX4FVPROC			RetroGlUniformMatrix4fv;
PFNGLGENRENDERBUFFERSPROC			RetroGlGenRenderbuffers;
PFNGLBINDRENDERBUFFERPROC			RetroGlBindRenderbuffer;
PFNGLRENDERBUFFERSTORAGEPROC		RetroGlRenderbufferStorage;
PFNGLGENFRAMEBUFFERSPROC			RetroGlGenFramebuffers;
PFNGLBINDFRAMEBUFFERPROC			RetroGlBindFramebuffer;
PFNGLFRAMEBUFFERTEXTURE2DPROC		RetroGlFramebufferTexture2D;
PFNGLFRAMEBUFFERRENDERBUFFERPROC	RetroGlFramebufferRenderbuffer;
PFNGLCHECKFRAMEBUFFERSTATUSPROC		RetroGlCheckFramebufferStatus;
PFNGLDELETERENDERBUFFERSPROC		RetroGlDeleteRenderbuffers;
PFNGLDELETEFRAMEBUFFERSPROC			RetroGlDeleteFramebuffers;
	
	
	
	
	
	
	
	
	
#define	GETGLBLENDEQUATION(var) var = (PFNGLBLENDEQUATIONPROC)RetroGlGetProcAddress((CASTBWLEW)"glBlendEquation");
#define	GETGLACTIVETEXTURE(var) var = (PFNGLACTIVETEXTUREPROC)RetroGlGetProcAddress((CASTBWLEW)"glActiveTexture");
#define	GETGLCREATESHADER(var) var = (PFNGLCREATESHADERPROC)RetroGlGetProcAddress((CASTBWLEW)"glCreateShader");
#define GETGLSHADERSOURCE(var) var = (PFNGLSHADERSOURCEPROC)RetroGlGetProcAddress((CASTBWLEW)"glShaderSource");
#define GETGLCOMPILESHADER(var) var = (PFNGLCOMPILESHADERPROC)RetroGlGetProcAddress((CASTBWLEW)"glCompileShader");
#define GETGLGETSHADERIV(var) var = (PFNGLGETSHADERIVPROC)RetroGlGetProcAddress((CASTBWLEW)"glGetShaderiv");
#define GETGLGETSHADERINFOLOG(var) var = (PFNGLGETSHADERINFOLOGPROC)RetroGlGetProcAddress((CASTBWLEW)"glGetShaderInfoLog");
#define GETGLCREATEPROGRAM(var) var = (PFNGLCREATEPROGRAMPROC)RetroGlGetProcAddress((CASTBWLEW)"glCreateProgram");
#define GETGLATTACHSHADER(var) var = (PFNGLATTACHSHADERPROC)RetroGlGetProcAddress((CASTBWLEW)"glAttachShader");
#define GETGLLINKPROGRAM(var) var = (PFNGLLINKPROGRAMPROC)RetroGlGetProcAddress((CASTBWLEW)"glLinkProgram");
#define GETGLGETPROGRAMIV(var) var = (PFNGLGETPROGRAMIVPROC)RetroGlGetProcAddress((CASTBWLEW)"glGetProgramiv");
#define GETGLGETPROGRAMINFOLOG(var) var = (PFNGLGETPROGRAMINFOLOGPROC)RetroGlGetProcAddress((CASTBWLEW)"glGetProgramInfoLog");
#define GETGLUSEPROGRAM(var) var = (PFNGLUSEPROGRAMPROC)RetroGlGetProcAddress((CASTBWLEW)"glUseProgram");
#define GETGLDELETEPROGRAM(var) var = (PFNGLDELETEPROGRAMPROC)RetroGlGetProcAddress((CASTBWLEW)"glDeleteProgram");
#define GETGLDELETESHADER(var) var = (PFNGLDELETESHADERPROC)RetroGlGetProcAddress((CASTBWLEW)"glDeleteShader");
#define GETGLDETACHSHADER(var) var = (PFNGLDETACHSHADERPROC)RetroGlGetProcAddress((CASTBWLEW)"glDetachShader");
#define GETGLFETUNIFORMLOCATION(var) var = (PFNGLFETUNIFORMLOCATIONPROC)RetroGlGetProcAddress((CASTBWLEW)"glGetUniformLocation");
#define GETGLUNIFORM1F(var) var = (PFNGLUNIFORM1FPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform1f");
#define GETGLUNIFORM1FV(var) var = (PFNGLUNIFORM1FVPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform1fv");
#define GETGLUNIFORM1I(var) var = (PFNGLUNIFORM1IPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform1i");
#define GETGLUNIFORM1IV(var) var = (PFNGLUNIFORM1IVPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform1iv");
#define GETGLUNIFORM2F(var) var = (PFNGLUNIFORM2FPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform2f");
#define GETGLUNIFORM2FV(var) var = (PFNGLUNIFORM2FVPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform2fv");
#define GETGLUNIFORM2I(var) var = (PFNGLUNIFORM2IPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform2i");
#define GETGLUNIFORM2IV(var) var = (PFNGLUNIFORM2IVPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform2iv");
#define GETGLUNIFORM3F(var) var = (PFNGLUNIFORM3FPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform3f");
#define GETGLUNIFORM3FV(var) var = (PFNGLUNIFORM3FVPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform3fv");
#define GETGLUNIFORM3I(var) var = (PFNGLUNIFORM3IPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform3i");
#define GETGLUNIFORM3IV(var) var = (PFNGLUNIFORM3IVPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform3iv");
#define GETGLUNIFORM4F(var) var = (PFNGLUNIFORM4FPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform4f");
#define GETGLUNIFORM4FV(var) var = (PFNGLUNIFORM4FVPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform4fv");
#define GETGLUNIFORM4I(var) var = (PFNGLUNIFORM4IPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform4i");
#define GETGLUNIFORM4IV(var) var = (PFNGLUNIFORM4IVPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniform4iv");
#define GETGLUNIFORMMATRIX2FV(var) var = (PFNGLUNIFORMMATRIX2FVPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniformMatrix2fv");
#define GETGLUNIFORMMATRIX3FV(var) var = (PFNGLUNIFORMMATRIX3FVPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniformMatrix3fv");
#define GETGLUNIFORMMATRIX4FV(var) var = (PFNGLUNIFORMMATRIX4FVPROC)RetroGlGetProcAddress((CASTBWLEW)"glUniformMatrix4fv");
#define GETGLGENRENDERBUFFERS(var) var = (PFNGLGENRENDERBUFFERSPROC)RetroGlGetProcAddress((CASTBWLEW)"glGenRenderbuffers");
#define GETGLBINDRENDERBUFFER(var) var = (PFNGLBINDRENDERBUFFERPROC)RetroGlGetProcAddress((CASTBWLEW)"glBindRenderbuffer");
#define GETGLRENDERBUFFERSTORAGE(var) var = (PFNGLRENDERBUFFERSTORAGEPROC)RetroGlGetProcAddress((CASTBWLEW)"glRenderbufferStorage");
#define GETGLGENFRAMEBUFFERS(var) var = (PFNGLGENFRAMEBUFFERSPROC)RetroGlGetProcAddress((CASTBWLEW)"glGenFramebuffers");
#define GETGLBINDFRAMEBUFFER(var) var = (PFNGLBINDFRAMEBUFFERPROC)RetroGlGetProcAddress((CASTBWLEW)"glBindFramebuffer");
#define GETGLFRAMEBUFFERTEXTURE2D(var) var = (PFNGLFRAMEBUFFERTEXTURE2DPROC)RetroGlGetProcAddress((CASTBWLEW)"glFramebufferTexture2D");
#define GETGLFRAMEBUFFERRENDERBUFFER(var) var = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)RetroGlGetProcAddress((CASTBWLEW)"glFramebufferRenderbuffer");
#define GETGLCHECKFRAMEBUFFERSTATUS(var) var = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)RetroGlGetProcAddress((CASTBWLEW)"glCheckFramebufferStatus");
#define GETGLDELETERENDERBUFFERS(var) var = (PFNGLDELETERENDERBUFFERSPROC)RetroGlGetProcAddress((CASTBWLEW)"glDeleteRenderbuffers");
#define GETGLDELETEFRAMEBUFFERS(var) var = (PFNGLDELETEFRAMEBUFFERSPROC)RetroGlGetProcAddress((CASTBWLEW)"glDeleteFramebuffers");
	
#ifdef		__cplusplus
	}
#endif
	
#endif //__RetroGLExt_H__