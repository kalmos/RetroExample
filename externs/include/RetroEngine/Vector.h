/*
** vector.h for SL
**
** Made by lucas stefas
** Login   stefas_l
**
** Started on 22/11/2013 12:07 2013 by lucas stefas
*/

#ifndef		__vector_H__
#define		__vector_H__

#ifdef		__cplusplus
extern "C" {
#endif
	
	/**
	 * @file
	 *
	 * @ingroup RetroList
	 *
	 * @brief RetroList
	 */
	
#include	<RetroEngine/RetroType.h>
#include	<RetroEngine/RetroDefine.h>	
	
	/**
	 * @defgroup Vector Vector
	 *
	 * @ingroup RetroList
	 *
	 * @brief The RetroList add an easy way to use List and Vector.
	 *
	 *
	 */
	
	/**
	 * @defgroup GenericVector GenericVector
	 *
	 * @ingroup Vector
	 *
	 * @brief Will allow to use C++ like vector in C.
	 *
	 * Allow to use generic C++ like vector in C.
	 * @{
	 */
	
	/* vector.c */
    
	/**
	 * @brief Get size of a vector.
	 *
	 * @param[in] vector The vector you work with.
	 * @retval The size of your vector.
	 */
	RetroUInt32	getSizeGenericVector(void** vector);
	
	/**
	 * @brief Put an element in a vector. if their is not enough space
	 on the vector, it allocate it.
	 *
	 * @param[in, out] vector The vector you work with.
	 * @param[in] data The data to put in.
	 * @param[in] num The case of the vector to put the data in.
	 * @retval alwais return 1337
	 */
    int			putInGenericVector(RETRO_TYPE_REF(void**) vector, void *data, const size_t num);
	
	/**
	 * @brief Get element from a vector. if the element is not found,
	 * will make an assert.
	 *
	 * @param[in] vector The vector you work with.
	 * @param[in] num Position of the element on the vector.
	 * @retval On sucess, return your elemen. on error return NULL.
	 */
    void*		getGenericItemVector(void** vector, const size_t num);

	/* vector2.c */
	
	/**
	 * @brief Free the vector
	 *
	 * @param[in, out] vector The vector you work with.
	 */
	void		freeGenericVector(RETRO_TYPE_REF(void**) vector);
	
	/**
	 * @brief allocate memory for a new vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] size Future size of the vector.
	 */
	void		reserveGenericVector(RETRO_TYPE_REF(void**) vector, RetroUInt32 size);
	
	/**
	 * @brief Change size of a vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] newSize Future size of the vector.
	 */
	void		resizeGenericVector(RETRO_TYPE_REF(void**) vector, RetroUInt32 newSize);
	
	/**
	 * @brief Show address of each element on the vector.
	 *
	 * @param[in] vector The vector you will work with.
	 */
	void		showGenericVector(void** vector);
	
    //void	freeMan(Drawable2D *drawable2D);
    //void*	newFunc(const size_t size, void* val);
	
	/** @} */
	
	/* vector3.c */
	
	/* char */
	
	/**
	 * @defgroup CharVector CharVector
	 *
	 * @ingroup Vector
	 *
	 * @brief Will allow to use C++ like vector in C for char only.
	 *
	 * Allow to use generic C++ like vector in C for char only.
	 * @{
	 */
	
	/**
	 * @brief Get size of a vector.
	 *
	 * @param[in] vector The vector you work with.
	 * @retval The size of your vector.
	 */
	RetroUInt32	getSizecharVector(char* vector);
	
	/**
	 * @brief Put an element in a vector. if their is not enough space
	 on the vector, it allocate it.
	 *
	 * @param[in, out] vector The vector you work with.
	 * @param[in] data The data to put in.
	 * @param[in] num The case of the vector to put the data in.
	 * @retval alwais return 1337
	 */
    int			putIncharVector(RETRO_TYPE_REF(char*) vector, char data, const size_t num);
	
	/**
	 * @brief Get element from a vector. if the element is not found,
	 * will make an assert.
	 *
	 * @param[in] vector The vector you work with.
	 * @param[in] num Position of the element on the vector.
	 * @retval On sucess, return your elemen. on error return NULL.
	 */
    char		getItemcharVector(char* vector, const size_t num);
	
	/**
	 * @brief Free the vector
	 *
	 * @param[in, out] vector The vector you work with.
	 */
	void		freecharVector(RETRO_TYPE_REF(char*) vector);
	
	/**
	 * @brief allocate memory for a new vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] size Future size of the vector.
	 */
	void		reservecharVector(RETRO_TYPE_REF(char*) vector, RetroUInt32 size);
	
	/**
	 * @brief Change size of a vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] newSize Future size of the vector.
	 */
	void		resizecharVector(RETRO_TYPE_REF(char*) vector, RetroUInt32 newSize);
	
	/** @} */
	
	/* short */
	
	/**
	 * @defgroup ShortVector ShortVector
	 *
	 * @ingroup Vector
	 *
	 * @brief Will allow to use C++ like vector in C for short only.
	 *
	 * Allow to use generic C++ like vector in C for short only.
	 * @{
	 */
	
	/**
	 * @brief Get size of a vector.
	 *
	 * @param[in] vector The vector you work with.
	 * @retval The size of your vector.
	 */
	RetroUInt32	getSizeshortVector(short* vector);
	
	/**
	 * @brief Put an element in a vector. if their is not enough space
	 on the vector, it allocate it.
	 *
	 * @param[in, out] vector The vector you work with.
	 * @param[in] data The data to put in.
	 * @param[in] num The case of the vector to put the data in.
	 * @retval alwais return 1337
	 */
    int			putInshortVector(RETRO_TYPE_REF(short*) vector, short data, const size_t num);
	
	/**
	 * @brief Get element from a vector. if the element is not found,
	 * will make an assert.
	 *
	 * @param[in] vector The vector you work with.
	 * @param[in] num Position of the element on the vector.
	 * @retval On sucess, return your elemen. on error return NULL.
	 */
    short		getItemshortVector(short* vector, const size_t num);
	
	/**
	 * @brief Free the vector
	 *
	 * @param[in, out] vector The vector you work with.
	 */
	void		freeshortVector(RETRO_TYPE_REF(short*) vector);
	
	/**
	 * @brief allocate memory for a new vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] size Future size of the vector.
	 */
	void		reserveshortVector(RETRO_TYPE_REF(short*) vector, RetroUInt32 size);
	
	/**
	 * @brief Change size of a vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] newSize Future size of the vector.
	 */
	void		resizeshortVector(RETRO_TYPE_REF(short*) vector, RetroUInt32 newSize);
	
	/** @} */
	
	/* int */
	
	/**
	 * @defgroup IntVector IntVector
	 *
	 * @ingroup Vector
	 *
	 * @brief Will allow to use C++ like vector in C for int only.
	 *
	 * Allow to use generic C++ like vector in C for int only.
	 * @{
	 */
	
	/**
	 * @brief Get size of a vector.
	 *
	 * @param[in] vector The vector you work with.
	 * @retval The size of your vector.
	 */
	RetroUInt32	getSizeintVector(int* vector);
	
	/**
	 * @brief Put an element in a vector. if their is not enough space
	 on the vector, it allocate it.
	 *
	 * @param[in, out] vector The vector you work with.
	 * @param[in] data The data to put in.
	 * @param[in] num The case of the vector to put the data in.
	 * @retval alwais return 1337
	 */
    int			putInintVector(RETRO_TYPE_REF(int*) vector, int data, const size_t num);
	
	/**
	 * @brief Get element from a vector. if the element is not found,
	 * will make an assert.
	 *
	 * @param[in] vector The vector you work with.
	 * @param[in] num Position of the element on the vector.
	 * @retval On sucess, return your elemen. on error return NULL.
	 */
    int		getItemintVector(int* vector, const size_t num);
	
	/**
	 * @brief Free the vector
	 *
	 * @param[in, out] vector The vector you work with.
	 */
	void		freeintVector(RETRO_TYPE_REF(int*) vector);
	
	/**
	 * @brief allocate memory for a new vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] size Future size of the vector.
	 */
	void		reserveintVector(RETRO_TYPE_REF(int*) vector, RetroUInt32 size);
	
	/**
	 * @brief Change size of a vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] newSize Future size of the vector.
	 */
	void		resizeintVector(RETRO_TYPE_REF(int*) vector, RetroUInt32 newSize);
	
	/** @} */
	
	/* long */
	
	/**
	 * @defgroup LongVector LongVector
	 *
	 * @ingroup Vector
	 *
	 * @brief Will allow to use C++ like vector in C for long only.
	 *
	 * Allow to use generic C++ like vector in C for long only.
	 * @{
	 */
	
	/**
	 * @brief Get size of a vector.
	 *
	 * @param[in] vector The vector you work with.
	 * @retval The size of your vector.
	 */
	RetroUInt32	getSizelongVector(long* vector);
	
	/**
	 * @brief Put an element in a vector. if their is not enough space
	 on the vector, it allocate it.
	 *
	 * @param[in, out] vector The vector you work with.
	 * @param[in] data The data to put in.
	 * @param[in] num The case of the vector to put the data in.
	 * @retval alwais return 1337
	 */
    int			putInlongVector(RETRO_TYPE_REF(long*) vector, long data, const size_t num);
	
	/**
	 * @brief Get element from a vector. if the element is not found,
	 * will make an assert.
	 *
	 * @param[in] vector The vector you work with.
	 * @param[in] num Position of the element on the vector.
	 * @retval On sucess, return your elemen. on error return NULL.
	 */
    long		getItemlongVector(long* vector, const size_t num);
	
	/**
	 * @brief Free the vector
	 *
	 * @param[in, out] vector The vector you work with.
	 */
	void		freelongVector(RETRO_TYPE_REF(long*) vector);
	
	/**
	 * @brief allocate memory for a new vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] size Future size of the vector.
	 */
	void		reservelongVector(RETRO_TYPE_REF(long*) vector, RetroUInt32 size);
	
	/**
	 * @brief Change size of a vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] newSize Future size of the vector.
	 */
	void		resizelongVector(RETRO_TYPE_REF(long*) vector, RetroUInt32 newSize);
	
	/** @} */
	
	/* float */
	
	/**
	 * @defgroup FloatVector FloatVector
	 *
	 * @ingroup Vector
	 *
	 * @brief Will allow to use C++ like vector in C for float only.
	 *
	 * Allow to use generic C++ like vector in C for float only.
	 * @{
	 */
	
	/**
	 * @brief Get size of a vector.
	 *
	 * @param[in] vector The vector you work with.
	 * @retval The size of your vector.
	 */
	RetroUInt32	getSizefloatVector(float* vector);
	
	/**
	 * @brief Put an element in a vector. if their is not enough space
	 on the vector, it allocate it.
	 *
	 * @param[in, out] vector The vector you work with.
	 * @param[in] data The data to put in.
	 * @param[in] num The case of the vector to put the data in.
	 * @retval alwais return 1337
	 */
    int			putInfloatVector(RETRO_TYPE_REF(float*) vector, float data, const size_t num);
	
	/**
	 * @brief Get element from a vector. if the element is not found,
	 * will make an assert.
	 *
	 * @param[in] vector The vector you work with.
	 * @param[in] num Position of the element on the vector.
	 * @retval On sucess, return your elemen. on error return NULL.
	 */
    float		getItemfloatVector(float* vector, const size_t num);
	
	/**
	 * @brief Free the vector
	 *
	 * @param[in, out] vector The vector you work with.
	 */
	void		freefloatVector(RETRO_TYPE_REF(float*) vector);
	
	/**
	 * @brief allocate memory for a new vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] size Future size of the vector.
	 */
	void		reservefloatVector(RETRO_TYPE_REF(float*) vector, RetroUInt32 size);
	
	/**
	 * @brief Change size of a vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] newSize Future size of the vector.
	 */
	void		resizefloatVector(RETRO_TYPE_REF(float*) vector, RetroUInt32 newSize);
	
	/** @} */
	
	/* double */
	
	/**
	 * @defgroup DoubleVector DoubleVector
	 *
	 * @ingroup Vector
	 *
	 * @brief Will allow to use C++ like vector in C for double only.
	 *
	 * Allow to use generic C++ like vector in C for double only.
	 * @{
	 */
	
	/**
	 * @brief Get size of a vector.
	 *
	 * @param[in] vector The vector you work with.
	 * @retval The size of your vector.
	 */
	RetroUInt32	getSizedoubleVector(double* vector);
	
	/**
	 * @brief Put an element in a vector. if their is not enough space
	 on the vector, it allocate it.
	 *
	 * @param[in, out] vector The vector you work with.
	 * @param[in] data The data to put in.
	 * @param[in] num The case of the vector to put the data in.
	 * @retval alwais return 1337
	 */
    int			putIndoubleVector(RETRO_TYPE_REF(double*) vector, double data, const size_t num);
	
	/**
	 * @brief Get element from a vector. if the element is not found,
	 * will make an assert.
	 *
	 * @param[in] vector The vector you work with.
	 * @param[in] num Position of the element on the vector.
	 * @retval On sucess, return your elemen. on error return NULL.
	 */
    double		getItemdoubleVector(double* vector, const size_t num);
	
	/**
	 * @brief Free the vector
	 *
	 * @param[in, out] vector The vector you work with.
	 */
	void		freedoubleVector(RETRO_TYPE_REF(double*) vector);
	
	/**
	 * @brief allocate memory for a new vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] size Future size of the vector.
	 */
	void		reservedoubleVector(RETRO_TYPE_REF(double*) vector, RetroUInt32 size);
	
	/**
	 * @brief Change size of a vector.
	 *
	 * @param[in, out] vector The vector you will work with.
	 * @param[in] newSize Future size of the vector.
	 */
	void		resizedoubleVector(RETRO_TYPE_REF(double*) vector, RetroUInt32 newSize);
	
	/** @} */
	
#ifdef		__cplusplus
}
#endif

#endif
