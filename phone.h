#define _CRT_SECURE_NO_WARNINGS

#ifndef _PHONE_H
#define _PHONE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <new>

using namespace std;

class phone {
	char *SecName;
	char *Name;
	char *Ot;
	char *Addr;
	char *Number;
	unsigned TimeInside;  //seconds
	unsigned TimeOutside;  //seconds
	void enter_string(char **string_in, char *string_out);
	void delete_val(char **str);
	bool is_null() {
		if (!SecName || !Name || !Ot || !Addr || !Number) {
			return true;
		}
		return false;
	}
public:
	phone();
	phone(const phone &obj);
	phone(char *pSecName, char *pName, char *pOt, char *pAddr, char *pNumber, unsigned pTimeInside, unsigned pTimeOutside);
	~phone();
	void set_SecName(char *pSecName);
	void set_Name(char *pName);
	void set_Ot(char *pOt);
	void set_Addr(char *pAddr);
	void set_Number(char *pNumber);
	void set_all(char *pSecName, char *pName, char *pOt, char *pAddr, char *pNumber, unsigned pTimeInside, unsigned pTimeOutside);
	void show();

	void set_TimeInside(unsigned pTimeInside) {
		TimeInside = pTimeInside;
	}

	void set_TimeOutside(unsigned pTimeOutside) {
		TimeOutside = pTimeOutside;
	}

	char *get_SecName() {
		return SecName;
	}

	char *get_Name() {
		return Name;
	}

	char *get_Ot() {
		return Ot;
	}

	char *get_Addr() {
		return Addr;
	}

	char *get_Number() {
		return Number;
	}

	unsigned get_TimeInside() {
		return TimeInside;
	}

	unsigned get_TimeOutside() {
		return TimeOutside;
	}

	friend ostream &operator<<(ostream &stream, phone obj);
	friend istream &operator>>(istream &stream, phone &obj);
	phone operator=(const phone &obj);
};


#endif