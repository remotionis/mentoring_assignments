#include <iostream>
#include <string>

using namespace std;

class Printer {
private:
	string word;
public:
	void SetString(string st);
	void ShowString();
};

void Printer::SetString(string st) {
	word = st;
}

void Printer::ShowString() {
	cout << word << endl;
}
int main(void) {
	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();

	pnt.SetString("I Love C++");
	pnt.ShowString();

	return 0;
}