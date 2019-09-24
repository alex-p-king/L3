#pragma once
#include "Review.h"

class CHash{
    public:
        void setBucketSize();
        int getBucketSize(){return m_bucketSize;};
        int getNumElements(){return m_numElements;};
        Review* getArray(){return m_arr;};
        virtual int hash(std::string name) = 0;
        virtual bool insert(Review r) = 0;
        virtual bool remove(std::string word,std::string table);
        virtual bool findByName(std::string name,std::string table);
        virtual Review* findByRating(int rating,std::string table);
        virtual Review* findByPrice(std::string price,std::string table);
        virtual void print();
        
        
    
    protected:
        Review* m_arr = new Review[31];
        int m_bucketSize = 31;
        int m_numElements = 0;


};