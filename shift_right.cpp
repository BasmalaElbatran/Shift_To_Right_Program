#include <iostream>

using namespace std;

int shiftRight(double* array, int startIndex, int endIndex, int distance, int arraySize) {
    if (startIndex > endIndex || distance <= 0 || startIndex < 0 || endIndex >= arraySize) {
        return 1;
    }

    int numElements = endIndex - startIndex + 1;

    for (int i = startIndex + numElements - 1; i >= startIndex; --i) {
        if (i + distance < arraySize) {
            array[i + distance] = array[i];
        }
        else {
            array[i + distance] = -999.9;
        }
    }

    return 0;
}

int main() {
    int arraySize;
    cout << "Please enter the size of your array: ";
    cin >> arraySize;

    if (arraySize <= 0) {
        cout << "Invalid array size. Please provide a positive integer." << endl;
        return 1;
    }

    double* array = new double[arraySize];

    cout << "Please enter " << arraySize << " elements for your array:" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cin >> array[i];
    }

    int startIndex, endIndex, shiftDistance;
    cout << "Enter the start index of the range to shift: ";
    cin >> startIndex;
    cout << "Enter the end index of the range to shift: ";
    cin >> endIndex;
    cout << "Enter the distance to shift the elements to the right: ";
    cin >> shiftDistance;

    int result = shiftRight(array, startIndex, endIndex, shiftDistance, arraySize);

    if (result == 0) {
        cout << "Modified Array:" << endl;
        for (int i = 0; i < arraySize; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Oops! Something went wrong during the shift. Please check your input." << endl;
    }

    delete[] array;
    return 0;
}
