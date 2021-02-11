/**
 * Title : Binary Search Trees
 * Description : Binary Search Tree header file
 */

#ifndef _BST
#define _BST

#include "BSTNode.h"

class BST {
public:
    BST();
    BST( const int &rootItem);
    BST( const int &rootItem, BST &leftTree, BST &rightTree);
    BST( const BST &tree);
    void copyTree( BSTNode *treePtr, BSTNode *&newTreePtr) const;
    ~BST();
    void destroyTree( BSTNode *&treePtr);

    void displayTree();
    void displayInOrder( BSTNode *&treePtr);

    void insertItem( int key);
    void insertItem( BSTNode*&treePtr, const int &newItem);

    void deleteItem ( int key);
    void deleteItem( BSTNode *&treePtr, int key);
    void deleteNodeItem( BSTNode *&nodePtr);
    void processLeftmost( BSTNode *&nodePtr, int &treeItem);

    BSTNode *retrieveItem( int key);

    int *inorderTraversal( int& length);
    void sortBST( BSTNode *&treePtr, int *&sortedArray, int &index);
    void getLength( BSTNode *&treePtr, int &length);

    bool containsSequence( int *seq, int length);
    void containsSequence( BSTNode *&treePtr, bool &firstFound, int first, int length, int *&treeSeq, int &index);

    int countNodesDeeperThan( int level);
    void countNodesDeeperThan( int level, int &nodeCount, int &currentLevel, BSTNode *&treeNode);

    int maxBalancedHeight();
    void balanceHeight( BSTNode *&treePtr, int &height);

private :
    BSTNode *root;

}; // end BST
#endif
