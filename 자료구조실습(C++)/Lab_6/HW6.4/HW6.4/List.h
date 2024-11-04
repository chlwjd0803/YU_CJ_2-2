#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class List {
public:
	int data;
	List* link;

	List* first; // ó�� ����Ʈ�� ��� ����

	List(int n = 0) {
		data = n;
		link = nullptr;
		first = nullptr;
	}

	~List() { //�޸�����
		List* temp;
		while (first != nullptr) {
			temp = first;
			first = first->link;
			delete temp;
		}
	}

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
			temp = temp->link; //���� ���� �̵�
		}
		cout << "nullptr" << endl;
	}
};



#endif