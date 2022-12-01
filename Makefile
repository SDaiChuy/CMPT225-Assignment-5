all: hftd

hftd: hashFunctionTestDriver.o List.o Memeber.o
	g++ -Wall -o hftd hashFunctionTestDriver.o List.o. Memeber.o

hashFunctionTestDriver.o: hashFunctionTestDriver.cpp
	g++ -Wall -c hashFunctionTestDriver.cpp

List.o: List.cpp
	g++ -Wall -c List.cpp

Member.o: Member.cpp
	g++ -Wall -c Memebr.cpp

clean:
	rm -f hftd *.o