/* 	Francisco Banda (Z1912220)
    BinaryTree
    CSCI 340-3
    I certify that this is my own work and where appropriate an extension
    of the starter code provided for the assignment.
*/

#ifndef H_BTREE
#define H_BTREE

#include "node.h"
#include <stdlib.h>

template <typename T> class BinaryTree{

public:

	// Default Constructor
    BinaryTree(){}
	
	// Return size of tree
    unsigned     getSize() const {

        return size;

    }
	
	// Return height of tree
    unsigned     getHeight() const {

        return _getHeight(root);

    }
	
	//Insert node into tree
    virtual void Insert(const T& data) {
    
        size++;
        _Insert(root, data);
    
    }
	
	// inorder traversal of tree
    void         Inorder(void (*func)(const T&)) {

        _Inorder(root, func);

    }

protected:
	//Root of tree
    Node<T> *root;

private:
    unsigned _getHeight(Node<T>* node) const {

        if (node == nullptr)
            return 0;
        else
        {
            //Calculate height of tree sides
            int lHeight = _getHeight(node->left);
            int rHeight = _getHeight(node->right);

            //Utilize larger value
            if (lHeight > rHeight)
                return(lHeight + 1);
            else return(rHeight + 1);
        }

    }
	
	//Implement insert routine
    void     _Insert(Node<T>* node, const T& data) {

        if (root == nullptr) {
            Node<T>* newNode = new Node<T>;
            newNode->data = data;
            root = newNode;
            return;
        } else {
        

           SIDE side = rnd();

           if (side == SIDE::left_side) {

               if (node->left == nullptr) {
                   node->left = new Node<T>(data, nullptr, nullptr);
               }
               else {
                   _Insert(node->left, data);
               }
           }
           else {

               if (node->right == nullptr) {
                   node->right = new Node<T>(data, nullptr, nullptr);
               }
               else {
                   _Insert(node->right, data);
               }
           }

        }

    }
	
	//Implement Inorder routine
    void     _Inorder(Node<T>* node, void (*func)(const T&)) {

        if (node == NULL)
            return;

        //Recursion or left subtree
        _Inorder(node->left, func);

        //Print current data
        func(node->data);

        //Recursion or right subtree
        _Inorder(node->right, func);

    }

	//Given random function
    typedef enum { left_side, right_side } SIDE;

    SIDE rnd() {
        return rand() % 2 ? right_side : left_side;
    }

    unsigned size = 0;

};

#endif // End of H_BTREE
