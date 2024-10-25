#ifndef LISTSTACK_H
#define LISTSTACK_H
#include "List.h"
#include <iostream>

using namespace std;

class ListStack : public List {
protected:
	List* top;
public:

	ListStack() {
		top = first; //top�� first ������ ������, ó���� null
	}

	//�Ҹ��ڴ� ����Ŭ�������� �� �޸����� ����

	bool empty() {
		if (top == nullptr) {
			cout << "Stack is empty!!!, return -1" << endl;
			return true;
		}
		else return false;
	}

	bool full_or_error(List* temp) {
		if (temp == nullptr) {
			cout << "Out of Memory(Stack is full, or Memory alloc failed." << endl;
			return true;
		}
		else return false;
	}

	void push(int item) {
		List* temp = new List(item); //data�� ä���� ��Ȳ
		if (full_or_error(temp)) return;


		if (top != nullptr) //��尡 1�� �̻��϶���
			temp->link = top; //�� ����� ��ũ�� ���� ž�� ����
		//�� ��尡 ������ top�� �ٷ� temp�� ����Ű�� ��
		top = temp; //top�� temp�� �Ǿ� top����

		//cout << "push data : " << item << "   top->data : " << top->data << endl;
	}

	int pop() {
		if (empty()) return -1;

		List* temp;

		temp = top; //��ũ�� �ű��� �ش� ����� �޸𸮸� �����ϱ� ����
		int item = top->data;

		if (top->link == nullptr) {
			delete top;
			top = nullptr; //��尡 �ϳ��� �����Ƿ�
		}
		else {
			top = top->link; //top����
			delete temp; //�����Ϸ��� top ��� �޸� ����
		}
		//cout << "pop  data : " << item << "   top->data : " << top->data << endl;

		return item; //������ ����� ���� ��
	}

	void printStack() {
		List* temp = top;

		//cout << "printStack" << endl;
		cout << "top ";
		if (temp == nullptr) cout << "-> nullptr" << endl;
		else while (temp != nullptr) {
			cout << " -> " << temp->data;
			temp = temp->link;
		}

		cout << endl;
	}
};


#endif