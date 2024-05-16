#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

template<typename T>
class vector {
private:
	T* arr;
	int s;
	int c;
public:
	vector() {
		s = c = 0;
	}

	vector(int num) {
		s = c = num;
		arr = new T[s];
	}

	vector(const vector& arr2) {
		s = arr2.s;
		c = arr2.c;
		T* tmp = new T[s];
		for (int i = 0; i < s; i++) {
			tmp[i] = arr2.arr[i];
		}
		delete[] arr;
		arr = tmp;

	}

	vector& operator=(const vector& arr2) {
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

	vector(vector&& arr2) : arr(arr2.arr),
		s(arr2.s),
		c(arr2.c) {
		T* tmp = new T[s];
		for (int i = 0; i < s; i++) {
			tmp[i] = arr2.arr[i];
		}
		delete[] arr;
		arr = tmp;
		arr2 = nullptr;
		arr2.s = 0;
		arr2.c = 0;
	}

	vector& operator=(vector&& arr2)
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

	void new_allocation() {
		c = s + 5;
		T* temp = new T[c]();


		for (int i = 0; i < s; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;

	}
	void push_back(T element) {
		if (s == c) {
			new_allocation();
		}
		arr[s] = element;
		s++;
	}


	void pop_back() {
		if (s == 0) {
			cout << "Can't pop, because vector is empty!" << endl;
			return;
		}
		s--;
	}

	int size() {
		return s;
	}

	void insert(int index, T data) {
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

	void pop(int index) {
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

	void print() {
		for (int i = 0; i < s; i++) {
			cout << setw(3) << arr[i];
		}
	}

	void clear() {
		s = c = 0;
		delete[] arr;
		arr = nullptr;
	}

	bool empty() {
		if (s == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	T& operator[](int index) {
		if (index < 0 or index > s) {
			cout << "Index out of range!";
		}
		return arr[index];
	}

	friend istream& operator >>(istream& fin, vector<T>& arr2) {
		for (int i = 0; i < arr2.s; i++) {
			fin >> arr2.arr[i];
		}
		return fin;
	}
	friend ostream& operator <<(ostream& fout, const vector<T>& arr2) {
		for (int i = 0; i < arr2.s; i++) {
			fout << arr2.arr[i];
		}
		return fout;
	}

	~vector() {
		delete[] arr;
	}
};