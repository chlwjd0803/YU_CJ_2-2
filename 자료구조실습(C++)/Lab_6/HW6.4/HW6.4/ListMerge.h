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

		else {
			for (ptr = first; ptr->link != nullptr; ptr = ptr->link); //추적하여 뒤에 붙임
			ptr->link = temp;
			temp->link = nullptr;
		}
	}

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