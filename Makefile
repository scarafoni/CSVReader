CSVReader : CSVReader.o
	g++ CSVReader.o -o CSVReader
CSVReader.o : CSVReader.cc
	g++ -c CSVReader.cc
clean :
	rm *.o
