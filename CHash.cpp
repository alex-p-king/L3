#include "CHash.h"




void CHash::print(){
    for(int i = 0; i < m_bucketSize; i++){
        m_arr[i].print();
    }
}

bool CHash::findByName(std::string name,std::string table){
    for(int i = 0; i < m_bucketSize; i++){
        if(m_arr[i].getName() == name){
            std::cout << table << name << " found in bucket " << i << std::endl;
            return true;
        }
    }
    std::cout << table << name << "could not be found" << std::endl;
    return false;

}

Review* CHash::findByRating(int rating, std::string table){
    Review* temp;
    int count;
    for(int i = 0; i < m_bucketSize; i++){
        if(m_arr[i].getRating() == rating ){
            count++;
        }
    }
    temp = new Review[count];
    count = 0;
    std::cout << table;
    for(int i = 0; i < m_bucketSize; i++){
        if(m_arr[i].getRating() == rating){
            temp[count] = m_arr[i];
            count++;
            std::cout << m_arr[i].getName() << ", ";
        }
    }
    std::cout << std::endl;
    return temp; 
}

Review* CHash::findByPrice(std::string price,std::string table){
    Review* temp;
    int count;
    for(int i = 0; i < m_bucketSize; i++){
        if(m_arr[i].getPrice() == price ){
            count++;
        }
    }
    temp = new Review[count];
    count = 0;
    std::cout << table;
    for(int i = 0; i < m_bucketSize; i++){
        if(m_arr[i].getPrice() == price){
            temp[count] = m_arr[i];
            count++;
            std::cout << m_arr[i].getName() << ", ";
        }
    }
    std::cout << std::endl;
    return temp;
}

bool CHash::remove(std::string word, std::string table){
    Review temp;
    for(int i = 0 ; i < m_bucketSize; i++){
        if(m_arr[i].getName() == word){
            m_arr[i] = temp;
            std::cout << table <<  word << " was successfully deleted from table\n";
            return true;
        }
    }
    std::cout << table << word << " was not found in table\n";
    return false;

}
