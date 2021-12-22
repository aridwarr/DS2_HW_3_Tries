#pragma once
#include<string>
using namespace std;

class Trie 
{
protected:
    class TrieNode
    {
    public:
        TrieNode* children[26] = { 0 };
        TrieNode* father;
        bool isEndWord = false;
        char nodeValue;
        int countChildren = 0;
    public:
        TrieNode(){}
        TrieNode(char c) : nodeValue(c) {};
    };
       
  public:
      TrieNode* root;
      Trie() { root = new TrieNode(0); }//ctor - initialize root to be "root"

        //all functions
        void insertWord(std::string str);
        bool deleteWord(std::string str);
        bool searchWord(std::string str);
        int printAutoSuggestions(std::string str);
        
       
    private:
       void printAutoSuggestions(string str, TrieNode* node);
       bool searchWord(string str, TrieNode*& node);
    };