#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H

#include <map>
#include <string>

using namespace std;

class Trie {
private:
	class TrieNode {
	public:
		bool isWord;
		map<char, TrieNode> next;

		TrieNode( bool isWord ) { this->isWord = isWord; }
		TrieNode() : isWord(false), next() {}
	};

	TrieNode* root;
	int _size = 0;


public:
	Trie() { root = new TrieNode(); _size = 0; }

	~Trie() { delete root; }

	int size() { return _size; }

	void add(string word) {
		TrieNode* node = root;
		for(int i = 0; (unsigned) i < word.size();  i++) {
			char c = word.at(i);
			if(node->next.find(c) == node->next.end()) {
				node->next.insert(pair<char, TrieNode> (c, TrieNode()));
			}
			node = &node->next.find(c)->second;
		}
		if(!node->isWord) {
			node->isWord = true;
			_size++;
		}
	}

	bool contain(string word) {
		TrieNode* node = root;
		for(int i = 0; (unsigned) i < word.size(); i++) {
			char c = word.at(i);
			if(node->next.find(c) == node->next.end()) {
				return false;
			}
			node = &node->next.find(c)->second;
		}
        return node->isWord;
	}
};

#endif  //TRIE_TRIE_H