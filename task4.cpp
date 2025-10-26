#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
    string name;
    double price;
    string description;
    bool availability;
};

int partition(Product arr[], int low, int high)
{
    double pivot = arr[high].price;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j].price <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    Product products[3];
    products[0].name = "Product 1";
    products[0].price = 10.99;
    products[0].description = "this is Product1";
    products[0].availability = true;
    products[1].name = "Product 2";
    products[1].price = 5.99;
    products[1].description = "this is Product2";
    products[1].availability = false;
    products[2].name = "Product 3";
    products[2].price = 2.99;
    products[2].description = "this is Product3";
    products[2].availability = true;
    quickSort(products, 0, 2);
    for (int i = 0; i < 3; i++)
    {
        cout << products[i].name << ", Price: " << products[i].price << ", Description: " << products[i].description << ", Available: " << (products[i].availability ? "true" : "false") << endl;
    }
    return 0;
}
