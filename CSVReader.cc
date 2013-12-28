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
	char* tok1;
	int pos = 0;
	for(tok1=strtok(str2arr(line),","); tok1; tok1=strtok(NULL,","))
	{
		for(int i=0; i<columns.size(); i++)
		{
			if(strcmp((columns[i]).c_str(),tok1) == 0)
			{
				//cout << columns[i] << " " << pos<<"\n";
				colNames.push_back(tok1);
				colPos.push_back(pos);
			}
		}
		pos++;
	}
	delete tok1;
	//go through line by line, find all elements in select columns
	vector<string> finTab[colNames.size()];
	char* tok2;
	while(getline(csvFile,line))
	{
		pos = 0;
		for(tok2=strtok(str2arr(line),","); tok2; tok2=strtok(NULL,","))
		{
			for(int i=0; i<colPos.size(); i++)
			{
				if(pos == colPos[i])
					finTab[i].push_back(tok2);	
			}
			pos++;
		}
	}
	delete(tok2);

	//print results to new file
	ofstream toWrite("results.txt");
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < finTab[i].size(); j++)
		{
			toWrite << finTab[i][j];
			if(j < finTab[i].size()-1)
				toWrite << ",";
		}
		toWrite <<"\n";
	}
	toWrite.close();
	return 0;
}
