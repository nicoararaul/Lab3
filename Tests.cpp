#include "pch.h"
#include "Tests.h"
#include "Tree.h"
#include <iostream>
#include <assert.h>

void testall()
{
	typedef class Node* Nodeptr;
	Tree arbore;
	Nodeptr radacina = new Node(10);

	int arr[] = { 8, 12 , 7, 13, 14, 6, 9, 11 };
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < size; i++)
	{
		arbore.insert(arr[i], radacina);
	}
	
	assert(arbore.countNodes(radacina) == size);
	assert(arbore.countEdges(radacina) == size - 1);

	arbore.del(13, radacina);

	assert(arbore.countNodes(radacina) == size - 1);



}