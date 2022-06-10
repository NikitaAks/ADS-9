// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BSTH
#define INCLUDE_BSTH
#pragma once
#pragma once
template<typename T>
class BST {
 private:
  struct Node {
  T value;
  int chetchik = 0;
  Node* levo = nullptr;
  Node* pravo = nullptr;;
  };
  Node* root;
  Node* addNode(Node* root, const T& val) {
    if (root == nullptr) {
      root = new Node;
      root->value = val;
      root->chetchik = 1;
      root->levo = root->pravo = nullptr;
    } else if (root->value < val) {
        root->levo = addNode(root->levo, val);
      } else if (root->value > val) {
          root->pravo = addNode(root->pravo, val);
        } else {
            root->chetchik++;
          }
    return root;
    }
    int searchNode(Node* root, const T& val) {
      if (root == nullptr) {
        return 0;
      } else if (root->value == val) {
          return root->;
        } else if (root->value < val) {
            return searchNode(root->levo, val);
          } else {
              return searchNode(root->pravo, val);
            }
    }
    int depth_p(Node* root) {
      int Levo = 0, Pravo = 0;
      if (root == nullptr) {
        return 0;
      } else {
          Levo = depth_p(root->levo);
          Pravo = depth_p(root->pravo);
        }
        if (Pravo > Levo) {
            return ++Pravo;
        } else {
            return ++Levo;
          }
    }
 public:
  BST() :root(nullptr) {}
  void Add(const T& val) {
    root = addNode(root, val);
  }
  int search(const T& val) {
    return searchNode(root, val);
  }
  int depth() {
    return depth_p(root) - 1;
  }
};
#endif  // INCLUDE_BSTH
