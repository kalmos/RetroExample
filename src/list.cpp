/*
** list.cpp
**
** Made by lucas stefas
** Started on 03/07/14 22:47
*/

#include <RetroEngine/List.h>
#include <RetroEngine/Vector.h>
#include <RetroEngine/RetroSystem.h>
#include <SDL/SDL.h>
#include <iostream>
#include "Input.h"

int initList(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	intList list;
	int*	vector = NULL;
	Object2D	obj;
	int id = 0;
	
	RetroChangeResolution(320, 240, RETRO_FIT_WINDOW_KEPT_RATIO, *system);
	RetroAddFont(0, "ABCDEFGH\nIJKLMNO \nPQRSTUVW\nXYZ.,:& \nabcdefgh\nijklmno\"\npqrstuvw\nxyz.,/&]\n01234567\n89+-*%=[", "font/mariopaint.bmp", *system);
	
	obj.posX = 0;
	obj.posY = 0;
	obj.sizeX = 8;
	obj.sizeY = 8;
	RetroWrite(id++, "list", &obj, 0, api);
	
	/*
	 * working with the list system.
	 * Retro engine essentialy work with that.
	 * if seeing any error, please report them.
	 */
	list.next = NULL;//preparing the list.
	putInintList(&list, 1, 1);// adding some value.
	putInintList(&list, 2, 3);
	putInintList(&list, 3, 5);
	putInintList(&list, 4, 7);
	obj.posY += 8;
	RetroWrite(id++, "list[1] = %d", &obj, 0, api, getintItem(&list, 1)); // seeing everithing is normal.
	obj.posY += 8;
	RetroWrite(id++, "list[3] = %d", &obj, 0, api, getintItem(&list, 3));
	obj.posY += 8;
	RetroWrite(id++, "list[5] = %d", &obj, 0, api, getintItem(&list, 5));
	obj.posY += 8;
	RetroWrite(id++, "list[7] = %d", &obj, 0, api, getintItem(&list, 7));
	obj.posY += 8;
	RetroWrite(id++, "list size = %ld", &obj, 0, api, getintSize(&list)); // and now the list size.
	putInintList(&list, 42, 2); // ading one more... oops
	obj.posY += 8;
	RetroWrite(id++, "list[2] = %d", &obj, 0, api, getintItem(&list, 2));
	obj.posY += 8;
	RetroWrite(id++, "list size = %ld", &obj, 0, api, getintSize(&list));
	delintElem(&list, 2); // deleting this error.
	obj.posY += 8;
	RetroWrite(id++, "list size = %ld", &obj, 0, api, getintSize(&list)); // and now the list size.
	resetintList(&list); // finishing working here and the list is not created with malloc
	obj.posY += 8;
	RetroWrite(id++, "list size = %ld", &obj, 0, api, getintSize(&list)); // and now the list size.
	
	
	obj.posY += 16;
	RetroWrite(id++, "vector", &obj, 0, api);
	
	/*
	 * working with vector.
	 */
	reserveintVector(&vector, 6); // first we alocate the vector.
	vector[0] = 1; // put element in the vector the normal way.
	vector[1] = 2;
	vector[2] = 3;
	putInintVector(&vector, 4, 3); //put element in the vector the alternate way.
	putInintVector(&vector, 5, 4);
	putInintVector(&vector, 24, 5);
	obj.posY += 8;
	RetroWrite(id++, "vector[0] = %d", &obj, 0, api, getItemintVector(vector, 0)); //seeing everithing is normal.
	obj.posY += 8;
	RetroWrite(id++, "vector[1] = %d", &obj, 0, api, getItemintVector(vector, 1));
	obj.posY += 8;
	RetroWrite(id++, "vector[2] = %d", &obj, 0, api, getItemintVector(vector, 2));
	obj.posY += 8;
	RetroWrite(id++, "vector[3] = %d", &obj, 0, api, vector[3]);
	obj.posY += 8;
	RetroWrite(id++, "vector[4] = %d", &obj, 0, api, vector[4]);
	obj.posY += 8;
	RetroWrite(id++, "vector[5] = %d", &obj, 0, api, vector[5]);
	obj.posY += 8;
	RetroWrite(id++, "vector size = %d", &obj, 0, api, getSizeintVector(vector)); // and checking his size
	putInintVector(&vector, 42, 6); // put another element in the vector for expending it.
	obj.posY += 8;
	RetroWrite(id++, "vector[6] = %d", &obj, 0, api, vector[6]); //seeing everithing is normal.
	obj.posY += 8;
	RetroWrite(id++, "vector size = %d", &obj, 0, api, getSizeintVector(vector)); //seeing the new size.
	resizeintVector(&vector, 10); // changing again his size.
	obj.posY += 8;
	RetroWrite(id++, "vector size = %d", &obj, 0, api, getSizeintVector(vector)); // verifiing the cange take effect.
	freeintVector(&vector); //freeing the memory.
	obj.posY += 8;
	RetroWrite(id++, "vector addresse = %p", &obj, 0, api, vector); // yep, it's free.
	return (0);
}

int	ListIter(Input& input, RETRO_TYPE_REF(Retro2DApi) api)
{
	(void)api;
	return (0);
}

int	stopList(RetroSystem** system, RETRO_TYPE_REF(Retro2DApi) api)
{
	RetroDeleteText(0, api);
	RetroDeleteText(1, api);
	RetroDeleteText(2, api);
	RetroDeleteText(3, api);
	RetroDeleteText(4, api);
	RetroDeleteText(5, api);
	RetroDeleteText(6, api);
	RetroDeleteText(7, api);
	RetroDeleteText(8, api);
	RetroDeleteText(9, api);
	RetroDeleteText(10, api);
	RetroDeleteText(11, api);
	RetroDeleteText(12, api);
	RetroDeleteText(13, api);
	RetroDeleteText(14, api);
	RetroDeleteText(15, api);
	RetroDeleteText(16, api);
	RetroDeleteText(17, api);
	RetroDeleteText(18, api);
	RetroDeleteText(19, api);
	RetroDeleteText(20, api);
	RetroDeleteText(21, api);
	RetroDeleteFont(0, *system);
	return (0);
}