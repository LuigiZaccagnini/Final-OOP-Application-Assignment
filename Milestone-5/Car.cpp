#include <iostream>
#include <string.h>
#include "ReadWritable.h"
#include "Vehicle.h"
#include "Car.h"
using namespace std;

namespace sdds
{
	Car::Car(const char* licensePlate, const char* makeModel)
	{
		setLicense(licensePlate);
		setMakeModel(makeModel);
		m_carWash[0] = false;
	};

	istream& Car::read(istream& in)
	{
		bool error = true;

		if (isCsv())
		{
			Vehicle::read(in);

			in.getline(m_carWash, 1, ',');

			if (m_carWash[0] == '1')
				m_carWash[0] = 'y';

			else
				m_carWash[0] = 'n';
		}

		else
		{
			cout << endl << "Car information entry" << endl;

			Vehicle::read(in);

			cout << "Carwash while parked? (Y)es/(N)o: ";
			in >> m_carWash;
			m_carWash[0] = tolower(m_carWash[0]);

			do
			{
				if ((m_carWash[0] != 'y' || m_carWash[0] != 'n') && m_carWash[1] != '\0')
				{
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					in >> m_carWash;
					m_carWash[0] = tolower(m_carWash[0]);
				}

				else
					error = false;

			} while (error);
		}

		return in;
	}

	ostream& Car::write(ostream& os) const
	{
		if (isEmpty())
			os << "Invalid Car Object" << endl;

		else
		{
			if (isCsv())
			{
				os << "C,";
				Vehicle::write(os);

				if (m_carWash[0] == 'y')
					os << 1 << endl;

				else
					os << 0 << endl;
			}

			else
			{
				os << "Vehicle type: Car" << endl;
				Vehicle::write(os);

				if (m_carWash[0] == 'y')
					os << "With Carwash" << endl;

				else
					os << "Without Carwash" << endl;

			}
		}

		return os;
	}
}