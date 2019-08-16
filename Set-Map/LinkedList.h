#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "ListNode.h"

template<class T>
class LinkedList
{
private:
	ListNode<T>* head;
	ListNode<T>* dummyHead;
	int _size;

public:
	LinkedList() {
		head = new ListNode<T>();
		_size = 0;
	}

	~LinkedList();

	int size() {
		return _size;
	}

	bool empty() {
		return _size == 0;
	}

	void set(int index, T e) {
		if(index < 0 || index > _size)
			throw
	}

	void insert(int index, T e) {
		ListNode<T>* node = new ListNode<T> (e);
		if(index < 0 || index > _size)
			throw 
		if(index == 0) 
			insertAsFirst(e);
		else {
			ListNode<T>* node = head;
			for(int i = 0; i < index - 1; i++)
				node = node->next;

			node->next = node->next;
			node->next = node;
			_size++;
		}
	}

	void insertAsFirst(T e) {
		ListNode<T>* node = new ListNode<T>(e);
		node->next = head;
		head = node;
		_size++;
	}

	void insertAsLast(T e) {
		insert(_size, e);
	}

	T remove(int index) {	//涉及链表头节点的操作，虚拟头结点
		ListNode<T>* dummyHead;
		dummyHead->next = head;
		ListNode<T>* node = dummyHead;
		if(index < 0 || index > _size)
			throw
		for(int i = 0; i < index; i++) {
			node = node->next;
		}
		ListNode<T>* retNode = node->next;
		node->next = retNode->next;
		_size--;

		delete retNode;
		return retNode->e;
	}

	T removeFirst() {
		return remove(0);
	}

	T removeLast() {
		return remove(_size - 1);
	}

	void removeElem(T e) {
	    Node<T> *prev = head;
	    while (prev->next != nullptr) {
	        if (prev->next->e == e) {
	            break;
	        }
	        prev = prev->next;
	    }

	    if (prev->next != nullptr) {
	        Node<T> *delNode = prev->next;
	        prev->next = delNode->next;
	        delNode->next = nullptr;
	        size--;
	    }
	}

	T get(int index) {
		if(index < 0 || index > _size)
		ListNode<T>* node = head;
		for(int i = 0; i < index; i++) {
			node = node->next;
		}
		return node->e;
	}

	T find(T e) {
		ListNode<T>* node = head;
		int index = 0;
		for(int i = 0; i < _size; i++) {
			if(node->e != e) {
				node = node->next;
				index++
			}
			else {
				return index;
			}
		}
		return -1;
	}


	
};

#endif  //LINKEDLIST_LINKEDLIST_H