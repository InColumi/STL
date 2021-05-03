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
		return T();
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

	bool is_empty()
	{
		return Count == 0;
	}

	~Queue()
	{
		if(Count > 0)
		{
			delete[] Data;
		}
	}
};

template<typename T>
struct List
{
	T* Data;
	size_t Count;

	List()
	{
		Data = nullptr;
		Count = 0;
	}

	void add(T item)
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
			{
				delete[] oldData;
			}
		}
		catch(std::bad_alloc e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	void insert(size_t position, T item)
	{
		CheckCount();
		CheckPosition(position);
		T* oldData;
		oldData = Data;

		try
		{
			Data = new T[Count + 1];

			for(size_t i = 0; i < position; i++)
			{
				Data[i] = oldData[i];
			}

			for(size_t i = position + 1; i < Count + 1; i++)
			{
				Data[i] = oldData[i - 1];
			}

			Data[position] = item;
			Count++;
			delete[] oldData;
		}
		catch(std::bad_alloc e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	void set(int position, T item)
	{
		CheckCount();
		CheckPosition(position);
		Data[position] = item;
	}

	int find(T item)
	{
		CheckCount();
		for(size_t i = 0; i < Count; i++)
		{
			if(item == Data[i])
			{
				return i;
			}
		}
		return -1;
	}

	bool is_empty()
	{
		return Count == 0;
	}

	T get(size_t position)
	{
		CheckCount();
		CheckPosition(position);
		return Data[position];
	}

	T remove(size_t position)
	{
		CheckCount();
		CheckPosition(position);
		T* oldData;
		oldData = Data;
		T oldItem = Data[position];
		try
		{
			Data = new T[Count - 1];

			for(size_t i = 0; i < position; i++)
			{
				Data[i] = oldData[i];
			}

			for(size_t i = position; i < Count; i++)
			{
				Data[i] = oldData[i + 1];
			}

			Count--;
			delete[] oldData;
			return oldItem;
		}
		catch(std::bad_alloc e)
		{
			std::cout << e.what() << std::endl;
		}
		return T();
	}


private:
	void CheckCount()
	{
		if(is_empty())
		{
			std::cout << "List empty\n";
			exit(0);
		}
	}

	void CheckPosition(size_t position)
	{
		if(position < 0 || position >= Count)
		{
			std::cout << "Wrong position\n";
			abort();
		}
	}
};

template< typename T >
struct LinckedList
{
private:
	template< typename T >
	struct Node
	{
	public:
		Node<T>* Next;
		T Value;

		Node(T value = T(), Node<T>* next = nullptr)
		{
			this->Value = value;
			this->Next = next;
		}
	};


	Node<T>* _head;
	size_t _count;

public:
	LinckedList(): _head(NULL), _count(0)
	{}

	~LinckedList()
	{
		while(_count)
		{
			remove(_count - 1);
		}
	}

	void add(T data)
	{
		if(_head == nullptr)
		{
			_head = new Node<T>(data);
		}
		else
		{
			Node<T>* current = this->_head;

			while(current->Next != nullptr)
			{
				current = current->Next;
			}
			current->Next = new Node<T>(data);
		}
		_count++;
	}

	T remove(size_t position)
	{
		CheckCount();
		T item;
		if(position == 0)
		{
			item = _head->Value;
			Node<T>* temp = _head;

			_head = _head->Next;

			delete temp;
			_count--;
			return item;
		}
		else
		{
			Node<T>* previous = this->_head;
			for(size_t i = 0; i < position - 1; i++)
			{
				previous = previous->Next;
			}


			Node<T>* toDelete = previous->Next;
			item = previous->Value;
			previous->Next = toDelete->Next;

			delete toDelete;

			_count--;
			return item;
		}
	}

	T get(size_t position)
	{
		CheckCount();
		Node<T>* previous = this->_head;
		for(size_t i = 0; i < position; i++)
		{
			previous = previous->Next;
		}
		T item = previous->Value;
		return item;
	}

	void insert(size_t position, T item)
	{
		CheckCount();
		if(position == 0)
		{
			_head = new Node<T>(item, _head);
			_count++;
		}
		else
		{
			Node<T>* previous = this->_head;

			for(size_t i = 0; i < position - 1; i++)
			{
				previous = previous->Next;
			}

			Node<T>* newNode = new Node<T>(item, previous->Next);

			previous->Next = newNode;

			_count++;
		}
	}

	void set(size_t position, T item)
	{
		CheckCount();
		if(position == 0)
		{
			_head->Value = item;
		}
		else
		{
			Node<T>* previous = this->_head;

			for(size_t i = 0; i < position; i++)
			{
				previous = previous->Next;
			}
			previous->Value = item;
		}
	}

	bool is_empty()
	{
		return _count == 0;
	}

private:
	void CheckCount()
	{
		if(is_empty())
		{
			std::cout << "List empty\n";
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

	cout << "Stack: \n";
	cout << a.pop() << endl;
	cout << a.pop() << endl;
	cout << a.pop() << endl;

	Queue<int> b;
	b.push(1);
	b.push(2);
	b.push(3);

	cout << "Queue: \n";
	cout << b.pop() << endl;
	cout << b.pop() << endl;
	cout << b.pop() << endl;

	List<int> c;
	cout << "List: \n";
	c.add(1);
	c.add(2);
	c.add(3);
	c.add(4);
	c.add(5);

	cout << "Insert: \n";
	c.insert(0, 10);
	cout << "Set: \n";
	c.set(0, 99);
	cout << "Find: \n";
	c.find(5);
	cout << "Remove: \n";
	cout << c.remove(0) << endl;
	cout << "Get: \n";
	cout << c.get(0) << endl;

	LinckedList<int> d;
	cout << "LinckedList: \n";
	d.add(1);
	d.add(2);
	d.add(3);
	d.add(10);

	cout << "Insert: \n";
	d.insert(0, 10);
	cout << "Set: \n";
	d.set(1, 99);

	cout << "Remove: \n";
	cout << d.remove(0) << endl;
	cout << "Get: \n";
	cout << d.get(0) << endl;
	system("pause");
	return 0;
}