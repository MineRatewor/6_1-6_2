#include"Text.h"
int main() {
	List<int> l1;
	List<int> l2;

	int n;
	cout << "Input size l1:" << endl; cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cout << "Input element l1:" << endl; cin >> num;
		l1.push_back(num);
	}
	cout << "Input size l2:" << endl; cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cout << "Input element l2:" << endl; cin >> num;
		l2.push_back(num);
	}

	List<int> l;
	int size = l1.GetSize();
	for (int i = 0; i < size; i++) {
		int flag = 0;
		for (int j = 0; j < l2.GetSize(); j++) {
			if (l1[i] == l2[j]) {
				flag++;
			}
		}
		if (flag == 0) {
			l.push_back(l1[i]);
		}
	}

	for (int i = 0; i < l2.GetSize(); i++) {
		int flag = 0;
		for (int j = 0; j < l1.GetSize(); j++) {
			if (l2[i] == l1[j]) {
				flag++;
			}
		}
		if (flag == 0) {
			l.push_back(l2[i]);
		}
	}

	cout << "L1:" << endl; l1.print();
	cout << endl << "L2:" << endl; l2.print();
	cout << endl << "L:" << endl; l.print();
	
} 