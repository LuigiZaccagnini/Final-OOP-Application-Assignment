/* Citation and Sources...
Final Project Milestone 5
Module: Menu Filename: Car.h
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

#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__

namespace sdds
{
	class Car : public Vehicle
	{
		char m_carWash[3];

	public:
		Car() { setEmpty(); m_carWash[0] = false; };
		Car(const char* licensePlate, const char* makeModel);

		Car& operator=(const Car&) = delete;
		Car(const Car&) = delete;

		istream& read(istream& in) override;
		ostream& write(ostream& os) const override;
	};
}
#endif