#include "DHash.h"

int DHash::hash(std::string name){
    //calculate the sum of the chars in name
    int value = 0;
    int i = 1;
    bool invalid = false;
    for(unsigned int i = 0; i < name.size(); i++){
        value += static_cast<int>(name[i]);
    }
    int index = value % this->getBucketSize();
    int base = index;
    while(invalid == false){
        if(m_arr[base].getName() == ""){
            return base;
        }
        else if(i > 10){
            invalid = true;
        }
        else{
            base = (index + i*(r -(value % r))) % this->getBucketSize();
        }
        i++;
    }
    std::cout << "***ERROR*** DOUBLE HASHING FAILED\n";
    return -1;

}

bool DHash::insert(Review r){
    int index = hash(r.getName());
    if(index == -1){
        std::cout << "***ERROR*** Quadratic Probing Failed\n";
        return false;
    }
    m_arr[index] = r;
    return true;
}

