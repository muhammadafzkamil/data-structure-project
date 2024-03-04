#ifndef AVL_H
#define AVL_H
#include "Recipe.h"


class AVLNode
{
public:
	AVLNode();
	AVLNode(Recipe*, int);

	int key;
	Recipe* data;
	AVLNode* left;
	AVLNode* right;
};

class AVLTree
{
public:
	AVLNode* root;
	AVLTree();
	AVLNode* insert(Recipe*);
	void display();
	void preOrder();
	void postOrder();
	int getBalanceFactor(AVLNode*);
	AVLNode* rotateRight(AVLNode*);
	AVLNode* rotateLeft(AVLNode*);
	AVLNode* remove(Recipe*);

private:
	AVLNode* insert(Recipe*, AVLNode*, int);
	void display(AVLNode*);
	int getHeight(AVLNode*);

	void preOrder(AVLNode*);
	void postOrder(AVLNode*);
	AVLNode* balanceNode(AVLNode*);
	AVLNode* remove(Recipe*, AVLNode*);
	AVLNode* getInOrderSuccessor(AVLNode*);
	static int count;
};

#endif