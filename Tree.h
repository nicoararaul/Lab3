#pragma once

#include "Node.h"
#include <string>

class Tree
{
	typedef class Node* nodeptr;
public:
	Tree();
	void insert(int, nodeptr);
	void del(int, nodeptr);
	std::string inorder(nodeptr);
	std::string preorder(nodeptr);
	std::string postorder(nodeptr);
	int countNodes(nodeptr);
	int countEdges(nodeptr);
	int height(nodeptr);

	



};

