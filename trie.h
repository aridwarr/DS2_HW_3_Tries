#pragma once
const int ALPHABET = 26;
class Trie {
protected:
	
	class TrieNode {
	public:
		TrieNode* children[ALPHABET] = { 0 };
		TrieNode* parent;
		bool isEndWord = false;

		TrieNode() {}
	};

	TrieNode* root;
public:
	Trie() {}

	void insertWord(string str);
	void deleteWord(string str);
	bool searchWord(string str);
	void printAllWordsFromPrefix(TrieNode*);
private:
	bool searchWord(string str, TrieNode* node);
};

