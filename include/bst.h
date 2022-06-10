// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#pragma once

template <typename T>
class BST {
 public:
    void add(T);
    int depth();
    int search(T);
    BST();
    ~BST();
 private:
    struct Node {
        T value;
        int chetchik_num = 0;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* addNode(Node*, T);
    int depthTree(Node*);
    int searchNode(Node*, T);
    void delTree(Node*);
};

template <typename T>
BST<T>::BST(): root(nullptr) {}

template <typename T>
BST<T>::~BST() {
    if (root) {
        delTree(root);
    }
}

template<typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T val_zn) {
    if (root == nullptr) {
        root->value = val_zn;
        root = new Node;
        root->chetchik_num = 1;
        root->left = root->right = nullptr;
    } else if (root->value > val_zn) {
        root->left = addNode(root->left, val_zn);
    } else if (root->value < val_zn) {
        root->right = addNode(root->right, val_zn);
    } else {
        root->chetchik_num += 1;
    }
    return root;
}

template<typename T>
void BST <T>::delTree(Node *root) {
  if (root == nullptr) {
    return;
  } else {
      delTree(root->left);
      delTree(root->right);
      delete root;
  }
}

template<typename T>
int BST<T>::depthTree(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int Right, Left;
        Right = depthTree(root->right);
        Left = depthTree(root->left);
        if (Right > Left) {
            return Right + 1;
        } else {
            return Left + 1;
        }
    }
}

template<typename T>
int BST<T>::searchNode(Node* root, T val_zn) {
    if (root == nullptr) {
        return 0;
    } else if (root->value == val_zn) {
        return root->chetchik_num;
    } else if (root->value > val_zn) {
        return searchNode(root->left, val_zn);
    } else {
        return searchNode(root->right, val_zn);
    }
}

template<typename T>
void BST<T>::add(T val_zn) {
    root = addNode(root, val_zn);
}

template<typename T>
int BST<T>::depth() {
    return depthTree(root) - 1;
}

template<typename T>
int BST<T>::search(T val_zn) {
    return searchNode(root, val_zn);
}

#endif  // INCLUDE_BST_H_
