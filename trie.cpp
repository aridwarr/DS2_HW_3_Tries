#include"trie.h"


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