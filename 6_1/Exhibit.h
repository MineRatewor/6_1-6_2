#pragma once
#include<iomanip>
#include<iostream>
using namespace std;

class Exhibit {
protected:
	char* name;
public:
	Exhibit() {
		name = nullptr;
	}
	Exhibit(const char arr[]) {
		char* tmp = new char[strlen(arr) + 1] {};
		for (int i = 0; i < strlen(arr); i++) {
			tmp[i] = arr[i];
		}
		name = tmp;
	}
	Exhibit(Exhibit& s) {
		char* temp = new char[strlen(s.name) + 1] {};
		for (int i = 0; i < strlen(s.name); i++) {
			temp[i] = s.name[i];
		}
		delete[] name;
		name = temp;

	}

	virtual Exhibit& operator=(Exhibit& s) {
		char* temp = new char[strlen(s.name) + 1] {};
		for (int i = 0; i < strlen(s.name); i++) {
			temp[i] = s.name[i];
		}
		delete[] name;
		name = temp;

		return *this;
	}

	Exhibit(Exhibit&& s) {
		name = s.name;
		s.name = nullptr;
	}

	virtual Exhibit& operator=(Exhibit&& s) {
		char* temp = new char[strlen(s.name) + 1] {};
		for (int i = 0; i < strlen(s.name); i++) {
			temp[i] = s.name[i];
		}
		delete[] name;
		name = temp;

		s.name = nullptr;
		return *this;
	}

	virtual void print() const {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		cout << "Name:" << setw(3);
		for (int i = 0; i < strlen(name); i++) {
			cout << name[i];
		}
	}
	friend ostream& operator <<(ostream& fout, const Exhibit& s) {
		s.print();
		return fout;
	}

	virtual ~Exhibit() {
		delete[] name;
	}

};