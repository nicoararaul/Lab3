#include "pch.h"
#include "Tree.h"
#include "Node.h"
#include <iostream>
#include <string>


void Tree::insert(int ival, nodeptr root)
{
	nodeptr newnode = new Node(ival);
	if (!root)
		root = newnode;
	else
	{
		nodeptr iterator = root;
		nodeptr aux = NULL;
		while (iterator != NULL)
		{
			aux = iterator;
			if (ival < iterator->val)
				iterator = iterator->left;
			else
				iterator = iterator->right;
		}
		if (ival < aux->val)
			aux->left = newnode;
		else
			aux->right = newnode;
	}

}

void Tree::del(int ival, nodeptr root)
{
	if (root == NULL)
		return;
	nodeptr nodcurent = root;
	nodeptr tata = NULL;

	while (nodcurent != NULL && nodcurent->val != ival)
	{
		tata = nodcurent;
		if (ival < nodcurent->val)
			nodcurent = nodcurent->left;
		else
			nodcurent = nodcurent->right;
	}
	if (nodcurent == NULL) {
		std::cout << "Nu exista nodul cautat"; 
		return;
	}
	// Cazul in care nodul nu are fii
	if (nodcurent->left == NULL && nodcurent->right == NULL)
	{
		if (nodcurent != root)
		{
			if (tata->right == nodcurent)
				tata->right = NULL;
			else
				tata->left = NULL;
		}
		delete nodcurent;
	}

	// Cazul in care nodul are un singur  fiu
	if (nodcurent->left == NULL || nodcurent->right == NULL)
	{
		nodeptr fiu = NULL;
		if (nodcurent->left == NULL)
			fiu = nodcurent->right;
		else
			fiu = nodcurent->left;
		if (nodcurent != root)
		{
			if (nodcurent == tata->left)
				tata->left = fiu;
			else
				tata->right = fiu;
			}
		else
			root = fiu;
		delete nodcurent;
	}

	if (nodcurent->left && nodcurent->right)
	{
		nodeptr urmator = nodcurent->right;
		while (urmator->left != NULL)
			urmator = urmator->left;
		int v = urmator->val;
		del(urmator->val, root);
		nodcurent->val = v;
	}
}


std::string Tree::inorder(nodeptr root)
{
	if (root == NULL)
		return "";
	return inorder(root->left) + std::to_string(root->val) + " " + inorder(root->right);
}
std::string Tree::preorder(nodeptr root)
{
	if (root == NULL)
		return "";
	return std::to_string(root->val) + " " + preorder(root->left) + preorder(root->right);
}

std::string Tree::postorder(nodeptr root) 
{ 
	if (root == NULL)
		return "";
	return postorder(root->left) + postorder(root->right) + std::to_string(root->val) + " ";
}

int Tree::countNodes(nodeptr root)
{
	if (root == NULL)
		return 0;
	
	if (root->left == NULL && root->right == NULL)
		return 1;
	
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int Tree::countEdges(nodeptr root)
{
	return countNodes(root) - 1;
}

int Tree::height(nodeptr root)
{
	if (root == NULL)
		return 0;
	int stanga = height(root->left);
	int dreapta = height(root->right);
	if (stanga > dreapta)
		return stanga + 1;
	return dreapta + 1;
}


