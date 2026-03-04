#ifndef __User_H__
#define __User_H__

#include "BaseEntity.hpp"

#include <string>

using namespace std;

class User : public BaseEntity
{

private:
    string firstname;
    string lastname;
    string email;
    string password;

public:
    User()
    {
        BaseEntity();
    };

    User(string email, string password)
    {
        this->email = email;
        this->password = password;
    }

    User(string firstname, string lastname, string email, string password)
    {
        this->firstname = firstname;
        this->lastname = lastname;
        this->email = email;
        this->password = password;
        BaseEntity();
    };

    // getters
    string getFirstname()
    {
        return this->firstname;
    }

    string getLastname()
    {
        return this->lastname;
    }

    string getEmail()
    {
        return this->email;
    }

    string getPassword()
    {
        return this->password;
    }

    // setters
    void setFirstname(string firstname)
    {
        this->firstname = firstname;
    }

    void setLastname(string lastname)
    {
        this->lastname = lastname;
    }

    void setEmail(string email)
    {
        this->email = email;
    }

    void setPassword(string password)
    {
        this->password = password;
    }
};

#endif //__User_H__