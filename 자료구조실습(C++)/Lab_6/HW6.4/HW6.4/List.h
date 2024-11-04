#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class List {
public:
	int data;
	List* link;

	List* first; // 처음 리스트는 비어 있음

	List(int n = 0) {
		data = n;
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
		List* temp = new List(item); //원소는 item으로 미리 줌, link는 NULL
		List* ptr;

		if (first == nullptr) {
			first = temp;
		}
		/*
		else {
			for (ptr = first; ptr->link != nullptr; ptr = ptr->link); //추적하여 뒤에 붙임
			ptr->link = temp;
			temp->link = nullptr;
		}
		*/
		else {
			ptr = first;
			for (; ptr->link != nullptr; ptr = ptr->link) {
				if ((ptr->data) <= (temp->data) && ((ptr->link->data) >= (temp->data))) {
					//ptr과 ptr->link 사이의(같은조건도 포함) 값이면 삽입
					temp->link = ptr->link;
					ptr->link = temp;
					break; //삽입이 끝났으므로 그냥 나가기
				}
			}
			if (ptr->link == nullptr) { //모두 비교하였는데 아닌경우 그냥 맨 뒤에다가 붙임
				ptr->link = temp;
				temp->link = nullptr;
			}
		}
	}

	List* merge(List* oth) {
		List* orig = first;
		List* temp = oth;
		for (; temp == nullptr; temp = temp->link) { insert(temp->data); }
		return this;
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