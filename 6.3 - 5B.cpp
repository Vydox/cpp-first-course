#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct students {
    string name;
    int age;
    char sex;
    int course;
    double grades;
};

void create(ofstream& all_stud_in, int n);
void read(ifstream& all_stud_out);
void newfile(ofstream& new_file, ifstream& all_stud_out, int n, int c);

int main()
{
	int n;
	cout << "Enter number of students: ";
	cin >> n;
	cout << endl;
	

	ofstream all_stud_in("students.bin", ios::binary);
	if (!all_stud_in)
	{
		cout << "error1" << endl;
		return 1;
	}

	create(all_stud_in, n); //Стварэнне файла з усімі студэнтамі
	all_stud_in.close();

	ifstream all_stud_out("students.bin", ios::binary);
	read(all_stud_out); //Вывад файла на экран
	all_stud_out.close();

	int c;
	cout << "Enter course: ";
	cin >> c;

	ofstream new_file("right_students.bin", ios::binary);
	all_stud_out.open("students.bin");
	newfile(new_file, all_stud_out, n, c);
	all_stud_out.close();
	new_file.close();

	ifstream new_out("right_students.bin", ios::binary);
	read(new_out);
	new_out.close();


	return 0;
}

void create(ofstream& all_stud_in, int n) {
	students student;
	for (int i = 1; i <= n; i++) {
		cin.get();
		cout << "Enter name: ";
		getline(cin, student.name);
		//all_stud.write(reinterpret_cast <char*>(&student.name), sizeof(student.name));

		cout << "Enter age: ";
		cin >> student.age;
		//all_stud.write(reinterpret_cast <char*>(&student.age), sizeof(student.age));

		cout << "Enter sex (M or F): ";
		cin >> student.sex;
		//all_stud.write(reinterpret_cast <char*>(&student.sex), sizeof(student.sex));

		cout << "Enter course: ";
		cin >> student.course;
		//all_stud.write(reinterpret_cast <char*>(&student.course), sizeof(student.course));

		cout << "Enter grades: ";
		cin >> student.grades;

		all_stud_in.write(reinterpret_cast <char*>(&student), sizeof(student));

		cout << endl;
	}
}

void read(ifstream& all_stud_out) {
	students student;
	all_stud_out.read(reinterpret_cast<char*>(&student), sizeof(student));
	while (!all_stud_out.eof())
	{
		cout << student.name << " " << student.age << " " << student.sex << " " << student.course << " " << student.grades << endl;
		all_stud_out.read(reinterpret_cast<char*>(&student), sizeof(student));
	}
}

void newfile(ofstream& new_file, ifstream& all_stud_out, int n, int c)
{
	students student;
	all_stud_out.seekg(0);
	all_stud_out.read(reinterpret_cast<char*>(&student), sizeof(student));
	while (!all_stud_out.eof())
	{
		if (student.course == c)
		{
			new_file.write(reinterpret_cast<char*>(&student), sizeof(student));
			cout << student.name << " " << student.age << " " << student.sex << " " << student.course << " " << student.grades << endl;
		}
		all_stud_out.read(reinterpret_cast<char*>(&student), sizeof(student));
	}
}