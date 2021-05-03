#include <iostream>


template<typename T>
struct Stack
{

	T* Data;
	size_t Size;

	Stack()
	{
		Data = NULL;
		Size = 0;
	}

	void push(T item)
	{
		T* oldData; 
		try
		{
			oldData = Data;
			Data = new T[Size + 1];
			Size++;
			for(size_t i = 0; i < Size - 1; i++)
			{
				Data[i] = oldData[i];
			}				

			Data[Size - 1] = item;
			if(Size > 1)
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
		if(Size > 0)
		{
			try
			{
				T* oldData;
				oldData = Data;
				Data = new T[Size - 1];
				Size--;
				for(size_t i = 0; i < Size; i++)
				{
					Data[i] = oldData[i];
				}
				T data = oldData[Size];
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
		return Size == 0;
	}

	~Stack()
	{
		if(Size > 0)
		{
			delete[] Data;
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
	cout << a.pop() << endl;

	system("pause");
	return 0;
}