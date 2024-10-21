#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class List {
private:
	List* first; // 처음 리스트는 비어 있음

public:
	int data;
	List* link;

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

	void add(int item) {
		List* temp = new List(item); //원소는 item으로 미리 줌, link는 NULL
		List* ptr;

		if (first == nullptr) {
			first = temp;
		}

		else {
			for (ptr = first; ptr->link != nullptr; ptr = ptr->link); //추적하여 뒤에 붙임
			ptr->link = temp;
			temp->link = nullptr;
		}
	}

	void insert(int item, int pv) { //입력받은 원소의 다음에 삽입한다. item:추가할원소, pv:이전원소
		List* temp = new List(item);
		List* ptr;

		if (first == nullptr) {
			first = temp; //리스트가 없기에 그냥 추가
		}
		else {
			for (ptr = first; ptr->data != pv; ptr = ptr->link);
			temp->link = ptr->link;
			ptr->link = temp;
		}
	}

	void dlt(int item) {
		if (first == nullptr) return;

		if (first->data == item) { //첫번째 노드에서 삭제할경우
			List* temp = first->link;
			delete first;
			first = temp;
			return;
		}

		List* ptr;
		List* target;

		for (ptr = first; ptr->link->data != item; ptr = ptr->link);
		target = ptr->link;
		ptr->link = target->link;
		delete target;
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