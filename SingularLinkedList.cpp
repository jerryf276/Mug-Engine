// Author William Kavanagh, Abertay.
// w.kavanagh@abertay.ac.uk
// CMP201 Practical 2 -- Partial Solution.


#include <iostream>				// You may want this for testing with a main()
#include <string>				// for std::string required for ToString()
#include "SingularLinkedList.h"	
//using namespace std;			// This can stay for now. We will stop using it soon.

// No args constructor, make empty ADT
template <class T>
SingularLinkedList<T>::SingularLinkedList() {
	head = nullptr;
}

template <class T>
// Single element constructor, head with node of value given
SingularLinkedList<T>::SingularLinkedList(T n)
{
	// TODO - assessed [1]
	head = nullptr;
	Insert(n);
}

template <class T>
// default destructor
SingularLinkedList<T>::~SingularLinkedList()
{
}

template <class T>
// append element to LL with value n
void SingularLinkedList<T>::Insert(T n)
{
	// TODO - assessed [1]
	if (head == nullptr) {
		head = new Node(n);
		return;
	}

	Node* temp = head;

	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = new Node(n);
}

// remove first instance of element with value n
template <class T>
void SingularLinkedList<T>::Remove(T n)
{
	// TODO - assessed [1]
	if (head->data == n) {
		head = head->next;
		return;
	}

	Node* temp = head;

	while (temp->next) {
		if (temp->next->data == n) {
			temp->next = temp->next->next;
			return;
		}
	}

}

// remove all instances of element with value n
template <class T>
void SingularLinkedList<T>::RemoveAll(T n)
{
	// TODO - assessed [1]
	if (head->data == n) {
		head = head->next;
	}

	if (head == nullptr) {
		return;
	}

	Node* temp = head;

	while (temp->next) {
		if (temp->next->data == n) {
			temp->next = temp->next->next;
		}

		else if (temp->next) {
			temp = temp->next;
		}
	}
}

// get size of linkedlist
template <class T>
int SingularLinkedList<T>::Size()
{
	int count = 0;
	Node* temp = head;
	while (temp->next)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

// get pointer to final element in linked list
//template <class T>
//typename SingularLinkedList<T>::Node* SingularLinkedList<T>::GetTail()
//{
//	Node* temp = head;
//	if (!head)
//	{
//		return nullptr;
//	}
//	while (temp->next)
//	{
//		temp = temp->next;
//	}
//	return temp;
//}

// Node constructor, set value to n.
template<class T>
Node<T>::Node(T n)
{
	data = n;
	next = nullptr;
}

// Use for testing. Remove or comment out before submitted, or [-1]
//int main()
//{
//
//	LinkedList * list;
//	list = new LinkedList(1);
//	list->Insert(10);
//
//	if (list->head->next->data == 10) {
//		std::cout << "Insert is working!" << std::endl;
//	}
//
//	list->Insert(7);
//	list->Insert(9);
//
//	LinkedList* secondList;
//	secondList = new LinkedList();
//
//	secondList->Insert(6);
//	secondList->Insert(7);
//	secondList->Insert(9);
//	secondList->Insert(10);
//	secondList->Remove(7);
//
//	if (secondList->head->next->data == 9) {
//		std::cout << "Remove is working!" << std::endl;
//	}
//
//
//	LinkedList* thirdList;
//	thirdList = new LinkedList;
//
//	thirdList->Insert(10);
//	thirdList->Insert(8);
//	thirdList->Insert(10);
//	thirdList->Insert(7);
//	thirdList->Insert(10);
//	thirdList->Insert(9);
//
//	thirdList->RemoveAll(10);
//
//	if (thirdList->head->next->data == 7) {
//		std::cout << "Remove all now works!" << std::endl;
//	}
//
//	LinkedList* fourthList;
//
//	fourthList = new LinkedList(1);
//	fourthList->Insert(10);
//	fourthList->Insert(8);
//	fourthList->Insert(10);
//
//	std::cout << fourthList->ToString() << std::endl;
//
//	fourthList->RemoveAll(10);
//	
//	std::cout << fourthList->ToString() << std::endl;
//
//	fourthList->Insert(7);
//
//	std::cout << fourthList->ToString() << std::endl;
//
//	LinkedList* fifthList;
//	
//	fifthList = new LinkedList();
//
//	fifthList->Insert(5);
//
//	fifthList->RemoveAll(5);
//	std::cout << fifthList->ToString();
//
//	return 0;
//}


