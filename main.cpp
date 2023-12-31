#include "Algorithms.h"

int main(int numArgs, char* argPointers[])
{
	if (numArgs != 2) { return 1; }

	Sorting sort;
	int dataSize = 0;

	// Read in data, from file...
	
	// std::string fileName = "files/pokemonRandomSmall.csv";
	std::string fileName = argPointers[1];
	std::ifstream userFile;
	userFile.open(fileName);

	vector<pokemon> poke;
	std::string line;
	pokemon fileInput;
	getline(userFile, line);

	while (!userFile.eof())
    {
		getline(userFile, line);

        if (line.length() != 0)
        {
			// Get Pokemon Number
            std::istringstream iss(line);
            getline(iss, fileInput.dexNum,',');

			// Get Power Level
			std::string str = "";
			getline(iss, str, ',');

			// Convert power level string to integer.
			fileInput.power = stoi(str);
			poke.push_back(fileInput);
        }
    }

	pokemon userData[poke.size()];
	for (int index = 0; index < poke.size(); index++) { userData[index] = poke[index]; }

	userFile.close();

	////**************************************************////

	dataSize = sizeof(userData) / sizeof(userData[0]);


	// CALLING INSERTION SORT METHOD
	std::cout << std::endl << "INSERTION SORT..." << std::endl;

	pokemon insertData[dataSize];
	for (int index = 0; index < dataSize; index++) { insertData[index] = userData[index]; }

	//Sorting the data...
	sort.InsertionSort(insertData, dataSize);

	std::cout << "Finished with " << sort.getInsertCount() << " operations." << std::endl;
	sort.CreateFile(insertData, dataSize, "insertOutputFile.csv");
	

	// CALLING MERGE SORT METHOD
	std::cout << std::endl << "MERGE SORT..." << std::endl;

	pokemon mergeData[dataSize];
	for (int index = 0; index < dataSize; index++) { mergeData[index] = userData[index]; }

	//Sorting the data...
	sort.MergeSort(mergeData, 0, dataSize - 1);

	std::cout << "Finished with " << sort.getMergeCount() << " operations." << std::endl << std::endl << std::endl;
	sort.CreateFile(mergeData, dataSize, "mergeOutputFile.csv");


	// CALLING QUICKSORT METHOD
	std::cout << std::endl << "QUICKSORT..." << std::endl;

	pokemon quickData[dataSize];
	for (int index = 0; index < dataSize; index++) { quickData[index] = userData[index]; }

	//Sorting the data...
	sort.QuickSort(quickData, 0, dataSize - 1);
	
	std::cout << "Finished with " << sort.getQuickCount() << " operations." << std::endl;
	sort.CreateFile(quickData, dataSize, "quickOutputFile.csv");

	return 0;
}