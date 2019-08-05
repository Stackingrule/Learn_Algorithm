#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H

#include <iostream>
#include <cassert>
#include <queue>

using namespace std;

template<typename Key, typename Value>
class BST {
private:
	struct Node {
		Key key;
		Value value;
		Node* left;
		Node* right;

		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = nullptr;
		}

		Node(Node *node) {
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
		}
	};

	Node* root;
	int count;

	Node* insert(Node* node, Key key, Value value) {
		if(node == nullptr) {
			count++;
			return new Node(key, value);
		}
		if(key == node->key) 
			node->value = value;
		else if(key < node->key)
			node->left = insert(node->left, key, value);
		else
			node->right = insert(node->right, key, value);

		return node;
	}

	bool contain(Node* node, Key key) {
		if(key == node->key) 
			return true;
		else if(key < node->key) 
			return contain(node->left, key);
		else
			return contain(node->right, key);
	}

	Value* search(Node* node, Key key) {
		if(node == nullptr) 
			return nullptr;

		if(key == node->key)
			return &(node->value);
		else if(key < node->key)
			return search(node->left, key);
		else
			return search(node->right, key);
	}

	void preOrder(Node* node) {
		if(node != nullptr) {
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	void inOrder(Node* node) {
		if(node != nullptr) {
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}

	void postOrder(Node* node) {
		if(node != nullptr) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;

		}
	}

	void destroy(Node* node) {
		if(node != nullptr) {
			destroy(node->left);
			destroy(node->right);

			delete node;
			count--;
		}
	}

	Node* findMin(Node* node) {
		if(node->left == nullptr)
			return node;
		return findMin(node->left);
	}

	Node* findMax(Node* node) {
		if(node->right == nullptr)
			return node;
		return findMax(node->right);
	}

	Node* removeMin(Node* node) {
		if(node->left == nullptr) {
			Node* rightNode = node->right;
			delete node;
			count--;
			return rightNode;
		}
		node->left = removeMin(node->left);
		return node;
	}

	Node* removeMax(Node* node) {
		if(node->right == nullptr) {
			Node* leftNode = node->left;
			delete node;
			count--;
			return leftNode;
		}

		node->right = removeMax(node->right);
		return node;
	}

	Node* remove(Node* node, Key key) {
		if(node == nullptr) return nullptr;
		if(key < node->key) {
			node->left = remove(node->left, key);
			return node;
		}
		else if(key > node->key) {
			node->right = remove(node->right, key);
			return node;
		}
		else {
			if(node->left == nullptr) {
				Node* rightNode = node->right;
				delete node;
				count--;
				return rightNode;
			}
			if(node->right == nullptr) {
				Node* leftNode = node->left;
				delete node;
				count--;
				return leftNode;
			}

			Node* delNode = node;
			Node* successor = new Node(findMin(node->right));
			count++;
			successor->right = removeMin(node->right);
			successor->left = node->left;

			delete delNode;
			count--;

			return successor;
		}
	}

	

public:
	BST() {
		root = nullptr;
		count = 0;
	}

	~BST() {
		destroy(root);
	}

	int size() {
		return count;
	}

	bool empty() {
		return count == 0;
	}

	void insert(Key key, Value value) {
		insert(root, key, value);
	}

	bool contain(Key key) {
		return contain(root, key);
	}

	Value* search(Key key) {
		return search(root, key);
	}

	void preOrder() {
		preOrder(root);
	}

	void inOrder() {
		preOrder(root);
	}

	void postOrder() {
		postOrder(root);
	}

	void levelOrder() {
		queue<Node*> Q;
		Q.push(root);
		while(!Q.empty()) {
			Node* node = Q.front();
			Q.pop();

			cout << node->key << endl;

			if(node->left)
				Q.push(node->left);
			if(node->right)
				Q.push(node->right);
		}
	}

	Key findMin() {
		assert(count != 0);
		Node* minNode = findMin(root);
	}

	Key findMax() {
		assert(count != 0);
		Node* maxNode = findMax(root);
	}

	void removeMin() {
		if(root)
			root = removeMin(root);
	}

	void removeMax() {
		if(root)
			root = removeMax(root);
	}

	void remove(Key key) {
		remove(root, key);
	}

};

#endif  //BINARYSEARCHTREE_BST_H
