#pragma once
#include <string>
#include <iostream>

class Review{
    public:
        Review();
        ~Review();
        void setName(std::string name);
        void setPrice(std::string price);
        void setRating(int rating);
        std::string getName()const;
        std::string getPrice()const;
        int getRating()const;
        void print()const;

        Review operator =(const Review& x){
            this->m_name = x.m_name;
            this->m_price = x.m_price;
            this->m_rating = x.m_rating;
            return *this;
        }
        
    private:
        std::string m_name = "";
        std::string m_price = "";
        int m_rating = 0;
};