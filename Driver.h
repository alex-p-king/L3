#pragma once
#include "Review.h"
#include "DHash.h"
#include "QHash.h"


class Driver{
	public:
		Driver();
		~Driver();	
		void run();
		void menu();
		void insert();
		void remove();
		void findByRating();
		void findByPrice();
		void print();
		void test();
		void printResults(std::pair<bool,bool> results, std::string op);
	private:
		QHash m_Qtable;
		DHash m_Dtable;


};
