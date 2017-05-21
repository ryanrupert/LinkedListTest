#include <iostream>

//this is the node structure
struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};
//function prototypes
void insertEnd(int d);
void deleteEnd();
void deleteBegin();

//this creates the head ptr and sets to null
Node *head = NULL;
//this creates the tail ptr and sets to null
Node *tail = NULL;

int main()
{
  //insert 1 at the end of the list
  insertEnd(1);
  //insert 2 at the end of the list
  insertEnd(2);
  //insert 4 at the end of the list
  insertEnd(4);
  //insert 3 at the end of the list
  insertEnd(3);
  //insert 6 at the end of the list
  insertEnd(6);
  //insert 5 at the end of the list
  insertEnd(5);
  //creates a pointer to head
  Node *ptr = head;
  //do until ptr next is null
  do
  {
    //output ptr data
    std::cout << ptr -> data;
    //ptr equals ptr next
    ptr = ptr -> next;
  }while(ptr -> next != NULL);
  std::cout << ptr -> data;
  std::cin.get();

  std::cout << std::endl;
  ptr = tail;
  //do until ptr prev is null
  do
  {
    std::cout << ptr -> data;
    ptr = ptr -> prev;
  }while(ptr -> prev != NULL);
  std::cout << ptr -> data;
  std::cin.get();

  //delete the end of the list
  deleteEnd();

  //do until ptr next is null
  do
  {
    std::cout << ptr -> data;
    ptr = ptr -> next;
  }while(ptr -> next != NULL);
  std::cout << ptr -> data;
  std::cin.get();

  std::cout << std::endl;
  ptr = tail;
  //do until ptr prev is null
  do
  {
    std::cout << ptr -> data;
    ptr = ptr -> prev;
  }while(ptr -> prev != NULL);
  std::cout << ptr -> data;
  std::cin.get();

  return 0;
}

void insertEnd(int d)
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
}

void deleteEnd()
{
  //create pointer to tails previous node
  Node *ptr = tail -> prev;
  //set pointers next pointer to null
  ptr -> next = NULL;
  //delete the node tail points to
  delete tail;
  //set tail to the node pointer points to
  tail = ptr;
}

void deleteBegin()
{
  //create pointer to heads next node
  Node *ptr = head -> next;
  //set pointers previous pointer to null
  ptr -> prev = NULL;
  //delete the node head points to
  delete head;
  //set head to the node pointer points to
  head = ptr;
}
