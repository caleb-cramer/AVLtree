/* @file AVLTree.cpp
   @name caleb cramer
   @date 28 April 2019 */

#include "AVLtree.h"
#include<iostream>
#include <algorithm>

using namespace std;

AVLTree::AVLTree(){
	mroot=NULL;
}

AVLTree::AVLTree(const ItemType& newItem){
	mroot= new Node(newItem, NULL, NULL);
	mroot->height=0;
}

AVLTree::~AVLTree(){
	destroyTree(mroot);
}

int AVLTree::height(const Node *curr)  
{  
    if (curr == NULL)  
        return 0;  
    return curr->height;  
}

void AVLTree::insertItem(Node *& treeptr, const ItemType& newItem){
	if (treeptr==NULL)
	{
		treeptr=new Node(newItem,NULL,NULL);
	}
	else if(newItem>treeptr->mitem){
		insertItem(treeptr->mrightptr,newItem);
	}
	else{
		insertItem(treeptr->mleftptr,newItem);
	}



	treeptr->height = 1 + max(height(treeptr->mleftptr),height(treeptr->mrightptr));

	//cout<<checkBalance(treeptr)<<endl;

	if(checkBalance(treeptr)>1 && newItem < (treeptr->mleftptr)->mitem){
		//left taller than right so rotateRight
		treeptr=rotateRight(treeptr);
		//cout<<"catch 1 \n";
	}
	if(checkBalance(treeptr)<-1 && newItem>(treeptr->mrightptr)->mitem){
		//right taller than left so rotateLeft
		treeptr=rotateLeft(treeptr);
		//cout<<"catch 2 \n";
	}
	if ((checkBalance(treeptr)>1 && newItem>(treeptr->mleftptr)->mitem))
	{
		treeptr->mleftptr=rotateLeft(treeptr->mleftptr);
		treeptr=rotateRight(treeptr);
		//cout<<"catch 3 \n";
	}
	if (checkBalance(treeptr)<-1 && newItem<(treeptr->mrightptr)->mitem)
	{
		treeptr->mrightptr=rotateRight(treeptr->mrightptr);
		treeptr=rotateLeft(treeptr);
		//cout<<"catch 4 \n";
	}
	else{
		return;
	}
}

int AVLTree::checkBalance(Node *treeptr){
	if (treeptr==NULL)
	{
		return 0;
	}
	else{

		return height(treeptr->mleftptr)-height(treeptr->mrightptr);
	}
}

Node *AVLTree::rotateLeft(Node *k2){
	Node *k1=k2->mrightptr;
	k2->mrightptr=k1->mleftptr;
	k1->mleftptr=k2;
	k2->height=1+max(height(k2->mleftptr),height(k2->mrightptr));
	k1->height=1+max(height(k1->mleftptr),height(k1->mrightptr));
	return k1;
}
Node *AVLTree::rotateRight(Node *k2){
	Node *k1 = k2->mleftptr;
	k2->mleftptr=k1->mrightptr;
	k1->mrightptr=k2;
	k2->height=1+max(height(k2->mleftptr),height(k2->mrightptr));
	k1->height=1+max(height(k1->mleftptr),height(k1->mrightptr));
	return k1;
}

void AVLTree::insert(const ItemType& newItem){
	insertItem(mroot,newItem);
}

void AVLTree::printTest() const{
	preorder_test(mroot);
}