#ifndef __TASK_H__
#define __TASK_H__

#include "BaseEntity.hpp"

#include <string>

using namespace std;

class Task : public BaseEntity
{
private:
    string title;
    string description;
    int userId;

public:
    Task(string title, string description, int userId)
    {
        this->id = ++Task::id;
        this->title = title;
        this->description = description;
        this->userId = userId;
        BaseEntity();
    }

    // getters
    string getTitle()
    {
        return this->title;
    }
    string getDescription()
    {
        return this->description;
    }
    int getUserId()
    {
        return this->userId;
    }

    // setters
    void setTitle(string title)
    {
        this->title = title;
    }
    void setDescription(string description)
    {
        this->description = description;
    }
    void setUserId(int userId)
    {
        this->userId = userId;
    }

    ~Task() {}
};

#endif //__TASK_H__
