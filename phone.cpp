#ifndef _PHONE
#define _PHONE

#include <cstring>
#include "phone.h"

void phone::enter_string(char **string_out, char *string_in) {
	if (string_in) {
		size_t size = strlen(string_in);
		try {
			*string_out = new char[size + 1];
		}
		catch (bad_alloc ba){
			cerr << "Error: can`t allocate memory for " << string_in << '\n';
			*string_out = NULL;
			throw;
		}

		strncpy(*string_out, string_in, size+1);
		return;
	}
	*string_out = NULL;
}

phone::phone() {
	SecName = Name = Ot = Addr = Number = NULL;
	TimeInside = TimeOutside = 0;
}

phone::phone(const phone &obj) {
	try {
		enter_string(&SecName, obj.SecName);
		enter_string(&Name, obj.Name);
		enter_string(&Ot, obj.Ot);
		enter_string(&Addr, obj.Addr);
		enter_string(&Number, obj.Number);
	}
	catch (bad_alloc ba) {
		throw;
	}
	TimeInside = obj.TimeInside;
	TimeOutside = obj.TimeOutside;
}

phone::phone(char *pSecName, char *pName, char *pOt, char *pAddr, char *pNumber, unsigned pTimeInside, unsigned pTimeOutside) {
	try {
		enter_string(&SecName, pSecName);
		enter_string(&Name, pName);
		enter_string(&Ot, pOt);
		enter_string(&Addr, pAddr);
		enter_string(&Number, pNumber);
	}
	catch (bad_alloc ba) {
		throw;
	}
	TimeInside = pTimeInside;
	TimeOutside = pTimeOutside;
}

void phone::delete_val(char **str) {
	if (*str) {
		delete[] (*str);
	}
	*str = NULL;
}

phone::~phone() {
	delete_val(&SecName);
	delete_val(&Name);
	delete_val(&Ot);
	delete_val(&Addr);
	delete_val(&Number);
}

void phone::show() {
	cout << SecName << '\n';
	cout << Name << '\n';
	cout << Ot << '\n';
	cout << Addr << '\n';
	cout << Number << '\n';
	cout << TimeInside << '\n';
	cout << TimeOutside << '\n';
	cout << endl;
}

ostream &operator<<(ostream &stream, phone obj) {
	if (obj.is_null()) {
		cerr << "Error:One of string value is empty!\n";
		return stream;
	}
	stream << obj.SecName << '\n';
	stream << obj.Name << '\n';
	stream << obj.Ot << '\n';
	stream << obj.Addr << '\n';
	stream << obj.Number << '\n';
	stream << obj.TimeInside << '\n';
	stream << obj.TimeOutside << endl << endl;
	return stream;
}


void phone::set_SecName(char *pSecName) {
	delete_val(&SecName);
	try{
		enter_string(&SecName, pSecName);
	}
	catch (bad_alloc ba){
		throw;
	}
}

void phone::set_Name(char *pName) {
	delete_val(&Name);
	try {
		enter_string(&Name, pName);
	}
	catch (bad_alloc ba){
		throw;
	}
}

void phone::set_Ot(char *pOt) {
	delete_val(&Ot);
	try{
		enter_string(&Ot, pOt);
	}
	catch (bad_alloc) {
		throw;
	}
}

void phone::set_Addr(char *pAddr) {
	delete_val(&Addr);
	try{
		enter_string(&Addr, pAddr);
	}
	catch (bad_alloc ba) {
		throw;
	}
}

void phone::set_Number(char *pNumber) {
	delete_val(&Number);
	try{
		enter_string(&Number, pNumber);
	}
	catch (bad_alloc ba){
		throw;
	}
}

void phone::set_all(char *pSecName, char *pName, char *pOt, char *pAddr, char *pNumber, unsigned pTimeInside, unsigned pTimeOutside) {
	try{
		set_SecName(pSecName);
		set_Name(pName);
		set_Ot(pOt);
		set_Addr(pAddr);
		set_Number(pNumber);
		set_TimeInside(pTimeInside);
		set_TimeOutside(pTimeOutside);
	}
	catch (bad_alloc ba) {
		throw;
	}
}

phone phone::operator=(const phone &obj) {
	try{
		set_SecName(obj.SecName);
		set_Name(obj.Name);
		set_Ot(obj.Ot);
		set_Addr(obj.Addr);
		set_Number(obj.Number);
		set_TimeInside(obj.TimeInside);
		set_TimeOutside(obj.TimeOutside);
	}
	catch (bad_alloc ba) {
		throw;
	}
	return *this;
}

istream &operator>>(istream &stream, phone &obj) {
	//stream >> obj.SecName >> obj.Name >> obj.Ot >> obj.Addr >> obj.Number >> obj.TimeInside >> obj.TimeOutside;
	try{
		char buffer[100];
		stream >> buffer;
		obj.set_SecName(buffer);
		stream >> buffer;
		obj.set_Name(buffer);
		stream >> buffer;
		obj.set_Ot(buffer);
		stream >> buffer;
		obj.set_Addr(buffer);
		stream >> buffer;
		obj.set_Number(buffer);
		stream >> obj.TimeInside;
		stream >> obj.TimeOutside;
	}
	catch (bad_alloc ba){
		throw;
	}
	return stream;
}


#endif
