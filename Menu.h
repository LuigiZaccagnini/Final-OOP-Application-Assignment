/* Citation and Sources...
Final Project Milestone 1
Module: Menu Filename: Menu.h
Version 1.0
Author Luigi Zaccagnini
Revision History
-----------------------------------------------------------
Preliminary release 2020/3/9
-----------------------------------------------------------
I have done all the coding by myself and only copied the code  that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

namespace sdds
{
	const int MAX_NO_OF_ITEMS = 10;

	class MenuItem
	{
		//Friend Classes
		friend class Menu;

		//Varibles
		char* m_itemName;

		//Functions
		MenuItem();
		MenuItem(const char* itemName);
		~MenuItem();
		ostream& display(int index, ostream& os = cout) const;
		MenuItem& operator=(const MenuItem& source) = delete;
		MenuItem(const MenuItem& source) = delete;
	};

	class Menu
	{
		char* m_title;
		MenuItem* m_menuItems[MAX_NO_OF_ITEMS];
		int m_numberOfItems = 0;
		int m_indentation = 0;

	public:
		//Constructor, Deconstructor, Copy constructor
		Menu();
		Menu(const char* title, int indentation = 0);
		~Menu();
		Menu(const Menu& source);

		//Operator Overload Functions
		Menu& operator=(const Menu& source);
		bool operator==(const Menu& source) { return source.isEmpty(); };
		operator bool() const { return !isEmpty(); };
		operator int() const { return run(); }; //Returns int from run function

		//Get information functions
		bool isEmpty() const; //Checks if menu is in a safe empty state.
		int run(istream& is = cin) const; //Gets user's input for the menu.
		ostream& display(ostream& os = cout, int indent = 0) const; //Prints the menu.

		//Set information functions
		void add(const char* itemName); //Adds menu items to menu.
		void setEmpty(); //sets object to a safe empty state
	};

	Menu& operator<<(Menu& menu, const char* itemName); //Works the same as add function
	void outputSpace(int space);
}

#endif 