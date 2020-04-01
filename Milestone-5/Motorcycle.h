/* Citation and Sources...
Final Project Milestone 5
Module: Menu Filename: Motorcycle.h
Version 1.0
Author Luigi Zaccagnini
Revision History
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Preliminary release 2020/3/9
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
I have done all the coding by myself and only copied the code  that my professor provided to complete my workshops and assignments.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "ReadWritable.h"
#include "Vehicle.h"
using namespace std;

#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__

namespace sdds
{
	class Motorcycle : public Vehicle
	{
		char m_sidecar[3];

	public:
		Motorcycle() { setEmpty(); m_sidecar[0] = false; };
		Motorcycle(const char* licensePlate, const char* makeModel);

		Motorcycle& operator=(const Motorcycle& source) = delete;
		Motorcycle(const Motorcycle&) = delete;

		istream& read(istream& in) override;
		ostream& write(ostream& os) const override;
	};
}
#endif