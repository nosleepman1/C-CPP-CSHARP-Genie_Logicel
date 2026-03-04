#include "products.hpp"
#include "categories.hpp"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int getNewProductId()
{
    ifstream C{"productsID.txt"};
    int id;
    C >> id;
    return id;
}

void setNewProductId(int id)
{
    ofstream C{"productsID.txt"};
    C << id;
}

bool checkIdCategory(int id)
{
    ifstream Cat{"categories.txt", ios::app};

    Category C;

    while (Cat >> C.idCategory >> C.libelle)
    {
        if (C.idCategory == id)
        {
            return true;
        }
    }
    return false;
}

void createProduct()
{
    Product P;

    P.id = getNewProductId() + 1;

    cout << "Code:  ";
    cin >> P.code;
    cout << "Libelle:  ";
    cin >> P.libelle;
    cout << "Price:  ";
    cin >> P.price;
    cout << "Quantite:  ";
    cin >> P.quantity;

    cout << "Id Category:  ";
    int idToEnter;

    do
    {
        cin >> idToEnter;

        if (!checkIdCategory(idToEnter))
        {
            cout << "Cette categorie n existe pas veuillez ressayer :  " << endl;
                }

    } while (!checkIdCategory(idToEnter));

    P.idCategory = idToEnter;

    ofstream Pro{"products.dat", ios::binary | ios::app};

    Pro << P.id << " " << P.code << " " << P.libelle << " " << P.price << " " << P.quantity << " " << P.idCategory << endl;

    setNewProductId(P.id);
    cout << "Produit cree avec success\n\n"
         << endl;
}

void deleteProduct()
{
    displayProducts();

    ofstream temp{"temp.dat", ios::binary | ios::app};
    ifstream Pro{"products.dat"};
    Product P;

    int toDelete;
    cout << "\n\nSaisir l'ID de la categorie a supprimer: ";
    cin >> toDelete;

    if (Pro.is_open())
    {
        while (Pro >> P.id >> P.code >> P.libelle >> P.price >> P.price >> P.quantity)
        {
            if (P.id == toDelete)
            {
                continue;
            }
            temp << P.id << " " << P.code << " " << P.libelle << " " << P.price << " " << P.quantity << " " << P.idCategory << endl;
        }
    }

    temp.close();
    Pro.close();

    remove("products.dat");
    rename("temp.dat", "products.dat");
}
void displayProducts()
{
    ifstream Pro{"products.dat", ios::binary};

    Product P;

    cout << "-----------Liste des Produits------------------" << endl;
    while (Pro >> P.id >> P.code >> P.libelle >> P.price >> P.price >> P.quantity >> P.idCategory)
    {
        cout << P.id << " " << P.code << " " << P.libelle << " " << P.price << " " << P.quantity << " " << P.idCategory << endl;
    }

    cout << "-------------------------------------------" << endl;
}
void mostValuableProduct()
{
    float max = 0;
    Product MaxProduct;

    ifstream Pro{"products.dat", ios::binary};

    Product P;

    while (Pro >> P.id >> P.code >> P.libelle >> P.price >> P.price >> P.quantity)
    {
        if (P.price > max)
        {
            max = P.price;
            strcpy(P.code, MaxProduct.code);
            MaxProduct.id = P.id;
            MaxProduct.price = P.price;
            strcpy(P.libelle, MaxProduct.libelle);
        }
    }

    cout << "Le Produit le plus cher est : " << MaxProduct.code << " " << MaxProduct.libelle << "  Prix:  " << MaxProduct.price << endl;
}

int getLengthProductsFile()
{
    int longeurFichier = 0;
    ifstream Pro{"products.dat", ios::binary};

    Product P;

    while (Pro >> P.id >> P.code >> P.libelle >> P.price >> P.price >> P.quantity)
    {
        longeurFichier++;
    }
    return longeurFichier;
}

void sortFileByPrices()
{
    ifstream Pro{"products.dat", ios::binary};

    Product P;
    int Z = 0;
    Product arrayProduct[getLengthProductsFile()];

    while (Pro >> P.id >> P.code >> P.libelle >> P.price >> P.price >> P.quantity >> P.idCategory)
    {
        arrayProduct[Z] = P;
        Z++;
    }

    for (int i = 0; i < Z - 1; i++)
    {
        for (int j = i + 1; j < Z; j++)
        {
            Product temp;
            if (arrayProduct[j].price < arrayProduct[i].price)
            {
                temp = arrayProduct[i];
                arrayProduct[i] = arrayProduct[j];
                arrayProduct[j] = temp;
            }
        }
    }

    ofstream tempFile{"temp.dat", ios::binary | ios::app};

    for (int i = 0; i < Z; i++)
    {
        tempFile << arrayProduct[i].id << " " << arrayProduct[i].code << " " << arrayProduct[i].libelle << " " << arrayProduct[i].price << " " << arrayProduct[i].quantity << " " << arrayProduct[i].idCategory << endl;
    }

    remove("products.dat");
    rename("temp.dat", "products.dat");

    cout << "Le fichier de produits a ete triee ave success ....." << endl;
}
void displayProductsByCategory()
{
    ifstream Cat{"categories.txt"};
    ifstream Pro{"products.dat", ios::binary};

    Product P;
    Category C;

    while (Cat >> C.idCategory >> C.libelle)
    {
        cout << "CATEGORIE" << C.idCategory << ":  " << C.libelle << endl;

        while (Pro >> P.id >> P.code >> P.libelle >> P.price >> P.price >> P.quantity >> P.idCategory)
        {
            if (P.idCategory == C.idCategory)
            {
                cout << "\t" << P.id << " " << P.code << " " << P.libelle << " " << P.price << " " << P.quantity << endl;
            }
        }
    }
}
