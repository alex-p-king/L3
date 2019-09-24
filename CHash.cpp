#include "CHash.h"



int CHash::getBucketSize(){
    return m_bucketSize;
}

int CHash::getNumElements(){
    return m_numElements;
}

void CHash::print(){
    for(int i = 0; i < m_bucketSize; i++){
        m_arr[i].print();
    }
}

bool CHash::findByName(std::string name){
    for(int i = 0; i < m_bucketSize; i++){
        if(m_arr[i].getName() == name){
            std::cout << "found '" << name << "' in bucket " << i << std::endl;
            return true;
        }
    }
        return false;

}

Review* CHash::findByRating(int rating){
    Review* temp;
    int count;
    for(int i = 0; i < m_bucketSize; i++){
        if(m_arr[i].getRating() == rating ){
            count++;
        }
    }
    temp = new Review[count];
    count = 0;
    for(int i = 0; i < m_bucketSize; i++){
        if(m_arr[i].getRating() == rating){
            temp[count] = m_arr[i];
            count++;
        }
    }
    return temp; 
}

Review* CHash::findByPrice(std::string price){
    Review* temp;
    int count;
    for(int i = 0; i < m_bucketSize; i++){
        if(m_arr[i].getPrice() == price ){
            count++;
        }
    }
    temp = new Review[count];
    count = 0;
    for(int i = 0; i < m_bucketSize; i++){
        if(m_arr[i].getPrice() == price){
            temp[count] = m_arr[i];
            count++;
        }
    }
    return temp; 
}

bool CHash::remove(std::string word){
    Review temp;
    for(int i = 0 ; i < m_bucketSize; i++){
        if(m_arr[i].getName() == word){
            m_arr[i] = temp;
            return true;
        }
    }
    return false;

}
