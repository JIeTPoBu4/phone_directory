#include "func.h"
#include "phone.h"
#include "page.h"

int main(int argc, char *argv[]) {

	if (argc > 1) {
		page *ptr = NULL;

		try{
			ptr = new page[argc - 1];
		}
		catch (bad_alloc ba) {
			cerr << "Error:can`t allocate memory for pages!\n";
			return 1;
		}

		for (int i = 1; i < argc; i++) {
			ptr[i - 1].pages = read_from_file(argv[i], ptr[i-1].count);

			if (!ptr[i - 1].pages) {
				cerr << "Error:can`t create page " << (i - 1);
				for (int j = 0; j < i - 1; j++) {
					delete[] ptr[j].pages;
				}
				delete[] ptr;
				return 1;
			}
		}

		int num_of_elements = 0;
		phone *result = merge_pages(ptr, argc - 1, num_of_elements);
		delete_pages(ptr, argc - 1);

		if (!result) {
			return 1;
		}

		show_in_althabet(result, num_of_elements);
		delete[] result;

	}
	else{

		phone result[] = { phone("Ab", "A", "B", "hgfhgh", "5666", 0, 1),
			               phone("Aa", "A", "A", "eeeeee", "9767", 11, 1) };

		show_in_althabet(result, 2);
	}
	

}
