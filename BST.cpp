/**
 * Title : Binary Search Trees
 * Author : Alkým Önen
 * Description : Binary Search Tree source file
 */

#include <iostream>
using namespace std;
#include "BSTNode.h"
#include "BST.h"

// constructor which creates empty tree
BST::BST()
    : root( NULL)
{

}

// constructor which creates a tree with only root
BST::BST( const int &rootItem)
        :root( new BSTNode( rootItem))
{
    root->leftChildPtr = NULL;
    root->rightChildPtr = NULL;
}

// constructor which creates a tree with given trees
BST::BST( const int &rootItem, BST &leftTree, BST &rightTree)
{
    root = new BSTNode( rootItem, leftTree.root, rightTree.root);
}

// Copy constructor
BST::BST( const BST &tree) {
		copyTree( tree.root, root);
}

// Helper recursive function for copy constructor
void BST::copyTree( BSTNode *treePtr, BSTNode *&newTreePtr) const
{
    if ( treePtr != NULL )
    {		// copy node
        newTreePtr = new BSTNode( treePtr->item, NULL, NULL);
        copyTree( treePtr->leftChildPtr, newTreePtr->leftChildPtr );
        copyTree( treePtr->rightChildPtr, newTreePtr->rightChildPtr );
    }
    else
        newTreePtr = NULL;	// copy empty tree
}

// Destructor
BST::~BST()
{
    destroyTree( root);
}

// Helper recursive function for destructor
void BST::destroyTree( BSTNode *&treePtr)
{
    if ( treePtr != NULL )
    {
        destroyTree( treePtr->leftChildPtr);
        destroyTree( treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}

// Displays the items in tree
void BST::displayTree()
{
    displayInOrder( root);
    cout << endl;
}

// Displays a node's item and moves to child nodes
void BST::displayInOrder( BSTNode *&treePtr)
{
    if ( treePtr != NULL )
    {
        displayInOrder( treePtr->leftChildPtr);
        cout << treePtr->item << " ";
        displayInOrder( treePtr->rightChildPtr);
    }
}

// Inserts item to given tree
void BST::insertItem( BSTNode*&treePtr, const int &key)
{
    // Position of insertion found; insert after leaf
    if ( treePtr == NULL) {
        treePtr = new BSTNode( key, NULL, NULL);
    }
    // Else search for the insertion position
    else if ( key < treePtr->item)
		insertItem( treePtr->leftChildPtr, key);
    else
        insertItem( treePtr->rightChildPtr, key);
}

// Original insert item function
void BST::insertItem( int key )
{
    insertItem( root, key);
}

void BST::deleteItem( int key)
{
    deleteItem ( root, key);
}

// Checks if a node should be deleted or not, if yes deletes it otherwise move to children
void BST::deleteItem( BSTNode *&treePtr, int key)
{
    if ( treePtr != NULL) // Empty tree
    {
		// Position of deletion found
		if ( key == treePtr->item )
			deleteNodeItem( treePtr);

		// Else search for the deletion position
		else if ( key < treePtr->item )
			deleteItem( treePtr->leftChildPtr, key);
		else
			deleteItem( treePtr->rightChildPtr, key);
    }
}

// Deletes given node
void BST::deleteNodeItem( BSTNode *&nodePtr)
{
		BSTNode *delPtr;

		// (1)  Test for a leaf
		if ( (nodePtr->leftChildPtr == NULL) && (nodePtr->rightChildPtr == NULL) )
		     {
			delete nodePtr;
			nodePtr = NULL;
		}

		// (2)  Test for no left child
		else if ( nodePtr->leftChildPtr == NULL )
        {
			delPtr = nodePtr;
			nodePtr = nodePtr->rightChildPtr;
			delPtr->rightChildPtr = NULL;
			delete delPtr;
		}

        // (3)  Test for no right child
		else if ( nodePtr->rightChildPtr == NULL )
        {
			delPtr = nodePtr;
			nodePtr = nodePtr->leftChildPtr;
			delPtr->leftChildPtr = NULL;
			delete delPtr;
		}

		// (4)  There are two children:
		//      Retrieve and delete the inorder successor
		else {
            int replacementItem;
			processLeftmost( nodePtr->rightChildPtr, replacementItem );
			nodePtr->item = replacementItem;
		}
}

// If node to be deleted has two children gets lowest value from right child
void BST::processLeftmost( BSTNode *&nodePtr, int &treeItem)
{
    if ( nodePtr->leftChildPtr == NULL )
    {
        treeItem = nodePtr->item;
        BSTNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL; // defense
        delete delPtr;
    }
    else
        processLeftmost( nodePtr->leftChildPtr, treeItem );
}

// gets the node of given value
BSTNode *BST::retrieveItem( int key)
{
    BSTNode *current;       // indicator
    bool found = false;

    current = root;

    while ( current != NULL && !found )
    {
        if ( current->item == key )     // item found
            found = true;
        else if ( key > current->item )     // item is less than key value
            current = current->rightChildPtr;
        else                                // item is more than key value
            current = current->leftChildPtr;
    }
    return current;
}

// Traverses tree in-orderly then returns sorted array
int *BST::inorderTraversal( int &length)
{
    int index;
    int *sortedArray;

    length = 0;
    getLength( root, length);       // get length of array

    index = 0;
    sortedArray = new int[length];      // create the array
    sortBST( root, sortedArray, index);     // put values to the array

    return sortedArray;
}

// Traverses tree and sorted its values in an dynamic array
void BST::sortBST( BSTNode *&treePtr, int *&sortedArray, int &index)
{
    if ( treePtr!= NULL )
    {
        // traverse in-orderly and put values to array
        sortBST( treePtr->leftChildPtr, sortedArray, index);
        sortedArray[index] = treePtr->item;
        index++;
        sortBST( treePtr->rightChildPtr, sortedArray, index);
    }
}

// Returns the number of nodes in given tree
void BST::getLength( BSTNode *&treePtr, int &length)
{
    if ( treePtr != NULL )
    {
        getLength( treePtr->leftChildPtr, length);      // length of left child
        length++;
        getLength( treePtr->rightChildPtr, length);     // length of right child
    }
}

// If tree contains given sequence returns true, false otherwise
bool BST::containsSequence( int *seq, int length)
{
    bool firstFound = false;       // if first value is found just traverse until new sequence is full
    int index = 0;
    int *treeSeq;

    if ( length > 0 )
    {
        treeSeq = new int[length];      // new sequence
        for ( int i = 0; i < length; i++)
            treeSeq[i] = -1;
        containsSequence( root, firstFound, seq[0], length, treeSeq, index);    // create new sequence
    }
    cout << endl;

    if ( !firstFound )      // if first value is not found return false
        return false;

    for ( index = 0; index < length; index++ )      // compare new sequence and given sequence
    {
        if ( seq[index] != treeSeq[index] )         // if one of the items is different return false
            return false;
    }
    return true;        // else return true
}

// Recursive helper function for containsSequence, in-order traversal
void BST::containsSequence( BSTNode *&treePtr, bool &firstFound, int first, int length, int *&treeSeq, int &index)
{
    if ( treePtr != NULL && index < length )
    {
        cout << treePtr->item << " ";
        if ( firstFound || (first < treePtr->item) )
            containsSequence( treePtr->leftChildPtr, firstFound, first, length, treeSeq, index);

        if ( firstFound || (first == treePtr->item) )
        {
            firstFound = true;

            treeSeq[index] = treePtr->item;
            index++;
        }

        if ( firstFound || (first > treePtr->item) )
            containsSequence( treePtr->rightChildPtr, firstFound, first, length, treeSeq, index);
    }
}

// Returns the number of nodes which is at equal to or more than given level
int BST::countNodesDeeperThan( int level)
{
    int nodeCount = 0;
    int currentLevel = 0;

    countNodesDeeperThan( level, nodeCount, currentLevel, root);
    return nodeCount;
}

// Recursive helper function for countNodesDeeperThan
void BST::countNodesDeeperThan( int level, int &nodeCount, int &currentLevel, BSTNode *&treePtr)
{
    if ( treePtr != NULL )
    {
        currentLevel++;         // node is at this level
        countNodesDeeperThan( level, nodeCount, currentLevel, treePtr->leftChildPtr);   // check left child
        if ( currentLevel >= level )        // if it has equal or higher level increase count
            nodeCount++;
        countNodesDeeperThan( level, nodeCount, currentLevel, treePtr->rightChildPtr);  // check right child
        currentLevel--;         // node goes back to its parent
    }
}

// Returns the balanced height of tree
int BST::maxBalancedHeight()
{
    int height;
    balanceHeight( root, height);
    return height;
}

// Returns the balanced height of given tree
void BST::balanceHeight( BSTNode *&treePtr, int &height)
{
    int leftHeight, rightHeight;
    height = 0;     // in case it is a child pointer of a leaf

    if ( treePtr != NULL )
    {
        balanceHeight( treePtr->leftChildPtr, height);
        leftHeight = height;        // balanced height of left child

        balanceHeight( treePtr->rightChildPtr, height);
        rightHeight = height;       // balanced height of right child

        if ( leftHeight > rightHeight )         // take the shortest one and
            height = rightHeight + 2;           // increase it by two
        else if ( leftHeight < rightHeight )    // one for node itself
            height = leftHeight + 2;            // one for balanced tree rules
        else
            height = rightHeight + 1;       // if they are same just increase one of heights
    }
}
