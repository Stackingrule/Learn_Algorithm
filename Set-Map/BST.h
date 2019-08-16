#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H

#include <iostream>
#include <stack>
#include <queue>

template<class T>
class BSTNode {
public:
	T e;
	BSTNode<T> *left, *right;

	BSTNode(T e) {
		this->e = e;
		left = nullptr;
		right = nullptr;
	}

};

template<class T>
class BST {
private:
	BSTNode<T>* root;
	int _size;

	BSTNode<T>* insert(BSTNode<T>* node, T e) {
		if(node == nullptr) {
			_size++;
			return new BSTNode<T>(e);
		}
		if(node->e > e) {
			insert(node->left, e);
		} else if(node->e < e) {
			insert(node->right, e);
		}

		return node;
	}

	BSTNode<T>* contain(BSTNode<T>* node,T e) {
		if(node == nullptr) 
			return false;

		if(node->e == e) 
			return true;
		else if(node->e < e)
			return contain(node->left, e);
		else
			return contain(node->right, e);
	}

	void preOrder(BSTNode<T>* node) {
		if(node == nullptr) {
			return;
		}

		std::cout << node->e << " ";
		preOrder(node->left);
		preOrder(node->right);
	}

	void inOrder(BSTNode<T>* node) {
		if(node == nullptr) {
			return;
		}
		inOrder(node->left);
		std::cout << std::endl;
		inOrder(node->right);
	}

	void postOrder(BSTNode<T>* node) {
		if(node == nullptr) {
			return;
		}
		postOrder(node->left);
		postOrder(node->right);
		std::cout << std::endl;
	}

	BSTNode<T>* findMin(BSTNode<T>* node) {
		if(node->left == nullptr) {
			return node;
		}
		return findMin(node->left);
	}

	BSTNode<T>* findMax(BSTNode<T>* node) {
		if(node->right == nullptr) {
			return node;
		}
		return findMax(node->right);
	}

	BSTNode<T>* removeMin(BSTNode<T>* node) {
		if(node->left == nullptr) {
			BSTNode<T>* rightNode = node->right;
			delete node;
			_size--;
			return rightNode;
		}

		node->left = removeMin(node->left);
		return node;
	}

	BSTNode<T>* removeMax(BSTNode<T>* node) {
		if(node->right == nullptr) {
			BSTNode<T>* leftNode = node->left;
			delete node;
			_size--;
			return leftNode;
		}

		node->right = removeMax(node->rightNode);
		return node;
	}

	BSTNode<T>* remove(BSTNode<T>* node, T e) {
		if(node == nullptr) {
			return nullptr;
		}
		if(node->e > e) {
			node->left = remove(node->left, e);
			return node;
		}
		else if(node->right < e) {
			node->right = remove(node->right, e);
			return node;
		}
		else {
			if(node->left == nullptr) {
				BSTNode<T>* rightNode = node->right;
				node->right = nullptr;
				_size--;
				return rightNode;
			}
			if(node->right == nullptr) {
				BSTNode<T>* leftNode = node->right;
				node->left = nullptr;
				_size--;
				return leftNode;
			}

			BSTNode<T>* successor = new BSTNode<T>(findMin(node->right)->e);
			_size++;

			successor->right = removeMin(node->right);
			successor->left = node->left;

			node->left = node->right = nullptr;
			delete node;
			_size--;

			return successor;
		}
	}

	void destroy(BSTNode<T>* node) {
		if(node != nullptr) {
			destroy(node->left);
			destroy(node->right);
			delete node;
			_size--;
		}
	}


public:
	class Empty {};

	BST() {
		root = nullptr;
		_size = 0;
	}

	~BST() {
		destroy(root);
	}

	int size() {
		return _size;
	}

	bool empty() {
		return _size == 0;
	}

	void insert(T e) {
		if(root == nullptr) {
			root = new BSTNode<T>(e);
			_size++;
		}
		else {
			insert(root, e);
		}
	}

	bool contain(T e) {
		return contain(root, e);
	}

	void preOrder() {
		preOrder(root);
        std::cout << std::endl;
	}

	void inOrder() {
		inOrder(root);
		std::cout << std::endl;
	}

	void postOrder() {
		postOrder(root);
		std::cout << std::endl;
	}

	void levelOrder() {
		std::queue<BSTNode<T>*> *q = new std::queue<BSTNode<T>*>();
		q->push(root);
		while(q->empty()) {
			BSTNode<T>* node = q->front();
			q->pop();
			std::cout << node->e << " ";
			if(node->left != nullptr) {
				q->push(node->left);
			}
			if(node->right != nullptr) {
				q->push(node->right);
			}
		}
		std::cout << std::endl;
	}

	T findMin() {
		if(_size == 0)
			throw Empty();

		return findMin(root)->e;
	}

	T findMax() {
		if(_size == 0) {
			throw Empty();
		}

		return findMax(root)->e;
	}

	T removeMin() {
		T ret = findMin();
		root = removeMin(root);
		return ret;
	}

	T removeMax() {
		T ret = findMax();
		root = removeMax(root);
		return ret;
	}

	void remove(T e) {
		root = remove(root, e);
	}

};

#endif  //BINARYSEARCHTREE_BST_H
