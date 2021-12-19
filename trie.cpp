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
	return true;
}

int Trie::printAutoSuggestions(string str)
{

	return 0;
}

int Trie::printAutoSuggestions(string str, TrieNode* node)
{
	return 0;
}

bool Trie::searchWord(string str, TrieNode* node)
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
	return true;
}

bool Trie::TrieNode::hasChildren() {
	int childNum = 0;
	for (int i = 0; i < 25; i++) {
		if (children[i] != NULL) {
			childNum++;
		}
	}
	if (childNum > 1) return true;
	else return false;
	
}
bool Trie::TrieNode::hasChild() {
	int childNum = 0;
	for (int i = 0; i < 25; i++) {
		if (children[i] != NULL) {
			childNum++;
		}
	}
	if (childNum > 0) return true;
	else return false;
}

bool Trie::deleteWord(std::string str) {
	
	bool inTrie = searchWord(str); //check for word in trie
	if (inTrie == false) return inTrie;

	int i;
	for (i = 0; i < str.length(); str[i]) { //get to last node
		root = root->children[i];
	}

	while (root->father) {

		if (root->hasChildren()) {
			root->isEndWord = false;
			return root;
		}

		if (root->hasChild()) {
			if (i = (str.length() - 1)) {//checks if last letter of word has children
				root->isEndWord = false;
				return root;
			}

			//deletion
			root->children[i] = nullptr;
			root->isEndWord = false;
			root->nodeValue = NULL;
			root = root->father;
		}
	}

	return inTrie;

 
}