/*
** Retrotype.h for SL
**
** Made by lucas stefas
** Login   stefas_l
**
** Started on 21/05/13 12:34 2013 by lucas stefas
*/

/**
 * @file
 *
 * @ingroup Engine2D
 *
 * @brief Engine2D
 */

#ifndef		__Retrotype_H__
#define		__Retrotype_H__

#ifdef		__cplusplus
extern "C" {
#endif

#	include <RetroEngine/RetroType.h>
	
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
	
	#if defined(Linux) || defined(Windows) || defined (Mac)
	
	/**
	 * @brief Enum for recognizing type of texture.
	 *
	 * this Enum was only here for DS dev and for making
	 * openGL call still work on DS.
	 */
		typedef enum	GL_TEXTURE_SIZE_ENUM
		{
			TEXTURE_SIZE_8,
			TEXTURE_SIZE_16,
			TEXTURE_SIZE_32,
			TEXTURE_SIZE_64,
			TEXTURE_SIZE_128,
			TEXTURE_SIZE_256,
			TEXTURE_SIZE_512,
			TEXTURE_SIZE_1024
		}				GL_TEXTURE_SIZE_ENUM;

	#endif
	
	/**
	 * @brief A color in RGBA stile.
	 *
	 * this permit to easy separate RGBA value writen in int
	 * into diferent char.
	 */
	typedef union	Color
	{
		RetroUInt32			allColor;
		RetroUInt8			RGBA[4];
	}				Color;
	
	/**
	 * @brief for having both ID in one variable.
	 */
#	ifdef X64
	typedef union	RetroId
	{
		RetroUInt64			FullId;
		RetroUInt32			id[2];
	}				RetroId;
	
	typedef RetroUInt64 RetroIntId;
#	else
	typedef union	RetroId
	{
		RetroUInt32			FullId;
		RetroUInt16			id[2];
	}				RetroId;
	
	typedef RetroUInt32 RetroIntId;
#	endif
	
	typedef struct Drawable2D Drawable2D;
	typedef struct Info Info;
	
	/**
	 * @brief Screen information and other things.
	 *
	 * Structure witch retain the different Inforamtion
	 * about rendering, screen, resolution ratio...
	 */
	struct			Info {
		/**
		 * @brief The width of the windows.
		 */
		RetroUInt		screenX;
		
		/**
		 * @brief The height of the windows.
		 */
		RetroUInt		screenY;
		
		/**
		 * @brief The original width of the windows.
		 */
		RetroUInt		origScreenX;
		
		/**
		 * @brief The original height of the windows.
		 */
		RetroUInt		origScreenY;
		
		/**
		 * @brief A function to call every frame.
		 */
		void		(*func)(void);
		
		/**
		 * @brief A function for calculate true cordinate.
		 */
		void		(*coorcalc)(Drawable2D*, Info*);
		
		/**
		 * @brief The screen resolution ratio.
		 */
		RetroFloat		res;
		
		/**
		 * @brief The original screen resolution ratio.
		 */
		RetroFloat		origRes;
		
		
	};

	/**
	 * @brief Enum for recognizing type of drawable.
	 *
	 * This is used for knowing if you want to draw a Background,
	 * a Sprite, a Shadow, A Light.
	 * @todo Implement Text, TextBox and Police system.
	 */
	typedef enum	enumList
	{
		BACKGROUND = 0,
		SPRITE = 1,
		SHADOWMAP = 2,
		LIGHTMAP = 3,
		TEXTBOX = 4,
		TEXT = 5,
		MODE7 = 6,
		TILEMAP = 7,
		TILEMAP7 = 8,
		ALLLIST = 9
	}				enumList;

	

	#if defined(Windows)

		#pragma pack(push)
		#pragma pack(1)
		typedef struct	s_bmp_header
		{
			uint16_t	magic;
			uint32_t	size;
			uint16_t	_app1;
			uint16_t	_app2;
			uint32_t	offset;
		}				t_bmp_header;
		#pragma pack(pop)

		#pragma pack(push)
		#pragma pack(1)
		typedef struct	s_bmp_info_header
		{
			uint32_t	size;
			int32_t		width;
			int32_t		height;
			uint16_t	planes;
			uint16_t	bpp;
			uint32_t	compression;
			uint32_t	raw_data_size;
			int32_t		h_resolution;
			int32_t		v_resolution;
			uint32_t	palette_size;
			uint32_t	important_colors;
		}				t_bmp_info_header;
		#pragma pack(pop)

	#endif
	#if defined(Linux) || defined (Mac)

		/**
		 * @brief The BMP header part 1.
		 * @todo Hide this.
		 */
		typedef struct __attribute__((packed))	s_bmp_header
		{
			uint16_t	magic;
			uint32_t	size;
			uint16_t	_app1;
			uint16_t	_app2;
			uint32_t	offset;
		}				t_bmp_header;

		/**
		* @brief The BMP header part 2.
		* @todo Hide this.
		*/
		typedef struct __attribute__((packed))	s_bmp_info_header
		{
			uint32_t	size;
			int32_t		width;
			int32_t		height;
			uint16_t	planes;
			uint16_t	bpp;
			uint32_t	compression;
			uint32_t	raw_data_size;
			int32_t		h_resolution;
			int32_t		v_resolution;
			uint32_t	palette_size;
			uint32_t	important_colors;
		}				t_bmp_info_header;

	#endif

	/**
	 * @brief enum corresponding to each basic type of shader variable
	 *
	 * this will be used to know how to pass your variable to your
	 * shader.
	 */
	typedef enum	ShaderParamType
	{
		UNIFORM_1F = 0, UNIFORM_1FV = 1, UNIFORM_1I = 2, UNIFORM_1IV = 3,
		UNIFORM_2F = 4, UNIFORM_2FV = 5, UNIFORM_2I = 6, UNIFORM_2IV = 7,
		UNIFORM_3F = 8, UNIFORM_3FV = 9, UNIFORM_3I = 10, UNIFORM_3IV = 11,
		UNIFORM_4F = 12, UNIFORM_4FV = 13, UNIFORM_4I = 14, UNIFORM_4IV = 15,
		UNIFORM_MATRIX2FV = 16, UNIFORM_MATRIX3FV = 17, UNIFORM_MATRIX4FV = 18
	}				ShaderParamType;
	
	/**
	 * @brief structure to old a shader variable
	 *
	 * it will retain all basic information for a shader variable.
	 */
	typedef struct		ShaderParam
	{
		/**
		 * @brief type of shader variable.
		 */
		ShaderParamType SPT;
		
		/**
		 * @brief name of your variable.
		 */
		const char*		varName;
		
		/**
		 * @brief value of your variable.
		 */
		void*			varVal;
	}					ShaderParam;
	
	/**
	 * @brief structure for olding shader info.
	 *
	 * old texture, variable and program for a shader
	 */
	typedef struct	Shader
	{
		/**
		 * @brief vector of texture
		 */
		RetroInt	*texture;
		
		/**
		 * @brief vector of variable
		 */
		ShaderParam	*variable;
		
		/**
		 * @brief précompiled shader program
		 */
		int			program;
		
	}				Shader;
	
	/**
	 * @brief This structure represent an Animation.
	 *
	 * This is all A sprite need to be animated.
	 * You can look at it, but don't directly use it.
	 */
	typedef struct		Animation
	{
		/**
		 * @brief The begin frame of the animation.
		 */
		RetroUChar		start;
		
		/**
		 * @brief The current frame of the animation.
		 */
		RetroUChar		current;
		
		/**
		 * @brief The last frame of the animation.
		 */
		RetroUChar		stop;
		
		/**
		 * @brief The number of frame you will see the same part of the animation.
		 */
		RetroUInt			temps;
		
		/**
		 * @brief The number of frame until the next part of the animation.
		 */
		RetroUInt			rest;
		
		/**
		 * @brief The sens of the animation.
		 */
		RetroBool			sens;
	}					Animation;

	/**
	 * @brief This structure represent a Texture.
	 *
	 * This is all A sprite need to have a Texture.
	 * You can look at it, but don't directly use it.
	 */
	typedef struct		Texture
	{
		/**
		 * @brief The texture id sent by OpenGL
		 */
		RetroUInt			num;
		
		/**
		 * @brief Number of frame in width.
		 */
		RetroUInt		nbX;
		
		/**
		 * @brief Number of frame in height.
		 */
		RetroUInt		nbY;
		
		/**
		 * @brief The begin of the displayed texture in width.
		 */
		RetroFloat		startx;
		
		/**
		 * @brief The end of the displayed texture in width.
		 */
		RetroFloat		endx;
		
		/**
		 * @brief The begin of the displayed texture in height.
		 */
		RetroFloat		starty;
		
		/**
		 * @brief The end of the displayed texture in height.
		 */
		RetroFloat		endy;
		
		
		/**
		 * @brief Only used in with Mode7.
		 */
		RetroFloat		rotx[4];
		
		/**
		 * @brief Only used in with Mode7.
		 */
		RetroFloat		roty[4];
		
		
		/**
		 * @brief To know if the texture was Vfliped or not.
		 */
		RetroBool			Vflip;
		
		/**
		 * @brief To know if the texture was Hfliped or not.
		 */
		RetroBool			Hflip;
		
		/**
		 * @brief An atached Animation.
		 */
		Animation		*anim;
	}					Texture;

	/**
	 * @brief a small coordinate struct (yeah, I'm french and bad at writing).
	 */
	typedef struct		Coordonee
	{
		/**
		 * @brief X position.
		 */
		RetroFloat		x;
		
		/**
		 * @brief Y position.
		 */
		RetroFloat		y;
		
		/**
		 * @brief Z position.
		 */
		RetroFloat		z;
		
		/**
		 * @brief Width.
		 */
		RetroFloat		sizeX;
		
		/**
		 * @brief Height.
		 */
		RetroFloat		sizeY;
	}					Coordonee;

	/**
	 * @brief A structure descrybing a sprite, a background and many other things.
	 * This is what you will use the most during all your work.
	 * 
	 * You can look at it, but don't directly use it.
	 */
	struct				Drawable2D
	{
		/**
		 * @brief The x position in the screen coordinate.
		 */
		RetroFloat		x;
		
		/**
		 * @brief The y position in the screen coordinate.
		 */
		RetroFloat		y;
		
		/**
		 * @brief The z position in the screen coordinate.
		 */
		RetroFloat		z;
		
		/**
		 * @brief The width of this element.
		 */
		RetroUInt			taillex;
		
		/**
		 * @brief The height of this element.
		 */
		RetroUInt			tailley;
		
		/**
		 * @brief used for rotation on z axis. 2 and 3 are used only for mode7
		 */
		RetroFloat		rotx[4];
		
		/**
		 * @brief used for rotation on z axis. 2 and 3 are used only for mode7
		 */
		RetroFloat		roty[4];
		
		/**
		 * @brief Not utilised at the moment.
		 */
		RetroFloat		rotz[2];
		
		/**
		 * @brief An atached texture.
		 */
		Texture			*texture;
		
		/**
		 * @brief Only used for TileMapingRendering.
		 */
		Texture			*secondaryTexture;
		
		/**
		 * @brief for shaderised object
		 */
		Shader			*shader;
		
		/**
		 * @brief The color used for this sprite.
		 */
		Color			RGBA[4];
		
		/**
		 * @brief memory of the user coordonée.
		 */
		Coordonee		coor;
		
		float weight;
		float startSpeedX;
		float startSpeedY;
		float speedX;
		float speedY;
		float maxSpeedX;
		float maxSpeedY;
	};

	/**
	 * @brief A structure representing a Camera.
	 *
	 * This is just a structure representing a OpenGl camera.
	 * His parameter are the same as the one of gluLookAt.
	 * I know, it's deprecated on osX 10.9.
	 */
	typedef struct		Camera
	{
		/**
		 * @brief Position of the eye point in X axis.
		 */
		RetroDouble		eyeX;
		
		/**
		 * @brief Position of the eye point in Y axis.
		 */
		RetroDouble		eyeY;
		
		/**
		 * @brief Position of the eye point in Z axis.
		 */
		RetroDouble		eyeZ;
		
		/**
		 * @brief Position of the reference point in X axis.
		 */
		RetroDouble		centerX;
		
		/**
		 * @brief Position of the reference point in Y axis.
		 */
		RetroDouble		centerY;
		
		/**
		 * @brief Position of the reference point in Z axis.
		 */
		RetroDouble		centerZ;
		
		/**
		 * @brief Direction of the up vector in X axis.
		 */
		RetroDouble		upX;
		
		/**
		 * @brief Direction of the up vector in Y axis.
		 */
		RetroDouble		upY;
		
		/**
		 * @brief Direction of the up vector in Z axis.
		 */
		RetroDouble		upZ;
	}					Camera;
	
	/**
	 * @brief Representing an 2D object.
	 *
	 * This will be used for passing less parameter
	 * and for other things.
	 */
	typedef	struct		Object2D
	{
		/**
		 * @brief An identifier to this object
		 */
		RetroUInt			id;
		
		/**
		 * @brief Position of this object on X axis.
		 */
		RetroUInt			posX;
		
		/**
		 * @brief Position of this object on Y axis.
		 */
		RetroUInt			posY;
		
		/**
		 * @brief Width of the object.
		 */
		RetroUInt			sizeX;
		
		/**
		 * @brief Height of the object.
		 */
		RetroUInt			sizeY;
		
		/**
		 * @brief Speed of the object.
		 */
		RetroUInt			speed;
		
		/**
		 * @brief Weight of the object, used for gravity calcul.
		 */
		RetroUInt			weight;
	}					Object2D;

	typedef struct		Mode7
	{
		int textID;
		int posX;
		int posY;
		int sizeX;
		int sizeY;
		float textSizeX;
		float textSizeY;
		float textWidth;
		float textHeight;
		
	}					Mode7;
	
	typedef struct		ComplexId
	{
		int				startId;
		int				Size;
	}					ComplexId;
	
	typedef struct		RetroUtf_8
	{
		int*	str;
		char**			coresp;
		
	}					RetroUtf_8;
	
	typedef struct		RetroFont
	{
		RetroUtf_8		descriptor;
		int				font;
		int				width;
		int				height;
		int				separator;
		int				size;
	}					RetroFont;
	
	/*
	typedef struct		Text
	{
		char			*str;
		Retro2DApi			*Letter;
		unsigned int	len;
		float			x;
		float			y;
	}					Text;

	typedef struct		TextBox
	{
		char			*str;
		unsigned int	len;
		float			xMin;
		float			yMin;
		float			xMax;
		float			yMax;
		Bool			fit;
	}				TextBox;
	
	typedef struct		Police
	{
		Retrouint			id;
		Retrouint			fileX;
		Retrouint			fileY;
		Retrouint			letterX;
		Retrouint			letterY;
	}					Police;
	 */

	/** @} */
	/** @} */
#ifdef		__cplusplus
}
#endif
	
#endif
