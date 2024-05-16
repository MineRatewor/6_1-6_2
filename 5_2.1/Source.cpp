#include<iostream>
#include<string>
using namespace std;

string getStr(string);
string delStr(string);
void main() {
	setlocale(LC_ALL, "RU");
	string str; 
	cout << "Пожалуйста, введите строку:" << endl; getline(cin, str);
	string s = delStr(str);
	string s1 = getStr(s);
	cout << s1;

}
string delStr(string str) {
	string s;
	for (int i = 0; i < str.length(); i++) {
		if ( str[i] == ',' or str[i] == '.' or str[i] == '!' or str[i] == ':') {
			s += ' ';
		}
		else {
			s += str[i];
			
		}

	}
	return s;
}

string getStr(string str) {
	string new_str; int index = 0; int count = 1; int ind = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ' or i == str.length() - 1) {
			
			if (i == str.length() - 1) {
				new_str.insert(ind, str, index, count);
				break;
			}
			if (i != 0) {
				new_str.insert(ind, str, index, count);
				ind += count;
			
			}
			index = i + 1; 	count = 1;
			continue;
		}
		char symbol = str[i]; int flag = 0;
		for (int j = i + 1; j < str.length(); j++) {
			if (str[j] == ' ' ) {
				break;
			}
			if (symbol == str[j]) {
				flag++;
				break;
			}
		}
		if (flag == 1) {
			int k = 0;
			for (int j = i+1; j < str.length(); j++) {
				
				if (str[j] == ' ' ) {
					break;
				}
				else {
					k++;
				}
			}
			i += k; count = 0; 
			
		}
		else {
			count++;
		}
	}
	return new_str;
}