#include<iostream>
#include<iomanip>
#include<forward_list>
using namespace std;

forward_list<int> getresult(forward_list<int>, forward_list<int>, forward_list<int>);
int main() {
	forward_list<int> l1;
	int n;
	cout << "Enter size for l1:" << endl; cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cout << "Enter num:" << endl; cin >> num;
		l1.push_front(num);
	}
	
	forward_list<int> l2;
	int k;
	cout << "Enter size for l2:" << endl; cin >> k;
	for (int i = 0; i < k; i++) {
		int num;
		cout << "Enter num:" << endl; cin >> num;
		l2.push_front(num);
	}

	forward_list<int> l = getresult(l1, l2, l);
	
	
	auto begin = l.begin();
	auto end = l.end();
	while (begin != end) {
		cout << setw(3) << *begin;
		begin++;
	}

}

forward_list<int> getresult(forward_list<int> l1, forward_list<int> l2, forward_list<int> l) {
	auto current_l1 = l1.begin();
	auto end_l1 = l1.end();
	while (current_l1 != end_l1) {
		int count = 0;
		int num = *current_l1;

		auto current_l2 = l2.begin();
		auto end_l2 = l2.end();

		while (current_l2 != end_l2) {
			int k = *current_l2;
			if (k == num) {
				count++;

			}
			current_l2++;
		}

		if (count == 0) {
			l.push_front(num);
		}
		current_l1++;
	}

	auto ptr_l2 = l2.begin();
	auto end_l2 = l2.end();
	while (ptr_l2 != end_l2) {
		int count = 0;
		int num = *ptr_l2;

		auto ptr_l1 = l1.begin();
		auto end_l1 = l1.end();
		while (ptr_l1 != end_l1) {
			int k = *ptr_l1;

			if (k == num) {
				count++;
			}
			ptr_l1++;
		}
		if (count == 0) {
			l.push_front(num);
		}
		ptr_l2++;
	}
	return l;
}