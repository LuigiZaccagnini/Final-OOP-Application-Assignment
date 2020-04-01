#include <iostream>
#include <string.h>
#include "ReadWritable.h"
#include "Vehicle.h"
#include "Motorcycle.h"
using namespace std;

namespace sdds
{
	Motorcycle::Motorcycle(const char* licensePlate, const char* makeModel)
	{
		setLicense(licensePlate);
		setMakeModel(makeModel);
		m_sidecar[0] = 'n';
	}

	istream& Motorcycle::read(istream& in) 
	{
		bool error = true;

		if(isCsv())
		{
			Vehicle::read(in);

			in.getline(m_sidecar, 1, ',');

			if (m_sidecar[0] == 1)
				m_sidecar[0] = 'y';

			else
				m_sidecar[0] = 'n';
		}

		else
		{
			cout << endl << "Motorcycle information entry" << endl;

			Vehicle::read(in);

			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			in >> m_sidecar;
			m_sidecar[0] = tolower(m_sidecar[0]);

			do
			{
				if ((m_sidecar[0] != 'y' || m_sidecar[0] != 'n') && m_sidecar[1] != '\0')
				{
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					in >> m_sidecar;
					m_sidecar[0] = tolower(m_sidecar[0]);
				}

				else
					error = false;

			} while (error);
		}

		return in;
	}

	ostream& Motorcycle::write(ostream& os) const 
	{
		if(isEmpty())
		{
			os << "Invalid Motorcycle Object" << endl;
		}

		else
		{
			if(isCsv())
			{
				os << "M,";
				Vehicle::write(os);

				if (m_sidecar[0] == 'y')
					os << 1 << endl;

				else
					os << 0 << endl;
			}

			else
			{
				os << "Vehicle type: Motorcycle" << endl;
				Vehicle::write(os);

				if (m_sidecar[0] == 'y')
					os << "With Sidecar" << endl;
			}
		}

		return os;
	}
}




//in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');