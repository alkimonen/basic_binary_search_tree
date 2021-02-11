/**
 * Title : Binary Search Trees
 * Author : Alkým Önen
 * Description : Binary Search Tree Node source file
 */

#include <iostream>
#include "BSTNode.h"

BSTNode::BSTNode()
        : item( 0), leftChildPtr(NULL), rightChildPtr(NULL)
{

}

BSTNode::BSTNode( const int &anItem)
        : item( anItem), leftChildPtr(NULL), rightChildPtr(NULL)
{

}

BSTNode::BSTNode( const int &anItem, BSTNode *leftPtr, BSTNode *rightPtr)
        : item( anItem), leftChildPtr( leftPtr), rightChildPtr( rightPtr)
{

}
