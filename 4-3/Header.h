#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

template<typename T>
class List {
private:

	class Node {
	public:
		T data;
		Node* next;
		Node* prev;

		Node(T data, Node* next = NULL, Node* prev = NULL) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};
	Node* head, * tail;
	int size;
public:
	List();
	List(int size);
	//конструктор копирования
	List(const List<T>& l);
	List& operator=(const List& l) {
		if (this != &l) {
			head = nullptr;
			Node* current = l.head;
			while (current != nullptr) {
				push_back(current->data);
				current = current->next;
			}
		}
		return *this;
	}
	//конструктор перемещения
	List(List&& l);
	List& operator=(List&& l) {
		if (this != &l) {
			head = nullptr;
			Node* current = l.head;
			while (current != nullptr) {
				push_back(current->data);
				current = current->next;
			}
		}
		l.clear();
		return *this;
	}
	void push_front(T data);
	void push_back(T data);
	void insert(T data, int index);
	void print();
	int getSize() { return size; }
	void pop_front();
	void find(int index);
	void pop_back();
	void pop(int index);
	void clear();
	T& operator[](const int index);

	~List();

};
template<typename T>
List<T>::List() {
	head = NULL;
	size = 0;
}

template<typename T>
inline List<T>::List(int size)
{
	
	int count = 0;
	while (count != size -1 ) {
		push_back(NULL);
		count++;
	}

}

// конструктор копирования 
template<typename T>
List<T>::List(const List<T>& l) {
	head = nullptr;
	Node* current = l.head;
	while (current != NULL) {
		push_back(current->data);
		current = current->next;
	}

}
//конструктор перемещения
template<typename T>
List<T>::List(List&& l) {
	if (this != &l) {
		head = nullptr;
		Node* current = l.head;
		while (current != NULL) {
			push_back(current->data);
			current = current->next;
		}
	}
	l.clear();
}

template<typename T>
void List<T>::push_front(T data) {
	Node* ptr = new Node(data);
	ptr->next = head;

	if (head != NULL) {
		head->prev = ptr;
	}
	if (tail == NULL) {
		tail = ptr;
	}
	head = ptr;
	size++;
}
template<typename T>
void List<T>::push_back(T data) {
	Node* ptr = new Node(data);

	ptr->prev = tail;
	if (tail != NULL) {
		tail->next = ptr;
	}
	if (head == NULL) {
		head = ptr;
	}
	tail = ptr;
	size++;
}
template<typename T>
T& List<T>::operator[](const int index)
{
	if (index < 0 or index >= size and index != 0) {
		cout << "Index out of range!";

	}
	int count = 0;
	Node* current = this->head;
	while (current != NULL) {
		if (count == index) {
			return current->data;
		}
		current = current->next;
		count++;
	}

}
template<typename T>
void List<T>::pop_front() {
	Node* tmp = this->head;

	head = head->next;

	delete[] tmp;
	size--;
}
template<typename T>
void List<T>::find(int index)
{
	if (index < 0 or index >= size and index != 0) {
		cout << "Index out of range!";
		return;
	}
	Node* current = this->head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	cout << current->data;
}
template<typename T>
void List<T>::pop_back() {
	Node* tmp = this->tail;
	tail = tail->prev;
	tail->next = NULL;
	delete[] tmp;
	size--;

}

template<typename T>
void List<T>::pop(int index)
{
	if (index >= size or index < 0) {
		cout << "Index out of range!";
		return;
	}
	if (index == 0) {
		pop_front();
	}
	else {
		Node* current = this->head;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		Node* tmp = current->next;
		current->next = tmp->next;
		delete[]tmp;
	}
	size--;

}

template<typename T>
void List<T>::insert(T data, int index)
{
	Node* current = this->head;

	for (int i = 0; i < index - 1; i++) {
		current = current->next;
	}
	Node* ptr = new Node(data, current->next, current);

	current->next = ptr;
	size++;
}

template<typename T>
void List<T>::print() {
	Node* current = this->head;
	while (current != NULL) {
		cout << setw(3) << current->data;
		current = current->next;
	}
}
template<typename T>
void List<T>::clear() {
	while (size) {
		pop_front();
	}
}

template<typename T>
List<T>::~List() {
	clear();

}