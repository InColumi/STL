#include <iostream>

template<typename T>
struct Stack
{

	T* Data;
	size_t Count;

	Stack()
	{
		Data = nullptr;
		Count = 0;
	}

	void push(T item)
	{
		T* oldData; 
		try
		{
			oldData = Data;
			Data = new T[Count + 1];
			Count++;
			for(size_t i = 0; i < Count - 1; i++)
			{
				Data[i] = oldData[i];
			}				

			Data[Count - 1] = item;
			if(Count > 1)
			{
				delete[] oldData;
			}
		}
		catch(std::bad_alloc e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	T pop()
	{
		if(Count > 0)
		{
			try
			{
				T* oldData;
				oldData = Data;
				Data = new T[Count - 1];
				Count--;
				for(size_t i = 0; i < Count; i++)
				{
					Data[i] = oldData[i];
				}
				T data = oldData[Count];
				delete[] oldData;
				return data;

			}
			catch(std::bad_alloc e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else
		{
			std::cout << "Stack is empty\n";
			exit(0);
		}
	}

	bool is_empty()
	{
		return Count == 0;
	}

	~Stack()
	{
		if(Count > 0)
		{
			delete[] Data;
		}
	}
};

template<typename T>
struct Queue
{
	T* Data;
	size_t Count;
	
	bool is_empty()
	{
		return Count == 0;
	}

	Queue()
	{
		Data = nullptr;
		Count = 0;
	}

	void push(T item)
	{
		T* oldData;
		oldData = Data;

		try
		{
			Data = new T[Count + 1];
					
			for(size_t i = 0; i < Count; i++)
			{
				Data[i] = oldData[i];
			}

			Data[Count] = item;
			Count++;
			if(Count > 1)
				delete[] oldData;
		}
		catch(std::bad_alloc e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	T pop()
	{
		if(Count > 0)
		{
			T item;
			item = Data[0];
			try
			{
				T* p2;
				p2 = new T[Count - 1];
				Count--;
				for(size_t i = 0; i < Count; i++)
				{
					p2[i] = Data[i + 1];
				}				

				  
				if(Count > 0)
				{
					delete[] Data;
				}
					
				Data = p2;

				return item;
			}
			catch(std::bad_alloc e)
			{
				std::cout << e.what() << std::endl;
				return 0;
			}
		}
		else
		{
			std::cout << "Queue is empty\n";
			exit(0);
		}		
	}
};

using namespace std;

int main(int argc, char** argv)
{
	Stack<int> a;
	a.push(1);
	a.push(2);
	a.push(3);

	cout << a.pop() << endl;
	cout << a.pop() << endl;
	cout << a.pop() << endl;

	Queue<int> b;
	b.push(1);
	b.push(2);
	b.push(3);

	cout << b.pop() << endl;
	cout << b.pop() << endl;
	cout << b.pop() << endl;
	cout << b.pop() << endl;

	system("pause");
	return 0;
}