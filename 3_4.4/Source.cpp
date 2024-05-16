#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

struct Student {
	char name[80]{};
	int course;
	int age;
	int perfomance;
};

void input(ofstream&, int);
void print(ifstream&, Student);
void deleteStudent(ifstream&, ofstream&, Student, Student);
void addStudent(ofstream&);
void editingFile(ifstream&, ofstream&, Student, Student);
void createFile(ifstream&, ofstream&, Student, int);

int main() {

	ofstream fout("Student.txt"); 
    int n;
	cout << "Enter amount students:" << endl; cin >> n;
	if (!fout.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		input(fout, n);
	}
	fout.close();
	Student student{};
	ifstream fin("Student.txt");
	if (!fin.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		print(fin, student);
	}
	fin.close();
	//delete student
	Student person{};
	ifstream finfile("Student.txt");
	if (!finfile.is_open()) {
		cout << "Error!" << endl;
	}
	ofstream foutfile("newfile.txt");
	if (!foutfile.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		deleteStudent(finfile, foutfile, student, person);
	}
	remove("Student.txt");
	finfile.close();
	foutfile.close();

	ifstream finl1("newfile.txt");
	cout << endl << "NEW FILE" << endl;
	print(finl1, student);
	rename("newfile.txt", "Student.txt");
	finl1.close();
	//add student

	ofstream foutfile1("newfile.txt",  ios::app);
	if (!foutfile1.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		cout << " Enter info about student, which you want to add:" << endl;
		addStudent(foutfile1);
	}
	foutfile1.close();
	ifstream finfile1("newfile.txt");
	if (!finfile1.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		cout << "File with new student!" << endl;
		cout << endl;
		print(finfile1, student);
	}
	finfile1.close();
	//editting student
	ifstream finfile3("newfile.txt", ios::binary);
	ofstream foutfile3("newfile1.txt", ios::binary);
	if (!foutfile3.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		editingFile(finfile3, foutfile3, student, person);
	}
	finfile3.close();
	foutfile3.close();
	//print
	ifstream foutfile4("newfile1.txt", ios::binary);
	if (!foutfile4.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		cout << "File after editing!" << endl;
		cout << endl;
		print(foutfile4, student);
	}
	foutfile4.close();
	int Course;
	cout << "Please, enter the course:" << endl; cin >> Course;
	ofstream fout1("GreatStudent.txt");
	if (!fout1.is_open()) {
		cout << "Error!";
	}
	ifstream fin1("newfile1.txt");
	if (!fin1.is_open()) {
		cout << "Error!";
	}
	else {
		createFile(fin1, fout1, student, Course);
	}
	fout1.close();
	fin1.close();

	ifstream fin2("GreatStudent.txt");
	if (!fin2.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		cout << "Excellent students:" << endl;
		cout << endl;
		print(fin2, student);
	}
	fin2.close();
}

void input(ofstream& fout, int n) {
	for (int i = 0; i < n; i++) {
		cout << "FIO:" << endl;
		cin.get();
		char Name[80]{}; cin.getline(Name, 80);
		fout << Name; fout << endl;
		cout << "Course:" << endl;
		int course; cin >> course;
		fout << course; fout << endl;
		cout << "Age:" << endl;
		int age; cin >> age;
		fout << age; fout << endl;
		cout << "Perfomance:" << endl;
		int perfomance; cin >> perfomance;
		fout << perfomance; fout << endl;

	}
}

void print(ifstream& fin, Student student) {
	fin.seekg(0, ios::beg); 
	while (fin >> student.name) {
		cout << "Name:" << setw(3);
		for (int i = 0; i < strlen(student.name); i++) {
			cout << student.name[i];
		}
		cout << setw(3);
		fin >> student.name;
		for (int i = 0; i < strlen(student.name); i++) {
			cout << student.name[i];
		}
		cout << endl;
		fin >> student.course;
		cout << "corse:" << setw(3) << student.course << endl;

		fin >> student.age;
		cout << "age:" << setw(3) << student.age << endl;

		fin >> student.perfomance;
		cout << "perfomance:" << setw(3) << student.perfomance << endl;

		cout << endl;
	}
}

void deleteStudent(ifstream& fin, ofstream& fout, Student student, Student person) {
	cout << "Enter info about student, which you want to delete:" << endl;
	cout << "FIO:" << endl; cin.get(); cin.getline(person.name, 80);
	cout << "Course:" << endl; cin >> person.course;
	cout << "Age:" << endl; cin >> person.age;
	cout << "Perfomance:" << endl; cin >> person.perfomance;

	while (fin >> student.name) {
		char name[80]{};
		for (int i = 0; i < strlen(student.name); i++) {
			name[i] = student.name[i];
		}
		name[strlen(name)] = ' ';
		fin >> student.name;
		int k = strlen(name);
		for (int i = 0; i < strlen(student.name); i++) {
			name[k] = student.name[i]; k++;
		}
	    fin >> student.course;
		 fin >> student.age;
		 fin >> student.perfomance;
		if (strlen(name) == strlen(person.name)) {
			int flag = 0;
			for (int i = 0; i < strlen(person.name); i++) {
				if (name[i] != person.name[i]) {
					flag++;
					break;
				}
			}
			if (flag == 0) {
				if (person.course == student.course and
					person.age == student.age and person.perfomance == student.perfomance) {
					continue;
				}
				else {
					fout << name << endl;
					 fout << student.course << endl;
					 fout << student.age << endl;
					 fout << student.perfomance << endl;
				}
			}
			else {
				fout << name << endl;
				fout << student.course << endl;
				fout << student.age << endl;
				fout << student.perfomance << endl;
			}
		}
		else {
			fout << name << endl;
			fout << student.course << endl;
			fout << student.age << endl;
			fout << student.perfomance << endl;
		}
	}
}

void addStudent(ofstream& fout) {
	cout << "FIO:" << endl;
	char name[80]{}; cin.get(); cin.getline(name, 80);
	cout << "Course:" << endl;
	int course; cin >> course;
	cout << "Age:" << endl;
	int age; cin >> age;
	cout << "Perfomance:" << endl;
	int perfomance; cin >> perfomance;
	int count = 0;


	 fout << endl << name << endl;
	 fout << course << endl;
	 fout << age << endl;
	 fout << perfomance << endl;

}

void editingFile(ifstream& fin, ofstream& fout, Student student, Student person) {
	cout << "Enter info about student, which you want to edit:" << endl;
	cout << "FIO:" << endl; cin.get(); cin.getline(person.name, 80);
	cout << "Course:" << endl; cin >> person.course;
	cout << "Age:" << endl; cin >> person.age;
	cout << "Perfomance:" << endl; cin >> person.perfomance;

	while (fin >> student.name) {
		char name[80]{};
		for (int i = 0; i < strlen(student.name); i++) {
			name[i] = student.name[i];
		}
		name[strlen(name)] = ' ';
		fin >> student.name;
		int k = strlen(name);
		for (int i = 0; i < strlen(student.name); i++) {
			name[k] = student.name[i]; k++;
		}
		fin >> student.course;
		fin >> student.age;
		fin >> student.perfomance;

		if (strlen(name) == strlen(person.name)) {
			int flag = 0;
			for (int i = 0; i < strlen(person.name); i++) {
				if (name[i] != person.name[i]) {
					flag++;
					break;
				}
			}
			if (flag == 0) {
				if (person.course == student.course and
					person.age == student.age and person.perfomance == student.perfomance) {
					cout << "Enter new info about student:" << endl;
					cout << "FIO:" << endl; cin.get(); cin.getline(person.name, 80);
					cout << "Course:" << endl; cin >> person.course;
					cout << "Age:" << endl; cin >> person.age;
					cout << "Perfomance:" << endl; cin >> person.perfomance;

					fout << person.name << endl;
					fout << person.course << endl;
					fout << person.age << endl;
					fout << person.perfomance << endl;
				}
				else {
					fout << name << endl;
					fout << student.course << endl;
					fout << student.age << endl;
					fout << student.perfomance << endl;

				}
			}
			else {
				fout << name << endl;
				fout << student.course << endl;
				fout << student.age << endl;
				fout << student.perfomance << endl;
			}
		}
		else {
			fout << name << endl;
			fout << student.course << endl;
			fout << student.age << endl;
			fout << student.perfomance << endl;
		}
	}
}

void createFile(ifstream& fin, ofstream& fout, Student student, int Course) {
	while (fin >> student.name) {
		char name[80]{};
		for (int i = 0; i < strlen(student.name); i++) {
			name[i] = student.name[i];
		}
		name[strlen(name)] = ' ';
		fin >> student.name;
		int k = strlen(name);
		for (int i = 0; i < strlen(student.name); i++) {
			name[k] = student.name[i]; k++;
		}
		fin >> student.course;
		fin >> student.age;
		fin >> student.perfomance;
		if (student.course == Course) {
			if (student.perfomance >= 7) {
				fout << name << endl;
				fout << student.course << endl;
				fout << student.age << endl;
				fout << student.perfomance << endl;
			}
		}
	}
}