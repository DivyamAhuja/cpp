#ifndef _MY_BINARY_TREE_
#define _MY_BINARY_TREE_ 1

#include <iostream>

template<typename T> class BinarySearchTree {
private:    
    struct node {
        T data;
        node* left;
        node* right;
    };
    
    node* root;
    
    node* createNode(T data) {
        node* newNode = new node;
        if(!newNode) return nullptr;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    void inOrderHelper(node* root) {
        if (root == nullptr) return;

        inOrderHelper(root->left);
        std::cout << root->data << " ";
        inOrderHelper(root->right);
    }

    void deleteTree(node* root) {
        if (root == nullptr) return;

        deleteTree(root->left);
        deleteTree(root->right);

        delete root;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    bool addNode(T data) {
        node* newNode = createNode(data); 
        if (!newNode) return false;
        node* ptr = root;
        node* temp = root;
        bool left = true;
        while (temp != nullptr) {
            ptr = temp;
            if (data <= temp->data) {
                temp = temp->left;
                left = true;
            } else {
                temp = temp->right;
                left = false;
            }
        }
        if (ptr == nullptr) {
            root = newNode;
        } else {
            if (left)
                ptr->left = newNode;
            else
                ptr->right = newNode;
        }
        return true;
    }

    void inOrder() {
        inOrderHelper(this->root);
        std::cout << '\n';
    }

    ~BinarySearchTree() {
        deleteTree(root);
    }
};

#endif