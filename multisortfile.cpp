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
		FileSortBasedString(this->FilePath, this->OutPutFile);
		break;
	case 3:
		FileSortBoth(this->OutPutFile);
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
	int i = 0;

	

	if (MainFile.is_open())
	{
		
		while (getline(MainFile, Line))
		{
			(*temp_map_ints)[i] = Line;
			i++;
		}
		MainFile.close();
	}
	else
	{
		cout << "File Not Found ! ";
	}
	int assigner;
	for (auto it = temp_map_ints->begin(); it != temp_map_ints->end(); ++it) {
		// 'it->first' is the key, 'it->second' is the value
		int key = it->first;
		string value = it->second;
		if (value._Equal("#numbers"))
		{
			assigner = key+1;
			for (auto is = temp_map_ints->lower_bound(assigner); is != temp_map_ints->end(); ++is)
			{
				string value = is->second;
				int x = stoi(value);
				if (value != "#strings" || value != "#numbers")
				{
					temp_vec_ints->push_back(x);
				}
				else
				{
					break;
				}

			}
		}
	}
	sort(temp_vec_ints->begin(), temp_vec_ints->end());
	OutFile << "#numbers" << "\n";
	for (const auto& line : *temp_vec_ints)
	{
		OutFile << line << "\n";
	}
	OutFile.close();// closed
	
	
}

void FileManagerMultiSort::FileSortBasedString(string& FilePath, string& OutFilePath)
{
	ifstream inFile(FilePath);
	ofstream outFile(OutFilePath);
	string Line;
	
	int i = 0;

	if (inFile.is_open())
	{
		while (getline(inFile, Line))
		{
			(*temp_map_strings)[i] = Line;
			i++;
		}
		inFile.close();
	}
	int assigner = 0;
	for (auto it = (*temp_map_strings).begin(); it != (*temp_map_strings).end(); ++it)
	{
		
		int key = it->first;
		string value = it->second;
		
		
		if (value._Equal("#strings"))
		{
			
			assigner = key;
			for (auto is = (*temp_map_strings).lower_bound(assigner+1); is != (*temp_map_strings).end(); ++is)
			{
				int keyd = is->first;
				string valued = is->second;
				temp_vec_strings->push_back(valued);
				if (valued._Equal("#numbers"))
					break;

			}
			auto it = std::find(temp_vec_strings->begin(), temp_vec_strings->end(), "#numbers");
			temp_vec_strings->erase(it);

		}
		else
		{
			cout << "No strings found";
		}

	}
	sort(temp_vec_strings->begin(), temp_vec_strings->end());
	outFile << "#strings" << "\n";
	for(auto &line : *temp_vec_strings)
	{
		outFile << line << "\n";
	}
	outFile.close();
	


}

void FileManagerMultiSort::FileSortBoth(string& OutFilePath)
{
	FileSortBasedNumber(FilePath, OutFilePath);
	FileSortBasedString(FilePath, OutFilePath);

	ofstream OutFile(OutFilePath);
	OutFile << "#strings" << "\n";
	for (const auto& strings : *temp_vec_strings)
	{
		OutFile << strings << "\n";
	}
	OutFile << "#numbers" << "\n";
	for (const auto& numbers : *temp_vec_ints)
	{
		OutFile << numbers << "\n";
	}
	OutFile.close();
	
}
