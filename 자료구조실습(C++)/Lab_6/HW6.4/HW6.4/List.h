#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class List {
public:
	int data;
	List* link;

	List* first; // 처음 리스트는 비어 있음

	List() {
		link = nullptr;
		first = nullptr;
	}

	~List() { //메모리해제
		List* temp;
		while (first != nullptr) {
			temp = first;
			first = first->link;
			delete temp;
		}
	}

	void insert(int item) {
		List* temp = new List();
		temp->data = item;
		List* ptr;

		if (first == nullptr) {
			first = temp;
		}

		else {
			if (temp->data <= first->data) {
				temp->link = first;
				first = temp;
				return;
			}

			ptr = first;
			for (; ptr->link != nullptr; ptr = ptr->link) {
				if ((ptr->data) <= (temp->data) && ((ptr->link->data) >= (temp->data))) {
					//ptr과 ptr->link 사이의(같은조건도 포함) 값이면 삽입
					temp->link = ptr->link;
					ptr->link = temp;
					return; //삽입이 끝났으므로 그냥 나가기
				}
			}

			ptr->link = temp;
			temp->link = nullptr;
		}
	}
	
	void merge(List* oth) {
		List* orig = this->first; //A객체의 함수에서 실행하였으므로 그대로 사용해도됨(또는 this로 명시)
		List* temp = oth->first; //매개변수로 가져왔으므로 B객체의 것이라고 명시해야함(중요함)
		for (; temp != nullptr; temp = temp->link) { insert(temp->data); }
	}

	void printList() {
		List* temp = first;
		while (temp != nullptr) {
			cout << temp->data << " -> ";
			temp = temp->link; //다음 노드로 이동
		}
		cout << "nullptr" << endl;
	}
};



#endif