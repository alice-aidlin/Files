
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include"Student.h"

Student::Student(int id, char* name, char* last, int gender, int middle_grade, int test_grade)//Ctor
{
	this->id = id;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name,name);
	this->last = new char[strlen(last) + 1];
	strcpy(this->last, last);
	this->gender = gender;
	this->middle_grade = middle_grade;
	this->test_grade = test_grade;
	this->final_grade = 0.2*middle_grade + 0.8*test_grade;
}

Student::Student()//Def Ctor
{
	 this->id = 0; 
	 this->name = NULL; 
	 this->last = NULL; 
	 this->gender = 0; 
	 this->middle_grade = 0; 
	 this->test_grade = 0;
	 this->final_grade = 0; 
}


Student::~Student()//Dtor
{
	
}

ostream& operator<<(ostream& os, const Student& s)//operator get
{
	os << "id: " << s.id << endl;
	os << "first name: " << s.name << endl;
	os<<"last name: "<< s.last << endl;
	if (s.gender == 0)
	os << "gender: Male" << endl;
	else os << "gender: Female" << endl;
	os << "middle grade: " << s.middle_grade << endl;
	os << "test grade: " << s.test_grade << endl;
	os << "final Grade: " << s.final_grade <<"\n"<< endl;
	return os;
}
istream& operator>>(istream& is, Student& s)//operatoe out
{
	int len, i;
	string buffer1,buffer2;
	is >> s.id;
	is >> buffer1;//to catch name
	s.name = new char[buffer1.length() + 1];
	for (int i = 0; i < buffer1.length(); ++i)
		s.name[i] = buffer1[i];
	s.name[buffer1.length()] = '\0';
	is>> buffer2;//to catch last name
	s.last = new char[buffer2.length() + 1];
	for (int i = 0; i < buffer2.length(); ++i)
		s.last[i] = buffer2[i];
	s.last[buffer2.length()] = '\0';
	is >> s.gender;
	is >> s.middle_grade;
	is >> s.test_grade;
	is>> s.final_grade;
	return is;
}

bool Student::operator<(const Student& s)const 
{
	int i = 0;
	
	if (strcmp(this->last,s.last) == 0)//if same last name
	{
		while (this->name[i]&&s.name[i])//check names
		{
			if (this->name[i] < s.name[i])//exempl:a<v
				return true;
			if (this->name[i] == s.name[i])//is same char (a=a) move on
				return ++i;
			else return false;//if a>v return false
		}
		if (strlen(this->name) < strlen(s.name))// if same name like "shir" and "shira" so the shorter smaller
			return true;
		else
			return false;
	}
	while (this->last[i]&&s.last[i])//if not same last name check last name
	{
		if (this->last[i] < s.last[i])
			return true;
		if (this->last[i] == s.last[i])
			++i;
		else
			return false;
	}
	if (strlen(this->last) < strlen(s.last))
		return true;
	else
		return false;
}


