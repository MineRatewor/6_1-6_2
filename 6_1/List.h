#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

template<typename T>
class List {
private:
	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;

		Node(T data, Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}

	};
	Node<T>* head;
	int size;

public:
	List();
	void push_back(T data);
	int GetSize() { return size; }
	void pop_front();
	void push_front(T data);
	void insert(T data, int index);
	void find(int index);
	void clear();
	T& operator[](const int index);
	void  print();
	void pop_back();
	void removeAt(int index);
	// конуструктор копирования
	List(const List& l);
	List& operator=(const List& l) {
		if (this != &l) {
			head = nullptr;
			Node<T>* current = l.head;
			while (current != nullptr) {
				push_back(current->data);
				current = current->pNext;
			}
		}
		return *this;
	}
	// конструктор перемещения
	List(List&& l);
	List& operator=(List&& l) {

		head = nullptr;
		Node<T>* current = l.head;
		while (current != nullptr) {
			push_back(current->data);
			current = current->pNext;
		}
		l.clear();

		return *this;
	}
	~List();

};

template<typename T>
List<T>::List() {
	size = 0;
	head = nullptr;
}


template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}


template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<T>* current = this->head;
		for (int i = 0; i < index - 1; i++) {
			current = current->pNext;
		}
		Node<T>* newNode = new Node<T>(data, current->pNext);

		current->pNext = newNode;
		size++;
	}
}
template<typename T>
void List<T>::find(int index)
{
	Node<T>* current = this->head;
	for (int i = 0; i < index; i++) {
		current = current->pNext;
	}
	cout << current->data;
}
template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;

}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* tmp = head;

	head = head->pNext;
	delete tmp;
	size--;
}

template<typename T>
void List<T>::removeAt(int index) {
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* current = this->head;
		for (int i = 0; i < index - 1; i++) {
			current = current->pNext;
		}
		Node<T>* ToDelete = current->pNext;
		current->pNext = ToDelete->pNext;
		delete ToDelete;
		size--;
	}
}



template<typename T>
void List<T>::clear()
{
	while (size) {
		pop_front();
	}
}



template<typename T>
T& List<T>::operator[](const int index)
{
	if (index < 0 or index >= size and index != 0) {
		cout << "Index out of range!";

	}
	int count = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (count == index) {
			return current->data;
		}
		current = current->pNext;
		count++;
	}

}

template<typename T>
void List<T>::print()
{
	Node<T>* current = this->head;
	while (current != nullptr) {
		cout << setw(3) << current->data;
		current = current->pNext;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);
	size--;
}



template<typename T>
List<T>::List(const List& l)
{
	head = nullptr;
	Node<T>* current = l.head;
	while (current != nullptr) {
		push_back(current->data);
		current = current->pNext;
	}

}
template<typename T>
List<T>::List(List&& l)
{
	head = nullptr;
	Node<T>* current = l.head;
	while (current != nullptr) {
		push_back(current->data);
		current = current->pNext;
	}
	l.clear();
}

template<typename T>
List<T>::~List()
{
	clear();
}
