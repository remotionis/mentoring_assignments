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

		void Menu(Link link);

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
}

int Link::InputIndex() {
	int index;

	cin >> index;

	return index;
}

void Link::InsertNode() {
	int data;

	cout << "넣고싶은 데이터를 입력하세요 : ";

	cin >> data;

	if(size == 0) {
		head->data = data;

	} else {
		Node* tempNode = head;
		Node* curNode = new Node();
		curNode->data = data;
		for (int i = 0; i < size-1; i++)
			tempNode = tempNode->next;
		tempNode->next = curNode;
	}
	size++;
	cout << "입력이 완료되었습니다.\n";
}

void Link::DeleteNode() {
	Node* tempNode = head;
	Node* delNode;
	Node* swapNode;

	if (size == 0) {
		cout << "데이터가 존재하지 않습니다.\n\n";
		return;
	}
	
	cout << "삭제하고 싶은 데이터 인덱스를 입력하세요 : ";

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
	cout << "삭제가 완료되었습니다.\n";
}

void Link::SearchNode() {
	Node* tempNode = head;

	if (size == 0) {
		cout << "데이터가 존재하지 않습니다.\n\n";
		return;
	}
	
	cout << "찾고싶은 데이터의 인덱스를 입력하세요 : ";

	int index = InputIndex();

	if (index < 0 || index >= size) {
		cout << "일치하는 데이터가 없습니다.\n\n";
		index = InputIndex();
	}
	else {
		for(int i = 0; i < index; i++) {
			tempNode = tempNode->next;
		}
		cout << "인덱스 " << index << "의 값 : " << tempNode->data << "\n\n";
		cout << "탐색을 완료했습니다.\n\n";
	}
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
	cout << "\n출력을 완료했습니다.\n\n";
}

const void Link::PrintSize() {
	cout << "Linked List 사이즈 : " << size << "\n\n";
	cout << "출력을 완료했습니다.\n\n";
}

void Link::Menu(Link link) {
    while (1) {
		cout << "\n";
        cout << "---------링크드 리스트 프로그램---------\n\n";
        cout << "1. 데이터 입력\n";
        cout << "2. 데이터 삭제\n";
        cout << "3. 데이터 값 찾기\n";
        cout << "4. 모든 데이터 출력\n";
        cout << "5. 데이터 크기 확인\n";
        cout << "6. 종료\n";
        cout << "\n--------------------------------------\n";

        int num;
        cin >> num;

            switch (num) {
            case 1 :
                link.InsertNode();
                break;
            case 2 :
                link.DeleteNode();
                break;
            case 3 :
                link.SearchNode();
                break;
            case 4 :
                link.PrintData();
                break;
            case 5 :
                link.PrintSize();
                break;
            default :
				cout << "프로그램을 종료합니다.\n";
                exit(0);
        }
    }
}

int main() {
	Link link;

	link.InitNode();
	link.InitSize();
	link.Menu(link);

	return 0;
}
