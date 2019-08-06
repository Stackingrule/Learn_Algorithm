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

		RBTree(RBNode* node) {
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
			this->color = node->color;
		}
	};

	RBNode* root;
	int _size;

	//     node                     x
	//    /    \       左旋转      /  \
	//    T1    x   ---------->  node  T3
	//         / \              /   \
	//        T2 T3            T1   T2
	//        
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

	void flipColor(RBNode* node) {
		node->color = RED;
		node->left = node->right = BLACK;
	}

	RBNode* insert(RBNode* node, Key key, Value value) {
		if(node == nullptr) {
			_size++;
			return new RBNode(key, value);
		}

		if(key < node->key) {

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

	void insert(Key key, Value value) {
		insert(root, key, value);
		root->color = BLACK;
	}

	bool contain(Key key) {
		return contain(root, key);
	}




	
};

#endif  //REDBLACKTREE_RBTREE_H
