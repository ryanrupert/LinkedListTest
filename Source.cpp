#include <iostream>
#include "List.h"

int main()
{
	List list;
  //insert 1 at the end of the list
  list.insertEnd(1);
  //insert 2 at the end of the list
  list.insertEnd(2);
  //insert 4 at the end of the list
  list.insertEnd(4);
  //insert 3 at the end of the list
  list.insertEnd(3);
  //insert 6 at the end of the list
  list.insertEnd(6);
  //insert 5 at the end of the list
  list.insertEnd(5);
  std::cout << list << std::endl;
	std::cout << list[1] << std::endl;
  std::cin.get();

  /*std::cout << std::endl;
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
  std::cin.get();*/

  return 0;
}
