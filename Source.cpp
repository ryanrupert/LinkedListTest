#include <iostream>
#include "List.h"

int main()
{
	List list;
	//insert 1 at the end of the list
	list.insert(1);
	//insert 2 at the end of the list
	list.insert(2);
	//insert 4 at the end of the list
	list.insert(4);
	//insert 3 at the end of the list
	list.insert(3);
	//insert 6 at the end of the list
	list.insert(6);
	//insert 5 at the end of the list
	list.insert(5);
	list.insert(20, 0);
	std::cout << list << std::endl;
	std::cout << list[1] << std::endl;
	list[2] = 7;
	std::cout << list << std::endl;
	list.erase(4);
	std::cout << list << std::endl;
	std::cin.get();

	List::Iterator it = list.begin();
	it++;
	it++;
	std::cout << *it << std::endl;
	list.erase(it);
	std::cout << list << std::endl;

	return 0;
}
