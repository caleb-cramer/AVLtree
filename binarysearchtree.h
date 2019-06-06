/* @file binarysearchtree.h 
   @name caleb cramer
   @date 12 April 2019 */


/*For ADT Binary Search Tree. Is a child of Binary Tree. Extends capabilities of the binary tree.
Is a binary tree that has added functions to search and insert.

Operations: allows for searching and inserting of the binary tree
Contract: is a friend of the node class and inheirits all of the public and protected members of binary tree
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binarytree.h"
#include "node.h"

class BinarySearchTree: public BinaryTree
{
public:
   //@creates a new binary search tree
   //@post: an empty binary search tree object exists
   //@usage: BinarySearchTree bst;
   BinarySearchTree();

   //@releases memory for a binary search tree
   //@pre: binary search tree object exists
   //@post: binary search tree object does not exist
   //@usage: automatically done at end of scope
   ~BinarySearchTree();

   // *****************************************************************
   // *  pre for all member functions: binary search tree object exists
   // *****************************************************************

   //@searches for a key in a binary search tree object and
   //    retrieves the corresponding item
   //@pre: key has been assigned.
   //@post: theItem contains tkey with rest of the item if
   //    tkey is found in the binary search tree object
   //    else an exception is thrown
   //@usage: bst.search (abbrev, meaning);
   bool search (const ItemType& theItem) const;

   //@inserts a new item into the binary search tree
   //@pre: newItem has been assigned
   //@post: if the newItem's key is not already in the tree
   //       and there is memory available
   //         then the newItem is added to the tree
   //       else an exception is thrown
   //@usage: bst.insert(item);
   void insert (const ItemType& newItem);

   //public function that calls removeItem
   //very similar to insert but for remove
   void remove (const ItemType& theItem);

   //calls and returns lookforMin(mroot)
   Node * FindMin() const;

   //calls and returns lookforMax(mroot)
   Node * FindMax() const;

protected:  // recursive helper functions
   //@recursively searches (modeling on binary search) for a key
   //@pre: treeptr is assigned. newItem is assigned.
   //@post: searches for tkey in the tree with treeptr's root.
   //    If tkey is found, theItem is the key together with the other
   //    parts of the item. Else an exception is thrown.
   //@usage: lookup(mroot, key);
   bool lookup (Node * treeptr, const ItemType& theItem) const;

    //@recursively searches for the correct place and then inserts the item
   //@pre: treeptr is assigned. newItem is assigned.
   //@post: searches for tkey in the tree with treeptr's root.
   //    If tkey is found, theItem is the key together with the other
   //    parts of the item. Else an exception is thrown.
   //@usage: insertItem(mroot, key);
   void insertItem (Node *& treeptr, const ItemType& newItem);

   //@recursively searches for the correct place and then removes the item. 3 cases: no child, one child or 2 children
   //@pre: treeptr is assigned. newItem is assigned.
   //@post: searches for tkey in the tree with treeptr's root.
   //    If tkey is found, theItem is the key together with the other
   //    parts of the item. Else an exception is thrown.
   //@usage: removeItem(mroot, key);
   void removeItem (Node *& treeptr, const ItemType& theItem);
   
   //@iterate uses a while loop to find the smallest element in the tree
   //@pre: treeptr is assigned. newItem is assigned.
   //@return: the smallest node
   //@usage: lookforMin(treeptr)
   Node * lookforMin(Node * treeptr) const;

   //@iterate uses a while loop to find the smallest element in the tree
      //then use that to find its parent
   //@pre: treeptr is assigned. newItem is assigned.
   //@return: the parent of the smallest node
   //@usage: lookforMin_he lp(treeptr)
   Node * lookforMin_help(Node * treeptr) const;

   //@iterate uses a while loop to find the largest element in the tree
   //@pre: treeptr is assigned. newItem is assigned.
   //@return: the largest node
   //@usage: lookforMax(treeptr)
   Node * lookforMax(Node * treeptr) const;      

};
#endif