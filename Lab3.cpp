// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Tree.h"
#include <iostream>

using namespace std;

int main()
{
	typedef class Node* Nodeptr;
	Tree tree;
	Nodeptr root = new Node(10);
	
	int v[] = { 8, 12 , 7, 13, 14, 6, 9, 11 };
	int lungime = sizeof(v) / sizeof(v[0]);

	for (int i = 0; i < lungime; i++)
	{
		tree.insert(v[i], root);
	}

	cout << "inorder: " << tree.inorder(root) << endl;
	cout << "preorder: " << tree.preorder(root) << endl;
	cout << "postorder: " << tree.postorder(root) << endl;

	cout << "Nr nodurilor, respectiv muchiilor: " << tree.countNodes(root) << ' ' << tree.countEdges(root) << endl;
	
	tree.del(13, root);

	
	

}

