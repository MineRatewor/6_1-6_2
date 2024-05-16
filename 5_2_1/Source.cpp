#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;


void main() {
	setlocale(LC_ALL, "RU");
	int N;
	cout << "Пожалуйста,введите максимательное число последовательности(N < 10^4):" << endl; cin >> N;
	while (N > pow(10, 4)) {
		cout << "Пожалуйста,введите максимательное число последовательности(N < 10^4):" << endl; cin >> N;
	}
	Vector<int> mass;
	for (int i = 0; i < N; i++) mass.push_back(0);

	int n;
	cout << "Пожалуйста, введите длину последовательности(n <= 10^9):" << endl; cin >> n;
	while (n > pow(10, 9)) {
		cout << "Пожалуйста, введите длину последовательности(n <= 10^9):" << endl;
		cin >> n;
	}
	for (int i = 0; i < n; i++) {
		int num;
		cout << "Пожалуйста, введите число последовательности:" << endl; cin >> num;
		int j = num;
		if (mass[j] == 0) {
			mass[j] = 1;
			continue;
		}
		if (mass[j] == 1) {
			mass[j] = 2;
		}
	}
	

	Vector<int> result;
	
	for (int i = mass.size() - 1; i >= 0; i--) {
		if (mass[i] == 2) {
			result.push_back(i);
		}
	}

	cout << "Ваш итоговый массив:" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << setw(3) << result[i];
	}

}