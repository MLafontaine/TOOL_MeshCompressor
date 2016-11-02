#pragma once

#include "definition.h"

namespace GTAP_PROJ
{
	template <typename Datatype>
	class Vector3D
	{
	private:

		Datatype m_X;
		Datatype m_Y;
		Datatype m_Z;

		friend std::ostream& operator<< (std::ostream& p_os, const Vector3D<Datatype>& p_obj)
		{
			p_os /*<< ":["*/ << std::setw(6) << std::right << p_obj.Get_X() << " " << std::setw(6) << std::right << p_obj.Get_Y() << " " << std::setw(6) << std::right << p_obj.Get_Z() /*<< "]"*/;
			return p_os;
		}
		friend std::ofstream& operator<< (std::ofstream& p_ofs, const Vector3D<Datatype>& p_obj)
		{
			p_ofs /*<< ":["*/ << std::setw(6) << std::right << p_obj.Get_X() << " " << std::setw(6) << std::right << p_obj.Get_Y() << " " << std::setw(6) << std::right << p_obj.Get_Z() /*<< "]"*/;
			return p_ofs;
		}

	public:

		Vector3D()
		{
			Set(0, 0, 0);
		}
		Vector3D(Datatype p_x, Datatype p_y, Datatype p_z)
		{
			Set(p_x, p_y, p_z);
		}
		Vector3D(const Vector3D<Datatype>& p_Vec)
		{
			m_X = p_Vec.Get_X();
			m_Y = p_Vec.Get_Y();
			m_Z = p_Vec.Get_Z();
		}

		bool operator== (const Vector3D<Datatype>& p_Vec)
		{
			if ( m_X == p_Vec.m_X && m_Y == p_Vec.m_Y && m_Z == p_Vec.m_Z )
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		void Set(Datatype p_x, Datatype p_y, Datatype p_z)
		{
			m_X = p_x;
			m_Y = p_y;
			m_Z = p_z;
		}
		Datatype Get_X() const
		{
			return m_X;
		}
		Datatype Get_Y() const
		{
			return m_Y;
		}
		Datatype Get_Z() const
		{
			return m_Z;
		}
		float Distance_Comp(const Vector3D& p_Data) const
		{
			// instantiate return value
			float f_distance = 0.0f;
			// create vector containing the distance values between this point and the comparison point
			Vector3D tempVector((static_cast<Datatype>(p_Data.Get_X()) - m_X), (static_cast<Datatype>(p_Data.Get_Y()) - m_Y), (static_cast<Datatype>(p_Data.Get_Z()) - m_Z));
			// use PYTHAGOREAN theory to discover the distance between the two points using the values from the new vector
			f_distance = sqrtf(	pow( static_cast<float>(tempVector.Get_X()), 2 ) + pow(	static_cast<float>(tempVector.Get_Y()), 2 ) + pow( static_cast<float>(tempVector.Get_Z()), 2 ) );
			// return distance
			return f_distance;
		}

		void Print() const
		{
			std::cout << " X: " << std::setw(5) << std::left << m_X << " Y: " << std::setw(5) << std::left << m_Y << " Z: " << std::setw(5) << std::left << m_Z << std::endl;
		}
		
		~Vector3D()
		{
		}
	};


	template <typename Datatype>
	class SLLNode
	{
	public:

		Datatype m_Data;
		SLLNode<Datatype>* m_Next;

		friend std::ostream& operator<< (std::ostream& p_os, GTAP_PROJ::SLLNode<Datatype>& p_obj)
		{
			p_os << p_obj.m_Data << "\n";
			return p_os;
		}
		friend std::ofstream& operator<< (std::ofstream& p_ofs, GTAP_PROJ::SLLNode<Datatype>& p_obj)
		{
			p_ofs << p_obj.m_Data << "\n";
			return p_ofs;
		}

	public:

		SLLNode()
		{
			m_Data = Datatype();
			m_Next = nullptr;
		}
		SLLNode(Datatype p_Data)
		{
			m_Data = p_Data;
			m_Next = nullptr;
		}

		bool operator== (const SLLNode<Datatype>& p_obj)
		{
			if (m_Data == p_obj.m_Data)
				return true;
			else
				return false;
		}
		bool operator!= (const SLLNode<Datatype>& p_obj)
		{
			if (m_Data != p_obj.m_Data)
				return true;
			else
				return false;
		}

		void InsertAfter(Datatype p_Data)
		{
			SLLNode<Datatype>* newNode = new SLLNode<Datatype>;
			if (newNode)
			{
				newNode->m_Data = p_Data;
				newNode->m_Next = m_Next;
				m_Next = newNode;
			}
			else
			{
				std::cout << "ERROR: SLLNode class - InsertAfter(): Could not create new node." << std::endl;
			}
		}

		~SLLNode()
		{
			if (m_Next)
			{
				m_Next = nullptr;
			}
		}
	};


	template <typename Datatype>
	class SingleLinkedList
	{
		int m_Size;

		friend std::ostream& operator<< (std::ostream& p_os, SingleLinkedList<Datatype>& p_obj)
		{
			GTAP_PROJ::SLLNode<Datatype>* t_Node = p_obj.m_Head;

			p_os << std::endl;
			for (int i = 0; i < p_obj.Size(); ++i)
			{
				p_os << *t_Node;
				if (t_Node->m_Next != nullptr)
				{
					t_Node = t_Node->m_Next;
				}
			}
			p_os << std::endl;
			return p_os;
		}
		friend std::ofstream& operator<< (std::ofstream& p_ofs, SingleLinkedList<Datatype>& p_obj)
		{
			GTAP_PROJ::SLLNode<Datatype>* t_Node = p_obj.m_Head;

			for (int i = 0; i < p_obj.Size(); ++i)
			{
				p_ofs << *t_Node;
				if (t_Node->m_Next != nullptr)
				{
					t_Node = t_Node->m_Next;
				}
			}

			return p_ofs;
		}

	public:

		SLLNode<Datatype>* m_Head;
		SLLNode<Datatype>* m_Tail;
		//SLLNode<Datatype>* m_Iter;

		/*SLLNode<Datatype>& ReferenceHead()
		{
			return *m_Head;
		}*/

		SingleLinkedList()
		{
			m_Head = nullptr;
			m_Tail = nullptr;	
			//m_Iter = nullptr;
			m_Size = 0;
		}

		void Append(Datatype p_Data)
		{
			if (m_Head == nullptr)
			{
				m_Head = m_Tail = new SLLNode<Datatype>;
				if (m_Head)
				{
					m_Head->m_Data = p_Data;
				}
				else
				{
					std::cout << "ERROR: SingleLinkedList class - Append(): Could not create new node." << std::endl;
				}
			}
			else
			{
				m_Tail->InsertAfter(p_Data);
				m_Tail = m_Tail->m_Next;
			}
			m_Size++;
		}
		void Prepend(Datatype p_Data)
		{
			SLLNode<Datatype>* t_Node = new SLLNode<Datatype>();
			if (t_Node)
			{
				t_Node->m_Data = p_Data;
				t_Node->m_Next = m_Head;
				m_Head = t_Node;
				if (m_Tail == nullptr)
				{
					m_Tail = m_Head;
				}
			}
			m_Size++;
		}
		void Remove_Head()
		{
			SLLNode<Datatype>* t_Node = nullptr;
			if (m_Head)
			{
				t_Node = m_Head->m_Next;
				delete m_Head;
				m_Head = t_Node;
				if (m_Head == nullptr)
				{
					m_Tail = nullptr;
				}
				m_Size--;
			}
		}
		void Remove_Item(Datatype p_Data)
		{
			SLLNode<Datatype>* t_Node = m_Head;
			SLLNode<Datatype>* t_PrevNode = m_Head;
			if (t_Node && t_PrevNode)
			{
				if (m_Head->m_Data == p_Data)
				{
					Remove_Head();
				}
				else if (m_Tail->m_Data == p_Data)
				{
					Remove_Tail();
				}
				else
				{
					while (t_Node->m_Next != nullptr)
					{
						t_Node = t_Node->m_Next;
						if (t_Node->m_Data == p_Data)
						{
							SLLNode<Datatype>* t_Temp = t_Node->m_Next;
							delete t_Node;
							t_Node = t_Temp;
							t_PrevNode->m_Next = t_Temp;
							m_Size--;
						}
						t_PrevNode = t_Node;
					}
				}
			}
		}
		void Remove_Tail()
		{
			SLLNode<Datatype>* t_Node = m_Head;

			if (m_Head)
			{
				if (m_Head == m_Tail)
				{
					delete m_Head;
					m_Head = m_Tail = nullptr;
				}
				else
				{
					while (t_Node->m_Next != m_Tail)
					{
						t_Node = t_Node->m_Next;
					}
					m_Tail = t_Node;
					delete t_Node->m_Next;
					t_Node->m_Next = nullptr;
				}
				m_Size--;
			}
		}
		int Size()
		{
			return m_Size;
		}

		/*SListIterator<Datatype> GetIterator()
		{
			return (SListIterator<Datatype>(this, m_Head));
		}*/


		~SingleLinkedList()
		{
			SLLNode<Datatype>* t_Iter = m_Head;
			SLLNode<Datatype>* t_Next;
			while (t_Iter)
			{
				t_Next = t_Iter->m_Next;
				delete t_Iter;
				t_Iter = t_Next;
			}
		}
	};
	

	/*template <typename Datatype>
	class SListIterator
	{
	private:



	public:

		SLLNode<Datatype>* m_Node;
		SingleLinkedList<Datatype>* m_List;

		SListIterator(SingleLinkedList<Datatype>* p_List = Datatype(), SLLNode<Datatype>* p_Node = Datatype())
		{
			m_List = p_List;
			m_Node = p_Node;
		}
		void Start()
		{
			if (m_List != nullptr)
			{
				m_Node = m_List->m_Head;
			}
		}
		void Forth()
		{
			if (m_Node != nullptr)
			{
				m_Node = m_Node->m_Next;
			}
		}
		Datatype& Item()
		{
			return m_Node->m_Data;
		}
		bool Valid()
		{
			return (m_Node != nullptr);
		}
		

		~SListIterator()
		{
			if (m_List)
			{
				delete m_List;
			}
			if (m_Node)
			{
				delete m_Node;
			}
		}
	};*/


	class VectorCompressor
	{
	private:
		
		SingleLinkedList<Vector3D<float>>* m_List;
		float m_Threshold;
		std::string m_FileName;
		std::string m_NewFileName;
	
		void Input_ToList(std::string p_Str)
		{
			float t_X, t_Y, t_Z;
			std::istringstream ss(p_Str);
			
			ss >> t_X  >> t_Y >> t_Z;
			/*std::cout << "x:" << t_X << std::endl;
			std::cout << "y:" << t_Y << std::endl;
			std::cout << "z:" << t_Z << std::endl;
			std::cout << std::endl;*/

			m_List->Append(Vector3D<float>(t_X, t_Y, t_Z));
		}
		void Read()
		{
			std::cout << " LOG: Getting old cheese from fridge." << std::endl;
			std::string t_Line;
			std::ifstream t_InFile(m_FileName);
			if (t_InFile.is_open())
			{
				while (getline(t_InFile, t_Line))
				{
					//std::cout << t_Line << "\n";
					Input_ToList(t_Line);
				}
				t_InFile.close();
			}
			else
			{
				std::cout << "ERROR: VectorCompressor.Read()- Unable to open file." << std::endl;
			}
			std::cout << std::endl;
		}
		void Compress()
		{		
			std::cout << " LOG: Slicing off moldy bits";
			SLLNode<Vector3D<float>>* t_myIter = m_List->m_Head;
			SLLNode<Vector3D<float>>* t_myComp = m_List->m_Head;
			while (t_myIter != nullptr)
			{
				t_myComp = t_myIter->m_Next;
				while (t_myComp != nullptr)
				{
					float t_f = t_myIter->m_Data.Distance_Comp(t_myComp->m_Data);
					if (t_f <= m_Threshold)
					{
						//std::cout << "./" << t_f << std::endl;
						SLLNode<Vector3D<float>>* t_tempNode = t_myComp->m_Next;
						m_List->Remove_Item(t_myComp->m_Data);
						t_myComp = t_tempNode;
					}
					else
					{
						t_myComp = t_myComp->m_Next;
					}
				}
				t_myIter = t_myIter->m_Next;
				std::cout << ".";
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
		void Write()
		{
			std::cout << " LOG: Returning remaining cheese to fridge." << std::endl;
			if (m_List->m_Head != nullptr)
			{
				std:: ofstream t_Outfile (m_NewFileName);
				if (t_Outfile.is_open())
				{
					t_Outfile << *m_List;
					t_Outfile.close();
				}
			}
			std::cout << std::endl;
		}
	
	public:
	
		VectorCompressor()
		{
			m_List =  new SingleLinkedList<Vector3D<float>>();
			SetThreshold();
			SetFileName();
		}
		//VectorCompressor(float p_Thresh, std::string p_Fname = TESTFILE_NAME)
		//{
		//	m_List = new SingleLinkedList<Vector3D<float>>();
		//	if (p_Thresh > 0)
		//	{
		//		m_Threshold = p_Thresh;
		//	}
		//	else
		//	{
		//		m_Threshold = DIST_THRESHOLD;
		//	}
		//	m_NewFileName = m_FileName = p_Fname;
		//}
		VectorCompressor(float p_Thresh, std::string p_Fname = TESTFILE_NAME, std::string p_NewFName = NEW_TESTFILE_NAME)
		{
			m_List = new SingleLinkedList<Vector3D<float>>();
			if (p_Thresh > 0)
			{
				m_Threshold = p_Thresh;
			}
			else
			{
				m_Threshold = DIST_THRESHOLD;
			}
			m_FileName = p_Fname;
			m_NewFileName = p_NewFName;
		}
	
		void RunCompression()
		{
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << " Operating on file: " << m_FileName << std::endl;
			std::cout << " Outputting compression to file: " << m_NewFileName << std::endl;
			std::cout << std::endl;
			std::cout << " Compressing w/ vector distance threshold: " << m_Threshold << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			Read();
			Compress();
		    Write();
			std::cout << std::endl;
		}

		void SetFileName()
		{
			std::cout << "File to open: ";
			std::cin >> m_FileName;
			std::cout << "Name of file to save to: ";
			std::cin >> m_NewFileName;
		}
		void SetThreshold()
		{
			std::cout << "Threshold of acceptable vector distance: ";
			std::cin >> m_Threshold;
		}
		std::string GetfileName() const
		{
			return m_FileName;
		}
		std::string GetNewFileName() const
		{
			return m_NewFileName;
		}
		float GetThreshold() const
		{
			return m_Threshold;
		}

		void PrintContents() const
		{
			std::cout << "LOG: PrintContents()" << std::endl;
			std::cout << *m_List;
		}

		~VectorCompressor()
		{
			if (m_List)
			{
				delete m_List;
			}
			m_List = nullptr;
			m_Threshold = 0;
			m_FileName = " ";
		}
	};
}
