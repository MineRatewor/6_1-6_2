// 2 способ с помощью указателей 
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

void printMatr(Vector<Vector<int>>& );
void inputMatr(Vector<Vector<int>>&);
Vector<Vector<int>> sumMatr(Vector<Vector<int>>&, Vector<Vector<int>>&, int, Vector<Vector<int>>&);
Vector<Vector<int>> multiMatr(Vector<Vector<int>>&, Vector<Vector<int>>&, int n, Vector<Vector<int>>&);
void main() {
	setlocale(LC_ALL, "RU");
	int n;
	cout << "Пожалуйста, введите порядок матрицы N:" << endl; cin >> n;
	// Matr_A
	Vector<Vector<int>> matrA(n, Vector<int>(n));

	// matr_B
	Vector<Vector<int>> matrB(n, Vector<int>(n));

	// Matr_result
	Vector<Vector<int>> matr(n, Vector<int>(n));

	inputMatr(matrA);
	
	cout << "Матрица А порядка N:" << endl;
	printMatr(matrA);

	inputMatr(matrB);
	cout << "Матрица B порядка N:" << endl;
	printMatr(matrB);

	// matr AB
	Vector<Vector<int>> matrAB(n, Vector<int>(n));

	cout << "Матрица AB порядка n:" << endl;
	multiMatr(matrA, matrB, n, matrAB);
	printMatr(matrAB);

	// matr BA  
	Vector<Vector<int>> matrBA(n, Vector<int>(n));

	

	cout << "Матрица BA порядка n:" << endl;
	multiMatr(matrB, matrA, n, matrBA);
	printMatr(matrBA);

	// sum matr
	cout << "Матрица C = AB + BA порядка n:" << endl;
    sumMatr(matrAB, matrBA, n, matr);
	printMatr(matr);

}

void inputMatr(Vector<Vector<int>>& matr) {
	srand(time(NULL));
	for (int i = 0; i < matr.size(); i++) {
		for (int j = 0; j < matr[i].size(); j++) {
			matr[i][j] = rand() % 10;
		}
	}
}

void printMatr(Vector<Vector<int>>& matr) {

	for (int i = 0; i < matr.size(); i++) {
		for (int j = 0; j < matr[i].size(); j++) {
			cout << setw(5) << matr[i][j];
		}
		cout << endl;
	}
}

Vector<Vector<int>> multiMatr(Vector<Vector<int>> &matrA, Vector<Vector<int>> &matrB, int n, Vector<Vector<int>> &matrAB) {

	for (int i = 0; i < matrAB.size(); i++) {
		for (int j = 0; j < matrAB[i].size(); j++) {
			int num = 0;
			for (int k = 0; k < n; k++) {
				num += matrA[i][k] * matrB[k][j];
			}
			matrAB[i][j] = num;
		}
	}
	return matrAB;
}
Vector<Vector<int>> sumMatr(Vector<Vector<int>> &matrAB, Vector<Vector<int>> &matrBA, int n, Vector<Vector<int>> &matr) {
	for (int i = 0; i < matr.size(); i++) {
		for (int j = 0; j < matr[i].size(); j++) {
			int num = matrAB[i][j] + matrBA[i][j];
			matr[i][j] = num;
		}
	}
	return matr;
}