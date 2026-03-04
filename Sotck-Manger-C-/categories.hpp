#ifndef __CATEGORIES__HPP
#define __CATEGORIES__HPP

typedef struct
{
    int idCategory;
    char libelle[50];
} Category;

void createCategory();
void deleteCatgory();
void displayCategories();
int getNewCategoryId();
void setNewCategoryId(int id);

#endif