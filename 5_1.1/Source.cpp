#include<iostream>
#include<string>
using namespace std;

string getCombination(string);
void main() {
	setlocale(LC_ALL, "RU");
	string str;
	cout << "Пожалуйста, введите текст:" << endl; getline(cin,str);
	cout << str << endl;
	string new_str = getCombination(str);
	cout << new_str;
}
string getCombination(string str) {
	int index_max = 0; int count_max = 0;
	for (int i = 0; i < str.length(); i++) {
		char symbol = str[i]; int index = i; int count = 0;
		for (int j = i + 1; j < str.length(); j++) {
			if (symbol == str[j]) {
				count++;
			}
			else {
				break;
			}
		}
		if (count + 1 >= count_max) {
			count_max = count + 1;
			index_max = index;
		}
		i += count;
	}
	str.erase(index_max, count_max);
	return str;
}