#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main(int argc, char* argv[])
{
	
	//get the filename and desired columns
	string fileName = string(argv[0]);
	vector<string> columns;
	for(int i = 1; i < argc; i++)
		columns.push_back(argv[i]);
	
	//open the file
	ifstream csvFile(fileName);

	//find the column numbers and save them
	string line;
	vector<string> lineToks;
	getline(csvGile,line);

	return 0;
}
