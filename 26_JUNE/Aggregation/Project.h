#ifndef PROJECT_H
#define PROJECT_H

#include<iostream>

class Project
{
private:
    std::string _id;
    unsigned int _teamsize;
    float _budget;
public:
    Project(std:: string id, unsigned int size, float budget);

    ~Project();

    std::string getid() const { return _id; }

    unsigned int getteamsize() const { return _teamsize; }

    float getbudget() const { return _budget; }

    friend std::ostream &operator<<(std::ostream &os, const Project &rhs) {
        os << "_id: " << rhs._id
           << " _teamsize: " << rhs._teamsize
           << " _budget: " << rhs._budget;
        return os;
    }

    
};
#endif // PROJECT_H