#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

struct Student {
	char name[80]{};
	int course;
	int age;
	int perfomance;
};

void input(ofstream&, int );
void print(ifstream& , Student);
void createFile(ifstream&, ofstream&, Student, int);
void deleteStudent(ifstream&, ofstream&, Student, Student);
void addStudent(ofstream&);
void editingFile(ifstream&, ofstream&, Student, Student);

void main() {
	setlocale(LC_ALL, "RU");
	ofstream fout("Student.bin", ios::binary);
	int n;
	cout << "Input amount students:" << endl; cin >> n;
	if (!fout.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		input(fout, n);
	}
	fout.close();
	Student student{};
	ifstream fin("Student.bin", ios::binary);
	if (!fin.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		print(fin, student);
	}
	fin.close();
	Student person{};
	ifstream finfile("Student.bin", ios::binary);
	if (!finfile.is_open()) {
		cout << "Error!" << endl;
	}
	ofstream foutfile("newfile.bin", ios::binary);
	if (!foutfile.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		deleteStudent(finfile, foutfile, student, person);
	}
	remove("Student.bin");
	finfile.close();
	foutfile.close();
	
	ifstream finl1("newfile.bin", ios::binary);
	cout << endl<<  "NEW FILE" << endl;
	print(finl1,student);
	rename("newfile.bin", "Student.bin");
	finl1.close();

	//add student
	ofstream foutfile1("newfile.bin", ios::binary|ios::app);
	if (!foutfile1.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		cout << " Enter info about student, which you want to add:" << endl;
		addStudent(foutfile1);
	}
	foutfile1.close();
	ifstream finfile1("newfile.bin", ios::binary);
	if (!finfile1.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		cout << "File with new student!" << endl;
		cout << endl;
		print(finfile1, student);
	}
	finfile1.close();

	// editing student
	ifstream finfile3("newfile.bin", ios::binary);
	ofstream foutfile3("newfile1.bin", ios::binary);
	if (!foutfile3.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		editingFile(finfile3, foutfile3, student, person);
	}
	finfile3.close();
	foutfile3.close();
	//print
	ifstream foutfile4("newfile1.bin", ios::binary);
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
	ofstream fout1("GreatStudent.bin", ios::binary);
	if (!fout1.is_open()) {
		cout << "Error!";
	}
	ifstream fin1("newfile1.bin", ios::binary);
	if (!fin1.is_open()) {
		cout << "Error!";
	}
	else {
		createFile(fin1, fout1, student, Course);
	}
	fout1.close();
	fin1.close();

	ifstream fin2("GreatStudent.bin", ios::binary);
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
		/*for (int i = 0; i < strlen(Name); i++) {
			fout.write((char*)&Name[i], sizeof(char));
		}*/
		fout.write((char*)&Name, sizeof(char[80]));
		cout << "Course:" << endl;
		int course; cin >> course;
		fout.write((char*)&course, sizeof(int));
		cout << "Age:" << endl;
		int age; cin >> age;
		fout.write((char*)&age, sizeof(int));
		cout << "Perfomance:" << endl;
		int perfomance; cin >> perfomance;
		fout.write((char*)&perfomance, sizeof(int));
	
	}
}
void print(ifstream&fin, Student student) {
	fin.seekg(0, ios::beg);
	while (fin.read((char*)&student.name, sizeof(char[80]))) {
		cout << "Name:" << setw(3);
		for (int i = 0; i < strlen(student.name); i++) {
			cout << student.name[i];
		}
		cout << endl; 
		fin.read((char*)&student.course, sizeof(int));
		cout <<"corse:" << setw(3) << student.course << endl;
		
		fin.read((char*)&student.age, sizeof(int));
		cout << "age:"<< setw(3)<< student.age << endl;

		fin.read((char*)&student.perfomance, sizeof(int));
		cout << "perfomance:"<< setw(3)<< student.perfomance << endl;

		cout << endl;
	}
}
void createFile(ifstream&fin, ofstream&fout, Student student,int Course) {
	while (fin.read((char*)&student.name, sizeof(char[80]))) {
		fin.read((char*)&student.course, sizeof(int));
		fin.read((char*)&student.age, sizeof(int));
		fin.read((char*)&student.perfomance, sizeof(int));
		if (student.course == Course) {
			if (student.perfomance >= 7) {
				fout.write((char*)&student.name, sizeof(char[80]));
				fout.write((char*)&student.course, sizeof(int));
				fout.write((char*)&student.age, sizeof(int));
				fout.write((char*)&student.perfomance, sizeof(int));
			}
		}
	}
}
void deleteStudent(ifstream& fin, ofstream& fout, Student student, Student person) {
	cout << "Enter info about student, which you want to delete:" << endl;
	cout << "FIO:" << endl; cin.get(); cin.getline(person.name, 80);
	cout << "Course:" << endl; cin >> person.course;
	cout << "Age:" << endl; cin >> person.age;
	cout << "Perfomance:" << endl; cin >> person.perfomance;

	while (fin.read((char*)&student.name, sizeof(char[80]))) {
		fin.read((char*)&student.course, sizeof(int));
		fin.read((char*)&student.age, sizeof(int));
		fin.read((char*)&student.perfomance, sizeof(int));
		if (strlen(student.name) == strlen(person.name)) {
			int flag = 0;
			for (int i = 0; i < strlen(person.name); i++) {
				if (student.name[i] != person.name[i]) {
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
					fout.write((char*)&student.name, sizeof(char[80]));
					fout.write((char*)&student.course, sizeof(int));
					fout.write((char*)&student.age, sizeof(int));
					fout.write((char*)&student.perfomance, sizeof(int));
				}
			}
			else {
				fout.write((char*)&student.name, sizeof(char[80]));
				fout.write((char*)&student.course, sizeof(int));
				fout.write((char*)&student.age, sizeof(int));
				fout.write((char*)&student.perfomance, sizeof(int));
			}
		}
		else {
			fout.write((char*)&student.name, sizeof(char[80]));
			fout.write((char*)&student.course, sizeof(int));
			fout.write((char*)&student.age, sizeof(int));
			fout.write((char*)&student.perfomance, sizeof(int));
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
	
	
	fout.write((char*)&name, sizeof(char[80]));
	fout.write((char*)&course, sizeof(int));
	fout.write((char*)&age, sizeof(int));
	fout.write((char*)&perfomance, sizeof(int));

}

void editingFile(ifstream& fin, ofstream&fout, Student student, Student person) {
	cout << "Enter info about student, which you want to edit:" << endl;
	cout << "FIO:" << endl; cin.get(); cin.getline(person.name, 80);
	cout << "Course:" << endl; cin >> person.course;
	cout << "Age:" << endl; cin >> person.age;
	cout << "Perfomance:" << endl; cin >> person.perfomance;

	while (fin.read((char*)&student.name, sizeof(char[80]))) {
		fin.read((char*)&student.course, sizeof(int));
		fin.read((char*)&student.age, sizeof(int));
		fin.read((char*)&student.perfomance, sizeof(int));

		if (strlen(student.name) == strlen(person.name)) {
			int flag = 0;
			for (int i = 0; i < strlen(person.name); i++) {
				if (student.name[i] != person.name[i]) {
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

					fout.write((char*)&person.name, sizeof(char[80]));
					fout.write((char*)&person.course, sizeof(int));
					fout.write((char*)&person.age, sizeof(int));
					fout.write((char*)&person.perfomance, sizeof(int));
				}
				else {
					fout.write((char*)&student.name, sizeof(char[80]));
					fout.write((char*)&student.course, sizeof(int));
					fout.write((char*)&student.age, sizeof(int));
					fout.write((char*)&student.perfomance, sizeof(int));
				}
			}
			else {
				fout.write((char*)&student.name, sizeof(char[80]));
				fout.write((char*)&student.course, sizeof(int));
				fout.write((char*)&student.age, sizeof(int));
				fout.write((char*)&student.perfomance, sizeof(int));
			}
		}
		else {
			fout.write((char*)&student.name, sizeof(char[80]));
			fout.write((char*)&student.course, sizeof(int));
			fout.write((char*)&student.age, sizeof(int));
			fout.write((char*)&student.perfomance, sizeof(int));
		}
	}
}
