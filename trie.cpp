#include"trie.h"

void Trie::insertWord(string str)
{

	TrieNode* pos = root;

	for (int i = 0; i < str.size(); i++)
	{
		//move pos to appropriate index in children array - calculated by (current letter - a)
		pos = pos->children[str[i] - 'a'];
		//if element is null - add TrieNode with appropriate letter to children array
		if (!pos)
		{
			pos = new TrieNode(str[i]);
		}
		
	}
	pos->isEndWord = true;
}

bool Trie::deleteWord(string str)
{
	return false;
}

bool Trie::searchWord(string str)
{
	return false;
}

int Trie::printAutoSuggestions(string str)
{

	return 0;
}

int Trie::printAutoSuggestions(string str, TrieNode* node)
{
	return 0;
}
