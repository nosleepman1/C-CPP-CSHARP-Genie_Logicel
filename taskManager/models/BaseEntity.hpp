#ifndef __BASEENTITY_H__
#define __BASEENTITY_H__

#include <string>
#include <ctime>

using namespace std;

class BaseEntity
{

protected:
    static int id;
    time_t createdAt;
    time_t updatedAt;

public:
    BaseEntity()
    {
        this->createdAt = time(0);
        this->updatedAt = time(0);
    };

    ~BaseEntity() {};

    int getId()
    {
        return this->id;
    }

    time_t getCreatedAt()
    {
        return this->createdAt;
    }

    time_t getUpdatedAt()
    {
        return this->updatedAt;
    }

    void setUpdatedAt()
    {
        this->updatedAt = time(0);
    }
};

#endif //__BASEENTITY_H__