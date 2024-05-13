#include <iostream>
#include <string>
#include <vector> 
#include <sstream>
#include <fstream>
#include <set>
#include <sstream>
#include <cstring>
#include "Trie.h"

using namespace std;

int boggleSolver(int theArray[4][4]);

void move(int x,int y,int up,int side,string str);
 
int visited[4][4];
char board[4][4];

set<string> solution;
Trie trie;

int counter = 0;

      
int main(){
  fstream wordsFile;
  wordsFile.open("words.txt",ios::in);
  if (wordsFile.is_open()){   //checking whether the file is open
      string word;
      while(getline(wordsFile, word)){ //read data from file object and put it into string.
         trie.insert(word);
      }
      wordsFile.close(); //close the file object.
   }

  //Ask user for filename
  std::string fileName;
  std::cout << "Please enter a filename containing a Boggle board: ";
  std::cin >> fileName;
  //Open the file
  std::ifstream inFile(fileName.c_str());
  //Read the file into the array
  std::string line; //hold the line from the string
  
  int row = 0; //current row
  int col = 0; //current col
  
  if(inFile.is_open()){
    while(getline(inFile,line)){ //get the line
      std::stringstream myStream(line); //make a stream from the string
      std:: string value;
      while(getline(myStream, value, ' ')){ //read the stream with ' ' delimiter
        board[row][col] = value[0];
        col++;
      }
      row++; //increment row
      col = 0; //reset column
    }
  }
  //printing the array just to make sure it worked
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      std::cout << board[i][j] << " ";
    }
    std::cout << std::endl;
  }

  ofstream solfile ("solution.txt");
  if (solfile.is_open())
  {
    string str = "";
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
        move(j,i,0,0,str);
      }
    }

    for (auto itr : solution)
    { 
      if(itr.length()>2)
        counter++;
      solfile << itr << "\n";
    }
    solfile << counter << "\n";
    solfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}

void move(int x,int y,int up,int side,string str){
  
  if(x+side>3||x+side<0||y+up>3||y+up<0)
    return;
  if(visited[x+side][y+up] == 1)
    return;
  if(!trie.searchPrefix(str+board[x+side][y+up]))
    return;
  if(trie.search(str+board[x+side][y+up]))
    solution.insert(str+board[x+side][y+up]);
  visited[x+side][y+up] = 1;
  move(x+side,y+up,1,0,str+board[x+side][y+up]);
  move(x+side,y+up,1,1,str+board[x+side][y+up]);
  move(x+side,y+up,0,1,str+board[x+side][y+up]);
  move(x+side,y+up,-1,1,str+board[x+side][y+up]);
  move(x+side,y+up,-1,0,str+board[x+side][y+up]);
  move(x+side,y+up,-1,-1,str+board[x+side][y+up]);
  move(x+side,y+up,0,-1,str+board[x+side][y+up]);
  move(x+side,y+up,1,-1,str+board[x+side][y+up]);
  visited[x+side][y+up] = 0;
  return;
}