#pragma once

#include <string>
class Brain {
   public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    virtual ~Brain();
    static const short int NUMBER_IDEAS = 100;
    void printIdeas(void) const;
    void copyBrain(void);
    std::string ideas_[100];  //should be private ?
};
