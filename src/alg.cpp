// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> MyTree;
  std::ifstream fin(filename);
  char j;
  std::string wd = "";
  if (!fin.is_open()) {
      std::cout << "Error! File can't be open!" << std::endl;
      return MyTree;
  }
  while (!fin.eof()) {
      j = fin.get();
      if (j >= 'A') {
          if (j <= 'Z') {
              j = j + 32;
          }
      }
      if (j >= 'a') {
          if (j <= 'z') {
              wd += j;
          }
      } else {
          MyTree.Add(wd);
          wd = "";
      }
  }
  fin.close();
  return MyTree;
}
