#pragma once
#include"Exhibit.h"
#include"ArtObjects.h"
class Figurines : public Exhibit , public ArtObjects {
private:
	char* author;
public:
	Figurines() :Exhibit() , ArtObjects() {}
	Figurines(const char arr[], const char arr1[], const char arr2[], int Year) :Exhibit(arr), ArtObjects(arr1, Year) {
		for(int i = 0; i < strlen(arr1); i++) {
			char* tmp2 = new char[strlen(arr2) + 1] {};
			for (int i = 0; i < strlen(arr2); i++) {
				tmp2[i] = arr2[i];
			}
			author = tmp2;
	}
	}
	Figurines(Figurines& s) :Exhibit(s), ArtObjects(s) {
		
		author = s.author;
		
	}
	Figurines& operator=(Figurines& s) {
		Exhibit::operator=(s);
		ArtObjects::operator=(s);
		
		author = s.author;
		

		return *this;
	}

	Figurines(Figurines&& s) :Exhibit(move(s)), ArtObjects(move(s)) {
		
		author = s.author;
		

		
		s.author = nullptr;

	}
	Figurines& operator=(Figurines&& s) {
		Exhibit::operator=(move(s));
		ArtObjects::operator=(move(s));

		
		author = s.author;
		

		
		s.author = nullptr;

		return *this;
	}
	void print() const override {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		cout << "Name:" << setw(3) << name << endl;
		cout << "Author:" << setw(3) << author << endl;
		ArtObjects::print();
	}

	friend ostream& operator <<(ostream& fout, const Figurines& s) {
		s.print();
		return fout;
	}
	~Figurines() {
		author = nullptr;
		delete[] author;
	}

};