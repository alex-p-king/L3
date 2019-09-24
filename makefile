CHash: main.o Driver.o Review.o CHash.o QHash.o DHash.o
	g++ -std=c++11 -g -Wall main.o Driver.o Review.o CHash.o QHash.o DHash.o  -o CHash

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Driver.o: Driver.h Driver.cpp Review.h Review.cpp CHash.h CHash.cpp QHash.h QHash.cpp DHash.h DHash.cpp
	g++ -std=c++11 -g -Wall -c Driver.cpp 

Review.o: Review.h Review.cpp	
	g++ -std=c++11 -g -Wall -c Review.cpp

CHash.o: CHash.h CHash.cpp Review.h Review.cpp	
	g++ -std=c++11 -g -Wall -c CHash.cpp

QHash.o: QHash.h QHash.cpp Review.h Review.cpp
	g++ -std=c++11 -g -Wall -c QHash.cpp

DHash.o: DHash.h DHash.cpp Review.h Review.cpp
	g++ -std=c++11 -g -Wall -c DHash.cpp

clean:
	rm *.o CHash
