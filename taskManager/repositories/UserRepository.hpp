#ifndef __USERREPOSITORY_H__
#define __USERREPOSITORY_H__

#include "BaseRepository.hpp"
#include "../models/User.hpp"

#include <string>
#include <fstream>

using namespace std;

class UserRepository : public BaseRepository
{
private:
public:
    UserRepository()
    {
        this->path += "users.txt";
    }
    ~UserRepository();

    void save(User user)
    {
        ofstream f{this->path, ios::app};

        int id = this->getLastInsertId();

        if (f.is_open())
        {
            f << id++ << " " << user.getFirstname() << " " << user.getLastname() << " " << user.getEmail() << " " << user.getPassword() << endl;
        }
        f.close();

        this->setLastInsertId(id);
    }
};

#endif //__USERREPOSITORY_H