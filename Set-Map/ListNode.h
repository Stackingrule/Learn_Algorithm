#ifndef LINKEDLIST_LISTNODE_H
#define LINKEDLIST_LISTNODE_H

template<class T>
class ListNode
{
private:
	T e;
	ListNode* next;
	
public:
	ListNode(T e, ListNode* next) : e(e), next(next) {}
	ListNode(T e) : e(e), next(nullptr) {}
	ListNode() : next(nullptr) {}
	~ListNode();
	
};

#endif  //LINKEDLIST_LISTNODE_H