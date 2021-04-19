#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Student
{
public:
	Student(int id, char* name, char* last, int gender, int middle_grade, int test_grade);
	Student();
	~Student();
	friend ostream& operator<<(ostream& os, const Student& s);
	friend istream& operator>>(istream& is, Student& s);
	bool operator<(const Student& s) const;
	int Get_ID() { return id; }
	char* Get_FirstName() { return name; }
	char* Get_LastName()  { return last; }
	int Get_gender() { return gender; }
	int Get_Middle() { return middle_grade; }
	int Get_Test() { return test_grade; }
	double Get_FinalGrade()  { return final_grade; }
	

private:
	int id;
	char* name;
	char* last;
	int gender;
	int middle_grade;
	int test_grade;
	float final_grade;
	
};
#endif

