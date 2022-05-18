#include <iostream>
using namespace std;

struct Elem
{
	Elem* link;
	int info;
};

void enqueue(Elem* &first, Elem* &last, int info)
{
	Elem* tmp = new Elem;
	tmp->info = info;
	tmp->link = nullptr;
	if (last != nullptr)
		last->link = tmp;
	last = tmp;
	if (first == nullptr)
		first = tmp;
}

int dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->link;
	int info = first->info;
	delete first;
	first = tmp;
	if (first == nullptr)
		last = nullptr;
	return info;
}

void copy_queue(const Elem* first, Elem*& new_first, Elem*& new_last)
{
	while (first != nullptr)
	{
		enqueue(new_first, new_last, first->info);
		first = first->link;
	}
}

void remove(Elem*& first, Elem*& last, int pos)
{
	if (pos == 0) {
		dequeue(first, last);
		return;
	}

	int i = 0;
	Elem* nav_first = first;
	while (nav_first != nullptr)
	{
		if (i == pos-1)
		{
			Elem* next_link = nav_first->link->link;
			delete nav_first->link;
			nav_first->link = next_link;
		}

		i++;
		nav_first = nav_first->link;
	}
}

int count(const Elem* L)
{
	int k = 0;
	while (L != nullptr)
	{
		k++;
		L = L->link;
	}
	return k;
}

void print(const Elem* first)
{
	int i = 0;
	while (first != nullptr)
	{
		cout << first->info << " ";
		i++;
		first = first->link;
	}
	cout << endl;
}

bool check(const Elem* l1, const Elem* l2)
{
	Elem* first1 = nullptr, * last1 = nullptr;
	Elem* first2 = nullptr, * last2 = nullptr;
	copy_queue(l1, first1, last1);
	copy_queue(l1, first2, last2);

	Elem* nav1 = first1;
	Elem* nav2 = first2;

	if (count(l2) < count(l1))
		return false;

	bool is_there = false;
	while (nav1 != nullptr)
	{
		
		int i = 0;
		while (nav2 != nullptr)
		{
			if (nav1->info == nav2->info)
			{
				is_there = true;
				remove(first2, last2, i);
				nav2 = first2;
				break;
			}

			i++;
			nav2 = nav2->link;
		}
		if (!is_there)
		{
			int k = count(nav1);
			for (size_t i = 0; i < k; i++)
				dequeue(first1, last1);
			k = count(first2);
			for (size_t i = 0; i < k; i++)
				dequeue(first2, last2);
			return is_there;
		}

		nav1 = nav1->link;
	}

	int k = count(first1);
	for (size_t i = 0; i < k; i++)
		dequeue(first1, last1);
	k = count(first2);
	for (size_t i = 0; i < k; i++)
		dequeue(first2, last2);
	return is_there;
}

int main()
{
	Elem* first = nullptr, *last = nullptr;
	Elem* first1 = nullptr, * last1 = nullptr;
	
	enqueue(first, last, 0);
	enqueue(first, last, 4);
	enqueue(first, last, 4);
	enqueue(first, last, 5);

	for (size_t i = 0; i < 10; i++)
		enqueue(first1, last1, i);

	print(first);
	print(first1);

	cout << check(first, first1) << endl;
	
	int k = count(first);
	for (size_t i = 0; i < k; i++)
		dequeue(first, last);
	k = count(first1);
	for (size_t i = 0; i < k; i++)
		dequeue(first1, last1);

	return 0;
}