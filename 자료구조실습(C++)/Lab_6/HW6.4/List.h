#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class List {
public:
	int data;
	List* link;

	List* first; // ó�� ����Ʈ�� ��� ����

	List() {
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
		List* temp = new List();
		temp->data = item;
		List* ptr;

		if (first == nullptr) {
			first = temp;
		}

		else {
			if (temp->data <= first->data) {
				temp->link = first;
				first = temp;
				return;
			}

			ptr = first;
			for (; ptr->link != nullptr; ptr = ptr->link) {
				if ((ptr->data) <= (temp->data) && ((ptr->link->data) >= (temp->data))) {
					//ptr�� ptr->link ������(�������ǵ� ����) ���̸� ����
					temp->link = ptr->link;
					ptr->link = temp;
					return; //������ �������Ƿ� �׳� ������
				}
			}

			ptr->link = temp;
			temp->link = nullptr;
		}
	}
	
	void merge(List* oth) {
		List* orig = this->first; //A��ü�� �Լ����� �����Ͽ����Ƿ� �״�� ����ص���(�Ǵ� this�� ���)
		List* temp = oth->first; //�Ű������� ���������Ƿ� B��ü�� ���̶�� ����ؾ���(�߿���)
		for (; temp != nullptr; temp = temp->link) { insert(temp->data); }
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