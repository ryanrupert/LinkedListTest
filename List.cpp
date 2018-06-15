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

void List::insert(int val)
{
	//this creates a node ptr to the new node
	Node *ptr = new Node();
	//this adds d to the data part of the node
	ptr -> data = val;
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

void List::insert(int val, int pos)
{
	Node* newNode = newElement(val);

	if(!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		Node* curr = NULL;
		int i = 0;
		while(curr && i != pos)
		{
			curr = curr->next;
			i++;
		}
		if(curr == head)
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
			newNode = NULL;
		}
		else if(curr == tail)
		{
			newNode->next = tail;
			newNode->prev = tail->prev;
			tail->prev->next = newNode;
			tail->prev = newNode;
			newNode = NULL;
		}
		else if(curr)
		{
			newNode->next = curr;
			newNode->prev = curr->prev;
			curr->prev->next = newNode;
			curr->prev = newNode;
			newNode = NULL;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
			newNode = NULL;
		}
	}
}

List::Node* List::newElement(int val)
{
	Node* newNode = NULL;

	newNode = new Node;
	newNode->data = val;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
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

void List::erase(const Iterator first, const Iterator last)
{
	Node* curr = first.curr;
	Node* next = NULL;
	
	if(!head)
		return;

	while(curr != last.curr)
	{
		next = curr->next;
		erase(Iterator(curr));
		curr = next;
	}
	if(curr)
		erase(Iterator(curr));
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
	if(!list.head)
	{
		os << "List empty";
	}
	else
	{
		do
		{
			os << ptr->data;
			os << " ";
			ptr = ptr->next;
		}while(ptr->next != NULL);
		os << ptr->data;
	}
	return os;
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
	return Iterator(nullptr);
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
