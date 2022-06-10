// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Tree;
  std::ifstream ser(filename);
  if (!ser.is_open()) {
      std::cout << "File not open!" << std::endl;
      return Tree;
  }
  char stchka;
  std::string word_srt = "";
  while (!ser.eof()) {
      stchka = ser.get();
      if (stchka <= 'Z' && str >= 'A') {
          stchka = stchka + ('a' - 'A');
      }
      if (stchka <= 'z' && stchka >= 'a') {
           word_srt += stchka;
      } else {
          Tree.add( word_srt);
           word_srt = "";
      }
  }
  ser.close();
  return Tree;
}
