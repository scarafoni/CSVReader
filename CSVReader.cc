#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

char* str2arr(string str) 
{
	char* writable = new char[str.size() + 1];
	copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';
	return writable;
}

int main(int argc, char* argv[])
{
	
	//get the filename and desired columns
	char* fileName = argv[1];
	vector<string> columns;
	for(int i = 2; i < argc; i++)
		columns.push_back(argv[i]);
	
	//open the file
	ifstream csvFile(fileName);

	//find the column numbers and save them
	string line = "fail";
	getline(csvFile,line);
	vector<string> colNames;
	vector<int> colPos;
	char* tok;
	for(tok=strtok(str2arr(line),","); tok; tok=strtok(NULL,","))
		for(int i=0; i<columns.size(); i++)
			if(strcmp((columns[i]).c_str(),tok) == 0)
			{
				colNames.push_back(tok);
				colPos.push_back(i);
			}
	delete tok;

	for(int i = 0; i < colNames.size(); i++)
		cout << colNames[i] << "\n";
	//go through line by line
	return 0;
}
