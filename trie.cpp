#include"trie.h"

void Trie::insertWord(string str)
{
	if (!root)
	{
		root = new TrieNode(str.front());
	}
	TrieNode* pos = root;

	for (int i = 1; i < str.size(); i++)
	{
		pos = pos->children[str[i] - 'a'];
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
