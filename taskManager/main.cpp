#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef struct
{
    string firstName;
    string lastName;
    int age;
} Person;

Person addPerson()
{
    Person p;
    system("cls");
    cout << "Enter first name: ";
    cin >> p.firstName;
    cout << "\nEnter last name: ";
    cin >> p.lastName;
    cout << "\nEnter age: ";
    cin >> p.age;
    return p;
}

int main()
{

    // ofstream f{"persons.txt"};

    // if (f.is_open())
    // {
    //     for (int i = 0; i < 3; i++)
    //     {
    //         Person p = addPerson();
    //         f << p.firstName << " " << p.lastName << " " << p.age << endl;
    //     }
    // }

    // f.close();

    ifstream f{"persons.txt"};
    ofstream temp{"temp.txt"};

    Person p;

    while (f >> p.firstName >> p.lastName >> p.age)
    {
        if (p.firstName == "Abdallah")
        {
            p.firstName = "Youngzer";
        }
        temp << p.firstName << " " << p.lastName << " " << p.age << endl;
    }

    f.close();
    temp.close();

    remove("persons.txt");
    rename("temp.txt", "persons.txt");

    return 0;
}
