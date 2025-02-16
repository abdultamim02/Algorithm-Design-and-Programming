#include <iostream>
#pragma once

using namespace std;

class BinaryTreeNode{
    public:
        int data;                   // Data to Store in the Node
        BinaryTreeNode* left;       // Pointer to the left child
        BinaryTreeNode* right;      // Pointer to the right child

        // Constructor for initialization
        BinaryTreeNode(int initialData, BinaryTreeNode* leftNode = nullptr, BinaryTreeNode* rightNode = nullptr){
            data = initialData;
            left = leftNode;
            right = rightNode;
        }
};

class MyBinaryTreeType{
    private:
        BinaryTreeNode* root;       // Root of the Binary Tree
        int* array;                 // Array pointer

        // in_order_traversal_helper method that returns a list of values in in-order (left, root, right)
        void in_order_traversal_helper(BinaryTreeNode* node, int*& array, int& index){
            if (node){
                in_order_traversal_helper(node->left, array, index);
                array[index++] = node->data;
                in_order_traversal_helper(node->right, array, index);
            }
        }

        // pre_order_traversal_helper method that returns a list of values in pre-order (root, left, right)
        void pre_order_traversal_helper(BinaryTreeNode* node, int*& array, int& index){
            if (node){
                array[index++] = node->data;
                pre_order_traversal_helper(node->left, array, index);
                pre_order_traversal_helper(node->right, array, index);
            }
        }

        // pre_order_traversal_helper method that returns a list of values in post-order (left, right, root)
        void post_order_traversal_helper(BinaryTreeNode* node, int*& array, int& index){
            if (node){
                post_order_traversal_helper(node->left, array, index);
                post_order_traversal_helper(node->right, array, index);
                array[index++] = node->data;
            }
        }

    public:
        // Constructor for initialization
        MyBinaryTreeType(){
            root = nullptr;
        }

        // insert method to insert a value into the binary tree
        void insert(int value){
            BinaryTreeNode* newNode = new BinaryTreeNode(value, nullptr, nullptr);
            if (!root){
                root = newNode;
                return;
            }

            BinaryTreeNode* current = root;
            BinaryTreeNode* parent = nullptr;

            // Find the correct position to insert the value
            while (current){
                parent = current;
                if (value < current->data){
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }

            // Insert the node either on the left or right
            if (value < parent->data){
                parent->left = newNode;
            }
            else {
                parent->right = newNode;
            }
        }

        // find method to search for a value in the binary tree and returns True if found, otherwise False
        bool find(int value){
            BinaryTreeNode* current = root;
            while (current){
                if (current->data == value){
                    return true;
                }
                else if (value < current->data){
                    current = current->left;
                }
                else{
                    current = current->right;
                }
            }
            return false;
        }

        // nodeCount method to count the number of nodes in the binary tree
        int nodeCount(BinaryTreeNode* node){
            if (!node){
                return 0;
            }
            return nodeCount(node->left) + nodeCount(node->right) + 1;
        }

        // in_order_traversal method to return a list of values in in-order (left, root, right)
        int* in_order_traversal(int& size){
            int index = 0;
            int* array = new int[size];
            in_order_traversal_helper(root, array, index);
            return array;
        }

        // pre_order_traversal method to returns a list of values in pre-order (root, left, right)
        int* pre_order_traversal(int& size){
            int index = 0;
            int* array = new int[size];
            pre_order_traversal_helper(root, array, index);
            return array;
        }

        // post_order_traversal to return a list of values in post-order (left, right, root)
        int* post_order_traversal(int& size){
            int index = 0;
            int* array = new int[size];
            post_order_traversal_helper(root, array, index);
            return array;
        }

        // PrintBinaryTree to print the binary tree in different traversal orders
        void PrintBinaryTree(){
            int size = nodeCount(root);

            // Print In-Order Traversal
            cout << "In-Order Traversal: [";
            int* inOrderArray = in_order_traversal(size);
            for (int i = 0; i < size; i++){
                cout << inOrderArray[i];
                if (i < size - 1) {
                    cout << ", ";
                }
            }
            delete[] inOrderArray;
            cout << "]" << endl;

            // Print Pre-Order Traversal
            cout << "Pre-Order Traversal: [";
            int* preOrderArray = pre_order_traversal(size);
            for (int i = 0; i < size; i++){
                cout << preOrderArray[i];
                if (i < size - 1) {
                    cout << ", ";
                }
            }
            delete[] preOrderArray;
            cout << "]" << endl;

            // Print Post-Order Traversal
            cout << "Post-Order Traversal: [";
            int* postOrderArray = post_order_traversal(size);
            for (int i = 0; i < size; i++){
                cout << postOrderArray[i];
                if (i < size - 1) {
                    cout << ", ";
                }
            }
            delete[] postOrderArray;
            cout << "]" << endl;
        }
};