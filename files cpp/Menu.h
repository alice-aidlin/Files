#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef MENU_H
#define MENU_H
#include<iostream>
#include<fstream>
#include<string>
#include"Student.h"
using namespace std;
class Menu
{
public:
	Menu();
	~Menu();
	void main_menu();
	void sort();
	void avege();
	

	
private:
	Student* arr_students=NULL;
	
	
};
#endif

