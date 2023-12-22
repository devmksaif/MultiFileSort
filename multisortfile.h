#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

class FileManagerMultiSort
{
public:
	FileManagerMultiSort(int& Choice,string& FilePath , string& OutFilePath); // Constructor for whole firework
	~FileManagerMultiSort();
	void FileSortBasedNumber(string& FilePath,string& OutPutFile);
	void FileSortBasedString(string& FilePath,string& OutFilePath);
	void FileSortBoth(string& OutFilePath);
	
private:
	string FilePath;
	string OutPutFile;
	vector<string>* temp_vec_strings = new vector<string>[sizeof(vector<string>)];
	map<int, string>* temp_map_strings = new map<int, string>;
	map<int, string>* temp_map_ints = new map<int, string>;
	vector<int>* temp_vec_ints = new vector<int>[sizeof(vector<string>)];

};