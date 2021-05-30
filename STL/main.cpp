#include <iostream>

/// <summary>
/// Стуктура Stack построена по принципу First in Last out
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
struct Stack
{
	/// <summary>
	/// Укзатель на первый эдемент
	/// </summary>
	T* Data;
	/// <summary>
	/// Кол-во элементов в структуре
	/// </summary>
	size_t Count;

	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	Stack()
	{
		Data = NULL; // присваивем указателю значение NULL 
		Count = 0; // обозначаем, что в структуре 0 элементов
	}

	/// <summary>
	/// Добавление элемента в Stack
	/// </summary>
	/// <param name="item">Новый элемент</param>
	void push(T item)
	{
		T* oldData; /// создаём временны указатель

		try // попытка добавить элемент в Stack
		{
			oldData = Data; // присваиваем oldData ссылку Data
			Data = new T[Count + 1]; // выделяем память на 1 элемент больше
			Count++; // Увеличиваем кол-во элементов в Stack
			for(size_t i = 0; i < Count - 1; i++)
			{
				Data[i] = oldData[i]; // Присваиваем Data старые элементы
			}

			Data[Count - 1] = item; // последним элементов записываем новый
			if(Count > 1) // Если элеменов больше одного, тогда удаляем созданную ссылку oldData
			{
				delete[] oldData; // очистка памяти из под указателя
			}
		}
		catch(std::bad_alloc e) // В случает проблем с добавлением, будет вызвано исключение
		{
			std::cout << e.what() << std::endl; // вывод текста ошибки
		}
	}

	/// <summary>
	/// Возвращает первый элемент Stack и удаляет из структуры
	/// </summary>
	/// <returns>первый элемент Stack</returns>
	T pop()
	{
		if(Count > 0) // если элементов больше, чем 1
		{
			try // попытка удаление первого элемента Stack
			{
				T* oldData; /// создаём временны указатель
				oldData = Data;  // присваиваем oldData ссылку Data
				Data = new T[Count - 1];// выделяем память на 1 элемент меньше
				Count--; // Уменьшаем кол-во элементов в Stack
				for(size_t i = 0; i < Count; i++)
				{
					Data[i] = oldData[i]; // Присваиваем Data старые элементы
				}
				T data = oldData[Count]; // сохраняем первый элемент  Stack 
				delete[] oldData; // очистка памяти из под указателя
				return data; // очистка памяти из под указателя

			}
			catch(std::bad_alloc e) // В случает проблем с добавлением, будет вызвано исключение
			{
				std::cout << e.what() << std::endl; // вывод текста ошибки
			}
		}
		else // Иначе вывести сообщение, что Stack пуст и закрыть программу
		{
			std::cout << "Stack is empty\n";
			exit(0);// выход из программы
		}
	}

	/// <summary>
	/// Возвращает bool пуст ли Stack
	/// </summary>
	/// <returns></returns>
	bool is_empty()
	{
		return Count == 0; // если кол-во элементов в структуре = 0, тогда вернет true иначе false
	}

	// Деструктор (очищает память из под объекта при удалении)
	~Stack()
	{
		if(Count > 0) // Если элементов больше, чем 1
		{
			delete[] Data; // очистка памяти из под указателя
			Count = 0; // Обнуляем счетчик элементов
		}
	}
};

/// <summary>
/// Структура Queue построенна по принципу First in First out
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
struct Queue
{
	/// <summary>
	/// Укзатель на первый эдемент
	/// </summary>
	T* Data;
	/// <summary>
	/// Кол-во элементов в структуре
	/// </summary>
	size_t Count;

	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	Queue()
	{
		Data = NULL; // присваивем указателю значение NULL 
		Count = 0; // обозначаем, что в структуре 0 элементов
	}

	/// <summary>
	/// Добавление элемента в Queue
	/// </summary>
	/// <param name="item">Новый элемент</param>
	void push(T item)
	{
		T* oldData; /// создаём временны указатель

		try // попытка добавить элемент в Queue
		{
			oldData = Data; // присваиваем oldData ссылку Data
			Data = new T[Count + 1];// выделяем память на 1 элемент больше

			for(size_t i = 0; i < Count; i++)
			{
				Data[i] = oldData[i];  // Присваиваем Data старые элементы
			}

			Data[Count] = item; // последним элементов записываем новый
			Count++; // Увеличиваем кол-во элементов в Queue
			if(Count > 1) // Если элеменов больше одного, тогда удаляем созданную ссылку oldData
				delete[] oldData;  // очистка памяти из под указателя
		}
		catch(std::bad_alloc e)  // В случает проблем с добавлением, будет вызвано исключение
		{
			std::cout << e.what() << std::endl; // вывод текста ошибки
		}
	}

	/// <summary>
	/// Возвращает первый элемент Queue и удаляет из структуры
	/// </summary>
	/// <returns>первый элемент Queue</returns>
	T pop()
	{
		if(Count > 0)  // если элементов больше, чем 1
		{
			T item;
			item = Data[0]; // сохраняем первый элемент Queue 
			try // попытка удаление первого элемента Queue
			{
				T* p2; // создаём указатель
				p2 = new T[Count - 1];// выделяем память на 1 элемент меньше
				Count--; // Уменьшаем кол-во элементов в Stack
				for(size_t i = 0; i < Count; i++)
				{
					p2[i] = Data[i + 1]; // Присваиваем p2 старые элементы
				}


				if(Count > 0) // Если элеменов больше 0, тогда удаляем созданную ссылку Data
				{
					delete[] Data; // очистка памяти из под массива
				}

				Data = p2; // присваиваем ссылку 

				return item; // позвращаем элемент
			}
			catch(std::bad_alloc e) // В случает проблем с добавлением, будет вызвано исключение
			{
				std::cout << e.what() << std::endl; // вывод текста ошибки
			}
		}
		else // Иначе вывести сообщение, что Stack пуст и закрыть программу
		{
			std::cout << "Queue is empty\n";
			exit(0); // выход из программы
		}
	}

	/// <summary>
	/// Возвращает bool пуста ли Queue
	/// </summary>
	/// <returns></returns>
	bool is_empty()
	{
		return Count == 0; // если кол-во элементов в структуре = 0, тогда вернет true иначе false
	}

	// Деструктор (очищает память из под объекта при удалении)
	~Queue()
	{
		if(Count > 0)
		{
			delete[] Data; // очистка памяти из под указателя
			Count = 0; // Обнуляем счетчик элементов
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