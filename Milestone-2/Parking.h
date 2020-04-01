/* Citation and Sources...
Final Project Milestone 2
Module: Menu Filename: parking.h
Version 1.0
Author Luigi Zaccagnini
Revision History
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Preliminary release 2020/3/9
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
I have done all the coding by myself and only copied the code  that my professor provided to complete my workshops and assignments.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Menu.h"
using namespace std;

#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__

namespace sdds
{
	class Parking
	{
		string m_path;
		Menu m_parkingMenu;
		Menu m_vehicleMenu;

		bool isEmpty() const;
		void parkingStatus() const;
		void parkVehicle() const; //Displays submenu vehicle selection menu
		void getVehicle() const;
		void listParkedVehicles() const;
		bool closeParking() const;
		bool exitParkingApp() const;
		bool loadData() const;
		void saveData();

		//write functions
		void setEmpty();

	public:

		Parking();
		Parking(const char* path);
		~Parking(); 
		Parking(const Parking& source) = delete;
		Parking& operator=(const Parking& source) = delete;

		//read functions
		int run();
		
	};
}

#endif 