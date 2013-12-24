#include<iostream>
#include<fstream>
#include<string>

int main()
{
	string line;
	ifstream csvFile("test.csv");
	if(csvFile.is_open())
	{
		while(getline(csvFile))
		{
			std::cout << line << "\n"
		}
	}
	csvTest.close();
	return 0;
}
