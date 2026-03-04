#ifndef __VIEWS_HPP__
#define __VIEWS_HPP__

#include <iostream>
using namespace std;

int Menu()
{
    int choix;

    cout << "1. Ajouter une categorie" << endl;
    cout << "2. Ajouter un produit" << endl;
    cout << "3. Afficher les produits" << endl;
    cout << "4. Trier Le fichier de produit sur les prix" << endl;
    cout << "5. Afficher le produit le plus cher" << endl;
    cout << "6. Supprimer un produit" << endl;
    cout << "7. Afficher les produits part categorie" << endl;
    cout << "8. Supprimer une categorie" << endl;
    cout << "9. Quitter" << endl;

    cout << "\n\n Votre choix:  ";
    cin >> choix;

    return choix;
}

#endif