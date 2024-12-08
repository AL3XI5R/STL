#include <iostream>
#include <cmath> 
using namespace std;

//---TEMPLATE---
template <typename T>
T half(T value) {
    return value / 2;
}

//---FUNCTION---
template <>
int half(int value) {
    return static_cast<int>(round(value / 2.0));
}

//---MAIN FUNCTION---
int main() {
    double a = 7.0;
    float b = 5.0f;
    int c = 3;

    // ---TEST CASES---
    cout << half(a) << endl; // RETURN 3.5
    cout << half(b) << endl; // RETURN 2.5
    cout << half(c) << endl; // RETURN 2

    return 0;
}
