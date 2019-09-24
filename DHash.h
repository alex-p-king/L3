#pragma once
#include "CHash.h"


class DHash : public CHash {
    public:
        int hash(std::string name);
        bool insert(Review r);
        std::string table = "Double: ";
    private:
        int r = 29;
};