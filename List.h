/**
* Created by Ryan Rupert
* Date: 2018-05-11
* Source: Inline
* This is the list class to test some linked list stuff.
*/
#include <iostream>
#include <cstddef>

class List
{
	private:
		struct Node
		{
			int data;
			Node *next;
			Node *prev;
		};
		Node *head;
		Node *tail;
		int size;
		Node* newElement(int val = 0);

	public:
		//constructor
		List();
		//deconstructor
		~List();

		//Iterator forward declaration
		class Iterator;

		void insert(int val);
		void insert(int val, int pos);
		void erase(int pos);
		void erase(Iterator pos);
		void clear();

		//list iterator methods
		//Source: https://www.geeksforgeeks.org/implementing-iterator-pattern-of-a-single-linked-list/
		Iterator begin();
		Iterator end();

		//overloads
		friend std::ostream& operator<<(std::ostream& os, const List& list);
		int& operator[](int pos);

		//Iterator
		class Iterator
		{
			private:
				Node* curr;

			public:
				friend List;
				Iterator();
				Iterator(Node* pNode);

				Iterator& operator++();
				Iterator& operator++(int);
				Iterator& operator=(Node* pNode);
				int operator*();
		};
};
