/*
	Name: Matthieu 'FONTY' Lafotnaine
	Date: 10/4/2016

	Purpose: Game Tools & Pipelines - A1
	- Take input from text file containing a list of vertices from a mesh
	- Search by point to see if there are any vertices which are a certain point of precision from eachother
	- Any points within range of eachother must be combined 
*/

#include "function.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));
	
	if (argc > 1)
	{
		// PROPER

		std::cout << "There are " << argc << " arguments." << std::endl;
		for (int i = 0; i < argc; ++i)
		{
			std::cout << i << " " << argv[i] << std::endl;
		}

		std::stringstream convert(argv[3]);
		float myFloat;
		if (!(convert >> myFloat))
		{
			myFloat = 0;
		}

		GTAP_PROJ::VectorCompressor myComp(myFloat, argv[1], argv[2]);
		myComp.RunCompression();
	}
	else
	{
		// TESTER
		
		std::cout << std::endl;
		std::cout << " MESSAGE: Generating temp-use Mesh file with " << TEST_VECS << " vectors with coordinate units reaching\n\t  a range of " << RANGE_VAL << " units." << std::endl;
		Write_Vector_File();

		GTAP_PROJ::VectorCompressor myComp(DIST_THRESHOLD, TESTFILE_NAME, NEW_TESTFILE_NAME);
		myComp.RunCompression();

		std::cout << std::endl;
		std::cout << " MESSAGE: Generated file and compressed file are found in the project folder.\n\n\t  One of these awful pauses for my own UI appreciation. " << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		system("PAUSE");
	}

	return 0;
}