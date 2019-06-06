/* @file AVLbinarytree.h 
   @name caleb cramer
   @date 28 April 2019 */

#ifndef AVLTREE_H
#define AVLTREE_H
#include "binarytree.h"
#include "binarysearchtree.h"
#include "node.h"
#include <iostream>
using namespace std;

//subclass of BST
class AVLTree: public BinarySearchTree
{
protected:
	//actual function to insert an item
	//@recursively searches for the correct place and then inserts the item. also balances tree
    //@pre: treeptr is assigned. newItem is assigned.
    //@post: searches for tkey in the tree with treeptr's root.
    //    If tkey is found, theItem is the key together with the other
    //    parts of the item. Else an exception is thrown. We also have a balanced AVL tree
    //@usage: insertItem(mroot, key);
	void insertItem(Node *& treeptr, const ItemType& newItem);

	//@checks for null and assign 0. otherwise returns height(lst)-height(rst)
    //@pre: treeptr is assigned.
    //@post: returns the balance
    //@usage: checkBalance(mroot);
	int checkBalance(Node *treeptr);

	//used if rst if taller than lst
	//@pre: tree must exist
	//@post: we have a slightly more balanced or fully balanced tree
	//@usage: treeptr=rotateRight(treeptr);
	Node *rotateLeft(Node *treeptr);

	//used if lst is taller than rst
	//@pre: tree must exist
	//@post: we have a slightly more balanced or fully balanced tree
	//@usage: treeptr=rotateLeft(treeptr);
	Node *rotateRight(Node *treeptr);

	//required for the case if curr==NULL => returns 0, returns height otherwise
	//@pre: must have a node with an item in it
	//@post: returns height of node
	//@usage: height(treeptr->mleftptr)
	int height(const Node *curr);

public:
	//basic constructor
	//@creates a new AVLTREE
    //@post: an empty AVL tree object exists
    //@usage: AVLTree avl;
	AVLTree();

	//allows for initial insertion of head item
	//@creates a new AVL tree
    //@post: an AVL tree object exists with a root with mitem=newItem
    //@usage: AVLTree avl(q1);
	AVLTree(const ItemType& newItem);

	//basic destructor
	//@releases memory for a AVL tree
    //@pre: AVL tree object exists
    //@post: AVL tree object does not exist
    //@usage: automatically done at end of scope
	~AVLTree();

	//public helper for insertItem
	//@inserts a new item into the AVL tree and rebalances the tree if need be
    //@pre: newItem has been assigned
    //@post: newItem is in the tree and the tree is balanced according to AVL rules
    //@usage: bst.insert(item);
	void insert(const ItemType& newItem);

	void printTest()const;
};



#define AVLTREE_H
#endif