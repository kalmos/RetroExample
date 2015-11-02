/*
** list for SL
**
** Made by lucas stefas
** Login   stefas_l
**
** Started on 21/05/13 12:29 2013 by lucas stefas
*/

/**
 * @file
 *
 * @ingroup RetroList
 *
 * @brief RetroList
 */

#ifndef		__list_H__
#define		__list_H__

#ifdef		__cplusplus
extern "C" {
#endif
    
#	include <RetroEngine/RetroDefine.h>
	
#	include <stdlib.h>
  
	/**
	 * @defgroup RetroList RetroList
	 *
	 * @ingroup UpperLevelGroup
	 *
	 * @brief The RetroList add an easy way to use List and Vector.
	 *
	 */
	
	/**
	 * @defgroup List List
	 *
	 * @ingroup RetroList
	 *
	 * @brief The RetroList add an easy way to use List and Vector.
	 *
	 */
	
	/**
	 * @defgroup ListGeneric ListGeneric
	 *
	 * @ingroup List
	 *
	 * @brief The RetroList add an easy way to use List and Vector.
	 *
	 * @{
	 */
	
	/**
	 * @brief Simple chained List.
	 *
	 * An object for retaining any tipe of data.
	 */
	typedef struct	List
	{
		/**
		 * @brief One of the data to retain.
		 */
		void		*data;
		
		/**
		 * @brief Identifier to access one element.
		 */
		size_t		num;
		
		/**
		 * @brief The next element or NULL.
		 */
		struct List	*next;
	}				List;
	
    /* list.c */
    
	/**
	 * @brief Put a new element in list.
	 *
	 * @param[in, out] list Adress of your list.
	 * @param[in] data A new item to put in list.
	 * @param[in] num An identifier for this item
	 * @param[in] size The size of your new item
	 * @retval 0 on sucess.
	 */
    int		putInList(List** list, void *data, const size_t num, const size_t size);
	
	/**
	 * @brief Delete an element in list.
	 * @param[in, out] list Adress of your list.
	 * @param[in] num An identifier of your item
	 * @param[in] func A specific funcion for deleting element in your list.
	 * if set to NULL, nothing will be done other than removing it from
	 * the list.
	 * @retval 0 on sucess.
	 */
    int		delElem(List** list, const size_t num, void (*func)(void*));
	
	/**
	 * @brief Delete a list
	 * @param[in, out] list Adress of your list.
	 * @param[in] func A specific funcion for deleting element in your list.
	 * if set to NULL, nothing will be done other than removing it from
	 * the list.
	 * @retval 0 on sucess.
	 */
    void	delList(List** list, void (*func)(void*));
	
	/**
	 * @brief get an element in list
	 * @param[in] list Your list.
	 * @param[in] num An identifier of your item.
	 * @retval your item or NULL if nothing was found.
	 */
    void*	getItem(List* list, const size_t num);
	
	/**
	 * @brief Get size of a list.
	 *
	 * @param[in] list your list.
	 * @retval The size of your list.
	 */
	size_t	getSize(List* list);

	/* list2.c */
	
    //void	freeMan(Drawable2D *drawable2D);
	
	/**
	 * @brief Creat a copy from memory content.
	 * @param[in] size The size to copy.
	 * @param[in] val the data to copy.
	 * @retval A new pointer with a copy of your data.
	 */
    void*	newFunc(const size_t size, void* val);
	
	/** @} */
	
	/* list3.c */
	
	/* char */
	
	/**
	 * @defgroup CharList CharList
	 *
	 * @ingroup List
	 *
	 * @brief The RetroList add an easy way to use List of char.
	 *
	 * @{
	 */
	
	/**
	 * @brief Simple chained List.
	 *
	 * An object for retaining any tipe of data.
	 */
	typedef struct		charList
	{
		/**
		 * @brief One of the data to retain.
		 */
		char			data;
		
		/**
		 * @brief Identifier to access one element.
		 */
		size_t			num;
		
		/**
		 * @brief The next element or NULL.
		 */
		struct charList	*next;
	}					charList;
	
	/**
	 * @brief Put a new element in list.
	 *
	 * @param[in, out] list Adress of your list.
	 * @param[in] data A new item to put in list.
	 * @param[in] num An identifier for this item
	 * @retval 0 on sucess.
	 */
	int				putIncharList(RETRO_TYPE_REF(charList) list, char data, const size_t num);
	
	/**
	 * @brief Delete an element in list.
	 * @param[in, out] list Adress of your list.
	 * @param[in] num An identifier of your item
	 * the list.
	 * @retval 0 on sucess.
	 */
	int				delcharElem(RETRO_TYPE_REF(charList) list, const size_t num);
	
	/**
	 * @brief Erase all element of a list
	 * @param[in, out] list Adress of your list.
	 * the list.
	 * @retval 0 on sucess.
	 */
	void			resetcharList(charList* list);
	
	/**
	 * @brief Delete a list
	 * @param[in, out] list Adress of your list.
	 * the list.
	 * @retval 0 on sucess.
	 */
	void			delcharList(charList* list);
	
	/**
	 * @brief get an element in list
	 * @param[in] list Your list.
	 * @param[in] num An identifier of your item.
	 * @retval your item or sizeof(your item)0's if nothing was found.
	 */
	char			getcharItem(RETRO_TYPE_REF_CONST(charList) list, const size_t num);
	
	/**
	 * @brief get a pointer to an element in list
	 * @param[in] list Your list.
	 * @param[in] num An identifier of your item.
	 * @retval your item or NULL if nothing was found.
	 */
	char*			getcharItemPointeur(RETRO_TYPE_REF_CONST(charList) list, const size_t num);
	
	/**
	 * @brief Get size of a list.
	 *
	 * @param[in] list your list.
	 * @retval The size of your list.
	 */
	size_t			getcharSize(RETRO_TYPE_REF_CONST(charList) list);
	
	/** @} */
	
	/* short */
	
	/**
	 * @defgroup ShortList ShortList
	 *
	 * @ingroup List
	 *
	 * @brief The RetroList add an easy way to use List of short.
	 *
	 * @{
	 */
	
	/**
	 * @brief Simple chained List.
	 *
	 * An object for retaining any tipe of data.
	 */
	typedef struct		shortList
	{
		/**
		 * @brief One of the data to retain.
		 */
		short			data;
		
		/**
		 * @brief Identifier to access one element.
		 */
		size_t			num;
		
		/**
		 * @brief The next element or NULL.
		 */
		struct shortList	*next;
	}					shortList;
	
	/**
	 * @brief Put a new element in list.
	 *
	 * @param[in, out] list Adress of your list.
	 * @param[in] data A new item to put in list.
	 * @param[in] num An identifier for this item
	 * @retval 0 on sucess.
	 */
	int				putInshortList(RETRO_TYPE_REF(shortList) list, short data, const size_t num);
	
	/**
	 * @brief Delete an element in list.
	 * @param[in, out] list Adress of your list.
	 * @param[in] num An identifier of your item
	 * the list.
	 * @retval 0 on sucess.
	 */
	int				delshortElem(RETRO_TYPE_REF(shortList) list, const size_t num);
	
	/**
	 * @brief Erase all element of a list
	 * @param[in, out] list Adress of your list.
	 * the list.
	 * @retval 0 on sucess.
	 */
	void			resetshortList(shortList* list);
	
	/**
	 * @brief Delete a list
	 * @param[in, out] list Adress of your list.
	 * the list.
	 * @retval 0 on sucess.
	 */
	void			delshortList(shortList* list);
	
	/**
	 * @brief get an element in list
	 * @param[in] list Your list.
	 * @param[in] num An identifier of your item.
	 * @retval your item or sizeof(your item)0's if nothing was found.
	 */
	short			getshortItem(RETRO_TYPE_REF_CONST(shortList) list, const size_t num);
	
	/**
	 * @brief get a pointer to an element in list
	 * @param[in] list Your list.
	 * @param[in] num An identifier of your item.
	 * @retval your item or NULL if nothing was found.
	 */
	short*			getshortItemPointeur(RETRO_TYPE_REF_CONST(shortList) list, const size_t num);
	
	/**
	 * @brief Get size of a list.
	 *
	 * @param[in] list your list.
	 * @retval The size of your list.
	 */
	size_t			getshortSize(RETRO_TYPE_REF_CONST(shortList) list);
	
	/** @} */
	
	/* int */
	
	/**
	 * @defgroup IntList IntList
	 *
	 * @ingroup List
	 *
	 * @brief The RetroList add an easy way to use List of int.
	 *
	 * @{
	 */
	
	/**
	 * @brief Simple chained List.
	 *
	 * An object for retaining any tipe of data.
	 */
	typedef struct		intList
	{
		/**
		 * @brief One of the data to retain.
		 */
		int			data;
		
		/**
		 * @brief Identifier to access one element.
		 */
		size_t			num;
		
		/**
		 * @brief The next element or NULL.
		 */
		struct intList	*next;
	}					intList;
	
	/**
	 * @brief Put a new element in list.
	 *
	 * @param[in, out] list Adress of your list.
	 * @param[in] data A new item to put in list.
	 * @param[in] num An identifier for this item
	 * @retval 0 on sucess.
	 */
	int				putInintList(RETRO_TYPE_REF(intList) list, int data, const size_t num);
	
	/**
	 * @brief Delete an element in list.
	 * @param[in, out] list Adress of your list.
	 * @param[in] num An identifier of your item
	 * the list.
	 * @retval 0 on sucess.
	 */
	int				delintElem(RETRO_TYPE_REF(intList) list, const size_t num);
	
	/**
	 * @brief Erase all element of a list
	 * @param[in, out] list Adress of your list.
	 * the list.
	 * @retval 0 on sucess.
	 */
	void			resetintList(intList* list);
	
	/**
	 * @brief Delete a list
	 * @param[in, out] list Adress of your list.
	 * the list.
	 * @retval 0 on sucess.
	 */
	void			delintList(intList* list);
	
	/**
	 * @brief get an element in list
	 * @param[in] list Your list.
	 * @param[in] num An identifier of your item.
	 * @retval your item or sizeof(your item)0's if nothing was found.
	 */
	int			getintItem(RETRO_TYPE_REF_CONST(intList) list, const size_t num);
	
	/**
	 * @brief get a pointer to an element in list
	 * @param[in] list Your list.
	 * @param[in] num An identifier of your item.
	 * @retval your item or NULL if nothing was found.
	 */
	int*			getintItemPointeur(RETRO_TYPE_REF_CONST(intList) list, const size_t num);
	
	/**
	 * @brief Get size of a list.
	 *
	 * @param[in] list your list.
	 * @retval The size of your list.
	 */
	size_t			getintSize(RETRO_TYPE_REF_CONST(intList) list);
	
	/** @} */
	
	/* long */
	
	/**
	 * @defgroup LongList LongList
	 *
	 * @ingroup List
	 *
	 * @brief The RetroList add an easy way to use List of long.
	 *
	 * @{
	 */
	
	/**
	 * @brief Simple chained List.
	 *
	 * An object for retaining any tipe of data.
	 */
	typedef struct		longList
	{
		/**
		 * @brief One of the data to retain.
		 */
		long			data;
		
		/**
		 * @brief Identifier to access one element.
		 */
		size_t			num;
		
		/**
		 * @brief The next element or NULL.
		 */
		struct longList	*next;
	}					longList;
	
	/**
	 * @brief Put a new element in list.
	 *
	 * @param[in, out] list Adress of your list.
	 * @param[in] data A new item to put in list.
	 * @param[in] num An identifier for this item
	 * @retval 0 on sucess.
	 */
	int				putInlongList(RETRO_TYPE_REF(longList) list, long data, const size_t num);
	
	/**
	 * @brief Delete an element in list.
	 * @param[in, out] list Adress of your list.
	 * @param[in] num An identifier of your item
	 * the list.
	 * @retval 0 on sucess.
	 */
	int				dellongElem(RETRO_TYPE_REF(longList) list, const size_t num);
	
	/**
	 * @brief Erase all element of a list
	 * @param[in, out] list Adress of your list.
	 * the list.
	 * @retval 0 on sucess.
	 */
	void			resetlongList(longList* list);
	
	/**
	 * @brief Delete a list
	 * @param[in, out] list Adress of your list.
	 * the list.
	 * @retval 0 on sucess.
	 */
	void			dellongList(longList* list);
	
	/**
	 * @brief get an element in list
	 * @param[in] list Your list.
	 * @param[in] num An identifier of your item.
	 * @retval your item or sizeof(your item)0's if nothing was found.
	 */
	long			getlongItem(RETRO_TYPE_REF_CONST(longList) list, const size_t num);
	
	/**
	 * @brief get a pointer to an element in list
	 * @param[in] list Your list.
	 * @param[in] num An identifier of your item.
	 * @retval your item or NULL if nothing was found.
	 */
	long*			getlongItemPointeur(RETRO_TYPE_REF_CONST(longList) list, const size_t num);
	
	/**
	 * @brief Get size of a list.
	 *
	 * @param[in] list your list.
	 * @retval The size of your list.
	 */
	size_t			getlongSize(RETRO_TYPE_REF_CONST(longList) list);
	
	/** @} */
	
	/* float */
	
	/**
	 * @defgroup FloatList FloatList
	 *
	 * @ingroup List
	 *
	 * @brief The RetroList add an easy way to use List of float.
	 *
	 * @{
	 */
	
	/**
	 * @brief Simple chained List.
	 *
	 * An object for retaining any tipe of data.
	 */
	typedef struct		floatList
	{
		/**
		 * @brief One of the data to retain.
		 */
		float			data;
		
		/**
		 * @brief Identifier to access one element.
		 */
		size_t			num;
		
		/**
		 * @brief The next element or NULL.
		 */
		struct floatList	*next;
	}					floatList;
	
	/**
	 * @brief Put a new element in list.
	 *
	 * @param[in, out] list Adress of your list.
	 * @param[in] data A new item to put in list.
	 * @param[in] num An identifier for this item
	 * @retval 0 on sucess.
	 */
	int				putInfloatList(RETRO_TYPE_REF(floatList) list, float data, const size_t num);
	
	/**
	 * @brief Delete an element in list.
	 * @param[in, out] list Adress of your list.
	 * @param[in] num An identifier of your item
	 * the list.
	 * @retval 0 on sucess.
	 */
	int				delfloatElem(RETRO_TYPE_REF(floatList) list, const size_t num);
	
	/**
	 * @brief Erase all element of a list
	 * @param[in, out] list Adress of your list.
	 * the list.
	 * @retval 0 on sucess.
	 */
	void			resetfloatList(floatList* list);
	
	/**
	 * @brief Delete a list
	 * @param[in, out] list Adress of your list.
	 * the list.
	 * @retval 0 on sucess.
	 */
	void			delfloatList(floatList* list);
	
	/**
	 * @brief get an element in list
	 * @param[in] list Your list.
	 * @param[in] num An identifier of your item.
	 * @retval your item or sizeof(your item)0's if nothing was found.
	 */
	float			getfloatItem(RETRO_TYPE_REF_CONST(floatList) list, const size_t num);
	
	/**
	 * @brief get a pointer to an element in list
	 * @param[in] list Your list.
	 * @param[in] num An identifier of your item.
	 * @retval your item or NULL if nothing was found.
	 */
	float*			getfloatItemPointeur(RETRO_TYPE_REF_CONST(floatList) list, const size_t num);
	
	/**
	 * @brief Get size of a list.
	 *
	 * @param[in] list your list.
	 * @retval The size of your list.
	 */
	size_t			getfloatSize(RETRO_TYPE_REF_CONST(floatList) list);
	
	/** @} */
	
	/* double */
	
	/**
	 * @defgroup DoubleList DoubleList
	 *
	 * @ingroup List
	 *
	 * @brief The RetroList add an easy way to use List of char.
	 *
	 * @{
	 */
	
	/**
	 * @brief Simple chained List.
	 *
	 * An object for retaining any tipe of data.
	 */
	typedef struct		doubleList
	{
		/**
		 * @brief One of the data to retain.
		 */
		double			data;
		
		/**
		 * @brief Identifier to access one element.
		 */
		size_t			num;
		
		/**
		 * @brief The next element or NULL.
		 */
		struct doubleList	*next;
	}					doubleList;
	
	/**
	 * @brief Put a new element in list.
	 *
	 * @param[in, out] list Adress of your list.
	 * @param[in] data A new item to put in list.
	 * @param[in] num An identifier for this item
	 * @retval 0 on sucess.
	 */
	int				putIndoubleList(RETRO_TYPE_REF(doubleList) list, double data, const size_t num);
	
	/**
	 * @brief Delete an element in list.
	 * @param[in, out] list Adress of your list.
	 * @param[in] num An identifier of your item
	 * the list.
	 * @retval 0 on sucess.
	 */
	int				deldoubleElem(RETRO_TYPE_REF(doubleList) list, const size_t num);
	
	/**
	 * @brief Erase all element of a list
	 * @param[in, out] list Adress of your list.
	 * the list.
	 * @retval 0 on sucess.
	 */
	void			resetdoubleList(doubleList* list);
	
	/**
	 * @brief Delete a list
	 * @param[in, out] list Adress of your list.
	 * the list.
	 * @retval 0 on sucess.
	 */
	void			deldoubleList(doubleList* list);
	
	/**
	 * @brief get an element in list
	 * @param[in] list Your list.
	 * @param[in] num An identifier of your item.
	 * @retval your item or sizeof(your item)0's if nothing was found.
	 */
	double			getdoubleItem(RETRO_TYPE_REF_CONST(doubleList) list, const size_t num);
	
	/**
	 * @brief get a pointer to an element in list
	 * @param[in] list Your list.
	 * @param[in] num An identifier of your item.
	 * @retval your item or NULL if nothing was found.
	 */
	double*			getdoubleItemPointeur(RETRO_TYPE_REF_CONST(doubleList) list, const size_t num);
	
	/**
	 * @brief Get size of a list.
	 *
	 * @param[in] list your list.
	 * @retval The size of your list.
	 */
	size_t			getdoubleSize(RETRO_TYPE_REF_CONST(doubleList) list);
		
	/** @} */
#ifdef		__cplusplus
}
#endif

#endif
