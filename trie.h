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
        void insertWord(std::string str);
        bool deleteWord(std::string str);
        bool searchWord(std::string str);
        int printAutoSuggestions(std::string str);
    private:
      //  bool searchWord(string str, TrieNode* node);

   
    };