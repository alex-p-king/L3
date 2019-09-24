#include "Review.h"



Review::Review(){

}

Review::~Review(){

}

void Review::setName(std::string name){
    m_name = name;
}

void Review::setPrice(std::string price){
    m_price = price;
}

void Review::setRating(int rating){
    m_rating = rating;
}

std::string Review::getName()const{
    return m_name;
}

std::string Review::getPrice()const{
    return m_price;
}

int Review::getRating()const{
    return m_rating;
}

void Review::print()const{
    std::cout << "{" << m_name << ", " << m_rating << ", " << m_price << "}\n";
}