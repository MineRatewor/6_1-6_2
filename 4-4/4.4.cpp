#include "Text.h"

int main() {
	setlocale(LC_CTYPE, ".1251");
	Text s1;
	s1 += 'ÿ';
	s1 += 'ô';
	s1 += 'ë';
	s1 += 'ì';
	s1.insert('û', 0);
	s1.print(); cout << endl;
	s1.pop_back();
	s1.print();
	
	
}


