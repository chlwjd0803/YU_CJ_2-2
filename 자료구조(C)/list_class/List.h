#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class List {
protected:
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
};



#endif