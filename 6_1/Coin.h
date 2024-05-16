#pragma once
#include"Exhibit.h"

class Coin : public Exhibit {
private:
	double domination;
	int startYear;
	int endYear;
public:
	Coin() :Exhibit() {}
	Coin(const char arr[], double dom, int st, int en) :Exhibit(arr) {
		domination = dom;
		startYear = st;
		endYear = en;
	}
	Coin(Coin& s) :Exhibit(s) {
		domination = s.domination;
		startYear = s.startYear;
		endYear = s.endYear;
	}
	Coin& operator=(Coin& s) {
		Exhibit::operator=(s);
		domination = s.domination;
		startYear = s.startYear;
		endYear = s.endYear;
		return *this;
	}

	Coin(Coin&& s) :Exhibit(move(s)) {
		domination = s.domination;
		startYear = s.startYear;
		endYear = s.endYear;


		s.domination = 0;
		s.startYear = 0;
		s.endYear = 0;
	}
	Coin& operator=(Coin&& s) {
		Exhibit::operator=(move(s));
		domination = s.domination;
		startYear = s.startYear;
		endYear = s.endYear;


		s.domination = 0;
		s.startYear = 0;
		s.endYear = 0;
		return *this;
	}

	void print() const override {
		if (name == nullptr) {
			cout << "Empty!" << endl;
			return;
		}
		cout << "Name:" << setw(5) << name << endl;
		cout << "Domination:" << setw(3) << domination << endl;
		cout << "StartYear:" << setw(5) << startYear << endl;
		cout << "EndYear:" << setw(5) << endYear << endl;
	}
	friend ostream& operator <<(ostream& fout, const Coin& s) {
		s.print();
		return fout;
	}

};