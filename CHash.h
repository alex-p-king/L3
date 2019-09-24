#pragma once
#include "Review.h"

class CHash{
    public:
        void setBucketSize();
        int getBucketSize();
        int getNumElements();
        virtual int hash(std::string name) = 0;
        virtual bool insert(Review r) = 0;
        virtual bool remove(std::string word);
        virtual bool findByName(std::string name);
        virtual Review* findByRating(int rating);
        virtual Review* findByPrice(std::string price);
        virtual void print();
        
        
    
    protected:
        Review* m_arr = new Review[31];
        int m_bucketSize = 31;
        int m_numElements = 0;

};