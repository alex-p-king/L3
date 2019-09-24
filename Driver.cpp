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
		case 3: findByRating();
			break;
		case 4: findByPrice();
			break;
		case 5: print();
			break;
		case 6: quit = true;
		default:
			break;
		}
	}
}

void Driver::menu(){
	std::cout << "\n*********************************\n1) insert\n2) remove\n3) Find by Rating\n4) Search by Price\n5) Print\n6) Quit\n\nSelection: ";
}

void Driver::insert(){
	Review r;
	std::string name = "TEMPNAME";
	std::string price = "TEMPPRICE";
	int rating = -1;
	std::cout << "please enter a Review of format 'restaurant_name [1-5] [$-$$$]\n" << "//: ";
	std::cin >> name >> rating >> price;
	r.setName(name);
	r.setPrice(price);
	r.setRating(rating);
	bool qt = false;
	bool dt = false;
	qt = m_Qtable.insert(r) ? true : false;
	dt = m_Dtable.insert(r) ? true : false;
	if(qt){
		r.print();
		std::cout << "Was inserted"; 
	}
	else{
		r.print();
		std::cout << "Was not inserted";
	}
	if(dt){
		r.print();
		std::cout << "Was inserted";
	}
	else{
		r.print();
		std::cout << "Was not inserted";
	}

}

void Driver::remove(){
	std::string name;
	std::cout << "Enter a name to remove: ";
	std::cin >> name;
	bool qt = m_Qtable.remove(name);
	bool dt = m_Dtable.remove(name);
	std::pair <bool, bool> results (qt,dt);
	printResults(results, "remove");
	

}

void Driver::findByRating(){
	int rating;
	std::cout << "Enter a name to find: ";
	std::cin >> rating;
	bool qt = m_Qtable.findByRating(rating);
	bool dt = m_Dtable.findByRating(rating);
	std::pair <bool, bool> results (qt,dt);
	printResults(results, "fRating");
}

void Driver::findByPrice(){
	std::string price;
	std::cout << "Enter a price to find: ";
	std::cin >> price;
	bool qt = m_Qtable.findByPrice(price);
	bool dt = m_Dtable.findByPrice(price);
	std::pair <bool, bool> results (qt,dt);
	printResults(results, "fPrice");
}

void Driver::print(){
	m_Qtable.print();
	m_Dtable.print();
}

void Driver::test(){
	
}
void Driver::printResults(std::pair<bool,bool> results, std::string op){
	if(results.first){
		std::cout << "QTable: TRUE\n"; 
	}
	else{
		std::cout << "QTable: FALSE\n";
	}
	if(results.second){
		std::cout << "DTable: TRUE\n";
	}
	else{
		std::cout << "DTable: FALSE\n";
	}
}

