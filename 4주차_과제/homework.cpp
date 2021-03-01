#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
};

class Link {
	private:
		int size;
	public:
		Node *head;
		void InitNode();
		void InitSize();
		int InputIndex();
		void InsertNode();
		void DeleteNode();
		void SearchNode();
		const void PrintData();
		const void PrintSize();
};

void Link::InitNode() {
	head = new Node();
}

void Link::InitSize() {
	size = 0;
	cout << size << "\n";
}

int Link::InputIndex() {
	int index;
	cout << "인덱스 입력: ";
	cin >> index;
	return index;
}

void Link::InsertNode() {
	int data;
	cout << "데이터 입력: ";
	cin >> data;
	if(size == 0) {
		head->data << data;
	} else {
		Node* tempNode = head;
		Node* curNode = new Node();
		curNode->data = data;
		for (int i = 0; i < size-1; i++)
			tempNode = tempNode->next;
		tempNode->next = curNode;
	}
	size++;
	cout << "데이터 입력 완료\n";
}

void Link::DeleteNode() {
	Node* tempNode = head;
	Node* delNode;
	Node* swapNode;
	if (size == 0) {
		cout << "데이터가 존재하지 않습니다.\n\n";
		return;
	}
	int index = InputIndex();
	while (index < 0 || index >= size) {
		cout << "다시 입력\n";
		index = InputIndex();
	}
	if(index == 0) {
		delNode = head;
		head = tempNode->next;
	} else {
		for(int i = 0; i < index-1; i++)
			tempNode = tempNode->next;
		delNode = tempNode->next;
		swapNode = delNode->next;
		tempNode->next = swapNode;
	}
	delete delNode;
	size--;
	cout << "데이터 삭제 완료\n";
}

void Link::SearchNode() {
	Node* tempNode = head;
	int count = 0;
	if (size == 0) {
		cout << "데이터가 존재하지 않습니다.\n\n";
		return;
	}
	int index = InputIndex();
	while (index < 0 || index >= size) {
		cout << "다시 입력\n";
		index = InputIndex();
	}
	for(int i = 0; i < index; i++) {
		if (tempNode->data == index) {
			cout << tempNode->data << "\n";
			count++;
		}
		tempNode = tempNode->next;
	}
	if (count == 0)
		cout << "일치하는 데이터가 없습니다.\n\n";
}

const void Link::PrintData() {
	Node* tempNode = head;
	if (size == 0) {
		cout << "데이터가 존재하지 않습니다.\n";
	} else {
		for (int i = 0; i < size; i++) {
			cout << tempNode->data << "\t";
			tempNode = tempNode->next;
		}
	}
	cout << "\n\n";
}

const void Link::PrintSize() {
	cout << size << "개\n\n";
}

class MainPage {
	public:
		void Root();
		void Menu();
		void Switch(int num);
};

void MainPage::Root() {
	int num;
	while (1) {
		Menu();
		cin >> num;
		Switch(num);
	}
}

void MainPage::Menu() {
	cout << "\n";
	cout << "---------데이터 관리 프로그램---------\n";
	cout << "1. 데이터 입력\n";
	cout << "2. 데이터 삭제\n";
	cout << "3. 데이터 출력\n";
	cout << "4. 데이터 크기 출력\n";
	cout << "5. 데이터 검색\n";
	cout << "6. 종료\n";
	cout << "--------------------------------------\n";
	cout << "번호 입력: ";
}

void MainPage::Switch(int num) {
	Link link;
	switch (num) {
		case 1 :
			link.InsertNode();
			break;
		case 2 :
			link.DeleteNode();
			break;
		case 3 :
			link.PrintData();
			break;
		case 4 :
			link.PrintSize();
			break;
		case 5 :
			link.SearchNode();
			break;
		case 6 :
			exit(0);
		default :
			cout << "다시 입력\n";
	}
}

int main() {
	Link link;
	MainPage main;

	link.InitNode();
	link.InitSize();
	main.Root();

	return 0;
}
