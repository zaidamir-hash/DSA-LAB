#include <iostream>
using namespace std;

struct Element {
    bool isInt;
    int value;
    Element** nested;
    int nestedSize;

    Element(int v) {
        isInt = true;
        value = v;
        nested = nullptr;
        nestedSize = 0;
    }

    Element(Element* arr[], int size) {
        isInt = false;
        nested = arr;
        nestedSize = size;
    }
};

int sumArray(Element* arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i]->isInt) {
            total += arr[i]->value;
        } else {
            total += sumArray(arr[i]->nested, arr[i]->nestedSize);
        }
    }
    return total;
}

int main() {
    Element* innerArr[] = { new Element(5), new Element(6) };
    Element* midArr[] = { new Element(4), new Element(innerArr, 2) };
    Element* arr1[] = { new Element(2), new Element(3) };
    Element* topArr[] = { new Element(1), new Element(arr1, 2),
                          new Element(midArr, 2), new Element(7) };

    int total = sumArray(topArr, 4);
    cout << "Total Sum = " << total << endl;

    return 0;
}
