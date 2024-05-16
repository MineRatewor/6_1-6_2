#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;


void create(ofstream&, int);
void getFile(ofstream&, ifstream&, int);
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	cout << "Пожалуйста, введите количество целых чисел:" << endl; cin >> n;

	ofstream fout("f.bin", ios::binary);
	
	if (!fout.is_open()) {
		cout << "Ошибка открытия файла!" << endl;

	}
	else {
		create(fout, n);
	}

	fout.close();

	ofstream fout1("g.bin", ios::binary);
	
	ifstream fin("f.bin", ios::binary);
	
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
	}
	else {
		getFile(fout1, fin, n);
	}

	fout1.close();
	fin.close();
	
	return 0;
}

void create(ofstream& fout, int n) {
	for (int i = 0; i < n; i++) {
		int num;
		cout << "Пожалуйста, введите целое число:" << endl; cin >> num;
		fout.write((char*)&num, sizeof(int));
		
	}
}

void getFile(ofstream& fout1, ifstream& fin, int n) {
	int num; int count1 = 0; int count2 = 0; int i = 0; int j = 0; int count = 0;
	while (1) {
		if (count1 == 0) {
			fin.seekg(i*sizeof(int), ios_base::beg);
			while (!fin.eof()) {
				i++;
				fin.read((char*)&num, sizeof(int));
				if (num % 2 == 0) {
					
					fout1.write((char*)&num, sizeof(int)); count1++; count++;
				}

				if (count1 == 2) {
					break;
				}
			}
			count2 = 0;
		}

		if (count2 == 0) {
			fin.seekg(j * sizeof(int), ios_base::beg);
			while (!fin.eof()) {
				j++;
				fin.read((char*)&num, sizeof(int));
				if (num % 2 == 1) {
					
				    fout1.write((char*)&num, sizeof(int)); count2++; count++;
				}
				if (count2 == 2) {
					break;
				}
			}
			count1 = 0;
		}
		if (count == n) {
			break;
		}
	}
}


