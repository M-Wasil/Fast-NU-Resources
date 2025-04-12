#include <iostream>
#include "sum.h"
#include "sum.cpp"

using namespace std;

int main() {
    int number1 = 9;
    int number2 = 3;
    int result = sum(number1,number2);
    int doubleResult = prod(number1,number2);
    
    cout << "The sum of " << number1 << " and "<< number2 << " is: " << result << endl;
    
    cout << "Multiplication with 2 of " << result << " is: " << doubleResult << endl;
    
    return 0;
}
