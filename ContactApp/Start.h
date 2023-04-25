#pragma once
#include<iostream>
#include "Entities.h"
#include "Functions.h"
using namespace std;

void ShowMenu() {
	cout << "Show All Contacts     [1]" << endl;
	cout << "Add New Contact       [2]" << endl;
	cout << "Delete Contact        [3]" << endl;
	cout << "Search Contact        [4]" << endl;
	cout << "Sorted Contacts A-Z   [5]" << endl;
	cout << "Sorted Contacts Z-A   [6]" << endl;
}

void Start() {

	Human* h1 = new Human{
		new char[20]{"John"},
		new char[20]{"+99455211111"},
		__DATE__
	};
	Human* h2 = new Human{
		new char[20] {"Aydin"},
		new char[20] {"+994514222222"},
		__DATE__
	};
	Human* h3 = new Human{
		new char[20] {"Leyla"},
		new char[20] {"+994514225522"},
		__DATE__
	};
	Human* h4 = new Human{
		new char[20] {"Akif"},
		new char[20] {"+994515487963"},
		__DATE__
	};

	auto humans = new Human * [4]{ h1,h2,h3,h4 };
	Contact* contact = new Contact{ humans,4 };

	while (true)
	{
		ShowMenu();
		int select = 0;
		cin >> select;
		
		system("cls");
		if (select == 1) {
			ShowAll(*contact);
		}
		else if (select == 2) {
			Human* item = getNewHuman();
			AddNewHuman(*contact, *item);
		}
		else if (select == 3) {
			cin.ignore();
			cin.clear();
			ShowAll(*contact);
			cout << endl << endl << endl;
			cout << "Enter Human ID : ";
			int no = 0;
			cin >> no;
			if (no >= 1 && no <= contact->count) {
				int index = no - 1;
				DeleteHuman(*contact, index);
			}
		}
		else if (select == 4) {
			cin.ignore();
			cin.clear();
			cout << "Enter Human name : ";
			char* name = new char[30] {};
			cin.getline(name,30);
			SearchHuman(*contact,name);
		}
		else if (select == 5) {
			SortAZ(*contact);
			system("cls");
			ShowAll(*contact);
		}
		else if (select == 6) {
			SortAZ(*contact,true);
			system("cls");
			ShowAll(*contact);
		}
	}


}