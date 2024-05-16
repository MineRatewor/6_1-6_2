#include"BinaryTree.h"

int main() {
	Tree<int> s(5);
	s.insert(4);
	s.insert(3);
	s.insert(7);
	s.insert(8);
	s.insert(1);
	s.insert(10);
	s.insert(5);
	s.insert(6);
	s.insert(12);
	s.insert(9);
	s.insert(14);
	s.insert(6);
	s.insert(19);
	s.print();
	cout << endl;
	s.maxLevel();
}