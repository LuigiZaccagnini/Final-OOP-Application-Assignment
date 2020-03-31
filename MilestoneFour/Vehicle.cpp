#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <cstring>
#include <stdlib.h>
#include "ReadWritable.h"
#include "Vehicle.h"
using namespace std;

namespace sdds
{
	//Protected
	void Vehicle::setEmpty()
	{
		m_licensePlate[0] = '\0';
		m_parkingSpotNumber = 0;
		m_makeModel = nullptr;
	}

	bool Vehicle::isEmpty() const
	{
		bool empty = false;

		if (m_licensePlate[0] == '\0' && m_parkingSpotNumber <= 0 && m_makeModel == nullptr)
		{
			empty = true;
		}

		return empty;
	}

	const char* Vehicle::getLicensePlate() const
	{
		const char* lp = &m_licensePlate[0];
		return lp;
	}

	void Vehicle::setMakeModel(const char* makeModel)
	{
		if (makeModel != nullptr && makeModel[0] != ' ' && makeModel[0] != '\0' && strlen(makeModel) >= 2)
		{
			if (m_makeModel != nullptr)
			{
				delete[] m_makeModel;
				m_makeModel = nullptr;
			}

			m_makeModel = new char[strlen(makeModel) + 1];
			strcpy(m_makeModel, makeModel);
		}

		else
		{
			if (m_makeModel != nullptr)
			{
				delete[] m_makeModel;
				m_makeModel = nullptr;
			}

			setEmpty();
		}
	}

	//Public	
	Vehicle::Vehicle(const char* licensePlate, const char* makeModel)
	{
		setEmpty();

		if (licensePlate != nullptr && strlen(licensePlate) <= 8 && licensePlate[0] != '\0')
		{
			strcpy(m_licensePlate, licensePlate);
			for (unsigned int i = 0; i < strlen(m_licensePlate); ++i) m_licensePlate[i] = toupper(m_licensePlate[i]);

			setMakeModel(makeModel);
		}
	}

	Vehicle::~Vehicle()
	{
		if (m_makeModel != nullptr)
		{
			delete[] m_makeModel;
			m_makeModel = nullptr;
		}
	}

	void Vehicle::setParkingSpot(int parkingSpot)
	{
		if (parkingSpot > 0)
		{
			m_parkingSpotNumber = parkingSpot;
		}

		else
		{

			if (m_makeModel != nullptr)
			{
				delete[] m_makeModel;
				m_makeModel = nullptr;
			}

			setEmpty();
		}
	}

	bool operator==(const Vehicle& source, const char* licensePlate)
	{
		bool returnValue = false;
		char* temp;

		if (!source.isEmpty() && licensePlate != nullptr && strlen(licensePlate) > 2)
		{
			temp = new char[strlen(licensePlate) + 1];
			strcpy(temp, licensePlate);
			for (unsigned int i = 0; i < strlen(temp); ++i) temp[i] = toupper(temp[i]);

			returnValue = strcmp(source.m_licensePlate, temp) == 0 ? true : false;

			delete[] temp;
			temp = nullptr;
		}

		return returnValue;
	}

	bool operator==(const Vehicle& mainSource, const Vehicle& source)
	{
		bool returnValue = false;

		if(!mainSource.isEmpty() && !source.isEmpty())
		{
			returnValue = strcmp(mainSource.m_licensePlate, source.getLicensePlate()) == 0 ? true : false;
		}

		return returnValue;
	}

	istream& Vehicle::read(istream& in)
	{
		bool error = true;
		char* temp = new char[256];

		if (isCsv())
		{
			in.getline(temp, 255, ',');
			m_parkingSpotNumber = atoi(temp);

			in.getline(m_licensePlate, 8, ',');
			for (unsigned int i = 0; i < strlen(m_licensePlate); ++i) m_licensePlate[i] = toupper(m_licensePlate[i]);

			in.getline(temp, 255, ',');
			setMakeModel(temp);


			if (!in)
				setEmpty();
		}

		else
		{
			cout << "Enter Licence Plate Number: ";

			do
			{
				in >> m_licensePlate;

				if (strlen(m_licensePlate) < 8)
				{
					for (unsigned int i = 0; i < strlen(m_licensePlate); ++i) m_licensePlate[i] = toupper(m_licensePlate[i]);
					error = false;
				}

				else
				{
					cout << "Invalid Licence Plate, try again: ";
				}
			} while (error == true);


			error = true;
			cout << "Enter Make and Model: ";

			do
			{
				in >> temp;

				if (strlen(temp) >= 2 && strlen(temp) < 60)
				{
					setMakeModel(temp);
					error = false;
				}

				else
				{
					cout << "Invalid Make and model, try again: ";
				}

			} while (error == true);

		}

		if (in.bad())
			setEmpty();


		delete[] temp;
		temp = nullptr;

		return in;
	}

	ostream& Vehicle::write(ostream& os) const
	{
		if (isEmpty())
		{
			cout << "Invalid Vehicle Object" << endl;
		}

		else
		{
			if (isCsv())
			{
				if (m_parkingSpotNumber > 0)
					cout << m_parkingSpotNumber << ",";

				else
					cout << "N/A" << ",";

				cout << m_licensePlate << ",";
				cout << m_makeModel << ",";
			}

			else
			{
				if (m_parkingSpotNumber > 0)
					cout << "Parking Spot Number: " << m_parkingSpotNumber << endl;

				else
					cout << "Parking Spot Number: " << "N/A" << endl;

				cout << "Licence Plate: " << m_licensePlate << endl;
				cout << "Make and Model: " << m_makeModel << endl;
			}
		}

		return os;
	}
}