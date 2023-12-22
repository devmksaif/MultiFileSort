#include "multisortfile.h"


using namespace std;
int main()
{
	string FilePath = "./file.txt"; // file in
	string OutPath = "./out.txt"; // file out
	int choice = 1;
	FileManagerMultiSort sortFile(choice, FilePath, OutPath);



	return 0;
}