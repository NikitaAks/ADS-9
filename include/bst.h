// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
    BST();
    ~BST();
    void add(T);
    int depth();
    int search(T);
 private:
    struct Node {
        T value;
        int chetchik_num = 0;
        Node* levo;
        Node* pravo;
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
        root->levo = root->pravo = nullptr;
    } else if (root->value > val_zn) {
        root->levo = addNode(root->levo, val_zn);
    } else if (root->value < val_zn) {
        root->pravo = addNode(root->pravo, val_zn);
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
      delTree(root->levo);
      delTree(root->pravo);
      delete root;
  }
}

template<typename T>
int BST<T>::depthTree(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int Pravo, Levo;
        Pravo = depthTree(root->pravo);
        Levo = depthTree(root->levo);
        if (Pravo > Levo) {
            return Pravo + 1;
        } else {
            return Levo + 1;
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
        return searchNode(root->levo, val_zn);
    } else {
        return searchNode(root->pravo, val_zn);
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
