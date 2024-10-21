#ifndef LISTQUEUE_H
#define LISTQUEUE_H
#include "List.h"
#include <iostream>

using namespace std;

class ListQueue : public List {
protected:
	List* front;
	List* rear;

public:
	
	ListQueue() {
		front = first; //��� �׳� first ����..(��¥�� nullptr��)
		rear = nullptr; //��� nullptr�� ����
	}

	bool empty() {
		if (front == nullptr) { //front�� ����Ű�°� ������ ��尡 ����
			cout << "Queue is empty!! (return -1)" << endl;
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


	void enqueue(int item) {
		List* temp = new List(item); //data�� �������� link�� nullptr��
		//����ٰ� Ǯ or ���� �����Ұ�

		temp->data = item;

		if (rear != nullptr)
			rear->link = temp; //��尡 �ϳ��̻� ������ ����ó������
		else
			front = temp; //��尡 ó�� �����Ǹ� front���� ��带 �����ؾ���

		rear = temp; //rear ����
	}

	int dequeue() {
		if (empty()) return -1;

		List* temp = front; //�������� ����� ����

		int item = front->data;
		front = front->link; //front����, ������ ��带 ��ť�ϸ� front�� nullptr����
		delete temp; //��� ����, ��ť
		return item; //���� ��ȯ
	}

	void printQueue() {
		List* temp = front;

		cout << "printQueue" << endl;
		cout << "front -> ";
		if (temp == nullptr) cout << "nullptr ";
		else while(temp != nullptr){ //�������� nullptr�� �����Ƿ�
			cout << temp->data << " ";
			temp = temp->link;
		}

		cout << "<- rear" << endl;
	}
};

#endif
