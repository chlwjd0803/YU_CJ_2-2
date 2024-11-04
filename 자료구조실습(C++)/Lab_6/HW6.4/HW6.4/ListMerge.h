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
		/*
		else {
			for (ptr = first; ptr->link != nullptr; ptr = ptr->link); //�����Ͽ� �ڿ� ����
			ptr->link = temp;
			temp->link = nullptr;
		}
		*/
		else {
			ptr = first;
			for (; ptr->link != nullptr; ptr = ptr->link) {
				if ((ptr->data) <= (temp->data) && ((ptr->link->data) >= (temp->data))) {
					//ptr�� ptr->link ������(�������ǵ� ����) ���̸� ����
					temp->link = ptr->link;
					ptr->link = temp;
					break; //������ �������Ƿ� �׳� ������
				}
			}
			if (ptr->link == nullptr) { //��� ���Ͽ��µ� �ƴѰ�� �׳� �� �ڿ��ٰ� ����
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
			temp = temp->link; //���� ���� �̵�
		}
		cout << "nullptr" << endl;
	}


	//�� �Լ��� �Ⱦ� ���� ����?
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