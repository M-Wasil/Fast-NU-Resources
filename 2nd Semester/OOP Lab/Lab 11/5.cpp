#include <iostream>
#include <string>
using namespace std;

template <typename T>
T findMax(T arr[], int size){
    T max = arr[0];
    for (int i=1;i<size;i++){
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int main() {
    int intArr[] = {3,79,33,15,30};
    int intSize = 5;
    cout << "Array: [3,79,33,15,30]" << endl;
    cout << "Maximum: " << findMax(intArr, intSize) << endl;
    string strArr[] = {"Pomegranate","Banana","Apple","Watermelon"};
    int strSize = 4;
    cout << "Array: [\"Pomegranate\", \"Banana\", \"Apple\", \"Watermelon\"]" << endl;
    cout << "Maximum: " << findMax(strArr, strSize) << endl;

}

