#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Class to define a Product
class Product {
private:
    int productID;
    string productName;
    int quantity;
    double price;

public:
    // Constructor
    Product(int id, string name, int qty, double pr) {
        productID = id;
        productName = name;
        quantity = qty;
        price = pr;
    }

    // Getters
    int getProductID() { return productID; }
    string getProductName() { return productName; }
    int getQuantity() { return quantity; }
    double getPrice() { return price; }

    // Setters
    void setQuantity(int qty) { quantity = qty; }
    void setPrice(double pr) { price = pr; }

    // Display Product Details
    void displayProduct() {
        cout << left << setw(10) << productID << setw(20) << productName
             << setw(10) << quantity << setw(10) << price << endl;
    }
};

// Class to manage the shop
class Shop {
private:
    vector<Product> inventory;

public:
    // Add a new product
    void addProduct() {
        int id, qty;
        string name;
        double price;

        cout << "Enter Product ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> qty;
        cout << "Enter Price: ";
        cin >> price;

        Product newProduct(id, name, qty, price);
        inventory.push_back(newProduct);
        cout << "\nProduct added successfully!\n";
    }

    // List all products
    void listProducts() {
        if (inventory.empty()) {
            cout << "\nNo products available in the inventory.\n";
            return;
        }

        cout << "\nCurrent Inventory:\n";
        cout << left << setw(10) << "ID" << setw(20) << "Name"
             << setw(10) << "Qty" << setw(10) << "Price" << endl;
        cout << string(50, '-') << endl;

        for (auto &product : inventory) {
            product.displayProduct();
        }
    }

    // Search for a product by ID
    void searchProduct() {
        if (inventory.empty()) {
            cout << "\nNo products available in the inventory.\n";
            return;
        }

        int id;
        cout << "Enter Product ID to search: ";
        cin >> id;

        for (auto &product : inventory) {
            if (product.getProductID() == id) {
                cout << "\nProduct Found:\n";
                cout << left << setw(10) << "ID" << setw(20) << "Name"
                     << setw(10) << "Qty" << setw(10) << "Price" << endl;
                cout << string(50, '-') << endl;
                product.displayProduct();
                return;
            }
        }
        cout << "\nProduct with ID " << id << " not found.\n";
    }

    // Edit product details
    void editProduct() {
        if (inventory.empty()) {
            cout << "\nNo products available in the inventory.\n";
            return;
        }

        int id;
        cout << "Enter Product ID to edit: ";
        cin >> id;

        for (auto &product : inventory) {
            if (product.getProductID() == id) {
                int qty;
                double price;
                cout << "Enter new Quantity: ";
                cin >> qty;
                cout << "Enter new Price: ";
                cin >> price;

                product.setQuantity(qty);
                product.setPrice(price);
                cout << "\nProduct details updated successfully!\n";
                return;
            }
        }
        cout << "\nProduct with ID " << id << " not found.\n";
    }
};

int main() {
    Shop shop;
    int choice;

    do {
        cout << "\n==== Shop Management System ====\n";
        cout << "1. Add Product\n";
        cout << "2. List Products\n";
        cout << "3. Search Product\n";
        cout << "4. Edit Product\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                shop.addProduct();
                break;
            case 2:
                shop.listProducts();
                break;
            case 3:
                shop.searchProduct();
                break;
            case 4:
                shop.editProduct();
                break;
            case 0:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}