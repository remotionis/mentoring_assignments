#include <iostream>

int main()
{
	int num;
	int sum = 0;
	for (int count = 1; count < 6; count++) {
		std::cout << count << "번째 정수 입력: ";
		std::cin >> num;
		sum += num;
	}
	std::cout << "합계: " << sum <<std::endl;
	return 0;
}
