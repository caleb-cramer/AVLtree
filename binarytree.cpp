/* @file binarytree.cpp
   @name caleb cramer
   @date 10 April 2019 */

#include "binarytree.h"

BinaryTree::BinaryTree(){
	mroot=new Node();
}

BinaryTree::BinaryTree(const ItemType &rootItem){
	mroot=new Node(rootItem,NULL,NULL);
}

BinaryTree::BinaryTree(const ItemType &rootItem,BinaryTree &leftTree, BinaryTree &rightTree){
	mroot=new Node(rootItem,leftTree.mroot,rightTree.mroot);
}

BinaryTree::BinaryTree(const BinaryTree &rhstree){
	copyTree(mroot,rhstree.mroot);
}

BinaryTree::~BinaryTree(){
	destroyTree(mroot);
}

bool BinaryTree::IsEmpty() const{
	return mroot==NULL;
}

void BinaryTree::preorderTraverse() const{
	preorder(mroot);
}

void BinaryTree::inorderTraverse() const{
	inorder(mroot);
}

void BinaryTree::postorderTraverse() const{
	postorder(mroot);
}

void BinaryTree::copyTree (Node*& newtreep, Node* oldtreep){
	if (oldtreep==NULL)
	{
		newtreep=NULL;
	}
	else{
		newtreep=new Node(oldtreep->mitem,oldtreep->mleftptr,oldtreep->mrightptr);
		copyTree(newtreep->mleftptr,oldtreep->mleftptr);
		copyTree(newtreep->mrightptr,oldtreep->mrightptr);
	}
}

void BinaryTree::destroyTree (Node*& treep){
	if (treep==NULL){
		return;
	}
	else{
		destroyTree(treep->mleftptr);
		destroyTree(treep->mrightptr);
		delete treep; treep=NULL;
	}
}

void BinaryTree::preorder(Node* treep) const{
	if(treep==NULL){
		return;
	}
	cout<<treep->mitem<<" ";
	preorder(treep->mleftptr);
	preorder(treep->mrightptr);
}

void BinaryTree::preorder_test(Node* treep) const{
	if(treep==NULL){
		return;
	}
	cout<<"Key: "<<treep->mitem<<"   height: "<<treep->height<<endl;
	preorder_test(treep->mleftptr);
	preorder_test(treep->mrightptr);
}

void BinaryTree::inorder(Node* treep) const{
	if(treep==NULL){
		return;
	}
	inorder(treep->mleftptr);
	cout<<treep->mitem<<" ";
	inorder(treep->mrightptr);
}

void BinaryTree::postorder(Node* treep) const{
	if(treep==NULL){
		return;
	}
	postorder(treep->mleftptr);
	postorder(treep->mrightptr);
	cout<<treep->mitem<<" ";
}