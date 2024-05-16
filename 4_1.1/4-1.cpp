
#include<iostream>
#include<iomanip>
using namespace std;

template<typename T>
class Vector {
private:
	T* arr;
	int s;
	int c;
public:
	Vector() {
		s = c = 0;
	}

	Vector(int num) {
		s = c = num;
		arr = new T[s];
	}

	Vector(const Vector& arr2) {
		s = arr2.s;
		c = arr2.c;
		T* tmp = new T[s];
		for (int i = 0; i < s; i++) {
			tmp[i] = arr2.arr[i];
		}
		delete[] arr;
		arr = tmp;

	}

	Vector& operator=(const Vector& arr2) {
		if (this != &arr2) {
			s = arr2.s;
			c = arr2.c;
			T* tmp = new T[s];
			for (int i = 0; i < s; i++) {
				tmp[i] = arr2.arr[i];
			}
			delete[]arr;
			arr = tmp;
		}
		return *this;
	}

	Vector(Vector&& arr2) : arr(arr2.arr),
		s(arr2.s),
		c(arr2.c) {
		s = arr2.s;
		c = arr2.c;
		T* tmp = new T[s];
		for (int i = 0; i < s; i++) {
			tmp[i] = arr2.arr[i];
		}
		delete[] arr;
		arr = tmp;
		arr2 = nullptr;
		arr2.s = 0;
		arr2.c = 0;
	}

	Vector& operator=(Vector&& arr2)
	{
		if (this != &arr2) {
			s = arr2.s;
			c = arr2.c;
			T* tmp = new T[s];
			for (int i = 0; i < s; i++) {
				tmp[i] = arr2.arr[i];
			}
			delete[] arr;
			arr = tmp;

			arr2.s = 0;
			arr2.c = 0;
		}
		return *this;
	}

	void new_allocation() {
		c = s + 5;
		T* temp = new T[c]();


		for (int i = 0; i < s; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;

	}
	void push_back(T element) {
		if (s == c) {
			new_allocation();
		}
		arr[s] = element;
		s++;
	}


	void pop_back() {
		if (s == 0) {
			cout << "Can't pop, because vector is empty!" << endl;
			return;
		}
		s--;
	}

	int size() {
		return s;
	}

	void insert(int index, T data) {
		if (s == c) {
			new_allocation();
		}
		s++;
		T* tmp = new T[s];
		int k = 0;
		for (int i = 0; i < s; i++) {
			if (i == index) {
				tmp[i] = data;
			}
			else {
				tmp[i] = arr[k];
				k++;
			}
		}
		delete[]arr;
		arr = tmp;
	}

	void pop(int index) {
		if (s == 0) {
			cout << "Can't pop, because vector is empty!" << endl;
			return;
		}
		s--;
		T* temp1 = new T[s];
		int k = 0;
		for (int i = 0; i < s; i++) {
			if (index == i) {
				k++;
			}
			temp1[i] = arr[k];
			k++;
		}
		delete[] arr;
		arr = temp1;

	}

	void print() {
		for (int i = 0; i < s; i++) {
			cout << setw(3) << arr[i];
		}
	}

	void clear() {
		s = c = 0;
		delete[] arr;
		arr = nullptr;
	}

	bool empty() {
		if (s == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	T& operator[](int index) {
		if (index < 0 or index > s) {
			cout << "Index out of range!";
		}
		return arr[index];
	}

	friend istream& operator >>(istream& fin, Vector<T>& arr2) {
		for (int i = 0; i < arr2.s; i++) {
			fin >> arr2.arr[i];
		}
		return fin;
	}
	friend ostream& operator <<(ostream& fout, const Vector<T>& arr2) {
		for (int i = 0; i < arr2.s; i++) {
			fout << arr2.arr[i];
		}
		return fout;
	}

	~Vector() {
		delete[] arr;
	}
};

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
	result.push_back(mass[0]);
	result.print();
	
	
}