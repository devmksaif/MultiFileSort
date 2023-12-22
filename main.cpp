#include "multisortfile.h"


using namespace std;
int main()
{
	string FilePath = "./file.txt"; // file in
	string OutPath = "./out.txt"; // file out
	int getLines = 0;
	ifstream getChoices("choices.txt");
	string LineOfChoices;
	map<int, string> ChoicesMap;
	if (getChoices.is_open())
	{
		while (getline(getChoices, LineOfChoices))
		{
			getLines++;
			ChoicesMap[getLines] = LineOfChoices;
			
		}
		getChoices.close();
	}

	for (auto it = ChoicesMap.begin(); it != ChoicesMap.end(); it++)
	{
		int key = it->first;
		string value = it->second;
		cout << "[" << key << "] " << value << "\n";
	}
	
	int choice = 0;
	do
	{
		cout << "Enter choices to do with file \n";
		cin >> choice;
	} while (choice <= 0 || choice > getLines);


	FileManagerMultiSort sortFile(choice, FilePath, OutPath);



	return 0;
}