#include <iostream>
#include "List.h"

int main()
{
	List list;

	std::cout << list << std::endl;
	std::cout << "add data" << std::endl;
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

	std::cout << "init it test" << std::endl;
	List::Iterator it = list.begin();
	it++;
	it++;
	std::cout << *it << std::endl;
	list.erase(it);

	std::cout << "erase range test" << std::endl;
	List::Iterator start = list.begin();
	start++;
	List::Iterator last = list.begin();
	last++;
	last++;
	last++;
	list.erase(start, last);
	std::cout << list << std::endl;

	return 0;
}
