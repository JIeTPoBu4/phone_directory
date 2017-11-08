#ifndef _FUNC_H
#define _FUNC_H

#include "phone.h"
#include "page.h"

void show_more_then(phone *obj, int size_of_massive, unsigned value);
void show_outside(phone *obj, int size_of_massive);
void sort_in_althabet(phone *obj, int size_of_massive);
void show_in_althabet(phone *obj, int size_of_massive);
phone *read_from_file(char *filename, int &strings_in_file);
phone *merge_pages(page *ptr, int num_of_pages, int &num_of_elements);
void delete_pages(page *ptr, int num_of_pages);

#endif