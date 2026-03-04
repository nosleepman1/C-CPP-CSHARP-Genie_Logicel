#ifndef __AUTH_H__
#define __AUTH_H__

#include <string>
#include <iostream>

#include "../models/User.hpp"
#include "../repositories/UserRepository.hpp"

using namespace std;

class Auth
{

private:
    static int authId;

public:
    Auth()
    {
        Auth::authId = 0;
    };
    ~Auth() {};

    static int getAuthId()
    {
        return Auth::authId;
    }
    static void setAuthId(int id)
    {
        Auth::authId = id;
    }

    static User login(string email, string password)
    {
        UserRepository userRepository = UserRepository();
        User user;

        ifstream f{userRepository.path + "users.txt"};

        if (f.is_open())
        {
            while (f >> user.id >> user.firstname >> user.lastname >> user.email >> user.password)
            {
                if (user.email == email && user.password == password)
                {
                    Auth::setAuthId(user.id);
                    return user;
                }
            }
        }
        f.close();
        return user;
    }

    static void logout()
    {
        Auth::setAuthId(0);
    }
};

#endif //__AUTH_H__