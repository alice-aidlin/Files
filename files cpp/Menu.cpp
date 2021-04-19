#include "Menu.h"
#include<fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

Menu::Menu()
{
	int len_name, len_last;
	int s_id, s_gender, s_middle, s_exeme;
	char* s_name;
	char* s_last;
	int number_students;
	cout << "enter number of students you want to add\n";
	cin >> number_students;
	ofstream file;
	file.open("students.data");//open file
	if (!file)//if not open
	{
		cout << "error, file not open" << endl;
		return;
	}
	file << number_students << " ";//write to file

	this->arr_students = new Student[number_students];//alloc arr stdents

	for (int i = 0; i < number_students; ++i)
	{
		cout << "\nenter id: ";
		cin >> s_id;
		while (s_id < 1000 || s_id > 9999)//4 digit id
		{
			cout << "4 digit id! try again: ";
			cin >> s_id;
		}
		cout << "\nnum of letters of first name: ";
		cin >> len_name;
		s_name = new char[len_name + 1];
		cout << "\nenter first name: ";
		cin >> s_name;
		cout << "\nnum of letters of last name: ";
		cin >> len_last;
		s_last = new char[len_last + 1];
		cout << "\nenter last name: ";
		cin >> s_last;
		cout << "\nenter gender, 0 for men, 1 for women: ";
		cin >> s_gender;
		cout << "\nenter middle test grade: ";
		cin >> s_middle;
		cout << "\nenter test grade: ";
		cin >> s_exeme;
		cout << "\n";
		this->arr_students[i] = Student::Student(s_id, s_name, s_last, s_gender, s_middle, s_exeme);//create new student
		//write to file
		file << arr_students[i].Get_ID() << " ";
		file << arr_students[i].Get_FirstName() << " ";
		file << arr_students[i].Get_LastName() << " ";
		file << arr_students[i].Get_gender() << " ";
		file << arr_students[i].Get_Middle() << " ";
		file << arr_students[i].Get_Test() << " ";
		file << arr_students[i].Get_FinalGrade() << " ";
	}
	file.close();

	main_menu();
}

Menu::~Menu()
{
}

void Menu::main_menu()
{
	int choice, check = 0;
	do
	{
		cout << "\nchoose:\n1.print to screen from file\n2.sort students and write to new file\n3.print all grades and average\n4.exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			int x;
			cout << "from which file you want to read?\n1.original file\n2.sort file" << endl;
			cin >> x;
			if (x == 1)
			{
				ifstream file;
				int number_students;
				file.open("students.data"); // open file
				if (!file)
				{
					cout << "error, file not open" << endl;
					return;
				}
				file >> number_students;//get number of student from file
				this->arr_students = new Student[number_students]; // allocate student array based on size
				for (int i = 0; i < number_students; i++)
				{
					file >> arr_students[i]; // first get the student then print it 
					cout << arr_students[i];
				}
				file.close(); // close file
			}
			else if (check == 0)//if student not sorted
				cout << "file not exist" << endl;
			else
			{
				ifstream file;
				int number_students;
				file.open("studentsAsc.data");
				if (!file)
				{
					cout << "error, file not open" << endl;
					return;
				}
				file >> number_students; // get size
				this->arr_students = new Student[number_students]; // allocate arr
				for (int i = 0; i < number_students; i++) {
					file >> arr_students[i]; // first get the student then print it
					cout << arr_students[i];
				}
				file.close(); // close file
			}

			break;
		case 2:
			check = 1;//check for print if student has been sorted
			sort();
			cout << "\n";
			break;
		case 3:
			avege();
			cout << "\n";
			break;
		case 4:
			cout << "goodbey\n";
			break;

		default:
			cout << "bad input, try again\n";
			break;
		}
	} while (choice != 4);


}

void Menu::sort()

{
	ifstream file;
	file.open("students.data");
	int number_students;
	file >> number_students;
	this->arr_students = new Student[number_students];
	for (int i = 0; i < number_students; i++)
		file >> arr_students[i]; // read the students from the file
	
	for (int i = 0; i < number_students; ++i)//bubble sort
	{
		for (int j = 0; j < number_students - i - 1; ++j)
		{
			if (!(arr_students[j] < arr_students[j + 1])) //if operator "<" return false
			{
				Student temp = arr_students[j];
				arr_students[j] =arr_students[j + 1];
				arr_students[j + 1] = temp;
			}
		}
	}
	

	ofstream sort_file; //write the sorted arr to new file
	sort_file.open("studentsAsc.data"); // open file
	sort_file << number_students << " "; // write size first
	for (int i = 0; i < number_students; i++) { // writes students
		sort_file << arr_students[i].Get_ID() << " ";
		sort_file << arr_students[i].Get_FirstName() << " ";
		sort_file << arr_students[i].Get_LastName() << " ";
		sort_file << arr_students[i].Get_gender() << " ";
		sort_file << arr_students[i].Get_Middle() << " ";
		sort_file << arr_students[i].Get_Test() << " ";
		sort_file << arr_students[i].Get_FinalGrade() << " ";
	}
	file.close(); // close both files
	sort_file.close();
	cout << "Students sorted succesfully! " << endl;
}


void Menu::avege() {
	ifstream file;
	int number_students;
	double sum = 0;
	file.open("students.data"); // open file
	file >> number_students; // get size
	this->arr_students = new Student[number_students];
	for (int i = 0; i < number_students; i++) {
		file >> arr_students[i]; // get student from file
		cout << "First Name: " << arr_students[i].Get_FirstName() << endl;
		cout << "Last Name: " << arr_students[i].Get_LastName() << endl;
		cout << "Final Grade: " << arr_students[i].Get_FinalGrade() << endl << endl;
		sum += this->arr_students[i].Get_FinalGrade(); // add grade of each student
	}
	cout << "The average grade of all students is: " << sum / number_students << endl; // all grades divide by amount of students
	file.close(); // close file
}