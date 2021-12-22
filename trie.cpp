#include"trie.h"
#include <iostream>

void Trie::insertWord(string str)
{

	TrieNode* pos = root;
	for (int i = 0; i < str.size(); i++)
	{
		//move pos to appropriate index in children array - calculated by (current letter - a)
		int index = str[i] - 'a';
		//if element is null - add TrieNode with appropriate letter to children array
		if (!pos->children[index])
		{
			pos->children[index] = new TrieNode(str[i]);
			pos->children[index]->father = pos;
			pos->countChildren++;
		}
		pos = pos->children[index];
		
	}
	/*I was unsure what was wanted when word is already present
	* if(pos->isEndWord)
	* {
	*	  word is present, do whatever
	*     return;
	* }
	* (also possible to use search at beginning of method)
	*/
	pos->isEndWord = true;
}

bool Trie::searchWord(string str)
{
	TrieNode* pos = root;
	for (int i = 0; i < str.size(); i++)
	{
		//move pos to appropriate index in children array - calculated by (current letter - a)
		pos = pos->children[str[i] - 'a'];
		//if element is null return false
		if (!pos)
		{
			return false;
		}
	}
	if (pos->isEndWord)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Trie::printAutoSuggestions(string str)
{

	TrieNode* pos = root;
	searchWord(str, pos); //check for prefix in trie, if present, update pos to final node in word.
	if (pos == root)  //if not (so pos wasn't updated - stayed equal to root) return 0 
	{
		return 0;
	}
	printAutoSuggestions(str, pos);
	cout << endl;
	return 1;
}

void Trie::printAutoSuggestions(string str, TrieNode* node)
{
	if (node->isEndWord)
	{
		cout << str << " ";
	}
	if (node->countChildren == 0)
	{
		return;
	}
	for (int i = 0; i < 26; i++)
	{ 
		if (node->children[i])
		{
			printAutoSuggestions(str + node->children[i]->nodeValue, node->children[i]);
		}
	}
}

bool Trie::searchWord(string str, TrieNode*& node)
{
	TrieNode* pos = root;
	for (int i = 0; i < str.size(); i++)
	{
		//move pos to appropriate index in children array - calculated by (current letter - a)
		pos = pos->children[str[i] - 'a'];
		//if element is null return false
		if (!pos)
		{
			return false;
		}
	}
	node = pos;
	if (pos->isEndWord)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Trie::deleteWord(std::string str) {
	TrieNode* pos = root;
	if (!searchWord(str, pos)) //check for word in trie, if present, update pos to final node in word
	{
		return false;
	}
	
	pos->isEndWord = false;
	int indx = pos->nodeValue;//track index of current pos
	//while pos isn't part of another word - isn't a wordend and has no children - delete it and move up
	while(pos->countChildren == 0 && !pos->isEndWord && pos != root)
	{
		//update pos
		pos = pos->father;
		//delete the previous pos
		//delete[] pos->children[indx]->children;
		pos->children[indx] = NULL;
		pos->countChildren--;
		//update index to current pos
		indx = pos->nodeValue;		
	}
	return true;
 
}