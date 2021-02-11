/**
 * Title : Binary Search Trees
 * Author : Alkým Önen
 * Description : Binary Search Tree Node header file
 */

#ifndef _BSTNode
#define _BSTNode

class BSTNode {
public :
    BSTNode();
    BSTNode( const int &anItem);
    BSTNode( const int &anItem, BSTNode *leftPtr, BSTNode *rightPtr);

private:
    int item; // Data portion
    BSTNode *leftChildPtr; // Pointer to left child
    BSTNode *rightChildPtr; // Pointer to right child

    friend class BST;
}; // end BSTNode
#endif
