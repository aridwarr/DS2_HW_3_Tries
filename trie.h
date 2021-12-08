#pragma once
#include<string>

class Trie 
{
protected:
    class TrieNode
    {
    public:
        TrieNode* children[26] = { 0 };
        TrieNode* father;
        bool isEndWord = false;
        //int countChildren = 0;
    public:
        TrieNode();
    };
        TrieNode* root;
  public:
        Trie() {}//ctor - initialize root to be "root"

        //all functions
        void insertWord(string str);
        bool deleteWord(string str);
        bool searchWord(string str);
        int printAutoSuggestions(string str);
    private:
      //  bool searchWord(string str, TrieNode* node);

   
    };