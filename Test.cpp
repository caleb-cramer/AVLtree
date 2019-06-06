/* @file Test.cpp
   @name caleb cramer
   @date 29 April 2019 */

#include "node.h"
#include "binarytree.h"
#include "binarysearchtree.h"
#include "AVLtree.h"

#include <iostream>
using namespace std;

int main()
{
	//cout<<boolalpha;
	ItemType q1=50;
	ItemType q2=10;
	ItemType q3=32;
	ItemType q4=49;
	ItemType q5=51;
	ItemType q6=62;
	ItemType q7=11;
	ItemType q8=20;
	ItemType q9=25;
	ItemType q10=29;

/* Testing for Binary Tree */
	/*BinaryTree *bt1= new BinaryTree(q1);
	BinaryTree *bt2= new BinaryTree(q2);
	BinaryTree *bt4= new BinaryTree(q4);
	BinaryTree *bt5= new BinaryTree(q5);
	BinaryTree *bt3= new BinaryTree(q3,*bt1,*bt2);
	BinaryTree *bt6= new BinaryTree(q6,*bt3,*bt4);
	BinaryTree *bt7= new BinaryTree(q7,*bt5,*bt6);
	BinaryTree *bt8= new BinaryTree(*bt7);
	cout<<bt7->IsEmpty()<<endl;
	cout<<bt8->IsEmpty()<<endl;
	cout<<"preorder ";bt7->preorderTraverse(); cout<<"\n";
	cout<<"inorder ";bt7->inorderTraverse(); cout<<"\n";
	cout<<"postorder ";bt7->postorderTraverse(); cout<<"\n";*/

/*Testing for Binary Search Tree*/
	/*BinarySearchTree *bst= new BinarySearchTree();
	cout<<"Is the tree empty? "<<bst->IsEmpty()<<endl;
	bst->insert(q1);bst->inorderTraverse(); cout<<"\n";
	bst->insert(q4);bst->inorderTraverse(); cout<<"\n";
	bst->insert(q5);bst->inorderTraverse(); cout<<"\n";
	bst->insert(q3);bst->inorderTraverse(); cout<<"\n";
	bst->insert(q2);bst->inorderTraverse(); cout<<"\n";
	bst->insert(q6);bst->inorderTraverse(); cout<<"\n";
	bst->insert(q7);bst->inorderTraverse(); cout<<"\n";
	cout<<"Is the tree empty? "<<bst->IsEmpty()<<endl;
	cout<<bst->search(q4)<<endl;
	cout<<"preorder ";bst->preorderTraverse(); cout<<"\n";
	cout<<"inorder ";bst->inorderTraverse(); cout<<"\n";
	//cout<<"postorder ";bst->postorderTraverse(); cout<<"\n";
	cout<<"Min of tree is "<<(bst->FindMin())->getItem()<<endl;
	cout<<"Max of tree is "<<(bst->FindMax())->getItem()<<endl;

	cout<<"remove a leaf node, specifically 62"<<endl;
	bst->remove(q6);
	cout<<"inorder after removal of 62: ";bst->inorderTraverse(); cout<<"\n";
	cout<<endl;

	cout<<"remove a node with 1 child, specifically 10"<<endl;
	bst->remove(q2);
	cout<<"inorder after removal of 10: ";bst->inorderTraverse(); cout<<"\n";
	cout<<endl;

	cout<<"remove a node with 2 children, specifically 50"<<endl;
	bst->remove(q1);
	cout<<"inorder after removal of 50: ";bst->inorderTraverse(); cout<<"\n";
	cout<<endl;*/

/*Testing for AVL Tree*/

	AVLTree *avl = new AVLTree(q1);

	avl->insert(q8); cout<<"added 20"<<endl;
	avl->insert(q7); cout<<"added 11"<<endl;
	avl->insert(q3); cout<<"added 32"<<endl;
	avl->insert(q9); cout<<"added 25"<<endl;
	avl->insert(q10); cout<<"added 29"<<endl;
	avl->printTest();
	return 0;
}
