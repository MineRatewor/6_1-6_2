#include "Text.h"

int main() {
	setlocale(LC_CTYPE, ".1251");
	Text s1;
	s1 += '�';
	s1 += '�';
	s1 += '�';
	s1 += '�';
	s1.insert('�', 0);
	s1.print(); cout << endl;
	s1.pop_back();
	s1.print();
	
	
}


