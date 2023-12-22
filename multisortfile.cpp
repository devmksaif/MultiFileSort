#include "multisortfile.h"


FileManagerMultiSort::FileManagerMultiSort(int& Choice,string& FilePath,string& OutFilePath)
{
	this->FilePath = FilePath;
	this->OutPutFile = OutFilePath;
	switch (Choice)
	{
	case 1:
		FileSortBasedNumber(this->FilePath, this->OutPutFile);
		break;
	case 2:
		FileSortBasedString(FilePath);
		break;
	case 3:
		FileSortBoth(FilePath);
		break;

	}
	
	
}

FileManagerMultiSort::~FileManagerMultiSort()
{
}

void FileManagerMultiSort::FileSortBasedNumber(string& FilePath, string& OutPutFile)
{
	ifstream MainFile(FilePath);
	ofstream OutFile(OutPutFile);
	string Line;
	map<int, string> temp_map;
	int i = 0;
	vector<int> temp_vec;
	malloc(sizeof(temp_vec));

	if (MainFile.is_open())
	{
		
		while (getline(MainFile, Line))
		{
			temp_map[i] = Line;
			i++;
		}
		MainFile.close();
	}
	else
	{
		cout << "File Not Found ! ";
	}
	int assigner;
	for (auto it = temp_map.begin(); it != temp_map.end(); ++it) {
		// 'it->first' is the key, 'it->second' is the value
		int key = it->first;
		string value = it->second;
		if (value._Equal("#numbers"))
		{
			assigner = key+1;
			for (auto is = temp_map.lower_bound(assigner); is != temp_map.end(); ++is)
			{
				string value = is->second;
				int x = stoi(value);
				if (value != "#string" || value != "#numbers")
				{
					temp_vec.push_back(x);
				}
				else
				{
					break;
				}

			}
		}
	}
	sort(temp_vec.begin(), temp_vec.end());
	OutFile << "#numbers" << "\n";
	for (const auto& line : temp_vec)
	{
		OutFile << line << "\n";
	}
	OutFile.close();// closed
	

}

void FileManagerMultiSort::FileSortBasedString(string& FilePath)
{
}

void FileManagerMultiSort::FileSortBoth(string& FilePath)
{
}
