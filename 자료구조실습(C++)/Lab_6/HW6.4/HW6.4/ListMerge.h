#ifndef LISTMERGE_H
#define LISTMERGE_H
#include "List.h"

class ListMerge : public List {
public:

	void insert(int item) {
		List* temp = new List(item); //���Ҵ� item���� �̸� ��, link�� NULL
		List* ptr;

		if (first == nullptr) {
			first = temp;
		}

		else {
			for (ptr = first; ptr->link != nullptr; ptr = ptr->link); //�����Ͽ� �ڿ� ����
			ptr->link = temp;
			temp->link = nullptr;
		}
	}

	void sort() { //�������ķ� ����
		int size;
		List* i;
		List* j;

		//�� �κ� ���ʿ�����������
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