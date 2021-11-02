#include <iostream> // Input & output in command shell via streams
#include "text.h"
using namespace std; // All standard C++ identifiers are in namespace 'std'

int main()
{
	cout << "Hello World!!!" << endl;
	// 'cout' : Standard command shell output stream
	// '<<' : Operator for strings
	// 'endl' : 'end of line' & flushes the stream

	// Use the class 'cText'
	cText text;
	text = "hello world!";
	cout << text.get() << endl;

	return 0;
}
