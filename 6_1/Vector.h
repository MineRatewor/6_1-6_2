#pragma once
#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

template<typename T>
class Vector {
private:
	T* arr;
	int s;
	int c;
public:

	Vector();
	Vector(int num);
	Vector(const Vector& arr2);

	Vector(Vector&& arr2);
	Vector& operator=(Vector&& arr2)
	{
		if (this != &arr2) {
			s = arr2.s;
			c = arr2.c;
			T* tmp = new T[s];
			for (int i = 0; i < s; i++) {
				tmp[i] = arr2.arr[i];
			}
			delete[] arr;
			arr = tmp;

			arr2.s = 0;
			arr2.c = 0;
		}
		return *this;
	}
	void new_allocation();
	void push_back(T element);
	void pop_back();

	void random();
	int size();



	void insert(int index, T data);

	void pop(int index);

	void print();

	void clear();

	bool empty();

	~Vector();

	Vector& operator=(const Vector& arr2) {
		if (this != &arr2) {
			s = arr2.s;
			c = arr2.c;
			T* tmp = new T[s];
			for (int i = 0; i < s; i++) {
				tmp[i] = arr2.arr[i];
			}
			delete[]arr;
			arr = tmp;
		}
		return *this;
	}

	T& operator[](int index) {
		if (index < 0 or index > s) {
			cout << "Index out of range!";
		}
		return arr[index];
	}
	friend istream& operator >>(istream& fin, Vector<T>& arr2) {
		for (int i = 0; i < arr2.s; i++) {
			fin >> arr2.arr[i];
		}
		return fin;
	}
	friend ostream& operator <<(ostream& fout, const Vector<T>& arr2) {
		for (int i = 0; i < arr2.s; i++) {
			fout << arr2.arr[i];
		}
		return fout;
	}


};
template<typename T>
Vector<T>::Vector() {
	s = c = 0;
}
template<typename T>
Vector<T>::Vector(int num) {
	s = c = num;
	arr = new T[s];
}
template<typename T>
Vector<T>::Vector(const Vector& arr2) {
	s = arr2.s;
	c = arr2.c;
	T* tmp = new T[s];
	for (int i = 0; i < s; i++) {
		tmp[i] = arr2.arr[i];
	}
	delete[] arr;
	arr = tmp;

}
template<typename T>
Vector<T>::Vector(Vector&& arr2) {
	s = arr2.s;
	c = arr2.c;
	T* tmp = new T[s];
	for (int i = 0; i < s; i++) {
		tmp[i] = arr2.arr[i];
	}
	delete[] arr;
	arr = tmp;

	arr2.s = 0;
	arr2.c = 0;
}
template<typename T>
void Vector<T>::new_allocation() {
	c = s + 5;
	T* temp = new T[c]();


	for (int i = 0; i < s; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}

template<typename T>
void Vector<T>::push_back(T element) {
	if (s == c) {
		new_allocation();
	}
	arr[s] = element;
	s++;
}

template<typename T>
void Vector<T>::pop_back() {
	if (s == 0) {
		cout << "Can't pop, because vector is empty!" << endl;
		return;
	}
	s--;
}
template<typename T>
void Vector<T>::random()
{
	srand(time(NULL));
	for (int i = 0; i < s; i++) {
		arr[i] = rand() % 100;
	}

}
template<typename T>
int Vector<T>::size() {
	return s;
}



template<typename T>
void Vector<T>::insert(int index, T data) {
	if (s == c) {
		new_allocation();
	}
	s++;
	T* tmp = new T[s];
	int k = 0;
	for (int i = 0; i < s; i++) {
		if (i == index) {
			tmp[i] = data;
		}
		else {
			tmp[i] = arr[k];
			k++;
		}
	}
	delete[]arr;
	arr = tmp;
}
template<typename T>
void Vector<T>::pop(int index) {
	if (s == 0) {
		cout << "Can't pop, because vector is empty!" << endl;
		return;
	}
	s--;
	T* temp1 = new T[s];
	int k = 0;
	for (int i = 0; i < s; i++) {
		if (index == i) {
			k++;
		}
		temp1[i] = arr[k];
		k++;
	}
	delete[] arr;
	arr = temp1;

}
template<typename T>
void Vector<T>::print() {
	for (int i = 0; i < s; i++) {
		cout << setw(3) << arr[i];
	}
}
template<typename T>
void Vector<T>::clear() {
	s = c = 0;
	delete[] arr;
	arr = nullptr;
}

template<typename T>
bool Vector<T>::empty() {
	if (s == 0) {
		return true;
	}
	else {
		return false;
	}
}
template<typename T>
Vector<T>::~Vector() {
	delete[] arr;
}
