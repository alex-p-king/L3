#include <iostream>
#include "Driver.h"

int main(){
	Driver* myDriver = new Driver;
	myDriver->run();
	delete myDriver;
}
