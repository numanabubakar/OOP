#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
    string name;
    int price;
    bool purchased;

public:
Product(){
    purchased = false;
}
    void setname(string t)
    {
        name = t;
    }

    string getname()
    {
        return name;
    }

    void setprice(int y)
    {
        price = y;
    }

    int getprice()
    {
        return price;
    }
    bool isPurchased()
    {
        return purchased;
    }

    void purchase()
    {
        purchased = true;
    }
};

const int MAX_products_SIZE = 100;
Product products[MAX_products_SIZE];
int productsSize = 0;

void addProduct()
{
    if (productsSize >= MAX_products_SIZE)
    {
        cout << "----------------------------------------------\n";

        cout << "products is full! Cannot add more Products." << endl;
        cout << "----------------------------------------------\n";

        return;
    }

    Product newProduct;

    string name;
    cout << "Enter the name of the Product: ";
    getline(cin, name);
    newProduct.setname(name);


    int price;
    cout << "Enter the price  of the Product: ";
    cin >> price;
    cin.ignore();
    newProduct.setprice(price);

    products[productsSize] = newProduct;
    productsSize++;
    cout << "----------------------------------------------\n";

    cout << "Product added successfully to the products!" << endl;
    cout << "----------------------------------------------\n";
}

void displayProducts()
{
    if (productsSize == 0)
    {
        cout << "----------------------------------------------\n";

        cout << "products is empty! No Products to display." << endl;
        cout << "----------------------------------------------\n";

        return;
    }
    cout << "----------------------------------------------\n";

    cout << "List of Products in the products:" << endl;
    for (int i = 0; i < productsSize; i++)
    {
        cout << "---------------Product #" << (i + 1) << "----------------\n";

        cout << "name: " << products[i].getname() << endl;
        cout << "price: " << products[i].getprice() << endl;
        cout << "Purchased: " << (products[i].isPurchased() ? "Yes" : "No") << endl;
        cout << endl;
    }
}

void searchProduct()
{
    if (productsSize == 0)
    {
        cout << "----------------------------------------------\n";

        cout << "products is empty! No Products to search." << endl;
        cout << "----------------------------------------------\n";

        return;
    }

    string searchname;
    cout << "Enter the name of the Product to search: ";
    getline(cin, searchname);

    bool found = false;
    cout << "----------------------------------------------\n";

    cout << "Matching Products:" << endl;
    for (int i = 0; i < productsSize; i++)
    {
        if (products[i].getname() == searchname)
        {
            cout << "----------------------------------------------\n";

            cout << "name: " << products[i].getname() << endl;
            cout << "price: " << products[i].getprice() << endl;
            cout << "Purchased: " << (products[i].isPurchased() ? "Yes" : "No") << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "----------------------------------------------\n";

        cout << "No Products found with the given name." << endl;
        cout << "----------------------------------------------\n";
    }
}

void removeProduct()
{
    if (productsSize == 0)
    {
        cout << "----------------------------------------------\n";

        cout << "products is empty! No Products to remove." << endl;
        cout << "----------------------------------------------\n";

        return;
    }

    string removename;
    cout << "Enter the name of the Product to remove: ";
    getline(cin, removename);

    bool found = false;
    int removeIndex;
    for (int i = 0; i < productsSize; i++)
    {
        if (products[i].getname() == removename)
        {
            found = true;
            removeIndex = i;
            break;
        }
    }

    if (found)
    {
        for (int i = removeIndex; i < productsSize - 1; i++)
        {
            products[i] = products[i + 1];
        }
        productsSize--;
        cout << "----------------------------------------------\n";

        cout << "Product removed successfully from the products!" << endl;
        cout << "----------------------------------------------\n";
    }
    else
    {
        cout << "----------------------------------------------\n";

        cout << "No Products found with the given name." << endl;
        cout << "----------------------------------------------\n";
    }
}

void purchaseProduct()
{
    if (productsSize == 0)
    {
        cout << "----------------------------------------------\n";

        cout << "products is empty! No products to purchase." << endl;
        cout << "----------------------------------------------\n";

        return;
    }

    string purchaseTitle;
    cout << "Enter the name of the product to purchase: ";
    getline(cin, purchaseTitle);

    bool found = false;
    for (int i = 0; i < productsSize; i++)
    {
        if (products[i].getname() == purchaseTitle)
        {
            products[i].purchase();
            cout << "----------------------------------------------\n";

            cout <<products[i].getname()<< " product purchased successfully!" << endl;
            cout << "----------------------------------------------\n";

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "No products found with the given title." << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "products System Menu" << endl;
        cout << "1. Add a Product" << endl;
        cout << "2. Display Products" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Remove Product" << endl;
        cout << "5. Purchase Product" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addProduct();
            break;
        case 2:
            displayProducts();
            break;
        case 3:
            searchProduct();
            break;
        case 4:
            removeProduct();
            break;
        case 5:
            purchaseProduct();
            break;
        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}