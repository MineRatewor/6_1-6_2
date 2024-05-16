#include<iostream>
#include<iomanip>
#include<list>
using namespace std;

int main() {
	int n;
	cout << "Enter n:" << endl; cin >> n;
	list<int> l;

	for (int i = 0; i < 2 * n; i++) {
		int num;
		cout << "Enter num for list:" << endl; cin >> num;
		l.push_back(num);
	}
	
	cout << "List:" << endl;

	auto ptr = l.begin();
	auto ptr_end = l.end();

	while (ptr != ptr_end) {
		cout << setw(3) << *ptr;
		ptr++;
	}
	cout << endl;

	int result = 0;

	auto current = l.begin();
	auto ptr_l = l.begin();
	auto end = l.end();
	end--;
	while (ptr_l != end) {
		ptr_l++;
	}
	

	for (int i = 0; i < n; i++) {
		int num1 = *current;
		int num2 = *ptr_l;
		result += num1 * num2;

		current++; ptr_l--;
	}

	cout << "Result:" << endl; cout << result;
}