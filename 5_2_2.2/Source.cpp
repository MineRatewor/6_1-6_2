#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int f(int, int, int);
void inputMatr(Vector<int>&, int);
void printMatr(Vector<int>, int);
void multiMatr(Vector<int> matr1, Vector<int> matr2, int n, Vector<int>& matr12);
void sumMatr(Vector<int> matr1, Vector<int>matr2, int n, Vector<int>& matr);
void main() {
	setlocale(LC_ALL, "RU");
	int n;
	cout << "Пожалуйста, введите порядок матрицы:" << endl; cin >> n;
	int size = pow(n, 2);
	// matr A
	Vector<int> matrA(size);
	inputMatr(matrA, n);
	cout << "Матрица A:" << endl;
	printMatr(matrA, n);

	//matr B
	Vector<int> matrB(size);
	inputMatr(matrB, n);
	cout << "Матрица B:" << endl;
	printMatr(matrB, n);
	cout << endl;
	Vector<int> matrAB(size);
	multiMatr(matrA, matrB, n, matrAB);
	cout << "Матрица AB:" << endl;
	printMatr(matrAB, n);
	cout << endl;

	Vector<int> matrBA(size);
	multiMatr(matrB, matrA, n, matrBA);
	cout << "Матрица BA:" << endl;
	printMatr(matrBA, n);
	cout << endl;

	Vector<int> matr(size);
	sumMatr(matrAB, matrBA, n, matr);
	cout << "Результат:" << endl;
	printMatr(matr, n);
}
int f(int i, int j, int n) {
	return i * n + j;
}
void inputMatr(Vector<int>& matr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matr[f(i, j, n)] = rand() % 10;
		}
	}
}

void printMatr(Vector<int> matr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <n; j++) {
			cout << setw(5) << matr[f(i, j, n)];
		}
		cout << endl;
	}
}

void multiMatr(Vector<int> matr1, Vector<int> matr2, int n, Vector<int>& matr12) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			sum = 0;
			for (int j = 0; j < n; j++)
			{
				sum += matr1[f(j, k, n)] * matr2[f(i, j, n)];
			}
			matr12[f(i, k, n)] = sum;
		}
	}


}
void sumMatr(Vector<int> matr1, Vector<int>matr2, int n, Vector<int>& matr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matr[f(i, j, n)] = matr1[f(i, j, n)] + matr2[f(i, j, n)];
		}
	}
}