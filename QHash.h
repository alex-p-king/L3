#pragma once
#include "CHash.h"

class QHash : public CHash {
    public:
        int hash(std::string name);
        bool insert(Review r);
        std::string table = "Quadratic: ";
};