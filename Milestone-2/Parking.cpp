/* Citation and Sources...
Final Project Milestone 2
Module: Menu Filename: parking.cpp
Version 1.0
Author Luigi Zaccagnini
Revision History
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Preliminary release 2020/3/9
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
I have done all the coding by myself and only copied the code  that my professor provided to complete my workshops and assignments.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string.h>
#include "Menu.h"
#include "Parking.h"
using namespace std;

namespace sdds
{

	Parking::Parking()
	{
		setEmpty();
	}

	Parking::Parking(const char* path)
	{
		setEmpty();

		if (path != nullptr && path[0] != '\0')
		{
			m_path = string(path);

			if (loadData())
			{
				m_parkingMenu = Menu("Parking Menu, select an action:");
				m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";

				m_vehicleMenu = Menu("Select type of the vehicle :", 1);
				m_vehicleMenu << "Car" << "Motorcycle" << "Cancel";
			}
		}

		else
		{
			cout << "Error in data file" << endl;
		}
	}

	Parking::~Parking()
	{
		saveData();
	}

	int Parking::run()
	{
		int input = 0;
		bool exit = false;

		if (!isEmpty())
		{
			do
			{
				parkingStatus();
				input = m_parkingMenu.run();

				if (input == 1)
				{
					parkVehicle();
				}

				else if (input == 2)
				{
					getVehicle();
				}

				else if (input == 3)
				{
					listParkedVehicles();
				}

				else if (input == 4 && closeParking())
				{
					exit = true;
				}

				else if (input == 5 && exitParkingApp())
				{
					exit = true;
				}

				cin.clear();
				cin.ignore(1000, '\n');

			} while (!exit);

			input = 0;
		}

		else
		{
			input = 1;
		}

		return input;
	}

	bool Parking::isEmpty() const
	{
		bool empty = true;

		if (!m_path.empty() && m_path[0] != '\0')
		{
			empty = false;
		}

		return empty;
	}

	void Parking::setEmpty()
	{
		m_path = '\0';
	}

	void Parking::parkingStatus() const
	{
		cout << "****** Seneca Valet Parking ******" << endl;
	}

	void Parking::parkVehicle() const
	{
		int input = 0;

		input = m_vehicleMenu.run();

		if (input == 1)
		{
			cout << "Parking Car" << endl;
		}

		else if (input == 2)
		{
			cout << "Parking Motorcycle" << endl;
		}

		else if (input == 3)
		{
			cout << "Cancelled parking" << endl;
		}
	}

	void Parking::getVehicle() const
	{
		cout << "Returning Vehicle" << endl;
	}

	void Parking::listParkedVehicles() const
	{
		cout << "Listing Parked Vehicles" << endl;
	}

	bool Parking::closeParking() const
	{
		cout << "Closing Parking" << endl;
		return true;
	}

	bool Parking::exitParkingApp() const
	{
		string input;
		char inputFirstChar = '\0';
		bool flag = false;

		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";

		do
		{
			cin >> input;
			inputFirstChar = tolower(input[0]);

			if (inputFirstChar != 'y' && inputFirstChar != 'n' || input.length() != 1)
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}

			else { flag = true; }

			cin.clear();
			cin.ignore(1000, '\n');

		} while (!flag);

		return flag;
	}

	bool Parking::loadData() const
	{
		bool error = false;

		if (!isEmpty())
		{
			cout << "loading data from " << m_path << endl;
			error = true;
		}

		return error;
	}

	void Parking::saveData()
	{
		if (!isEmpty())
		{
			cout << "Saving data into " << m_path << endl;
		}
	}
}