#ifndef LISTBASIC_H
#define LISTBASIC_H
#include "List.h"

//�� �ڵ�� ���� �������� Basic�ڵ忡 �ǽ������� �Լ��� �����Ͽ� �ٽ� ����

#include <iostream>

using namespace std;

class ListBasic : public List {

public:

	void insert_front(int item) {
		List* temp = new List(item);

		if (first != nullptr) temp->link = first; //���Ұ� ������ temp��ũ�� first�� ����

		first = temp; //temp�� first����
	}

	void insert_last(int item) {
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

	void search(int item) { // �Լ� ������ �ٸ��� ��ȯ�� void�� �ϰ� ���ο��� ��� �����ϰ���
		List* ptr;
		int count = 0;
		for (ptr = first; (ptr != nullptr) && (ptr->data != item); ptr = ptr->link) count++; //������ġ ã��

		if (ptr == nullptr) cout << "�Է��� �����͸� ���� ��尡 �������� �ʽ��ϴ�." << endl;
		else cout << "������ : " << item << " / ����ȣ : " << count << endl;
	}

	int dlt_front() {
		List* temp = first; //������(������)
		int item = first->data;
		first = first->link;
		delete temp;

		return item;
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

		for (ptr = first; (ptr->link != nullptr) && (ptr->link->data != item); ptr = ptr->link);
		if (ptr->link == nullptr) cout << "���� ��尡 �����ϴ�." << endl;
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
			temp = temp->link; //���� ���� �̵�
		}
		cout << "nullptr" << endl;
	}


};

#endif