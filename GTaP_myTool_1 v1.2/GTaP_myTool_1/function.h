#pragma once

#include "class.h"

void newline(int p_n)
{
	for (int i = 0; i < p_n; ++i)
	{
		std::cout << (char)(176) << std::endl;
	}
}

float Roll(int p_Range)
{
	return (rand() % p_Range) + 1;
}

void Vector3D_TEST_MAIN()
{
	TEST_TYPE f_Distance;
	GTAP_PROJ::Vector3D<TEST_TYPE> Vec1((TEST_TYPE)Roll(RANGE_VAL), (TEST_TYPE)Roll(RANGE_VAL), (TEST_TYPE)Roll(RANGE_VAL));
	GTAP_PROJ::Vector3D<TEST_TYPE> Vec2((TEST_TYPE)Roll(RANGE_VAL), (TEST_TYPE)Roll(RANGE_VAL), (TEST_TYPE)Roll(RANGE_VAL));
	GTAP_PROJ::Vector3D<TEST_TYPE> Vec3(Vec1);
	newline(3);

	std::cout << " 1 " << Vec1 << std::endl;
	Vec1.Print();
	newline(1);

	std::cout << " 2 " << Vec2 << std::endl;
	Vec2.Print();
	newline(1);

	std::cout << " 2 " << Vec3 << std::endl;
	Vec3.Print();
	newline(1);

	f_Distance = Vec1.Distance_Comp(Vec2);
	std::cout << " Distance between points " << 1 << " and " << 2 << " = " << f_Distance << " units." << std::endl;
	newline(2);

	if (f_Distance <= DIST_THRESHOLD)
		std::cout << " Distance is within threshold." << std::endl;
	else
		std::cout << " Distance is outside of the threshold." << std::endl;

	if (Vec1 == Vec2)
		std::cout << " vectors are equal." << std::endl;
	else
		std::cout << " vectors are unequal." << std::endl;

	newline(2);
}

void SLLNode_TEST_MAIN()
{
	GTAP_PROJ::Vector3D<TEST_TYPE> myVec1(1, 2, 3);
	GTAP_PROJ::Vector3D<TEST_TYPE> myVec2(2, 4, 6);

	GTAP_PROJ::SLLNode<GTAP_PROJ::Vector3D<TEST_TYPE>> Node1(myVec1);
	GTAP_PROJ::SLLNode<GTAP_PROJ::Vector3D<TEST_TYPE>> Node2;


	newline(1);
	myVec1.Print();
	myVec2.Print();
	newline(1);

	std::cout << " Linked List Node: " << std::endl;
	std::cout << " Data: " << Node1.m_Data << std::endl;
	std::cout << " Next: " << Node1.m_Next << std::endl;
	std::cout << " tail: " << Node1.m_Next << std::endl;
	newline(1);

	Node2.InsertAfter(myVec1);
	Node2.InsertAfter(myVec2);

	std::cout << " Linked List Node: " << std::endl;
	std::cout << " Data: " << Node2.m_Data << std::endl;
	std::cout << " Next: " << Node2.m_Next->m_Data << std::endl;
	std::cout << " tail: " << Node2.m_Next->m_Next->m_Data << std::endl;
	newline(1);

	Node1.InsertAfter(myVec2);

	std::cout << " Linked List Node: " << std::endl;
	std::cout << " Data: " << Node1.m_Data << std::endl;
	std::cout << " Next: " << Node1.m_Next->m_Data << std::endl;
	std::cout << " Tail: " << Node1.m_Next->m_Next << std::endl;
	newline(1);	
}

void SingleLinkedList_TEST_MAIN()
{
	/*GTAP_PROJ::SingleLinkedList<int> MyList;
	
	for (int i = 0; i < 21; ++i)
	{
		MyList.Append(i);
	}
	for (int i = 10; i < 15; ++i)
	{
		MyList.Remove_Item(i);
	}
	std::cout << MyList << std::endl;*/

	GTAP_PROJ::SingleLinkedList<GTAP_PROJ::Vector3D<int>> MyVectorList;
	GTAP_PROJ::Vector3D<int> myVector;
	for (int i = 0; i < 21; ++i)
	{
		myVector.Set(i, i * 2, i * 3);
		MyVectorList.Append(myVector);
	}
	for (int i = 4; i < 15; ++i)
	{
		myVector.Set(i, i * 2, i * 3);
		MyVectorList.Remove_Item(myVector);
	}
	std::cout << MyVectorList << std::endl;
	std::cout << MyVectorList << std::endl;
	

}

void Write_Vector_File()
{
	GTAP_PROJ::Vector3D<float> myVec;
	std::ofstream OutVectorFile(TESTFILE_NAME);
	if (OutVectorFile.is_open())
	{
		for (int i = 0; i < TEST_VECS; ++i)
		{
			myVec.Set(Roll(RANGE_VAL), Roll(RANGE_VAL), Roll(RANGE_VAL));
			OutVectorFile << myVec << "\n";
		}
		OutVectorFile.close();
	}
	else
	{
		std::cout << "ERROR: Write_Vector_File(): Unable to open file.";
	}
}

void VectorCompressor_TEST_MAIN()
{
	GTAP_PROJ::VectorCompressor myComp(DIST_THRESHOLD);
	myComp.RunCompression();
}