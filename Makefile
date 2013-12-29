CSVReader : CSVReader.o
	gcc CSVReader.o -o CSVReader
CSVReader.o : CSVReader.cc
	gcc -c CSVReader.cc
clean :
	rm *.o
