#pragma once
#include"Exhibit.h"
#include"ArtObjects.h"

class Picture : public Exhibit, public ArtObjects
{
private:
	char* author;
	
public:
	Picture() :ArtObjects() {
		author = nullptr;

	}
	Picture(const char arr[], const char arr1[], const char arr2[], int Year) :Exhibit(arr) , ArtObjects(arr1,Year) {
	/*	char* tmp1 = new char[strlen(arr1) + 1] {};
		for (int i = 0; i < strlen(arr1); i++) {
			tmp1[i] = arr1[i];
		}
		subject = tmp1;*/
		
		char* tmp2 = new char[strlen(arr2) + 1] {};
		for (int i = 0; i < strlen(arr2); i++) {
			tmp2[i] = arr2[i];
		}
		author = tmp2;

		//year = Year;
	}

	Picture(Picture& s) :Exhibit(s), ArtObjects(s) {
		/*subject = s.subject;*/
		author = s.author;
		/*year = s.year;*/
	}
	 Picture& operator=(Picture& s) {
		Exhibit::operator=(s);
		ArtObjects::operator=(s);
		/*subject = s.subject;*/
		author = s.author;
		/*year = s.year;*/

		return*this;
	}

	Picture(Picture&& s) :Exhibit(move(s)), ArtObjects(move(s)){
		/*subject = s.subject;*/
		author = s.author;
		/*year = s.year;*/


		s.author = nullptr;
		/*s.subject = nullptr;*/
	/*	s.year = 0;*/
	}

	Picture& operator=(Picture&& s) {
		Exhibit::operator=(move(s));
		ArtObjects::operator=(move(s));
		/*subject = s.subject;*/
		author = s.author;
	/*	year = s.year;*/


		s.author = nullptr;
		/*s.subject = nullptr;*/
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
	friend ostream& operator <<(ostream& fout, const Picture& s) {
		s.print();
		return fout;
	}
	~Picture()  {
		 author = nullptr;
		delete[] author;
	}


};