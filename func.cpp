#define _CRT_SECURE_NO_WARNINGS

#ifndef _FUNC
#define _FUNC

#include <fstream>
#include <cstring>
#include "phone.h"
#include "func.h"


void show_more_then(phone *obj, int size_of_massive, unsigned value) {
	for (int i = 0; i < size_of_massive; i++) {
		if (obj[i].get_TimeInside() > value) {
			cout << obj[i];
		}
	}
}

void show_outside(phone *obj, int size_of_massive) {
	for (int i = 0; i < size_of_massive; i++) {
		if (obj[i].get_TimeOutside()) {
			cout << obj[i];
		}
	}
}

int string_compare(char *str1, char  *str2) {
	return strcmp(str1, str2);
}

void sort_in_althabet(phone *obj, int size_of_massive) {
	for (int i = 0; i < size_of_massive; i++) {
		for (int j = 0; j < (size_of_massive - i - 1); j++) {
		
			if (string_compare(obj[j].get_SecName(), obj[j + 1].get_SecName()) < 0) {
				continue;
			}
			else if (string_compare(obj[j].get_SecName(), obj[j + 1].get_SecName()) > 0) {
				phone buf = obj[j];
				obj[j] = obj[j + 1];
				obj[j + 1] = buf;
			}
			else if (!string_compare(obj[j].get_SecName(), obj[j + 1].get_SecName())) {
				if (string_compare(obj[j].get_Name(), obj[j + 1].get_Name()) < 0) {
					continue;
				}
				else if (string_compare(obj[j].get_Name(), obj[j + 1].get_Name()) > 0) {
					phone buf = obj[j];
					obj[j] = obj[j + 1];
					obj[j + 1] = buf;
				}
				else if (!string_compare(obj[j].get_Name(), obj[j + 1].get_Name())) {
					if (string_compare(obj[j].get_Ot(), obj[j + 1].get_Ot()) > 0) {
						phone buf = obj[j];
						obj[j] = obj[j + 1];
						obj[j + 1] = buf;
					}
					else {
						continue;
					}
				}
			}
		}
	}
}

void show_in_althabet(phone *obj, int size_of_massive) {
	sort_in_althabet(obj, size_of_massive);
	for (int i = 0; i < size_of_massive; i++) {
		cout << obj[i];
	}
}

phone *read_from_file(char *filename, int &strings_in_file){
	ifstream inputfile(filename, ios::in);

	if (!inputfile){
		cerr << "Error:can`t open file!\n";
		return NULL;
	}

	strings_in_file = 0;

	while (!inputfile.eof()) {
		char buf[256];
		inputfile.getline(buf, sizeof buf);
		strings_in_file++;
	}

	if (!strings_in_file) {
		cerr << "Error:empty input file!\n";
		inputfile.close();
		return NULL;
	}

	inputfile.clear();
	inputfile.seekg(0, ios::beg);
	phone *temp = NULL;
	try {
		temp = new phone[strings_in_file];
	}
	catch (bad_alloc ba) {
		cerr << "Error:cant allocate memory!\n";
		inputfile.close();
		return NULL;
	}

	for (int i = 0; i < strings_in_file; i++) {
		char buffer[256];
		inputfile.getline(buffer, sizeof buffer);

		try{
			temp[i].set_SecName(strtok(buffer, " "));
			temp[i].set_Name(strtok(NULL, " "));
			temp[i].set_Ot(strtok(NULL, " "));
			temp[i].set_Addr(strtok(NULL, " "));
			temp[i].set_Number(strtok(NULL, " "));
			temp[i].set_TimeInside(atoi(strtok(NULL, " ")));
			temp[i].set_TimeOutside(atoi(strtok(NULL, " ")));
		}
		catch (bad_alloc ba) {
			cerr << "Error:Can`t allocate memory!\n";
			delete[] temp;
			inputfile.close();
			return NULL;
		}
	}

	inputfile.close();
	return temp;
}

phone *merge_pages(page *ptr, int num_of_pages, int &num_of_elements) {
	num_of_elements = 0;

	for (int i = 0; i < num_of_pages; i++) {
		num_of_elements += ptr[i].count;
	}

	phone *result = NULL;
	try{
		result = new phone[num_of_elements];
	}
	catch (bad_alloc ba) {
		return NULL;
	}

	int z = 0;
	for (int i = 0; i < num_of_pages; i++) {
		for (int j = 0; j < ptr[i].count; j++) {
			try{
				result[z] = ptr[i].pages[j];
			}
			catch (bad_alloc) {
				delete[] result;
				return NULL;
			}
			z++;
		}
	}

	return result;
}

void delete_pages(page *ptr, int num_of_pages) {
	for (int i = 0; i < num_of_pages; i++) {
		delete[] ptr[i].pages;
	}

	delete[] ptr;
}

#endif
