/* Citation and Sources...
Final Project Milestone 5
Module: Menu Filename: Vehicle.h
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
using namespace std;

#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__

namespace sdds
{
	class Vehicle : public ReadWritable
	{
		char m_licensePlate[9];
		char* m_makeModel;
		int m_parkingSpotNumber;

	protected:
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		char* getMakeModel() const { return m_makeModel; };
		void setLicense(const char* licensePlate);
		void setMakeModel(const char* makeModel);

	public:
		Vehicle() { setEmpty(); };
		Vehicle(const char* licensePlate, const char* makeModel);
		~Vehicle();
		Vehicle& operator=(const Vehicle& source) = delete;
		Vehicle(const Vehicle&) = delete;

		int getParkingSpot() const { return m_parkingSpotNumber; };
		void setParkingSpot(int parkingSpot);
		friend bool operator==(const Vehicle&, const char* licensePlate);
		friend bool operator==(const Vehicle&, const Vehicle& source);
		istream& read(istream& in) override;
		ostream& write(ostream& os) const override;
	};
}
#endif