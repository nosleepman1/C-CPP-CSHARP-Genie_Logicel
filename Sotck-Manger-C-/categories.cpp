#include "categories.hpp"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int getNewCategoryId()
{
    ifstream C{"categoriesID.txt"};
    int id;
    C >> id;
    return id;
}

void setNewCategoryId(int id)
{
    ofstream C{"categoriesID.txt"};

    C << id;
}

void createCategory()
{
    Category C;

    cout << "Libelle:  ";
    cin >> C.libelle;

    C.idCategory = getNewCategoryId() + 1;

    ofstream Cat{"categories.txt", ios::app};

    Cat << C.idCategory << " " << C.libelle << endl;

    setNewCategoryId(C.idCategory);
}

void displayCategories()
{

    ifstream Cat{"categories.txt", ios::app};

    Category C;

    cout << "Liste des Categories";
    while (Cat >> C.idCategory >> C.libelle)
    {
        cout << C.idCategory << " " << C.libelle << endl;
    }
}

void deleteCatgory()
{
    displayCategories();

    ofstream temp{"temp.txt", ios::app};
    ifstream Cat{"categories.txt"};
    Category C;

    int toDelete;
    cout << "\n\nSaisir l'ID de la categorie a supprimer: ";
    cin >> toDelete;

    if (Cat.is_open())
    {
        while (Cat >> C.idCategory >> C.libelle)
        {
            if (C.idCategory == toDelete)
            {
                continue;
            }
            temp << C.idCategory << " " << C.libelle;
        }
    }

    temp.close();
    Cat.close();

    remove("categories.txt");
    rename("temp.txt", "categories.txt");
}