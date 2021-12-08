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
        char val;
        bool isEndWord = false;
        //int countChildren = 0;
    public:
        TrieNode(){}
        TrieNode(char c) : val(c) {};
    };
        //TrieNode* root = new TrieNode();
  public:
      TrieNode* root;
      Trie() { root = new TrieNode(); }//ctor - initialize root to be "root"

        //all functions
        void insertWord(string str);
        bool deleteWord(string str);
        bool searchWord(string str);
        int printAutoSuggestions(string str);
    private:
        int printAutoSuggestions(string str, TrieNode* node);
      //  bool searchWord(string str, TrieNode* node);

   
    };