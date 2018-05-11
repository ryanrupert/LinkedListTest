/**
* Created by Ryan Rupert
* Date: 2018-05-11
* Source: None
* This is the list class to test some linked list stuff.
*/
#include <iostream>

class List
{
	private:
		struct Node
		{
			int data;
			struct Node *next;
			struct Node *prev;
		};
		Node *head;
		Node *tail;
		int size;

	public:
		List();
		~List();
		void insertEnd(int d);
		void deleteEnd();
		void deleteBegin();
		friend std::ostream& operator<<(std::ostream& os, const List& list);
		int& operator[](int pos);
};
