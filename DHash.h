#pragma once
#include "CHash.h"


class DHash : public CHash {
    public:
        int hash(std::string name);
        bool insert(Review r);
    private:
        int r = 29;
};