/*
** ColorSwaping.c for Example
** 
** Made by lucas stefas
** Login   stefas_l
** 
** Started on 08/09/2015 20:14
*/

#include <RetroEngine/RetroSystem.h>
#include <SDL/SDL.h>
#include "Input.h"
	
static int sm;
static int smp;
static Shader* shad = NULL;
static Drawable2D* d2d;
static int t = 0;
static int tt = 0;
static int ttt = 0;
static int tttt = 0;
static int p1 = 12;
static int p2 = 1;
static int p3 = 1;


#define TESTSHADER \
"uniform sampler2D	tex;\n\
uniform sampler2D	pal;\n\
uniform int			palSize;\n\
uniform int			palOfset;\n\
uniform int			decal;\n\
\n\
void main(void)\n\
{\n\
	vec4 baseCol = texture2D(tex,gl_TexCoord[0].st);\n\
	vec2 pos = vec2(0, 0);\n\
	int col = int(baseCol.b * 256.0) + int(baseCol.g * 255.0 * 255.0) + int(baseCol.r * 255.0 * 255.0 * 255.0);\n\
	\n\
	if (col < palSize)\n\
	{\n\
		col += decal;\n\
		if (col > palSize);\n\
		col -= palSize;\n\
		pos.s = float(col + 1) / float(palSize + 1);\n\
		pos.t = float(palOfset + 1) / float(palSize + 1);\n\
		gl_FragColor = texture2D(pal, pos);\n\
	}\n\
	else\n\
		gl_FragColor = baseCol;\n\
		}"

int initColorSwaping(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	Object2D		obj;
	obj.posX = 104;
	obj.posY = 46;
	obj.sizeX = 48;
	obj.sizeY = 99;

		
	RetroChangeResolution(256, 192, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	
	sm = RetroLoadBmpTexture("SecretOfMana/perso1.bmp", RetroTrue, *system);
	smp = RetroLoadBmpTexture("SecretOfMana/pal.bmp", RetroTrue, *system);
	
	d2d = RetroCreateDrawable2D(0, &obj, TILEMAP, api);
	RetroAddDrawable2DTex(0, 1, 1, sm, TILEMAP, api);
	
	shad = newShader();
	shad->program = RetroEasyCreateFragmentShader(TESTSHADER, *system);
	addShaderTexture(shad, sm, "tex");
	addShaderTexture(shad, smp, "pal");
	addShaderVariable(shad, "palSize", (void*)&(p1), UNIFORM_1I);
	addShaderVariable(shad, "palOfset", (void*)&(p2), UNIFORM_1I);
	addShaderVariable(shad, "decal", (void*)&(p3), UNIFORM_1I);
	
	retroAttachShader(0, shad, TILEMAP, api);
	
	d2d->shader->variable[4].varVal = (void*)&(tt);
	d2d->shader->variable[3].varVal = (void*)&(tttt);

	return (0);
	}
	
	int ColorSwapingIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
	{
		t += 1;
		if (t == 3)
		{
			tt += 1;
			if (tt == 12)
				tt = 0;
			t = 0;
		}
		
		ttt += 1;
		
		if (ttt == 240)
		{
			tttt += 1;
			if (tttt == 9)
				tttt = 0;
			ttt = 0;
		}
		
		
		return (0);
	}
	
	int stopColorSwaping(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
	{
		(void)system;
		RetroUnloadTexture(sm, *system);
		RetroUnloadTexture(smp, *system);
		RetroDelDrawable2D(0, TILEMAP, api);
		deleteShader(shad);
		return (0);
	}