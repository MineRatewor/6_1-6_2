#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void create(ofstream&, int);
void getFile(ofstream&, ifstream&);

int main() {
	setlocale(LC_ALL, "RU");
	int n; 
	cout << "Пожалуйста, введите количество целых чисел:" << endl; cin >> n;
	
	ofstream fout("f.txt");

	if (!fout.is_open()) {
		cout << "Ошибка открытия файла!" << endl;

	}
	else {
		fout.clear();
		create(fout, n);
	}

	fout.close();

	ofstream fout1;
	fout1.open("g.txt");
	ifstream fin;
	fin.open("f.txt");
	
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
	}
	else {
		getFile(fout1, fin);
	}
	
	
	fout1.close();
	fin.close();
	
	return 0;
}

void create(ofstream&fout, int n) {
	for (int i = 0; i < n; i++) {
		int num;
		cout << "Пожалуйста, введите целое число:" << endl; cin >> num;
		fout <<  " " << num ;
	}
}

void getFile(ofstream& fout1, ifstream& fin) {
	int end = 0; int k;
	while (!fin.eof()) {
		fin >> k;
		end++;
	}
	int num; int count1 = 0; int count2 = 0; int i = 1; int j = 1; int count = 0; 
	while (1) {
		if (count1 == 0) {
			fin.seekg(i , ios_base::beg); 
			while (!fin.eof()) {
				
				fin >> num;
				 int tmp = num;
				while (tmp >= 1) {
					tmp /= 10; i++;
				}
				if (num % 2 == 0) {
					fout1 << " " << num; count1++; count++;
				}
				if (count1 == 2) {
					i++; break;
				}
				i++;
			}
			count2 = 0;
		}
		
		if (count2 == 0) {
			fin.seekg(j, ios_base::beg);  
			while (!fin.eof()) {
				
				fin >> num;
				 int tmp = num;
				while (tmp >= 1) {
					
					tmp /= 10; j++;
				}
				
				if (num % 2 == 1) {
					fout1 << " " << num; count2++; count++;
				}
				
				if (count2 == 2) {
					j++; break;
				}
				j++;
			}
			count1 = 0;
		}
		if (count == end) {
			break;
		}
	}
}
