#ifndef __USERCONTROLLER_H__
#define __USERCONTROLLER_H__

#include <string>
#include <iostream>

#include "../models/User.hpp"
#include "../repositories/UserRepository.hpp"

using namespace std;

class UserController
{
private:
    UserRepository userRepository;

public:
    UserController()
    {
        this->userRepository = UserRepository();
    }
    ~UserController() {}
    void registerUser()
    {
        User user = Utils::createUser();
        this->userRepository.add(user);
    }

    bool loginUser()
    {
        string email;
        string password;

        cout << "Enter your email: ";
        cin >> email;
        cout << "Enter your password: ";
        cin >> password;
    };

#endif //__USERCONTROLLER_H__