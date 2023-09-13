#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Define a product structure
struct Product {
    string name;
    int id;
    double price;
};

// Function to calculate the total bill
double calculateTotal(vector<Product>& cart) {
    double total = 0.0;
    for (const Product& item : cart) {
        total += item.price;
    }
    return total;
}

int main() {
    vector<Product> inventory = {
        {"Shirt", 101, 2.00},
        {"Pant", 102, 1.49},
        {"Tshirt", 103, 1.99},
        {"Jeans", 104, 2.49},
        {"Girls Top", 105, 3.99},
        {"Skirts", 106, 4.49},
        {"Shoes", 107, 2.99},
        {"Shocks", 108, 1.49},
        {"Cap", 109, 3.49},
        {"Soap", 110, 2.49},
        {"Facewash", 111, 1.99},
        {"Fair lovely", 112, 3.49},
        // Add more products here
    };

    vector<Product> cart;
    char choice;

    cout << "Welcome to the Supermarket Billing System!" << endl;

    do {
        cout << "Available Products:" << endl;
        cout << "ID\tName\tPrice" << endl;
        for (const Product& item : inventory) {
            cout << item.id << "\t" << item.name << "\t$" << fixed << setprecision(2) << item.price << endl;
        }

        int selectedID;
        cout << "Enter the ID of the product you want to purchase: ";
        cin >> selectedID;

        bool found = false;
        for (const Product& item : inventory) {
            if (item.id == selectedID) {
                cart.push_back(item);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Product not found." << endl;
        }

        cout << "Do you want to add another product? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "------- Invoice -------" << endl;
    cout << "ID\tName\tPrice" << endl;
    for (const Product& item : cart) {
        cout << item.id << "\t" << item.name << "\t$" << fixed << setprecision(2) << item.price << endl;
    }

    double total = calculateTotal(cart);
    cout << "-----------------------" << endl;
    cout << "Total: $" << fixed << setprecision(2) << total << endl;

    cout << "Thank you for shopping with us!" << endl;

    return 0;
}