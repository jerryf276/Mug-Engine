#pragma once

//Used for pool allocators
template<class T>
class Node
{
public:
	T data;
	Node* next;

	Node(T n);
};

template<class T>
class SingularLinkedList
{
public:
	Node<T>* head;

	SingularLinkedList();
	SingularLinkedList(T n);
	~SingularLinkedList();

	void Insert(T n);
	void Remove(T n);
	void RemoveAll(T n);
	int Size();
//	typename SingularLinkedList<T>::Node* GetTail();
	
};
