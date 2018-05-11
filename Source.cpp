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

	return 0;
}
