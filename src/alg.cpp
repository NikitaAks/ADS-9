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
  char stchka;
  std::string word_s = "";
  while (!fin.eof()) {
      stchka = fin.get();
      if (stchka <= 'Z' && stchka >= 'A') {
          stchka = stchka + ('a' - 'A');
      }
      if (stchka <= 'z' && stchka >= 'a') {
          word_s += stchka;
      } else {
          Tree.add(word_s);
          word_s = "";
      }
  }
  fin.close();
  return Tree;
}
}
