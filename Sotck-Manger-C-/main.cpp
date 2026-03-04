#include <iostream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "categories.hpp"
#include "products.hpp"
#include "views.hpp"

using namespace std;

int main()
{
    int choice;

    do
    {
        system("cls");
        choice = Menu();

        switch (choice)
        {
        case 1:
            system("cls");
            createCategory();
            system("pause");
            break;
        case 2:
            system("cls");
            createProduct();
            system("pause");
            break;
        case 3:
            system("cls");
            displayProducts();
            system("pause");
            break;
        case 4:
            system("cls");
            sortFileByPrices();
            system("pause");
            break;
        case 5:
            system("cls");
            mostValuableProduct();
            system("pause");
            break;
        case 6:
            system("cls");
            deleteProduct();
            system("pause");
            break;
        case 7:
            system("cls");
            displayProductsByCategory();
            system("pause");
            break;
        case 8:
            system("cls");
            deleteCatgory();
            system("pause");

        case 9:
            system("cls");
            cout << "Au revoir" << endl;
            system("pause");
            break;

        default:
            system("cls");
            cout << "Choix incorrect !!!" << endl;
            system("pause");
            break;
        }

    } while (choice != 9);

    return 0;
}
