#include "List.h"

List::List()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

List::~List()
{
	clear();
}

void List::insertEnd(int d)
{
	//this creates a node ptr to the new node
	Node *ptr = new Node();
	//this adds d to the data part of the node
	ptr -> data = d;
	//this adds null to the next ptr
	ptr -> next = NULL;
	//if head is null then
	if (head == NULL)
	{
		//set ptr prev to null
		ptr -> prev = NULL;
		//and set head to ptr
		head = ptr;
	}
	//if head is not null then
	else
	{
		//create a temp node pointer
		Node *temp = head;
		//loop till temp next is null
		while (temp -> next != NULL) {
			//set temp to the next temp ptr location
			temp = temp -> next;
		}
		//when at the end of the list set temp next to ptr
		temp -> next = ptr;
		ptr -> prev = temp;
		tail = ptr;
	}
	size++;
}

void List::erase(int pos)
{
	Node* ptr = head;
	if(pos >= size)
		return;

	for(int i = 0; i < pos; i++)
		ptr = ptr->next;

	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;

	delete ptr;
	ptr = NULL;
	size--;
}

void List::erase(Iterator pos)
{
	Node* ptr = pos.curr;
	if(ptr->prev == NULL)
	{
		head = ptr->next;
		head->prev = NULL;
		delete ptr;
		ptr = NULL;
	}
	else if(ptr->next == NULL)
	{
		tail = ptr->prev;
		tail->next = NULL;
		delete ptr;
		ptr = NULL;
	}
	else
	{
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;

		delete ptr;
		ptr = NULL;
	}
	pos.curr = NULL;
}

void List::clear()
{
	Node* curr = head;
	Node* next = NULL;
	while(curr)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
	head = NULL;
	tail = NULL;
	size = 0;
}

std::ostream& operator<<(std::ostream& os, const List& list)
{
	List::Node* ptr = list.head;
	do
	{
		os << ptr->data;
		ptr = ptr->next;
	}while(ptr->next != NULL);
	os << ptr->data;
}

int& List::operator[](int pos)
{
	int i = 0;
	Node* ptr = head;
	for(i = 0; i < size && i < pos; i++)
		ptr = ptr->next;
	return ptr->data;
}

List::Iterator List::begin()
{
	return Iterator(head);
}

List::Iterator List::end()
{
	return Iterator(tail);
}



List::Iterator::Iterator()
{
	curr = NULL;
}

List::Iterator::Iterator(Node* pNode)
{
	curr = pNode;
}

List::Iterator& List::Iterator::operator++()
{
	if(curr->next)
		curr = curr->next;
	return *this;
}

List::Iterator& List::Iterator::operator++(int)
{
	Iterator iterator = *this;
	++(*this);
	return iterator;
}

List::Iterator& List::Iterator::operator=(Node* pNode)
{
	this->curr = pNode;
	return *this;
}

int List::Iterator::operator*()
{
	return curr->data;
}
