#ifndef __PRODUCTS__HPP
#define __PRODUCTS__HPP

typedef struct
{
    int id;
    char code[10];
    char libelle[50];
    float price;
    int quantity;
    int idCategory;
} Product;

void createProduct();
void deleteProduct();
void displayProducts();
void mostValuableProduct();
void sortFileByPrices();
void displayProductsByCategory();
int getNewProductId();
void setNewProductId(int id);

#endif