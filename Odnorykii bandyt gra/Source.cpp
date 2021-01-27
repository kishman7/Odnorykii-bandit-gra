#include<iostream> 
#include<windows.h>
#include<string>
#include <time.h>


using namespace std;

class Queue
{
	int* queue;  // створюємо масив
	int maxLength; // максимальна кількість елементів
	int queueLength;  // поточний елемент

public:
	Queue(int max);
	~Queue();

	void Add(int el); // додавання елемента
	int Extract(); // переміщення елемента

	bool isFull() const; // коли повний список
	bool isEmpty() const; // коли порожній список
	int GetCount() const; // виводить кількість елементів
	void Clear(); // очищає список повністю
	void Show() const; // виводить елементи
	int Element(int size); // вивід окремого елемента по рандомному ітератору
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int size = 10;
	srand(time(0));
	Queue q1(size);
	Queue q2(size);
	Queue q3(size);

	int el;
	int rnd = 2; // діапазон в межах якого будемо рандомити числа
	for (int i = 0; i < size; i++)
	{
		el = rand() % rnd;
		q1.Add(el);
	}
	for (int i = 0; i < size; i++)
	{
		el = rand() % rnd;
		q2.Add(el);
	}
	for (int i = 0; i < size; i++)
	{
		el = rand() % rnd;
		q3.Add(el);
	}
	q1.Show();
	q2.Show();
	q3.Show();
	
	cout << q1.GetCount() << endl;
	//q1.Element(size);
	
	int attempt = 0; // кількість спроб
	int count = 0; // лічільник спроб
	cout << "Choose the number of attempts: ";
	cin >> attempt;
	cout << "\nPress the Enter key" << endl;
	cout << endl;
	bool enter = true;
	while (enter)
	{
		char ch;
		ch = cin.get(); // щоб нажати клавішу Enter
		if (ch == '\n')
		{
			count++;
			int x, y, z;
			x = q1.Extract();
			y = q2.Extract();
			z = q3.Extract();
			cout << "Attempt " << count << endl;
			cout << x << "\t" << y << "\t" << z << endl;
			if (x == y && x == z)
			{
				cout << "***CONGRATULATIONS!!! YOU WIN!!!***" << endl;
				break;
			}
		}
		else
		{
			cout << "Вы нажали не Enter\n";
		}
		
		if (attempt == count)
		{
			cout << "Your attempts are complete!!!" << endl;
			cout << "===GAME OVER!!!===" << endl;
			break;
		}
	}
		
	return 0;
}

Queue::Queue(int max)
{
	maxLength = max;
	queue = new int[maxLength];
	queueLength = 0;
}

Queue::~Queue()
{
	delete[] queue;
}

void Queue::Add(int el)
{
	if (!isFull())
	{
		queue[queueLength++] = el;
	}
}

int Queue::Extract()
{
	if (!isEmpty())
	{
		int temp = queue[0];
		for (int i = 1; i < queueLength; i++)
		{
			queue[i - 1] = queue[i];
		}
		queue[queueLength - 1] = temp; // варіант кільцевої черги -
		//замість видалення елемент переміщується в кінець черги

		//queueLength--;
		return temp;
	}
}

bool Queue::isFull() const
{
	return queueLength == maxLength;
}

bool Queue::isEmpty() const
{
	return queueLength == 0;
}

int Queue::GetCount() const
{
	return queueLength;
}

void Queue::Clear()
{
	queueLength = 0;
}

void Queue::Show() const
{
	for (int i = 0; i < queueLength; i++)
	{
		cout << queue[i] << "\t";
	}

	cout << endl;
}

int Queue::Element(int size)
{
	int temp = rand() % size;
	for (int i = 0; i < size; i++)
	{
		if (i == temp)
		{
			cout << queue[i] << endl;
		}
	}
	return 0;
}
