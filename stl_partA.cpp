//Alexis Rojas
//CIS 1202.N01

#include <iostream>
#include <stdexcept>
#include <string>
#include <cctype>

using namespace std;
//-------------------------
// EXCEPTION CLASSES
//-------------------------
class invalidCharacterException : public runtime_error {
public:
    invalidCharacterException(const string& message) : runtime_error(message) {}
};

class invalidRangeException : public runtime_error {
public:
    invalidRangeException(const string& message) : runtime_error(message) {}
};


//-------------------------
//PROTOTYPING
//-------------------------
char character(char start, int offset);



//-------------------------
//MAIN FUNCTION
//-------------------------
int main() {
    try {
        cout << "character('a', 1) = ";
        cout << character('a', 1) << endl; // Returning "b"
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "character('a', -1) = ";
        cout << character('a', -1) << endl; // Throw invalidRangeException
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "character('Z', -1) = ";
        cout << character('Z', -1) << endl; // Return "Y"
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "character('?', 5) = ";
        cout << character('?', 5) << endl; // Throw invalidCharacterException
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "character('A', 32) = ";
        cout << character('A', 32) << endl; // Throw invalidRangeException
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}


//-------------------------
//CHARACTHER FUNCTION
//-------------------------
char character(char start, int offset) {
    if (!isalpha(start)) {
        throw invalidCharacterException("The start character is not a valid letter.");
    }

    char target = start + offset;

    if ((islower(start) && !islower(target)) || (isupper(start) && !isupper(target))) {
        throw invalidRangeException("The resulting character is out of range.");
    }

    return target;
}