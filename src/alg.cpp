// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> Tree;
  std::ifstream fin(filename);
  if (!fin.is_open()) {
      std::cout << "File not open!" << std::endl;
      return Tree;
  }
  char strchka_w;
  std::string slovo = "";
  while (!fin.eof()) {
      strchka_w = fin.get();
      if (strchka_w <= 'Z' && strchka_w >= 'A') {
          strchka_w = strchka_w + ('a' - 'A');
      }
      if (strchka_w <= 'z' && strchka_w >= 'a') {
          slovo += strchka_w;
      } else {
          Tree.add(slovo);
          slovo = "";
      }
  }
  fin.close();
  return Tree;
}
