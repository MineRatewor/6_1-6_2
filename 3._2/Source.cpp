#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void create(ofstream&, int);
void getFile(ofstream&, ifstream&, int);
void print(ifstream& fin);
int countSize(ifstream& fin);
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	cout << "Пожалуйста, введите количество целых чисел:" << endl; cin >> n;

	ofstream fout("f.bin", ios::binary);

	if (!fout.is_open()) {
		cout << "Ошибка открытия файла!" << endl;

	}
	else {
		/*fout.clear();*/
		create(fout, n);
	}

	fout.close();

	ofstream fout1;
	fout1.open("g.bin", ios::binary);
	ifstream fin;
	fin.open("f.bin", ios::binary);
	ifstream f("f.bin", ios::binary);
	int size = countSize(f);
	f.close();
	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
	}
	else {
		getFile(fout1, fin, size);
	}
	
	print(fin);
	fout1.close();
	fin.close();
	ifstream gfile("g.bin", ios::binary);
	if (!gfile.is_open()) {
		cout << "Ошибка открытия файла!" << endl;
	}
	print(gfile);
	gfile.close();
	
	
	return 0;
}

void create(ofstream& fout, int n) {
	for (int i = 0; i < n; i++) {
		int num;
		cout << "Пожалуйста, введите целое число:" << endl; cin >> num;
		 fout.write((char*)&num, sizeof(int));
	}
}

void getFile(ofstream& fout1, ifstream& fin , int size) {
	 int k;
	/*while (!fin.eof()) {
		fin >> k;
		end++;
	}*/
	int num; int count1 = 0; int count2 = 0; int i = 0; int j = 0; int count = 0;
	while (1) {
		if (count1 == 0) {
			fin.seekg(i*sizeof(int), ios_base::beg);
			while (!fin.eof()) {

				 fin.read((char*)&num, sizeof(int));
				int tmp = num;
				/*while (tmp >= 1) {
					tmp /= 10; i++;
				}*/
				if (num % 2 == 0) {
					fout1.write((char*)&num, sizeof(int)); count1++; count++;
				}
				if (count1 == 2) {
					i++; break;
				}
				i++;
			}
			count2 = 0;
		}

		if (count2 == 0) {
			fin.seekg(j*sizeof(int), ios_base::beg);
			while (!fin.eof()) {

				fin.read((char*)&num, sizeof(int));
				int tmp = num;
				/*while (tmp >= 1) {

					tmp /= 10; j++;
				}*/

				if (num % 2 == 1) {
					fout1.write((char*)&num, sizeof(int)); count2++; count++;
				}

				if (count2 == 2) {
					j++; break;
				}
				j++;
			}
			count1 = 0;
		}
		if (count == size) {
			break;
		}
	}
}
void print(ifstream& fin) {
	int num = 0;
	fin.seekg( ios::beg);
	fin.read((char*)&num, sizeof(int));
	while (fin) {
		cout << setw(3) << num;
		fin.read((char*)&num, sizeof(int));
	}
	cout << endl;
}
int countSize(ifstream& fin) {
	int num; int size = -1;
	while (!fin.eof()) {
		fin.read((char*)&num, sizeof(int)); size++;
	}
	return size;
}
