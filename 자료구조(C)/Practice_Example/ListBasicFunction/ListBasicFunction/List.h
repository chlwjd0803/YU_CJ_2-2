#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class List {
private:
	List* first; // ó�� ����Ʈ�� ��� ����

public:
	int data;
	List* link;

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

	void add(int item) {
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

	void insert(int item, int pv) { //�Է¹��� ������ ������ �����Ѵ�. item:�߰��ҿ���, pv:��������
		List* temp = new List(item);
		List* ptr;

		if (first == nullptr) {
			first = temp; //����Ʈ�� ���⿡ �׳� �߰�
		}
		else {
			for (ptr = first; ptr->data != pv; ptr = ptr->link);
			temp->link = ptr->link;
			ptr->link = temp;
		}
	}

	void dlt(int item) {
		if (first == nullptr) return;

		if (first->data == item) { //ù��° ��忡�� �����Ұ��
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
			temp = temp->link; //���� ���� �̵�
		}
		cout << "nullptr" << endl;
	}

};



#endif