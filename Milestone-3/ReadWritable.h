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
using namespace std;

#ifndef SDDS_ReadWritable_H__
#define SDDS_ReadWritable_H__

namespace sdds
{
	class ReadWritable
	{
		bool m_commaSeparatedMode;

	public:
		ReadWritable() { m_commaSeparatedMode = false; };
		virtual ~ReadWritable() {};
		bool isCsv() const { return m_commaSeparatedMode; };
		void setCsv(bool value) { m_commaSeparatedMode = value; };
		virtual istream& read(istream& in) = 0;
		virtual ostream& write(ostream& os) const = 0;

		friend ostream& operator<<(ostream& os, const ReadWritable& source) { source.write(os); return os; };
		friend istream& operator>>(istream& in, ReadWritable& source) { source.read(in); return in; };
	};
}
#endif