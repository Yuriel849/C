#include "text.h"
#include <cstring> // To handle strings in C-style

// Default constructor
cText::cText() {
	text = NULL;
}

// Copy constructor
// If not defined, all attributes are copied; here only the pointer 'text' is copied
cText::cText(const cText& newText) {
	text = NULL;
	set(newText.get());
}

// Destructor
// Only one per class and has no return value and no parameter
cText::~cText() {
	if (text) delete[] text;
}

void cText::set(const char* newText) { // Define parameter as 'const' to allow method to be called with constant string
	// 1. Free previous memory
	// 2. Allocation new memory
	// 3. Copy text
	if (text) delete[] text;
	text = NULL;
	if (newText) {
		text = new char[strlen(newText) + 1];
		strcpy_s(text, 100, newText);
	}
}

// Returns 'const char *' const pointer to protect the private attribute 'text'
// 'const' at end of method signature indicates method does not modify any member attribute
const char* cText::get() const {
	return text ? text : "";
}

cText& cText::operator=(const char* newText) {
	set(newText);
	
	return *this;
}
