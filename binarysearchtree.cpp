/* @file binarysearchtree.cpp
   @name caleb cramer
   @date 12 April 2019 */

#include "binarysearchtree.h"
#include<iostream>

using namespace std;

BinarySearchTree::BinarySearchTree(){
	mroot=NULL;
}

BinarySearchTree::~BinarySearchTree(){
	destroyTree(mroot);
}

bool BinarySearchTree::search(const ItemType& theItem) const{
	return lookup(mroot,theItem);
}

void BinarySearchTree::insert(const ItemType& newItem){
	insertItem(mroot,newItem);
}

void BinarySearchTree::remove(const ItemType& newItem){
	removeItem(mroot,newItem);
}

Node *BinarySearchTree::FindMax()const{
	return lookforMax(mroot);
}

Node *BinarySearchTree::FindMin()const{
	return lookforMin(mroot);
}

bool BinarySearchTree::lookup (Node * treeptr, const ItemType& theItem) const{
	if(treeptr->mitem==theItem){
		return true;
	}
	else if(theItem<=treeptr->mitem){
		return lookup(treeptr->mleftptr, theItem);
	}
	else if(theItem>treeptr->mitem){
		return lookup(treeptr->mrightptr, theItem);
	}
	else{
		return false;
	}
}

void BinarySearchTree::insertItem (Node *& treeptr, const ItemType& newItem){
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

}

void BinarySearchTree::removeItem (Node *& treeptr, const ItemType& theItem){
	if (treeptr==NULL)
	{
		return;
	}
	if (theItem<treeptr->mitem)
	{
		removeItem(treeptr->mleftptr,theItem);
	}
	else if(theItem>treeptr->mitem){
		removeItem(treeptr->mrightptr,theItem);
	}
	else 
	{
		if (treeptr->mleftptr!=NULL&&treeptr->mrightptr!=NULL){
			Node *curr=lookforMin(treeptr->mrightptr);
			treeptr->mitem=curr->mitem;
			//cout<<"made it"<<endl;
			removeItem(curr,curr->mitem);
		}
		else if (treeptr->mleftptr==NULL&&treeptr->mrightptr==NULL)
		{
			//cout<<"help";
			delete treeptr;
			treeptr=NULL;
		}
		else{
			//cout<<"help";
			Node *temp=(treeptr->mleftptr)? treeptr->mleftptr: treeptr->mrightptr;
			Node *temp2= treeptr;
			treeptr=temp;
			delete temp2;
		}
	}
		
		
}
Node *BinarySearchTree::lookforMin(Node * treeptr) const{
	Node *temp = treeptr;
	while(temp->mleftptr!=NULL){
		temp=temp->mleftptr;
	}
	return temp;
}

Node *BinarySearchTree::lookforMax(Node * treeptr) const{
	Node *temp = treeptr;
	while(temp->mrightptr!=NULL){
		temp=temp->mrightptr;
	}
	return temp;
}

Node *BinarySearchTree::lookforMin_help(Node * treeptr) const{
	Node *temp= treeptr->mrightptr;
	Node *prev= treeptr->mrightptr;
	while(temp->mleftptr!=NULL){
		temp=temp->mleftptr;
	}
	while(prev->mleftptr!=temp){
		prev=prev->mleftptr;
	}
	return prev;
}

