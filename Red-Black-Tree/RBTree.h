#ifndef REDBLACKTREE_RBTREE_H
#define REDBLACKTREE_RBTREE_H

template<typename Key, typename Value>
class RBTree
{
private:
	static const bool RED = true;
	static const bool BLACK = false;
	struct RBNode {
		Key key;
		Value value;
		RBNode* left;
		RBNode* right;
		bool color;

		RBNode(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = left = nullptr;
			this->right = right = nullptr;
			color = RED;
		}

		RBNode(RBNode* node) {
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
			this->color = node->color;
		}
	};

	RBNode* root;
	int _size;

	/*     node                     x          */
	/*    /    \       左旋转      /  \        */
	/*    T1    x   ---------->  node  T3      */
	/*         / \              /   \          */
	/*        T2 T3            T1   T2         */
	/*                                         */        
	RBNode* leftRotate(RBNode* node) {       
		RBNode* x = node->right;	    	 
		node->right = x->left;               
		x->left = node;                      
		x->color = node->color;              
		node->color = RED;                   
		return x;
	}

	RBNode* rightRotate(RBNode* node) {
		RBNode* x = node->left;
		node->left = x->right;
		x->right = node;
		x->color = node->color;
		node->color = RED;
		return x;
	}

	RBNode* find(RBNode* node, Key key) {
		if(node == nullptr) {
			return nullptr;
		}
		if(key = node->key) {
			return node;
		} 
		else if (key < node->key) {
			return find(node->left, key);
		}
		else {
			return find(node->right, key);
		}
	}

	void flipColor(RBNode* node) {
		node->color = RED;
		node->left = node->right = BLACK;
	}

	RBNode* insert(RBNode* node, Key key, Value value) {
		if(node == nullptr) {
			_size++;
			return new RBNode(key, value);	//默认为红节点		
		}

		if(key < node->key) {
			node->left = insert(node->left, key, value);
		}
		else if(key > node->key) {
			node->right = insert(node->right, key, value);
		}
		else {
			node->value = value;
		}

		if(isRed(node->right) && !isRed(node->left)) {
			node = leftRotate(node);
		}
		if(isRed(node->left) && isRed(node->left->left)) {
			node = rightRotate(node);
		}
		if(isRed(node->left) && isRed(node->right)) {
			flipColor(node);
		}

		return node;
	}

	void destroy(RBNode* node) {
		if(node != nullptr) {
			destroy(node->left);
			destroy(node->right);
			delete node;
			_size--;
		}
	}


public:
	RBTree() {
		root = nullptr;
		_size = 0;
	}

	~RBTree() {
		destroy(root);
	}

	int size() {
		return _size;
	}

	bool empty() {
		return _size == 0;
	}

	bool isRed(RBNode* node) {
		if(node == nullptr)
			return BLACK;
		return node->color;
	}

	void insert(Key key, Value value) {
		insert(root, key, value);
		root->color = BLACK;
	}

	bool contain(Key key) {
		return find(root, key) != nullptr;
	}

	Value* getValue(Key key) {
		RBNode* node = find(root, key);
		return node == nullptr ? nullptr : &(node->value);
	}

	void set(Key key, Value value) {
		RBNode* node = find(root, key);
		if(node != nullptr) {
			node->value = value;
		}
	}
	
};

#endif  //REDBLACKTREE_RBTREE_H
