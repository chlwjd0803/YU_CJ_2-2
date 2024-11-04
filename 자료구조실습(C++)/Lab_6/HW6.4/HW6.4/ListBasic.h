#ifndef LISTBASIC_H
#define LISTBASIC_H
#include "List.h"

//본 코드는 원래 만들어놓은 Basic코드에 실습용으로 함수를 수정하여 다시 제작

#include <iostream>

using namespace std;

class ListBasic : public List {

public:

	void insert_front(int item) {
		List* temp = new List(item);

		if (first != nullptr) temp->link = first; //원소가 있으면 temp링크를 first로 설정

		first = temp; //temp가 first가됨
	}

	void insert_last(int item) {
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

	void search(int item) { // 함수 원형과 다르게 반환을 void로 하고 내부에서 모두 수행하게함
		List* ptr;
		int count = 0;
		for (ptr = first; (ptr != nullptr) && (ptr->data != item); ptr = ptr->link) count++; //원소위치 찾기

		if (ptr == nullptr) cout << "입력한 데이터를 가진 노드가 존재하지 않습니다." << endl;
		else cout << "데이터 : " << item << " / 노드번호 : " << count << endl;
	}

	int dlt_front() {
		List* temp = first; //해제용(삭제용)
		int item = first->data;
		first = first->link;
		delete temp;

		return item;
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

		for (ptr = first; (ptr->link != nullptr) && (ptr->link->data != item); ptr = ptr->link);
		if (ptr->link == nullptr) cout << "지울 노드가 없습니다." << endl;
		else {
			target = ptr->link;
			ptr->link = target->link;
			delete target;
		}
	}

	void invert() {
		List* lead = first;
		List* middle = nullptr;
		List* trail;

		while (lead != nullptr) {
			trail = middle;
			middle = lead;
			lead = lead->link;
			middle->link = trail;
		}

		first = middle;
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