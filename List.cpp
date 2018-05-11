#include "List.h"

List::List()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

List::~List()
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

void List::deleteEnd()
{
	//create pointer to tails previous node
	Node *ptr = tail -> prev;
	//set pointers next pointer to null
	ptr -> next = NULL;
	//delete the node tail points to
	delete tail;
	//set tail to the node pointer points to
	tail = ptr;
	size--;
}

void List::deleteBegin()
{
	//create pointer to heads next node
	Node *ptr = head -> next;
	//set pointers previous pointer to null
	ptr -> prev = NULL;
	//delete the node head points to
	delete head;
	//set head to the node pointer points to
	head = ptr;
	size--;
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
