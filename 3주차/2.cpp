#include <iostream>

int main()
{
	int num;
	std::cin >> num;
	for (int count = 1; count < 10; count++) {
		std::cout << num << " * " << count << " = " << num*count << std::endl;
	}
	return 0;
}
