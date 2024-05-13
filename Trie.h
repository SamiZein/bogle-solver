#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>

using namespace std;
class Trie {
private:
  TrieNode *root;

public:
  Trie() { root = new TrieNode(' '); }

  TrieNode getRoot(){
    return *root;
  }
  void insert(string word) {
    TrieNode *current = root;
    int leng = word.length();
    int index = 0;
    while (index < leng) {
      if (current->hasChild(word[index]) == nullptr)
        break;
      current = current->hasChild(word[index]);
      index++;
    }
    while (index < leng) {
      current->insertChild(word[index]);
      current = current->hasChild(word[index]);
      index++;
    }
    if (current->hasChild('.'))
      return;
    current->insertChild('.');
  }

  bool search(string word) {
    TrieNode *current = root;
    int leng = word.length();
    for (int i = 0; i < leng; i++) {
      if (current->hasChild(word[i]) == nullptr)
        return false;
      current = current->hasChild(word[i]);
    }

    if (current->hasChild('.') == nullptr)
      return false;
    return true;
  }

  bool searchPrefix(string word) {
    TrieNode *current = root;
    int leng = word.length();
    for (int i = 0; i < leng; i++) {
      if (current->hasChild(word[i]) == nullptr)
        return false;
      current = current->hasChild(word[i]);
    }
    return true;
  }
};

#endif // TRIE_H