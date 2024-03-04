#include "AVLTree.h"
#include <iostream>
#include <cmath>
#include "Recipe.h"

using namespace std;

AVLNode::AVLNode()
{
	//data = 0;
	left = right = NULL;
}


AVLNode::AVLNode(Recipe* data, int key)
{
	AVLNode();
	this->data = data;
	this->key = key;
}

int AVLTree::count = 0;

AVLTree::AVLTree()
{
	root = NULL;
}

AVLNode* AVLTree::insert(Recipe* data)
{
	root = insert(data, root, ++count);
	return root;
}


AVLNode* AVLTree::insert(Recipe* data, AVLNode* node, int key)
{
	if (!node)
		return new AVLNode(data, key);

	if (key > node->key)
		node->right = insert(data, node->right, key);
	else
		node->left = insert(data, node->left, key);

	node = balanceNode(node);

	return node;
}

AVLNode* AVLTree::balanceNode(AVLNode* node)
{
	// Balancing nodes.
	int balanceFactor = getBalanceFactor(node);
	if (balanceFactor >= 2)
	{
		if (!node->left->left)
			node->left = rotateLeft(node->left);

		node = rotateRight(node);
	}
	else if (balanceFactor <= -2)
	{
		if (!node->right->right)
			node->right = rotateRight(node->right);

		node = rotateLeft(node);
	}

	return node;
}

void AVLTree::display()
{
	display(root);
}

void AVLTree::display(AVLNode* node)
{
	if (!node)
		return;


	display(node->left);
	// cout << node->key << endl;
	if (node->data)
		node->data->display();
	cout << endl;
	display(node->right);
}

int AVLTree::getHeight(AVLNode* node)
{
	if (!node)
		return -1;

	return max(getHeight(node->left), getHeight(node->right)) + 1;
}

int AVLTree::getBalanceFactor(AVLNode* node)
{
	if (!node)
		return 0;

	return getHeight(node->left) - getHeight(node->right);
}

AVLNode* AVLTree::rotateRight(AVLNode* node)
{
	AVLNode* temp = node->left->right;
	node->left->right = node;
	node = node->left;
	node->right->left = temp;

	return node;
}

AVLNode* AVLTree::rotateLeft(AVLNode* node)
{
	AVLNode* temp = node->right->left;

	node->right->left = node;
	node = node->right;
	node->left->right = temp;

	return node;
}

void AVLTree::preOrder()
{
	preOrder(root);
}

void AVLTree::preOrder(AVLNode* node)
{
	if (!node)
		return;

	cout << node->key << endl;
	preOrder(node->left);
	preOrder(node->right);
}

void AVLTree::postOrder()
{
	postOrder(root);
}

void AVLTree::postOrder(AVLNode* node)
{
	if (!node)
		return;

	postOrder(node->left);
	postOrder(node->right);
	cout << node->key << endl;
}

AVLNode* AVLTree::remove(Recipe* data, AVLNode* node)
{
	if (data > node->data)
		node->right = remove(data, node->right);
	else if (data < node->data)
		node->left = remove(data, node->left);
	else
	{
		if (!node->left && !node->right)
		{
			delete node;
			node = NULL;

			return NULL;
		}

		if (node->left && !node->right)
		{
			AVLNode* left = node->left;
			node->left = NULL;
			delete node;
			node = left;

			return node;
		}

		if (!node->left && node->right)
		{
			AVLNode* right = node->right;
			node->right = NULL;
			delete node;
			node = right;

			return node;
		}

		Recipe* temp = getInOrderSuccessor(node->right)->data;
		root = remove(temp, root);
		node->data = temp;
	}

	node = balanceNode(node);

	return node;
}

AVLNode* AVLTree::remove(Recipe* data)
{
	if (!root)
		return NULL;

	root = remove(data, root);

	return root;
}

AVLNode* AVLTree::getInOrderSuccessor(AVLNode* node)
{
	AVLNode* current = node;
	while (current && current->left)
		node = current->left;

	return node;
}