#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

string binary(int );

int main() {
	Vector<int> result;
	int N;
	cout << "Enter N:" << endl; cin >> N;
	int num = 1;
	while (num <= N) {

		string s = binary(num);

		int count = 0;
		if (s.size() % 2 == 1 ) {
			num += 1;
			continue;
		}
		else {
			for (int i = s.size() - 1; i >= 0; i-=2) {
				if (s[i] != '1' or s[i - 1] != '0') {
					count++;
				}
			}
		}
		if (count == 0) {
			result.push_back(num);
		}
		num += 1;
	}
	
	cout << "Result:" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << setw(5) << result[i];
	}
}

string binary(int num)
{
	string result;
	while (num >= 1) {
		if (num % 2 == 0) {
			num /= 2;
			result += "0";
	   }
		else {
			num -= 1;
			num /= 2;
			result += "1";
	    }
	}

	return result;
}
