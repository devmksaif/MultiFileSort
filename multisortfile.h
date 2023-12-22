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
	void FileSortBasedString(string& FilePath);
	void FileSortBoth(string& FilePath);
	
private:
	string FilePath;
	string OutPutFile;

};