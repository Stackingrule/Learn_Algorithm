#ifndef AVL_AVLTREE_H
#define AVL_AVLTREE_H

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<typename Key, typename Value>
class AVLTree {
private:
	struct AVLNode {
		Key key;
		Value value;
		AVLNode* left;
		AVLNode* right;
		int height;

		AVLNode(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->height = 1;
		}

		AVLNode(AVLNode* node) {
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
			this->height = node->height;
		}
	};

	AVLNode* root;
	int _size;

	AVLNode* insert(AVLNode* node, Key key, Value value) {
		if(node == nullptr) {
			_size++;
			return new AVLNode(key, value);
		}
		if(node->key == key) {
			node->value = value;
		}
		else if(key < node->key) {
			node->left = insert(node->left, key, value);
		}
		else {
			node->right = insert(node->right, key, value);
		}

		//更新height
		node->height = 1 + max( getHeight(node->left), getHeight(node->right) );

		//计算平衡因子
		int blanceFactor = getBlanceFactor(node);
		if( abs(blanceFactor) > 1 ) {
			cout << "Unblanceed: " << blanceFactor;
		}

		//平衡维护
		//右旋转 LL
		if(blanceFactor > 1 && getBlanceFactor(node->left) >= 0) {
			return rightRotate(node);
		}

		//左旋转 RR
		if(blanceFactor > 1 && getBlanceFactor(node->right) >= 0) {
			return leftRotate(node);
		}

		//LR
		if(blanceFactor > 1 && getBlanceFactor(node->left) < 0) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		//RL
		if(blanceFactor > 1 && getBlanceFactor(node->right) < 0) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		return node;
	}


	void inOrder(AVLNode* node, std::vector<Key> keys) {
		if(node == nullptr) return;
		inOrder(node->left, keys);
		keys.push_back(node->key);
		inOrder(node->right, keys);
	}

	bool isBlanced(AVLNode* node) {
		if(node == nullptr)
			return true;

		int blanceFactor = getBlanceFactor(node);

		if(abs(blanceFactor) > 1)
			return false;

		return isBlanced(node->left) && isBlanced(node->right);
	}

	void rightRotate(AVLNode* y) {
		AVLNode* x = y->left;
		AVLNode* T3 = x->right;

		//向右旋转
		x->right = y;
		y->left = T3;

		//更新height
		y->height = 1 + max( getHeight(y->left), getHeight(y->right) );
		x->height = 1 + max( getHeight(x->left), getHeight(x->right) );

		return x;
	}

	void leftRotate(AVLNode* y) {
		AVLNode* x = y->right;
		AVLNode* T3 = x->left;

		//向左旋转
		x->left = y;
		y->right = T3;

		//更新height
		y->height = 1 + max( getHeight(y->left), getHeight(y->right) );
		x->height = 1 + max( getHeight(x->left), getHeight(x->right) );

		return x;
	}

	AVLNode* findMin(AVLNode* node) {
		if(node->left == nullptr)
			return node;
		return findMin(node->left);

	}

	AVLNode* findMax(AVLNode* node) {
		if(node->right == nullptr)
			return node;
		return findMax(node->right);
	}

	AVLNode* removeMin(AVLNode* node) {
		if(node->left == nullptr) {
			AVLNode* rightNode = node->right;
			delete node;
			_size--;
			return rightNode;
		}
		node->left = remove(node->left);
		return node;
	}

	AVLNode* removeMax(AVLNode* node) {
		if(node->right == nullptr) {
			AVLNode* leftNode = node->left;
			delete node;
			_size--;
			return leftNode;
		}
		node->right == remove(node->right);
		return node;
	}

	AVLNode* remove(AVLNode* node, Key key) {
		if(node == nullptr)
			return nullptr;

		AVLNode* retNode;
		if(key < node->key) {
			node->left = remove(node->left, key);
			retNode = node;
		}
		else if(key > node->key) {
			node->right = remove(node->right, key);
			retNode = node;
		}
		else {
			if(node->left == nullptr) {
				AVLNode* rightNode = node->right;
				node->right = nullptr;
				_size--;
				retNode = rightNode;
			}
			if(node->right == nullptr) {
				AVLNode* leftNode = node->left;
				node->left = nullptr;
				_size--;
				retNode = leftNode;
			}

			AVLNode* successor = new AVLNode(findMin(node->right));
			_size++;

			successor->right = removeMin(node->right);
			successor->left = node->left;

			delete node;
			_size--;

			retNode = successor;
		}
	}

	void destroy(AVLNode* node) {
		if(node != nullptr) {
			destroy(node->left);
			destroy(node->right);

			delete node;
			_size--;
		}
	}

public:
	AVLTree() {
		root = nullptr;
		int _size = 0;
	}

	~AVLTree() { destroy(root); }

	int size() {
		return _size;
	}

	bool empty() {
		return _size == 0;
	}

	int getHeight(AVLNode* node) {
		if(node == nullptr)
			return 0;
		return node->height;
	}
	//获得节点的平衡因子
	int getBlanceFactor(AVLNode* node) {
		if(node == nullptr)
			return 0;
		return ( getHeight(node->left) - getHeight(node->right) );
	}

	bool isBST() {
		std::vector<Key> keys;
		inOrder(root, keys);
		for(int i =1; i < keys.size(); i++) {
			if(keys.at(i - 1) < keys.at(i))
				return false;
		}
		return true;
	}

	bool isBlanced() {
		return isBlanced(root);
	}

	void insert(Key key, Value value) {
		insert(root, key, value);
	}

	AVLNode* find(AVLNode* node, Key key) {
		if(node == nullptr) {
			return nullptr;
		}
		if(key == node->key) {
			return node;
		}
		else if (key < node->key) {
			find(node->left, key);
		}
		else {
			find(node->right, key);
		}
	}

	bool contain(Key key) {
		return find(root, key) != nullptr;
	}

	Value* getValue(Key key) {
		AVLTree* node = find(key);
		return node == nullptr ? nullptr : &(node->value);
	}

	Key findMin() {
		AVLNode* minNode = findMin(root);
	}

	Key findMax() {
		AVLNode* maxNode = findMax(root);
	}

	AVLNode* removeMin() {
		if(root)
			removeMin(root);
	}

	AVLNode* removeMax() {
		if(root)
			removeMax(root);
	}

	void set(Key key, Value value) {
		AVLTree* node = find(key);
		if(node != nullptr) {
			node->value = value;
		}
	}

	Value* remove(Key key) {
		AVLNode* node = find(root, key);
		if(node != nullptr) {
			root = remove(root, key);
			return &(node->value);
		}
		return nullptr;
	}


};

#endif  //AVL_AVLTREE_H
