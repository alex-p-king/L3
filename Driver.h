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
		void findByName();
		void findByRating();
		void findByPrice();
		void print();
		void test();
	private:
		QHash m_Qtable;
		DHash m_Dtable;


};
