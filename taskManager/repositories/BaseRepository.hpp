#ifndef __BASEREPOSITORY_H__
#define __BASEREPOSITORY_H__

#include <string>
#include <fstream>
#include <iostream>
#include <fstream>

using namespace std;

class BaseRepository
{
private:
    int id;

protected:
    string path;

public:
    BaseRepository()
    {
        this->id = 0;
        this->path = "../datas/";
    }
    ~BaseRepository();

    void destroy(int id, string file)
    {
        ifstream f{this->path + file};
        ofstream temp{this->path + "temp.txt"};

        if (f.is_open())
        {
            string line;
            while (getline(f, line))
            {
                if (line.find(to_string(id)) != string::npos)
                    continue;
                temp << line << endl;
            }
        }
        f.close();
        temp.close();

        string tempPath = this->path + "temp.txt";
        string toDelete = this->path + file;

        remove(toDelete.c_str());
        rename(tempPath.c_str(), toDelete.c_str());
    }

    void update(int id, string file, const string &newLine)
    {
        ifstream f(this->path + file);
        ofstream temp(this->path + "temp.txt");

        if (!f.is_open() || !temp.is_open())
        {
            cout << "Erreur ouverture fichier" << endl;
            return;
        }

        string line;
        while (getline(f, line))
        {
            // Extraire l'ID de la ligne (avant le premier ';')
            size_t pos = line.find(';');
            if (pos != string::npos)
            {
                int lineId = stoi(line.substr(0, pos));
                if (lineId == id)
                {
                    temp << newLine << endl; // nouvelle ligne
                    continue;                // ligne modifiée, on continue
                }
            }
            temp << line << endl; // ligne inchangée
        }

        f.close();
        temp.close();

        string tempPath = this->path + "temp.txt";
        string toDelete = this->path + file;

        remove(toDelete.c_str());
        rename(tempPath.c_str(), toDelete.c_str());
    }

    int getLastInsertId()
    {
        return this->loadLastInsertId();
    }

    void setLastInsertId(int id)
    {
        ofstream f{this->path + "lastUserInsertId.txt"};

        if (f.is_open())
        {
            f << id;
        }
        f.close();
    }

    int loadLastInsertId()
    {
        ifstream f{this->path + "lastUserInsertId.txt"};

        if (f.is_open())
        {
            f >> this->id;
        }
        f.close();
        return this->id;
    }
};

#endif //__BASEREPOSITORY_H__