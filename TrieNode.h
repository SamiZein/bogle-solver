#ifndef TRIENODE_H
#define TRIENODE_H

using namespace std;
class TrieNode{
private:
  char letter;
  vector<TrieNode*> children;
public:
  TrieNode(char val){
    this->letter = val;
  }
  char getChar(){
    return this->letter;
  }
  TrieNode* hasChild(char let){
    for(int i=0; i < this->children.size(); i++){
       if(this->children[i]->letter == let)
         return this->children[i];
    }
    return nullptr;
  }
  void insertChild(char let){
    this->children.push_back(new TrieNode(let));
  }

};


#endif // TRIENODE_H