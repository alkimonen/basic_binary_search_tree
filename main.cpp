/**
 * Title : Binary Search Trees
 * Author : Alkým Önen
 * Description : Main test program
 */

#include <iostream>
using namespace std;
#include "BSTNode.h"
#include "BST.h"

int main(){

    int *treeArray;
    int treeLength;
    bool contains;
    BST binarySearchTree(5);

    binarySearchTree.insertItem(12);
    binarySearchTree.insertItem(7);
    binarySearchTree.insertItem(1);
    binarySearchTree.insertItem(6);
    binarySearchTree.insertItem(3);
    binarySearchTree.insertItem(13);
    binarySearchTree.insertItem(2);
    binarySearchTree.insertItem(10);
    binarySearchTree.insertItem(11);
    binarySearchTree.displayTree();

    binarySearchTree.deleteItem(2);
    binarySearchTree.deleteItem(7);
    binarySearchTree.deleteItem(5);
    binarySearchTree.deleteItem(6);
    binarySearchTree.deleteItem(11);
    binarySearchTree.displayTree();

    treeArray = binarySearchTree.inorderTraversal( treeLength);

    for ( int i = 0; i < treeLength; i++ )
        cout << treeArray[i] << " ";
    cout << endl;
    delete [] treeArray;


    treeArray = new int[3];
    treeLength = 3;
    treeArray[0] = 3;
    treeArray[1] = 10;
    treeArray[2] = 12;
    cout << "Key values of traversed nodes: ";
    contains = binarySearchTree.containsSequence( treeArray, treeLength);
    cout << "Contains [3,10,12]: " << contains << endl;

    treeArray = new int[3];
    treeLength = 3;
    treeArray[0] = 3;
    treeArray[1] = 11;
    treeArray[2] = 12;
    cout << "Key values of traversed nodes: ";
    contains = binarySearchTree.containsSequence( treeArray, treeLength);
    cout << "Contains [3,11,12]: " << contains << endl;

    treeArray = new int[3];
    treeLength = 3;
    treeArray[0] = 2;
    treeArray[1] = 10;
    treeArray[2] = 12;
    cout << "Key values of traversed nodes: ";
    contains = binarySearchTree.containsSequence( treeArray, treeLength);
    cout << "Contains [2,10,12]: " << contains << endl;

    cout << "Nodes under level 1: " << binarySearchTree.countNodesDeeperThan( 1) << endl;
    cout << "Nodes under level 2: " << binarySearchTree.countNodesDeeperThan( 2) << endl;
    cout << "Nodes under level 3: " << binarySearchTree.countNodesDeeperThan( 3) << endl;
    cout << "Nodes under level 4: " << binarySearchTree.countNodesDeeperThan( 4) << endl;

    cout << "Max balanced height: " << binarySearchTree.maxBalancedHeight() << endl;


    BST secondBinarySearchTree( 8);     // Tree at figure 1
    secondBinarySearchTree.insertItem( 4);
    secondBinarySearchTree.insertItem( 6);
    secondBinarySearchTree.insertItem( 5);
    secondBinarySearchTree.insertItem( 3);
    secondBinarySearchTree.insertItem( 1);
    secondBinarySearchTree.insertItem( 2);
    secondBinarySearchTree.insertItem( 13);
    secondBinarySearchTree.insertItem( 12);
    secondBinarySearchTree.insertItem( 10);
    secondBinarySearchTree.insertItem( 15);
    secondBinarySearchTree.insertItem( 14);

    cout << "Max balanced height: " << secondBinarySearchTree.maxBalancedHeight() << endl;


    delete [] treeArray;
    return 0;
}
