#include"Header.h"

int main() {
	int n;
	cout << "Enter n:" << endl; cin >> n;
	List<int> l;
	for (int i = 0; i < 2*n; i++) {
		int num;
		cout << "Enter element for list:" << endl; cin >> num;
		l.push_back(num);
	}
	int result = 0; 
	for (int i = 0; i <  n; i++) {
		result += l[i] * l[2*n - i - 1];
	}
	cout << "result:" << endl;
	cout << result;
	
	
}