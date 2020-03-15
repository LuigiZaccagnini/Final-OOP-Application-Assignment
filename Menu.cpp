/* Citation and Sources...
Final Project Milestone 1
Module: Menu Filename: Menu.cpp
Version 1.0
Author Luigi Zaccagnini
Revision History
-----------------------------------------------------------
Preliminary release 2020/3/9
-----------------------------------------------------------
I have done all the coding by myself and only copied the code  that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iostream> 
#include <iomanip>
#include <string.h>
#include "Menu.h"
using namespace std;

namespace sdds
{
	Menu::Menu()
	{
		m_title = nullptr;
		m_indentation = 0;
		m_numberOfItems = 0;

		for (int i = 0; i < MAX_NO_OF_ITEMS; i++)
		{
			m_menuItems[i] = nullptr;
		}
	}

	Menu::Menu(const char* title, int indentation)
	{
		if (title != nullptr && title[0] != '\0')
		{
			string temp = string(title);
			m_title = new char[temp.length() + 1];
			strcpy(m_title, title);

			m_indentation = indentation * 4;

			for (int i = 0; i < MAX_NO_OF_ITEMS; i++)
			{
				m_menuItems[i] = nullptr;
			}
		}

		else { setEmpty(); }
	}

	Menu::~Menu()
	{
		int i = 0;

		delete[] m_title;
		m_title = nullptr;

		for (i = 0; i < m_numberOfItems; i++)
		{
			delete m_menuItems[i];
			m_menuItems[i] = nullptr;
		}
	}

	Menu::Menu(const Menu& source)
	{
		int i = 0;

		if (source.m_title != nullptr)
		{
			string temp = string(source.m_title);
			m_title = new char[temp.length() + 1];
			strcpy(m_title, source.m_title);

			m_indentation = source.m_indentation;
			m_numberOfItems = source.m_numberOfItems;

			for (i = 0; i < m_numberOfItems; i++)
			{
				m_menuItems[i] = new MenuItem(source.m_menuItems[i]->m_itemName);
			}
		}

		else { setEmpty(); }
	}

	int Menu::run(istream& is) const
	{
		int userInput = 0;

		if (m_numberOfItems > 0)
		{
			display();
			cout << "> ";
			is >> userInput;

			while (userInput == 0)
			{
				is >> userInput;

				if (!cin.good())
				{
					cout << "Invalid Integer, try again: ";
					userInput = 0;
					is.clear();
					is.ignore(1000, '\n');
				}

				else if (userInput <= 0 || userInput > m_numberOfItems)
				{
					cout << "Invalid selection, try again: ";
					userInput = 0;
				}

			}
		}

		else
		{
			display();
		}

		return userInput;
	}

	bool Menu::isEmpty() const
	{
		bool empty = false;

		if (m_title == nullptr || m_indentation == -1)
		{
			empty = true;
		}

		return empty;
	}

	void Menu::setEmpty()
	{
		int i = 0;

		if (m_title != nullptr)
		{
			delete[] m_title;
			m_title = nullptr;
		}

		if (m_menuItems[0] != nullptr)
		{
			for (i = 0; i < m_numberOfItems; i++)
			{
				delete m_menuItems[i];
				m_menuItems[i] = nullptr;
			}
		}

		for (i = 0; i < m_numberOfItems; i++)
		{
			m_menuItems[i] = nullptr;
		}

		m_title = nullptr;
		m_indentation = -1;
		m_numberOfItems = 0;
	}

	void Menu::add(const char* itemName)
	{
		if (itemName != nullptr && m_numberOfItems < 10 && !isEmpty())
		{
			m_numberOfItems++;
			m_menuItems[m_numberOfItems - 1] = new MenuItem(itemName);
		}

		else if (itemName == nullptr || itemName[0] == '\0')
		{
			setEmpty();
		}
	}

	Menu& operator<<(Menu& menu, const char* itemName)
	{
		menu.add(itemName);
		return menu;
	}

	Menu& Menu::operator=(const Menu& source)
	{
		setEmpty();

		if (source.m_title != nullptr && source.m_title[0] != '\0')
		{
			string temp = string(source.m_title);
			m_title = new char[temp.length() + 1];
			strcpy(m_title, source.m_title);
		}

		if (m_menuItems[0] != nullptr)
		{
			for (int i = 0; i < m_numberOfItems; i++)
			{
				delete[] m_menuItems[i];
				m_menuItems[i] = nullptr;
			}
		}

		m_indentation = source.m_indentation;
		m_numberOfItems = source.m_numberOfItems;

		if (source.m_menuItems[0] != nullptr)
		{
			for (int i = 0; i < source.m_numberOfItems; i++)
			{
				m_menuItems[i] = new MenuItem(source.m_menuItems[i]->m_itemName);
			}
		}

		return *this;
	}

	ostream& Menu::display(ostream& os, int indent) const
	{
		int i = 0;

		if (isEmpty())
		{
			os << "Invalid Menu!" << endl;
		}

		else if (m_numberOfItems == 0)
		{
			outputSpace(m_indentation);
			os << m_title << endl;
			os << "No Items to display!" << endl;
		}

		else
		{
			outputSpace(m_indentation);
			os << m_title << endl;

			for (i = 0; i < m_numberOfItems; i++)
			{
				outputSpace(m_indentation);
				m_menuItems[i]->display(i);
			}
		}

		return os;
	}

	void outputSpace(int space)
	{
		int i = 0;

		for(i = 0; i <= space; i++)
		{
			cout << ' ';
		}
	}

	MenuItem::MenuItem()
	{
		m_itemName = nullptr;
	}

	MenuItem::MenuItem(const char* itemName)
	{
		m_itemName = nullptr;

		if (itemName != nullptr)
		{
			string temp = string(itemName);
			m_itemName = new char[temp.length() + 1];
			strcpy(m_itemName, itemName);
		}
	}

	MenuItem::~MenuItem()
	{
		if (m_itemName != nullptr)
		{
			delete[] m_itemName;
			m_itemName = nullptr;
		}
	}

	ostream& MenuItem::display(int index, ostream& os) const
	{
		return os << index + 1 << "- " << m_itemName << endl;
	}
}