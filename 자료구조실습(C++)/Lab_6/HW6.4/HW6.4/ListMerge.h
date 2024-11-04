#ifndef LISTMERGE_H
#define LISTMERGE_H
#include "List.h"

class ListMerge : public List {
public:

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

	static void merge(ListMerge* A, ListMerge* B) {
		ListMerge* orig = A;
		ListMerge* temp = B;
		for (; temp == nullptr; temp = temp->link) { A.insert(temp->data); }
	}

	void printList() {
		List* temp = first;
		while (temp != nullptr) {
			cout << temp->data << " -> ";
			temp = temp->link; //다음 노드로 이동
		}
		cout << "nullptr" << endl;
	}


	//이 함수를 안쓸 수는 없나?
	void sort() { //선택정렬로 구현
		int size;
		List* i;
		List* j;

		//이 부분 불필요할지도몰라
		//for (size = 0; temp != nullptr; temp = temp->link, size++);
		//temp = first->link;

		for (i = first; i->link != nullptr; i = i->link) {
			for (j = i->link; j != nullptr; j = j->link) {
				if (i->data > j->data) {
					int temp = i->data;
					i->data = j->data;
					j->data = temp;
				}
			}
		}
	}


};




#endif