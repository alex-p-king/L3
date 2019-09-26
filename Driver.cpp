#include "Driver.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "QHash.h"
#include "DHash.h"

Driver::Driver(){
	std::ifstream infile;
	std::string line;
	std::string name;
	std::string price;
	int rating;
	int count = 0;
	Review* temp = new Review;
	infile.open("data.txt");
	while (std::getline(infile, line)){
		count++;
	}
	infile.close();

	infile.open("data.txt");
	while (std::getline(infile, line)){
		std::istringstream s(line);
		s >> name >> rating >> price;
		temp->setName(name);
		temp->setPrice(price);
		temp->setRating(rating);
		m_Qtable.insert(*temp);
		m_Dtable.insert(*temp);
	}
	delete temp;
}

Driver::~Driver(){

}

void Driver::run(){
	bool quit = false;
	int uinput = 0;
	while(quit == false){
		menu();
		std::cin >> uinput;
		switch (uinput)
		{
		case 1: insert();
			break;
		case 2: remove();
			break;
		case 3: findByName();
			break;
		case 4: findByRating();
			break;
		case 5: findByPrice();
			break;
		case 6: print();
			break;
		case 7: quit = true;
		default:
			break;
		}
	}
}

void Driver::menu(){
	std::cout << "\n*********************************\n1) insert\n2) remove\n3) Find by Name\n4) Find by Rating\n5) Find by Price\n6) print\n7) Quit\n\nSelection: ";
}

void Driver::insert(){
	Review r;
	std::string name = "TEMPNAME";
	std::string price = "TEMPPRICE";
	bool check1 = true;
	bool check2 = false;
	int rating = -1;
	std::cout << "please enter a Review of format 'restaurant_name [1-5] [$-$$$]\n" << "//: ";
	std::cin >> name >> rating >> price;
	if(rating < 1 || rating > 5){
		check1 = false;
	}
	if(price == "$" || price == "$$" || price == "$$$"){
		check2 = true;
	}
	if(check1 && check2){
		r.setName(name);
		r.setPrice(price);
		r.setRating(rating);
		m_Qtable.insert(r);
		m_Dtable.insert(r);
	}
	else{
		std::cout << "Insertion failed please enter a valid review\n";
	}
}

void Driver::remove(){
	std::string name;
	std::cout << "Enter a name to remove: ";
	std::cin >> name;
	m_Qtable.remove(name,"Quadratic: ");
	m_Dtable.remove(name,"Double: ");
}

void Driver::findByName(){
	std::string name;
	std::cout << "Enter a name to find: ";
	std::cin >> name;
	m_Qtable.findByName(name,"Quadratic: ");
	m_Dtable.findByName(name,"Double: ");
}

void Driver::findByRating(){
	int rating;
	std::cout << "Enter a name to find: ";
	std::cin >> rating;
	if(rating > 0 && rating < 6){
		m_Qtable.findByRating(rating,"Quadratic: ");
		m_Dtable.findByRating(rating,"Double: ");
	}
	else{
		std::cout << "rating must be between 1 and 5\n";
	}
	
	
}

void Driver::findByPrice(){
	std::string price;
	std::cout << "Enter a price to find: ";
	std::cin >> price;
	if((price == "$")||(price == "$$")||(price == "$$$")){
		m_Qtable.findByPrice(price,"Quadratic: ");
		m_Dtable.findByPrice(price,"Double: ");
	}
	else{
		std::cout << "price must be '$' or '$$' or '$$$'\n";
	}
	
}

void Driver::print(){
	Review* qt = m_Qtable.getArray();
	Review* dt = m_Dtable.getArray();
	std::cout << "Quadratic ------- Double\n" << std::endl;
	for(int i = 0; i < m_Qtable.getBucketSize(); i++){
		std::cout << "index[" << i << "]: " << qt[i].print() << " -------  " << dt[i].print() << std::endl; 
	}
}

void Driver::test(){
	
}

