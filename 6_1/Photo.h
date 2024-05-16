#pragma once
#include"Exhibit.h"
#include"ArtObjects.h"
class Photo :public Exhibit, public ArtObjects {
public:
	Photo() :Exhibit() , ArtObjects() {}
	Photo(const char arr[], const char arr1[], int Year) :Exhibit(arr) , ArtObjects(arr1,Year){
	}

	Photo(Photo& s) :Exhibit(s), ArtObjects(s) {
	}

	Photo& operator=(Photo& s) {
		Exhibit::operator=(s);
		ArtObjects::operator=(s);
		return*this;
	}

	Photo(Photo&& s) :Exhibit(move(s)) , ArtObjects(move(s)) {
	}

	Photo& operator=(Photo&& s) {
		Exhibit::operator=(move(s));
		ArtObjects::operator=(move(s));

		return*this;
	}
	void print() const override {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		cout << "Name:" << setw(3) << name << endl;
		ArtObjects::print();
	}
	friend ostream& operator <<(ostream& fout, const Photo& s) {
		s.print();
		return fout;
	}
	~Photo() {
		
	}
};
