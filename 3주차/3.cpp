#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	int num[5];
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		int j = i-1;
		num[i] = rand() % 100;
		while (j >= 0) {
			if (num[i] == num[j]) {
				i--;
				break;
			}
			j--;
		}
		std::cout << num[i] << std::endl;
	}
	return 0;
}
