//-------------------------------------------------------------------
//
//	Laboratory 1, CS-401	                             logbook.h
//	Declaration of class Logbook for logbook ADT
//
//--------------------------------------------------------------------

class Logbook
{
	int logMonth,
		logYear,
		entry[31];		//Basic elements

	int lflag;			//=1 if leapyear
	void leapyear();	//leapyear ?

public:

	Logbook (int month, int year);		//constructor
	void putentry(int day, int value);
	int getentry(int day) const;
	void dsply();
	int month() const;
	int year() const;
	int daysInMonth() const;
	void operator += (const Logbook &rightlogbook);

};