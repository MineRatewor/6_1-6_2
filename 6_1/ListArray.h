#pragma once
#include"Coin.h"
#include"ColdWeapon.h"
#include"Exhibit.h"
#include"Figurines.h"
#include"Photo.h"
#include"Picture.h"
#include"List.h"


class ListArray {
private:
	List<Exhibit*> l;
public:
	ListArray() {}
	
	void push_back(Coin& st) {
		Coin* st1 = new Coin(st);
		l.push_back(st1);
	}

	void push_back(ColdWeapon& st) {
		ColdWeapon* st1 = new ColdWeapon(st);
		l.push_back(st1);
	}

	void print() {
		for (unsigned int i = 0; i < l.GetSize(); i++)
			cout << *l[i] << endl;
	}

};